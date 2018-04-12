#include <bits/stdc++.h>
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

/* -----  2018/04/12  Problem: yukicoder 053  / Link: http://yukicoder.me/problems/no/053  ----- */
/* ------問題------

以下の漸化式で定義される数列 {Ak}∞k=0 の第 N 項 AN を求めるプログラムを書け。
　　A0=4,
  　　A1=3,
	　　4Ak=19Ak−1−12Ak−2,k≥2.

-----問題ここまで----- */
/* -----解説等-----

†計算の際に起きる誤差死を意図的に引き起こす†
という問題。
高校で習った算数をすると二項間漸化式を求めることができて、
A_k = 4*(3/4)^k

----解説ここまで---- */

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	//vector<long double> a(N+1, 0);
	//a[0] = 4;
	//a[1] = 3;
	//FOR(i, 2, N + 1) {
	//	a[i] = (19*a[i-1] -12*a[i-2]) / 4.0;
	//}
	//long double ans = a[N];
	//cout <<fixed<<setprecision(100)<< ans << "\n";

	cout << fixed << setprecision(20) << 4.0*pow(3.0 / 4.0,N) << endl;

	return 0;
}
