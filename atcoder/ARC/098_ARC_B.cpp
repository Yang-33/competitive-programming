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


// a+b>=a^bっぽいので、しゃくとりで数える
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	LL sum = 0;
	LL Xor = 0;
	LL ans = 0;
	for (int l = 0, r = 0; l <N; l++) {
		while(r<N&&
			((sum+a[r] )== (Xor^a[r]))
			/*ただしいならすすめる*/) {
			sum += a[r]; Xor ^= a[r];
			ans += r-l+1;
			r++;

		}
		sum -= a[l], Xor ^= a[l];
	}


	cout << ans << endl;

	return 0;
}
