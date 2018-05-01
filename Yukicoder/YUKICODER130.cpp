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

/* -----  2018/04/26  Problem: yukicoder 130  / Link: http://yukicoder.me/problems/no/130  ----- */
/* ------問題------

非負整数列 a1 , a2 , … , aN が与えられる。
あなたは適当な非負整数 x を選び、a1⊕x , a2⊕x , … , aN⊕x の最大値を最小化したい。
ただし、⊕ はビット XOR の記号である。
最小化した最大値を答えよ。

-----問題ここまで----- */
/* -----解説等-----

末尾まで結果がわからないので、状況に応じて再帰を書く。
ある上位桁について、bitが全部同じであればその桁は0にできるが、
そうでない場合は必ず1になる。
あとは下位集合から最小値を持ってこれば良い。
これを最下位まで下ってから繰り返す。

これ分割統治っていうんですね

----解説ここまで---- */

LL N;

LL ans = 0LL;


int f(int pos, VI& a) {
	if (pos < 0)return 0;
	VI a0, a1;
	FOR(i, 0, SZ(a)) {
		if (a[i] & 1 << pos) {
			a1.push_back(a[i]);
		}
		else {
			a0.push_back(a[i]);
		}
	}

	if (!SZ(a0)) {
		return f(pos - 1, a1);
	}
	else if (!SZ(a1)) {
		return f(pos - 1, a0);
	}
	else {
		return (1 << pos) + min(f(pos-1,a0), f(pos-1,a1));
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	ans = f(31, a);

	cout << ans << "\n";

	return 0;
}
