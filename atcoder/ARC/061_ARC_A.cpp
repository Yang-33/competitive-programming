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

/* -----  2018/02/14  Problem: 061_arc_a / Link: https://arc060.contest.atcoder.jp/tasks/arc060_a?lang=en  ----- */
/* ------問題------

1 以上 9 以下の数字のみからなる文字列 S が与えられます。 この文字列の中で、あなたはこれら文字と文字の間のうち、いくつかの場所に + を入れることができます。
一つも入れなくてもかまいません。 ただし、+ が連続してはいけません。
このようにして出来る全ての文字列を数式とみなし、和を計算することができます。
ありうる全ての数式の値を計算し、その合計を出力してください。

-----問題ここまで----- */
/* -----解説等-----

全探索！これ昔出来なかった

----解説ここまで---- */

LL N,K;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;
	VI a(SZ(S));
	FOR(i, 0, SZ(S)) {
		a[i] = S[i] - '0';
	}
	FOR(bit, 0, 1 << (SZ(S)-1)) {
		LL sum = 0;
		LL ret = a[0];
		FOR(i, 1, SZ(a)) {
			if (bit&(1 << (i-1))) {
				sum += ret;
				ret = a[i];
			}
			else ret = 10 * ret + a[i];
		}
		sum += ret;
		ans += sum;
	}

	cout << ans << "\n";

	return 0;
}
