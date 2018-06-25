#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
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

/* -----  2018/06/25  Problem: AOJ 2511 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2511  ----- */
/* ------問題------

とある海域に，ミスト諸島と呼ばれる美しい自然と豊かな資源に恵まれた島々がある． 気候も温暖であるため，人々はそこで長きに渡って平和な暮らしを営んできた． しかし，最近になって大変な事実が判明した． 地殻変動によって，ミスト諸島の島々が遠からず沈没してしまうというのだ．
この事態に対応するため，各島の代表からなる対策本部が結成された． まず，調査隊の働きにより各島がいつ沈没してしまうかが明らかになった． また，ミスト諸島の技術を結集することで，いくつかの島の間には橋が架けられることも分かった． その結果，島の間に橋を架け，各島の住民が特定の島に避難できるようにすることに決まった．
現段階で，どの島を避難先にするかは決まっていないらしい． そのため，最初はどの島が避難先になっても良いよう，どの島からもいくつかの橋を渡ることで他の全ての島に行けるように橋を架ける． 時間の経過によって島が沈んだとき，両端の島が一方でも沈んだ橋は通行できなくなる． このとき，最初の橋の架け方によっては，ある島から辿りつけないような島ができてしまう場合がある． この場合は，新たに橋を架けることで，まだ沈んでいない島々の間で移動経路が確保できるようにする． どのように橋を架けても移動経路が確保できなくなった場合は，それ以上の橋の建設は行わない． 対策本部は，それまでに避難先を決め，住民の避難を完了させなくてはならないだろう． なお，現時点で既に移動経路を確保するように橋を架ける事が出来ない場合は，橋の建設は一切行わない． 対策本部は新たな案を練ることになるだろう．
ところで，橋は架ける位置によって建設費用が決まっている． 避難には何かと費用がかかるので，対策本部では橋の建設費用の合計がなるべく小さくなるように橋を架けたいと考えているようだ． そのためにはどのように橋を架ければ良いだろうか．

-----問題ここまで----- */
/* -----解説等-----

逆からUFしたくなる。
これは正しくて、どの橋を渡ってくるかについて最適になる。
新たに案を練ることは、逆の走査ではresetするだけで良いので適当にやれば良い。

----解説ここまで---- */


struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
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
// UnionFind uf(n); uf.unionSet(i,j); if(uf.same(x,y))




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, M;
	while (cin >> N >> M, M) {
		vector<PLL>H(N);
		FOR(i, 0, N) {
			int h;
			cin >> h;
			H[i] = PLL(h, i);
		}
		RSORT(H);
		H.push_back(PLL(-1, -1));

		using tp = tuple<int, int, int>;
		vector<tp> edges;
		FOR(i, 0, M) {
			int a, b, c;
			cin >> a >> b >> c;
			a--, b--;
			if (a > b)swap(a, b);
			edges.emplace_back(a, b, c);
		}

		sort(ALL(edges), [](const tp&a ,const tp& b) {
			int ca, cb;
			tie(ignore, ignore, ca) = a;
			tie(ignore, ignore, cb) = b;
			return ca < cb;

		});
		// なんかコスト0ニナルを忘れない
		int i;
		UnionFind uf(N);
		int cnt = 0;
		LL ans = 0;

		map<int, int>Map;
		for (i = 0; i < N; i++) {
			// 許可

			Map[H[i].second] = 1;
			while (H[i].first == H[i + 1].first) {
				Map[H[i+1].second] = 1;
				i++;
			}
			// idをくっつけたい
			FOR(k, 0, M) {
				int a, b, c; tie(a, b, c) = edges[k];
				if (Map[a] && Map[b] && !uf.same(a, b)) {
					ans += c;
					uf.unionSet(a, b);
					cnt++;
				}
			}
			if (cnt != i) {
				ans = 0;
				cnt = 0;
				uf = UnionFind(N);
			}

		}
		cout << ans << endl;


	}

	return 0;
}
