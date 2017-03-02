#include<iostream>
#include<cstdio>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/02  Problem: ABC011 D / Link: https://abc011.contest.atcoder.jp/tasks/abc011_4  ----- */
/* ------問題------

XY 座標上に、スタート地点とゴール地点が 1 つずつあります。 スタート地点は (0,0) にあり、ゴール地点は (X,Y) です。
あなたは、ジャンプという移動法を用いて、移動を行います。 ジャンプを 1 回行うと、あなたは、以下の 4 つのうち、ランダムで選ばれた 1 つの移動が行われます。
X 軸に平行に +D だけ移動する。
X 軸に平行に ?D だけ移動する。
Y 軸に平行に +D だけ移動する。
Y 軸に平行に ?D だけ移動する。
これらの移動は、どれもちょうど 1?4 の確率で選択されます。
あなたは、最初にスタート地点におり、ちょうど N 回のジャンプでゴール地点にたどり着きたいです。
目的を達成できる確率を出力しなさい。

-----問題ここまで----- */
/* -----解説等-----

動的計画法では計算量が足りない。
上下左右の移動量を決定すればその組み合わせで解ける。

解法としてはあっていたけれどなぜＷＡしたのかわからない。桁あふれ?
引っ張り出す値の計算時に確率化するのではなく、テーブルを作る段階で割り算しとくと良さそう。
いい経験！？
>> double 型は10^308までしか値が収まりきらないことに起因しているらしい。
答えを曹宇数で出すのはちょっと危険で、確率で足しこんでいった方がエラーになりにくいとのこと。確かに。

 ----解説ここまで---- */

#define MAX_N 1010
ll N, D, X, Y;
double comb[MAX_N][MAX_N];
double ans = 0.0;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> D >> X >> Y;

    if (X % D != 0 || Y % D != 0) {
        cout << 0 << endl;
        return 0;
    }
    X /= D; Y /= D;

    FOR(i, 0, MAX_N)FOR(j, 0, MAX_N)comb[i][j] = 0;

    comb[0][0] = 1;

    FOR(i, 1, MAX_N) {
        comb[i][0] = comb[i - 1][0]/2;
        FOR(j, 1, MAX_N) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) / 2;
        }
    }
    FOR(i, 0, N + 1) {
        if ((i + X) % 2 == 1 || i - X < 0 || i + X < 0) continue;

        int right = (i + X) / 2, left = (i - X) / 2;
        int j = N - i;

        if ((j + Y) % 2 == 1 || j - Y < 0 || j + Y < 0) continue;

        int up = (j + Y) / 2, down = (j - Y) / 2;
        ans += comb[N][i] * comb[i][right] * comb[N-i][up];
    }
    printf("%.10lf¥n", ans);

    return 0;
}