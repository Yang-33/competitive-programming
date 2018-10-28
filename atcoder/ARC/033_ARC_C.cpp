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

/* -----  2018/10/27  Problem: ARC 033 C / Link: http://arc033.contest.atcoder.jp/tasks/arc033_c  ----- */
/* ------問題------

数の集合 S に対する以下のクエリを処理してください。
タイプ 1 ： S に数 X を追加する。
タイプ 2 ： S に含まれる数のうち X 番目に小さい数を答え、その数を S から削除する。


-----問題ここまで----- */
/* -----解説等-----

setでkthがわかればよい。

----解説ここまで---- */

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

	int lower_bound(type w) {
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k <= N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x;
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	BIT0<int> bit(2e5 + 5);
	FOR(_, 0, N) {
		int t, x; cin >> t >> x;
		if (t == 1) {
			bit.add(x, 1);
		}
		else {
			int idx = bit.lower_bound(x);
			cout << idx << endl;
			bit.add(idx, -1);
		}
	}

	return 0;
}
