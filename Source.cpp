#include<iostream>
#include<algorithm>
#include<vector>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;
ll N, W;

/* 2017/01/10 問題 -----  Name AOJ_DPL_1_H /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H */
/* -----解説等-----
問題: 巨大ナップザック問題
価値が vi 重さが wi であるような N 個の品物と、容量が W のナップザックがあります。次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
価値の合計の最大値を求めてください。

1 ? N ? 40
1 ? v_i ? 10^15
1 ? w_i ? 10^15
1 ? W ? 10^15

数が圧倒的に多いのでnWでは到底不可能
Nが小さいので半分全列挙の考え方を用いて計算量を落としていくことを念頭に置く。
2^n ≦ 2^40 通り(Over)であったものが 高々 2^20≒10^6 となった
前半部分の全列挙では(重さ、価値)でソートし、後半部分では重さが W-(生成した重さ)≧0
のときに限り価値の最大値を更新しようとすればよい
この際に W-(生成した重さ)の値に最も近いがそれより重さが少なくそれを満たす中での最大の価値を
ソート済みである ps から二分探索で求めればよい。

*/


#define MAX_N 40
#define INF (LLONG_MAX/10)
ll v[MAX_N], w[MAX_N]; /* 価値と重さ */

pair<ll, ll>ps[1 << (MAX_N / 2)];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    /* in */
    cin >> N >> W;
    FOR(i, 0, N) {
        cin >> v[i] >> w[i];
    }

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

    return 0;
}