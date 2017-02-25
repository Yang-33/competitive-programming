#include<iostream>
using namespace std;

typedef long long ll;

/* -----  2017/02/25  Problem: ABC027 C / Link: http://abc027.contest.atcoder.jp/tasks/abc027_c ----- */
/* ------問題------

高橋君と青木君が以下のような二人ゲームで勝負する。
まず、正の整数 N が与えられる。 また、変数 x を 1 に初期化する。高橋君から始め、高橋君と青木君が交互に次の操作を行う。
x の値を 2x または 2x+1 に置き換える。
x が N よりも大きくなったとき、最後に操作を行った人が負けである。
二人が最善を尽くすとき、どちらが勝つか求めよ。

-----問題ここまで----- */
/* -----解説等-----

手書きで実験する。
勝ちの区間の法則が1,4,4,16,16,32,32,...となっているので順番にこれを判定していけばよい

また、解説には深さの偶奇によって戦略が変わると書いてあり、Ｎの深さが偶数のときは1人目は左に分岐して二人目は右に分岐するのが最適。
奇数のときは逆になる。
これを実際に動かして計算させればよい。

 ----解説ここまで---- */

ll N;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    if (N == 1) {
        cout << "Aoki" << endl;
    }
    else {
        ll x = 1;
        for (ll i = 4;; i = i * 4) {
            x += i;
            if (x >= N) {
                cout << "Takahashi" << endl;
                break;
            }
            x += i;
            if (x >= N) {
                cout << "Aoki" << endl;
                break;
            }

        }
    }
    return 0;
}