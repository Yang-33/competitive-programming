#include <bits/stdc++.h>
#include <unordered_map>
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
#define FOR(i, va, e) for (int(i) = (va); (i) < (e); (i)++)
#define FORR(i, va, e) for (int(i) = (va); (i) > (e); (i)--)
#define debug(nx) cerr << #nx << ": " << nx << endl
const int INF = 1e9;                          const LL LINF = 1e16;
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/20  Problem: AOJ 2703 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2703  ----- */
/* ------問題------

あなたは地元の縁日で，今までに見たことがないゲームの出店を発見した． N 個の6面サイコロを，ボード上に落として転がすゲームだ． より正確には， N 個のボタンが N 個のサイコロに1対1に紐付いており，ボタンを押すことで対応したサイコロがボードに落ちる． ボタンを好きなように N 回押し，サイコロを N 回落として転がすことで得点を得るゲームである．
ゲームのより詳細なルールを説明しよう． ゲームで使用する N 個のサイコロはすべて各辺の長さが1の立方体であり，ボードは長さが1の正方形のマスに区切られた十分に広い平面である． ゲーム開始前，ボードの各マスにはすべて0が書かれている． 各サイコロの各面には整数が書かれている．これは1から6までとは限らないし，サイコロごとに違う数が書かれていることもある．
ゲームで用いる筐体には N 個のボタンが付いており， N 個のサイコロと1対1に紐付いている． いずれかのボタンを押すと，対応したサイコロが機械から排出されてボードに落ち，何度か回転する． 回転の途中，サイコロの下面は必ずボードのいずれかのマスにぴったりと重なる． 下面がマスに触れる度，そのマスに書かれていた数が，サイコロの下面に書かれた数で上書きされる． これは落下により初めてボードに触れたときも含む． 回転が止まった後，サイコロはボードから取り除かれ，元の排出装置へと戻される． ボタンを N 回押した後，ボードに書かれた数の和が最終得点となる． 同じボタンを複数回押すことはできるが，1つ前に排出したサイコロの回転が終わり，排出装置に戻るまで次のボタンを押すことはできない．
さて，出店のおっちゃんはサイコロの排出の仕方はランダムだと主張しているが，注意深いあなたは，他の客が遊ぶ様子を観察することで，同じボタンを押した時の挙動がそれまでのボタンの押し方に依らず完全に同一であることに気付いた． より具体的には， i 番目のボタンを押したときの挙動は以下のように決定的である．
i 番目のサイコロが排出される．
このサイコロは内部で決められたマスに決められた向きで落下する．この向きは必ず，マスの正方形と下面の正方形とがぴったりと重なる向きである．
サイコロは前後左右4方向いずれかに回転することを繰り返す．回転回数やそれぞれの回転の方向も，内部で決められている．
決められた回転が終了すると，サイコロはボードから取り除かれ，排出装置に戻される．
ここで，便宜上3次元空間を考え，マスの辺に平行な向きにそれぞれ x 軸と y 軸をとり，サイコロ上面が向く方向を z 軸正方向とする. この時，サイコロの回転は x, y 軸の正，負方向の4通りであり，それぞれ下図のようになる．ただし，図中の記号は後述の入力形式に対応している．
決定的に動くとはなんて詐欺だ，と憤りを感じたものの，あなたは N 回のボタンの押し方によって最終得点を変えられることに気が付いた．
あなたは入念な観察により各サイコロの各面に書かれた数や落とされる初期位置・向き・その後の回転の仕方に至るまで完全な情報を揃えた． 集めた情報に基づいて，最善のボタンの押し方で得られるこのゲームの最高得点を求めよ．

-----問題ここまで----- */
/* -----解説等-----

非可換埋め立てなので最適値のみ保存すれば良い。
したがってbitDPでおわる。

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

void solve_AOJ_ITP1_11_A() {
	int N = 6;
	Dice D;
	FOR(i, 0, N) {
		int val; cin >> val;
		D.s[i] = val;
	}
	string s; cin >> s;
	FOR(i, 0, SZ(s)) {
		D.roll(s[i]);
	}
	cout << D.top() << endl;
}

void solve_AOJ_ITP1_11_B() {
	Dice D;
	int N = 6;
	FOR(i, 0, N) {
		int val; cin >> val;
		D.s[i] = val;
	}
	vector<Dice> dices = makeDices(D);
	int Q; cin >> Q;
	FOR(i, 0, Q) {
		int TOP, FRONT;
		cin >> TOP >> FRONT;
		FOR(i, 0, SZ(dices)) { //24個
			if (dices[i].top() == TOP && dices[i].s[1] == FRONT) {
				cout << dices[i].s[2] << endl;
				break;
			}
		}
	}
}

void solve_AOJ_ITP1_11_C() {
	Dice d[2];
	FOR(k, 0, 2) {
		FOR(i, 0, 6) {
			int val; cin >> val;
			d[k].s[i] = val;
		}
	}
	uLL hashval = d[0].hash();
	vector<Dice>dices = makeDices(d[1]);
	FOR(i, 0, SZ(dices)) {
		if (hashval == dices[i].hash()) {
			cout << "Yes" << endl;
			return;
		}
	}
	cout << "No" << endl;
}
void solve_AOJ_ITP1_11_D() {
	int N; cin >> N;
	vector<Dice>d(N);
	FOR(k, 0, N) {
		FOR(i, 0, 6) {
			int val; cin >> val;
			d[k].s[i] = val;
		}
	}
	set<uLL>Se;
	Se.insert(d[0].hash());
	FOR(i, 1, N) {
		vector<Dice>dices = makeDices(d[i]);
		int flag = 0;
		FOR(j, 0, SZ(dices)) {
			flag |= (Se.count(dices[j].hash()));
		}
		if (flag) {
			cout << "No" << endl;
			return;
		}
		Se.insert(dices[i].hash());

	}
	cout << "Yes" << endl;
}

void solve_AOJ_0502() {
	int Q;
	while (cin >> Q, Q) {
		Dice d; FOR(i, 0, 6)d.s[i] = i + 1;
		int ans = 1;
		FOR(kim, 0, Q) {
			string s; cin >> s;
			d.roll(s[0]);
			ans += d.top();
		}
		cout << ans << endl;
	}


}

using PII = pair<int, int>;
map<char, char>changeC;
inline  int  mhash(const PII &a) {
	return (a.first + 1200) * 2400 + a.second + 1200;
}
void solve_AOJ_2703() { // えーサイコロ関係なくないですか？ないですね
	const string ORIG = "EWNS";
	const string TO = "RLBF";
	FOR(i, 0, 4) {
		changeC[TO[i]] = ORIG[i];
	}
	int N;
	while (cin >> N, N) {
		vector<map<PII, int>>Map(N);
		int x, y;
		Dice dice;
		FOR(i, 0, N) {
			cin >> x >> y;
			cin >> dice.s[3] >> dice.s[2] >> dice.s[1] >> dice.s[4] >> dice.s[5] >> dice.s[0];
			string s; cin >> s;
			Map[i][PII(y, x)] = dice.bottom();
			FOR(j, 0, SZ(s)) {
				dice.roll(changeC[s[j]]);
				// R,L,B,F
				if (s[j] == 'R')x++;
				if (s[j] == 'L')x--;
				if (s[j] == 'B')y++;
				if (s[j] == 'F')y--;
				// ny nx の移動
				Map[i][PII(y, x)] = dice.bottom();
			}
		}

		vector<int>bitdp(1 << N, 0);
		FOR(state, 0, 1 << N) {
			unordered_map<int, bool>used; // orderedだと結構遅かった
			FOR(i, 0, N) {
				if (state & 1 << i) {
					for (auto it : Map[i]) {
						used[mhash(it.first)] = 1;
					}
				}
			}
			// 記録した
			FOR(i, 0, N) {
				if (state & 1 << i)continue;
				int addv = 0;

				for (auto it : Map[i]) {
					if (!used.count(mhash(it.first))) {
						addv += it.second;
					}
				}
				bitdp[state | (1 << i)] = max(bitdp[state | (1 << i)], bitdp[state] + addv);
			}
		}
		cout << bitdp[(1 << N) - 1] << endl;

	}
}

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
Dice resDice[4];
vector<Dice>diceState[4];

void Dfs(int state, const int N, int& ans) {
	if (N == state) {
		int res = 0;
		// あるおきかたについて
		// 一緒になるように最小の塗り分けをする

		FOR(i, 0, 6) { //ある面について
			map<int, int>cnt;
			FOR(k, 0, N) {
				cnt[resDice[k].s[i]]++;
			}
			int mx = 0;
			for (auto it : cnt) {
				mx = max(mx, it.second); // 重複maxが保存すべきもの
			}
			res += N - mx;
		}
		ans = min(ans, res);
		return;
	}
	FOR(i, 0, 24) {
		resDice[state] = diceState[state][i];
		Dfs(state + 1, N, ans);
	}
}

void solve_AOJ_1259() {
	// N diff checkする 全探索 同じにするための塗り替えを最小にする
	int N;
	while (cin >> N, N) {
		if (N == 1) {
			string s; FOR(i, 0, 6)cin >> s;

			cout << 0 << endl;
		}
		else {

			vector<Dice>baseDice(N);
			FOR(i, 0, 4)diceState[i].clear();
			map<string, int>sHash;
			int hp = 1;
			FOR(i, 0, N) {
				FOR(j, 0, 6) {
					string s;  cin >> s;
					if (sHash.find(s) == sHash.end())sHash[s] = hp++;
					baseDice[i].s[j] = sHash[s];
				}
			}
			// 値をいれたので24^(N-1)全部つくる
			FOR(i, 0, N) {
				diceState[i] = makeDices(baseDice[i]);
			}
			int ans = INF;
			resDice[0] = baseDice[0];
			Dfs(1, N, ans);
			cout << ans << endl;
		}
	}


}

char dice[8][5][5];
int i, j, res, f[3];
int input()
{
	for (i = 1; i <= 6; i++)
		for (j = 2; j >= 0; j--)
		{
			scanf("%s", dice[i][j]);
			if (i == 1 && j == 2 && dice[i][j][0] == '#') return 0;
		}
	return 1;
}
void f1(int a, int b, int m)
{
	for (f[m] = i = 0; i < 3; i++) if (dice[a][b][i] == '*') f[m] = 1;
}
void f3(int a, int b, int m)
{
	for (f[m] = i = 0; i < 3; i++) if (dice[a][i][b] == '*') f[m] = 1;
}
void C(int x)
{
	if (f[1] && f[2]) res = min(res, x);
}

// さいころ関係ねえ…
// ゆるさん
void solve_AOJ_2245() {
	while (input())
	{
		res = 9;

		f1(1, 0, 1), f1(3, 0, 2), C(0);
		f1(1, 2, 1), f1(3, 2, 2), C(2);
		f3(1, 0, 1), f3(3, 2, 2), C(1);
		f3(1, 2, 1), f3(3, 0, 2), C(1);

		f1(2, 0, 1), f1(4, 0, 2), C(3);
		f1(2, 2, 1), f1(4, 2, 2), C(3);
		f3(2, 0, 1), f3(4, 2, 2), C(2);
		f3(2, 2, 1), f3(4, 0, 2), C(2);

		f1(5, 0, 1), f1(6, 2, 2), C(1);
		f1(5, 2, 1), f1(6, 0, 2), C(1);
		f3(5, 0, 1);
		for (f[2] = i = 0; i < 3; i++) if (dice[6][2 - i][0] == '*') f[2] = 1;
		C(2);
		f3(5, 2, 1);
		for (f[2] = i = 0; i < 3; i++) if (dice[6][2 - i][2] == '*') f[2] = 1;
		C(2);

		printf("%d\n", res);
	}


}

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

// えー最強の呪文と一緒なんだけど虚無度が高すぎる
void solve_AOJ_2451() {

	class Data
	{
	public:
		int y, x;
		Dice d;
		Data(int y0, int x0, const Dice& d0) {
			y = y0;
			x = x0;
			d = d0;
		}
		int toInt() const {
			return ((y * 14 + x) * 6 + d.s[0]) * 6 + d.s[1];
		}
		bool operator<(const Data& d) const {
			return toInt() < d.toInt();
		}
	};

	int dy[] = { 0, 1, 0, -1 };
	int dx[] = { 1, 0, -1, 0 };
	int H, W;
	cin >> H >> W;

	VS va(H + 2, string(W + 2, '.'));
	FOR(i, 1, H + 1) {
		FOR(j, 1, W + 1) {
			cin >> va[i][j];
		}
	}
	H += 2;
	W += 2;

	VS name(6);
	FOR(i, 0, 6) {
		cin >> name[i];
	}

	int sy, sx, gy, gx;
	cin >> sy >> sx >> gy >> gx;

	Dice Base;
	int setting[] = { 0,3,4,2,1,5 };
	FOR(i, 0, 6) {
		Base.s[i] = setting[i];
	}
	vector<bool> check(14 * 14 * 6 * 6, false);
	queue<Data> q;
	auto dices = makeDices(Base);
	FOR(i, 0, 24) {
		Data d(gy, gx, dices[i]);
		check[d.toInt()] = true;
		q.push(d);
	}


	vector<vector<Data> > edges(14 * 14 * 6 * 6);
	while (!q.empty()) {
		Data d0 = q.front();
		q.pop();
		int y0 = d0.y;
		int x0 = d0.x;
		Dice dice0 = d0.d;
		FOR(i, 0, 4) {
			int ny = y0 + dy[i];
			int nx = x0 + dx[i];
			if (va[ny][nx] != '+') {
				if (i == 0 && va[ny][nx] != '-' && va[ny][nx] != '<')
					continue;
				if (i == 1 && va[ny][nx] != '|' && va[ny][nx] != '^')
					continue;
				if (i == 2 && va[ny][nx] != '-' && va[ny][nx] != '>')
					continue;
				if (i == 3 && va[ny][nx] != '|' && va[ny][nx] != 'v')
					continue;
			}
			const string strF = "ESWN";
			Dice dice = dice0;
			dice.roll(strF[i]);
			Data d(ny, nx, dice);

			edges[d.toInt()].push_back(d0);
			if (!check[d.toInt()]) {
				check[d.toInt()] = true;
				q.push(d);
			}
		}
	}

	Data d(sy, sx, Base);
	if (edges[d.toInt()].size() == 0) {
		cout << "no" << endl;
		return;
	}

	set<pair<Data, int> > Se;
	Se.insert(make_pair(d, 0));

	string ret;
	FOR(kyomu, 0, 5000) {
		char c = 'a';
		for (const auto &it : Se) {
			Data d = it.first;
			int i = d.d.top();
			int j = it.second;
			c = min(c, name[i][j]);
		}

		ret += string(1, c);

		set<pair<Data, int> > NextSet;
		for (const auto &it : Se) {
			Data d = it.first;
			int i = d.d.top();
			int j = it.second;
			if (c == name[i][j]) {
				if (j == name[i].size() - 1) {
					if (d.y == gy && d.x == gx) {
						cout << ret << endl;
						return;
					}
					FOR(k, 0, SZ(edges[d.toInt()])) {
						Data d2 = edges[d.toInt()][k];
						NextSet.insert(make_pair(d2, 0));
					}
				}
				else {
					NextSet.insert(make_pair(d, j + 1));
				}
			}
		}

		Se.swap(NextSet);
	}

	cout << "infinite" << endl;

}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//solve_AOJ_ITP1_11_A();
	//solve_AOJ_ITP1_11_B();
	//solve_AOJ_ITP1_11_C();
	//solve_AOJ_ITP1_11_D();
	//solve_AOJ_0502();

	//solve_AOJ_1181();
	solve_AOJ_2703();
	//solve_AOJ_1253();
	//solve_AOJ_1259();
	//solve_AOJ_2245();
	//solve_AOJ_1290();
	//solve_AOJ_2451();

	return 0;
}
