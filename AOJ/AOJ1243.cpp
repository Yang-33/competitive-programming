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
int DX[9] = { 0, 0, 1, -1, 1, 1, -1, -1,0 };    int DY[9] = { 1, -1, 0, 0, 1, -1, 1, -1 ,0 };

/* -----  2018/05/11  Problem: AOJ 1243 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1243  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

がんばる以外はなく、頑張る

----解説ここまで---- */

int dx[] = { 0,1,0,-1,0,2,0,-2,0 };
int dy[] = { 1,0,-1,0,2,0,-2,0,0 };
int f(vector<PII>& in) {
	int a = 0;
	for (int i = 5; i >= 0; i--) {
		a *= 9;
		a += in[i].first * 3 + in[i].second;
	}
	return a;
}
vector<PII> F(int a) {
	vector<PII> out;
	FOR(i, 0, 6) {
		int b = a % 9;
		out.push_back(PII(b / 3, b % 3));
		a /= 9;
	}
	return out;
}
VI dp;
int main() {
	int n;
	while (cin >> n, n) {
		VVI in(n, VI(16));
		FOR(i, 0, n)FOR(j, 0, 16)cin >> in[i][j];
		int N = 531441;
		dp = VI(N);
		vector<PII> qwr(6, PII(1, 1));
		dp[f(qwr)] = 1;
		FOR(i, 0, n) {
			VI ndp(N);
			FOR(j, 0, N)if (dp[j])FOR(k, 0, 9) {
				if (i == 0 && k != 8)continue;
				vector<PII> state = F(j);
				PII now = state[5];
				now.first += dx[k];
				now.second += dy[k];
				if (now.first < 0 || now.first >= 3 || now.second < 0 || now.second >= 3)continue;
				state.push_back(now);

				bool h = true;
				if (in[i][now.first * 4 + now.second])continue;
				if (in[i][now.first * 4 + now.second + 1])continue;
				if (in[i][now.first * 4 + now.second + 4])continue;
				if (in[i][now.first * 4 + now.second + 5])continue;
				FOR(l, 0, 16) {
					bool H = false;
					FOR(x, 0, 7) {
						if (state[x].first * 4 + state[x].second == l)H = true;
						if (state[x].first * 4 + state[x].second + 1 == l)H = true;
						if (state[x].first * 4 + state[x].second + 4 == l)H = true;
						if (state[x].first * 4 + state[x].second + 5 == l)H = true;
					}
					if (!H)h = false;
				}
				state.erase(state.begin());
				if (i < 6 || h)ndp[f(state)] = true;
			}
			dp = ndp;
		}
		bool h = false;
		FOR(i, 0, N)if (dp[i])h = true;
		cout << h << endl;
	}
}