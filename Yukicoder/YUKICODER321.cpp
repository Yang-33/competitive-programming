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

/* -----  2018/10/02  Problem: yukicoder 321  / Link: http://yukicoder.me/problems/no/321  ----- */
/* ------問題------

「良い子のところにサンタが来るのではない，サンタが来たところの子が良い子なのだ」
因果が逆転した街ユキシティであなたは (P,Q) -サンタと呼ばれていて，街の中心に君臨している唯一のサンタである．

ユキシティは(X,Y)平面で表され，あなたは原点(0,0)に居ます．
街の子供たちはユキシティの格子点（X,Yが共に整数の座標）上に住んでいます．
クリスマスにプレゼントを配るのがあなたの仕事ではありますが，その移動手段は特殊なトナカイに引かれたそりであり，機動性は申し分ないが移動できる方向に制限があります．
(P,Q)-サンタの名の由来の通り，現在地点(x,y)に対して1回の移動で(x±P,y±Q) 及び(x±Q,y±P) に移動することが出来ます．

例えば，(P,Q)=(1,2)の場合，現在地点をsとすると，tに移動が可能です．
.t.t.
t...t
..s..
t...t
.t.t.

あなたは非常に責任感が強いサンタであり，また機動力は高く何回でも移動できるので，訪れることが可能な子供には必ずプレゼントを配ります。
N人の街の子供たちについてそれぞれの座標(Xi,Yi)が与えられるので，街に住む良い子の数を求めてください．

-----問題ここまで----- */
/* -----解説等-----

何もわからないがどうせO(1)なので実験をする。
実験によってgcdごとに幅のあるマスのみに到達可能であることがわかる。
また、gcdを撮ったP,Qに対して和は奇数と偶数のどちらかだが、偶数の時市松模様、
奇数の時全部になる。
00のときだけ場合分けをすれば解けた。

解説はちゃんと書かれていてビックリした。

----解説ここまで---- */

LL ans = 0LL;

void solve() {
	int H, W; H = W = 100;
	cout << "what is vec(P,Q)?" << endl;
	int P, Q; cin >> P >> Q;
	VVI m(2*H, VI(2*W, 0));

	m[H][W] = 2;
	queue<PII>q;
	q.push(PII(H, W));
	while (!q.empty()) {
		PII a = q.front(); q.pop();
		for (int i = -1; i < 2; i += 2) {
			for (int j = -1; j < 2; j += 2) {
				int ny = a.first + P * i;
				int nx = a.second + Q * j;
#define IN(x,y,z) (x<=y&&y<z)
				if (IN(0, ny, 2 * H) && IN(0, nx, 2 * W) && !m[ny][nx]) {
					m[ny][nx] = 1;
					q.push(PII(ny, nx));
				}
			}
		}
		for (int i = -1; i < 2; i += 2) {
			for (int j = -1; j < 2; j += 2) {
				int ny = a.first + Q * i;
				int nx = a.second + P * j;
				if (IN(0, ny, 2 * H) && IN(0, nx, 2 * W) && !m[ny][nx]) {
					m[ny][nx] = 1;
					q.push(PII(ny, nx));
				}
			}
		}
	}
	FOR(i, -20, 21) {
		FOR(j, -20, 21) {
			cout << m[i+H][j+W] << " ";
		}cout << endl;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//solve(); return 0;
	LL P, Q; cin >> P >> Q;
	LL G = __gcd(P, Q);
	if (G) {
		P = P / G;
		Q = Q / G;
	}
	LL N; cin >> N;

	FOR(i, 0, N) {
		LL x, y; cin >> x >> y;
		if (P == 0 && P == Q) {
			if (x == 0 && x == y)ans++;
		}
		else {
			if (x%G == 0 && y%G == 0) {
				x /= G, y /= G;
				if (P & 1 && Q & 1) {
					if ((x + y) % 2 == 0) {
						ans++;
					}
				}
				else {
					ans++;
				}
			}
		}

	}
	
	
	cout << ans << "\n";

	return 0;
}
