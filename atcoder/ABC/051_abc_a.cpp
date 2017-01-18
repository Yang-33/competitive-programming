#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 問題 -----  abc051 a /Link ----- */
/* -----解説等-----
問題: 句読点付き俳句から句点をなくす
S[5],S[13]=" "とすればよい。
やるだけ。

*/

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    string S;
    cin >> S;
    FOR(i, 0, 5) {
        cout << S[i];
    }
    cout << " ";
    FOR(i, 6, 13) {
        cout << S[i] ;
    }
    cout << " ";

    FOR(i, 14, 19) {
        cout << S[i] ;
    }
    cout << endl;
    return 0;
}