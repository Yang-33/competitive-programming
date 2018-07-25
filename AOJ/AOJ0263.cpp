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

/* -----  2018/07/26  Problem: AOJ 0263 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0263  ----- */
/* ------問題------

遊太君は、近所のゲームセンターで人気のゲーム「ビートパネル」にはまっています。このゲームは図のようなグリッド状に並べられた 4×4 の計16個のパネル型のボタンからなります。
図のように、左上から右下にボタン1, ボタン2, …, ボタン16の順にボタンが並んでいます。ゲームでは一定間隔でビート音が鳴り最後に終了音が鳴ります。ビート音が鳴ると同時に複数のボタンが光ります。１個も光らない場合もあります。プレイヤーは、ビート音が鳴った直後から次の音が鳴るまでの間に両手の指を使って複数のボタンを１度だけ同時に押すことができます。何も押さないということも可能です。終了音が鳴ったと同時にゲームは終了します。
遊太君は c 通りの押し方を習得しており、ビート音が鳴る度に、それらの押し方の中から１つ決めてボタンを押します。押したボタンが光っていれば、それらのボタンの光は消え、消えたボタンの数がプレイヤーのスコアに加算されます。また、一度光ったボタンはそのボタンが押されるまで光は消えることはありません。
ビート音が n 回鳴るときのボタンの光り方と遊太君が習得している c 通りのボタンの押し方を入力とし、遊太君が獲得することのできる得点の最大値を出力するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

最終的な解に対して行動の是非は分からない。よってDPをする。
着いている電気を状態にdpする。
隣接しか関係していないので、メモリが足りないときは[2]でできる。

----解説ここまで---- */

template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;


int dp[32][1 << 16];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, C;
	while (cin >> N >> C, N) {
		V<int>quiz(N);
		FOR(i, 0, N) {
			int ret = 0;
			FOR(j, 0, 16) {
				int a; cin >> a;
				ret *= 2;
				ret += a;
			}
			quiz[i] = ret;
		}
		V<int>pat(C);
		FOR(i, 0, C) {
			int ret = 0;
			FOR(j, 0, 16) {
				int a; cin >> a;
				ret *= 2;
				ret += a;
			}
			pat[i] = ret;
		}
		int ans = 0;
		// NC2^16で max add dp
		fill(*dp, *dp + 32 * (1 << 16), -1);
		dp[0][0] = 0;
		FOR(i, 0, N) {
			FOR(state, 0, 1 << 16) {
				if (dp[i][state] == -1)continue;
				int nstate = state | quiz[i];
				FOR(j, 0, C) {
					int add = nstate & pat[j];
					int nnstate = nstate - add;
					dp[i + 1][nnstate] = max(dp[i + 1][nnstate], dp[i][state] + __builtin_popcount(add));
				}
				dp[i + 1][nstate] = max(dp[i + 1][nstate], dp[i][nstate]);
			}
		}
		FOR(i, 0, 1 << 16) {
			ans = max(ans, dp[N][i]);
		}
		cout << ans << endl;
	}

	return 0;
}