#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/08  Problem: codefestival2017_qual A  / Link: http://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_a  ----- */
/* ------問題------

りんごさんは、とある祭りに参加しようとしています。
その祭りの名称が FESTIVAL で終わる文字列 S として入力に与えられるので、りんごさんが何の祭りに参加しようしているのかを出力して下さい。
ただし、s の祭りの名称は s の末尾に FESTIVAL を 1 つだけ追加した文字列であるとします。 例えば CODEFESTIVAL は CODE の祭りです。

-----問題ここまで----- */
/* -----解説等-----

最後の文字はfestivalらしいので8文字削ればよい。
pythonの方がはやそう。print (s[:-8])

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	
	cin >> s;
	string p;
	FOR(i, 0,int(s.size()) - 8) {
		p += s[i];
	}

	cout << p << endl;

	return 0;
}
