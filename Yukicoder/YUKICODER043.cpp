#include <bits/stdc++.h>
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

/* -----  2018/04/11  Problem: yukicoder 043  / Link: http://yukicoder.me/problems/no/043  ----- */
/* ------問題------

N個の野球チームがある。
K君はその０番目のチームに所属している。
すべてのチームが総当たりで試合をすることになった。
総当たりではすべてのチームがそれぞれ１試合ずつ試合を行う。
試合は勝ち負けが確定し引き分けは無いものとする。
順位は勝ち数が多い順で１位から決定していく。
勝ち数が同じであれば同じ順位のチームが複数のこともある。
また、順位は１位から決定し数字が抜けることは無い。
例えば１位が２チームでも次の順位は２位になる。
１位が２チームであるから次の順位が３位になるということは無い。
現在の勝ち負けの勝敗表が渡される。
もし残りの試合があれば残りの試合について試合の勝ち負けのパターンを考慮する。
K君の０番目のチームが最高で何位になりえるかを答えよ。


-----問題ここまで----- */
/* -----解説等-----

空いている場所が最大15個なので、これは全探索できる。

----解説ここまで---- */

int check(VS &t) {
	int N = SZ(t);
	vector<PII>rank(N, PII(0, 0));
	FOR(j, 0, N) {
		rank[j].second = j;
	}
	FOR(j, 0, N) {
		FOR(k, 0, N) {
			if (t[j][k] == 'o')rank[j].first++;
		}
	}
	RSORT(rank);
	int R = 1;
	int point=-1;
	FOR(j, 0, N) {
		if (point == -1) {
			point = rank[j].first;
		}
		else if (point == rank[j].first) {

		}
		else {
			R++;
			point = rank[j].first;
		}
		if (rank[j].second == 0)return R;

	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VS s(N);
	FOR(i, 0, N) {
		cin >> s[i];
	}
	vector<PII> pos;
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			if (s[i][j] == '-') {
				pos.push_back(PII(i, j));
			}
		}
	}
	int ans = (SZ(pos)?N:check(s));

	FOR(i, 0, 1 << SZ(pos)) {
		VS t = s;
		FOR(j, 0, SZ(pos)) {
			if (i&(1 << j)) {
				t[pos[j].first][pos[j].second] = 'o';
				t[pos[j].second][pos[j].first] = 'x';
			}
			else {
				t[pos[j].first][pos[j].second] = 'x';
				t[pos[j].second][pos[j].first] = 'o';
			}
		}
		ans = min(ans, check(t));
	}
	cout << ans << "\n";

	return 0;
}
