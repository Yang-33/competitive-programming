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

/* -----  2018/08/23  Problem: yukicoder 212  / Link: http://yukicoder.me/problems/no/212  ----- */
/* ------問題------

素数サイコロとはそれぞれの面に 2,3,5,7,11,13 の整数が書かれているサイコロである。
合成数サイコロとはそれぞれの面に 4,6,8,9,10,12 の整数が書かれているサイコロである。
素数サイコロを P 個と合成数サイコロを C 個の合計 P+C 個のサイコロを同時に振った時、出る目の積の期待値を求めるプログラムを書いてください。
各面が出る確率はすべて 1/6 で、それぞれのサイコロについて出る面は独立です。

-----問題ここまで----- */
/* -----解説等-----

あたまが無いのでE[XY]=E[X]*E[Y]として、各サイコロについて全列挙をした。
そもそもサイコロそのものが独立なので一つのサイコロの期待値をだして、積を求めればよい。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI pdice = { 2,3,5,7,11,13 };
	VI cdice = { 4,6,8,9,10,12 };

	int P, C; cin >> P >> C;
	auto f = [](const VI& dice,int N) {
		if (N == 0)return 1.0;
		LL val = 0;
		function<void(int,LL)> dfs = [&](int idx,LL sum) {
			if (idx == N) {
				val += sum;
				return;
			}
			for (int d : dice) {
				dfs(idx + 1, sum*d);
			}

		};
		dfs(0, 1);
		return val / pow(6.0, N);
	};

	double P1 = accumulate(ALL(pdice), 0.0) / 6.0, C1 = accumulate(ALL(cdice), 0.0) / 6.0;
	double ans = pow(P1, P)*pow(C1, C);
	//double ans = 
	//double ans = f(pdice,P)*f(cdice,C);

	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
