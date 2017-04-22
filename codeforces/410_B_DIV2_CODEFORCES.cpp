#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(int (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(int (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/04/21  Problem: CodeForces410 B div2 / Link:  ----- */
/* ------–â‘è------



-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



----‰ðà‚±‚±‚Ü‚Å---- */

ll N;


int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s[50];
	cin >> N;
	FOR(i, 0, N) {
		cin >> s[i];
	}


	string gg = s[0];
	int ans = INF;

	FOR(i, 0, gg.size()) {
		string g;
		FOR(j, i, gg.size())g += gg[j];
		FOR(j, 0, i)g += gg[j];
		g += g;
		//debug(g);
		int cnt = 0;
		FOR(j, 0, N) {
			bool f = false;
			int cc = INF;
			FORR(k, gg.size() - 1, -1) {
				if (s[j] == g.substr(k, gg.size())) {
					f = true;
					if (k != 0)
						cc = min(cc,(int)gg.size() - k);
					if (k == 0) { cc = 0; break; }
				}
			}
			//cout << "in " << cnt << endl;
			if (f == false||cc==INF) {
				cout << -1 << endl;
				return 0;
			}
			cnt += cc;
		}
		//debug(cnt);
		ans = min(ans, cnt);
	}

	cout << ans << endl;

	return 0;
}