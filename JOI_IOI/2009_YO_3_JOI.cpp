#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
const int INF = 1e9;

/* -----  2017/03/31  Problem: JOI予選 2009 3  / Link: https://www.ioi-jp.org/joi/2008/2009-yo-prob_and_sol/2009-yo-t3/2009-yo-t3.html  ----- */
/* ------問題------

次のようなゲームがある．
あるキャラクターが縦 1 列に N 個並んでいる． これらのキャラクターの色は赤，青，黄のいずれかであり， 初期状態で同じ色のキャラクターが4つ以上連続して並んでいることはない．
プレーヤーは，ある位置のキャラクターを選び他の色に変更することができる． この操作により同じ色のキャラクターが4つ以上連続して並ぶとそれらのキャラクターは消滅する．
キャラクターが消滅することにより新たに同じ色のキャラクターが4つ以上連続して並ぶとそれらのキャラクターも消滅し，同じ色のキャラクターが4つ以上連続して並んでいる箇所がなくなるまでこの連鎖は続く．
このゲームの目的は， 消滅しないで残っているキャラクター数をなるべく少なくすることである．
例えば， 下図の左端の状態で， 上から6番目のキャラクターの色を黄色から青に変更すると， 青のキャラクターが5つ連続するので消滅し， 最終的に3つのキャラクターが消滅せずに残る．
初期状態における N 個のキャラクターの色の並びが与えられたとき， 1箇所だけキャラクターの色を変更した場合の， 消滅しないで残っているキャラクター数の最小値 M を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

最初の状態では色を消せない状態になっていることが保証されている。
ある場所を色ｊにするとして消していけばよい。
N*3*Nで≦3*10^8だが10秒なので間に合うだろうという感じ。
方針を変えて速くなる解ってあるのかな。
実装ゲーすぎる。

----解説ここまで---- */

int  N;

ll ans = 0LL;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int mini = INF;
    int m[10000];
    FOR(i, 0, N) {
        cin >> m[i];
    }
    FOR(i, 0, N)FOR(j, 0, 3) {
        int s = i, t = i;
        while (0 < s&&m[s - 1] == j)s--;
        while (t < N - 1 && m[t] == j)t++;
        for (;;) {
            int a = s - 1, b = t + 1;
            if (a < 0 || b >= N || m[a] != m[b])break;
            while (0 < a&&m[a] == m[a - 1])a--;
            while (b < N - 1 && m[b] == m[b + 1])b++;
            if (s - a + b - t >= 4)s = a, t = b;
            else break;
        }
        if (s != t)mini = min(mini, N - (t - s + 1));
    }
    ans = mini;
    cout << ans << endl;

    return 0;
}
