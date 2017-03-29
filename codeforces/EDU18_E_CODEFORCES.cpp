#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/28  Problem: codeforces Educatinal18 E / Link: http://codeforces.com/contest/792/problem/E  ----- */
/* ------問題------

N個の箱の中にAi個のボールが入っている。
それぞれの箱ごとに異なる色が割り振られており、次のような分割方法で最小の分け方を考えたい。
１：全てのボールを振り分ける
２：空の集合はない
３：同じ色のみの集合しか作ってはならない
４：各集合ごとの大きさの差は１より大きくなってはならない
以上を満たす集合の最小サイズを求めよ。

-----問題ここまで----- */
/* -----解説等-----

４の条件から二分探索はできない。
またAiの大きさは10^9なので全探索はできない。
そこで1つの集合の大きさを考える。
Aiが大きな値のときこれを√Ai以上の値で割ると、余りと集合の大きさがかけ離れて正しい分割方法ではなくなってしまう。
このことから[1,√Ai+1]と[√Ai/k](k=1,...,√Ai)を調査していけばよい。
条件から省かれるものとして、Aiをある集合のサイズで分割したときにできる集合の数が復元可能か、
＝＞最後にできる集合の大きさが小さいと条件４を満たさない　があるのでこれを答えから除外されるようにすればよい。
ゼロで割り算ができないのでc++としたら通った。


----解説ここまで---- */

ll N;
ll a[510];


ll f(int c) {
    c++;
    bool check = true;
    ll sum = 0;
    FOR(i, 0, N) {
        int x = (a[i] + c - 1) / c;
        int y = x*c - a[i];
        if (y > x) {
            check = false;
            break;
        }
        sum += x;
    }
    if (check) return sum;
    else return 1e18;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

//    cin >> N;
    scanf("%lld", &N);
    FOR(i, 0, N) {
  //      cin >> a[i];
        scanf("%lld", &a[i]);
    }


    ll ans = 1e18;

    FOR(c, 1, 1e5)
        ans = min(ans, f(c));
   // debug(ans);
    FOR(c, 1, 1e5) {
        ans = min(ans, f(a[0] / c));
        if (a[0] % c == 0) ans = min(ans, f((a[0] / c) - 1));
    }
    printf("%lld\n", ans);
    //cout << ans << endl;

    return 0;
}
