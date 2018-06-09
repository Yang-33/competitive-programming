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

/* -----  2018/05/05  Problem: GCJ2018_R1_C A / Link: https://codejam.withgoogle.com/2018/challenges/0000000000007765/dashboard  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

一つだけ変更すれば良い。  
複数個(x個)変更しないといけないとする。
(x-k)個変更しても一致するものがあるとする。これは一致するものから見ると一箇所も変更してないと見れる。(当たり前すぎる説明)
すると、ある文字をx-1個変更して一致するも物があれば、この一致するものを変更させれば良いことになる。
したがって1つだけ変更すれば良い。

----解説ここまで---- */


string solve() {
	int N, L;
	cin >> N >> L;
	VS vs(N);
	int ok = 0;
	set<string>SE;
	FOR(i, 0, N) {
		cin >> vs[i];
		SE.insert(vs[i]);
	}
	string target;
	FOR(tar, 0, N) {
		if (ok == 0) {
			target = vs[tar];
			FOR(j, 0, L) {
				FOR(i, 0, N) {
					if (tar == i)continue;
					if (ok == 1)continue;

					string ck = target;
					ck[j] = vs[i][j];
					if (SE.count(ck)) {

					}
					else {
						ok = 1;
						target = ck;
					}

				}
			}
		}
	}

	if (ok == 1) {
		return target;
	}
	else {
		return string(1, '-');
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int Case; cin >> Case;
	FOR(ccaassee, 0, Case) {
		cout << "Case #" << ccaassee + 1 << ": " << solve() << "\n";

	}

	return 0;
}
