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

/* -----  2018/10/01  Problem: yukicoder 318  / Link: http://yukicoder.me/problems/no/318  ----- */
/* ------問題------

数列 a1,…,an が与えられます。この数列を元に数列 b1,…,bn を次のように作ります。

t=1 から t=109 について、順番に次の操作をする。
al=t , ar=t であるような全ての l≤r について、bl,…,br を t で書き換える。

数列 b1,…,bn を求めて下さい。

-----問題ここまで----- */
/* -----解説等-----

fillをするsegtreeがあればできる。

segtreeを使わない!
最大値から塗られていくのだから、区間の末尾を考える。
先頭から見た時、ここを塗るのは、自身か、これを覆う区間である。
最大値が知りたくて、シュミレーションがしたいのでpriority_queueでできる。
かしこい

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	VI a(N);
	map<int, int>End;
	FOR(i, 0, N) {
		cin >> a[i]; 
		End[a[i]] = i;
	}

	priority_queue<int>pq;
	FOR(i, 0, N) {
		pq.push(a[i]);
		while ( End[pq.top()] < i){
			pq.pop();
		}
		cout << pq.top() << " \n"[i == N - 1];
	}

	return 0;
}
