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

/* -----  2018/05/02  Problem: yukicoder 134  / Link: http://yukicoder.me/problems/no/134  ----- */
/* ------問題------

サブロー君は酒屋で働いており、注文された商品をトラックで配達しようとしています。
出発地点である酒屋とすべての配達先は2次元平面上にあり、それぞれの位置は、
(X0, Y0)が酒屋の座標、そしてN件の配達先は(Xi, Yi)の座標で表されます。(1≤i≤N)
各配達先iでは、重さWiの商品をトラックから降ろして渡します。

この町は、碁盤の目状に道が整備されており、
各地点から任意の地点まで、南北方向(Y軸)または東西方向(X軸)に移動することができますが、
荷物の重さWを積んでいるとき、1単位距離を移動するためには、以下の式で表される時間Tが掛かります。
T=W+100120

また、各配達先iで重さWiの荷物を降ろすのに時間Wiが掛かります。

酒屋ですべての荷物をトラックに積んで各配達先を周り
すべての配達先へ荷物を配達し終わり、酒屋へ戻ってくるまでの最短時間を求めてください。

・トラックには、配達する荷物以外のものを積むことはありません。
・移動の途中で何らかの理由で停止や減速することはなく、等速で移動し続けられるものとします。
・最初に荷物を積む時間は含みません。

-----問題ここまで----- */
/* -----解説等-----

あるあるすぎて
ICPCかと思った

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	double tx, ty; cin >> tx >> ty;
	int N; cin >> N;
	vector<double>x(N), y(N), w(N, 0);
	x.push_back(tx); y.push_back(ty);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> w[i];
	}
	double sum = accumulate(ALL(w), 0.0);
	//コストを2^nで列挙

	//bitDP
	auto dist = [&](int i, int j) {
		double ret = abs(x[i]-x[j]) + abs(y[i] - y[j]);
		return ret;
	};
	auto f = [&](int i, int j, double s) {
		double ret = dist(i, j)*(s + 100) / 120.0;
		return ret;
	};
	x.push_back(tx);
	y.push_back(ty);
	vector<vector<double>>dp(1 << N, vector<double>(N, LINF));
	FOR(i, 0, N) {
		dp[1 << i][i] = f(N, i, sum) + w[i];
	}
	vector<double>costw(1 << N, LINF);
	FOR(i, 0, 1 << N) {
		double ret = 0;
		FOR(j, 0, N) {
			if (i & 1 << j) {
				ret += w[j];
			}
		}
		costw[i] = sum - ret;
	}
	FOR(i, 0, 1 << N) {
		FOR(j, 0, N) {
			if (i & 1 << j) {
				FOR(k, 0, N) {
					if (i & 1 << k)	continue;
					dp[i | 1 << k][k] = min(dp[i | 1 << k][k], dp[i][j] + f(j, k, costw[i]) + w[k]);
				}
			}
		}
	}
	double ans = LINF;
	FOR(i, 0, N) {
		ans = min(ans, dp[(1 << N) - 1][i] + f(i,N,0));
	}
	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
