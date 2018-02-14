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

/* -----  2018/02/14  Problem: 080_abc_c / Link: https://abc080.contest.atcoder.jp/tasks/abc080_c?lang=en  ----- */
/* ------問題------

joisinoお姉ちゃんは、ある商店街に店を開こうとしています。
その商店街の店は、月曜日から金曜日の 5 つの曜日を午前と午後の 2 つの時間帯に分けて、これら 10 個の時間帯それぞれについて店を営業するか否かを決めることとなっています。
ただし、1 つ以上の時間帯で店を営業しなければなりません。
商店街には既に N 個の店があり、1 から N までの番号がついています。
これらの店の営業時間の情報として Fi,j,k が与えられ、月曜日 = 曜日 1、火曜日 = 曜日 2、水曜日 = 曜日 3、木曜日 = 曜日 4、金曜日 = 曜日 5、 午前 = 時間帯 1、午後 = 時間帯 2 と対応させたとき、
Fi,j,k=1 なら曜日 j の時間帯 k に店 i が営業しており、Fi,j,k=0 なら営業していないことを意味します。
店 i とjoisinoお姉ちゃんの開く店の両方が営業している時間帯の個数を ci としたとき、joisinoお姉ちゃんの店の利益は P1,c1+P2,c2+…+PN,cN となります。
ただし、利益は負にもなりうることに注意してください。
1 つ以上の時間帯で店を営業しなければならないことに注意しつつ、10 個の時間帯それぞれについて店を営業するか否かを決めるとき、joisinoお姉ちゃんの店の利益のあり得る最大値を求めてください。


-----問題ここまで----- */
/* -----解説等-----

bitmaskを考えれば、一緒の時間にやるのはandで計算できる。
また立っているビットの数も簡単に計算できるのでこれは解ける。

----解説ここまで---- */

int popcount2(int x) {
	int ret = 0;
	while (x) {
		x &= x - 1;
		++ret;
	}
	return ret;
}
LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI shop(N, 0);
	FOR(i, 0, N) {
		int ret = 0;
		FOR(j, 0, 10) {
			int a; cin >> a;
			ret <<= 1;
			ret += a;
		}
		shop[i] = ret;
	}
	VVI pro(N, VI(11));
	FOR(i, 0, N) {
		FOR(j, 0, 11) {
			cin>>pro[i][j];
		}
	}

	ans = -LINF;
	FOR(bit, 0, 1 << 10) {
		if (popcount2(bit) == 0)continue;// 0のみだった
		LL ret = 0;
		FOR(i, 0, N) {
			int state = bit&shop[i];
			int cnt = popcount2(state);
			ret += pro[i][cnt];
		}
		ans = max(ans, ret);
	}
	cout << ans << "\n";

	return 0;
}
