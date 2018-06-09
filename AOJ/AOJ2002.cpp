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

/* -----  2018/06/10  Problem: AOJ 2002 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2002  ----- */
/* ------問題------

これは 20XX 年の話である．再生発電網による安定したエネルギー供給，および液化合成燃料の発明によって航空旅客数は鰻登りに増加した．しかし，航空機によるテロリズムの脅威は依然として存在するため，高速でかつ高い信頼性をもつ自動手荷物検査システムの重要性が高まっている．検査官が全部の荷物を調べることは実際問題として困難であることから，自動検査において疑わしいと判断された手荷物だけを検査官で改めて調べるという仕組みを整えたいわけである．

航空機業界からの要請を受け，国際客室保護会社（International Cabin Protection Company）では，新たな自動検査システムを開発するため，最近の旅客の手荷物について調査した．調査の結果，最近の旅客の手荷物には次のような傾向があることが判明した．

手荷物は 1 辺だけが短い直方体のような形状をしている．
一般の乗客が手荷物に詰めて航空機に持ち込む品物としてはノートパソコン，音楽プレイヤー，携帯ゲーム機，トランプなどがあり，これらはいずれも長方形である．
個々の品物は，その長方形の辺が手荷物の辺と平行になるように詰めこまれる．
一方，テロリズムに用いられるような武器は，長方形とは非常に異なる形状をもつ．
上記の調査結果をふまえて，以下のような手荷物検査のためのモデルを考案した．それぞれの手荷物は X 線に対して透明である直方体の容器だとみなす．その中には X 線に対して不透明である複数の品物が入っている．ここで，直方体の 3 辺を x 軸，y 軸，z 軸とする座標系を考え，x 軸と平行な方向に X 線を照射して，y-z 平面に投影された画像を撮影する．撮影された画像は適当な大きさの格子に分割され，画像解析によって，それぞれの格子領域に映っている品物の材質が推定される．この会社には非常に高度の解析技術があり，材質の詳細な違いすらも解析することが可能であることから，品物の材質は互いに異なると考えることができる．なお，複数の品物が x 軸方向に関して重なっているときは，それぞれの格子領域について最も手前にある，すなわち x 座標が最小である品物の材質が得られる．また，2 つ以上の品物の x 座標が等しいことはないと仮定する．

あなたの仕事は，画像解析の結果が与えられたときに，長方形ではない（武器であるかもしれない）品物が入っていることが断言できるか，あるいはその手荷物には長方形の品物以外のものは入っていないと推測されるかを判定するプログラムを作成することである．

-----問題ここまで----- */
/* -----解説等-----

まず、ある文字について四隅を発見できたとする。(隅のmax/minをとればよい)
長方形の内部に.があったらダメ
次に、上に乗っかっている場合はダメ。
これはなんかめんどくさいので考える。(どう考えても僕が書くと実装がバグるため)
なんか循環してはダメであることがわかる。
これは閉路判定であるから手抜きをすればワーシャルフロイドでも解ける気持ちになれる。
あとは上にあれば辺をはれば良い。

----解説ここまで---- */

string solve(int H, int W, vector<string>& grid) {
	VI sy(300, 50);
	VI sx(300, 50);
	VI ey(300, 0);
	VI ex(300, 0);

	VVI g(26, VI(26, 1e9));
	FOR(i, 0, 26) {
		g[i][i] = 0;
	}

	FOR(i, 0, H) {
		FOR(j, 0, W) {
			char c = grid[i][j];
			sx[c] = min(sx[c], i);
			sy[c] = min(sy[c], j);
			ex[c] = max(ex[c], i);
			ey[c] = max(ey[c], j);
		}
	}

	for (char c = 'A'; c <= 'Z'; c++) {
		for (int x = sx[c]; x <= ex[c]; x++) {
			for (int y = sy[c]; y <= ey[c]; y++) {
				if (grid[x][y] == '.') {
					return "SUSPICIOUS";
				}
				else if (grid[x][y] != c) {
					g[c - 'A'][grid[x][y] - 'A'] = -1;
				}
			}
		}
	}

	//  負閉路があったらそれはダメそう
	FOR(k, 0, 26) {
		FOR(i, 0, 26) {
			FOR(j, 0, 26) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	FOR(i, 0, 26) {
		if (g[i][i] < 0) {
			return "SUSPICIOUS";
		}
	}
	return "SAFE";
}

int main() {
	int N, H, W;
	scanf("%d", &N);

	FOR(kim, 0, N) {
		scanf("%d %d", &H, &W);
		vector<string> vs(H);
		FOR(i, 0, H) {
			cin >> vs[i];
		}
		cout << solve(H, W, vs) << endl;
	}

	return 0;
}