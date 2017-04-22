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

/* -----  2017/04/21  Problem: CodeForces410 A div2 / Link:  ----- */
/* ------–â‘è------



-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



----‰ðà‚±‚±‚Ü‚Å---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string s;

	cin >> s;

	int cnt = 0;
	FOR(i, 0, (int)s.size()/2) {
		if (s[i] != s[s.size() - i - 1])cnt++;
	}
	if (s.size() % 2 == 0 && cnt == 0)cnt = 3;
	if(cnt<=1)	cout<<"YES"<<endl;
	else cout << "NO" << endl;
	return 0;
}