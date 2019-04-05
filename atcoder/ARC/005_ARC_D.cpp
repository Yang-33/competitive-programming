#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/04/05  Problem: ARC 005 D / Link: http://arc005.contest.atcoder.jp/tasks/arc005_d  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI usable(10, 0); {
		string oknum; cin >> oknum;
		for (auto c : oknum) {
			usable[c - '0'] = 1;
		}
	}
	string target_price; {
		cin >> target_price;
		for (auto &c : target_price) {
			c -= '0';
		}
	}

	// DP
	VVI subdp(11, VI(112, -1)); {
		subdp[0][0] = 0;
		FOR(num, 0, 10) {
			if (!usable[num])continue;
			FOR(cnt, 0, 10) {
				FOR(sum, 0, 100) {
					if (subdp[cnt][sum] != -1) {
						subdp[cnt + 1][sum] = subdp[cnt][sum];
						subdp[cnt + 1][sum + num] = num;
					}
				}
			}
		}
	}

	LL ans = LINF;
	vector<VVL>memo(22, VVL(11, VL(11, -1)));
	function<LL(int, int, int)> f = [&](int idx, int seqs, int carry) {
		if (idx == -1) {
			if (carry)return LINF;
			else return 0LL;
		}
		if (memo[idx][seqs][carry] != -1)return memo[idx][seqs][carry];

		LL ret = LINF;
		if (seqs) {// leading zero
			ret = min(ret, f(idx, seqs - 1, carry));
		}
		FOR(add, 0, 100) {
			if (subdp[seqs][add] == -1)continue;
			if ((add + carry) % 10 != target_price[idx])continue;
			ret = min(ret, f(idx - 1, seqs, (carry + add) / 10) + seqs);
		}

		return memo[idx][seqs][carry] = ret;
	};

	// 必ず解は存在する
	FOR(i, 1, 10) {
		ans = min(ans, f(SZ(target_price) - 1, i, 0) + i - (i == 1));
	}

	vector<string>anss(11);
	function<void(int, int, int)> recover = [&](int idx, int seqs, int carry) {
		if (idx == -1) {
			if (carry) { assert(0); }
			return;
		}
		LL memoval = memo[idx][seqs][carry];
		if (seqs > 0 && f(idx, seqs - 1, carry) == memoval) {
			return recover(idx, seqs - 1, carry);
		}
		FOR(add, 0, 100) {
			if (subdp[seqs][add] == -1)continue;
			if ((add + carry) % 10 != target_price[idx])continue;
			if (memoval == f(idx - 1, seqs, (carry + add) / 10) + seqs) {
				recover(idx - 1, seqs, (carry + add) / 10);
				// 復元は上の桁から決めたいので先に再帰

				int strid = seqs;
				int leftval = add;
				FOR(i, 0, seqs) {
					anss[i] += string(1, '0' + subdp[strid][leftval]);
					leftval -= subdp[strid][leftval];
					strid--;
				}

				return;
			}
		}
		return;
	};

	FOR(i, 1, 10) {
		if (ans == f(SZ(target_price) - 1, i, 0) + i - (i == 1)) {
			recover(SZ(target_price) - 1, i, 0);
			FOR(j, 0, i) {
				cout << anss[j];

				if (j != i - 1)cout << "+";
			}
			if (i > 1) {
				cout << "=";
			}
			cout << endl;
			return 0;
		}
	}




	//cout << (ans) << "\n";

	return 0;
}
