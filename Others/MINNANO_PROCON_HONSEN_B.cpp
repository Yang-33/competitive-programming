#include "bits/stdc++.h"
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
#define FOR(i, s, e) for (LL(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/04  Problem: Nagoya_univ_contest_17_g  / Link: http://yahoo-procon2017-final-open.contest.atcoder.jp/tasks/yahoo_procon2017_final_b  ----- */
/* ------問題------

ACoder では，チーム高橋とチーム青木の 2 チーム対抗でのプログラミングコンテストを開こうとしています．
チーム高橋の参加者の候補は N 人いて，チーム高橋の i 番目の候補者の実力は Ai で表されます．
また，チーム青木の参加者の候補は M 人いて，チーム青木の i 番目の候補者の実力は Bi で表されます．
コンテストを開く前に，チーム高橋，チーム青木のそれぞれから K 人ずつの参加者を選ぶことにしました．
参加者は，それぞれのチームの参加者の候補から選ばれます． 
ここで，K 人ずつの参加者を選んだときの，チーム間の実力差を次のように定義することにしました．
チーム高橋の参加者の中で i 番目に実力の値が大きい人の実力を Xi，
チーム青木の参加者の中で i 番目に実力の値が大きい人の実力を Yi とする．
このとき，チーム間の実力差は，max(|X1−Y1|,|X2−Y2|,…,|XK−YK|) である．
各チームの参加者を決めたときの，チーム間の実力差の最小値を求めてください．

-----問題ここまで----- */
/* -----解説等-----

要素間の差を最小にしようと考えたとき、昇順に並べた2つの列から、
大きいものを見ていき、相手の列のなるべく大きい方からとっていって、最悪小さいものをとるようにすればいいことが分かる。
したがって、差をX以下でK個組を作れるかについて、にぶたんをすればよい。

----解説ここまで---- */
#define DB(x)cerr<<#x<<": "<<x<<", "

LL N, M, K;
vector<LL>a, b;
LL ans = 0LL;
int kuso = 0;
LL f(LL x) {//最大差分を何個X以下にできるか
	int last = M;
	int cnt = 0;
	FORR(i, N - 1, -1) {
		int up = (upper_bound(ALL(b), a[i] + x) - b.begin());
		int sita = (lower_bound(ALL(b), a[i] - x) - b.begin());
		up--;

		if (up >= 0 && up < last) {
			if (abs(a[i] - b[up]) <= x) {
				cnt++;
				last = up;
			}
		}
		else if (up >= 0) {
			int tmp = last - 1;
			if (tmp >= sita)
				if (abs(a[i] - b[tmp]) <= x) {
					cnt++;
					last = tmp;
				}
		}
//		DB(cnt); DB(last);
	}
//	cout << "push! "; cin >> kuso;
//	debug(cnt);
	return cnt;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> K;
	a = VL(N, 0);
	b = VL(M, 0);
	FOR(i, 0, N)cin >> a[i];
	FOR(i, 0, M)cin >> b[i];
	SORT(a);
	SORT(b);

	LL L = 0, R = 1e9 + 100;
	FOR(_i, 0, 40) {
		LL mid = (L + R) / 2;
		if (f(mid) >= K) {//できちゃう
			R = mid;
		}
		else L = mid;
	}
	//debug(L);
	ans = LINF;
	FOR(i, max(0LL, L - 5), L + 5) {
		if (f(i) >= K) {
			ans = min(ans, (LL)i);
		}
	}

	cout << ans << "\n";

	return 0;
}