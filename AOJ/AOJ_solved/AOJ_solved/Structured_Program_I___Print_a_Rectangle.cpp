#include<iostream>
#include<time.h>
using namespace std;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
/* 2017/01/11 ��� -----  Name/Link ----- */
/* -----�����-----
���:�@1�b�҂�����I�茠�I


*/

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int H, W;

    while (1) {
        cin >> H>>W;
        if (H == 0 && W == 0)break;
        FOR(i, 0, H) {
            FOR(j, 0, W) {
                cout << "#";
            }
            cout << endl;
        }
        cout << endl;
    }

    for (int i = 0; i < 1000000000; i++) {
        int p=0;
    }

    return 0;
}