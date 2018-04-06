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

/* -----  2018/04/06  Problem: yukicoder 003  / Link: http://yukicoder.me/problems/no/003  ----- */
/* ------問題------

Carol は特殊なすごろくをしようとしている。

1からNの番号がふられている一直線に並べられているN個のマスがある。
1から開始のマスとして、ゴールはNが書かれているマスとする。

その場に書かれている数字の2進数で表現した時の1のビット数 だけ「前」または「後」に進めることができる。
(1未満とN+1以上のマスには移動することは出来ない、正確にNにならないとゴールできない）

自然数Nを与えられた時、ゴールに到達できる最短の移動数（開始のマスへも移動にカウントする）を求めてください。
到達できない場合は-1を出力してください。

開始のマスがすでにゴールになっている場合もあリます。

-----問題ここまで----- */
/* -----解説等-----

値が小さいので幅優先探索をします。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;

	VI dist(N + 1, INF);
	queue<PII>q;
	dist[1] = 1;
	q.push(PII(1, 1));

	while (!q.empty()) {
		int now = q.front().first;
		int ti = q.front().second;
		q.pop();
		if (now == N) {
			ans = ti;
			break;
		}
		int ad = __builtin_popcount(now);
		if (now - ad > 0 && dist[now - ad] > ti + 1) {
			q.push(PII(now - ad, ti + 1));
			dist[now - ad] = ti + 1;
		}

		if (now + ad <= N && dist[now + ad] > ti+1) {
			q.push(PII(now + ad, ti + 1));
			dist[now + ad] = ti + 1;
		}
	}
	if (ans == 0)ans = -1;
	cout << ans << "\n";

	return 0;
}
