#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/02  Problem: ABC012 C / Link: https://abc012.contest.atcoder.jp/tasks/abc012_3 ----- */
/* ------問題------

高橋君は、先日、九九の表を全て暗記することに成功しました。
九九で物足りなくなった高橋君は、 1 × 1 から 9 × 9 までの値を、全て足してみることにしました。
高橋君は、九九のうちの一つの答えを忘れてしまったので、その計算を後回しにして、残りの和を求めたところ、N になりました。
しかし、高橋君は、後回しにした問題がどれだか解らなくなってしまいました。
高橋君が後回しにしてしまった問題として、あり得るものを辞書順で全て出力しなさい。

-----問題ここまで----- */
/* -----解説等-----

整数問題を制約の中で全探索すれば通る。
Ｎの制約から簡単に解けそうだったので書いたら通った。
可換なものかつ制約の整数内なものは制約上の整数をひとつづつ進めればよい。

 ----解説ここまで---- */

ll N;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int left = 2025 - N;

    FOR(i, 1, 10) {
        int a = left / i;
        if (!(a*i == left && 1 <= a&&a <= 9))continue;
        cout << i << " x " << a << endl;
    }

    return 0;
}