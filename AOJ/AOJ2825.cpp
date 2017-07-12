#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;
/* -----  2017/07/12  Problem: AOJ 2825  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2825  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

本番では少し相談してキムが書いた。
ある人の取得可能な点数について、最小のものはある問題に対してこの人のみが解答するものの和、
最大のものは複数人解答可能なものをすべてこの人が正解したときであることが入力から分かる。
したがってある人が最少得点をとるときにそれ以外の人が最大得点をとる際の差を求め、逆転優勝できるような点の最小値をとればよい。

----解説ここまで---- */

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, M;
	while (cin >> N >> M) {
		if (N == 0 && M == 0)break;
		vector<ll> d(N + 1, 0), t(N + 1, 0);
		for (int i = 0; i < M; i++) {
			int S, k; cin >> S >> k;
			if (k == 1) {
				int c; cin >> c;
				d[c] += S;
			}
			else {
				int c;
				for (int j = 0; j < k; j++) {
					cin >> c;
					t[c] += S;
				}
			}
		}

		ll Ans = -1;

		for (int i = 1; i <= N; i++) {
			ll Min = INF;
			for (int j = 1; j <= N; j++) {
				if (i == j) continue;
				Min = min(Min, d[j]);
			}
			Ans = max(Ans, (d[i] + t[i]) - Min + 1);
		}
		cout << Ans << endl;
	}
}