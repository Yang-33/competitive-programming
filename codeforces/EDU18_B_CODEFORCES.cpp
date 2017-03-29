#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/28  Problem: codeforces Educatinal18 B / Link: http://codeforces.com/contest/792/problem/B  ----- */
/* ------問題------

1-n番の人が円を描くように座っている。Aiが与えられるのでプレーヤーを親から順に数えその番号の人を除外する。
除外された次の人が親都とし、最初の親は１とする。
除外された人を順に出力せよ。

-----問題ここまで----- */
/* -----解説等-----

番号にとらわれずにある位置にいる人を削除していけばよい。
剰余を使う際は剰余の数そのものが表現されないのでこれを場合分けすればよい。

----解説ここまで---- */

ll N, k;

ll ans = 0LL;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> k;
    int a[100];
    FOR(i, 0, k) {
        cin >> a[i];
    }
    vector<int >v;
    FOR(i, 0, N + 1)v.push_back(i);

    ll p = 1;
    ll num = N;
    FOR(i, 0, k) {
        ll next;
        if ((p + a[i]) % num == 0) {
            next = num;
        }
        else  next = (p + a[i]) % num;
        cout << v[next];
        v.erase(remove(v.begin(), v.end(), v[next]));
        num--;
        if (next > num)next = 1;
        p = next;
        if (i != k - 1)cout << " ";
    }

    return 0;
}
