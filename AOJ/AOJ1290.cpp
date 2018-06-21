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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/24  Problem: AOJ 1290 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1290  ----- */
/* ------問題------

指定された順番でさいころの目を巡回した際の、最短路値

-----問題ここまで----- */
/* -----解説等-----

区別すればいいのは着いたサイコロの数、今の目の状態(24)

----解説ここまで---- */


using uLL = unsigned long long;

const uLL MOD = 1e9;
//BEGIN CUT HERE
struct Dice {
	int s[6];
	void roll(char c) {
		//the view from above
		// N
		//W E
		// S
		//va[0]:top
		//va[1]:south
		//va[2]:east
		//va[3]:west
		//va[4]:north
		//va[5]:bottom
		int b;
		if (c == 'E') {
			b = s[0];
			s[0] = s[3];
			s[3] = s[5];
			s[5] = s[2];
			s[2] = b;
		}
		if (c == 'W') {
			b = s[0];
			s[0] = s[2];
			s[2] = s[5];
			s[5] = s[3];
			s[3] = b;
		}
		if (c == 'N') {
			b = s[0];
			s[0] = s[1];
			s[1] = s[5];
			s[5] = s[4];
			s[4] = b;
		}
		if (c == 'S') {
			b = s[0];
			s[0] = s[4];
			s[4] = s[5];
			s[5] = s[1];
			s[1] = b;
		}

		// migi neji 
		if (c == 'R') {
			b = s[1];
			s[1] = s[2];
			s[2] = s[4];
			s[4] = s[3];
			s[3] = b;
		}

		if (c == 'L') {
			b = s[1];
			s[1] = s[3];
			s[3] = s[4];
			s[4] = s[2];
			s[2] = b;
		}

	}
	int top() {
		return s[0];
	}
	int bottom() {
		return s[5];
	}
	uLL hash() {
		uLL res = 1;
		for (int i = 0; i < 6; i++) res = res * (MOD)+s[i];
		return res;
	}
	void print() {
		cout << "Dice num: ";
		FOR(i, 0, 6) {
			cout << s[i] << " ";
		}
		cout << "Hash: " << this->hash() << endl;
		cout << endl;
	}
	bool operator < (const Dice &x)const {
		FOR(i, 0, 6)if (x.s[i] < s[i])return true;
		return false;
	}

};
vector<Dice> makeDices(Dice d) {
	vector<Dice> res;
	for (int i = 0; i < 6; i++) {
		Dice t(d);
		if (i == 1) t.roll('N');
		if (i == 2) t.roll('S');
		if (i == 3) t.roll('S'), t.roll('S');
		if (i == 4) t.roll('L');
		if (i == 5) t.roll('R');
		for (int k = 0; k < 4; k++) {
			res.push_back(t);
			t.roll('E');
		}
	}
	return res;
}
//END CUT HERE


// V
// さいころの目と盤面があるのでこれをたどりきる最短のもの
// state[ny][nx][7][24]:=minっぽくやればよい

// いやbottomにしてくれ

int d[33][33][7][24];
void solve_AOJ_1290() {
	int W, H;

	string ini = "rmbygc";
	Dice Based;
	FOR(i, 0, 6)Based.s[i] = ini[i];
	vector<Dice>dices = makeDices(Based);
	map<uLL, int>HashMap;
	FOR(i, 0, 24)HashMap[dices[i].hash()] = i;

	using tp = tuple<int, int, int, Dice>;

	while (cin >> W >> H, W) {
		VS vs(H);
		queue<tp>q;
		fill(***d, ***d + 33 * 33 * 7 * 24, -1);

		FOR(i, 0, H) {
			cin >> vs[i];
			FOR(j, 0, W) {
				if (vs[i][j] == '#') {
					vs[i][j] = 'w';
					d[i][j][0][0] = 0;
					q.push(tp(i, j, 0, Based));
				}
			}
		}
		string target; cin >> target; // この順

		const string F = "SNEW";
		int ans = -1;
		while (!q.empty()) {
			int y, x, cnt; Dice D;
			tie(y, x, cnt, D) = q.front(); q.pop();
			if (cnt == 6) {
				ans = d[y][x][cnt][HashMap[D.hash()]];
				break;
			}
			FOR(i, 0, 4) {
				int ny = y + DY[i], nx = x + DX[i];
				if (0 <= ny&&ny < H && 0 <= nx&&nx < W) {
					if (vs[ny][nx] == 'k')continue;
					Dice NxtD = D;
					NxtD.roll(F[i]);
					if (vs[ny][nx] == target[cnt] && NxtD.top() == target[cnt]) {
						if (d[ny][nx][cnt + 1][HashMap[NxtD.hash()]] == -1) {
							d[ny][nx][cnt + 1][HashMap[NxtD.hash()]] = d[y][x][cnt][HashMap[D.hash()]] + 1;
							q.push(tp(ny, nx, cnt + 1, NxtD));
						}
					}
					else {
						if (vs[ny][nx] != 'w')continue;
						if (d[ny][nx][cnt][HashMap[NxtD.hash()]] == -1) {
							d[ny][nx][cnt][HashMap[NxtD.hash()]] = d[y][x][cnt][HashMap[D.hash()]] + 1;
							q.push(tp(ny, nx, cnt, NxtD));
						}
					}
				}
			}
		}
		if (ans == -1) {
			cout << "unreachable" << endl;
		}
		else {
			cout << ans << endl;
		}
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve_AOJ_1290();

	return 0;
}
