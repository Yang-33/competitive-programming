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

/* -----  2018/08/03  Problem: edu48 C / Link: __CONTEST_URL__  ----- */
/* ------問題------

変化する重み付き経路、一筆書き

-----問題ここまで----- */
/* -----解説等-----

縮退辺と差分を管理すればいいだけで、そんなに大変ではない。
途中でmaxをとらなかったのでWA(そう…)
実装はすぐできたけど頭まわってなさすぎ…

----解説ここまで---- */

int main() {

	int N; scanf("%d", &N);
	VVL a(2, VL(N));
	FOR(i, 0, 2) {
		FOR(j, 0, N) {
			scanf("%lld", &a[i][j]);
		}
	}
	LL ans = 0;
	// 3 ways
	{/// guru
		LL t = 0;
		LL ret = 0;
		FOR(i, 0, N) {
			ret += t*a[0][i];
			t++;
		}
		FORR(i, N - 1, 0-1) {
			ret += t*a[1][i];
			t++;
		}
		ans = max(ans, ret);
	}

	{// sita guru
		LL t = 1;
		LL ret = 0;
		FOR(i, 0, N) {
			ret += t*a[1][i];
			t++;
		}
		FORR(i, N - 1, 0) {
			ret += t*a[0][i];
			t++;
		}

		ans = max(ans, ret);
	}

	{// uku + return 
		{
			// topを修正する
			vector<PLL>tops;
			VL topsum(N + 1, 0);
			FOR(i, 0, N) {
				topsum[i + 1] += topsum[i] + a[0][i];
			}
			VL undersum(N + 1, 0);
			FOR(i, 0, N) {
				undersum[i + 1] += undersum[i] + a[1][i];
			}
			LL t = 0;
			LL ret = 0;

			FOR(i, 0, N) {
				if (i % 2 == 0) {//down
					if (i) {
						tops.push_back(PLL(i-1,t-1));
					}
					ret += t*a[0][i];
					t++;
					ret += t*a[1][i];
					t++;
				}
				else {
					ret += t*a[1][i];
					t++;
					ret += t*a[0][i];
					t++;
				}
			}
			ans = max(ans, ret);

			LL T = t - 1;

			if (N % 2 == 1 && N>1) { //fix
				tops.pop_back();
				ret -= (T - 2)*a[0][N - 2];
				ret -= (T - 1)*a[0][N - 1];
				ret -= (T - 0)*a[1][N - 1];

				ret += (T - 2)*a[1][N - 1];
				ret += (T - 1)*a[0][N - 1];
				ret += (T - 0)*a[0][N - 2];
			}
			// delete and add 
			while (tops.size()) {
				LL prefID, pastT;
				tie(prefID, pastT) = tops.back(); tops.pop_back();
				ret -= pastT*a[0][prefID];
				ret -= (pastT+1)*a[0][prefID+1];
				
				// 引いたので列を-2
				ret -= 2*(topsum[N] - topsum[(prefID+2)]);
				ret -= 2*(undersum[N] - undersum[(prefID+1)]);


				// 最後に足す
				ret += T*a[0][prefID];
				ret += (T-1)*a[0][prefID+1];
				ans = max(ans, ret);

			}


		}
		{
			// downを修正する
			vector<PLL>downs;
			VL downsum(N + 1, 0);
			FOR(i, 0, N) {
				downsum[i + 1] += downsum[i] + a[1][i];
			}
			VL topssum(N + 1, 0);
			FOR(i, 0, N) {
				topssum[i + 1] += topssum[i] + a[0][i];
			}
			LL t = 0;
			LL ret = 0;

			FOR(i, 0, N) {
				if (i % 2 == 0) {//down
					ret += t*a[0][i];
					t++;
					ret += t*a[1][i];
					t++;
				}
				else {
					if (i) {
						downs.push_back(PLL(i - 1, t - 1));
					}
					ret += t*a[1][i];
					t++;
					ret += t*a[0][i];
					t++;
				}
			}
			ans = max(ans, ret);

			LL T = t - 1;

			if (N % 2 == 0) { //fix
				downs.pop_back();
				ret -= (T - 2)*a[1][N - 2];
				ret -= (T - 0)*a[0][N - 1];

				ret += (T - 2)*a[0][N - 1];
				ret += (T - 0)*a[1][N - 2];
			}
			// delete and add 
			while (downs.size()) {
				LL prefID, pastT;
				tie(prefID, pastT) = downs.back(); downs.pop_back();
				ret -= pastT*a[1][prefID];
				ret -= (pastT + 1)*a[1][prefID + 1];

				// 引いたので列を-2
				ret -=2*( downsum[N] - downsum[(prefID + 2)]);
				ret -= 2*(topssum[N] - topssum[(prefID + 1)]);


				// 最後に足す
				ret += T*a[1][prefID];
				ret += (T - 1)*a[1][prefID +1];
				ans = max(ans, ret);

			}

		}

	}

	cout << ans << "\n";

	return 0;
}
