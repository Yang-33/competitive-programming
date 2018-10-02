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

/* -----  2018/10/02  Problem: yukicoder 319  / Link: http://yukicoder.me/problems/no/319  ----- */
/* ------問題------

りあんくんは, 正整数 A,B(A≤B) に対し A から B までの数字を十進表記でつなげた文字列を考え, 「(A,B)文字列」と名付けることとしました.
例えば「(3,5)文字列」は "345", 「(8,13)文字列」は "8910111213", 「(102,102)文字列」は "102" となります.
ここでりあんくんは, ある正整数 A,B からなる「(A,B)文字列」に含まれる "12" という連続部分文字列の個数が気になってしまいました.
初めてのぽしゃけで酔っぱらってしまいダメダメなりあんくんの代わりに, 「(A,B)文字列」に含まれる "12" の個数を求めてあげてください.

-----問題ここまで----- */
/* -----解説等-----

ある数に含まれる12の数は簡単。いつもの桁DPをすれば良い。
次に、[...1][2...]を考える。
包除すれば出せそう。
一方、数値に含まれる[2...2]の数を数えた時、この手前に必ず[...1]があるので[2...2]のような、
2ではじまって2で終わるような数値の数を数えればよい。
これは桁DPで簡単にできる。
ただし、A,Bの区間はギリギリ重複しうるので、Aが[2...2]のときだけは-1しておく。(ex:B=23332, A=23332のときは、1ではなくて0)

----解説ここまで---- */

LL dp[14][2][7];
LL f(const string & s, int i, int preone = 0, int cnt = 0, int less = 0) {
	if (i == -1) {
		return cnt;
	}
	if (dp[i][preone][cnt] != -1 && less == 1)return dp[i][preone][cnt];

	LL res = 0;
	int Max = less ? 9 : s[i] - '0';
	FOR(nx, 0, Max + 1) {
		res += f(s, i - 1, nx == 1, cnt + (preone && (nx == 2)), less || nx < Max);
	}

	if (less == 1)return dp[i][preone][cnt] = res;
	return res;
}

LL dp2[14][2][2][2];
LL g(const string& s, int i, int lz = 1, int firsttwo = 0, int endtwo = 0, int less = 0) {
	if (i == -1) {
		return (!lz) && firsttwo&&endtwo;
	}

	if (less && dp2[i][lz][firsttwo][endtwo] != -1) { return dp2[i][lz][firsttwo][endtwo]; }
	LL res = 0;
	int Max = less ? 9 : s[i] - '0';
	FOR(nx, 0, Max + 1) {
		res += g(s, i - 1, lz&&nx == 0, firsttwo || (lz&&nx == 2), i == 0 && nx == 2, less || nx < Max);
	}

	if (less)return dp2[i][lz][firsttwo][endtwo] = res;
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	string A, B; cin >> A >> B;
	// A--
	LL ans = 0;
	if (A.front() == '2'&&A.back() == '2')ans--;
	FORR(i, SZ(A) - 1, 0 - 1) {
		if (A[i] == '0') {
			A[i] = '9';
		}
		else {
			A[i]--; break;
		}
	}
	if (A[0] == '0')A = A.substr(1);

	fill(**dp, **dp + 14 * 2 * 7, -1);
	fill(***dp2, ***dp2 + 14 * 2 * 2 * 2, -1);

	reverse(ALL(A));
	reverse(ALL(B));

	ans += f(B, SZ(B) - 1) - f(A, SZ(A) - 1);
	LL ret = g(B, SZ(B) - 1) - g(A, SZ(A) - 1);
	ans += ret;

	cout << ans << "\n";

	return 0;
}

