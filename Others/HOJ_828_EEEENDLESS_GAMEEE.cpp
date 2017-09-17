#include "bits/stdc++.h"
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

/* -----  2017/09/17  Problem: HOJ_828_eeeendless_gameee  / Link: https://hoj.hamako-ths.ed.jp/onlinejudge/problems/828  ----- */
/* ------問題------

N個の石の山があります
 山にはそれぞれAi個の石があります
 石を交互に取っていきましょう ただし、Aiの山から、
 Aiの最小の素因数pについて、p個より多く取ってはだめ
 K個より多く取ってはだめ
神通力でゲーム開始直後に後手は最初にある山を１つだけコピーして増やすことが可能

-----問題ここまで----- */
/* -----解説等-----

連続区間なので、0に近い側からgrundy数の登場したindexの最大値を保持してそれをにぶたんすればよい
cf.ARC038 C 104点解放
神通力は使うかを選択できるので、盤面のgrundy数から各石のgrundy数を全部取るか試して0になるものが存在するかを確認してみればよい。

----解説ここまで---- */


struct SegTree {
	using type = int; 	type INIT_VAL = INT_MAX; type merge(type a, type b) { return min(a, b); } int N; vector<type> dat;
	SegTree(int _N) { N = 1;	while (N < _N)N *= 2; dat = vector<type>(N * 2 - 1, INIT_VAL); }
	void update(int k, type val) { k += N - 1; dat[k] = val;	while (k) { k = (k - 1) / 2; dat[k] = merge(dat[k * 2 + 1], dat[k * 2 + 2]); } }
	type query(int a, int b, int k, int l, int r) {
		if (r <= a || b <= l)return INIT_VAL; if (a <= l&&b >= r)return dat[k];
		type v1 = query(a, b, k * 2 + 1, l, (l + r) / 2); type v2 = query(a, b, k * 2 + 2, (l + r) / 2, r);	return merge(v1, v2);
	}
	inline type query(int a, int b) { return query(a, b, 0, 0, N); }
};

#define primeN 1000000 //78493個
bool prime[primeN + 1];// 外部だとハッシュ表みたいになる
void make_prime() {
	FOR(i, 0, primeN + 1) { prime[i] = 1; }
	prime[0] = prime[1] = 0;

	for (int i = 2; i <= primeN; i++) {
		if (prime[i])
			for (int j = i * 2; j <= primeN; j += i) prime[j] = 0;
	}
#undef primeN 
}

LL N, K;
int a[100005];
int G[1000006];
int maxp[1000006];
LL ans = 0LL;

void pre() {
	make_prime();//素数表作成
	//maxp(i)の作成
	FOR(i, 0, 1000006)maxp[i] = -1;
	maxp[1] = 1;
	FOR(i, 2, 1000006) {
		if (prime[i]) {
			for (int j = i; j < 1000006; j += i) {
				if (maxp[j] == -1)
					maxp[j] = i;
			}
		}
	}
	//////////
	SegTree seg(1000006);
	FOR(i, 0, 1000006) {
		seg.update(i, -1);
	}
	seg.update(0, 0);
	G[0] = 0;
	//小さい方からセグ木にぶたん

	FOR(i, 1, 1000001) {
		int width = min((int)K, maxp[i]);
		int k = max(0, i - width);
		int y = 0;
		FORR(j, 20, -1) {
			if (seg.query(0, y + (1 << j)) >= k) {
				y += 1 << j;
			}
		}
		G[i] = y;
		seg.update(y, i);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;


	//前処理,seg+にぶたん

	pre();
	FOR(i, 0, N) {
		cin >> a[i];
	}
	int g = 0;
	FOR(i, 0, N) {
		g ^= G[a[i]];
	}
	ans = 1;
	if (g == 0)ans = 0;

	FOR(i, 0, N) {
		if ((g^G[a[i]]) == 0)ans = 0;
	}

	string First = "ESCAPE";
	string Second = "CAUGHT";

	cout << ((ans != 0) ? First : Second) << "\n";


	return 0;
}
