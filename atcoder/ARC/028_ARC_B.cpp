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

/* -----  2018/11/03  Problem: ARC 028 B / Link: http://arc028.contest.atcoder.jp/tasks/arc028_b  ----- */
/* ------問題------

高橋君はプログラミングコンテストを行い、N 人の人が参加しました。
賞品がないと物足りないのではないかと思った高橋君は「i 位以上の人のうち、K 番目に若い人」に特別賞を出すことにしました。
参加者全員の年齢は分かっています。K の値はもう既に決めているのですが、i の値はまだ決めていません。
i の値を決めるために高橋君は、K 以上 N 以下の整数 i それぞれについて誰が特別賞を取ることが出来るのかを計算してみることにしました。

-----問題ここまで----- */
/* -----解説等-----

えーという気持ちになるが、ある一定時間をすぎると答えに含まれない人達が出てくるのでpriority_queueでやればできる。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	priority_queue<PII>pq;// bigger
	FOR(i, 0, N) {
		int a; cin >> a;
		pq.push(PII(a, i + 1));
		if (SZ(pq) >= K) {
			if (SZ(pq) > K) {
				pq.pop();
			}
			cout << pq.top().second << endl;
		}

	}

	return 0;
}