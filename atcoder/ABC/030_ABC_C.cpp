#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  2017/02/20  Problem: ABC030 C / Link: http://abc030.contest.atcoder.jp/tasks/abc030_c ----- */
/* ------問題------
ウナギの高橋くんは飛行機に乗ることが趣味です。今回は空港Aと空港Bを往復することにしました。
空港Aから空港Bの飛行機には X 時間かかり、空港Bから空港Aへの飛行機には Y 時間かかります。
空港Aから空港Bへの飛行機は N 本あり、i 番目の便は ai 時に出発します。 空港Bから空港Aへの飛行機は M 本あり、j 番目の便は bj 時に出発します。

ある飛行機には、出発する空港に出発する時刻以前にいれば乗ることができます。
出発する時刻ちょうどに到着した場合も、すぐに飛行機に乗って出発できます。
高橋くんははじめ空港Aに 0 時にいます。 空港Aと空港Bの間を最大何往復できるか調べてください。
*/
/* -----解説等-----

はやく行っても損はないので、はやく行く。
次の便の検索には時刻が昇順であることに気付き、lower_boundを使うまたはお手製の二分探索機を
つかって検索すれば、Ｏ(max(N,M)log(max(N,M)))で解ける。

*/

ll N,M,X,Y;
vector<int> a;
vector<int> b;
int ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> X >> Y;

    FOR(i, 0, N) {
        int d;
        cin >> d;
        a.push_back(d);
    }
    FOR(i, 0, M) {
        int d;
        cin >> d;
        b.push_back(d);
    }

    int state = 0;
    int ntime = 0;
    while (1) {
        if (state == 0) {
            auto it = lower_bound(a.begin(), a.end(),ntime) ;
            int id = distance(a.begin(), it);
            if (id == N)break;
            ntime = a[id] + X;
            state = 1;
        }
        else {
            auto it  = lower_bound(b.begin(), b.end(), ntime);
            int id = distance(b.begin(), it);
            if (id == M) break;
            ntime = b[id] + Y;
            ans++;
            state = 0;
        }
    }

    cout << ans << endl;

    return 0;
}