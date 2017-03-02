#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/02  Problem: ABC011 C / Link: https://abc011.contest.atcoder.jp/tasks/abc011_3 ----- */
/* ------問題------


あなたは、友人から、一人用のゲームを紹介されました。
最初に、数字 N が与えられます。 1 , 2 , 3 の中から好きな数字を選び、 与えられた数字に対し、引き算を行う、という処理を行うことできます。
この処理は 100 回まで行うことが可能であり、最終的に数字を 0 にすることが目標のゲームです。
しかし、計算途中でなってはいけないNG数字が 3 つ与えられており、 この数字に一時的にでもなってしまった瞬間、このゲームは失敗となります。
NG数字が N と同じ場合も失敗となります。
NG数字が N と同じ場合について、正しい判定が行われていませんでした。リジャッジを行いました。
あなたは、このゲームが、目標達成可能なゲームとなっているか調べたいです。
目標達成可能な場合はYES、そうでない場合はNOと出力してください。

-----問題ここまで----- */
/* -----解説等-----

ＮＧ数字がNと同じ点だけに注意。
動的計画法を使わなくても、3マスまでしか進めないことから貪欲に遠くに行けばよい。


 ----解説ここまで---- */

ll N, a, b, c;
bool m[301];
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> a >> b >> c;
    if (N == a || N == b || N == c) {
        cout << "NO" << endl;
        return 0;
    }
    FOR(i, 0, 301)m[i] = true;
    m[a] = false;
    m[b] = false;
    m[c] = false;

    int index = N;
    FOR(i, 0, 100) {
        if (m[index - 3] == true && index - 3 >= 0)index -= 3;
        else if (m[index - 2] == true && index - 2 >= 0)index -= 2;
        else if (m[index - 1] == true && index - 1 >= 0)index -= 1;
        else {
            cout << "NO" << endl;
            return 0;
        }
        if (index == 0) {
            cout << "YES" << endl;
            return 0;
        }
    }

    cout << "NO" << endl;

    return 0;
}