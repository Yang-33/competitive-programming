#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define FOR(i,s,e) for(int (i) = (s); (i) < (e); (i)++)
#define debug(x) cout  << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/11/01  Problem: ICPC国内予選2009E / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1161&lang=jp  ----- */
/* ------問題------

覆面算

-----問題ここまで----- */
/* -----解説----

アルファベットごとの割り振りを行う。Ｏ(ALPHA^10).(10^10)

----解説ここまで---- */

ll ans = 0;
int N;
vector<char>alpha;
int alnum_e[30], used[30], notzero[30];

ll solve(int id, ll sum) {
	ll ret = 0;
	if (id == alpha.size())return sum == 0LL;

	//alpha[id]の割り当ての全探索
	int ch = alpha[id] - 'A';
	FOR(i, 0, 10) {
		if (used[i])continue;
		if (i == 0 && notzero[ch])continue;
		used[i] = 1;
		ret += solve(id + 1, sum + alnum_e[ch] * i);
		used[i] = 0;
	}

	return ret;
}

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (cin >> N, N) {

		alpha.clear();
		FOR(i, 0, 30)alnum_e[i] = 0, used[i] = 0, notzero[i] = 0;
		FOR(i, 0, N) {
			string s; cin >> s;
			if (s.size() != 1)notzero[s[0] - 'A'] = 1;
			reverse(s.begin(), s.end());

			int tanee = 1;
			FOR(j, 0, s.size()) {
				alpha.push_back(s[j]);
				if (i == N - 1) {
					alnum_e[s[j] - 'A'] += -tanee;
				}
				else {
					alnum_e[s[j] - 'A'] += tanee;
				}
				tanee *= 10;
			}
		}
		sort(alpha.begin(), alpha.end());
		alpha.erase(unique(alpha.begin(), alpha.end()), alpha.end());

		ans = solve(0, 0LL);
		cout << ans << endl;
	}
	return 0;
}