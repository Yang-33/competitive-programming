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

/* -----  2018/05/03  Problem: yukicoder 150  / Link: http://yukicoder.me/problems/no/150  ----- */
/* ------問題------

ある文字列がT個与えられる。i+1(1≤i≤T)行目には文字列Siが与えられる
文字列Siの先頭から検索していったとき、 goodという部分文字列が見つかり、かつ、それ以降にproblemという部分文字列が見つかったとき、文字列Siは良問であるという。
全く見つからなかった場合は、文字列Siは良問ではない。

あなたは文字列Siの内の任意の場所の1文字を’a’～’z’のいずれかに書き換えるという操作を繰り返し行う。
文字列Siを良問にするまでに必要な操作の回数の最小値をKiとする。Kiをi行目に出力せよ。

-----問題ここまで----- */
/* -----解説等-----

数字が小さいので適当にできる。(添字を適当にやったのでできなかった)  
なんとなくO(T|S|log|S|)にしたけど、後ろからやればlogもつかない。

----解説ここまで---- */

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string GOOD = "good";
	string PROBLEM = "problem";
	FOR(i, 0, N) {
		string s; cin >> s;
		VI good(SZ(s), INF);
		VI problem(SZ(s), INF);
		int ans = 11;
		FOR(j, 0, SZ(s) - 10) {
			int ret = 0;
			FOR(k, 0, 4) {
				ret += (s[j + k] != GOOD[k]);
				
			}
			good[j] = ret;
		}
		set<PII>se;
		FOR(j, 4, SZ(s)-6) {
			int ret = 0;
			FOR(k, 0, 7) {
				ret += (s[j + k] != PROBLEM[k]);
			}
			problem[j] = ret;
			se.insert(PII(ret, j));
		}
		FOR(j, 0, SZ(s) - 10) {
			ans = min(ans,good[j] + se.begin()->first );
			se.erase(PII(problem[j+4],j+4));
		}
		cout << ans << "\n";
	}

	return 0;
}
