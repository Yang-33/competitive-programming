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

/* -----  2018/04/10  Problem: yukicoder 033  / Link: http://yukicoder.me/problems/no/033  ----- */
/* ------問題------

N匹のアメーバが１直線上にいます。
各アメーバには初期座標が与えられます。
初期座標はすべて整数座標です。
アメーバは１秒後に３つに分裂します。
その後、１匹は現在の座標から−Dだけ移動します。
もう１匹は現在の座標から+Dだけ移動します。
最後の１匹はそのままの座標です。
また、アメーバは同じ座標に２匹以上いると、
合体して１匹になります。
最初にN匹いたアメーバがT秒後には
何匹になっているか答えなさい。

-----問題ここまで----- */
/* -----解説等-----

区間を最後にmergeする作業は区間スケジューリングでおなじみ。
重複しうるグループはx%Dの同値類のみ。
グループ分けした後にmergeすればよい。

----解説ここまで---- */

LL N, D, T;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> D >> T;
	map<int, VL>Map;
	FOR(i, 0, N) {
		LL x; cin >> x;
		Map[(x%D+D)%D].push_back(x);
	}
	ans = 0;
	for (auto it = Map.begin(); it != Map.end(); it++) {
		VL a = it->second;
		SORT(a);
		LL L = a[0] - D*T;
		LL R = a[0] + D*T;
		FOR(i, 1, SZ(a)) {
			if (R >= a[i] - D*T) {
				R = a[i] + D*T;
			}
			else {
				ans +=(R-L)/D+1 ;

				L = a[i] - D*T;
				R = a[i] + D*T;
			}

		}
		// 末尾のやつ
		ans += (R - L) / D + 1;
	}

	cout << ans << "\n";

	return 0;
}
