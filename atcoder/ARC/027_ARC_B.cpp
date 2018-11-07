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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/07  Problem: ARC 027 B / Link: http://arc027.contest.atcoder.jp/tasks/arc027_b  ----- */
/* ------問題------

私は 10 進数のある正の整数を覚えておくように言われました。その数字は N 桁で、先頭の数字は 0 ではないです。
大事な数なのでメモ帳に 2 回書きました。
ところで私は文字を書くのが下手です。
後でメモ帳を読み返すと、メモ帳に書いた数字のうちいくつかについて、元はどの数字だったかわからなくなってしまいました。
元の数字がわからない文字は最大 26 文字で、以下では A から Z までの大文字アルファベットで表すことにします。これらの文字は、元は 0 から 9 までの 1 桁の数字のいずれかです。
メモ帳に書いた文字には、同じアルファベットが複数出てくるかもしれません。同じアルファベットが複数回出てきた場合、それらのアルファベットについてはいずれも元は同じ数字となります。1 回目に書いた文字列と 2 回目に書いた文字列に共通して登場するアルファベットが存在する場合もありますが、その場合でも、それらのアルファベットについて元は同じ数字となります。また、異なる種類のアルファベットの元の数字が同じ数字である場合も考えられます。
例えば、メモ帳の 1 回目の文字列が 1XYX であった場合、覚えておくように言われた数字としては 1101(X=1,Y=0) や 1111(X=1,Y=1), 1848(X=8,Y=4) などが考えれますが、一方で例えば 1132(Y=3) は X に対する元の数字が 1 と 2 の複数種類存在するので、覚えておくように言われた数字としては考えられません。
メモ帳に書いた 2 つの文字列が与えられるので、覚えておくように言われた数字として全部で何通り考えられるかを求めるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

コメントの通り。
UFでキレイにrootに情報を伝播させると楽。

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
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	string s1, s2;
	cin >> s1 >> s2;
	// A..Zは未定　先頭に0はおけない X=Yは可能
	const int sz = 256;
	UnionFind uf(sz);
	// 同じ文字はつないで、同じ位置もつなぐ
	// 数字とつないだ際にはなにかフラグを持っておく
	FOR(i, 0, N) {// pos
		FOR(j, 0, N) {
			if (s1[i] == s2[j] && isalpha(s1[i])) {
				uf.unionSet(i, N + j);
			}
		}
	}
	FOR(i, 0, N) {
		FOR(j, i + 1, N) {
			if (s1[i] == s1[j])uf.unionSet(i, j);
			if (s2[i] == s2[j])uf.unionSet(i + N, j + N);
		}
	}
	// 記号位置
	FOR(i, 0, N) {
		uf.unionSet(i, N + i);
	}

	VI numFlag(sz);
	FOR(i, 0, N) {
		if (isalpha(s1[i]) && isdigit(s2[i])) {
			numFlag[uf.root(i)] = 1;
		}
		else if (isalpha(s2[i]) && isdigit(s1[i])) {
			numFlag[uf.root(i + N)] = 1;
		}
	}
	// 両方とも数字ではないときにcal
	ans = 1;
	FOR(i, 0, N) {
		if (isalpha(s1[i]) || isalpha(s2[i])) {
			if (uf.root(i) == i || uf.root(i + N) == i + N) {
				if (i) {
					if (numFlag[i] || numFlag[N + i]) {
						ans *= 1;
					}
					else {
						ans *= 10;
					}
				}
				else {
					if (numFlag[i] || numFlag[N + i]) {
						ans = 1;
					}
					else {
						ans *= 9;
					}
				}
			}
		}
	}


	cout << ans << "\n";

	return 0;
}