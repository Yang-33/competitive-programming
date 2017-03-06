#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<set>
#include<climits> //INT_MIN/MAX
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/03/06  Problem: ABC005 D / Link: https://abc005.contest.atcoder.jp/tasks/abc005_4 ----- */
/* ------問題------

高橋君のたこ焼き屋で使っているたこ焼き器は焼く場所によって美味しさの変わるクセの強いたこ焼き器です。
また、店員の力量によって一度に焼けるたこ焼きの数が違います。
高橋君はそれぞれの店員ができるだけ美味しくたこ焼きを焼けるようにしようと思いました。

たこ焼き器はN×Nの正方形をしています。
それぞれの場所ごとにたこ焼きの美味しさDijが決まっています。
それぞれの店員は一度に焼けるたこ焼きの上限Pkが決まっています。
また、一度に焼くたこ焼きは必ずたこ焼き器の長方形の部分になっていて、その中の全てを使わなければなりません。
それぞれの店員について一度に焼けるたこ焼きの美味しさの合計の最大値を求めて下さい。
ただし、店員が焼き始める時はたこ焼き器が完全に空いていてどの場所でも使えるとします。


-----問題ここまで----- */
/* -----解説等-----

クエリが来た時に判定を行うのは時間的に厳しい。
クエリの前に前処理をしておきたい。
盤面(0,0) => (i,j)への累積和をとっておけば、サイズ(x,y)=>(x',y')での焼きあがる最高のたこ焼きを差分から求めることができる。
インデックスが配列の制約から一つずれるので注意。（累積和をとる際にありがちのもの。端点はゼロの方が計算がしやすい。）
これをサイズごとに管理しておけばクエリにO(1)で答えることができる。

また、クエリの値よりも小さい面積で最高のたこ焼きが焼ける場合はそれを選択すればいいので下から最大値を伝播させておけばよい。

 ----解説ここまで---- */

ll N, Q;
int d[50][50];
int query[2500];
int dp[60][60];
int x[2600];
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N)FOR(j, 0, N)cin >> d[i][j];
    cin >> Q;
    FOR(i, 0, Q)cin >> query[i];

    FOR(i, 0, N)FOR(j, 0, N)
        dp[i + 1][j + 1] = dp[i + 1][j] + dp[i][j + 1] - dp[i][j] + d[i][j];

    FOR(i, 0, N + 1)FOR(j, 0, N + 1)FOR(k, 0, i)FOR(l, 0, j) {
        int num = (i - k)*(j - l);
        x[num] = max(x[num], dp[i][j] - dp[i][l] - dp[k][j] + dp[k][l]);
    }

    FOR(i, 0, N*N)x[i + 1] = max(x[i], x[i + 1]);

    FOR(i, 0, Q)
        cout << x[query[i]] << endl;

    return 0;
}