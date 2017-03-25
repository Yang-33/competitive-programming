#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<climits> //INT_MIN/MAX
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

/* -----  xtimex  Problem: CodeForces406 a div2 / Link:  ----- */
/* ------���------



-----��肱���܂�----- */
/* -----�����-----



----��������܂�---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
    int a, b, c, d;
	cin >> a>>b>>c>>d;
    map<int, int>m;
    FOR(i, 0, 100000) {
        int x = b+i*a;
        m[x]=2;
    }
    FOR(i, 0, 100000) {
        int y = d + c*i;
        if (m[y] == 2) {
            cout << y << endl;
            return 0;
        }
    }
    cout << -1 << endl;

	return 0;
}