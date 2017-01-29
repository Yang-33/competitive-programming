#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/29 問題 ----- ABC035 D /Link http://abc035.contest.atcoder.jp/tasks/abc035_d */
/* -----解説等-----
問題: 高橋君が住む国には N 箇所の町と町同士をつなぐ一方通行の道が M 本あり、それぞれの町には 1 から N の番号が割りふられています。
i 番目の道は ai 番の町から bi 番の町へ移動することが可能であり、移動に ci 分だけかかります。

所持金が 0 円の高橋君は T 分間のトレジャーハントに出かけることにしました。高橋君は開始 0 分の時点で 1 番の町にいます。
また、開始から T 分の時点にも 1 番の町にいなくてはなりません。
高橋君が i 番の町に 1 分間滞在すると、 Ai 円が高橋君の所持金に加算されます。
T 分間のトレジャーハントによって高橋君の所持金は最大いくらになるか求めてください。


頂点滞在で得られるお金について考えたとき、どの頂点でも同様に1分でお金を得ることができる。(これで最大となる)
よって頂点1に戻るまでの時間を差し引いて残った時間である頂点に滞在し続けることを考える。

つまり1->K->1となる最短経路を考えるが、これを愚直に求めようとするとMNlogMで間に合わない。
K->1について、今回は有効グラフであるから逆辺を生成すれば一周する最短路を
1->K(有効正グラフ) + K->1(有効逆辺グラフ)で求めることができる。
すなわちダイクストラ法を二回行えばよい。
その後、頂点1から移動しある頂点で滞在したときにお金はいくら手に入るのかを全探索すればよい。

ライブラリ化したいと思って少し整備した。
c++の勉強が普通に足りない。

*/


/* 非頂点管理 Dijkstra */
struct edge {
    int v; ll w;
    edge() {}
    edge(int v, ll w) : v(v), w(w) {};
};

/* 非頂点管理 Dijkstra
edge G, 頂点数 N, 始点 s
return vector<ll> 頂点に対するsからの距離
全頂点探索可能 O(MlogN)?
経路復元機能: 未実装
*/
vector<ll> Dijkstra(int n, vector<vector<edge> >& G, int s) {
    vector<ll> d(n, LLONG_MAX / 10); // 頂点初期化
    d[s] = 0; // 頂点sを0で初期化
    priority_queue<pair<ll, int> > que; //優先度付きqueue 降順(距離、頂点)
    que.push(make_pair(0ll, s)); // push(距離,頂点)
    while (!que.empty()) {
        pair<ll,int> p = que.top(); que.pop(); //pair
        int u = p.second; //頂点
        ll dist = -p.first; //頂点uまでの距離
        if (dist > d[u]) continue; //最適でないならば考慮しない
        FOR(i, 0, G[u].size()) { //頂点uからはi本の辺が存在
            int vv = G[u][i].v; // u->vv
            if (d[vv] > d[u] + G[u][i].w) { //経路短縮可能=>更新
                d[vv] = d[u] + G[u][i].w;
                que.push(make_pair(-d[vv], vv)); //push(-距離,頂点) //ここはこのままで頼む
            }
        }
    }
    return d;
}


#define MAX_N 100000
int N, M, T;
int a[MAX_N];
vector<vector<edge>>G(MAX_N);
vector<vector<edge>>rG(MAX_N);
ll ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> T;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, M) {
        int s, t, c; cin >> s >> t >> c;
        s--; t--;
        G[s].push_back(edge(t, c));
        rG[t].push_back(edge(s, c));
    }

    vector<ll>d = Dijkstra(N, G, 0);
    vector<ll>rd = Dijkstra(N, rG, 0);

    FOR(i, 0, N) {
        ll tt = d[i] + rd[i];
        if (tt > T)continue;
        ans = max(ans, (T - tt)*a[i]);
    }

    cout << ans << endl;

    return 0;
}