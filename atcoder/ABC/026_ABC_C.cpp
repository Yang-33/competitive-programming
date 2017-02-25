#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
const int INF = 1e9;
typedef long long ll;

/* -----  2017/02/25  Problem: ABC026 C / Link: http://abc026.contest.atcoder.jp/tasks/abc026_c ----- */
/* ------問題------

高橋君は、社員が N 人いる会社の社長です。高橋君の会社では、以下のように給料が決まっています。

高橋君を含む社員の全員が、 1 から N までの社員番号を持っている。高橋君の社員番号はもちろん 1 である。
高橋君以外の社員には、必ず自分より社員番号が小さい上司がただ一人存在する。自分が上司になっている社員のことを、直属の部下と呼ぶ。
直属の部下がいない社員の給料は 1 であり、直属の部下がいる社員の給料は 、max(その社員の直属の部下の給料)+min(その社員の直属の部下の給料)+1 である。直属の部下が一人しかいない場合は、その部下の給料の 2 倍 + 1 が、その社員の給料となる。
この時、高橋君の給料を求めなさい。

-----問題ここまで----- */
/* -----解説等-----

有効グラフを作ってdfsさせた。
社員番号の大きい順に値を伝播させていくのも面白そう。

 ----解説ここまで---- */

ll N;
int b[30];
vector<int >v[30];
ll ans = 0LL;

ll dfs(int n) {
    ll rec;
    if (v[n].size() == 0)return 1;
    ll maxv = -INF, minv = INF;
    
    FOR(i, 0, v[n].size()) {
        ll num= dfs(v[n][i]);
        maxv = max(maxv, num);
        minv = min(minv, num);
    }

    rec = maxv + minv + 1;

    if (v[n].size() == 1) {
        rec = maxv * 2 + 1;
    }

    return rec;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 2, N + 1) {
        cin >> b[i];
        v[b[i]].push_back(i);
    }

    ans=dfs(1);

    cout << ans << endl;

    return 0;
}