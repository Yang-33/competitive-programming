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

/* -----  2017/07/08  Problem: AOJ 1602  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1602  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

構文解析。
先に演算子が来るのでこれを形にする(言葉にできない)

----解説ここまで---- */

ll N;
ll ans = 0LL;

int expr0(vector<string> &s, int &i) {
	int d = s[i].size();
	int n = s.size();
	char c = s[i][d - 1];
	if (c == '+') {
		int res = 0;
		i++;
		while (s[i].size() == d + 1 && i < n)
		{
			res += expr0(s, i);
		}
		return res;
	}
	else if (c == '*') {
		int res = 1;
		i++;
		while (s[i].size() == d + 1 && i < n)
		{
			res *= expr0(s, i);
		}
		return res;
	}
	else {
		i++;
		return c - '0';
	}
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> N;
		if (N == 0)break;
		vector<string>s(N+1);
		FOR(i, 0, N)cin >> s[i];
		int index = 0;
		ans = expr0(s, index);
		cout << ans << endl;
	}
	return 0;
}
