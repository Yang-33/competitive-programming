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

/* -----  2018/05/01  Problem: AOJ 2606 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2606  ----- */
/* ------問題------

{1, 2, … , N}の順列 (p(1), p(2), … , p(n)) が与えられる． (li, ri) からなるクエリが Q 個与えられるので，各クエリに対して以下の擬似コードによる処理結果を出力せよ．

ret := 0, (x(1), x(2), … , x(N)) := (1, 2, … , N) とおく．
各i ∈{1, 2, … , N} について y(i):=p(x(i)) とする．
各i ∈{1, 2, … , N} について x(i) = y(i)とする．
ret := ret+x(li)+x(li+1)+… +x(ri)
もし (x(li), x(li+1), … , x(ri))=(li, li+1, … , ri) なら (ret mod109+7) を出力して終了する．そうでないなら 2 行目に戻る．

-----問題ここまで----- */
/* -----解説等-----

置換をする
もとに戻るまでは各要素の置換の回数のLCM回繰り返す
区間lcmはsegtreeでできる。
履歴は残さなくても良いので簡単
よって各要素ごとの和みたいなのが欲しくなる
lcmの性質から、sum.lcmを組みとしたnodeはmergeできる。
よってセグ木にこれらをのせればおしまい。

----解説ここまで---- */




long long  gcd(long long  a, long long  b) { return b ? gcd(b, a%b) : a; }
long long  LCM(long long  a, long long  b) { return a / gcd(a, b) * b; }

long long modpow(long long a, long long b) {
	if (b == 0) return 1;
	return modpow(a * a % MOD, b / 2) * (b & 1 ? a : 1) % MOD;
}
long long modinv(long long a) { return modpow(a, MOD - 2); }


struct Node {
	LL lcm, sum;
	Node(LL l = 1, LL s = 0) :lcm(l), sum(s) {}
};

Node INIT_VAL = Node(); // 影響のない値すなわち単位元

struct SegTree {
	inline Node merge(Node a, Node b) { //台数構造
		Node ret;
		ret.lcm = LCM(a.lcm, b.lcm);
		ret.sum = ((a.sum)*((ret.lcm / a.lcm) % MOD )%MOD+ (b.sum)*((ret.lcm / b.lcm) % MOD)%MOD) % MOD;
		(ret.sum += MOD) %= MOD;
		return ret; //merge部分
	}
	//-----setting-----//
	int N;	vector<Node> dat;

	SegTree(int _N) {
		N = 1;
		while (N < _N)N *= 2;
		dat = vector<Node>(N * 2 - 1, INIT_VAL);
		//dat.resize(N * 2 - 1, INT_MAX);
		// max値を入れておく、書き換えupdasteはいいが加算addに注意
	}

	~SegTree() { vector<Node>().swap(dat); }

	void build() { for (int i = N - 2; i >= 0; i--) dat[i] = merge(dat[2 * i + 1], dat[2 * i + 2]); }

	void update(int k, Node val) {
		k += N - 1;
		dat[k] = val;
		while (k) { // 根まで再帰的に上る
			k = (k - 1) / 2;
			dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]); // merge
		}
	}
	// 区間[a,b)の評価
	Node query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return INIT_VAL; // 区間が被らない 
		if (a <= l&&b >= r)return dat[k]; // 値を返す
		Node v1 = query(a, b, k * 2 + 1, l, (l + r) / 2);
		Node v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);
		return merge(v1, v2); //merge
	}

	inline Node query(int a, int b) {
		return query(a, b, 0, 0, N);
	}
};





LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, Q; cin >> N >> Q;
	VI p(N+1);
	VI pc(N + 1);
	VL sum(N + 1);
	FOR(i, 1, N + 1) {
		cin >> p[i];
	}
	FOR(i, 1, N+1) {
		int integer = i;
		int cnt = 1;
		sum[i] += integer;
		while (p[integer] != i) {
			cnt++;
			integer = p[integer];
			sum[i] += integer;
		}
		pc[i] = cnt;
	}

	SegTree seg(N+1);
	FOR(i, 1, N+1) {
		Node val = Node(pc[i],sum[i]%MOD );
		seg.update(i, val);
	}

	FOR(i, 0, Q) {
		int l, r;
		cin >> l >> r; //[l,r]
		Node res = seg.query(l, r + 1);
		ans = res.sum;
		cout << ans << "\n";
	}

	return 0;
}
