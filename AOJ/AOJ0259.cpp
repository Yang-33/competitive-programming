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

/* -----  2018/07/26  Problem: AOJ 0259 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0259  ----- */
/* ------問題------

0 から 9 の数字からなる四桁の数 N に対して以下の操作を行う。
N の桁それぞれの数値を大きい順に並べた結果得た数を L とする
N の桁それぞれの数値を小さい順に並べた結果得た数を S とする
差 L-S を新しい N とする(1回分の操作終了)
新しい N に対して 1. から繰り返す
このとき、全桁が同じ数字(0000, 1111など)である場合を除き、あらゆる四桁の数はいつかは 6174になることが知られている。例えば N = 2012の場合
	   1回目 (N = 2012): L = 2210, S = 0122, L-S = 2088
	   2回目 (N = 2088): L = 8820, S = 0288, L-S = 8532
	   3回目 (N = 8532): L = 8532, S = 2358, L-S = 6174
となり、3 回の操作で 6174 に到達する。
0 から 9 の数字からなる四桁の数が与えられたとき、何回の操作で 6174 に到達するか計算するプログラムを作成して下さい。

-----問題ここまで----- */
/* -----解説等-----

ICPCの6桁バージョンはこれがもとなのかな?
シュミレーションをします。

----解説ここまで---- */

template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		if (N == 6174) { cout << 0 << endl; }
		else {
			if (N % 1111 == 0) {
				cout << "NA" << endl;
			}
			else {
				int cnt = 0;
				while (N != 6174) {
					V<int>a(4, 0);
					FOR(i, 0, 4) {
						a[4 - i - 1] = N % 10;
						N /= 10;
					}
					SORT(a);
					auto f = [&a]() {
						int ret = 0;
						FOR(i, 0, 4) {
							ret *= 10;
							ret += a[i];
						}
						return ret;
					};
					int S = f();
					reverse(ALL(a));
					int L = f();
					N = L - S;
					cnt++;
				}
				cout << cnt << endl;
			}
		}
	}
}