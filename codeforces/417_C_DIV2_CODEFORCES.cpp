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

/* -----  2017/06/01  Problem: CodeForces417 C div2 / Link: http://codeforces.com/contest/812/problem/C ----- */
/* ------–â‘è------

‚¨“X‚ªN“X•À‚ñ‚Å‚¢‚éB—\ŽZ‚ªS‰~‚ ‚è‚±‚Ì‹àŠz“à‚Å‚È‚é‚×‚­‚½‚­‚³‚ñAˆÀ‚­”ƒ‚¢•¨‚ð‚µ‚½‚¢B
¡‚©‚ç‚ ‚È‚½‚ªK“X‚ðŒˆ‚ß‚Ä‚»‚Ì“X‚Å¤•i‚ð”ƒ‚¤B
‚»‚Ì“X‚Ì’l’i‚Í¡”ƒ‚Á‚½¤•i‚Ì‘˜a‚Å’l’i‚ª•Ï‚í‚éB
(’l’i)=(‚»‚Ì“X‚Ì¤•i‚Ì’l’i){(”ƒ‚Á‚½ŒÂ”)(K)
ðŒ‚ð–ž‚½‚·Û‚Ì”ƒ‚Á‚½ŒÂ”‚ðŽg‚Á‚½‹àŠz‚ð‹‚ß‚æB

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

–â‘è•¶‚ª•ª‚©‚è‚É‚­‚·‚¬‚éB
”ƒ‚¤ŒÂ”‚É‚Â‚¢‚Ä“ñ•ª’Tõ‚ð‚µ‚ÄA
‚»‚ÌŒË”‚Å”ƒ‚¤Û‚ÌŠe“X‚Ì¤•i‚Ì’l’i‚ð‹‚ß‚Ä‚©‚çˆÀ‚¢‚à‚Ì‚ð”ƒ‚Á‚Ä‚¢‚¯‚Î‚æ‚¢B
—\ŽZS‚ð’´‚¦‚Ä‚Í‚¢‚¯‚È‚¢‚Ì‚Å‹æŠÔ‚ð[l,r)‚Æ‚µ‚Ä’Tõ‚·‚éB
‚µ‚½‚ª‚Á‚Äans=l

----‰ðà‚±‚±‚Ü‚Å---- */

ll N, S;
ll a[100010];
ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> S;
	FOR(i, 0, N)cin >> a[i];
	ll l = 0; ll r = N+1 ;
	ll res = 0;
	FOR(_i, 0, 200) {
		ll mid = (l + r) / 2;
		res = 0;
		ll A[100010];
		FOR(i, 0, N)A[i] = a[i] + (i + 1)*mid;
		sort(A, A + N);

		FOR(k, 0, min(N, mid )) {
			res += A[k];
		}
		if (res > S)r = mid;
		else l = mid;
	}
	ans = l;
	if (l == 0)res = 0;
	cout << ans << " " << res << endl;

	return 0;
}