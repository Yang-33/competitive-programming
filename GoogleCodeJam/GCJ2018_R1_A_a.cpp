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
#define debug(x) cout<< #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };


// ŽÀ‘•‚·‚ê‚Î‚æ‚¢

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int  Case; cin >> Case;
	FOR(kim, 0, Case) {
		cout << "Case #" << kim + 1 << ": ";
		int R, C, H, V; cin >> R >> C >> H >> V;
		VS s(R);
		int sum = 0;
		FOR(i, 0, R) {
			cin >> s[i];
			FOR(j, 0, C) {
				if (s[i][j] == '@')sum++;
			}
		}
		int ans = 0;
		if (sum % ((H + 1)*(V + 1)) == 0) {
			if (sum == 0) {
				ans = 1;
				goto End;
			}
			int eachv = sum / (V + 1);
			//debug(sum);
			//debug(eachv);
			VI pos; // size == V?
			int vcnt = 0;
			FOR(j, 0, C) {
				int in = 0;
				FOR(i, 0, R) {
					if (s[i][j] == '@') {
						vcnt++;
						if (in == 1) {
							goto End;
						}
						if (vcnt% eachv == 0) {
							pos.push_back(j);
							in = 1;
						}
					}
				}
			}
			if (SZ(pos) != V + 1) {
				ans = 0;
				goto End;
			}
			VI vpos;
			vpos.push_back(-1);
			FOR(i, 0, V + 1)vpos.push_back(pos[i]);
			//FOR(i, 0, V + 1) {
			//	cout << vpos[i] << "," << vpos[i + 1] << endl;
			//}

			eachv = sum / (H + 1);
//			debug(eachv);
			pos.clear(); // size == V?
			int hcnt = 0;
			FOR(i, 0, R) {
				int in = 0;
				FOR(j, 0, C) {
					
					if (s[i][j] == '@') {
						hcnt++;
						if (in == 1) {
							goto End;
						}
						if (hcnt% eachv == 0) {
							pos.push_back(i);
							in = 1;
						}
					}
				}
			}
			if (SZ(pos) != H + 1) {
				ans = 0;
				goto End;
			}



			VI hpos;
			hpos.push_back(-1);
			FOR(i, 0, H + 1)hpos.push_back(pos[i]);
			/*debug(SZ(pos));
			FOR(i, 0, H + 1) {
				cout << hpos[i] << "," << hpos[i + 1] << endl;
			}*/

			//[0,pos[0]](pos[i-1],pos[i]] divide
			int block = sum / (H + 1) / (V + 1);
			FOR(v, 0, V + 1) {// ->
				FOR(h, 0, H + 1) {// down
					int Cnt = 0;
					for (int i = hpos[h] + 1; i <= hpos[h + 1]; i++) {
						for (int j = vpos[v] + 1; j <= vpos[v + 1]; j++) {
							if (s[i][j] == '@')Cnt++;
						}
					}
					if (block != Cnt) {
						ans = 0;
						goto End;
					}
				}
			}
			ans = 1;

		}

	End:;
		if (ans) {
			cout << "POSSIBLE" << endl;
		}
		else {
			cout << "IMPOSSIBLE" << endl;
		}
	}
	return 0;
}
