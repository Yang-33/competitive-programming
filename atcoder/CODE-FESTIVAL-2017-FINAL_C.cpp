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

/* -----  2018/03/03  Problem: code-festival-2017-final_c / Link: https://cf17-final.contest.atcoder.jp/tasks/cf17_final_c?lang=en  ----- */
/* ------問題------

XXXX年のCODE FESTIVALには、世界中から高橋君を含めて N+1 人の参加者が集まりました。
高橋君の都市と他の N 人の都市の時刻の差を調べてみたところ、i 番目の人の都市との時刻の差は Di 時間でした。 ただし 2 つの都市について、片方の都市で 0 時の瞬間にもう一方の都市で d 時であるようなとき、これらの都市の時刻の差は min(d,24−d) であるものとします。 ここで、時刻の表記には 24 時間表記を用いるものとします。 つまり、例えば高橋君の都市で 0 時の瞬間には i 番目の人の都市は Di 時または 24−Di 時のいずれかとなります。
高橋君は次に、N+1 人のうちの全ての 2 人組についてその人の都市どうしの時刻の差を書き出し、それらの時刻の差のうちの最小値を s としました。
s として考えられる最大値を求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

時間について愚直にシュミレション？
3人以上同じ時間にあるときはans = 0
2人のときはバラバラに分け、1人のときは両方試すのが良い
2^24ぐらい

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	VI cnt(13, 0);

	FOR(i, 0, N) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	cnt[0]++;
	FOR(i, 0, 13) {
		if (cnt[i] > 2) {
			cout << 0 << endl;
			return 0;
		}
	}

	if (cnt[0] > 1 || cnt[12] > 1) {
		cout << 0 << endl;
		return 0;
	}
	VI base(24, false);
	base[0] = true;
	if (cnt[12] == 1) {
		base[12] = true;
	}
	FOR(i, 0, 13) {
		if (cnt[i] == 2) {
			base[i] = base[24 - i] = true;
		}
	}
	ans = 0;
	FOR(i, 0, (1 << 11)) {
		VI used(48,0);
		FOR(i, 0, 24) {
			used[i] = base[i];
		}
		FOR(j, 0, 11) {
			if (cnt[j + 1] != 1) continue;
			if ((i >> j) & 1) {
				used[j + 1] = true;
			}
			else {
				used[24 - (j + 1)] = true;
			}
		}
		FOR(j, 0, 24) used[j + 24] = used[j];
		int l = 0;
		int tans = INF;
		FOR(r, 1, 48) {// 2周
			if (used[r]) {
				int t = min(r - l, 24 - (r - l));
				tans = min(tans, t);
				l = r;
			}
		}
		ans = max(ans, (LL)tans);
	}
	cout << ans << endl;


	return 0;
}
