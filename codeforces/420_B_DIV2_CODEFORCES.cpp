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

/* -----  2017/06/25  Problem: CodeForces420 B div2 / Link: http://codeforces.com/contest/821/problem/B  ----- */
/* ------���------

�΂Ȃȉ��������āAy=-1/M+B�̒����̉��̗̈悪�o�i�i���̖{�̂ł���B
(X,Y)�ɂ�X+Y�̃o�i�i������B
����_��I�������(0,0)����(X,Y)�܂ł̒����`���̃o�i�i�����ׂē��邱�Ƃ��ł���B
�ő傢���̃o�i�i������ł��邩�B

-----��肱���܂�----- */
/* -----�����-----

x,y�ɂ��Ă݂��x�̑�����y+1�i�����������݂��āA
y�����l�̌`���Ƃ�B
���̂����̍ő�l���Ƃ�΂����B
x�̒l�ł͂Ȃ�y�̒l�Œ��ׂ��������������ł���̂ł����Ǝv�����B

----��������܂�---- */

ll M, B;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> M >> B;


	FOR(i, 0, M*B + 1) {
		ll y = -((i + M - 1) / M) + B;
		ll x = i;

		ll ret = (y + 1)*(x*(x + 1)) / 2;
		ret += (x + 1)*(y*(y + 1)) / 2;
		ans = max(ans, ret);
	}


	cout << ans << endl;

	return 0;
}