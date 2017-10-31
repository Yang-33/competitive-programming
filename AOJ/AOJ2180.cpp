#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/30  Problem: NU23 G / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2180  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

たくさん水があればよいので二分探索をすればいいことは明らか。
これは(l,r]でやる。
毎日定量で続けても問題ないときは、この値は次の日に影響を与えないものとなっているはずである。したがって
二分探索内では二日分のチェックを行い、この差が微小であるかを確認すればよい。
そうでないときはいづれ水不足になるのでこれをfalseとすればよい。
550？ってみんないってた

----解説ここまで---- */

LL N;
bool check(double& left, double in, VI &s, VI &t, VI &u, LL L) {
	int now = 0;
	FOR(i, 0, N) {
		left = min((double)L, left + (s[i] - now)*in);
		left = min((double)L, left + (t[i] - s[i])*(in - u[i]));
		if (left < 0) return false;//あってくれ
		now = t[i];
	}
	left = min((double)L, left + (86400 - now)*in);
	return true;
}


bool f(double x, VI &s, VI &t, VI &u,LL L) {// 単位時間当たりの量がxでよいか?
	double left = L;
	if (check(left, x,s,t,u,L) == false)return 0;
	double left_c = left;
	if (check(left, x, s, t, u, L) == false)return 0;
	if (abs(left - left_c) < 1e-6)return 1; 
	else return 0;
}

void solve(VI &s, VI &t, VI &u, LL L) {
	double ans = 0LL;

	double l = 0;
	double r = 1e6;
	FOR(i, 0, 80) {
		double mid = (l + r) / 2;
		if (f(mid, s, t, u,L))r = mid;
		else l = mid;
	}
	ans = r;
	cout << fixed << setprecision(10) << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	LL L;
	while (cin >> N >> L) {
		if (N == 0 && L == 0)break;
		VI s(N), t(N), u(N);
		FOR(i, 0, N) {
			cin >> s[i] >> t[i] >> u[i];
		}
		solve(s, t, u, L);
	}

	return 0;
}
