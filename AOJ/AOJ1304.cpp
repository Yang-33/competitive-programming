#include "bits/stdc++.h"
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

/* -----  2017/11/22  Problem: AOJ 1304 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1304  ----- */
/* ------問題------

シュミレーション

-----問題ここまで----- */
/* -----解説等-----

めんどくさいけど、盤面をハッシュにしてやる

----解説ここまで---- */

LL N;
#define IN(x,y) (0<=x&&x<N&&0<=y&&y<N)
bool isinfe(int y, int x, string &s) {
	int virus = 0;
	FOR(k, 0, 8) {
		int ny = y + DY[k], nx = x + DX[k];
		if (!IN(nx, ny)) continue;
		if (s[ny*N + nx] == '#') virus++;
		else if (s[ny*N + nx] == '@') virus++;
	}
	if (s[y*N + x] == '.') return (virus == 3);
	else if (s[y*N + x] == '#') return (virus == 2 || virus == 3);
}

string change(string &s) {
	string t;
	FOR(k, 0, SZ(s)) {
		if (s[k] == '@') t += '@';
		else if (isinfe(k / N, k%N, s)) t += '#';
		else t += '.';
	}
	return t;
}

bool oshiri(string &s) {
	FOR(i, 0, SZ(s)) {
		if (s[i] == '#') return false;
	}
	return true;
}

int doko(string &s) {
	FOR(i, 0, SZ(s)) {
		if (s[i] == '@') return i;
	}
}

int bfs(string &s) {
	map<string, int>mp;
	queue<string> que;
	mp[s] = 0;
	que.push(s);
	while (!que.empty()) {
		string t = que.front(); que.pop();
		if (oshiri(t)) return mp[t];
		int idx = doko(t);
		int y = idx / N, x = idx%N;
		FOR(k, 0, 8) {
			string u = t;
			int ny = y + DY[k], nx = x + DX[k];
			int ni = nx + ny*N;
			if (!IN(nx, ny)) continue;
			if (u[ni] != '.') continue;
			u[idx] = '.'; u[ni] = '@';
			u = change(u);
			if (!mp.count(u)) {
				mp[u] = mp[t] + 1;
				que.push(u);
			}
		}
	}
	return -1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (cin >> N, N) {
		string s;
		FOR(i, 0, N) {
			string t;
			cin >> t;
			s += t;
		}
		cout << bfs(s) << endl;
	}

	return 0;
}