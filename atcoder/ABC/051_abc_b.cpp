#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 問題 abc051 b  Name/Link ----- */
/* -----解説等-----
問題:
3重ループでもいける。（枝狩り
Zの値は決めなくてもきまる（この考えはよく使う）

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