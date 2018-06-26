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

/* -----  2018/06/26  Problem: AOJ 1312 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1312  ----- */
/* ------問題------

H*W,P*Pの二次元文字列がある。
パターンの方を回転、反転を全ておこなってよいとして、何回マッチするか。

-----問題ここまで----- */
/* -----解説等-----

2DRollingHashの練習問題と書かれているようなものなので、練習をする。
サンプルで分かるけど、回転一致に注意。

----解説ここまで---- */
typedef unsigned long long ull;


struct RollingHash2D {
	typedef unsigned long long ull;

	struct RollingHash {
		string S;
		ull B;
		int len;
		vector<ull> hash, p;
		RollingHash() {}
		RollingHash(string S_, ull B_ = 1000000007LL) :
			S(S_), B(B_), len(S.length()), hash(len + 1), p(len + 1) {
			hash[0] = 0; p[0] = 1;
			for (int i = 0; i < len; i++) {
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
		for (int i = 0; i < h; i++) rh[i] = RollingHash(S[i]);
		p[0] = 1;
		for (int i = 0; i < h; i++) p[i + 1] = p[i] * B;
		for (int j = 0; j < w - c + 1; j++) {
			hash[0][j] = 0;
			for (int i = 0; i < h; i++)
				hash[i + 1][j] = hash[i][j] * B + rh[i].find(j, j + c);
		}
	}
	//[i,i+r) * [j,j+c)
	ull find(int i, int j) {
		return hash[i + r][j] - hash[i][j] * p[r];
	}
};

int tonum(char c) {
	if (isupper(c))return c - 'A';
	if (islower(c))return c - 'a' + 26;
	if (isdigit(c))return c - '0' + 52;
	if (c == '+')return 62;
	if (c == '/')return 63;
	assert(0);
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int W, H, P;
	while (cin >> W >> H >> P, W) {
		VS pretable(H);
		FOR(i, 0, H) {
			cin >> pretable[i];
		}
		VS prepat(P);
		FOR(i, 0, P) {
			cin >> prepat[i];
		}
		auto trans = [](const VS& vs, int Re) {
			VS ret(SZ(vs));
			FOR(i, 0, SZ(vs)) {
				FOR(j, 0, SZ(vs[i])) {
					int num = tonum(vs[i][j]);
					string s = "";
					FORR(k, 5, 0 - 1) {
						if (num & 1 << k) {
							s += string(1, '1');
						}
						else {
							s += string(1, '0');
						}
					}
					ret[i] += s;
				}
				ret[i].resize(Re);
			}
			return ret;
		};

		VS table = trans(pretable, W);
		VS pat = trans(prepat, P);

		auto rev = [](VS &vs) {
			VS ret(vs);
			FOR(i, 0, SZ(vs)) {
				FOR(j, 0, SZ(vs[i])) {
					ret[i][SZ(vs[i]) - j - 1] = vs[i][j];
				}
			}
			return ret;
		};
		auto rot = [](VS &vs) {
			VS ret(vs);
			FOR(i, 0, SZ(vs)) {
				FOR(j, 0, SZ(vs[i])) {
					ret[j][SZ(vs[i]) - i - 1] = vs[i][j];
				}
			}

			return ret;
		};



		int ans = 0;
		RollingHash2D rT(table, P, P);
		set<ull>Se;
		FOR(kk, 0, 2) {
			// rev
			pat = rev(pat);
			FOR(k, 0, 4) {
				// rot
				pat = rot(pat);
				RollingHash2D rp(pat, P, P);
				ull hashval = rp.find(0, 0);
				if (Se.count(hashval))continue;
				
				Se.insert(hashval);
				FOR(i, 0, H - P + 1) {
					FOR(j, 0, W - P + 1) {
						if (rT.find(i, j) == rp.find(0, 0))ans++;
					}
				}
			}
		}
		cout << ans << endl;
	}


	return 0;
}
