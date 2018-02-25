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

/* -----  2018/02/27  Problem: dwango-challenge-2018-final_a / Link: __CONTEST_URL__  ----- */
/* ------問題------

太郎君と次郎君はアナログ時計が好きです。 太郎君と次郎君が持っているアナログ時計は普通のアナログ時計と同じように 秒針が1分で1周し、分針が1時間で1周し、時針が12時間で1周します。 また、秒針、分針、時針はなめらかに一定の角速度で動き、12時0分0秒ちょうどに全ての針が重なります。

太郎君は突然眠くなり、ちょうど H:M:S (H 時 M 分 S 秒) に眠りについてしまいました。 その後、目が覚めたとき、次郎君から以下の情報を聞きました。

眠っている間にアナログ時計の分針と秒針が重なった回数が C1 回だった
眠っている間にアナログ時計の時針と分針が重なった回数が C2 回だった
太郎君が眠っていた時間はちょうど整数秒間だった
太郎君が眠りについた時刻・目が覚めた時刻に、アナログ時計の分針と秒針は重なっていない
太郎君が眠りについた時刻・目が覚めた時刻に、アナログ時計の時針と分針は重なっていない
これらの情報から、太郎君が眠っていた時間の最小秒数 t1 と最大秒数 t2 を出力してください。 そのような範囲が存在しない場合は −1 を出力してください。

-----問題ここまで----- */
/* -----解説等-----

適当倍してシュミレーション

----解説ここまで---- */




struct Time {
	static const int mod = 60 * 60 * 12;
	int h, m, s;

	void step() {
		(s += 60 * 12) %= mod;
		(m += 12) %= mod;
		(h += 1) %= mod;
	}
	int bet_h_m() { // H -> m  / cc
		int diff = m - h;
		if (diff < 0) diff += 60 * 60 * 12;
		return diff;
	}
	int bet_m_s() { // m -> s  / cc
		int diff = s - m;
		if (diff < 0) diff += 60 * 60 * 12;
		return diff;
	}
};

int main() {


	int H, M, S; cin >> H >> M >> S;
	int C1, C2; cin >> C1 >> C2;

	H %= 12;

	// とりあえず現在時刻まで進める
	Time time{ 0, 0, 0 };
	for (int i = 0; i < H * 60 * 60 + M * 60 + S; i++) {
		time.step();
	}

	int min_t = INF;
	int max_t = -INF;

	int c1 = 0;
	int c2 = 0;
	int t = 0;
	while (!(c1 > C1 || c2 > C2)) {
		Time nx = time;
		nx.step();
		if (nx.bet_m_s() < time.bet_m_s()) c1++;
		if (nx.bet_h_m() < time.bet_h_m()) c2++;
		t++;
		time = nx;
		if (c1 == C1 && c2 == C2 &&
			time.bet_m_s() != 0 &&
			time.bet_h_m() != 0) {
			min_t = min(min_t, t);
			max_t = max(max_t, t);
		}
	}

	if (min_t == INF)
		cout << -1 << endl;
	else {
		cout << min_t << " " << max_t << endl;
	}

	return 0;
}