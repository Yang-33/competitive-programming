#include<iostream>
#include<vector>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define pb(i) push_back(i)

/* -----  2017/03/12  Problem: ARC056 B / Link: http://arc056.contest.atcoder.jp/tasks/arc056_b ----- */
/* ------問題------

駐車場でN人が車を駐めようとしています。 駐車場はN個の駐車スペースがあり1からNまで番号付けられています。
また、2つの駐車スペースを双方向に結ぶ道がM本あり、i番目の道はui番目の駐車スペースとvi番目の駐車スペースを結んでいます。 
駐車スペースSは駐車場の入り口とつながっています。
i番目の人は、どういうわけかi番目の駐車スペースにしか車を駐めたくないようです。
このため、駐車場の入り口から、まだ誰も車を駐めていない駐車スペースとそれらを結ぶ道を通ってi番目の駐車スペースに行くことができないとき、車を駐めずに帰ってしまいます。
1番目の人からN番目の人まで順番に駐車場にやってきます。最終的に駐車場に駐める人の番号を昇順に出力してください。

-----問題ここまで----- */
/* -----解説等-----

i番目の頂点に駐車をしたとき、その番号の駐車場を通ることはできない。
したがってi番目の駐車場に到達するにはi番目の駐車場よりも多き番号の駐車場を通る必要がある。
これは値の大きい駐車場からさらに値の大きい駐車場に辺を張っていき、Ｓから到達可能かをUFで判定していけばよい。
ダイクストラ変形の解法はかっこいい。

----解説ここまで---- */

/* Union Find */
struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

ll N, M, S;
vector<int> G[200000];
vector<int> ans;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> S;
	S--;
	FOR(i, 0, M) {
		int x, y; cin >> x >> y;
		x--; y--;
		G[x].pb(y);
		G[y].pb(x);
	}

	UnionFind uf1;
	uf1.init(N);

	FORR(i, N - 1, -1) {
		FOR(j, 0, G[i].size()) {
			int nv = G[i][j];
			if (nv >= i)uf1.unionSet(i, nv);
		}
		if (uf1.same(S, i))ans.pb(i);
	}

	sort(ans.begin(), ans.end());

	FOR(i,0,ans.size())
	cout << ans[i]+1 << endl;

	return 0;
}