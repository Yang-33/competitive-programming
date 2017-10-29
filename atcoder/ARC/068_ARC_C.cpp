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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_i  / Link: http://arc068.contest.atcoder.jp/tasks/arc068_c  ----- */
/* ------問題------

すぬけくんは鉄道会社を運営するゲームで遊ぶことにしました。すぬけ鉄道には M+1 個の駅があり、 0 から M までの番号がついています。 すぬけ鉄道の列車は駅 0 から d 駅ごとに停車します。 例えば d=3 のとき駅 0,駅 3,駅 6,駅 9, … に停車します。

すぬけ鉄道が走っている地域には N 種類の名産品があり、種類 i の名産品は 駅 li,駅 li+1,駅 li+2, …, 駅 ri のいずれかに列車が停車したとき購入することが可能です。

列車が停車する間隔 d は 1,2,3,…,M の M 種類が存在しています。 M 種類の列車それぞれについて、その列車に駅 0 で乗車した場合に購入可能な名産品の種類数を求めなさい。 なお、列車から別の列車への乗り換えは許されないものとします。

-----問題ここまで----- */
/* -----解説等-----

いろいろな嘘解法をはやした。しかしこの嘘解法の考察から、なぜ嘘解法が嘘になるのかで考察が進むとよかったなあ
嘘では後ろから埋めていき、素数倍の点から情報を回収し、
区間はBITで頑張る感じだった。これでも重複が出てしまう。
重複をなくしたいと考えたときに、区間幅で考えるというのができなかった

区間幅で考えたとき、自分のジャンプする幅よりも大きい区間は必ず通る。
したがってこれを除いた自分のジャンプ幅よりも小さい区間のお土産の種類を求めればよい。
これはUNIQUEなものであることが分かるので、数えても重複が起こるような問題はない。
累積和の部分は、そのままやるといけないけどBITでこれはできる。
今日、累積和も平衡二分木のすごい縮小機能をもつものと考えていたので解法を聞いたときとてもしっくり来た

----解説ここまで---- */

LL N, M;

// BIT 簡易の方 1indexの方
template<typename type>struct BIT {int N;int nn;vector<type> data;
BIT(int n) {N = n + 1;data = vector<type>(n + 1, 0);nn = 1;while (nn * 2 <= N)nn *= 2;}
void add(int i, type w) {for (int x = i; x <= N; x += x & -x) {data[x] += w;}}
type sum(int i) {type ret = 0;for (int x = i; x > 0; x -= x & -x) {ret += data[x];}return ret;}};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	VI width[100005];
	BIT<int> bit(100005);
	FOR(i, 0, N) {
		int l, r;
		cin >> l >> r;
		width[r-l+1].push_back(l);
	}
	int Size = N;
	FOR(i, 1, M + 1) {//幅iについて
		Size -= SZ(width[i - 1]);
		int ans = Size;
		FOR(j, 0, SZ(width[i - 1])) {
			bit.add(width[i - 1][j], 1);
			bit.add(width[i - 1][j]+i-1, -1);
		}
		for (int j = i; j <= M; j += i) {//ここにあるのは重複する可能性はない
			ans += bit.sum(j);
		}
		cout << ans << endl;
	}

	return 0;
}
