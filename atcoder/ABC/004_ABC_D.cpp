#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const ll LINF = 1e16;

/* -----  2017/03/08  Problem: ABC004 D / Link: http://abc004.contest.atcoder.jp/tasks/abc004_4 ----- */
/* ------問題------

一直線上に無限個の箱が並んでいます。それぞれの箱に、左から右にかけて …,?2,?1,0,1,2,… の番号が付いています。
いま、番号が ?100 の箱に赤いマーブルが R 個入っています。同様に、番号が 0 の箱に緑のマーブルが G 個、番号が 100 の箱に青いマーブルが B 個入っています。これら以外の箱には何も入っていません。
以下の操作を繰り返して、全ての箱に入っているマーブルの個数が 1 個以下になるようにして下さい。
マーブルを 1 つ選び、それを左右どちらかの隣接する箱に移動させる。
ただしこのとき、1 つの箱に複数の異なる色のマーブルを入れてはならない。
必要となる最小の操作回数を求めてください

-----問題ここまで----- */
/* -----解説等-----

緑のマーブルの左端の位置を全探索し、それに対応した各マーブルの左端の位置を決定しそこから移動にかかるコストを計算していけばよい。
なんで昔解けなかったんだろう。

 ----解説ここまで---- */

ll N,R,G,B;

ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> R>>G>>B;
    ans = LINF;

    FOR(i, -600, 601) {
        int Rl = min(i - R, -100 - R / 2);
        int Bl = max(i + G, 100 - B / 2);
        ll c = 0;
        FOR(s, Rl, Rl + R) {
            c += abs(-100 - s);
        }
        FOR(s, i, i + G) {
            c += abs(s);
        }
        FOR(s, Bl, Bl + B) {
            c += abs(100 - s);
        }
        ans = min(ans, c);
    }
    

    cout << ans << endl;
    
    return 0;
}