#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef vector<string> VS;

#define ALL(a)  a.begin(),a.end()
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

/* -----  2017/12/11  Problem: POJ 1328 / Link: http://poj.org/problem?id=1328  ----- */
/* ------問題------

X軸の周りに点がN点ある。
X軸を中心にして、半径Dの円をおいてこの点をカバーするとき、最小で何個円を置けばいいか。

-----問題ここまで----- */
/* -----解説等-----

点をカバーするのに被覆しなくてはならない区間を考えると、右端を基準にしてソートすればいいことに気づく。
基準点は新たに設置する円をなるべく右に寄せたほうがいいので、円を新たに設置するまでは更新しない。
値に対して線分をのせれるだけ載せる感じをやればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;
struct segment {
	double L;
	double R;
	bool operator < (const segment &x) const{
		if (R != x.R)return R < x.R;
		else return L < x.L;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	
	int D;
	int cs = 1;
	while (cin >> N >> D, N||D) {
		ans = 0;
		vector<segment>p(N);
		int ok = 1;
		FOR(i, 0, N) {
			int x, y; cin >> x >> y;
			double delta = sqrt(1.0*D*D- 1.0*y*y);
			p[i].L = x- delta;
			p[i].R = x + delta;
			if (y > D)ok = 0;
		}
		cout << "Case " << cs++ << ": ";
		if (ok == 0) {
			ans = -1;
		}
		else {
			SORT(p);
			double now = p[0].R;
			ans = 1;
			FOR(i, 1, N) {
				if (now < p[i].L) {
					ans++;
					now = p[i].R;
				}
			}


		}

		cout << ans << "\n";
	}

	return 0;
}