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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/06/26  Problem: AOJ ALDS1_14_C / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_C  ----- */
/* ------問題------

縦 H × 横 W の文字フィールドの中から、縦 R × 横 C の文字パターンを探してください。
文字パターンと一致する部分について、文字フィールドの左上の位置 (i, j) を順番にすべて報告してください。
ただし、文字フィールドの最も左上の位置を (0, 0)、最も右下の位置を (H-1, W-1) とします。

-----問題ここまで----- */
/* -----解説等-----

2DRollingHash

----解説ここまで---- */

//BEGIN CUT HERE
struct RollingHash2D {
	typedef unsigned long long ull;

	struct RollingHash {
		typedef unsigned long long ull;
		string S;
		ull B;
		int len;
		vector<ull> hash, p;
		RollingHash() {}
		RollingHash(string S_, ull B_ = 1000000007LL) :
			S(S_), B(B_), len(S.length()), hash(len + 1), p(len + 1) {
			hash[0] = 0; p[0] = 1;
			for (int i = 0; i<len; i++) {
				hash[i + 1] = hash[i] * B + S[i];
				p[i + 1] = p[i] * B;
			}
		}
		//S[l,r)
		ull find(int l, int r) {
			return hash[r] - hash[l] * p[r - l];
		}
	};

	vector<string> S;
	int h, w, r, c;
	ull B;
	vector<ull> p;
	vector<vector<ull> > hash;
	vector<RollingHash> rh;
	RollingHash2D() {}
	RollingHash2D(vector<string> S_, int r_, int c_, ull B_ = 1000000009LL) :
		S(S_), h(S_.size()), w(S_[0].size()), r(r_), c(c_), B(B_),
		p(h + 1), hash(h + 1, vector<ull>(w - c + 1, 0)), rh(h) {
		for (int i = 0; i<h; i++) rh[i] = RollingHash(S[i]);
		p[0] = 1;
		for (int i = 0; i<h; i++) p[i + 1] = p[i] * B;
		for (int j = 0; j<w - c + 1; j++) {
			hash[0][j] = 0;
			for (int i = 0; i<h; i++)
				hash[i + 1][j] = hash[i][j] * B + rh[i].find(j, j + c);
		}
	}
	//[i,i+r) * [j,j+c)
	ull find(int i, int j) {
		return hash[i + r][j] - hash[i][j] * p[r];
	}
};
//END CUT HERE

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int H, W;
	cin >> H >> W;
	VS t(H);
	FOR(i, 0, H) {
		cin >> t[i];
	}
	int subH, subW;
	cin >> subH >> subW;
	VS pat(subH);
	FOR(i, 0, subH) {
		cin >> pat[i];
	}


	RollingHash2D table(t,subH,subW);
	RollingHash2D pattable(pat,subH,subW);
	FOR(i, 0, H - subH + 1) {
		FOR(j, 0, W - subW + 1) {
			if (table.find(i,j)==pattable.find(0,0)) {
				printf("%d %d\n", i, j);
			}
		}
	}


	return 0;
}
