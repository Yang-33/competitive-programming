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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/16  Problem: yukicoder 074  / Link: http://yukicoder.me/problems/no/074  ----- */
/* ------問題------

貯金箱くんはとても退屈していました。
そこで自分が持っている硬貨で遊ぶことにしました。

まず自分の持っている硬貨を床にばらまき、そこから N 枚硬貨を選び円形に並べます。
次に N 枚の硬貨から適当に1枚選びます。選んだ硬貨の額面を D 円としたとき、選んだ硬貨から時計回りに D 個先の硬貨と、反時計回りに D 個先の硬貨をひっくり返します。
ただし時計回りでも反時計回りでも同じ硬貨だった場合はその硬貨を1回だけひっくり返します。
貯金箱くんは、この操作を繰り返しすべての硬貨を表向きにしたいです。

硬貨の並び、額面、最初の裏表が与えられるのですべての硬貨を表向きにできるか判定してください。
ただし同じ硬貨を複数回選んでもよいとします。

-----問題ここまで----- */
/* -----解説等-----

無限時間解けて悲しい。連結成分について全然考えが進まなくて解説を見ました。ダメ  
解法1: コインを選択したときの選択先について、これらのグループは任意の二枚を反転できる。これを利用すればグループのサイズ、自己辺の存在から判定ができる。  
解法2: 合同方程式,mod=2の場合で反転回数で解く。

解法1: O(N)
解法2: O(N^3) ただしbit並列をすれば64倍高速


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



long long extgcd(long long a, long long b, long long &x, long long &y) {
	long long d = a;
	if (b != 0) {
		d = extgcd(b, a%b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}
	return d;
}

long long mod_inverse(long long a, long long m) {
	long long x, y;
	extgcd(a, m, x, y);
	return (m + x%m) % m;
}


// A[n*p] * X[p*m] = B[n*m]
template<class T = int>
int gaussian_elimination_with_mod(vector<vector<T>>& A, vector<vector<T>>& B, int n, int p, int m, const T mod) {
	int R = max(n, p); int C = p + m;
	vector<vector<T>> V(R, vector<T>(C, 0));
	for (int i = 0; i<n; i++)
		for (int j = 0; j<p; j++) V[i][j] = A[i][j];
	for (int i = 0; i<n; i++)
		for (int j = 0; j<m; j++) V[i][j + p] = B[i][j];


	int rank = 0;
	int row = 0;

	vector<int> left(R, -1);

	//foward
	for (int col = 0; col<C && row<R; col++) {
		//pivot
		T val = abs(V[row][col]);
		int pivot = row;
		for (int j = row + 1; j<R; j++) {
			if (val < abs(V[j][col])) {
				val = abs(V[j][col]);
				pivot = j;
			}
		}
		if (pivot != row) swap(V[row], V[pivot]);

		if (val == 0) continue;

		T inv = mod_inverse(val, mod);
		for (int j = row + 1; j<R; j++) {
			T c = (V[j][col] * inv + mod) % mod;
			for (int k = col; k<p + m; k++) V[j][k] = ((V[j][k] - V[row][k] * c) % mod + mod) % mod;
		}

		left[row] = col;
		row++;
		rank++;
	}

	//backward
	for (int i = R - 1; i >= 0; i--) {
		bool zero = true;
		bool valid = true;
		for (int col = 0; col<p; col++) if (V[i][col] != 0) zero = false;
		for (int col = p; zero && col<C; col++) if (V[i][col] != 0) valid = false;

		if (valid == false) return -1;	//no solution

		if (left[i] == -1) continue;

		T inv = mod_inverse(V[i][left[i]], mod);
		for (int j = left[i]; j<C; j++) V[i][j] = (V[i][j] * inv) % mod;

		for (int j = i - 1; j >= 0; j--) {
			for (int k = 0; k<C; k++) {
				V[j][k] = ((V[j][k] - V[j][i] * V[i][k]) % mod + mod) % mod;
			}
		}
	}
	//return V;
	return rank;
}

void solve1() {
	LL N; cin >> N;
	VL D(N), W(N);
	FOR(i, 0, N)cin >> D[i];
	FOR(i, 0, N)cin >> W[i];
	VVI A(N, VI(N, 0));
	FOR(i, 0, N) {
		int r = (i + D[i]) % N;
		int l = (i - D[i] + N * 1000) % N;
		A[r][i] = A[l][i] = 1;
	}
	VVI B(N, VI(1, 0));
	FOR(i, 0, N) {
		B[i][0] = !W[i];
	}

	int ans = gaussian_elimination_with_mod(A, B, N, N, 1, 2);
	cout << (ans == -1 ? "No" : "Yes") << endl;
}
void solve2() {
	LL N; cin >> N;
	UnionFind uf(N);
	VL D(N), W(N);
	VI self(N, 0);
	FOR(i, 0, N) {
		cin >> D[i];
		int r = (i + D[i]) % N;
		int l = (i - D[i] + N * 1000) % N;
		if (r == l)self[r] = 1;
		uf.unionSet(r, l);
	}
	VI groupOK(N, 0);
	FOR(i, 0, N) {
		if (self[i])groupOK[uf.root(i)] = 1;
	}
	VI groupSIZE(N, 0);
	FOR(i, 0, N) {
		int w; cin >> w;//0:裏
		if (w == 0) {
			groupSIZE[uf.root(i)]++;
		}
	}
	FOR(i, 0, N) {
		if (uf.root(i) == i && groupSIZE[i] % 2 == 1 && groupOK[i] == 0) {
			cout << "No" << endl; return;
		}
	}
	cout << "Yes" << "\n";
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	solve1(); // 合同方程式解
	return 0;
	solve2(); // UF解
	
}
