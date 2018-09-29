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

/* -----  2018/09/29  Problem: yukicoder 297  / Link: http://yukicoder.me/problems/no/297  ----- */
/* ------問題------

N枚のカードに一桁の数字か+,−が書かれている。
全てのカードを好きな順番に横一列に並べて数式を作りたい。
この時、数式の最初や最後が演算子になったり、演算子同士が並んではいけない。
leading zero(012,003など0が先頭にくる数の表し方)は認める。
できる数式の答えの最大値と最小値を求めよ。

-----問題ここまで----- */
/* -----解説等-----

Maxについては、めちゃめちゃ大きい数字を1個作って、あとは適当をすれば良い。
Minについては、-があるときはどうようにできて、+しかないときは、均等に数字を割り振るのがよいことが証明できるのでそうする。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	int pc = 0, mc = 0;
	VI nums;
	FOR(i, 0, N) {
		char c; cin >> c;
		if (c == '-')mc++;
		else if (c == '+')pc++;
		else nums.push_back(c - '0');
	}
	RSORT(nums);

	LL Max = -INF;
	{ // Max
		LL ret = 0;
		FOR(i, 0, SZ(nums) - (pc + mc)) {
			ret *= 10;
			ret += nums[i];
		}
		int off = SZ(nums) - (pc + mc);
		FOR(i, 0, pc) {
			ret += nums[off + i];
		}
		off += pc;
		FOR(i, 0, mc) {
			ret -= nums[off + i];
		}
		Max = ret;
	}

	LL Min = INF;
	{ // Min
		if (mc) { // でっかいのをつくる
			LL ret = 0;
			FOR(i, 0, SZ(nums) - (pc + mc)) {
				ret *= 10;
				ret -= nums[i];
			}
			int off = SZ(nums) - (pc + mc);

			FOR(i, 0, mc-1) {
				ret -= nums[off + i];
			}
			off += mc-1;
			FOR(i, 0, pc+1) {
				ret += nums[off + i];
			}
			Min = ret;

		}
		else { // なるべく均等
			int cnt = pc + 1;
			SORT(nums);
			VI p(cnt, 0);
			for (int j = 0; j < SZ(nums); j += cnt) {
				for (int i = 0; i < cnt; i++) {
					if (j + i >= SZ(nums))continue;
					p[i] *= 10;
					p[i] += nums[j + i];
				}
			}
			LL ret = 0;
			FOR(i, 0, cnt) {
				ret += p[i];
			}
			Min = ret;
		}

	}

	cout << Max << " " << Min << endl;

	return 0;
}
