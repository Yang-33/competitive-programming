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

/* -----  2017/10/07  Problem: DDCC2017_qual C  / Link:  http://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_c ----- */
/* ------問題------

N 本の棒があり、 i(1≦i≦N) 本目の棒の長さは Li です。
これらを長さ C のケースに収納していきます。
ケースには 1 本か 2 本の棒を収納できますが、棒を収納できる条件は
1 本の棒を収納するには、棒の長さが a のとき、 a≦C
2 本の棒を収納するには、棒の長さが a,b のとき、 a+b+1≦C
です。
全ての棒を収納するのに、ケースは最小でいくつ必要か答えてください。

-----問題ここまで----- */
/* -----解説等-----

最悪N個使うとみて、いい感じのペアができれば一つ削減していく感じにする。
にらむとこれは両端から貪欲にやっていけばいいことが分かるので
ならべてしゃくとりっぽくやればよい

----解説ここまで---- */

ll N, C;
ll L[100005];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> C;

	FOR(i, 0, N) {
		cin >> L[i];
	}
	sort(L, L + N);
	cout << endl;
	ans = N;
	int j = N - 1;
	int i = 0;
	while (i < j) {
		if (i >= j)break;
		if (L[i] + L[j] + 1 <= C) {
			ans -= 1;
			j--;
			i++;
		}
		else {
			j--;
		}

	}


	cout << ans << endl;

	return 0;
}
