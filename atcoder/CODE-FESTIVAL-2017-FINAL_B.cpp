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

/* -----  2018/02/24  Problem: code-festival-2017-final_b / Link: https://cf17-final.contest.atcoder.jp/tasks/cf17_final_b?lang=en  ----- */
/* ------問題------

すぬけ君は a、b、c の 3 種類の文字のみからなる文字列 S を持っています。
回文恐怖症のすぬけ君は S の文字を自由に並び替えて、2 文字以上の回文を部分文字列として含まないようにしようと思いました。 これが可能かどうかを判定して下さい。

-----問題ここまで----- */
/* -----解説等-----

順番はなんでもいいけどabcabcabc...しかつくれない。
したがってアルファベットのそれぞれの個数についてMax-Min<=1のみ作成可能
あとはつくれない

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s;
	cin >> s;

	VI a(3, 0);
	FOR(i, 0, SZ(s)) {
		a[s[i] - 'a']++;
	}
	int m = INF;
	int M =- INF;
	FOR(i, 0, 3) {
		M = max(M, a[i]);
		m = min(m, a[i]);
	}
	if (M - m < 2) {
		cout << "YES" << endl;
	}
	else cout << "NO" << endl;

	return 0;
}
