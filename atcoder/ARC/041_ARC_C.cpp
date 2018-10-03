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

/* -----  2018/10/03  Problem: ARC 041 C / Link: http://arc041.contest.atcoder.jp/tasks/arc041_c  ----- */
/* ------問題------

L 個のマスが横一列に並んでいる。 マスの上には N 匹のウサギがいる。 i (1≦i≦N) 番目のウサギは、左から xi 番目のマスにいる。 ただし、1≦x1<x2<..<xN≦L を満たす。 また、ウサギはそれぞれ左向きまたは右向きである。
それぞれのウサギは、自分の 1 つ前にマスが存在し、そこに他のウサギがいなければ、ジャンプして自分の 1 つ前のマスへ移動できる。
ウサギがジャンプする順番を自由に選べるとき、ジャンプの総回数の最大値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

向かい合っているやつで衝突せざるを得ない。したがって向かい合うウサギさんについて考える。
結局、-> -> -> <- みたいなのは、=> <-みたいなのに縮約できる。このとき、衝突点に最も近いうさぎ以外は寄せてしまっても問題ないことがわかる。
また、まとめられた後の向かい合う2匹のうさぎさんについて、たくさんいるほうが移動したほうが総移動回数を稼げる。
したがって問題をO(N)で解ける。実装をバグらせないように頑張る。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, L; cin >> N >> L;
	// 区間に対して、なんか [-> -> <-]+
	// のsetを [=> <-]+ みたいにすれば貪欲?
	char pc = 0;
	using tp = tuple < char, int, LL>;
	vector<tp>a;
	vector<LL>pos;
	LL ans = 0;
	FOR(i, 0, N) {
		int x; char c; cin >> x >> c;
		if (!pc) {
			pc = c;
			pos.push_back(x);
		}
		else if (pc == 'R') {
			if (pc != c) { // merge
				LL Front = pos.back(); LL F = Front;
				LL sum = 0;
				FORR(i, SZ(pos) - 2, 0 - 1) {
					sum += Front - pos[i] - 1;
					Front--;
				}
				ans += sum;
				a.push_back(tp(pc, F, SZ(pos)));
				// change
				pos.clear();
				pc = c;
				pos.push_back(x);
			}
			else { // push
				pos.push_back(x);
			}
		}
		else { // pc == 'L'
			if (pc != c) { // merge
				LL Front = pos.front(); LL F = Front;
				LL sum = 0;
				FOR(i, 1, SZ(pos)) {
					sum += pos[i] - Front - 1;
					Front++;
				}
				ans += sum;
				a.push_back(tp(pc, F, SZ(pos)));
				// change
				pos.clear();
				pc = c;
				pos.push_back(x);
			}
			else { // push
				pos.push_back(x);
			}
		}
	}

	// 末尾も書く
	{
		if (SZ(pos)) {
			if (pc == 'R') {
				LL Front = pos.back(); LL F = Front;
				LL sum = 0;
				FORR(i, SZ(pos) - 2, 0 - 1) {
					sum += Front - pos[i] - 1;
					Front--;
				}
				ans += sum;
				a.push_back(tp(pc, F, SZ(pos)));
			}
			else { // pc L 
				LL Front = pos.front(); LL F = Front;
				LL sum = 0;
				FOR(i, 1, SZ(pos)) {
					sum += pos[i] - Front - 1;
					Front++;
				}
				ans += sum;
				a.push_back(tp(pc, F, SZ(pos)));
			}
		}
	}

	// end A
	char topcolor;
	tie(topcolor, ignore, ignore) = a.front();
	if (topcolor == 'L') {
		LL f, sz; tie(ignore, f, sz) = a.front();
		ans += (f - 1)*sz;
	}
	for (int i = topcolor == 'L'; i + 1 < SZ(a); i += 2) {
		// => <= なので、頑張る
		char R, L; LL Rf, Lf, Rsz, Lsz;
		tie(R, Rf, Rsz) = a[i];
		tie(L, Lf, Lsz) = a[i + 1];
		assert(Rf <= Lf);
		ans += (Lf - Rf - 1)*max(Rsz, Lsz);
	}
	// こっちも末尾
	tie(topcolor, ignore, ignore) = a.back();
	if (topcolor == 'R') {
		LL f, sz; tie(ignore, f, sz) = a.back();
		ans += (L - f)*sz;
	}


	
	
	cout << ans << "\n";

	return 0;
}
