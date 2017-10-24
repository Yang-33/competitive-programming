#include "bits/stdc++.h"
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
int DX[8] = { 0, 1, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, 0, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/18  Problem: 20_d  / Link: http://joi2009ho.contest.atcoder.jp/tasks/joi2009ho_d  ----- */
/* ------問題------

問題
JOI町に住む太郎君は，ある日，健康増進のために散歩を日課にしようと思い立った．
太郎君の住む JOI 町には，図のように，東西方向に走る (H + 1) 本の道路と，南北
方向に走る (W + 1) 本の道路が碁盤目状に通っている．太郎君の家はもっとも北西の
交差点にあり，ここから散歩を開始する．
以降，北から a 番目，西から b 番目の交差点を (a, b) で表す．たとえば，太郎君の
家がある交差点は (1, 1) である．
太郎君は，散歩のルートが日々違ったほうが面白いと考えたので，(1, 1)から(H, W)
までの H × W 個の交差点に，「東」または「南」の文字を書き，次のようなルールに
従って毎日散歩を行うことにした．
• 文字の書かれた交差点にいる場合，その交差点に書かれている文字が「東」な
ら「南」に，「南」なら「東」に文字を書き換え，もともと書かれていた文字の
方角にある次の交差点まで進む．
• もっとも東やもっとも南の道路に到達したら散歩を終了する．
この計画を考えた後，太郎君は，将来の散歩で自分がどのようなルートをたどる
ことになるのかが気になった．太郎君のために，太郎君の N 回目の散歩のルートを
予測するプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

毎回地図を書き換えているところを実験すると各点を通る回数がなんとなくわかる。
それは正しくて右と下にN/2ぐらい渡すことになるので、さいしょの方角をみながらわたす量を決めていけばよい。
N-1回目を終えた地図が分かればうれしいのでこれをつくってあとはシュミレーションをする。

----解説ここまで---- */

LL H, W, N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W >> N;
	VVL masu(H + 1, VL(W + 1, 0));
	VVL sum(H + 1, VL(W + 1, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> masu[i][j];
		}
	}
	LL n = N - 1;
	sum[0][0] += n;
	FOR(i, 0, H) {
		FOR(j, 0, W) {//右と下に渡す
			LL R = (masu[i][j] == 1 ? (sum[i][j]+1) / 2: sum[i][j] / 2);
			LL D = (masu[i][j] == 0 ? (sum[i][j]+1) / 2 : sum[i][j] / 2);
			sum[i + 1][j] += D;
			sum[i][j + 1] += R;
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			masu[i][j] = 1 & (masu[i][j] ^ sum[i][j]);
		}
	}
	queue<PII>q;
	q.push(PII(0, 0));

	while (!q.empty()) {
		PII a = q.front();
		q.pop(); int h, w;
		h = a.first, w = a.second;
		int k = masu[h][w];
		int nh = h + DY[k]; int nw = w + DX[k];
		if (nh == H || nw == W) {
			cout << nh+1 << " " << nw+1 << endl;
			return 0;
		}
		else {
			if (0 <= nh&&nh < H && 0 <= nw&&nw < W) {
				q.push(PII(nh, nw));
			}
		}

	}

	return 0;
}