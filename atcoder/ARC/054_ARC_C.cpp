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

/* -----  2018/11/19  Problem: ARC 054 C / Link: http://arc054.contest.atcoder.jp/tasks/arc054_c  ----- */
/* ------問題------


高橋君の家にはタイヤが N 個と木が N 本あります。高橋君は、これらを一つずつ組み合わせて鯛焼きを N 個作ることにしました。
タイヤと木の組には相性があり、相性のいいタイヤと木の組み合わせでのみおいしい鯛焼きを作ることができます。 高橋君はおいしい鯛焼きしか食べないので、作る N 個の鯛焼きすべてが、相性のいいタイヤと木の組み合わせでできている必要があります。
高橋君はこの条件を満たすように鯛焼きを作る方法が何通りあるのかが気になりましたが、これはとても数えられそうにないことに気付きました。
そこで高橋君は、その方法の数の偶奇だけを求めることにしました。
高橋君は、すべてのタイヤと木のペアについて、そのペアの相性がいいかどうかを表あらわす表 (Sij) を持っています。この表は N 行 N 列からなり、i 行 j 列の要素が 1 のとき i 番目のタイヤと j 番目の木の相性がいいことを、 0 のとき悪いことを表します。 高橋君に代わって、すべての鯛焼きをおいしくするような組み合わせ方の数の偶奇を求めてください。 ただし、 2 つの組み合わせ方が異なるとは、あるタイヤが存在し、そのタイヤが別の木と組み合わせられて鯛焼きが作られていることを指します。
-----問題ここまで----- */
/* -----解説等-----

ググる。
http://www.kurims.kyoto-u.ac.jp/~kyodo/kokyuroku/contents/pdf/1799-01.pdf
https://mathtrain.jp/pfaffian

----解説ここまで---- */

template<typename T>
int detmod2(vector<vector<T>> A) {
	int n = A.size();
	int det = 1;
	for (int i = 0; i < n; ++i) {
		int pi = i;
		while (pi < n && !A[pi][i]) ++pi;
		if (pi == n) return false;
		swap(A[pi], A[i]);
		det *= A[i][i];
		for (int j = i + 1; j < n; ++j) {
			if (!A[j][i]) continue;
			for (int k = 0; k < n; ++k) {
				A[j][k] ^= A[i][k];
			}
		}
	}
	return det;
}

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VVI a(N, VI(N, 0));
	FOR(i, 0, N) {
		string s; cin >> s;
		FOR(j, 0, N) {
			if (s[j] == '1')a[i][j] = 1;
		}
	}
	ans = detmod2(a);
	cout << (ans & 1 ? "Odd" : "Even") << "\n";

	return 0;
}
