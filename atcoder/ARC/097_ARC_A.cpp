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


// 辞書順最小を知っていれば、取り出してsort,k番目を取れば良い。
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	int K; cin >> K;
	set<string> vs;
	FOR(k, 1, K + 1) {
		FOR(i, 0, SZ(s)) {
			int j = i + k;
			string a;
			FOR(m, i, j) {
				if(m<SZ(s))
				a += s[m];
			}
			if(SZ(a))vs.insert(a);
		}
	}
	string ans;
	int i = 0;
	for (auto it = vs.begin(); i != K; ) {
		ans = *it;
		i++;
		it++;
	}
	cout << ans << endl;

	return 0;
}
