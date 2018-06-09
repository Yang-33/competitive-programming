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

/* -----  2018/04/30  Problem: GCJ2018_R1_B C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

閉路がないとしてやっていけばよい

----解説ここまで---- */

LL R1[101];
LL R2[101];
LL G1[101];
LL G2[101];
int num = 0;
bool dfs(int a, LL x) {
	if (num > 10001) {
		return false;
	}
	num++;
	if (G1[a] >= x) {
		G1[a] -= x;
		return true;
	}
	LL res = x - G1[a];
	G1[a] = 0;
	if (dfs(R1[a], res) == false) {
		return false;
	}
	if (dfs(R2[a], res) == false) {
		return false;
	}
	return true;
}

bool check(LL x) {
	return dfs(0, x);
}

LL binary_search(int M) {
	LL ub = 1e16;
	LL lb = 0;
	FOR(i, 0, M) {
		G2[i] = G1[i];
	}
	while (abs(ub - lb) > 1) {
		LL mid = (ub + lb) / 2;
		//cout<<mid<<endl;
		num = 0;
		FOR(i, 0, M) {
			G1[i] = G2[i];
		}
		if (check(mid)) {
			lb = mid;
		}
		else {
			ub = mid;
		}
	}
	return lb;
}

int main() {
	int T;
	cin >> T;
	FOR(k, 0, T) {
		int M;
		cin >> M;
		FOR(i, 0, M) {
			cin >> R1[i] >> R2[i];
			R1[i]--;
			R2[i]--;
		}
		FOR(i, 0, M) {
			cin >> G1[i];
		}
		cout << "Case #" << (k + 1) << ": " << binary_search(M) << endl;
	}
	return(0);
}