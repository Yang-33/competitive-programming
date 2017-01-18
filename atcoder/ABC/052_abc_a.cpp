#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/18 –â‘è -----  abc052 a /Link ----- */
/* -----‰ðà“™-----
–â‘è:

MAX.

*/

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int ab, cd;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    ab = a*b;
    cd = c*d;

    int ans = max(ab, cd);



        cout << ans << endl;

    return 0;
}