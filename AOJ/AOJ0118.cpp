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

/* -----  2017/11/11  Problem: AOJ 0118 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0118  ----- */
/* ------問題------

タナカ氏が HW アールの果樹園を残して亡くなりました。果樹園は東西南北方向に H×W の区画に分けられ、区画ごとにリンゴ、カキ、ミカンが植えられています。タナカ氏はこんな遺言を残していました。
果樹園は区画単位でできるだけ多くの血縁者に分けること。ただし、ある区画の東西南北どれかの方向にとなりあう区画に同じ種類の果物が植えられていた場合は、区画の境界が分からないのでそれらは 1 つの大きな区画として扱うこと。
例えば次のような 3 × 10 の区画であれば ('リ'はリンゴ、'カ'はカキ、'ミ'はミカンを表す)
雪が降って区画の境界が見えなくなる前に分配を終えなくてはなりません。あなたの仕事は果樹園の地図をもとに分配する区画の数を決めることです。
果樹園の地図を読み込み、分配を受けられる血縁者の人数を出力するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

四方向に各マス一回だけ色塗りをしていけばよい。
連続して塗ることを一回にカウントして、何カウント必要かをみればよい。

----解説ここまで---- */

int H, W;
LL ans = 0LL;
VVI visit;
VS masu;

void dfs(int i, int j,char c) {
	visit[i][j] = 1;
	FOR(k, 0, 4) {
		int ny = i + DY[k]; int nx = j + DX[k];
		if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {
			if (masu[ny][nx] == c&&visit[ny][nx]==-1)dfs(ny, nx, c);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> H >> W, H) {
		ans = 0;
		masu = VS(H);
		visit = VVI(H, VI(W, -1));
		FOR(i, 0, H) {
			cin >> masu[i];
		}
		FOR(i, 0, H) {
			FOR(j, 0, W) {
				if (visit[i][j] == -1)dfs(i, j,masu[i][j]), ans++;
			}
		}


		cout << ans << "\n";
	}

	return 0;
}
