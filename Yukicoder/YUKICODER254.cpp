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

/* -----  2018/08/27  Problem: yukicoder 254  / Link: http://yukicoder.me/problems/no/254  ----- */
/* ------問題------

正の整数 N が与えられる．以下の条件をすべて満たす文字列 S を 1 つ求めよ．

1≤|S|≤105
英小文字のみからなる．
どの隣り合う文字も相異なる．
回文であるような部分文字列がちょうど N 箇所に含まれる．

-----問題ここまで----- */
/* -----解説等-----

寿司ネタ出力したい！
- どの隣り合う文字も相異なる．

a{ba}^*を考えると、繰り返し回数^2ぐらいの部分回文を得ることができる。
|S|≦10^5なので、N≦10^9は容易に満たすことができる。
最大長を求めて、小さくしていけば良い。O(logNlogN)?

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	string ans = "";
	int charadd = 0;
	auto f = [](LL N) {
		return N*N;
	};
	auto binSearch = [&f](LL N) {
		int L = 1; int R = 100001;
		FOR(i, 0, 18) {
			LL mid = (L + R) / 2;
			if (N >= f(mid)) {
				L = mid;
			}
			else {
				R = mid;
			}
		}
		return L;
	};
	auto makeXYX = [](int x, int base) {
		string ret;
		char a = 'a' + base;
		char b = 'a' + base + 1;
		FOR(i, 0, x * 2 - 1) {
			if (i & 1)ret += string(1, b);
			else ret += string(1, a);
		}

		return ret;
	};
	while (N > 0) {
		LL sz = binSearch(N);
		N -= f(sz);
		// 長さがsz*2+1
		ans += makeXYX(sz, charadd);
		(charadd += 2) %= 26;
	}
	cout << ans << "\n";

	return 0;
}
