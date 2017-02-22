#include<iostream>
#include<cstdio>
using namespace std;

typedef long long ll;

/* -----  2017/02/23  Problem: ABC028 D / Link: http://abc028.contest.atcoder.jp/tasks/abc028_d ----- */
/* ------問題------

2 つの整数 N、K が与えられます。
1 以上 N 以下の整数のなかからどれか 1 つ、等確率に選ぶ機械を考えます。
その機械を 3 回動かした時、選ばれた 3 つの数の中央値が K となる確率を求めてください。

-----問題ここまで----- */
/* -----解説等-----

場合分けをしたら終わってしまった。
３つとも違う値、2つはＫのとき、３つともＫのときを足し合わせたものが総組み合わせ。

 ----解説ここまで---- */

double N, K;

double temp = 0, ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    temp += 6 * (K - 1)*(N - K);
    temp += 3 * (K - 1) + 3 * (N - K);
    temp += 1;


    ans = temp / (N*N*N);
    printf("%.12f¥n", ans);

    return 0;
}