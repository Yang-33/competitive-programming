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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/12/14  Problem: ARC 010 B / Link: http://arc010.contest.atcoder.jp/tasks/arc010_b  ----- */
/* ------問題------

2011 年、AtCoder 国の高橋首相はある重大な決定を行った。
その決定とは...法改正である。国民の祝日に関する法律を変更し、休日を増やすことにした!!
国民の創造性を尊重するその決定が、霞が関を魔境へと変えたッ！

あなたは霞が関の国土交通省に勤務する職員であり、この法改正により上司から新たな任務を与えられた。
その任務とは、2012 年の「連休の最大日数」を計算することである。
連休の大きさを事前に計算することで国民の行動を予想し、高速道路の部分的な値下げを行い、経済を活性させるためだ。
したがって、あなたに失敗することは許されない。国民の行動を正確に予想できなくなるからだ。

以下に、「連休」の定義と諸注意を記す。
AtCoder 国が使用する暦はグレゴリオ暦に従う。
「連休」とは、「休日」が連続して続くことである。
「土曜日」「日曜日」「祝日」「振替休日」が「休日」に相当する。
「祝日」が他の休日と同じ日に指定されていた場合、「振替休日」を必ず設置する。
「振替休日」は祝日の時系列順に決定していき、その祝日以降最も近い平日（休日を除いた日）となる。
2012 年 1 月 1 日は日曜日である。

-----問題ここまで----- */
/* -----解説等-----

がんばる。

----解説ここまで---- */

const int holiday[7] = { 1, 0, 0, 0, 0, 0, 1 };
const int days[12] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

int main() {
	int N; cin >> N;

	set<PII> shuku;
	FOR(i, 0, N) {
		int m, d; scanf("%d/%d", &m, &d);
		shuku.insert(PII(m, d));
	}

	int m = 1, d = 1;
	int kind = 0, huri = 0;
	int ans = 0, sub = 0;

	while (m <= 12) {
		if (holiday[kind]) {
			sub++;
			ans = max(ans, sub);
			if (shuku.find(PII(m, d)) != shuku.end()) {
				huri++;
			}
		}
		else if (shuku.find(PII(m, d)) != shuku.end()) {
			sub++;
			ans = max(ans, sub);
		}
		else if (huri) {
			huri--;
			sub++;
			ans = max(ans, sub);
		}
		else {
			sub = 0;
		}

		d++;
		if (d > days[m - 1]) {
			d = 1;
			m++;
		}
		kind++;
		kind %= 7;
	}
	cout << ans << endl;

	return 0;
}