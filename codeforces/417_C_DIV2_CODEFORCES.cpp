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
/* ------���------

���X��N�X����ł���B�\�Z��S�~���肱�̋��z���łȂ�ׂ���������A�������������������B
�����炠�Ȃ���K�X�����߂Ă��̓X�ŏ��i�𔃂��B
���̓X�̒l�i�͍����������i�̑��a�Œl�i���ς��B
(�l�i)=(���̓X�̏��i�̒l�i)�{(��������)(K)
�����𖞂����ۂ̔����������g�������z�����߂�B

-----��肱���܂�----- */
/* -----�����-----

��蕶��������ɂ�������B
�������ɂ��ē񕪒T�������āA
���̌ː��Ŕ����ۂ̊e�X�̏��i�̒l�i�����߂Ă���������̂𔃂��Ă����΂悢�B
�\�ZS�𒴂��Ă͂����Ȃ��̂ŋ�Ԃ�[l,r)�Ƃ��ĒT������B
����������ans=l

----��������܂�---- */

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