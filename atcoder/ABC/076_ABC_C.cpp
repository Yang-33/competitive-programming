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

/* -----  2018/02/14  Problem: 076_abc_c / Link: https://abc076.contest.atcoder.jp/tasks/abc076_c?lang=en  ----- */
/* ------問題------


E869120 は、宝物が入ってそうな箱を見つけました。
しかし、これには鍵がかかっており、鍵を開けるためには英小文字からなる文字列 S が必要です。
彼は文字列 S' を見つけ、これは文字列 S の 0 個以上 |S| 個以内の文字が '?' に置き換わった文字列であることも分かりました。
ただし、文字列 A に対して、|A| を「文字列 A の長さ」とします。
そこで、E869120 はヒントとなる紙を見つけました。
•条件1：文字列 S の中に連続する部分文字列として英小文字から成る文字列 T が含まれている。
•条件2：S は、条件1を満たす文字列の中で辞書順最小の文字列である。
そのとき、鍵となる文字列 S を出力しなさい。
ただし、そのような文字列 S が存在しない場合は代わりに 'UNRESTORABLE' と出力しなさい。

-----問題ここまで----- */
/* -----解説等-----

全部列挙できるので列挙して最も小さいものを選択すれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string T; cin >> T;
	string S; cin >> S;
	vector<string>vs;
	FOR(i, 0, SZ(T) - SZ(S)+1) {
		int ok = 1;
		FOR(j, 0, SZ(S)) {
			if (T[i + j] == '?'||S[j] == T[i + j]) {
				;
			}
			else {
				ok = 0;
			}
		}
		if (ok) {
			string a = T.substr(0,i)+S+ T.substr(i+SZ(S));
			FOR(i, 0, SZ(T))if (a[i] == '?')a[i] = 'a';
			vs.push_back(a);
		}
	}

	if (SZ(vs) == 0) {
		cout << "UNRESTORABLE" << endl;
	}
	else SORT(vs),cout << vs[0] << "\n";

	return 0;
}
