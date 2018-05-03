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

/* -----  2018/05/03  Problem: yukicoder 146  / Link: http://yukicoder.me/problems/no/146  ----- */
/* ------問題------

とある教員（匿名希望）は，すぐ近くでは節分祭をやっている中，期末試験の試験監督をしている時に以下の問題を考えました．
カンニング防止の為，受講生は同じ机で隣同士の席に座ることはできません．
例えば，3 つの椅子がある机の場合，2 人の受講生が座る場合は両端の椅子を使う以外は許されておらず，1 人の受講生が座る場合は 3 つのうちどの椅子でも使うことができます．
ある部屋では，N 種類の机があり，Ck 個の椅子がある机が Dk 個あります．
ここで，Ck 個の椅子がある机は，Ck 個の椅子が直線上に配置されています．
この部屋で試験を受けることができるの受講生の人数の最大値を mod 109+7 で求めるプログラムを書いてください．

-----問題ここまで----- */
/* -----解説等-----

計算順序は…大事だね！  
C%=MOD, ans+=((c+1)/2*d)じゃあないんだよね

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	LL ans = 0;
	FOR(i, 0, N) {
		LL c, d; cin >> c >> d;
		d %= MOD;
		(c = (c+1)/2)%= MOD;
		ans += (c*d) % MOD;
		ans %= MOD;
	}
	cout << ans << "\n";

	return 0;
}
