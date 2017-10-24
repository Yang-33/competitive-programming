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

/* -----  2017/06/17  Problem: CodeForces419 B div2 / Link: http://codeforces.com/contest/816/problem/B  ----- */
/* ------���------

N�̃R�[�q�[�}�V��������A�����͂��ꂼ��[Li,Ri]�̉��x�̃R�[�q�[����邱�Ƃ��ł���B
Q�̃N�G��������B[Li,Ri]�̉��x�̃R�[�q�[���ł��邾����肽���B
�������R�[�q�[�����ۂ�K��ނ���Ȃ���΂����Ȃ��B
�e�N�G�����Ƃɉ��t�܂ō��邩���o�͂���B

-----��肱���܂�----- */
/* -----�����-----

�������@�Ő�����Ԃɑ������񂾌�A���̒l��K�ȏ�Ȃ�(�쐬�\)�Ƃ��Ă�����x�ݐϘa���Ƃ�B


----��������܂�---- */

ll N;
ll K, Q;
int l[200020];
int r[200020];
int a[200020];
int b[200020];
ll ans = 0LL;
int x[200020];
int y[200020];
int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
   
	cin>>N>>K>>Q;
	FOR(i, 0, N) {
		cin >> l[i] >> r[i];
	}
	FOR(i, 0, Q) {
		cin >> a[i] >> b[i];
	}
	
	FOR(i, 0, N) {
		x[l[i]]++;
		x[r[i] + 1]--;
	}
	FOR(i, 1, 200010) {
		x[i] += x[i - 1];
	}
	FOR(i, 0, 200010) {
		if (x[i] >= K)y[i] = 1;
	}
	FOR(i, 1, 200010) {
		y[i] += y[i - 1];
	}

	FOR(i, 0, Q) {
		cout << y[b[i]]-y[a[i]-1] << endl;
	}

	return 0;
}