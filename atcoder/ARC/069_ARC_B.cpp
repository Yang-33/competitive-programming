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

/* -----  2018/02/27  Problem: 069_arc_b / Link: https://abc055.contest.atcoder.jp/tasks/arc069_b?lang=en  ----- */
/* ------問題------

すぬけくんは動物が好きなので動物園を作りました。
この動物園では 1,2,3,…,N の番号を割り振られた N 匹の動物が円環状に並べられています。 i(2≦i≦N−1) 番の動物は i−1 番の動物と i+1 番の動物と隣り合っています。また、1 番の動物は N 番の動物と 2 番の動物と隣り合っており、N 番の動物は N−1 番の動物と 1 番の動物と隣り合っています。
動物園には本当のことしか言わない正直者の羊と、嘘しか言わない嘘つきの狼の 2 種類の動物がいます。
すぬけくんには羊と狼の区別がつかないので、それぞれの動物に両隣の動物が同じ種類かどうかを訪ねたところ、i 番目の動物は si と答えました。si が o ならば両隣の動物が同じ種類であると、x ならば異なる種類であると i 番の動物が言ったことを示します。
より形式的には、羊は両隣の動物がどちらも羊あるいはどちらも狼のとき o と答え、そうでないとき x と答えます。 狼は両隣の動物がどちらも羊あるいはどちらも狼のとき x と答え、そうでないとき o と答えます。
これらの回答結果と矛盾しないような各動物の種別の割り当てが存在するか、すぬけくんは気になっています。存在するならば一例を示し、存在しないならば -1 を出力しなさい。

-----問題ここまで----- */
/* -----解説等-----

4つ状態を決めるとあとは決定されていき、
全部の候補が上がったら確認を入れれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string s;
	cin >> s;
	VVI a(4, VI(N, -1));
	a[0][0] = (0);	a[0][1] = (0);
	a[1][0] = (0);	a[1][1] = (1);
	a[2][0] = (1);	a[2][1] = (0);
	a[3][0] = (1);	a[3][1] = (1);
	// 動物の種類を決定 0 - S, 1 - W

	FOR(k, 0, 4) {
		VI &p = a[k];
		FOR(i, 1, N-1) {
			if (s[i] == 'o') {
				if(p[i] == 0)p[i + 1] = p[i - 1];
				else p[i + 1] = !p[i - 1];
			}
			else { // 'x'
				if (p[i] == 0)p[i + 1] = !p[i - 1];
				else p[i + 1] = p[i - 1];
			}
		}

	}

	string str= "SW";

	FOR(k, 0, 4) {
		VI &p = a[k];
		bool ok = 1;
		if (s[0] == 'o') {
			if (p[0] == 0) {
				if (p[N - 1] != p[1])ok = 0;
			}
			else {
				if (p[N - 1] == p[1]) ok = 0;
			}
		}
		else {
			if (p[0] == 0) {
				if (p[N - 1] == p[1])ok = 0;
			}
			else {
				if (p[N - 1] != p[1]) ok = 0;
			}
		}

		if (s[N-1] == 'o') {
			if (p[N-1] == 0) {
				if (p[N - 2] != p[0])ok = 0;
			}
			else {
				if (p[N - 2] == p[0]) ok = 0;
			}
		}
		else {
			if (p[N-1] == 0) {
				if (p[N - 2] == p[0])ok = 0;
			}
			else {
				if (p[N - 2] != p[0]) ok = 0;
			}
		}
		if (ok) {
			FOR(i, 0, N) {
				cout << str[p[i]];
			}cout << endl;
			return 0;
		}
	}

	cout << -1 << "\n";

	return 0;
}
