#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;
typedef long long ll;

/* -----  2017/03/02  Problem: ABC010 D / Link: https://abc010.contest.atcoder.jp/tasks/abc010_4 ----- */
/* ------問題------

高橋君の秘書のなぎさちゃんは、高橋君が大好きです。今日も、高橋君に悪い虫が取り憑かないように、高橋君を監視しなければなりません。
高橋君は、女の子と仲良くなるために、自前のSNSを使います。SNSで友人関係にある人を辿って行き、見つけた女の子にメッセージを送ります。 
なぎさちゃんは、高橋君のメッセージを女の子が見ることがないように、このSNSに対して、工作を行うことにしました。
行える工作活動は、以下の 2つです。
特定の二人の友人関係を解消する
特定の一人のパスワードを変え、ログイン出来なくする　高橋君のパスワードは変更できません。(21:11追記)
友人関係が解消されると、高橋君は、その二人の間を辿ることが出来なくなります。しかし、他の友人を経由して、辿ることが可能な場合は、その限りではありません。
パスワードを変更すると、その人は、メッセージを見ることが不可能になります。友人関係に変化はないので、パスワードを変更された人を辿って、別の友人を探すのは可能です。
なぎさちゃんは、出来るだけ工作の回数を少なくして、予めマークした女の子達が、高橋君のメッセージを閲覧できないようにしたいです。なぎさちゃんが工作を行う必要のある回数を求めてください。

-----問題ここまで----- */
/* -----解説等-----

グラフをうまく切断したいみたい。
操作２が厄介である。
各友人関係を容量1の枝で双方向に繋ぎ、高橋くんをsource、女の子から容量1で片方向につながれた頂点をsinkとするネットワークと考える。
ここで、各操作1が頂点間の枝を切断する操作であり、また、女の子以外に対して操作2を行う必要がないことを考えると、
操作2は女の子とsinkを結ぶ枝を切断する操作であることがわかる。
この操作を最小にしたいということは、求める答えは、このネットワークの最小カットである。
よって最大フロー=最小カット定理により、このネットワークの最大フローを求めれば良い。

冷静になぎさちゃんが怖すぎる。

https://gist.github.com/knuu/64ba401cfd58bd803e527cbd588ba721
つよそう


 ----解説ここまで---- */

int N, g, E;

int ans = 0LL;

#define MAX_V 130
struct edge {
    int to; int cap; int rev;
};
vector<edge> G[MAX_V];

bool used[MAX_V];

void add_edge(int from, int to, int cap) {
    G[from].push_back((edge) { to, cap, (int)G[to].size() });
    G[to].push_back((edge) { from, 0, (int)G[from].size() - 1 });
}

int dfs(int v, int t, int f) {
    if (v == t)return f;
    used[v] = true;

    FOR(i, 0, (int)G[v].size()) {
        edge &e = G[v][i];
        if (!used[e.to] && e.cap > 0) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}

int max_flow(int s, int t) {
    int flow = 0;
    for (;;) {
        memset(used, 0, sizeof(used));
        int f = dfs(s, t, INF);
        if (f == 0)return flow;
        flow += f;
    }
    return -1;
}


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> g >> E;
    FOR(i, 0, g) {
        int a; cin >> a;
        add_edge(a, N, 1);
    }

    FOR(i, 0, E) {
        int a, b;
        cin >> a >> b;
        add_edge(a, b, 1);
        add_edge(b, a, 1);
    }
    ans = max_flow(0, N);
    cout << ans << endl;

    return 0;
}