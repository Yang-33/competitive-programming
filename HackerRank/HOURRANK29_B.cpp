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

/* -----  2018/08/02  Problem: hourrank29 B / Link: __CONTEST_URL__  ----- */
/* ------問題------

数列Aを空でないP,Qにわける。
Pの積,Qの積のgcdが1になるような選択方法は何通りあるか。

-----問題ここまで----- */
/* -----解説等-----

選択すると一緒にしないといけないものをまとめる。
素因数分解をしてその要素についてUnionFindをする。
その結果、a[i]についてのグループ数がわかる。
2^cnt-2が答え。
想定解ではないかもしれなくて、数列をuniqueにした。
その際コーナーケースが有って、1です。

----解説ここまで---- */

struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
// UnionFind uf(n); uf.unionSet(i,j); if(uf.same(x,y))

vector<long long >make_factor(long long  n) {
	vector<long long >ans;
	for (long long i = 2; i * i <= n; i++) {
		while (n%i == 0) {
			ans.push_back(i);
			n /= i;
		}
	}
	if (n != 1)ans.push_back(n);
	return ans;
}
const long long mod = 1e9 + 7;

long long modpow(long long a, long long b) { 
	if (b == 0) return 1;
	return modpow(a * a % mod, b / 2) * (b & 1 ? a : 1) % mod;
}

#include <unordered_map>
int main() {

	int T; scanf("%d",&T);
	FOR(_, 0, T) {
		int N; scanf("%d", &N);
		VI a(N);
		int one = 0;
		FOR(i, 0, N) {
			scanf("%d", &a[i]);
			if (a[i] == 1)one++;
		}
		SORT(a);
		UNIQ(a);
		N = SZ(a);
		UnionFind uf(N+6e4);
		unordered_map<int, int>Map;
		int id = N+10;
		FOR(i, 0, N) {
			VL b = make_factor(a[i]);
			for (LL x : b) {
				if (Map.find(x) == Map.end())Map[x] = ++id;
				uf.unionSet(i,Map[x]);
			}
		}
		LL cnt = 0;
		if (one)cnt += one - 1;
		unordered_map<int,bool> check;
		FOR(i, 0, N) {
			int rt = uf.root(i);
			if (check.find(rt) == check.end()) {
				check[rt] = 1;
				cnt++;
			}
		}
		// comb
		LL ans = modpow(2, cnt);
		ans += (-2 + MOD);
		ans %= MOD;
		ans += MOD;
		ans %= MOD;
		if (cnt<=1)cout << 0 << endl;
		else cout << ans << endl;
	}

	return 0;
}
