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

/* -----  2017/02/28  Problem: ABC018 D / Link: http://abc018.contest.atcoder.jp/tasks/abc018_4 ----- */
/* ------問題------

あるクラスには女子が N 人、男子が M 人いる。女子には 1 から N までの出席番号が、男子には 1 から M までの出席番号が割り当てられている。
幸運のキューピットはここから女子 P 人と男子 Q 人からなる、1 つの旅行グループを作る。
N 人の女子は合わせて R 個のチョコレートを持っており、チョコレートには 1 から R までの番号が付けられている。
チョコレート i(1≦i≦R) は出席番号が xi である女子が持っており、旅行中に出席番号が yi である男子に渡す予定である。
そのため旅行グループに出席番号が xi である女子と出席番号が yi である男子が両方含まれていた場合に限り渡すことができる。
無事にチョコレート i が渡された場合の幸福度は zi である。
無事に渡されたチョコレートによる幸福度の合計値として考えられる最大値はいくらか。

-----問題ここまで----- */
/* -----解説等-----

組合わせ数が膨大ではないため半分全列挙。同じ男子に渡す可能性もあるので縮約し、
渡す候補のうち値の高い男を上からＱ人取る。

 ----解説ここまで---- */

ll N, M, P, Q, R;
vector<pair<ll, ll>>v[20];
ll happy[20];
ll ans = 0LL;

int countbit(int n) {
    int ret = 0;
    while (n) {
        n &= n - 1;
        ++ret;
    }
    return ret;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> P >> Q >> R;
    FOR(i, 0, R) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        v[a].push_back(make_pair(b, c));
    }

    FOR(i, 0, (1 << N)) {
        int bitc = countbit(i);
        if (bitc != P)continue;
        FOR(x, 0, 20)happy[x] = 0;
        FOR(j, 0, N) {
            if (i >> j & 1) {
                FOR(y, 0, v[j].size()) {
                    int to = v[j][y].first;
                    int cost = v[j][y].second;
                    happy[to] += cost;
                }
            }
        }
        sort(happy, happy + 20);
        ll rec = 0;
        FOR(s, 0, Q) {
            rec += happy[19 - s];
        }
        ans = max(ans, rec);
    }
    cout << ans << endl;

    return 0;
}