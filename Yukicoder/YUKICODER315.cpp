#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
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

/* -----  2018/10/01  Problem: yukicoder 315  / Link: http://yukicoder.me/problems/no/315  ----- */
/* ------問題------

ある芸人のモノマネをする芸人が現れました。
彼は「3の倍数 もしくは 3のつく数」のとき「アホ」になり、「Pの倍数(Pは 8, 80, 800 のいずれか)」のとき「恥じらい」を見せます。
A 以上 B 以下の整数のうち、「アホ」になりかつ「恥じらい」を見せない数がいくつあるかを 109+7 で割った時の余りで求めてください。

-----問題ここまで----- */
/* -----解説等-----

これ解くの1年ぶりなんだ
メモリについて、全部の状態を取るとMLEする。
そこで8**の倍数の判定を考える。すると、下位3,4,5桁だけアレば判定できることがわかる。
したがって、適当に最後だけメモリを確保するみたいな感じの実装を付け加えた、普通の桁DPをすれば良い。

----解説ここまで---- */


vector<LL> dp[200005][3][2];
int EIGHT;
map<int, int>eightDigit = { {8,3},{80,4},{800,5} };
int positiveDigit;
LL f(const string& s, int i, short threemod = 0, bool hasthree = 0, int eightmod = 0, bool less = 0) {
	if (i == -1) {
		return (threemod == 0 || hasthree == 1) && eightmod%EIGHT;
	}
	if (less && dp[i][threemod][hasthree].size() == 0) {
		if (i + 1 > positiveDigit) {
			dp[i][threemod][hasthree].assign(1, -1);
		}
		else {
			dp[i][threemod][hasthree].assign(EIGHT, -1);
		}
	}
	else {
		// return memo
		if (less) {
			if (i + 1 > positiveDigit) {
				if (dp[i][threemod][hasthree][0] != -1)return dp[i][threemod][hasthree][0];
			}
			else {
				if (dp[i][threemod][hasthree][eightmod] != -1)return dp[i][threemod][hasthree][eightmod];
			}
		}
	}
	LL res = 0;
	int Max = less ? 9 : s[i] - '0';
	FOR(nx, 0, Max + 1) {
		res += f(s, i - 1, (threemod + nx) % 3, hasthree || nx == 3, (eightmod * 10 + nx) % EIGHT, less || (nx < Max));
	}
	res %= MOD;
	if (less) {
		if (i + 1 > positiveDigit) 	return dp[i][threemod][hasthree][0] = res;
		else return dp[i][threemod][hasthree][eightmod] = res;
	}
	else {
		return res;
	}
}



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string A, B; cin >> A >> B >> EIGHT;
	::positiveDigit = eightDigit[EIGHT];
	FORR(i, SZ(A) - 1, 0 - 1) { // A--;
		if (A[i] == '0') {
			A[i] = '9';
		}
		else {
			A[i]--;
			break;
		}
	}
	if (A[0] == '0')A = A.substr(1);
	reverse(ALL(A)), reverse(ALL(B));

	LL ans = f(B, SZ(B) - 1);
	LL ret = f(A, SZ(A) - 1);
	ans -= ret;
	if (ans < 0)ans += MOD;
	cout << ans << "\n";

	return 0;
}
