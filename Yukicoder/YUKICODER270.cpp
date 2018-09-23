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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/09/19  Problem: yukicoder 270  / Link: http://yukicoder.me/problems/no/270  ----- */
/* ------問題------

あるnに対する[1,2,…,n]の置換(permutation) xに対し、f(x)を辞書順でxの次の置換とする。 ただし、xが辞書順で最後のもの[n,n−1,…,1]である場合は、f(x)を辞書順で最初のもの[1,2,…,n]として定義する。 たとえば、f([1,2,3])=[1,3,2], f(f([3,1,2]))=f([3,2,1])=[1,2,3] となる。
あるnに対し長さがnの2つの配列x,yに対するL1距離 ∑i=1n|xi−yi|をdist(x,y)として表す。 たとえば、x=[1,2,3],y=[3,2,1]ならdist(x,y)=|1−3|+|2−2|+|3−1|=4となる。
置換pが与えられたとき、置換の列Aを、A0=p, Ai=f(Ai−1) (i∈[1,2,…]) として定義する。 つまり、Aiはpにfをi回適用したものである。 たとえば、p=[2,1,3] なら A=[[2,1,3],[2,3,1],[3,1,2],[3,2,1],[1,2,3],…] となる。 Aの添字は0から始まることに注意せよ。
整数N, 整数K, 長さNの置換p, 長さNの配列B が入力として与えられる。 ∑i=0K−1dist(Ai,B)を求めよ。

-----問題ここまで----- */
/* -----解説等-----

next_permutationの内部に付け加えるとswap分だけで良いことになり、O(N+K)
https://cpprefjp.github.io/reference/algorithm/next_permutation.html
今更になってK==0に気を配れないぐらいなら辞めたほうが良さそう

----解説ここまで---- */

LL my_permutation(VL& A, VL& d,LL diffVal)
{
	int n = A.size();
	if (n == 1) {
		return diffVal;
	}

	int i = n - 1;

	for (;;){
		int ii = i;
		--i;
		if (A[i] < A[ii]){
			int j = n;
			while (!(A[i] < A[--j])){}

			diffVal -= abs(A[i] - d[i]);
			diffVal -= abs(A[j] - d[j]);
			swap(A[i], A[j]);
			diffVal += abs(A[i] - d[i]);
			diffVal += abs(A[j] - d[j]);

			FOR(k, ii, n) {
				diffVal -= abs(A[k] - d[k]);
			}
			reverse(A.begin() + ii, A.end());
			FOR(k, ii, n) {
				diffVal += abs(A[k] - d[k]);
			}
			return diffVal;
		}
		if (i == 0)
		{
			FOR(k, 0, n) {
				diffVal -= abs(A[k] - d[k]);
			}
			reverse(ALL(A));
			FOR(k, 0, n) {
				diffVal += abs(A[k] - d[k]);
			}
			return diffVal;
		}
	}
	return diffVal;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	VL a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	LL sum = 0;

	FOR(i,0,N){
		sum += abs(a[i] - b[i]);
	}
	LL ans = (K?sum:0);
	FOR(k, 1, K) {
		sum = my_permutation(a, b, sum);
		ans += sum;
	}

	cout << ans << "\n";

	return 0;
}
