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

/* -----  2018/06/24  Problem: AOJ 2245 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2245  ----- */
/* ------問題------

脱出

-----問題ここまで----- */
/* -----解説等-----

えー考察をすると最古とはほぼ関係ないことがわかる。
答えの最大値が3で抑えられるので場合分けをすれば良い。

----解説ここまで---- */

char dice[8][5][5];
int i, j, res, f[3];
int input(){
	for (i = 1; i <= 6; i++)
		for (j = 2; j >= 0; j--){
			scanf("%s", dice[i][j]);
			if (i == 1 && j == 2 && dice[i][j][0] == '#') return 0;
		}
	return 1;
}
void f1(int a, int b, int m){
	for (f[m] = i = 0; i < 3; i++) if (dice[a][b][i] == '*') f[m] = 1;
}
void f3(int a, int b, int m){
	for (f[m] = i = 0; i < 3; i++) if (dice[a][i][b] == '*') f[m] = 1;
}
void C(int x){
	if (f[1] && f[2]) res = min(res, x);
}

void solve_AOJ_2245() {
	while (input()){
		res = 9;

		f1(1, 0, 1), f1(3, 0, 2), C(0);
		f1(1, 2, 1), f1(3, 2, 2), C(2);
		f3(1, 0, 1), f3(3, 2, 2), C(1);
		f3(1, 2, 1), f3(3, 0, 2), C(1);

		f1(2, 0, 1), f1(4, 0, 2), C(3);
		f1(2, 2, 1), f1(4, 2, 2), C(3);
		f3(2, 0, 1), f3(4, 2, 2), C(2);
		f3(2, 2, 1), f3(4, 0, 2), C(2);

		f1(5, 0, 1), f1(6, 2, 2), C(1);
		f1(5, 2, 1), f1(6, 0, 2), C(1);
		f3(5, 0, 1);
		for (f[2] = i = 0; i < 3; i++) if (dice[6][2 - i][0] == '*') f[2] = 1;
		C(2);
		f3(5, 2, 1);
		for (f[2] = i = 0; i < 3; i++) if (dice[6][2 - i][2] == '*') f[2] = 1;
		C(2);

		printf("%d\n", res);
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve_AOJ_2245();

	return 0;
}
