#include<iostream>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/30  Problem: CodeForces407 A div2 / Link: http://codeforces.com/contest/789/problem/A ----- */
/* ------���------

N��ނ̂��ꂼ�����Ai�̐΂�����B
�|�P�b�g�������P��K������邱�Ƃ��ł���B���ꂼ��̒��ɂ͈قȂ��ނ̐΂����Ă͂����Ȃ��B
�ŒZ�����ł��ׂĂ�����ł��邩�B

-----��肱���܂�----- */
/* -----�����-----

Ai�̐΂�K�̃T�C�Y�ŕ�������B�قȂ�΂͒��ɓ���Ă͂����Ȃ��̂�����΂̐���K�Ő؂�グ��΂悢�B
�Q�|�P�b�g������̂ő��^���񐔂��Q�Ŋ���Ȃ������犄������łP�𑫂��B

----��������܂�---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
    ll K;
	cin>>N>>K;
    ll a[100010];
    FOR(i, 0, N) {
        cin >> a[i];
    }

    FOR(i, 0, N) {
        ll num = a[i] / K;
        ans += num;
        if (a[i] % K != 0)ans++;
    }
    if (ans % 2 == 1) {
        cout << ans / 2 + 1 << endl;
    }else
	cout<<ans/2<<endl;

	return 0;
}