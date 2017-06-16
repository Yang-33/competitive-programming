#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/06/01  Problem: CodeForces417 A div2 / Link: http://codeforces.com/contest/812/problem/A ----- */
/* ------問題------

交差点の四方向から車がやってくる。かつ一つの交差点から直進右折左折のくるまがある。
また交差点の四方向に対して向こう側に横断歩道がある。この横断歩道を歩く歩行者がいる。
これらの存在が01であたえられるので事故が起きうるならYES,起きないならNO
を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

本番は問題文を読むので困ってしまって4通りの場合分けを無理やり書いてしまった。
modでやればfor文でできるんじゃないんですか？となったのでなおした。

----解説ここまで---- */

ll N;
int l[4], r[4], s[4], pos[4];

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	FOR(i, 0, 4)cin >> l[i] >> s[i] >> r[i] >> pos[i];
	bool f = 0;

	FOR(i, 0, 4) {
		if (pos[i] && l[i])f = 1;
		if (pos[i] && s[i])f = 1;
		if (pos[i] && r[i])f = 1;
		if (pos[i]) {
			if (l[(i + 1) % 4] || s[(i + 2) % 4] || r[(i + 3) % 4])f = 1;
		}
	}

	//if (pos[0]) {
	//	if (l[1] || s[2] || r[3])f = 1;
	//}
	//if (pos[1]) {
	//	if (l[2] || s[3] || r[0])f = 1;
	//}
	//if (pos[2]) {
	//	if (l[3] || s[0] || r[1])f = 1;
	//}
	//if (pos[3]) {
	//	if (l[0] || s[1] || r[2])f = 1;
	//}
	if (f) {
		cout << "YES" << endl;
	}
	else {
		cout << "NO" << endl;

	}
	return 0;
}