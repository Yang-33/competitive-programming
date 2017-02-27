#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
const int INF = 1e9;
typedef long long ll;

/* -----  2017/02/27  Problem: ABC021 C / Link: http://abc021.contest.atcoder.jp/tasks/abc021_c ----- */
/* ------問題------

あなたと高橋君は、AtCoder 王国に住んでいます。AtCoder 王国には、N 個の町と、町どうしを結ぶ M 本の道路が存在し、それらは双方向に移動可能です。
N 個の町はそれぞれ 町 1,町 2,…,町 N と呼ばれています。 また、M 個の道路はそれぞれ 道路 1,道路 2,…,道路 M と呼ばれています。
高橋君はあなたの家に遊びに行くことにしました。
そして、高橋君は町 a から出発して、AtCoder 王国のいくつかの町（0 個でも良い）を経由して町 b にあるあなたの家に到着しました。
高橋君は最短経路を辿ってきたと主張しています。 高橋君は正直なので、絶対に嘘をつきません。
そこで、あなたは町 a から町 b への最短経路が何通りあるかを数えることにしました。
答えは非常に大きくなる可能性があるので、実際の答えを 1,000,000,007(=109+7) で割った余りを出力してください。
町 a から町 b への最短経路とは、町 a から町 b への移動経路において道路を通る回数が最小となるような経路のことを言います。

-----問題ここまで----- */
/* -----解説等-----

非優先度付きキューdijkstraの実行中に、pathの数も数える。
次頂点までの最短距離が現在の頂点からの最短距離と同じときにはそこまでのpathを加える。
最短路を更新した場合にはpath数を上書きする。
昔解いてた。　昔よりも高速になっていた。嬉しい

 ----解説ここまで---- */

ll N, a, b, M;
vector<pair<int, int>>G[100];
ll ans = 0LL;

ll d[100], path[100];
bool used[100];

void dijkstra(int a) {
    FOR(i, 0, N) {
        d[i] = INF * 10;
        used[i] = false;
        path[i] = 0;
    }

    d[a] = 0;
    path[a] = 1;
    queue<int>Q;
    Q.push(a);

    while (!Q.empty()) {
        int u = Q.front();
        Q.pop();
        if (used[u] == false) {
            used[u] = true;
            FOR(i, 0, G[u].size()) {
                int v = G[u][i].first; int cost_v = G[u][i].second;
                if (used[v] == false) {
                    Q.push(v);
                    if (d[v] > d[u] + cost_v) {
                        d[v] = d[u] + cost_v;
                        path[v] = path[u];
                    }
                    else if (d[v] == d[u] + cost_v) {
                        path[v] = (path[v] + path[u]) % MOD;
                    }
                }
            }
        }
    }

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> a >> b >> M;
    a--; b--;
    FOR(i, 0, M) {
        int x, y; cin >> x >> y;
        x--; y--;
        G[x].push_back(make_pair(y, 1));
        G[y].push_back(make_pair(x, 1));
    }

    dijkstra(a);

    ans = path[b] % MOD;

    cout << ans << endl;

    return 0;
}