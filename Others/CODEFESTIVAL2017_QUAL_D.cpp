#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, S, e) for (int(i) = (S); (i) < (e); (i)++)
#define FORR(i, S, e) for (ll(i) = (S); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/08  Problem: codefestival2017_qual D  / Link: http://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_d  ----- */
/* ------問題------

01文字列がある。
101->010としたときに最大何回置換できるか

-----問題ここまで----- */
/* -----解説等-----

まず00が連続する区間は除いてよい。
そうすると各区間について111011101011111
となる。
これは3 3 1 5 となり、これを上手に選択するDPになる。
(実装がクソなので不可)
これは選択のときに1つ残すといい感じになる。

が、
dp[i]:=i番目までの最大値
として両端に伸ばしたらできたね、悔しい

----解説ここまで---- */

ll N;
ll ans = 0LL;
int dp[1000000];


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string s;
	cin >> s;
	s = "0" + s + "0";
	FOR(i,1,(int)s.size()-1){
		dp[i + 1] = max(dp[i + 1], dp[i]);
		if (s[i - 1] == '1'&&s[i] == '0'&&s[i + 1] == '1')
		{
			int a = i - 1, b = i + 1;
			for (;;){
				if (s[a] == '0')break;
				dp[i + 1] = max(dp[i + 1], dp[a - 1] + (i - a));
				a--;
			}
			for (;;){
				if (s[b] == '0')break;
				dp[b] = max(dp[b], dp[i - 2] + (b - i));
				b++;
			}
		}
	}
	printf("%d\n", dp[s.size() - 1]);








	//cin >> N;
	//string S;
	//cin >> S;



	///*00が連続する区間ごとに別問題となる
	//5.2.4.8.6.2.6から一か所とるとその両隣がとれなくなる*/
	//string sub[500005];
	//int mode = 0;
	//int bef = 0;
	//FOR(i, 0, N - 1) {
	//	if (S[i] == '0'&&S[i + 1] == '0') {
	//		int pos = i + 2;
	//		while (S[pos] == '0')pos++;
	//		FOR(j, bef, i) {
	//			sub[mode] += S[j];
	//		}mode++;
	//		i = pos - 1;//last 0

	//		bef = pos;
	//	}
	//}
	//if (bef != N - 1) {
	//	FOR(j, bef, N) {
	//		sub[mode] += S[j];
	//	}
	//	mode++;
	//}


	//FOR(_m, 0, mode) {
	//	if (sub[_m].size() < 3)continue;

	//	vector<int>L((int)sub[_m].size() + 2, 0);
	//	int s = -1;
	//	int cnt = 0;
	//	N = (int)sub[_m].size();
	//	FOR(i, 0, N) {
	//		if (sub[_m][i] == '1') {
	//			cnt++;
	//			if (s == -1) {
	//				s = i;
	//			}
	//		}
	//		else {
	//			if (cnt > 0) {
	//				FOR(j, s, i) {
	//					L[j] = cnt;
	//				}
	//				cnt = 0;
	//				s = -1;
	//			}
	//		}
	//	}
	//	if (s != -1) {
	//		FOR(j, s, N) {
	//			L[j] = cnt;
	//		}
	//	}

	//	/*FOR(i, 0, N) {
	//		printf("%d", L[i]);
	//	}printf("\n");*/

	//	// Dp的なこと
	//	vector<int>v;
	//	FOR(i, 0, N) {
	//		if (L[i] > 0) {
	//			v.push_back(L[i]);
	//			i += L[i] - 1;

	//		}
	//	}
	//	int vsize = (int)v.size();
	//	if (vsize <= 1)continue;

	//	/*vector<vector<ll>>dp(vsize + 1, vector<ll>(2, 0));
	//	FOR(i, 0, vsize) {
	//		cout << v[i] << " ";
	//	}cout << endl;
	//	FOR(i, 0, vsize) {
	//		if (i != vsize - 1) {
	//			dp[i + 1][0] = max(dp[i][0], dp[i][1]);
	//			dp[i + 1][1] = dp[i][0] + v[i];
	//		}
	//		else {
	//			dp[i][0] += v[i];
	//		}
	//		debug(dp[i][0]);
	//		debug(dp[i][1]);
	//	}
	//	vsize--;
	//	debug(dp[vsize][0]);
	//	debug(dp[vsize][1]);

	//	ans += max(dp[vsize][0], dp[vsize][1]);
	//	debug(ans);*/

	//	vector<vector<int>>dp(vsize + 1, vector<int>(3, 0));
	//	FOR(i, 0, vsize-1) {

	//		if (i >=1) {
	//			dp[i][0] = max({ dp[i - 1][0],dp[i - 1][1] ,dp[i-1][2]});
	//			dp[i][1] = max({ dp[i - 1][0] + v[i],dp[i - 1][1] + v[i] - 1 });
	//			dp[i][2] = max({ dp[i - 1][0] + v[i+1],dp[i-1][1] });
	//		}
	//		else {
	//			dp[0][0] = 0;
	//			dp[0][1] = v[0];
	//			dp[0][2] = v[1];
	//		}


	//	}
	//	vsize-=2;
	//	ans += max({ dp[vsize][0], dp[vsize][1],dp[vsize][2] });
	//}

	////FOR(l, 0, N - 2) {
	////	if (S[l] == '1'&&S[l + 1] == '0'&&S[l + 2] == '1') {
	////		int Li = 0;
	////		int Ri = 0;
	////		ans++;
	////		if (l >= 0) { Li = L[l]; }
	////		if (l < N - 2) { Ri = L[l + 2]; }
	////		if (Ri == Li&&Ri == 1) {
	////			S[l] = '0'; S[l + 1] = '1'; S[l + 2] = '0';
	////		}
	////		else {
	////			if (Li >= Ri) {
	////				ans += Li - 1;
	////				//S[l-Li] = '0';
	////			}
	////			else {
	////				ans += Ri - 1;
	////				S[l + 2 + Ri - 1] = '0';
	////			}
	////		}
	////	}
	////}
	//cout << ans << endl;

	return 0;
}
