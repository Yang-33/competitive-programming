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
int DX[9] = { 0,0, 0, 1, -1, 1, 1, -1, -1 };    int DY[9] = { 0,1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/02/23  Problem: 061_arc_b / Link: https://abc045.contest.atcoder.jp/tasks/arc061_b?lang=en_  ----- */
/* ------問題------

縦 H 行、横 W 列のマス目からなる盤があります。最初、どのマス目も白く塗られています。
すぬけ君が、このうち N マスを黒く塗りつぶしました。i 回目 ( 1≤i≤N ) に塗りつぶしたのは、 上から ai 行目で左から bi 列目のマスでした。
すぬけ君がマス目を塗りつぶした後の盤の状態について、以下のものの個数を計算してください。
各整数 j ( 0≤j≤9 ) について、盤の中に完全に含まれるすべての 3 行 3 列の連続するマス目のうち、黒いマスがちょうど j 個あるもの。

-----問題ここまで----- */
/* -----解説等-----

検索のとき楽になるようにmapの恩恵を受ける。
pair<int,int>をもってこれをsortしてから数えてもいいっぽい

----解説ここまで---- */

LL H, W, N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W >> N;
	map<PII, int>Map;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		a--, b--;
		FOR(k, 0, 9) {
			int ny = a + DY[k], nx = b + DX[k];
			if (1 <= ny&&ny < H-1 && 1 <= nx&&nx < W-1) {
				Map[PII(ny, nx)]++;
			}
		}
	}
	VL cnt(10, 0);
	int sum = 0;
	for (auto it = Map.begin(); it != Map.end(); it++) {
		cnt[(*it).second]++;
		sum++;
	}
	cnt[0] = (H-2)*(W-2) - sum;
	FOR(i, 0, 10) {
		cout << cnt[i] << endl;
	}

	return 0;
}
