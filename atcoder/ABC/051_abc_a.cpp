#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 ��� -----  abc051 a /Link ----- */
/* -----�����-----
���: ��Ǔ_�t���o�傩���_���Ȃ���
S[5],S[13]=" "�Ƃ���΂悢�B
��邾���B

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