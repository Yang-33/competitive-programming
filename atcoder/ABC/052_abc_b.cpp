#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;
ll N;
/* 2017/01/18 –â‘è -----  abc052 b /Link ----- */
/* -----‰ðà“™-----
–â‘è:

”‚¦ã‚°

*/

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    string S;
    cin >> N >> S;
    int cnt = 0;
    int ans = 0;
    FOR(i, 0, N) {
        if (S[i] == 'I') {
            cnt++;
            ans = max(ans, cnt);
        }
        else cnt--;
    }
    cout << ans<< endl;

    return 0;
}