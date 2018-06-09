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

// 間に合うのでBITを使う(累積和の区間はバグるので)
template<typename type>
struct BIT0 { 
	int N;
	int nn;
	vector<type> data;
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) {
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) {
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	type sum(int l, int r) {
		return sum(r) - sum(l);
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	string s;
	cin >> s;
	BIT0<LL> bitW(N + 10);
	BIT0<LL> bitE(N + 10);
	FOR(i, 0, N) {
		if (s[i] == 'W')bitW.add(i, 1);
		else bitE.add(i, 1);
	}
	LL ans =LINF;
	FOR(i, 0, N) {
		LL ret = bitW.sum(0, i) + bitE.sum(i + 1, N);
		ans = min(ans, ret);
	}
	

	cout << ans << endl;

	return 0;
}
