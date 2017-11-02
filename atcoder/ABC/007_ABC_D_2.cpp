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
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/10/31  Problem: ketadp1 / Link: http://abc007.contest.atcoder.jp/tasks/abc007_4  ----- */
/* ------問題------

たかはし王国の国王であるたかはし君主は数字の 4 と 9 が大嫌いです。それらの数字を国内で目にするだけで気分が悪いので、それらを使ってはいけないという法律を定めました。この法律を破ってしまうと罰せられます。数字が禁止されているので、ある数の10進表現を考えたとき、いずれかの桁に禁止された数字が1つでも含まれている場合、その数を使うことはできません。

今まで使っていた数字を使えなくなったあなたは、うっかり使ってしまって罰せられては困るので、使う可能性がある数の区間 [A,B]={A,A+1,A+2,…,B} に、いくつ禁止された数が含まれているかを確かめることにしました。そのためのプログラムを作ってください。
-----問題ここまで----- */
/* -----解説等-----

dp[今i桁を見ている][禁止文字なら1][値未満が確定しているなら1]:=総数
で再帰

----解説ここまで---- */

string A, B;

LL ans = 0LL;
LL dp[20][2][2];
// less:=未満が確定か
LL f(string &target, int i = 0, int no = 0,int less = 0) {
	if (SZ(target) == i) {
		//debug(no);
		if (no == 1)return 1;
		else return 0;
	}

	LL &res = dp[i][no][less];
	if (res != -1)return res;
	res = 0;
	int num = target[i] - '0';
	int Max = (less ? 9 : num);
	FOR(nx, 0, Max + 1) {
		res += f(target, i + 1, no||nx == 4 || nx == 9,less||nx<Max);
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL a, b;
	cin >> a >> b;
	a--;
	A = to_string(a);
	B = to_string(b);
	FOR(i, 0, 20)FOR(j, 0, 2)FOR(k, 0, 2)dp[i][j][k] = -1;
	LL ret1 = f(B);
	FOR(i, 0, 20)FOR(j, 0, 2)FOR(k, 0, 2)dp[i][j][k] = -1;
	LL ret2 = f(A);
	//debug(ret1);
	//debug(ret2);
	ans = ret1 - ret2;
	cout << ans << "\n";

	return 0;
}
