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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/02/19 問題 ----- ABC032 D /Link http://abc032.contest.atcoder.jp/tasks/abc032_d */
/* -----解説等-----
問題: 0/1ナップサック問題を解いてください。0/1ナップサック問題とは以下のような問題のことです。

N 個の荷物があり、i(1≦i≦N) 番目の荷物には価値 vi と重さ wi が割り当てられている。
許容重量 W のナップサックが1つある。
重さの和が W 以下となるように荷物の集合を選びナップサックに詰め込むとき、価値の和の最大値を求めよ。
ただし、同じ荷物は一度しか選ぶことができない。
1 行目には、荷物の数を表す整数 N(1≦N≦200) とナップサックの許容重量を表す整数 W(1≦W≦109) が空白区切りで与えられる。
2 行目からの N 行には、各荷物の情報が与えられる。
そのうち i(1≦i≦N) 行目には、i 番目の荷物の価値を表す整数 vi(1≦vi≦109) と重さを表す整数 wi(1≦wi≦109) が空白区切りで与えられる。
「N≦30」、「全てのi(1≦i≦N) について 1≦wi≦1000」、「全てのi(1≦i≦N) について 1≦vi≦1000」という 3 つの条件のうち少なくとも1つの条件が成り立つ。
部分点
この問題には部分点が設定されている。満点は 100 点である。

N≦30 を満たすデータセット 1 に正解した場合は、34 点が与えられる。
N≦200 かつ全ての i(1≦i≦N) について 1≦wi≦1000 を満たすデータセット 2 に正解した場合は、上記の点数とは別に 33 点が与えられる。
N≦200 かつ全ての i(1≦i≦N) について 1≦vi≦1000 を満たすデータセット 3 に正解した場合は、上記の点数とは別に 33 点が与えられる。


解法
データセットによって、以下のものを選択させる

半分全列挙 => 最小をとるやつDP => おなじみDP

最適なものをそれぞれのデータセットに対して選んであげればよい。
最小をとるやつ Ｏ( N*MAX_V_SUM )     dp[ N個まで商品を選択できる ][ 価値がＶ ]:= 重さの最小値

inf 以下かつ W以下で最大の dp[N][j]のjを選択
おなじみ Ｏ( N*W )    dp[ Ｎ個までの商品を選択できる ][ 重さがW以下 ]:= 最大の価値

*/

#define INF (LLONG_MAX/10)
ll N;
ll W; ll v[200], w[200];
ll dp[210][210 * 1000];
pair<ll, ll>ps[1 << (32 / 2)];
bool flag = false;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> W;
    FOR(i, 0, N) {
        cin >> v[i] >> w[i];
        if (w[i] > 1000)flag = true;
    }

    if (N < 31) { //meet in the middle
                  /* solve */
        ll fn = N / 2; /* first half N */

        for (ll i = 0; i < (1 << fn); i++) {
            ll sw1 = 0, sv1 = 0; /* part source w and source v */
            FOR(j, 0, fn) {
                if ((i >> j) & 1) {
                    sw1 += w[j];
                    sv1 += v[j];
                }
            }
            ps[i] = make_pair(sw1, sv1);
        }

        // Optimisation
        sort(ps, ps + (1 << fn));
        ll m = 1; /* new ps point => m */
        for (ll i = 0; i < (1 << fn); i++) {
            if (ps[m - 1].second < ps[i].second) {
                ps[m++] = ps[i];
            }
        }

        ll ans = 0;
        ll sn = N - fn; /*second half N */
        FOR(i, 0, (1 << sn)) {
            ll sw2 = 0, sv2 = 0;
            FOR(j, 0, sn) {
                if ((i >> j) & 1) {
                    sw2 += w[fn + j];
                    sv2 += v[fn + j];
                }
            }

            if (sw2 <= W) {
                ll tv; /* part target v */
                tv = (lower_bound(ps, ps + m, make_pair(W - sw2, INF)) - 1)->second;
                ans = max(ans, sv2 + tv);
            }
        }

        /* out */
        cout << ans << endl;
    }
    else if (flag) { // min dp case 3
        FOR(i, 0, 1000 * 200 + 1) {
            dp[0][i] = INF;
        }//最小値がほしいのでINFに。
        dp[0][0] = 0;


        FOR(i, 0, N) {//品物
            FOR(j, 0, 200 * 1000 + 1) {//価値
                if (j - v[i] >= 0) {
                    //生成した状態が同じループで影響を与えないようにするので次元拡張=>次の状態にのみ影響させる
                    dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
                }
                else {
                    dp[i + 1][j] = dp[i][j]; //何もできないので前の状態を引き継ぐ
                }
            }
        }

        ll ans = 0;
        FOR(j, 0, 200 * 1000 + 1) {
            if (dp[N][j] <= W)
                ans = j; //大きぃのがほしぃの?

        }

        cout << ans << endl;
    }
    else { // typical dp case2
        FOR(i, 0, N) {
            FOR(j, 0, W + 1) {
                if (j - w[i] >= 0)
                    dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
                else dp[i + 1][j] = dp[i][j];
            }
        }
        /* 添え字をずらしたので注意（拡張したのを忘れていた） */
        cout << dp[N][W] << endl;
    }


    return 0;
}
