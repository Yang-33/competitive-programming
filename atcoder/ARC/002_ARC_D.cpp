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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2019/04/03  Problem: ARC 002 D / Link: http://arc002.contest.atcoder.jp/tasks/arc002_d  ----- */

// space2のときが貪欲

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;
	vector<string> a(H);
	for (int i = 0; i < H; ++i) {
		cin >> a[i];
	}

	//xoならcut

	static const int WHITE = 1;
	static const int BLACK = 2;
	static const int BOTH = 3;

	// sの[S,T)を評価
	// (STATE,oの余ターン)
	using tp = tuple<int, int, int>;
	static vector<tp> parallel_scores;
	auto f = [](const string& s, int S, int T) {
		PII res;
		int ocnt = count(s.begin() + S, s.begin() + T, 'o');
		int xcnt = count(s.begin() + S, s.begin() + T, 'x');
		int lasto = s.substr(S, T - S).find_last_of('o') + S;
		int firstx = s.substr(S, T - S).find_first_of('x') + S;
		if (ocnt&&xcnt) {
			res.first = BOTH;
			int center = (lasto + firstx + 1) / 2;// koko

			if ((firstx - lasto) % 2 == 1) {
				parallel_scores.push_back(tp(ocnt + xcnt, ocnt, xcnt));
				//return res;
			}

			DD(de(center, lasto, firstx))
				int score = 0;
			{ // o
				int lastpos = center-((firstx - lasto) % 2 == 1);
				for (int i = lastpos; i >= S; i--) {
					if (s[i] == 'o') {
						score += lastpos - i - 1;
						lastpos--;
					}
				}
			}
			{ // x
				int lastpos = center;
				for (int i = lastpos; i < T; i++) {
					if (s[i] == 'x') {
						score -= i - lastpos - 1;
						lastpos++;
					}
				}
			}
			res.second = score;
		}
		else if (ocnt) {
			res.first = WHITE;
			res.second = SZ(s) - 1 - lasto;

		}
		else {
			res.first = BLACK;
			res.second = firstx;
		}
		DD(de("call", S, T, res));

		return res;
	};

	int xmin = INF, omin = INF;
	int tiescore = 0;
	FOR(i, 0, H) {

		char prevc = a[i].front();
		int lastid = 0;
		FOR(j, 0, W) {
			if (prevc == 'x'&&a[i][j] == 'o') {
				auto res = f(a[i], lastid, j);
				if (res.first == BOTH) {
					tiescore += res.second;
				}
				else if (res.first == WHITE) {
					omin = min(omin, res.second);
				}
				else {
					xmin = min(xmin, res.second);
				}

				lastid = j;
			}


			if (a[i][j] != '.')prevc = a[i][j];
		}
		auto res = f(a[i], lastid, W);
		if (res.first == BOTH) {
			tiescore += res.second;
		}
		else if (res.first == WHITE) {
			omin = min(omin, res.second);
		}
		else {
			xmin = min(xmin, res.second);
		}
		DD(de(tiescore, omin, xmin));
	}

	// koko
	RSORT(parallel_scores);
	bool turn = 0;
	for (auto it : parallel_scores) {
		if (!turn) {
			tiescore += get<1>(it);
		}
		else {
			tiescore -= get<2>(it);
		}

		turn ^= 1;
	}
	DD(de("last",tiescore, omin, xmin));
	int ans = 0;
	if (xmin != INF || omin != INF) {
		ans = (omin <= xmin);
	}
	else {
		ans = tiescore > 0;
	}


	cout << (ans ? "o" : "x") << "\n";

	return 0;
}
