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

/* -----  2017/12/25  Problem: 055_arc_b / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL N, K;


double dp[1003][1003][2];

double f(int i, int k, int eat) {
	//if (k > K)return 0;
	if (i == N) {
		//if(k==K)
		return eat;
	}
	double &ret = dp[i][k][eat];
	if (ret != -1)return ret;

	ret = 0; //max

	//ret += f(i + 1, k, eat)*((1.0*N - 1.0*i - 1.0) / (1.0* (N - i)));
	if (k < K) {
		ret += f(i + 1, k, eat)*i; //(i fr i+1)

		double choice = max(f(i + 1, k, 0), f(i + 1, k + 1, 1));//(1 fr i+1)
		ret += choice;
	}
	else {
		ret += f(i + 1, k, eat)*i;
		ret += f(i + 1, k, 0);
	}

	ret /= (1.0*(i + 1));
	return ret;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;

	fill(**dp, **dp + 1003 * 1003 * 2, -1);

	double ans = f(0, 0, 0);

	cout << fixed << setprecision(12) << ans << "\n";

	return 0;
}
