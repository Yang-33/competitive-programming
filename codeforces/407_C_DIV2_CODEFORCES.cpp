#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl

/* -----  2017/03/30  Problem: CodeForces407 C div2 / Link: http://codeforces.com/contest/789/problem/C ----- */
/* ------���------

f(l,r)=��(i=[l,r-l]) |a[i]-a[i+1]|*(-1)^(i-l)
��an���^������B�֐�f�̍ő�l�����߂�B


-----��肱���܂�----- */
/* -----�����-----

��Βl�����݂̂�O�v�Z���A��ɂ����Ƃ��납�� +,-,+,-,...,+,- �ƂȂ�̂Ŋ�����߂���
���݂̒l���O�Ƃ��Ă�����+�𑫂�=> �����}�C�i�X�ł����ݒl�ɂ��̒l�������Ă��{�Ȃ炱����Ƃ��Ď������邱�Ƃ��ł���
�Ƃ������Ƃ𗘗p���Ďڎ��@�̂悤�Ȍ`�Œ[����[�܂Ō��Ă����B
���݂̒l���O�ȏ�ɕۂ��ƂŁA�����}�C�i�X�̒l�Œl�����ɂȂ�����ɉ�����l���v���X�ł��A����͂��̐V���ȃv���X�̒l�݂̂�
����������œK�ƂȂ�悤�Ȏڎ��@���������邱�Ƃ��ł���B
���ݒl�݂̂��̐S�Ȃ̂�index�͕s�v�B

----��������܂�---- */

ll N;

ll ans = 0LL;
ll b[100010], c[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    ll a[100010];
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, N - 1) {
        int x = 1; if ((i + 1) % 2 == 0)x = -1;
        b[i] = abs(a[i + 1] - a[i])*x;
        int y = -1; if ((i + 1) % 2 == 0)y = 1;
        c[i] = abs(a[i + 1] - a[i])*y;

    }
   /* FOR(i, 0, N - 1) {
        cout << b[i] << " " << c[i] << endl;
    }*/
    ll sum = 0;
    FOR(i, 0, N - 1) {
        ans = max(ans, sum + b[i]);
        if (b[i] + b[i + 1] >= 0)sum += b[i] + b[i + 1], ans = max(ans, sum);
        else {
            ans = max(ans, sum);
            if (sum + b[i] + b[i + 1] >= 0)sum += b[i] + b[i + 1];
            else sum = 0;
        }

        i++;
        ans = max(ans, sum);

    } 
    sum = 0;
    FOR(i, 1, N - 1) {
        ans = max(ans, sum + c[i]);

        if (c[i] + c[i + 1] >= 0)sum += c[i] + c[i + 1], ans = max(ans, sum);
        else {
            ans = max(ans, sum);
            if (sum + c[i] + c[i + 1] >= 0)sum += c[i] + c[i + 1];
            else sum = 0;
        }

        i++;

    }
    cout << ans << endl;

    return 0;
}