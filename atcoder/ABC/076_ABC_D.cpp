#include <bits/stdc++.h>
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

/* -----  2018/02/15  Problem: 076_abc_d / Link: https://abc076.contest.atcoder.jp/tasks/abc076_d?lang=en ----- */
/* ------問題------

2168年、AtCoder 社は成長し、ついに "AtCoder特急" という鉄道を建設することを決めた。
さて、社長の高橋君は、"AtCoder特急" の列車を以下のように運行することを計画した。
列車の走行時間は、(t1+t2+t3+…+tN) 秒である。
最初の t1 秒間は、列車は速度 v1 m/s 以内で走っていなければならない。また、次の t2 秒間は、列車は速度 v2 m/s 以内で走っていなければならない。 次の t3 秒間、またそれ以降についても同様である。
最後の tN 秒間は、列車は速度 vN m/s 以内で走っていなければならない。
ただし、列車の性能上、加速度は ±1m⁄s2 以内でなければならない。また、走行開始時と走行終了時には列車は止まっていなければならない。

列車が発車してから停車するまでに走れる最大の距離を求めなさい。

-----問題ここまで----- */
/* -----解説等-----

傾きが1なので三角形と2つの台形が見えればこれはO(N)で適当にできる。

----解説ここまで---- */

LL N;

double ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI t(N);
	vector<double> v(N);
	vector<double> mx(N + 1, 0);
	FOR(i, 0, N) {
		cin >> t[i];
	}
	double now = 0;
	FOR(i, 0, N) {
		cin >> v[i];
		now = min(now + t[i], v[i]);
		mx[i + 1] = now;
	}
	mx[N] = 0;
	now = 0;
	FORR(i, N - 1, 0 - 1) {
		now = min(now + t[i], v[i]);
		mx[i] = min(mx[i], now);
	}

	FOR(i, 0, N) {
		double top = max(mx[i], mx[i + 1]) + (double)(t[i] - abs(mx[i] - mx[i + 1]) ) / 2.0;
		double S = (mx[i] + top)*(top - mx[i]) / 2.0 + (mx[i + 1] + top)*(top - mx[i + 1]) / 2.0;
		if (top < v[i])ans += S;
		else {
			ans += S;
			ans -= (top - v[i])*(top - v[i]);
		}
	}


	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
