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

/* -----  2018/06/23  Problem: AOJ 2824 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2824  ----- */
/* ------問題------

海岸には毎秒波が押し寄せる．基準点 P を超えて何 m の地点まで波が押し寄せたかを，T 秒の間だけ毎秒観測し記録したデータがある．データは T 個の整数 x1, ..., xT からなり，各 i (1 ≤ i ≤ T) に対し，観測を始めてから i 秒後には地点 P からちょうど xi m の地点までの波が押し寄せ，海水に浸っていたことを表す．
海岸は，最後に海水に浸ってから D 秒後に乾くことが分かっている．ここで，乾くまでの時間は最後に海水に浸った時間のみに依存し，それ以前に波に浸っていた回数や時間には依存しないことに注意せよ．
基準点 P から，陸の方向に距離 L だけ離れた地点が，観測を開始してから 1 秒後と T 秒後の間に少なくとも何秒間濡れていたかを求めよ．ただし，時刻 0 で海岸は乾いていたことがわかっている．

-----問題ここまで----- */
/* -----解説等-----

問題文を誤読しまくったのでかなしい
ポインタ的なものをすすめればよい

----解説ここまで---- */

int main(void) {
	cin.tie(0); ios_base::sync_with_stdio(false);


	int N, D, L;
	while (cin >> N >> D >> L, N || L || D) {
		vector<int>a(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> a[i];
		}

		int ans = 0; int cnt = 0; int left = -2;
		int s = 1;
		for (int i = 1; i < N; i++) {

			if (a[i] >= L) {
				left = D;
			}
			if (left >= 0) {
				left--;
				if (left >= 0)ans++;
			}
			else {
				left--;
			}

		}
		cout << ans << endl;
	}
	return 0;
}