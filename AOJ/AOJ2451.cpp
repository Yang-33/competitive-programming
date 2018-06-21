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

/* -----  2018/06/24  Problem: AOJ 2451 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2451  ----- */
/* ------問題------

辞書順最小の文字列でゴールできるか

-----問題ここまで----- */
/* -----解説等-----

実装は厳しいが最強の呪文と一緒なので頑張れば良い。(頑張れるとは言ってない)
一文字づつシュミレーションすると必ず辞書順最小になる。

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

	solve_AOJ_2451();

	return 0;
}
