#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 ��� abc051 b  Name/Link ----- */
/* -----�����-----
���:
3�d���[�v�ł�������B�i�}���
Z�̒l�͌��߂Ȃ��Ă����܂�i���̍l���͂悭�g���j

*/

int K, S;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll ans = 0;
    cin >> K >> S;
        FOR(x, 0, K + 1) {
            FOR(y, 0, K + 1) {
                if ((S - (x + y) >= 0) && (S - (x+y)<=K))ans++;
            }
        }


        cout << ans<< endl;

    return 0;
}