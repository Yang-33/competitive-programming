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

/* -----  2019/02/27  Problem: ABC 111 D / Link: http://abc111.contest.atcoder.jp/tasks/abc111_d  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

- 腕の不変量
- 移動可能な点集合の確認
- マンハッタンチャンス
- 上から二分探索のノリ

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	vector<LL> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	int parity = abs(x.front() + y.front()) % 2;
	auto ok = [&]() {
		bool valid = 1;
		FOR(i, 0, N) {
			valid &= (parity == (abs(x[i] + y[i]) % 2));
		}
		return valid;
	};

	if (!ok()) {
		cout << -1 << endl;
	}
	else {
		int M = 32;
		VL arms(M);
		FOR(i, 0, M) {
			arms[i] = (1LL << ((M - 1) - i));
		}
		if (parity % 2 == 0)arms.push_back(1);
		M = SZ(arms);

		cout << M << endl;
		FOR(i, 0, M) {
			cout << arms[i] << " \n"[i == M - 1];
		}

		FOR(i, 0, N) {
			LL X = x[i] + y[i];
			LL Y = x[i] - y[i];
			LL curX = 0, curY = 0;
			string s = "";
			FOR(j, 0, M) {
				if (abs(curX + arms[j] - X) <= abs(curX - arms[j] - X)) {
					curX += arms[j];
					if (abs(curY + arms[j] - Y) <= abs(curY - arms[j] - Y)) {
						s += "R";
						curY += arms[j];
					}
					else {
						s += "U";
						curY -= arms[j];
					}

				}
				else {
					curX -= arms[j];
					if (abs(curY + arms[j] - Y) <= abs(curY - arms[j] - Y)) {
						s += "D";
						curY += arms[j];
					}
					else {
						s += "L";
						curY -= arms[j];
					}

				}
			}
			cout << s << endl;
		}

	}

	return 0;
}
