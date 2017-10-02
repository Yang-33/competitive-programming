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

/* -----  2017/10/02  Problem: CS academy 33 C / Link:  https://csacademy.com/contest/round-33/task/div-3/solution/ ----- */
/* ------問題------

Xが与えられる。
X--
X++
if(X%3==0)X=X/3
最小の手順で1にするとき、何手で1になるか。

-----問題ここまで----- */
/* -----解説等-----

実験してそれをあてはめます

----解説ここまで---- */

ll N;
int Greedy(int x) {
	if (x == 2) {
		return 1;
	}
	else if (x == 1) {
		return 0;
	}

	if (x % 3 == 0) {
		return 1 + Greedy(x / 3);
	}
	else if (x % 3 == 1) {
		return 1 + Greedy(x - 1);
	}
	else {
		return 1 + Greedy(x + 1);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cout << Greedy(N) << endl;
	return 0;
}
