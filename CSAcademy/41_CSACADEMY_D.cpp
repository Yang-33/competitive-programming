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

/* -----  2017/08/09  Problem: 41_csacademy D  / Link: https://csacademy.com/contest/round-41/tasks/  ----- */
/* ------問題------

N頂点のグラフをBFS,DFSで訪問した順の情報がそれぞれ与えられる。
N頂点M辺のグラフとして復元し、出力せよ。
もしこのようなグラフが存在しないときは-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

ずるいけど、BFSの巡回順は1からすべての辺を張ったとしてもよい。
DFSはBFSでつくった頂点と辺に対して、DFSは移動の前後の点をつなげばよい。
辺は重複してはいけないので、最初の辺だけ1度張るとして N-1 + ((N-1)-1) = 2N-3 辺はればよい。

->想定解だった　ウケる

----解説ここまで---- */

ll N;
int b[5000];
int d[5000];
ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	if (N == 1) {
		cout << 0 << endl;
		return 0;
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	FOR(i, 0, N) {
		cin >> d[i];
	}

	if (b[1] != d[1]) {
		cout << -1 << endl;
		return 0;
	}
	cout << 2 * N - 3 << endl;;
	FOR(i, 1, N) {
		cout << 1 << " " << b[i] << endl;
	}
	FOR(i, 1, N - 1) {
		cout << d[i] <<" "<< d[i + 1] << endl;
	}

	return 0;
}
