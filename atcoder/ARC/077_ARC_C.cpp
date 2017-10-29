#include "bits/stdc++.h"
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

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_h  / Link: http://arc077.contest.atcoder.jp/tasks/arc077_c  ----- */
/* ------問題------

snuke 君は明るさを m 段階に切り替えられる照明を買いに来ました。
この照明の 明るさは 1 以上 m 以下の整数で表され、 リモコンに付いた 2 種類のボタンで明るさを切り替えます。
1 つめのボタンは「順送り」ボタンで、 明るさを 1 増やすことができます。
ただし、ボタンを押す前の明るさが最大の m である場合には、 明るさは 1 になります。
2 つめのボタンは「お気に入り」ボタンで、 購入時に決めたお気に入りの明るさ x に切り替えることが出来ます。
snuke 君はお気に入りの明るさ x を、できるだけ効率的に明るさが切り替えられるように設定しようと考えました。
snuke 君は今後 n−1 回明るさを切り替える予定で、i 回目には明るさ ai から 明るさ ai+1 に切り替えようと計画しています。
最初、明るさは a1 です。 ボタンを押す回数の合計が最小になるようにお気に入りの明るさ x を決めた時の ボタンを押す回数を求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

こどふぉでみたよね！
うれしさが1,2,3,4みたいな三角形となっており、この短形和を区間に加算できれば良い。
これは1次元上の一次関数imos法を使えばいいことが分かる。(コンテスト中はできないと思っていた)
あとはこの嬉しさが最大値になっている部分を見つけ、a[i+1]-a[i]の総和から除けばよい。
printfでLLにしてなくてWAしないで！

----解説ここまで---- */




LL N, M;
LL ans = 0LL;
LL a[100005];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;

	FOR(i, 0, N) {
		cin >> a[i];
		a[i]--;
	}

	VL data(3 * M);
	ans = 0;
	FOR(i, 0, N - 1) {
		LL A = a[i], B = a[i + 1];
		if (B < A)B += M;
		ans += B - A;
		if (A + 1 < B) {
			data[A + 2] += 1;
			data[B + 1] += -(B + 1 - (A + 2) + 1);
			data[B + 2] += B + 1 - (A + 2);
		}
	}

	FOR(i, 0, SZ(data) - 1) {
		data[i + 1] += data[i];
	}
	LL maxc = -1;

	FOR(i, 0, SZ(data) - 1) {
		data[i + 1] += data[i];
	}
	FOR(i, 0, M) {
		data[i + M] += data[i];
	}

	//FOR(i, 0, SZ(data)) {
	//	cout << setw(3) << setfill('.') << data[i] << " ";
	//}
	//cout << endl;

	FOR(i, M, 2 * M)maxc = max(maxc, data[i]);

	printf("%lld\n", ans - maxc);

	return 0;
}