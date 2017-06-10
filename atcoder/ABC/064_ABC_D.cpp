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

/* -----  2017/06/10  Problem: ABC 064 D / Link: http://abc064.contest.atcoder.jp/tasks/abc064_d  ----- */
/* ------問題------

( と ) で構成される N 文字の文字列 S が与えられる。S にいくつかの ( または ) を挿入することで正しい括弧列を作りたい。
ただし、正しい括弧列は次のように定義されている：

() は正しい括弧列である。
X が正しい括弧列であるとき、(、X、) をこの順につなげたものは正しい括弧列である。
X、Y が正しい括弧列であるとき、X と Y をこの順につなげたものは正しい括弧列である。
それ以外の括弧列は正しくない。
そのとき、作れる最も文字数が少ない正しい括弧列を求めなさい。このようなものが複数ある場合は、辞書順最小のものを求めなさい。

-----問題ここまで----- */
/* -----解説等-----

辞書順最小だけど、括弧の対応を考えれば1通りしかない。
したがって完璧な括弧を作ればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string S;

	cin >> N;
	cin >> S;
	int cnt1 = 0;
	int cnt2 = 0;
	int f = 0;
	stack<char>s1;
	stack<char>s2;
	FOR(i, 0, S.size()) {
		if (S[i] == '(') {
			s1.push(')');
		}
		else if (S[i] == ')') {
			if (s1.size() >= 1)s1.pop();
			else s2.push('(');
		}


	}
	int x = s2.size();
	FOR(i, 0, x) {
		cout << '(';
	}
	cout << S;
	
	 x = s1.size();
	FOR(i, 0, x) {
		cout << ')';
	}
	cout << endl;

	return 0;
}
