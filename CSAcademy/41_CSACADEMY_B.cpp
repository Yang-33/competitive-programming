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

/* -----  2017/08/09  Problem: 41_csacademy B  / Link: https://csacademy.com/contest/round-41/tasks/  ----- */
/* ------問題------

一直線上に並んだ椅子に人が座ったり座ってなかったりしている。
1人だけの席を変えたときに最大何個連続している場所ができるか。

-----問題ここまで----- */
/* -----解説等-----

1をひとつとばした次の1の位置をみてその間以外に1を置くことができればこれを答えの候補に入れてもよい。
そうでない場合には端に寄せるだけ。
そもそも動かしても意味がない場合があるので、解の候補に３点選んだ際の二つの区間もかいにふくめればよい。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	int a[100005];
	FOR(i, 0, 100005)a[i] = 0;
	int cnt = 0;
	vector<int >v;

	FOR(i, 0, 100004) {
		int c = 0;
		if (i < s.size() && s[i] == '0')cnt++, c = 1;
		else if (i < s.size() && s[i] == '1') v.push_back(i + 1);

		a[i + 1] = a[i] + c;
	}

	ans = 1;
	int n = v.size();
	v.push_back(0);
	v.push_back(s.size() + 1);
	sort(v.begin(), v.end());

	FOR(i, 0, n) {
		ans = max((int)ans, a[v[i + 1]] - a[v[i]]);
		ans = max((int)ans, a[v[i + 2]] - a[v[i + 1]]);
		if (a[v[i + 2]] - a[v[i]] != cnt)ans = max((int)ans, a[v[i + 2]] - a[v[i]] + 1);
		else ans = max((int)ans, a[v[i + 2]] - a[v[i]]);
	}
	cout << ans << endl;

	return 0;
}
