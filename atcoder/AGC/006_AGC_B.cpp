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

/* -----  2018/02/24  Problem: 006_agc_b / Link: https://agc006.contest.atcoder.jp/tasks/agc006_b?lang=en  ----- */
/* ------問題------

N 段のピラミッドがあります。 段は上から順に 1, 2, …, N と番号が振られています。 各 1≤i≤N について、i 段目には 2i−1 個のブロックが横一列に並んでいます。 また、各段の中央のブロックに注目すると、これらは縦一列に並んでいます。
すぬけ君は N 段目のブロックに (1, 2, …, 2N−1) を並べ替えたもの（順列）を書き込みました。 さらに、次のルールに従い、残りすべてのブロックに整数を書き込みました。
あるブロックに書き込まれる整数は、そのブロックの左下、真下、右下のブロックに書き込まれた整数の中央値である。
その後、すぬけ君はすべてのブロックに書き込まれた整数を消してしまいました。 すぬけ君は、1 段目のブロックに書き込まれた整数が x であったことだけを覚えています。
N 段目のブロックに書き込まれた順列としてあり得るものが存在するか判定し、存在するならばひとつ求めてください。

-----問題ここまで----- */
/* -----解説等-----

Xが2回連続する部分を作り出せればよい。1indexでX-1,X番目にXをつくる。
これによって頂点はXとなる。
これにはXを最下部の中央にしこれの周りをMin,Maxで囲めば良い。
また正当性はN>=5で成り立つことを示せればよい。
書くとわかる。(は？)

----解説ここまで---- */

LL N, X;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> X;

	if (X == 1 || X == 2 * N - 1) {
		cout << "No" << endl;
	}
	else {
		cout << "Yes" << endl;
		VI a(2 * N - 1);
		FOR(i, 0, SZ(a))a[i] = i + 1;
		swap(a[N - 1], a[X - 1]);
		swap(a[0], a[N - 2]);
		swap(a[2 * N-2], a[N]);

		FOR(i, 0, SZ(a)) {
			cout << a[i] << endl;
		}

	}
	return 0;
}
