#include <iostream>
using namespace std;
typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/27  Problem: JOI莠磯∈2007 4  / Link: http://www.ioi-jp.org/joi/2006/2007-yo-prob_and_sol/2007-yo-problems/2007-yo-t4/2007-yo-t4.html  ----- */
/* ------蝠城｡

1 から 2n の数が書かれた 2n 枚のカードがあり， 上から 1, 2, 3, ... , 2n の順に積み重なっている．
このカードを， 次の方法を何回か用いて並べ替える．

整数 k でカット
上から k 枚のカードの山 A と 残りのカードの山 B に分けた後， 山 A の上に山 B をのせる．
リフルシャッフル
上から n 枚の山 A と残りの山 B に分け， 上から A の1枚目， B の1枚目， A の2枚目， B の2枚目， …， A の n枚目， B の n枚目， となるようにして， 1 つの山にする．
入力ファイルの指示に従い， カードを並び替えたあとのカードの番号を， 上から順番に出力するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

計算量がO(N*M)で間に合うので愚直にシュミレートする。

----解説ここまで---- */

ll N, M;

ll ans = 0LL;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int c[205], d[205];
    cin >> N >> M;
    FOR(i, 0, 2 * N) {
        c[i] = i + 1;
    }

    FOR(x, 0, M) {
        int k; cin >> k;
        if (k == 0) {
            FOR(i, 0, N) {
                d[2 * i] = c[i];
                d[2 * i + 1] = c[N + i];
            }
        }
        else {
            FOR(i, 0, k) {
                d[2 * N - k + i] = c[i];
            }
            FOR(i, 0, 2 * N - k) {
                d[i] = c[k + i];
            }
        }
        FOR(i, 0, 2 * N)c[i] = d[i];
    }
    FOR(i,0,2*N)
    cout <<c[i] << endl;

    return 0;
}
