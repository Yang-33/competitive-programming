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

/* -----  2018/03/02  Problem: 010_agc_b / Link: https://agc010.contest.atcoder.jp/tasks/agc010_b?lang=en  ----- */
/* ------問題------

N 個の箱が円環状に並んでおり、i 番目の箱には Ai 個の石が入っています。
以下の操作を繰り返して、全ての石を取り除くことができるか判定してください。
箱を一か所選ぶ。それを i 番目としたとき、1 から N の各 j に対して、i+j 番目の箱から石をちょうど j 個取り除く。
ただし、N+k 番目と表される箱は k 番目の箱と同一視するものとする。
各操作において、取り除きたい個数の石がない箱があるときは、その操作を行えないことに注意してください。

-----問題ここまで----- */
/* -----解説等-----

わからないので悲しくなって階差をとると、数字に規則性を感じる。
階差を取ることで得られる情報として、数列を生成するごとに+1がn-1回、-Nが1回加算される。
このことからこれが成り立っているかを確認すれば良い。
条件は”階差数列の値が数列を生成するのに必要な回数以下、かつ先の関係が成立している”

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(2 * N);
	LL sum = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		a[i + N] = a[i];
		sum += a[i];
	}

	ans = 1;
	LL k = sum / (N*(N + 1) / 2);

	if (k*(N*(N + 1) / 2) != sum)ans = 0;

	FOR(i, 0, N) {
		int diff = a[i + 1] - a[i];
		if (k - diff < 0 || ((k - diff) % N != 0))ans = 0;
	}
	if (ans) {
		cout << "YES" << endl;
	}
	else
		cout << "NO" << "\n";

	return 0;
}
