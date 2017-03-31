#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional> 
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
const int INF = 1e9;

/* -----  2017/03/31  Problem: JOI予選 2008 6  / Link: http://www.ioi-jp.org/joi/2007/2008-yo-prob_and_sol/2008-yo-t6/2008-yo-t6.html  ----- */
/* ------問題------

JOI国には，n 島の島があり， 各島には 1 から n までの番号が付けられている． 現在，JOI国では各島の間を結ぶ航路網の整備が進んでいる．

あなたは，船舶の切符を扱っているチケットセンターに勤務している．
JOI国には船舶を使って，できる限り安価に， 島と島の間を旅行したいと考えている人が沢山おり， 彼らは，出発地と目的地を注文票に記入して，あなたのところに送ってくる．
あなたの仕事は，客から注文票を受け取ったらすぐに， いくつかの船舶を乗り継いで， 出発地と目的地を結ぶ航路の中で， もっとも安価な運賃を計算し，客に伝えることである．
ただし，旅程によっては，船舶を使って旅行することが出来ない場合もある． そのときは『船舶を使って旅行することが出来ない』と客に伝える必要がある．
また，JOI国では，島と島の間を結ぶ新しい船舶が，次々と運航を開始しており， あなたには，その情報が随時伝えられる． 客に返事をする際には，最新の情報に留意しなければならない．

入力として，客の注文票や新たに運航を開始した船舶の運航情報が与えられたときに， 客への返事を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

ダイクストラ法を適宜使ってもK回行えばよいので間に合う。
最初greaterを入れ忘れて大変なことになった。

----解説ここまで---- */

ll N, K;
vector<pii>G[100];
ll ans = 0LL;

ll dijkstra(int s, int t) {
    priority_queue<pii, vector<pii>, greater<pii>>q;
    ll d[100];
    FOR(i, 0, 100)d[i] = INF;
    d[s] = 0;
    q.push(pii(0, s));
    while (!q.empty()) {
        int dis = q.top().first;
        int v = q.top().second;
        q.pop();
        if (d[v] < dis)continue;
        FOR(i, 0, G[v].size()) {
            int nv = G[v][i].first;
            int nc = G[v][i].second;
            if (d[v] + nc < d[nv]) {
                d[nv] = d[v] + nc;
                q.push(pii(d[nv], nv));
            }
        }
    }

    if (d[t] == INF)return -1;
    else return d[t];
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    FOR(i, 0, K) {
        int a, b, c, d;
        //cin >> a;
        scanf("%d", &a);
        if (a == 0) {
            //cin >> b >> c;
            scanf("%d%d", &b, &c);
            printf("%lld\n", dijkstra(b - 1, c - 1));
        }
        else {
            //cin >> b >> c >> d;
            scanf("%d%d%d", &b, &c, &d);
            G[b - 1].push_back(pii(c - 1, d));
            G[c - 1].push_back(pii(b - 1, d));
        }
    }

    return 0;
}
