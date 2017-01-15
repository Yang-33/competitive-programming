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
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;
ll N;

/* 2016/12/31 問題 ----- AOJ_DPL_1_G Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_G ----- */
/* -----解説等-----
問題:　個数制限付きナップザック問題
価値が v_i 重さが w_i であるような N 種類の品物と、容量が W のナップザックがあります。

次の条件を満たすように、品物を選んでナップザックに入れます：

選んだ品物の価値の合計をできるだけ高くする。
選んだ品物の重さの総和は W を超えない。
i 番目の品物は m_i 個まで選ぶことができる。


N*W*max(M) <= 10^10 (Over)
=> 無理だあ・・・
[蟻本 p.302]<< N*W or N*W*log m で解ける（らしい）

[N*W の解法]
dequeの様に両端の操作が可能なデータ構造を持つようにすればスライド最小Ｏ(W)の形で解くことができる。
スライド最小値がここで効いてきた

[N*W*log m の解法]
m = 1 + 2 + 4 + ... + 2^x + a ( 0 <= a < 2^(x+1) )
としてWに関して最終的な解を求めていく。ただしWに関してのみ解くことができるので、
計算を終えた後にWの値を変更してしまうと正しい解は得られなくなるために初期化が必要
０１ナップザック問題に帰着させている。
dp[W] := 重さWにおける価値の最大値
*/

#define MAX_N 100
#define MAX_W 10000

ll dp[MAX_W + 1];
ll v[MAX_N]/*価値*/, w[MAX_N],/*重さ*/ m[MAX_N]/*個数*/;
ll W;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> W;
    FOR(i, 0, N) {
        cin >> v[i] >> w[i] >> m[i];
    }

    FOR(i, 0, N) {
        ll num = m[i];
        for (ll k = 1; num > 0; k <<= 1) {
            ll mul = min(k, num);// 2^(k-1) or a
            for (ll j = W; j - w[i] * mul >= 0; j--) {
                dp[j] = max(dp[j], dp[j - w[i] * mul] + v[i] * mul);
            }
            num -= mul;
        }
    }

    cout << dp[W] << endl;

    return 0;
}