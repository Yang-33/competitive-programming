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

/* -----  2018/03/02  Problem: 002_agc_c / Link: https://agc002.contest.atcoder.jp/tasks/agc002_c?lang=en  ----- */
/* ------問題------

N 本のロープがあります。 ロープは 1 から N まで番号が振られています。 ロープ i の長さは ai です。
最初、1≤i≤N−1 について、ロープ i の右端とロープ i+1 の左端が結ばれています。 高橋君は次の操作を N−1 回行い、すべての結び目をほどこうとしています。
ひと繋がりのロープのうち、長さの総和が L 以上のものをひとつ選ぶ。 選んだひと繋がりのロープに結び目があれば、結び目のうちどれかひとつをほどく。
高橋君は結び目をほどく順番を工夫し、すべての結び目をほどくことができるでしょうか？ 可能か判定し、可能ならば結び目をほどく順番をひとつ求めてください。

-----問題ここまで----- */
/* -----解説等-----

ケツに着目すると、L以上のものがつながっていないといけない。
逆にこれが繋がっているときはどう切ってもいいので、Lの周りをはしから削除していく。

----解説ここまで---- */

LL N, L;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> L;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	LL pos = -1;
	FOR(i, 0, N - 1) {
		if (a[i] + a[i + 1] >= L) {
			pos = i;
		}
	}
	if (pos == -1) {
		cout << "Impossible" << endl;
	}
	else {
		cout << "Possible" << endl;
		VI ans(N - 1);
		FOR(i, 0, pos) {
			cout << i + 1 << " ";
		}
		FORR(i, N - 1, pos) {
			cout << i << " ";

		}cout << endl;
	}

	return 0;
}
