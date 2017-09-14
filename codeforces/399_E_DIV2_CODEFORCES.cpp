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

/* -----  2017/09/14  Problem: codeforces 399 div2 E Game of Stones  / Link: http://codeforces.com/contest/768/problem/E  ----- */
/* ------問題------

2人で行う複数の山の石取りゲームがある。
石の取り方は、各山について一度とった石の取り方はしてはいけない。
両者が最適にゲームを行った際に、後手は勝てるか。

-----問題ここまで----- */
/* -----解説等-----

sの制約が小さいのでbitmaskを考えればよい。
冷静にならずに状態をみると、60*2^60ほどあるが実際はそこまではいかず、各山のgrundy数を先に計算できる。
遅そうなら埋め込むというテクもある。(好き)

----解説ここまで---- */

ll N;
int s[1000006];
ll ans = 0LL;
map<ll, int>memo[61];
int f(int num, ll bit) { // num でbitを使用しているときのgrundy数
	if (num == 0)return 0;
	if (memo[num][bit] != 0)return memo[num][bit];
	int subg = 0;
	set<int>se;
	FOR(i, 1, num + 1) {
		if((bit & (1LL<<i))==0){
			se.insert(f(num - i, bit | (1LL << i)));
		}
	}
	while (se.count(subg))subg++;
	return memo[num][bit] = subg;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> s[i];
	}
	FOR(i, 1, 61) {
		f(i, 0);
	}
	int grundy = 0;
	FOR(i, 0, N) {
		grundy ^= memo[s[i]][0];
	}
	cout << ((grundy == 0) ? "YES" : "NO") << endl;

	return 0;
}
