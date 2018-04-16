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

/* -----  2018/04/16  Problem: yukicoder 078  / Link: http://yukicoder.me/problems/no/078  ----- */
/* ------問題------

A君は当たりクジ付きのアイスバーが大好きである。
アイスバーには「ハズレ」と「1本当たり」と「2本当たり」がある。
ハズレは何ももらえないが、当たりだとその本数をタダでもらえる。

お店ではアイスバーが箱詰めされて売られている。
1つの箱にはN本のアイスバーが入っている。
A君は箱の先頭から順にしかアイスバーを取り出すことはできない。
買う場合も当たりと引き換えの場合もこの箱からアイスバーを取り出す。
1つの箱の中のハズレと当たりクジの配置はどの箱も同じである。
お店には1つのアイスバーの箱があり、売り切れると1つの新しい箱を補充する。
いまお店には新しい手つかずのアイスバーの箱がある。
A君は最初は「当たり」クジを持っておらず予算は無限にある。
K本のアイスバーを食べるためにはA君は最低何本のアイスを買う必要があるか？

-----問題ここまで----- */
/* -----解説等-----

区間を次のように分割する。
[愚直]{[前回のあたりが影響する区間]}[K%Nが真なら前回のあたりが影響する]
とすれば良い。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, K; cin >> N >> K;
	string s;  cin >> s;
	int ret = INF;
	int free = 0, cnt = 0;
	FOR(i, 0, N) {
		if (free > 0) {
			free--;
		}
		else {
			cnt++;
		}

		free += s[i] - '0';
		if ((i + 1) % N == K%N) {// K個目を買い終える
			ret = min(ret, cnt);
		}
	}
	int ans = ret;

	int t = K / N;
	if (t) {
		ans = cnt + (t - 1)*(max(0, cnt - free)) + (K%N ? max(0, ret - free) : 0);
	}


	cout << ans << "\n";

	return 0;
}
