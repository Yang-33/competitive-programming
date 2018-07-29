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

/* -----  2018/07/28  Problem: yukicoder 178  / Link: http://yukicoder.me/problems/no/178  ----- */
/* ------問題------

太郎君は難解プログラミング言語であるWhitespaceでプログラムを作ることに熱中しています。
Whitespaceでは、スペース・タブ・改行のみを構文に使用し、その他は無視します。

太郎君はソースコードの美しさにこだわりがあり、ソースコードについて、すべての行の幅が等しい時に「完璧」と呼びます。
太郎君は自分の書いたWhitespaceのソースコードに全角スペースを挿入することで「完璧」にしようとしています。
太郎君がソースコードを「完璧」にするために必要な最小の全角スペースの数を求めるプログラムを作ってください。
ただし、ある行のスペースの数をa、タブの数をb、全角スペースの数をcとしたとき、その行の幅は(a+4b+2c)とします。
普通のエディタとは異なり、タブの位置などは幅に影響しません。

-----問題ここまで----- */
/* -----解説等-----

最大をチェックして全部それに合わせる。
また、偶奇もチェックする。

----解説ここまで---- */




int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI sum(N);
	int f = 1;
	LL sumOfsum = 0;
	LL Max = 0;
	FOR(i, 0, N) {
		int a, b; cin >> a >> b;
		sum[i] = a + 4 * b;
		sumOfsum += sum[i];
		Max = max(Max, (LL)sum[i]);
		if (i) {
			f &= (sum[0] % 2 == sum[i] % 2);
		}
	}

	if (f) {
		cout << (Max*N - sumOfsum) / 2 << endl;
	}
	else cout << -1 << endl;

	return 0;
}