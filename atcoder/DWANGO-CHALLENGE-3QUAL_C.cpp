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

/* -----  2018/02/26  Problem: dwango-challenge-3qual_c / Link: https://dwacon2017-prelims.contest.atcoder.jp/tasks/dwango2017qual_c?lang=en  ----- */
/* ------問題------

スキーが大好きなタカシくんは、ニコニコスキー場でリフト係のアルバイトを始めました。 このスキー場には搬器（いす）1 台あたりの定員が 4 人であるリフトが 1 基あり、ここにスキー客が 1 人から 4 人までのグループで並びに来ます。
ある日、リフトの待ち行列が長くなったことに困ったタカシくんは、スキー客にリフトの相乗りをしてもらおうと考えました。 タカシくんは、搬器が 1 台乗り場に着くごとに以下のような手順でスキー客のグループをその搬器に案内することにしました。

最初に、待ち行列の先頭にいるグループを搬器に案内する。
現在の搬器に相乗りしても定員を超えないようなグループが存在する限り、そのようなグループを搬器に案内する。ただし、そのようなグループが複数存在する場合は、待ち行列での位置に関わらず、いずれのグループを案内しても構わない。
今、リフトには N グループのスキー客が並んでおり、待ち列の先頭から i(1≦i≦N) 番目のグループは Ai 人のスキー客からなります。 タカシくんがうまくスキー客のグループを案内することによって、最短で何台目の搬器で今並んでいるグループをすべて運びきることができるかを求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

順序が関係ないのでしきつめもんだいになる

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a(N);

	VI num(4, 0);
	FOR(i, 0, N) {
		cin >> a[i];
		if (a[i] == 4)ans++;
		else num[a[i]]++; // 1,2,3
	}
	ans += (num[2]) / 2;
	num[2] %= 2;

	LL ret = min(num[1], num[3]);
	ans += ret;
	num[1] -= ret;
	num[3] -= ret;



	if (num[2]) {
		ans += 1;
		num[1] -= 2;
	}

	if (num[1] > 0)ans += (num[1] + 3) / 4;



	ans += num[3];

	cout << ans << "\n";

	return 0;
}
