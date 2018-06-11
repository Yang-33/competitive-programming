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

/* -----  2018/06/10  Problem: AOJ 2775 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2775  ----- */
/* ------問題------

※この問題はリアクティブ問題です．すなわち，サーバー側に用意されたプログラムと対話的に応答することで正答を導くプログラムを作成する必要があります． また、サーバー側のプログラムも計算機資源を共有する関係上、サーバーだけで最大 3 sec程度の実行時間、最大 300 MB程度のメモリを使用する場合がありますので、TLE・MLEにお気をつけください。
あいずにゃんは若ヶ松高校のプログラミングコンテスト部、通称ぷろこん部に所属する2年生である。見目麗しい。あいずにゃんはその小さな体も無限に存在するチャームポイントの1つであるが、本人はコンプレックスを感じているようだ。そのせいか、一列に並んでいる人たちを見ると、それぞれの人の前方にその人より身長が高い人が何人並んでいるかを瞬時に数えられる能力を持っている。
プロコンの名門・律命館大学中等部卒のエリート競技プログラマであり、ぷろこん部の部長であるりっつちゃんは、あいずにゃんのこの能力を使えば、並んでいる人たちがそれぞれ何番目に背が高いのかを当てることができるのではないかと考えた。
今、りっつちゃんはN人が並んでいる列をあいずにゃんに見せている。りっつちゃんは、人がN人並んでいることは知っているが、その並び順がどうなっているかはわからない。りっつちゃんはあいずにゃんに “l番目の人からr番目の人までコンプレックス度” を教えてもらうことができる。ここで、l番目の人からr番目の人までのコンプレックス度とは、i (l≤i≤r) 番目の人それぞれに関して、l番目からi−1番目までの間にいる自分 (i) より背が高い人の人数の総和である。(より厳密な定義は入出力形式を参照のこと)
(うらやましいことに) ぷろこん部の部員であるあなたは、(とても、とても心苦しいが) あいずにゃんをオラクルとして利用することで身長順を当てるプログラムを書くようりっつちゃんに命じられた。つらい。せめてあいずにゃんに負担をかけないよう、少ない質問回数で求められるよう頑張ろう。

-----問題ここまで----- */
/* -----解説等-----

[1:X]で質問をする。
差分から、X-1,Xの間の数がわかるので、使用していない数字から二分探索をすれば良い。

----解説ここまで---- */

struct BIT {
	int N, nn; vector<int> data;
	BIT(int n) {
		N = n + 1;
		data = vector<int>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, int w) {
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	int sum(int i) { // [0,i)
		int ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l,r)
	int sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

void solve() {
	int N;
	cin >> N;
	BIT bit(N);
	FOR(i, 0, N) {
		bit.add(i, 1);
	}
	LL kim = N;
	VI ans(N, -1);
	VI SET(N, 0);
	cout << "? 1 " << N << endl;
	cin >> kim;
	for (int i = N - 1; i >= 1; i--) {
		cout << "? 1 " << i << endl;
		LL nx; cin >> nx;
		LL val = kim - nx + 1;
		int l = 0; int r = N;
		FOR(unchi, 0, 30) {
			int mid = (l + r) / 2;
			if (bit.sum(mid, N) >= val) {
				l = mid;
			}
			else r = mid;
		}
		ans[i] = l;
		SET[l] = 1;
		if (bit.sum(l, l + 1) == 1)bit.add(l, -1);
		kim = nx;
	}
	FOR(i, 0, N) {
		if (!SET[i])ans[0] = i;// , debug(i);
	}
	cout << "!";
	FOR(i, 0, N) {
		assert(ans[i] != -1);
		cout << " " << ans[i] + 1;
	}
	cout << endl;

}

signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();

	return 0;
}