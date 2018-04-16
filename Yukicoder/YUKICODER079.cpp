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

/* -----  2018/04/16  Problem: yukicoder 079  / Link: http://yukicoder.me/problems/no/079  ----- */
/* ------問題------

競技プログラミングの出題サイト yurucoder では問題ごとにレベルが設定されています。

問題のレベルはユーザーからアンケートを取り以下のルールで決められます。
N人のユーザーは問題のレベルをそれぞれ Li として評価する。 (1≤i≤N)
多数決を取り、最もユーザーからの回答が多いレベルをその問題のレベルとする。
最も多い回答を得たものが複数ある場合は、よりレベルの高い方を採用する。

このルールに従い、ユーザーから得た評価から問題のレベルを求めてください。

-----問題ここまで----- */
/* -----解説等-----

PIIのmax.minでやると楽

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI L(7, 0);
	FOR(i, 0, N) {
		int a; cin >> a;
		L[a]++;
	}
	PII Max = PII(-1, -1);
	FOR(i, 1, 7) {
		Max = max(Max, PII(L[i],i));
	}
	ans = Max.second;
	cout << ans << "\n";

	return 0;
}
