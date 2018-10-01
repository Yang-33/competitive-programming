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

/* -----  2018/10/01  Problem: yukicoder 310  / Link: http://yukicoder.me/problems/no/310  ----- */
/* ------問題------

オイラー路の数え上げ

-----問題ここまで----- */
/* -----解説等-----

ref: antaさんのsubmission
これ無理！線形代数の勉強から始めます
結局、sparseな-1だらけの行列式を求めたいことになる。
N^3しか思いつかないが、なんかN^2ぐらいになって最高らしい

kmjpさんによると乱択でも通るっぽい  -1が多いことに起因しているらしい

----解説ここまで---- */

#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
using namespace std;

////////////////////////////////////////////////////////
//ModInt

template<int MOD>
struct ModInt {
	static const int Mod = MOD;
	unsigned x;
	ModInt() : x(0) {}
	ModInt(signed sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	ModInt(signed long long sig) { int sigt = sig % MOD; if (sigt < 0) sigt += MOD; x = sigt; }
	int get() const { return (int)x; }

	ModInt &operator+=(ModInt that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator-=(ModInt that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
	ModInt &operator*=(ModInt that) { x = (unsigned long long)x * that.x % MOD; return *this; }
	ModInt &operator/=(ModInt that) { return *this *= that.inverse(); }

	ModInt operator+(ModInt that) const { return ModInt(*this) += that; }
	ModInt operator-(ModInt that) const { return ModInt(*this) -= that; }
	ModInt operator*(ModInt that) const { return ModInt(*this) *= that; }
	ModInt operator/(ModInt that) const { return ModInt(*this) /= that; }

	ModInt inverse() const {
		signed a = x, b = MOD, u = 1, v = 0;
		while (b) {
			signed t = a / b;
			a -= t * b; std::swap(a, b);
			u -= t * v; std::swap(u, v);
		}
		if (u < 0) u += Mod;
		ModInt res; res.x = (unsigned)u;
		return res;
	}

	bool operator==(ModInt that) const { return x == that.x; }
	bool operator!=(ModInt that) const { return x != that.x; }
	ModInt operator-() const { ModInt t; t.x = x == 0 ? 0 : Mod - x; return t; }
};
typedef ModInt<1000000007> mint;

////////////////////////////////////////////////////////
//Black box linear algebra

//Berlekamp-Massey algorithm
//(\sum_{j=0}^L C[j] s[i + L - j]) = 0 for all 0 <= i < N - L
//となるような最小の L, C を返す。C[0] = 1 である
int berlekampMessey(const vector<mint> &s, vector<mint> &C) {
	int N = (int)s.size();
	C.assign(N + 1, mint());
	vector<mint> B(N + 1, mint());
	C[0] = B[0] = 1;
	int degB = 0;
	vector<mint> T;
	int L = 0, m = 1;
	mint b = 1;
	for (int n = 0; n < N; ++n) {
		mint d = s[n];
		for (int i = 1; i <= L; ++i)
			d += C[i] * s[n - i];
		if (d == mint()) {
			++m;
		}
		else {
			if (2 * L <= n)
				T.assign(C.begin(), C.begin() + (L + 1));
			mint coeff = -d * b.inverse();
			for (int i = 0; i <= degB; ++i)
				C[m + i] += coeff * B[i];
			if (2 * L <= n) {
				L = n + 1 - L;
				B.swap(T);
				degB = (int)B.size() - 1;
				b = d;
				m = 1;
			}
			else {
				++m;
			}
		}
	}
	C.resize(L + 1);
	return L;
}

//体上の数列のminimum polynomialを計算する。
//(\sum_{j=0}^d phi[j] s[i + j]) = 0 for all i
void computeMinimumPolynomialForLinearlyRecurrentSequence(const vector<mint> &a, vector<mint> &phi) {
	int n2 = (int)a.size(), n = n2 / 2;
	assert(n2 % 2 == 0);
	int L = berlekampMessey(a, phi);
	reverse(phi.begin(), phi.begin() + (L + 1));
}

struct RandomModInt {
	default_random_engine re;
	uniform_int_distribution<int> dist;
#ifndef _DEBUG
	RandomModInt() : re(random_device{}()), dist(1, mint::Mod - 1) { }
#else
	RandomModInt() : re(), dist(1, mint::Mod - 1) { }
#endif
	mint operator()() {
		mint r;
		r.x = dist(re);
		return r;
	}
} randomModInt;

void randomModIntVector(vector<mint> &v) {
	int n = (int)v.size();
	for (int i = 0; i < n; ++i)
		v[i] = randomModInt();
}


////////////////////////////////////////////////////////
//ユーティリティー
struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if (x != y) {
			if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

////////////////////////////////////////////////////////
//解答メイン部分

#ifdef MY_LOCAL_RUN
#define RANDOM_TEST
#define NAIVE_CHECK
//#define TIME_CHECK
#endif

mint dot(const vector<mint> &a, const vector<mint> &b) {
	int n = (int)a.size();
	assert(b.size() == n);
	mint sum;
	rep(i, n)
		sum += a[i] * b[i];
	return sum;
}

mint computeDeterminant(int N, const vector<mint> &diag, const vector<pair<int, int> > &validEdges, int src, int dst) {
	int n = N - 1;
	if (n == 0)
		return 1;
	vector<mint> D(n);
	vector<mint> m;
	randomModIntVector(D);
	vector<mint> u(n), b(n), res;
	randomModIntVector(u);
	randomModIntVector(b);

	vector<mint> uTAib(n * 2);
	uTAib[0] = dot(u, b);

	vector<mint> diag1(n);
	rep(i, n)
		diag1[i] = diag[i] + 1;

	vector<pair<short, short> > edges(validEdges.begin(), validEdges.end());

	for (int k = 1; k < n * 2; ++k) {
		res.assign(n, mint());
		rep(i, n)
			b[i] *= D[i];

		mint sumb;
		rep(i, n)
			sumb += b[i];

		if (src != -1) {
			if (dst < n && src < n)
				res[dst] -= b[src];
		}

		for (auto e : edges)
			res[e.first] += b[e.second];

		rep(i, n)
			res[i] += diag1[i] * b[i] - sumb;

		b.swap(res);
		uTAib[k] = dot(u, b);
	}

	computeMinimumPolynomialForLinearlyRecurrentSequence(uTAib, m);
	//運が悪い場合は気にしないことにする
	//m = char(AD)
	assert(m.size() == n + 1);
	assert(m.back() == mint(1));
	mint detD = 1;
	for (int i = 0; i < n; ++i)
		detD *= D[i];
	mint invdetD = detD.inverse();
	mint detA = m[0] * invdetD;
	if (n % 2 == 1)
		detA = mint() - detA;
	return detA;
}

mint countEulerianCyclesOnComplementGraph(int N, const vector<pair<int, int> > &edges, int src, int dst) {
	assert(N > 0);

	vector<int> loops(N, 1);
	vector<int> outDeg(N, N), inDeg(N, N);
	//サイクルにならない場合は辺を1つ足してサイクルにするようにする
	if (src != -1) {
		assert(src != dst);
		++outDeg[dst];
		++inDeg[src];
	}
	for (auto e : edges) {
		--outDeg[e.first];
		--inDeg[e.second];
		if (e.first == e.second)
			--loops[e.first];
	}

	rep(i, N)
		assert(inDeg[i] == outDeg[i]);

	//BEST theoremによりオイラー閉路を数えられる
	//<https://en.wikipedia.org/wiki/BEST_theorem>

	vector<mint> fact(N + 1);
	fact[0] = 1;
	rer(n, 1, N)
		fact[n] = fact[n - 1] * n;

	//matrix tree theorem によって有向木を数える
	//<https://en.wikipedia.org/wiki/Kirchhoff%27s_theorem#Kirchhoff.27s_theorem_for_directed_multigraphs>
	//頂点 N - 1 を根とする。
	//1行削除されるため、それに接する辺も一緒に削除しておく
	//また、ループも削除しておく
	vector<pair<int, int> > validEdges;
	for (auto e : edges) if (e.first < N - 1 && e.second < N - 1 && e.first != e.second)
		validEdges.push_back(e);
	//なんとなくソートしておく
	sort(validEdges.begin(), validEdges.end());
	//行列の対角要素
	vector<mint> diag(N - 1);
	rep(i, N - 1)
		diag[i] = outDeg[i] - loops[i];

	mint res = computeDeterminant(N, diag, validEdges, src, dst);

	rep(i, N) {
		int deg = outDeg[i];
		assert(deg > 0);
		res *= fact[deg - 1];
	}

	return res;
}

int main() {
	do {
		int N, M;
		scanf("%d%d", &N, &M);
		vector<vector<bool> > g(N, vector<bool>(N, true));
		vector<int> outDeg(N, N), inDeg(N, N);
		vector<pair<int, int> > edges(M);

		rep(i, M) {
			int A, B;
			scanf("%d%d", &A, &B), --A, --B;

			assert(g[A][B]);
			g[A][B] = false;
			edges[i] = { A, B };
			--outDeg[A];
			--inDeg[B];
		}

		//空グラフは場合分けしておく
		if (M == N * N) {
			puts("1");
			continue;
		}

		//ちなみに、ある補グラフ上でのDFSやBFSは線形時間で可能である
		UnionFind uf; uf.init(N);
		rep(i, N) rep(j, N) if (g[i][j])
			uf.unionSet(i, j);

		//まず、eulerianかどうか判定する
		int mainCC = -1;
		int src = -1, dst = -1;
		bool eulerian = true;
		rep(i, N) {
			if (outDeg[i] == inDeg[i]) {
			}
			else if (outDeg[i] == inDeg[i] + 1) {
				eulerian &= src == -1;
				src = i;
			}
			else if (outDeg[i] == inDeg[i] - 1) {
				eulerian &= dst == -1;
				dst = i;
			}
			else {
				eulerian = false;
			}
			if (mainCC == -1 && outDeg[i] > 0)
				mainCC = i;
		}
		assert(mainCC != -1);

		vector<int> vertices;
		rep(i, N) {
			if (outDeg[i] > 0 || inDeg[i] > 0)
				eulerian &= uf.findSet(mainCC, i);
		}

		if (src != -1 || dst != -1)
			eulerian &= src != -1 && dst != -1;

		if (!eulerian) {
			puts("0");
			continue;
		}

		//孤立点を取り除いたグラフを作る
		vector<int> vertexIndex(N, -1);
		int V = 0;
		rep(i, N)
			if (outDeg[i] > 0 || inDeg[i] > 0)
				vertexIndex[i] = V++;
		if (src != -1) {
			src = vertexIndex[src];
			dst = vertexIndex[dst];
			assert(src != -1 && dst != -1);
		}

		for (auto &e : edges) {
			e.first = vertexIndex[e.first];
			e.second = vertexIndex[e.second];
			if (e.first == -1 || e.second == -1)
				e = { -1, -1 };
		}
		edges.erase(remove(edges.begin(), edges.end(), make_pair(-1, -1)), edges.end());

		mint ans = countEulerianCyclesOnComplementGraph(V, edges, src, dst);
		//サイクルの場合、どの辺から始めるかの分をかける
		if (src == -1)
			ans *= N * N - M;

		printf("%d\n", ans);

	} while (0);
	return 0;
}
