#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/04/03  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

木の直径を求めるが、木に対して一本の辺を削除し木である状態を維持したまま、
辺を追加し木の直径を最大にする。
まず直径を求め、その直径を通る頂点を逆向きからたどって使用済みとする。
逆向きから通れば一意に頂点は定まる。
次3度目のdfsでは使用済み頂点から使用済みの頂点ではない頂点の末端までの距離を求めるようにし、
この値が存在すれば、1+直径+枝の距離　が答えとなる
もし存在しなければ直径自身が答え。

----解説ここまで---- */

ll N;
#define MAX 500100
ll ans = 0LL;
vector<int>G[MAX];
int d[MAX];
bool visit[MAX];
int count;
int maxn = 0;
void bfs(int s) {//???????????????
    FOR(i, 0, N) {
        d[i] = INF;
    }
    queue<int >Q;
    Q.push(s);
    d[s] = 0;
    int u;

    while (!(Q.empty())) {
        u = Q.front(); Q.pop();

        FOR(i, 0, G[u].size()) {
            int e = G[u][i];

            if (d[e] == INF) {
                d[e] = d[u] + 1;
                Q.push(e);
            }
        }
    }
}

int solve() {
    int maxv = 0, top;
    bfs(0);
    FOR(i, 0, N) {
        if (d[i] == INF)continue;
        if (maxv < d[i]) {
            maxv = d[i];
            top = i;
        }
    }

    bfs(top);
    maxv = 0;
    int t;
    FOR(i, 0, N) {
        if (d[i] == INF)continue;
        if (maxv<d[i]) {
            maxv = max(maxv, d[i]);
            t = i;
        }
    }
    int xx = maxv;// t <=> top
    queue<int >q;
    q.push(t);
    visit[t] = true;
    maxv--;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        FOR(i, 0, G[v].size()) {
            int nv = G[v][i];
            if (d[nv] == maxv) {
                q.push(nv);
                visit[nv] = true;
                maxv--;
            }
        }


    }
    return maxv;
}

int solve2() {
    int m = -1;;
    FOR(i, 0, N) {
        if (visit[i] == false) {
            dfs2(i);
        m=max(m,)
        }
    }

    return m;
}
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >> N;
  FOR(i, 0, N) {
      int s, t;
      cin >> s >> t;
      s--; t--;
      G[s].push_back(t);
      G[t].push_back(s);
  }
  FOR(i, 0, N) {
      visit[i] = false;
  }
  int dir=solve();
  maxn = solve2();
  ans = 1 + dir + maxn;
  cout << ans << endl;

  return 0;
}
