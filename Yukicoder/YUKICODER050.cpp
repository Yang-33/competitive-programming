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

/* -----  2018/04/11  Problem: yukicoder 050  / Link: http://yukicoder.me/problems/no/050  ----- */
/* ------問題------

おもちゃがN個とおもちゃ箱がM個ある。
おもちゃとおもちゃ箱にはそれぞれ容積が決まっている。
おもちゃ箱の容積以下のおもちゃをおもちゃ箱に入れることができる。
おもちゃ箱の容積以下であればおもちゃはいくつでも入る。
おもちゃ箱をおもちゃ箱に入れてはならない。

例えば、容積2のおもちゃと容積3のおもちゃと容積5のおもちゃ箱がある。
この場合、おもちゃ2つの容積は足して5なので容積5のおもちゃ箱に入る。

例えば、容積8のおもちゃと容積12のおもちゃと容積10のおもちゃ箱がある。
この場合、おもちゃ2つの容積は足して20なので容積10のおもちゃ箱に入らない。
ただし、容積8のおもちゃだけであれば容積10のおもちゃ箱に入る。

おもちゃとおもちゃ箱の情報が与えられる。
おもちゃをすべて入れることができる最小のおもちゃ箱の数を求めよ。
ただし、すべてのおもちゃがおもちゃ箱に入りきらなければ-1を答えとする。

-----問題ここまで----- */
/* -----解説等-----

a,bを整頓して、O(N!*M)だけ試せば良い。
おもちゃゲシュタルト崩壊した

----解説ここまで---- */

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	for (int &x : a) {
		cin >> x;
	}
	int M; cin >> M;
	VI b(M);
	for (int &x : b) {
		cin >> x;
	}
	RSORT(b);
	SORT(a);
	int ans = INF;
	do {
		VI B = b;
		int id = 0;
		map<int, int>Map;//使ったidを管理
		int acnt = 0;
		FOR(i, 0, N) {
			if (id >= M) {
				id = INF;
				continue;
			}
			while (B[id] < a[i]) {
				id++;
			}
			if (id < M && B[id] >= a[i]) {
				B[id] -= a[i];
				acnt++;
				Map[id] = 1;
				if (B[id] == 0)id++;
			}
		}

		if (acnt == N && id != INF)
			ans = min(ans, SZ(Map));

	} while (next_permutation(ALL(a)));
	if (ans == INF)ans = -1;
	cout << ans << "\n";

	return 0;
}
