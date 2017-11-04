#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/11/04  Problem: ABC 084 C / Link: http://arc084.contest.atcoder.jp/tasks/arc084_c  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

0を詰めれば各項が長さNの数列になる。
k+K^2+k^3+...+k^Nの中央の値が知りたい。Kが偶数のときはすぐにわかる。
これは全体を半分で割った後のものをみればいいので(K/2,K,K,K,..,K)である。
一方Kが奇数のときは悲しいことに一発では決まらない。
樹形図みたいなのを考える。頂点集合に各数列を割り当てたとき、X=(K+1)/2とすると、
N/2 個、大きい側に(X,X,X,X,...,X)があることが分かる。
したがってこれを愚直に戻せばよい。
K==1では通じないので注意

----解説ここまで---- */

LL N, K;

LL ans = 0LL;

// N,K grobal
VI f1() {
	VI a(N, (K + 1) / 2);
	if (K == 1)return VI((N+1)/2, 1);
	FOR(i, 0, N / 2) {
		FORR(j, N - 1, -1) {
			if (a[j] > 0) {
				a[j]--;
				if (a[j] > 0) {
					FOR(l, j + 1, N) {
						a[l] = K;
					}
				}
				break;
			}
		}
	}
	return a;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> K >> N;
	if (K % 2 == 0) {// K 偶数
		cout << K / 2;
		FOR(i, 1, N) {
			cout << " " << K;
		}cout << endl;
	}
	else { // 半分が簡単
		VI a = f1();
		FOR(i, 0, SZ(a)) {
			if (a[i] == 0)break;
			else if(i!=0)cout << " ";
			cout << a[i];
		}cout << endl;
	}

	return 0;
}
