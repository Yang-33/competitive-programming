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

/* -----  2018/09/19  Problem: yukicoder 267  / Link: http://yukicoder.me/problems/no/267  ----- */
/* ------問題------

友達とトランプで遊ぶことにしました。
カードを配ってもらいましたが、手札のカードを順番に並べないと気が済みません。
カードを順番通りに並び替えてください。

カードは左から順にダイヤ、クローバー、ハート、スペードの順に並べます。
マークごとに左から順に数字の小さい順に並べます。

-----問題ここまで----- */
/* -----解説等-----

思い思いにソートを実装すれば良いです。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	auto decode = [](char c) {
		if (isdigit(c))return c - '0';
		else {
			if (c == 'A')return 1;
			else if (c == 'T')return 10;
			else if (c == 'J')return 11;
			else if (c == 'Q')return 12;
			else if (c == 'K')return 13;

			else if (c == 'D')return 0;
			else if (c == 'C')return 1;
			else if (c == 'H')return 2;
			else if (c == 'S')return 3;
		}
	};


	sort(ALL(vs), [&](const string &a, const string &b) {
		if (decode(a[0]) == decode(b[0])) {
			return decode(a[1]) <= decode(b[1]);
		}
		else {
			return decode(a[0]) <= decode(b[0]);
		}
	});

	FOR(i, 0, N) {
		cout << vs[i] << " \n"[i == N - 1];
	}

	return 0;
}
