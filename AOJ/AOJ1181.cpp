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

/* -----  2018/06/24  Problem: AOJ 1181 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1181  ----- */
/* ------問題------

確率的アルゴリズムの大家であるランダム教授は現在，偏りのあるサイコロの実験を行っている．実験というのは，平面の上方の決まった位置から次々にサイコロを落とすものである．サイコロは平面またはすでにそこにあるサイコロの上に回転せずに落ち，さらに転がり落ちることもある．結果としては，積み上がった山の状態，具体的には上から見たときにどの目がいくつ見えるかを記録する．すべてのサイコロは同じ大きさで，数の振り方はすべて図C-1のようになっている．
ここで用いるサイコロは非常に特殊な性質を持っている．
(1)通常のサイコロは4方向に転がることができるが，ここで用いるサイコロは4，5，6の面の方向にしか転がらない（1，2，3の面の方向には転がれない）．図C-2に示す状況では，ここで用いるサイコロ(our die)は2方向にしか転がらない．
(2)サイコロが転がるのは，転がった後に落ちる時のみである．この様子を図C-3に示す．転がりうる方向が複数ある場合は，最も大きな目の面の方向に転がる．
(3)転がる場合には，図C-4の[B]，[C]のように，ちょうど90度回転した後，まっすぐ下に落ち，平面か他のサイコロの上に着地する．
(4)サイコロは一度転がり落ちた後も，(1)～(3)の規則に従い繰り返し転がり落ちる．

たとえば，同じ向き(上面が6，前面が4)で4つのサイコロを落下させた場合，図C-4のように山ができる．
山が完成したら，1から6までの面が上からいくつ見えるかを数えて記録する．たとえば図C-5の左の場合は記録は「0 2 1 0 0 0」となり，右の場合は「0 1 1 0 0 1」となる．

-----問題ここまで----- */
/* -----解説等-----

広い場所に設置するとして、これをシュミレーションすればよい。
昔は厳しいと思ってたけど簡単だった。

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

void solve_AOJ_1181() {
	int N;
	Dice BaseDi;
	FOR(i, 0, 6)BaseDi.s[i] = i + 1;
	vector<Dice>dices = makeDices(BaseDi);
	while (cin >> N, N) {
		VVI masu(210, VI(210, 0));
		vector<VVI>valset(210, VVI(210, VI()));
		FOR(okaduki, 0, N) {
			int tp, fr; cin >> tp >> fr;
			int X = 100, Y = 100;
			Dice d;
			FOR(i, 0, SZ(dices)) {
				if (dices[i].top() == tp&&dices[i].s[1] == fr) {
					d = dices[i];
					break;
				}
			}
			while (1) {
				masu[Y][X]++;
				// 落ちる方向を決める
				// 大きな方に転がり落ちる
				int dy[] = { -1, 1, 0, 0, -1, };
				int dx[] = { -1, 0, 1, -1, 0, };
				int dir = -1;
				FOR(num, 4, 6 + 1) {
					if (d.top() != num && d.bottom() != num) { //面があれ
						FOR(i, 1, 4 + 1) {
							if (d.s[i] == num) {
								if (masu[Y][X] > masu[Y + dy[i]][X + dx[i]] + 1) {
									dir = i;
								}
							}
						}
					}
				}
				if (dir == -1) {
					valset[Y][X].push_back(d.top());
					break;
				}
				masu[Y][X]--;
				string TO = "$SEWN";
				Y += dy[dir]; X += dx[dir];
				d.roll(TO[dir]);
			}
		}
		VI a(7, 0);
		FOR(i, 0, 210) {
			FOR(j, 0, 210) {
				if (!SZ(valset[i][j]))continue;
				int val = valset[i][j].back();
				a[val]++;
			}
		}
		FOR(i, 1, 6 + 1) {
			cout << a[i] << " \n"[i == 6];
		}

	}

}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	solve_AOJ_1181();

	return 0;
}
