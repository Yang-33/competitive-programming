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
#define DEBUG(x)
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/14  Problem: CODEFESTIVAL2018_QUAL_B C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

かぶらないようにしきつめる。

----解説ここまで---- */

void check(VVI& a) {
	VVI b = a;
	FOR(i, 0, SZ(a)) {
		FOR(j, 0, SZ(a[i])) {
			if (a[i][j]) {
				FOR(k, 0, 4) {
					int ny = i + DY[k];
					int nx = j + DX[k];
					if(0<=ny && ny < SZ(a) && 0<=nx && nx<SZ(a)){
						b[ny][nx] = 1;
					}
				}
			}
		}
	}
	int ok = 1;
	int cnt = 0;
	FOR(i, 0, SZ(a)) {
		FOR(j, 0, SZ(a)) {
			if (!b[i][j])a[i][j] = 2,b[i][j] =1;

			if (a[i][j])cnt++;
			ok &= b[i][j];
		}
	}
	DEBUG(
		debug(ok,cnt);
	)
	/*debug(ok); cout << endl;
	debug(cnt); cout << endl;*/
}


VVI paint(int N) {
	int tn = N;
	N = 1100;
	VVI a(N, VI(N,0));
	for (int i = 0; i < N; i += 5) {
		for (int j = 0; j < N; j += 5) {
			a[i][j+1] = 1;
			a[i+1][j+3] = 1;
			a[i+2][j] = 1;
			a[i+3][j+2] = 1;
			a[i+4][j+4] = 1;
		}
	}
	VVI res(tn, VI(tn, 0));
	FOR(i, 0, tn) {
		FOR(j, 0, tn) {
			res[i][j] = a[i+10][j+10];
		}
	}
	return res;
}


LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;


	VVI a = paint(N);
	DEBUG(
//		D(a);
		//D(a);
	);
	check(a);
	DEBUG(
	//	D(a);
	)

	{
		FOR(i, 0, N) {
			FOR(j, 0, N) {
				if (a[i][j])cout << "X";
				else cout << ".";
			}cout << endl;
		}
	}
	


	return 0;
}
