#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  2017/03/01  Problem: ABC014 D / Link: https://abc014.contest.atcoder.jp/tasks/abc014_4 ----- */
/* ------問題------

n 個の頂点と n?1 本の辺からなる連結な無向グラフが与えられます．それぞれの頂点には 1 から n までの番号が順番にふられています．
グラフ理論において，このような条件を満たすグラフは木と呼ばれ，閉路を含まないという性質があります．
このグラフに対し，元のグラフに含まれない追加辺 (a,b) を1つ追加したグラフについて考えてみると，このグラフはちょうど1つの閉路を含みます．
あなたの仕事は，そのようなグラフについて，閉路の長さ(閉路に含まれる辺の数)を出力することです．
ただ，追加辺の候補はいくつかあり，Q 個与えられるので，それら全ての候補について答えを出力してください．

-----問題ここまで----- */
/* -----解説等-----

LCAを検索し、深さ(a) + 深さ(b) - 2*深さ(LCA(a,b)) +1
が答えとなる。前処理により一回の質問に対してlog Nで答えることができる。Ｏ(Q log N).
蟻本に感謝

 ----解説ここまで---- */

ll N,Q;
vector<int>G[100010];
int depth[100010];
int root = 0;
int parent2[20][100010];
ll ans = 0LL;

void dfs2(int v, int p, int d) {
    parent2[0][v] = p;
    depth[v] = d;
    FOR(i, 0, G[v].size()) {
        if (G[v][i] != p) {
            dfs2(G[v][i], v, d + 1);
        }
    }
}

void init2(int V) {
    dfs2(root, -1, 0);
    for (int k = 0; k + 1 < 20; k++) {
        FOR(v, 0, V) {
            if (parent2[k][v] < 0)parent2[k + 1][v] = -1;
            else parent2[k + 1][v] = parent2[k][parent2[k][v]];
        }
    }
}

int lca2(int u, int v) {
    if (depth[u] > depth[v])swap(u, v);//vのほうが深くする

                                       /* 深さをそろえる */
    FOR(k, 0, 20) {
        if ((depth[v] - depth[u]) >> k & 1) {
            v = parent2[k][v];
        }
    }

    /* 特例　片側がすでに祖先そのもの */
    if (u == v)return u;

    /* 深さが一緒なのであとはたどるだけ　実質 増加系の二分探索 */
    for (int k = (20)-1; k >= 0; k--) {
        /* 条件から境界線の一つ手前まで進む */
        if (parent2[k][u] != parent2[k][v]) {
            u = parent2[k][u];
            v = parent2[k][v];
        }
    }
    return parent2[0][u]; //一段上る
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int x, y;
    FOR(i, 0, N-1) {
        cin >> x >> y;
        x--; y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    root = 0;
    init2(N);

    cin >> Q;
    FOR(i, 0, Q) {
        cin >> x >> y;
        x--; y--;
        ans = depth[x] + depth[y] - 2 * depth[lca2(x, y)] + 1;
        cout << ans << endl;
    }

    return 0;
}