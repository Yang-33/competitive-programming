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

/* -----  2018/06/24  Problem: AOJ 1259 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1259  ----- */
/* ------問題------

サイコロがNこある。(N<=4)
適当な面を存在する面の値に書き換えることでサイコロを一致させたい。
最小何面で達成できるか。

-----問題ここまで----- */
/* -----解説等-----

回転の性質から、N-1こ見れば良い。
また、24*24*24を探索して、各面の一致の最小を見れば簡単。

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


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve_AOJ_1259();

	return 0;
}




