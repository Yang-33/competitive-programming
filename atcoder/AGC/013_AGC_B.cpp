#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/04/15  Problem: AGC 013 B / Link: http://agc013.contest.atcoder.jp/tasks/agc013_b  ----- */
/* ------問題------

N 頂点 M 辺の、連結な単純無向グラフが与えられます。
頂点には 1 から N までの番号がついており、辺には 1 から M までの番号がついています。
辺 i は、頂点 Ai と頂点 Bi を結んでいます。 次の条件を満たすパスを 1 つ見つけて、出力してください。

2 個以上の頂点を通る
同じ頂点を 2 度以上通らない
パスの少なくとも一方の端点と直接辺で結ばれている頂点は、必ずパスに含まれる
ただし、この問題の制約の下で、このようなパスが必ず存在することが証明できます。
また、あり得る答えのうちどれを出力しても構いません。

-----問題ここまで----- */
/* -----解説等-----

グラフの端から端にパスを形成すれば必ず答えになる。
また、パスを形成する際には頂点から1辺だけを延ばせばよい。
パスの末端について、ここから出ている辺がすべてパスに含まれていればパスを形成できない、
またこれが答えになる。
パスの作成は任意の頂点から始めた場合には2方向に、末端から始めた場合には1方向にパスを作る必要がある。

----解説ここまで---- */

vector<int >G[100100];
bool node[100100];
vector<ll>ans;
vector<ll>ans2;
void dfs(int v, int f) {
	node[v] = true;
	ans.push_back(v);
	bool flag = false;
	FOR(i, 0, G[v].size()) {
		if (flag == false) {
			if (node[G[v][i]] == false) {
				dfs(G[v][i], v);
				flag = true;
			}
		}
		else return;
	}
	return;
}
void dfs2(int v, int f) {
	node[v] = true;
	if (f != 0)
		ans2.push_back(v);
	bool flag = false;
	FOR(i, 0, G[v].size()) {
		if (flag == false) {
			if (node[G[v][i]] == false) {
				dfs2(G[v][i], v);
				flag = true;
			}
		}
		else return;
	}
	return;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	ll N, M;
	FOR(i, 0, 100100) {
		node[i] = false;
	}
	cin >> N >> M;
	FOR(i, 0, M) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int p = 1;
	FOR(i, 1, N + 1) {
		if (G[i].size() == 1)p = i;
	}
	dfs(p, 0);
	dfs2(p, 0);
	
	cout << (int)ans.size() + (int)ans2.size() << endl;
	FORR(i, (int)ans2.size()-1,-1) {
		cout <<ans2[i]<< " ";
	}
	FOR(i, 0, (int)ans.size()) {
		cout << ans[i];
		if (ans.size() - 1 != i)cout << " ";
	}

	cout << endl;
	return 0;
}
