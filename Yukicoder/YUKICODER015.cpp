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

/* -----  2018/04/08  Problem: yukicoder 015  / Link: http://yukicoder.me/problems/no/015  ----- */
/* ------問題------

太郎君はカタログショッピングが大好き。

今日もカタログから商品を選んで購入したのだが、
太郎君はとてもお金持ちなので適当に商品を選んでしまい、
何を購入したかいつも忘れてしまいます。

幸い、クレジットカードの明細は手元にあるので、
購入した合計金額だけはわかりました。

太郎君が何を購入したのかを計算し、その商品番号を太郎君に教えてあげてください。
ただし、一つの商品を複数買うことはないものとします。

-----問題ここまで----- */
/* -----解説等-----

半分前列挙をやるだけ。
IDの出力が面倒で、辞書順最小とするためには2進数のbitを反転して管理する必要がある。
これ、a[i]をreverseするともっとやるだけっぽそう…

----解説ここまで---- */

LL N, S;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> S;
	VL a(N);

	FOR(i, 0, N) {
		cin >> a[i];
	}
	vector<PLL>v;
	int n1 = N / 2;
	FOR(i, 0, 1 << n1) {
		LL sum = 0;
		LL bit = 0;
		FOR(j, 0, n1) {
			if (i & (1 << j)) {
				sum += a[j];
				bit += 1LL << (N - j);
			}
		}
		v.push_back(PLL(sum, bit));
	}
	SORT(v);
	int n2 = N - n1;
	VL ans;
	FOR(i, 0, 1 << n2) {
		LL sum = 0;
		LL bit = 0;
		FOR(j, 0, n2) {
			if (i& (1 << j)) {
				sum += a[n1 + j];
				bit += 1 << (N - (n1 + j));
			}
		}

		auto x = lower_bound(ALL(v), PLL(S - sum, 0LL));
		auto y = lower_bound(ALL(v), PLL(S - sum, 1LL<<32));
		for (; x != y; x++) {
			if (x->first + sum == S) {
				ans.push_back(x->second | bit);
			}
		}
	}
	RSORT(ans);
	FOR(i, 0, SZ(ans)) {
		int out = 0;
		FOR(k, 0, N) {
			if (ans[i] & (1LL << (N-k))) {
				if (out)cout << " ";
				out = 1;
				cout << k + 1;
			}
		}
		if (out)cout << endl;
	}

	return 0;
}
