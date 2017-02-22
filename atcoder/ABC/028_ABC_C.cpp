#include<iostream>
#include<set>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/02/23  Problem: ABC028 C / Link: http://abc028.contest.atcoder.jp/tasks/abc028_c ----- */
/* ------問題------

異なる整数が 5 個与えられます。
この中から 3 つ選んでその和で表すことの出来る整数のうち、3 番目に大きいものを出力してください。

-----問題ここまで----- */
/* -----解説等-----

重複要素を選ばないようにしてsetで管理。三番目に大きいものを求めたいのでイテレーターを３つずらせばよい。

 ----解説ここまで---- */

int a[5];
set<int >s;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    FOR(i,0,5)
    cin >> a[i];

    FOR(i, 0, 5)FOR(j, 0, 5)FOR(k, 0, 5) {
        if (i != j&&j != k&&k != i) {
            s.insert(a[i] + a[j] + a[k]);
        }
    }
    auto it = s.end();
    it--;
    it--;
    it--;

    ans = *it;
    cout << ans << endl;

    return 0;
}