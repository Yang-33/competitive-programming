#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int (i) = (s) ;(i) < (e) ;(i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/06/27  Problem: ICPC‘“à—\‘I2010 C / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1165&lang=jp  ----- */
/* ------–â‘è------

‚Ý‚Ä

-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----

Šï”‚Ì‚à‚Ì‚Æ‘S‘Ì‚Ìdp‚ð‚·‚ê‚Î‚æ‚¢B

----‰ðà‚±‚±‚Ü‚Å---- */
ll dp[3000100];
ll dp2[3000100];
ll a[200];

int main() {
	cin.tie(0); ios::sync_with_stdio(false);

	FOR(i, 1, 200) {
		a[i] = i*(i + 1)*(i + 2) / 6;
	}
	FOR(i, 0, 1000100)dp[i]=dp2[i] = LINF;
	dp[0] = dp2[0] = 0;
	FOR(i, 1, 200) {
		FOR(j, 0, 1000100) {
			if (a[i] + j >= 1000100)continue;
			dp[a[i] + j] = min(dp[a[i] + j], dp[j] + 1);
			if (a[i] % 2 == 1) {
				dp2[a[i] + j] = min(dp2[a[i] + j], dp2[j] + 1);
			}
		}
	}

	while (1) {
		int N; cin >> N;
		if (N == 0)break;
		cout << dp[N] << " " << dp2[N] << endl;
	}
	return 0;
}