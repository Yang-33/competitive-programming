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
int dx[8] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[8] = {1, -1, 0, 0, 1, -1, 1, -1};

/* -----  2017/04/30  Problem:  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


void solve(int _T) {
	double ans = 1;
	int N, K; cin >> N >> K;
	double U; cin >> U;
	double p[55];
	FOR(i, 0, N) {
		cin >> p[i];
	}
	sort(p, p + 55);
	if (N == K) {
		//最小をなくしてならす
		double minp = p[0];
		double min2 = 1;
		int cnt = 1;
		FOR(i, 0, N) {
			if()
		}
	}
	else {
		//1-(k未満のものしか起動しない)がこたえなので　dp,最大を１にもってくgreedyでやる
	}
	cout << "Case #" << _T << ": " << ans << endl;
}

int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int __T;
  cin >> __T;
  FOR(i, 0, __T) {
	  solve(i + 1);
  }

  return 0;
}
