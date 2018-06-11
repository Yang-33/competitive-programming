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
// �ɂԂ���

bool f(LL x, VL&M, VL&S, VL&P, LL R, LL B) {
	LL res = 0;
	LL N = SZ(M);

	VL box;
	FOR(i, 0, N) {
		LL can = x - P[i];
		if (can > 0) {
			box.push_back(min(M[i],can/S[i]));
		}
		else box.push_back(0);
	}
	RSORT(box);
	FOR(i, 0, R) {
		res += box[i];
	}
	return res>=B;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Case; cin >> Case;
	FOR(kim, 0, Case) {
		cout << "Case #" << kim + 1 << ": ";
		LL R, B, C; cin >> R >> B >> C;
		VL M(C), S(C), P(C);
		FOR(i, 0, C) {
			cin >> M[i] >> S[i] >> P[i];
		}
		LL L = 0; LL RR = 4e18;
		FOR(i, 0, 100) {
			LL mid = (L + RR) / 2;
			if (f(mid, M, S, P, R, B)) {
				RR = mid;
			}
			else {
				L = mid;
			}
		}
		LL ans = RR;
		cout << ans << "\n";
	}

	return 0;
}