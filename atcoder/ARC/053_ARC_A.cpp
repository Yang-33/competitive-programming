#include<iostream>
using namespace std;

typedef long long ll;

/* -----  2017/03/09  Problem: ARC053 A / Link: http://arc053.contest.atcoder.jp/tasks/arc053_a ----- */
/* ------問題------

縦 H マス、横 W マスの白いマス目があります。
高橋君は、上下または左右に隣り合う 2 マスを選び、それら 2 マスを黒く塗ります。
高橋君が 2 マスを黒く塗る方法は何通りか求めてください。

-----問題ここまで----- */
/* -----解説等-----

片側のサイズが１であるとその向きの塗り方はできない。

 ----解説ここまで---- */

ll H, W;

ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W;
    if (W > 1)
        ans += H*(W - 1);
    if (H > 1)
        ans += W*(H - 1);
    cout << ans << endl;

    return 0;
}