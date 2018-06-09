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
// int DX[9] = { 0, 0, 1, -1, 1, 1, -1, -1 ,0 };    int DY[9] = { 1, -1, 0, 0, 1, -1, 1, -1 ,0 };
int DX[9] = { -1, 0, 1, -1, 0, 1, -1, 0 ,1 };
int DY[9] = { -1, -1, -1, 0, 0, 0, 1, 1 ,1 };
/* -----  2018/04/07  Problem: GCJ2018_qual C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

乱数について考えると最悪なパターンは起きにくいのて、前から全部ぬれたら遷移する的なことをすればよい。

----解説ここまで---- */


PII ask(int a, int b) {
	cout << a << " " << b << endl;
	cin >> a >> b;
	return PII(a, b);
}

inline void InitRand()
{
	srand((unsigned int)time(NULL));
}

/* 適当なlong long の乱数 */
long long myrand() {
	return abs(rand() * rand() + 2311 * rand() + 1992);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	InitRand();
	int T; cin >> T;
	FOR(_, 0, T) {
		int A; cin >> A; // 20 / 200
		//debug(A);
		if (A == 20) {
			FOR(q, 0, 1000) {
				int x = 98 + myrand() % 3, y = 98 + myrand() % 3;
				PII a = ask(x, y);
				if (a == PII(0, 0)) {
					break;
				}
				else {


				}
			}
		}
		else {
			VVI masu(3, VI(68, 0));
			{
				FOR(q, 0, 1000) {
					FOR(i, 1, 67) {
						int cnt = 0;
						FOR(k, 0, 9) {
							int x = 1 + DX[k];
							int y = i + DY[k];
							if(masu[x][y])cnt |= 1<<k;
						}
						if ((cnt & 7)!=7||(cnt!=9 && i>64)) {
							int x = 1; int y = i;
							PII a = ask(x + 100, y + 100);
							if (a == PII(0, 0))goto endP;
							masu[a.first - 100][a.second - 100] = 1;
							goto qq;
						}
					}
					//if (q ==999) {
					//	int c = 0;
					//	FOR(i, 0, 3) {
					//		FOR(j, 0, 67) {
					//			c += masu[i][j];
					//		}
					//	}
					//	debug(c);
					//}
				qq:;
				}
			}
		endP:;
		}
	}

	return 0;
}
