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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/05/26  Problem: google_kickstart2019_roundC A / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000050ff2  ----- */

// 
void solve(int testcasenum) {


	int N; cin >> N;
	int H, W; cin >> H >> W;
	int Y, X; cin >> Y >> X;
	string s; cin >> s;
	//	string URDL = "URDL";
	string URDL = "SENW";
	map<char, int>Map;
	FOR(i, 0, SZ(URDL))Map[URDL[i]] = i;
	using tp = tuple<int, int, int>;
	map<tp, PII>posMap;
	const int DY[] = { 1, 0,-1, 0, }; const int DX[] = { 0, 1,0, -1, };
	auto relink = [&posMap, &DY, &DX](int y, int x) {
		FOR(i, 0, 4) {
			if (posMap.find(tp(y, x, i)) == posMap.end()) {
				posMap[tp(y, x, i)] = PII(y + DY[i], x + DX[i]);
			}
		}
		FOR(i, 0, 4) {
			int rev = (i + 2) % 4;
			PII nx = posMap[tp(y, x, i)];
			posMap[tp(nx.first, nx.second, rev)] = posMap[tp(y, x, rev)];
		}

	};
	int y = Y, x = X;
	relink(y, x);
	for (char c : s) {
		PII nx = posMap[tp(y, x, Map[c])];
		y = nx.first, x = nx.second;
		DD(de(y, x));
		relink(y, x);
	}
	cout << "Case #" << testcasenum << ": ";
	cout << y << " " << x << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		solve(t + 1);
	}

	return 0;
}
