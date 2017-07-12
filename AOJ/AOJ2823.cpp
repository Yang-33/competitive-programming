#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/07/12  Problem: AOJ 2823  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2823  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

各難易度の問題について、推薦度が高いものを更新していけばよい。

----解説ここまで---- */


int x[120];
int y[120];
int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	int N, M;
	while (1) {
		FOR(i, 0, 120)x[i] = y[i] = 0;
		cin >> N >> M;
		if (N == 0 && M == 0)break;
		FOR(i, 0, N) {
			int a, b;
			cin >> a >> b;
			x[a]++;
			if (y[a] < b)y[a] = b;
		}
		int ans = 0;
		FOR(i, 1, M + 1) {
			if (x[i])ans += y[i];
		}
		cout << ans << endl;
	}
}