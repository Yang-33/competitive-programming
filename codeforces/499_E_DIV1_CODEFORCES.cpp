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
#define DD(x) 
#endif

/* -----  2018/11/14  Problem: 499_E_div1_codeforces / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

2Dクエリに帰着可能。

----解説ここまで---- */


const int INF = 1 << 30;
const int SIZE = 1000;
//const int SIZE = 100002;
int main() {
	int S[3], N, M, K;
	int X[SIZE][3];
	int A[SIZE][3];
	int x[SIZE][3];
	scanf("%d %d %d %d %d %d", &S[0], &S[1], &S[2], &N, &M, &K);
	for (int i = 0; i < N; i++) scanf("%d %d %d", &X[i][0], &X[i][1], &X[i][2]);
	for (int i = 0; i < M; i++) scanf("%d %d %d", &A[i][0], &A[i][1], &A[i][2]);

	vector< pair< int, int > > mx(3);
	for (int i = 0; i < 3; i++) mx[i] = { S[i], 1 };
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 3; j++) mx[j].first = min(mx[j].first, X[i][j]);
		for (int j = 0; j < 3; j++) mx[j].second = max(mx[j].second, X[i][j]);
	}
	for (int i = 0; i < M; i++) {
		bool f = true;
		for (int j = 0; j < 3; j++) {
			f &= mx[j].first <= A[i][j] && A[i][j] <= mx[j].second;
		}
		if (f) {
			cout << "INCORRECT\n";
			return 0;
		}
	}


	vector< pair< pair< pair< int, int >, pair< int, int > >, int > > add[SIZE];
	vector< pair< pair< pair< int, int >, pair< int, int > >, int > > del[SIZE];

	for (int i = 0; i < K; i++) {
		scanf("%d %d %d", &x[i][0], &x[i][1], &x[i][2]);
		vector< pair< int, int > > mz(mx);
		for (int j = 0; j < 3; j++) mz[j].first = min(mz[j].first, x[i][j]);
		for (int j = 0; j < 3; j++) mz[j].second = max(mz[j].second, x[i][j]);
		add[mz[0].first].emplace_back(make_pair(mz[1], mz[2]), i);
		del[mz[0].second + 1].emplace_back(make_pair(mz[1], mz[2]), i);
	}

	using BIT = BinaryIndexedTree< int >;
	auto f = [](int x, int y) { return x + y; };
	auto g = [](BIT &k, int x, int y) { return k.sum(y - 1) - k.sum(x - 1); };
	auto h = [](BIT &k, int x, int y) { k.add(x, y); };

	SegmentTree2DCompressed< BIT, int, int > seg(SIZE, f, g, h, 0);// ref:lib/datastructure/segmenttree2Dcompressed

	vector< pair< int, int > > point[SIZE];
	for (int i = 0; i < M; i++) {
		seg.preupdate(A[i][1], A[i][2]);
		point[A[i][0]].emplace_back(A[i][1], A[i][2]);
	}

	seg.build();
	vector< int > sum(K);
	for (int i = 0; i < SIZE; i++) {
		for (auto &p : del[i]) sum[p.second] -= seg.query(p.first.first.first, p.first.first.second + 1, p.first.second.first, p.first.second.second + 1);
		for (auto &p : add[i]) sum[p.second] += seg.query(p.first.first.first, p.first.first.second + 1, p.first.second.first, p.first.second.second + 1);
		for (auto &p : point[i]) seg.update(p.first, p.second, 1);
	}

	puts("CORRECT");
	for (int i = 0; i < K; i++) {
		if (sum[i] != 0) {
			puts("CLOSED");
		}
		else {
			bool f = true;
			for (int j = 0; j < 3; j++) {
				f &= mx[j].first <= x[i][j] && x[i][j] <= mx[j].second;
			}
			if (f) puts("OPEN");
			else puts("UNKNOWN");
		}
	}
}