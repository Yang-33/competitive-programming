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

/* -----  2018/07/28  Problem: yukicoder 180  / Link: http://yukicoder.me/problems/no/180  ----- */
/* ------問題------

Whitespaceでは、スペース・タブ・改行のみを構文に使用し、その他は無視します。

太郎君はソースコードに全角スペースを混ぜていましたが、次郎君はそれだとインタプリタによってはエラーになることに気が付きました。
次郎君はN行からなるソースコードを書きました。i行目にはスペースがai個、タブがbi個含まれます。ソースコードにスペース・タブ・改行以外の文字は含まれません。

次郎君はエディターのタブ幅x(xは正の整数)を変えることによって、ソースコードの「醜さ」を最小にしようとしています。
ソースコードの「醜さ」は、ソースコードの行の幅の最大値から最小値を引いたものです。
より正確に言うと、タブ幅x(xは正の整数)に対して、「醜さ」f(x)は次の式で与えられます。
f(x)=(max1≤i≤N(ai+bix))−(min1≤i≤N(ai+bix))
普通のエディタとは異なり、タブの位置などは幅に影響せず、スペースとタブそれぞれの個数のみから「醜さ」が決まることに注意してください。

ソースコードの「醜さ」f(x)を最小にする正の整数xのうち、最も小さいものを出力するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

下に凸なので三分探索できる。
境界がアレなので近傍を探索をすれば良い。
CHTがあればO(NlogN+log^2N)とかでも解ける。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VL a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i] >> b[i];
	}
	auto f = [&](LL x) {
		LL M = LLONG_MIN, m = LLONG_MAX;
		FOR(i, 0, N) {
			LL ret = a[i]+b[i]*x;
			M = max(M, ret);
			m = min(m, ret);
		}
		return M - m;
	};
	LL L = 0,  R = INF;
	FOR(i, 0, 100) {
		LL m1 = (2 * L + R) / 3, m2 = (L + 2 * R) / 3;

		if (f(m1) <= f(m2)) {
			R = m2;
		}
		else {
			L = m1;
		}
	}

	LL sub = 1e18;
	int ans;
	FOR(x, max(1LL,L - 5), max(1LL,L + 5)) {
		LL ret = f(x);
		if (ret < sub) {
			sub = ret;
			ans = x;
		}
	}
	cout << ans << "\n";

	return 0;
}
