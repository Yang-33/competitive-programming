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

/* -----  2017/08/09  Problem: 41_csacademy C  / Link: https://csacademy.com/contest/round-41/tasks/  ----- */
/* ------問題------

未確定なサイズ2^Nの完全二分木があるとする。この上でいわゆるレートじゃんけんを行う。
このとき、K番の番号を振られた人がM回勝つためにはどのようなノードの順であればいいか。
不可能な場合は-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

完全二分木を作る際に、Kさんが勝つためには自分に近い点には2^M-1人必要である。
・これが作成可能か
・K==2^NのときはM==Nしか不可能（必ず勝ってしまうので）
をかくにんして、あとは答えを適当に出力すればよい。

----解説ここまで---- */

ll N,K,M;

ll ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>K>>M;
	int pe = pow(2, N);
	int a = 0; 
	while (1) {
		if (pow(2, a) <= K&&K < pow(2, a + 1))break;
		else a++;
	}
	if (a<M||(K==(int)pow(2,N)&&M!=N)) {
		cout << -1 << endl;
		return 0;
	}
	cout << K << " ";
	int cnt = 0;
	FOR(i, 0, pow(2, M) - 1) {
		cout << i + 1 << " ";
		cnt++;
	}

	while (cnt < pow(2, N)) {
		cnt++;
		if (pe == K) { pe--; continue; }
		cout << pe << " "; pe--;
	}

	cout << endl;
	return 0;
}
