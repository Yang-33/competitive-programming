#include "bits/stdc++.h"
#include <unordered_set>
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

/* -----  2017/06/09  Problem: CSAcademy 32 C / Link: https://csacademy.com/contest/round-32/task/subarray-partition/  ----- */
/* ------問題------

長さN(≦10^5)の数列が与えられる。
これを部分数列の中にある数字のなかのすべての数字について、他の同じ数字が同じ部分数列の中にある
数列の分割の最大個数を求めよ。

-----問題ここまで----- */
/* -----解説等-----

英語力がなさ過ぎて問題文が読めなかった。めっちゃ簡単だった。
英語読みましょうね～

同じ数字の末尾の位置を保存しておき、ある数字を見たときの末尾を区間内の数字について現在の末尾の数字よりもさらに後ろにあるときは
見る部分を延ばしていく。伸ばしきったらそこが条件を満たす区間になるのでこれの個数を数える。尺取り？

----解説ここまで---- */

ll N;
ll a[100010];
ll fin[100010];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N)cin >> a[i];
	
	FOR(i, 0, N) {
		fin[a[i]] = i;
	}

	int i;
	for (i = 0; i < N;i++) {
		ans++;
		ll mx = fin[a[i]];
		ll j = i;
		while (j < mx) {
			mx = max(mx, fin[a[j]]);
			j++;
		}
		i = j;
		//debug(j);
	}



	cout << ans << endl;

	return 0;
}
