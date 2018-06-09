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
#define debug(x) cout << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/14  Problem: GCJ2018_R1_A C / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

// がんばればよい

long double solve1(VL& w, VL &h, LL P) {// same
	LL Min = 4.0*min(w[0], h[0])*min(w[0], h[0]);
	LL Max = 4.0 * (w[0] * w[0] + h[0] * h[0]);
	LL m = 0, M = 0;
	if (P*P< Min)return 0;
	FOR(i, 0, SZ(w)) {
		m = (i + 1)*Min, M = (i + 1)* Max;
		//debug(m); debug(P*P); debug(M); debug(P);
		if (m <= P*P && P*P <= M) {
			return P;
		}
	}
	return 2*SZ(w)*sqrt(w[0] * w[0] + h[0] * h[0]);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Case; cin >> Case;
	FOR(kim, 0, Case) {
		cout << "Case #" << kim + 1 << ": ";
		int N; LL P; cin >> N >> P;

		VL w(N), h(N);
		LL sum = 0;
		LL ww, hh, flag = -1;
		FOR(i, 0, N) {
			cin >> w[i] >> h[i];
			sum += 2 * w[i] + 2 * h[i];
			if (flag == -1) {
				ww = w[i], hh = h[i];
				flag = 1;
			}
			else if (flag == 1) {
				if (ww != w[i] || hh != h[i])flag = 0;
			}
		}
		P -= sum;
		//assert(flag);
		long double ans = 0;
		if (flag == 1) {
			if(P>0)ans = solve1(w, h, P);
			//debug(ans);
		}
		else {

		}



		ans += sum;
		cout << fixed << setprecision(6) << ans << "\n";
	}
	return 0;
}
