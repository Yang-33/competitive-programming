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

/* -----  2017/06/27  Problem: CodeForces421 A div2 / Link: http://codeforces.com/contest/820/problem/A  ----- */
/* ------���------

c�؁[�V�̖{��v0�œǂށB���̓�L�y�[�W���ǂ��āAv0+a�̑��x�œǂށB�ő�ł�v1�̑��x�͉z���Ȃ��B
������ɂ��œǂ߂邱�Ƃ��m�肵�Ă���ۂɉ����œǂ߂邩�B

-----��肱���܂�----- */
/* -----�����-----

����ꂽ�Ƃ���ɏ����B
TLE���Ȃ���������a,l�̏�������ł�1�y�[�W�����ǂ߂Ȃ����̂������Ă��ꂾ���ꍇ�������Ă��悳�����B

----��������܂�---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int c, v0, v1, a, l;
	cin >> c >> v0 >> v1 >> a >> l;
	int readed = 0;
	while (1) {
		ans++;
		readed += v0;
		if (readed >= c)break;

		v0 += a;
		if (v0 >= v1)v0 = v1;
		readed -= l;
	}


	cout << ans << endl;

	return 0;
}