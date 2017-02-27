#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;
typedef long long ll;

/* -----  2017/02/28  Problem: ABC019 D / Link: http://abc019.contest.atcoder.jp/tasks/abc019_4 ----- */
/* ------問題------

あなたは２頂点間の距離を質問することができる。
Nが与えられるので 木の直径をリアクティブ問題として2N回以内の質問で求めよ。

-----問題ここまで----- */
/* -----解説等-----

AOJで覚えた木の直径そのままである。
「任意の頂点から最も遠い点を基準にした最も遠い点が木の直径」
これは三つの場合分けで正当性を示すことができる。

解答としては　適当に１から全ての点までの距離を知り、最も遠い頂点を知る。
次にそこを基準として最も遠い頂点までの距離を質問して求める。
2N-2回の質問で解くことができる。おわり

 ----解説ここまで---- */

ll N;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    ll x = -INF, y;
    ll id;

    FOR(i, 2, N + 1) {
        cout << "? " << 1 << " " << i << endl;
        cin >> y;
        if (x < y) {
            x = y;
            id = i;
        }
    }

    FOR(i, 1, N + 1) {
        if (i == id)continue;
        cout << "? " << id << " " << i << endl;
        cin >> y;
        ans = max(ans, y);
    }

    cout << "! " << ans << endl;
    fflush(stdout);
    return 0;
}