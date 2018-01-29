#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/01/29  Problem: AOJ 0304 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0304  ----- */
/* ------問題------

今日はＺ大学のオープンキャンパスです。毎年この日の昼休みには、大勢の高校生たちが学食に列をつくります。そこでＺ大学の事務局は、行列の長さが最大でどのくらいの距離になるかを予測することにしました。事前調査の結果で、以下のことが分かっています。 
• 行列にはそれぞれ 1 から N までの番号が振られた N 人が並びます。
• C 個の高校生のペア (ai, bi) それぞれについて、以下の２種類の制約があります： •１つ目の制約は順序に関するもので以下のいずれかです：
ai は bi よりも先、または同じ位置に並ばなくてはならない
ai は bi よりも後、または同じ位置に並ばなくてはならない
ai は bi より先でも、同じ位置でも、後でもよい
•２つ目の制約は距離に関するもので以下のいずれかです：
ai と bi は di メートル以上離れなければならない
ai と bi は di メートル以内に並ばなければならない

また、先頭から同じ距離の場所に複数の人が並ぶことができ、行列の先頭には常に番号 1 の人が並ぶことが分かっています。 
与えられた C 個の制約をすべて満たす行列について、先頭から最後尾までの距離が最大となるような並び方をした場合の距離を求めるプログラムを作成してください。ただし、どこまでも離れることができる場合は inf と、制約を満たす並び方が不可能な場合は -1 と出力してください。 

-----問題ここまで----- */
/* -----解説等-----

なんか制約条件がLPになるけど式に出てくる変数の数から最短経路になるアレ？
->そう
制約式は、"*"であるanyなパターンを除いて d(from) + cost >= d(to)
のような形に書き換えられる。
したがってこれは最短路問題に帰着できる。
anyなパターンは全通り試せばいいため、計算量的には大丈夫。
先頭の人が1さんで、0の位置にいることはわかっているので、あとはベルマンフォードで求める。
最大路が最短路になっている点、負の値は取らない点に注意すれば解ける。

----解説ここまで---- */

/* ベルマンフォード 経路復元なし
負辺に対しても最短経路を求めることができる
頂点に着目した遷移を行う？
閉路検出は頂点の更新回数がV-1回を超えたときに閉路検出としてこれを出力する
O(VE) */

struct Edge {
	int to, cost;
	Edge(int t, int c = 0) : to(t), cost(c)
	{}
	bool operator>(const Edge& rhs) const {
		return cost > rhs.cost;
	}
	bool operator<(const Edge& rhs) const {
		return cost < rhs.cost;
	}

};
typedef vector< vector<Edge> > Graph;


//precondition: d.size == V
//O(V*E)
int BellmanFord(const Graph& G) {
	const int V = G.size();
	VI d(V, INF);
	d[0] = 0;
	FOR(i, 0, V) {
		FOR(j, 0, V) {
			FOR(k, 0, SZ(G[j])) {
				Edge e = G[j][k];
				if (d[e.to] > d[j] + e.cost) {
					d[e.to] = d[j] + e.cost;
					if (i == V - 1 || d[e.to] < 0)return -1;
				}
			}

		}
	}
	//FOR(i, 0, V) {
	//	cout<<d[i] <<" ";
	//}cout << endl;
	return *max_element(ALL(d));
}
LL N, C;

LL A[202], B[202], OP[202], PM[202], D[202];

LL ans = 0LL;
int numb(string &s, int &i) {
	int ret = 0;
	while (isdigit(s[i])) {
		ret *= 10;
		ret += s[i] - '0';
		i++;
	}
	return ret;
}
void parse(string &s, int &i) {
	int a, b, c, op1, op2;
	a = numb(s, i);
	static int cnt = 0;
	op1 = 0;
	if (s[i] == '*') { i++, op1 = 2; }
	else if (s[i] == '>') {
		i += 2;	op1 = 1;
	}
	else {
		i += 2;	op1 = 0;
	}

	b = numb(s, i);

	op2 = 0;
	if (s[i] == '+') {
		op2 = 1;
	}
	i++;
	c = numb(s, i);
	A[cnt] = a - 1; B[cnt] = b - 1; D[cnt] = c;
	OP[cnt] = op1; PM[cnt] = op2;
	cnt++;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> C;
	VI IDs;
	FOR(i, 0, C) {
		string s;
		cin >> s;
		int idx = 0;
		parse(s, idx);
		if (OP[i] == 2)IDs.push_back(i);

	}
	ans = -1;
	FOR(i, 0, (1 << (SZ(IDs)))) {
		FOR(j, 0, SZ(IDs)) {
			OP[IDs[j]] = (i&(1 << j) ? 1 : 0);
		}
		Graph G(N);
		FOR(i, 0, C) {
			if (OP[i] == 0) {// <=
				G[B[i]].push_back(Edge(A[i], 0));
				if (PM[i] == 0) {// -
					G[A[i]].push_back(Edge(B[i], D[i]));
				}
				else {// +
					G[B[i]].push_back(Edge(A[i], -D[i]));
				}
			}
			else { // -
				G[A[i]].push_back(Edge(B[i], 0));
				if (PM[i] == 0) {
					G[B[i]].push_back(Edge(A[i], D[i]));
				}
				else {// +
					G[A[i]].push_back(Edge(B[i], -D[i]));
				}
			}

		}
		ans = max(ans, (LL)BellmanFord(G));
	}
	if (ans >= INF) {
		cout << "inf" << endl;
	}
	else
		cout << ans << "\n";

	return 0;
}
