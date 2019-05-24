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

/* -----  2019/05/19  Problem: ABC 126 F / Link: http://abc126.contest.atcoder.jp/tasks/abc126_f  ----- */


void test(int M, int K) {
	VI a(2 << M, 0);
	FOR(i, 0, 2 << M) {
		a[i] = i / 2;
	}
	int N = 2 << M;
	bool ex = 0;
	VI b;
	do {
		VI pa(1 << M, 0);
		FOR(i, 0, N) {
			FOR(j, i + 1, N) {
				if (a[i] == a[j]) {
					LL x = 0;
					FOR(k, i + 1, j) {
						x ^= a[k];
					}
					if (x == K) {
						pa[a[i]] = 1;
					}
				}
			}
		}
		LL s = accumulate(ALL(pa), 0LL);
		if (!ex && s == 1 << M) {
			ex = 1, b = a;
			/*for (auto it : b) {
				cout << it << " ";
			}cout << endl;*/
			break;
		}

	} while (next_permutation(ALL(a)));
	if (ex)DD(de(M, K, ex));
	if (ex) {
		for (auto it : b) {
			cout << it << " ";
		}cout << endl;
	}
}

long long xorxor(long long  val) {
	long long ret = ((val + 1) / 2) % 2;
	for (int i = 0; i <= 59; i++) if ((val >> i) % 2) ret |= (1 ^ (val % 2)) << i;
	return ret;
}

// 実験してちゃんと仮説を検証すること !!!
// 実験: した
// 検証: 雑すぎ
//       - 二山位あれば良さそう
//       - こういうときに1山にしたくならないとダメ
// 

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int M, K; cin >> M >> K;
	if (pow(2, M) - 1 < K) {
		cout << "-1" << endl;
		return 0;
	}
	DD(de(xorxor(2 << M)));
	if (M == 1 && K == 1) {
		cout << "-1" << endl;
		return 0;
	}
	if (K == 0) {
		FOR(i, 0, 1 << M) {
			cout << i << " "<< i<<" ";
		}cout << endl;
		return 0;
	}
	VI ans;
	ans.push_back(K);
	FOR(i, 0, 1 << M) {
		if (i == K)continue;
		ans.push_back(i);
	}
	ans.push_back(K);
	FORR(i, (1 << M) - 1, 0 - 1) {
		if (i == K)continue;
		ans.push_back(i);
	}
	for (auto it : ans) {
		cout << it << " ";
	}cout << endl;

	//FOR(k, 0, 10) {
	//	test(0, k);
	//}
	//FOR(k, 0, 10) {
	//	test(1, k);
	//}
	//FOR(k, 0, 10) {
	//	test(2, k);
	//}
	//FOR(k, 0, 10) {
	//	test(3, k);
	//}

	return 0;
}
