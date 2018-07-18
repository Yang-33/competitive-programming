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

/* -----  2018/07/23  Problem: AOJ 0559 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0559  ----- */
/* ------問題------

情報オリンピック日本委員会では，今年の日本情報オリンピック (JOI) を宣伝するために， JOI のロゴをモチーフにした旗を作ることになった．旗は「良い旗」でなければならない．「良い旗」とは，アルファベットの J, O, I のいずれかの文字を，縦 M 行，横 N 列の長方形状に並べたもので， J, O, I が以下の図のように (すなわち，J の右隣に O が，その J の下隣に I が) 並んでいる箇所が旗の少なくとも 1 か所にあるものである．
いま M, N の値，および旗の一部の場所について J, O, I のどの文字にするかが決まっており，入力としてその情報が与えられる．考えられる「良い旗」は何通りあるかを計算し，その数を 100000 (=105) で割った余りを出力するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

重複が存在するので、禁止パターンが何種類存在するかを数え上げて、3^cntから引く。
重複の存在は、列を保存するbitDPをすれば判定できる。上にJOがあるときに、Iをおいてはいけないことと、JOが成立しているかどうかを
保存しておけばいいので、これを持つ。

この問題を通すのに一年かかってませんか(…)

----解説ここまで---- */


using LL = long long; template<class T> using V = vector<T>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	const LL mod = 100000;
	int W, H; cin >> H >> W;
	V<string>vs(H);
	FOR(i, 0, H) {
		cin >> vs[i];
	}
	V<int>dp(1 << (W - 1), 0);
	dp[0] = 1;
	auto add = [&mod](int &x, int y) {
		x += y;
		x %= mod;
	};
	FOR(i, 0, H) {// 禁止パターンを数え上げる
		FOR(j, 0, W) {
			V<int>nx(1 << (W - 1), 0);
			FOR(state, 0, 1 << (W - 1)) {
				if (dp[state] == 0)continue;
				int ns = state & ~(1 << (j - 1));
				if (vs[i][j] == 'J' || vs[i][j] == '?') {
					if (j < W - 1) {
						add(nx[ns | 1 << j], dp[state]);// jを追加
					}
					else {
						add(nx[ns &~(1 << j)], dp[state]);
					}
				}
				if (vs[i][j] == 'O' || vs[i][j] == '?') {
					add(nx[state&~(1 << j)], dp[state]); // o
				}
				if (vs[i][j] == 'I' || vs[i][j] == '?') { // iをおいては置いてはいけないことはないときに置いてしまっても以降に問題はない
					if (!(state & 1 << j)) {
						add(nx[ns&~(1 << j)], dp[state]);
					}
				}
			}
			dp.swap(nx);
		}
	}
	LL ans = 1;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (vs[i][j] == '?')ans *= 3;
			ans %= mod;
		}
	}
	//debug(ans);
	auto dec = [&mod](LL x, LL y) {
		LL ret = (x - y + mod) % mod;
		return ret >= 0 ? ret : ret + mod;
	};
	FOR(i, 0, 1 << (W - 1)) {
		//cout << dp[i] << endl;
		ans = (dec(ans, dp[i])) % mod;
	}
	cout << ans << endl;


	return 0;
}
