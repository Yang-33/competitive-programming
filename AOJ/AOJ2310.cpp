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

/* -----  2018/06/24  Problem: AOJ 2310 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2310  ----- */
/* ------問題------

薔薇園の魔女 GERTRUD は幅 W メートル，高さ H メートルの長方形の庭でバラを育てている．庭は一辺 1 メートルの正方形で区切られており，W×H のブロックに分けられている．各ブロックはバラが育てられているか育てられていないかのどちらかである．
ただ驚くべきことに，この庭で育てられているバラはブロックを越えて絡み合い 1 つの生命体となっている．この生命体は辺を共有しているブロック間を越えて絡み合うことができ，どこかある 1 点を共有していれば同じ生命体となる．
巴マミは庭の左下の角から直線に必殺技「ティロ・フィナーレ」で巨大な銃を撃ち，その弾丸が通る直線上でその生命体を分割した時，生命体が出来る限り多くの分割数に分断されるようにすることによりダメージを与えたい．ティロ・フィナーレは最大でこの生物を何分割できるか求めよ．

-----問題ここまで----- */
/* -----解説等-----

答えを見た。
line-sweep的に考える。
イベント点は領域の増加、減少になる。
片側から線を動かしていくときに、増えるパターンと減るパターンを検索していく。
最後にこのイベント点を角度でソートすればシュミレーションできる。

発想が厳しい…

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL H, W; cin >> H >> W;

	VS vs(H + 2);
	vs[0] = string(W + 2, '.');
	vs[H + 1] = string(W + 2, '.');
	FOR(i, 1, H + 1) {
		cin >> vs[i];
		vs[i] = "." + vs[i] + ".";
	}

	W += 2, H += 2;
	using tp = tuple<int, int, int>;
	vector<tp> events;
	FOR(i, 0, H - 1) {
		FOR(j, 0, W - 1) {
			// ##
			// #.
			if (vs[i][j] == '#'&&vs[i][j + 1] == '#'&&vs[i + 1][j] == '#'&&vs[i + 1][j + 1] == '.') {
				events.push_back(tp(j, H - 2 - i, 1));
			}
			// ..
			// .#
			if (vs[i][j] == '.'&&vs[i][j + 1] == '.'&&vs[i + 1][j] == '.'&&vs[i + 1][j + 1] == '#') { // inc
				events.push_back(tp(j, H - 2 - i, 1));
			}
			// .#
			// ##
			if (vs[i][j] == '.'&&vs[i][j + 1] == '#'&&vs[i + 1][j] == '#'&&vs[i + 1][j + 1] == '#') { // dec
				events.push_back(tp(j, H - 2 - i, 0));
			}
			// #.
			// ..
			if (vs[i][j] == '#'&&vs[i][j + 1] == '.'&&vs[i + 1][j] == '.'&&vs[i + 1][j + 1] == '.') { // dec
				events.push_back(tp(j, H - 2 - i, 0));
			}
		}
	}
	sort(ALL(events), [](const tp& a, const tp& b) {
		int ah, aw, aval;
		int bh, bw, bval;
		tie(ah, aw, aval) = a;
		tie(bh, bw, bval) = b;
		LL L = aw*bh; LL R = ah*bw;
		if (L == R)return aval < bval;
		else return L > R;

	});

	int ans = 1;
	int cnt = 1;
	FOR(i, 0, SZ(events)) {
		int val;
		tie(ignore, ignore, val) = events[i];
		if (val)cnt++;
		else cnt--;
		ans = max(ans, cnt);
	}
	cout << ans << endl;

}
