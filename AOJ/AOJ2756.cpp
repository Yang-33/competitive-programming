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

/* -----  2018/06/10  Problem: AOJ 2756 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2756  ----- */
/* ------問題------

南北方向に H ，東西方向に W の大きさの町がある． 町には一辺の長さが 1 の正方形の区画に隙間なく整備されており，全ての区画に 1 軒ずつ家が建っている．
この町のある区画の上空で台風が発生し，被害を与えた後，ある区画の上空で温帯低気圧に変化した． 変化した後は被害を与えない． 下図のように，台風は高さ 3, 幅 3 の正方形であり， ★のついたマスを中心と呼ぶことにする．台風は 8 近傍に区画単位で移動する． つまり，台風の中心は辺または頂点を共有する区画(現在の区画を含む)に移るように，全体を伴って移動する． ただし，町の外に台風がはみ出ることはなく， 台風の中心は，下の図の網掛けのように，北から 0 番目と H−1 番目，西から 0 番目と W−1 番目の区間は通らないように移動する．
家は台風が一度上空に来ると，以下のように被害の程度が変化する．
損壊ナシ → 一部損壊 → 半壊 → 全壊 → 跡形ナシ
だが，幸い跡形ナシとなった家は無かったようだ． 各家の被害の状況が与えられるので，台風が発生した地点と，温帯低気圧に変化した地点を求めよ． ただし，発生した区画を北から si 番目，西から sj 番目， 温帯低気圧に変化した区画を北から ti 番目，西から tj 番目とすると， 2 つの地点は 10000ti+tj ≤ 10000si+sj を満たすように定まる．

-----問題ここまで----- */
/* -----解説等-----

左上からなめると、台風の中心の道がわかる。3という値から、戻ったりはしないことがわかる。
したがって道が1つに定まる。始点終点の候補はたくさんあるかもしれないが、候補をsortして上と下を取れば良い。

----解説ここまで---- */


void solve() {
	int H, W; cin >> H >> W;
	VVI m(H, VI(W));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			cin >> m[i][j];
		}
	}

	VVI cent(H + 10, VI(W + 10, 0));
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (m[i][j]) {
				cent[i + 1][j + 1] = 1;
				int x = m[i][j];
				for (int k = 0; k < 2 + 1; k++) {
					for (int l = 0; l < 2 + 1; l++) {
						m[i + k][j + l] -= x;
					}
				}
			}
		}
	}

	vector<PII>pos;
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			if (cent[i][j]) {
				int cnt = 0;
				for (int k = -1; k < 2; k++) {
					for (int l = -1; l < 2; l++) {
						if (cent[i + k][j + l])cnt++;
					}
				}
				if (cnt == 1) {
					pos.push_back(PII(i, j));
				}
				else if (cnt == 2) {
					pos.push_back(PII(i, j));
				}
				else if (cnt == 3) {
					// nashi
				}
				else {
					// nasi
				}
			}
		}
	}
	SORT(pos);
	PII s, t;
	s = pos.back(), t = pos.front();
	cout << s.first << " " << s.second << " " << t.first << " " << t.second << endl;;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve();

	return 0;
}
