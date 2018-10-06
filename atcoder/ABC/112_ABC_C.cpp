#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
using PLL = pair<LL, LL>;




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI x(N), y(N), h(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> h[i];
	}

	auto f = [&](int CX, int CY) {
		LL H = -1;
		bool flag = 1;
		FOR(i, 0, N) {
			if (H == -1 && h[i]) {
				H = abs(CX - x[i]) + abs(CY - y[i]) + h[i];
			}
		}
		FOR(i, 0, N) {
			LL HQ = max(H - (abs(CX - x[i]) + abs(CY - y[i])), 0LL);
			if (HQ != h[i])flag = 0;
		}
		return PLL(H, flag);
	};

	FOR(xx, 0, 101) {
		FOR(yy, 0, 101) {
			PLL val = f(xx, yy);
			if (val.second) {
				int ans = val.first;

				cout << xx << " " << yy << " ";
				cout << ans << endl;
				return 0;
			}
		}
	}

	return 0;
}
