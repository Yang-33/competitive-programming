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

/* -----  2018/06/24  Problem: AOJ 1253 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1253  ----- */
/* ------問題------

27個のサイコロを設置する。ただし接するサイコロの面の和は7,正面と上部の値が指定されているものがある。
置き方は何通りか。

-----問題ここまで----- */
/* -----解説等-----

条件指定から、全部出せる。

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
vector<Dice>dices;
int tops[3][3], fronts[3][3];
vector<int> ans;
Dice putdice[3][3][3];
void dfs(int state) {
	if (state == 27) {
		int ret = 0;
		FOR(i, 0, 3) {// 右の右をとる va[2]
			FOR(j, 0, 3) {
				ret += putdice[i][2][j].s[2];
			}
		}

		ans.push_back(ret);
	}
	else {
		int X = (state / 3) % 3;
		int Y = state % 3;
		int Z = state / 9;
		FOR(i, 0, 24) { // put dices to putdice
						// ダメなもの top .front がちゃう
			if (Z == 0 && tops[X][Y] && tops[X][Y] != dices[i].top())continue;
			if (X == 2 && fronts[Z][Y] && fronts[Z][Y] != dices[i].s[1])continue;
			// ダメなもの 7じゃない
			if (X&& putdice[X - 1][Y][Z].s[4] + dices[i].s[1] != 7)continue; // 奥
			if (Y&& putdice[X][Y - 1][Z].s[2] + dices[i].s[3] != 7)continue; // 左
			if (Z&& putdice[X][Y][Z - 1].s[5] + dices[i].s[0] != 7)continue; // 上

			putdice[X][Y][Z] = dices[i];
			dfs(state + 1);
		}


	}

}


// 24^27なきもちになるけど前処理すればだいたい決まるので解析しなくても投げる気持ちが固まる
// パラメータの管理壊れる
void solve_AOJ_1253() {
	// 条件を見たすように配置したときの右面の種類
	Dice Base;
	FOR(i, 0, 6)Base.s[i] = i + 1;
	dices = makeDices(Base);

	int Case; cin >> Case;
	FOR(kyo, 0, Case) {
		FOR(i, 0, 3)FOR(j, 0, 3)cin >> tops[i][j];
		FOR(i, 0, 3)FOR(j, 0, 3)cin >> fronts[i][j];
		dfs(0);
		SORT(ans); UNIQ(ans);
		FOR(i, 0, SZ(ans)) {
			cout << ans[i] << " \n"[i == SZ(ans) - 1];
		}
		if (SZ(ans) == 0)cout << 0 << endl;
		ans.clear();
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve_AOJ_1253();

	return 0;
}
