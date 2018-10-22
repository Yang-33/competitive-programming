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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DEBUG(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/10/22  Problem: SPOJ DQUERY / Link: https://www.spoj.com/problems/DQUERY  ----- */
/* ------問題------

数列Aがあり、クエリがQ回与えられる。
Q: A[i:j]に含まれる数列のuniqueな個数は？

-----問題ここまで----- */
/* -----解説等-----

解法は2つ。
オフライン：クエリの右端をソートして、a[i]の最後に現れる位置を移していけば区間和だけで解ける。
オンライン：クエリソートができないので永続segtreeでrをキーにしてやる。

----解説ここまで---- */

template<typename type>
struct BIT { // 0-index
	int N;
	vector<type> data;
	BIT(int n) : N(n), data(n + 1, 0) {}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x < N; x |= x + 1) {
			data[x] += w;
		}
	}
	type sum(int i) { // a[0] +...+ a[i-1] !!! [0,i)
		type ret = 0;
		for (int x = i - 1; x >= 0; x = (x&(x + 1)) - 1) {
			ret += data[x];
		}
		return ret;
	}
	type sum(int l, int r) { //a[l]+...+a[r-1] !!! [l,r)
		return sum(r) - sum(l);
	}
};

int a[30004];
int ans[200005];
int lastPos[1000006];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%d", &a[i]);
	}
	int Q; scanf("%d", &Q);
	vector<vector<PII>>Querys(N);
	FOR(i, 0, Q) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--, r--;
		Querys[r].push_back(PII(l,i));
	}
	fill(lastPos, lastPos + 1000006, -1);
	BIT<int>bit(N);
	FOR(i, 0, N) {
		if (lastPos[a[i]] != -1) {
			bit.add(lastPos[a[i]], -1);
		}
		lastPos[a[i]] = i;
		bit.add(i, 1);
		for (PII L : Querys[i]) {
			ans[L.second] = bit.sum(L.first, i + 1);
		}
	}
	FOR(i, 0, Q) {
		printf("%d\n", ans[i]);
	}

	return 0;
}
