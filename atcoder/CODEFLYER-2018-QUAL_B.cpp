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

/* -----  2018/06/02  Problem: codeflyer-2018-qual B / Link: __CONTEST_URL__  ----- */
/* ------問題------

あなたは洋菓子店を経営しています。 本日はショートケーキを A 個、チーズケーキを B 個用意しました。

本日はこの洋菓子店を N 人の客が訪れることがわかっています。 また、それぞれの客のふるまいは、文字 S、C、E からなる長さ N の文字列 X を用いて以下のように表されます。

X の i 文字目が S の場合、i 番目に来る客はショートケーキを 1 個買う。ただし、到着した時点でショートケーキがすでに売り切れている場合は何も買わない。
X の i 文字目が C の場合、i 番目に来る客はチーズケーキを 1 個買う。ただし、到着した時点でチーズケーキがすでに売り切れている場合は何も買わない。
X の i 文字目が E の場合、i 番目に来る客はショートケーキとチーズケーキのうち到着した時点で多く残っている方を 1 個買う。 ただし、両方がすでに売り切れている場合は何も買わない。また、両方が 1 以上の同じ数ずつ残っている場合はショートケーキを 1 個買う。
すべての客が帰ったあと、ショートケーキおよびチーズケーキはそれぞれいくつ残っているでしょうか。

-----問題ここまで----- */
/* -----解説等-----

問題文を理解できなかった。
場合分け

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A, B, N;
	string s;

	cin >> A >> B >> N;
	cin >> s;

	FOR(i, 0, SZ(s)) {
		if (A&&s[i] == 'S') {
			A--;
		}
		if (B&&s[i] == 'C') {
			B--;
		}
		if (s[i] == 'E') {
			if (A >= B&&A) {
				A--;
			}
			else if (A< B && B) {
				B--;
			}
		}
	}

	cout << A << endl;
	cout << B << "\n";

	return 0;
}