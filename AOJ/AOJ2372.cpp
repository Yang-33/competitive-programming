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

/* -----  2017/12/06  Problem: AOJ 2372 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2372  ----- */
/* ------問題------

数直線上の整数座標に, ねこの Taro の家, にんじん, うさぎの Hanako の家がこの順に並んでいる. 点 xx にいるイカは, 一回のジャンプで x+1x+1 または x+2x+2 に移動することができる.
あなたは, イカが Taro の家から Hanako の家までにんじんの置かれている座標に止まらずに行く経路が何通りあるか求めようとしたが, Taro の家, にんじん, Hanako の家の座標を知らないので 求めることができなかった. そこで, 代わりに経路の数として考えられる数をすべて列挙することにした.
ある Taro の家, にんじん, Hanako の家の配置に対してイカの経路数となる整数をイカ数と呼ぶことにする. KK 番目に小さいイカ数 (1-indexed) を mod 1,000,000,007 で求めよ.

-----問題ここまで----- */
/* -----解説等-----

証明が全くわからず、†実験†でごめんなさい感がある
fib(a)*fib(b)のうち、最小のものから見つけていきたい。
積の表を見ると、謎の単調性から、上三角の部分は右斜したにかけて部分を塊としてみると、
塊ごとは単調増加であるといえる。
したがって、だいたいK番目がどのへんにあるかが二分探索で求められる・
1/2*(n)*(n+1) *2 < K
各右斜したの列を考えると、一番上から、一つ飛ばしで移動するごとに値が大きくな定期、折り返すときは
上に上がるとごとに増加していく。
あとはこれの番号を上手に実現すれば、表の番号が求まる。

----解説ここまで---- */



//a*B
template<typename T>
vector<vector<T>> mul(vector<vector<T>> A, vector<vector<T>> B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			FOR(j, 0, (int)B[0].size()) {
				C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j])) % MOD;
			}
		}
	}
	return C;
}

//a^N べき乗法 logN
template<typename T>
vector<vector<T>> pow(vector<vector<T>> A, long long n) {
	vector<vector<T>> B((int)A.size(), vector<T>((int)A.size()));
	FOR(i, 0, (int)A.size()) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n & 1) B = mul<T>(B, A);
		A = mul<T>(A, A);
		n >>= 1;
	}
	return B;
}

LL matfib(LL n) { // fast fib(n), f(0)=1 f(1)=1 f(2)=2
	using vec = VL;
	using mat = vector<vec>;

	mat A(2, vec(2, 0));
	A[0][0] = 1;
	A[0][1] = 1;
	A[1][0] = 1;
	A[1][1] = 0;

	mat res(2, vec(1, 0));
	res[0][0] = 1;
	res[1][0] = 0;
	mat ans = mul<LL>(pow<LL>(A, n), res);
	return ans[0][0];
}


LL N;

LL ans = 0LL;

//LL m[1000];
//LL fibs(int n) {
//	if (m[n] > 0)return m[n];
//
//	return m[n] = fibs(n - 1) + fibs(n - 2);
//}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	//m[0] = 1;
	//m[1] = 1;
	//m[2] = 2;

	//FOR(i, 1, 15) {
	//	FOR(j, 1, 15) {
	//		if (j < i)cout << "      ";
	//		else cout << setw(5) << setfill(' ') << fibs(i)*fibs(j) << " ";
	//	}cout << endl; cout << endl;
	//}


	LL K;
	cin >> K;
	LL L = 0; LL R = 1e10;
	FOR(i, 0, 50) {
		LL mid = (L + R) / 2;
		if (mid*(mid + 1) < K)L = mid;
		else R = mid;
	}
	LL KK = K;
	K -= L*(L + 1);

	// 10^5 列が2つ
	LL a, b;
	LL w = 2 * (L + 1);
	if (K > (L + 1)) {
		K -= (L + 1);
		w = 2 * (L + 1) + 1;
	}
	// 斜めのライン番号と残りの数はわかるので、番号を探す
	LL halfup = ((L + 1) + 1) / 2; //左へ
	//debug(halfup);
	if (K <= halfup) {
		a = 2 * K - 1;
		//if (((L+1)%2==0)&&(halfup == K))a--;
		b = w - a;//右の番号
	}
	else {
		K -= halfup;
		//debug(K);
		a = ((L + 1) % 2 == 0 ? L + 1 : L) - 2 * (K - 1);
		b = w - a;
	}
	//	debug(a);
		//debug(b);
	cout << matfib(a)*matfib(b) % MOD << endl;

	return 0;
}
