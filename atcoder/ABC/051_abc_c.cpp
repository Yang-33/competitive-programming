#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 ��� -----  abc052 c /Link ----- */
/* -----�����-----
���:
���������i2WA�j
�y����
*/

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    string SU;
    string SR;
    string SD;
    string SL;
    FOR(i, 0, d - b) {
        SU += "U";
        SD += "D";
    }
    FOR(i, 0, c - a) {
        SR += "R";
        SL += "L";
    }
    string SS = SU + SR + SD + SL + "L" + "U" + SU + SR +"R" + "D" + "R" + SD + "D" + SL + "L" + "U";
    cout << SS << endl;

    return 0;
}