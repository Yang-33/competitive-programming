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

/* -----  2018/05/05  Problem: yukicoder 158  / Link: http://yukicoder.me/problems/no/158  ----- */
/* ------問題------

A君は1000円札をA1000枚、100円玉をA100枚、1円玉をA1枚持っている。
Bさんのところで紙幣、硬貨の種類を問わずちょうどDb円払うと、(Db円より多く払うことは出来ない)
1000円札をB1000枚、100円玉をB100枚、1円玉をB1枚もらえる。
このときもらえる額は払った額より必ず少ない。
Cさんのところで紙幣、硬貨の種類を問わずちょうどDc円払うと、(Dc円より多く払うことは出来ない)
1000円札をC1000枚、100円玉をC100枚、1円玉をC1枚もらえる。
このときももらえる額は払った額より必ず少ない。
BさんもしくはCさんにお金を払ってお金をもらう行為を1回のお使いとする。
A君はお使いにたくさん行くと褒められる。
A君はBさんCさんにお使いに行く順番と支払い方法を工夫してたくさんお使いに行きたい。
A君が行くことのできる最大のお使いの回数は何回か？。

-----問題ここまで----- */
/* -----解説等-----

よくわからないし、操作は二種類しかないので、メモ化再帰する。

----解説ここまで---- */
int memo[21][201][20001];
int Db, B1000, B100, B1, Dc, C1000, C100, C1;

int f(int a1000, int a100, int a1) {
	int &ret = memo[a1000][a100][a1];
	if (ret != -1)return ret;
	ret = 0;
	FOR(i, 0, a1000 + 1) {
		FOR(j, 0, a100 + 1) {
			int sum = i * 1000 + j * 100;
			if (sum <= Db && a1 >= Db - sum) {

				ret = max(ret, f(a1000 - i + B1000, a100 - j + B100, a1 - (Db - sum) + B1) + 1);
			}
			if (sum <= Dc && a1 >= Dc - sum) {
				ret = max(ret, f(a1000 - i + C1000, a100 - j + C100, a1 - (Dc - sum) + C1) + 1);
			}
		}
	}
	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int A1000, A100, A1;
	cin >> A1000 >> A100 >> A1;
	cin >> Db >> B1000 >> B100 >> B1;
	cin >> Dc >> C1000 >> C100 >> C1;
	fill(**memo, **memo + 21 * 201 * 20001, -1);

	int ans = f(A1000, A100, A1);
	cout << ans << "\n";

	return 0;
}
