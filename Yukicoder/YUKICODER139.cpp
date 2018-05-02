#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
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

/* -----  2018/05/02  Problem: yukicoder 139  / Link: http://yukicoder.me/problems/no/139  ----- */
/* ------問題------

yuki君は自宅から距離Lのところにある友人宅に遊びに行くことにした。
友人宅に着くには、間にあるN個の交差点を横断する必要がある。
i番目の交差点は、自宅から距離Xiの位置から始まり、幅がWiある。
すなわち、区間(Xi,Xi+Wi)は交差点である。

各交差点に設置された信号は、時間Tiごとに青信号と赤信号が交互に変化する。
なお、各交差点における信号はyuki君が出発すると同時に青信号になった。

yuki君は単位時間あたり距離1の速さでまっすぐ向かう。
ただし、yuki君は交差点手前の距離Xiに到着したとき、赤信号中に交差点内にいる可能性があるならば、その可能性がなくなるまで距離Xiの位置で待機する。

yuki君が自宅を出てから、友人宅に到着するまでにかかる経過時間を求めよ。

-----問題ここまで----- */
/* -----解説等-----

場合分けをする。
待つ必要があるかどうかを考えれば良い。

----解説ここまで---- */


LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, L;
	cin >> N >> L;
	VI x(N), w(N), t(N);
	FOR(i, 0, N) {
		cin >> x[i] >> w[i] >> t[i];
	}
	int time = 0;
	int pos = 0;
	FOR(i, 0, N) {
		int nx = x[i] - pos;
		time += nx;
		// 今赤なら待つ
		if (time % (2 * t[i]) >= t[i]) {
			time = (time + t[i]) / t[i] * t[i];
		}
		else if (t[i] - (time%t[i]) < w[i]) { // 渡る途中で赤なら超待つ
			time = (time + 2 * t[i]) / t[i] * t[i];
		}

		// 渡る
		time += w[i];
		pos = x[i] + w[i];
	}
	ans = time + L - pos;
	cout << ans << "\n";

	return 0;
}
