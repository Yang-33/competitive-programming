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

/* -----  2018/07/30  Problem: yukicoder 184  / Link: http://yukicoder.me/problems/no/184  ----- */
/* ------問題------

頭脳派おたくのkamipeipaa君は勉強を続けています。kamipeipaa君は復習を欠かしません。今日は以下の問題を解いています。

N個のスイッチを発見した。i番目のスイッチにはAiという整数が書かれている。あなたはi番目のスイッチを押すことで、ある整数Xに対して
X=X⊕Ai
という操作を行うことができる。ただし⊕とはビットXORの記号である(参考)。
一度押したスイッチは二度と使用することはできない。
Xははじめ0である。
あなたが作ることができる整数は何種類あるか。

kamipeipaa君はこの問題の制約を厳しくしても解くことができることに気づいたので解くことにしました。あなたも解いてあげてください。

-----問題ここまで----- */
/* -----解説等-----

xor操作はmod2とも見れる。(ゲームでよくやった。)
行列とみれれば簡単で、独立な行の数を求めれば良い。

----解説ここまで---- */


typedef unsigned long long ull;
vector<ull> getrank(vector<ull> v, int B) {// B:= digit
	int n = v.size();
	vector<ull> t(B, 0);
	int used = 0;
	for (int j = B - 1; j >= 0; j--) {
		int i = used;
		while (i < n && (~v[i] >> j & 1)) i++;
		if (i < n) {
			ull x = v[i];
			swap(v[i], v[used++]);
			t[j] = x;
			for (i = used; i < n; i++)
				if (v[i] >> j & 1)
					v[i] ^= x;
		}
	}
	return t;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	vector<ull> a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	auto vec = getrank(a, 62);

	int zeros = count(ALL(vec), 0);
	ull ans = 1ULL << (SZ(vec) - zeros);
	cout << ans << "\n";

	return 0;
}
