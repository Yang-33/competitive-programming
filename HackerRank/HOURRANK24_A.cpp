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

/* -----  2017/11/02  Problem: hourrank24 A / Link: https://www.hackerrank.com/contests/hourrank-24/challenges/strong-password  ----- */
/* ------問題------

長さ6以上で四つの記号を必ず含むパスワードを作成したい。
現在考えているパスワードがあり、この文字列は変更しないでおきたい。
何文字追加すればいいか。

-----問題ここまで----- */
/* -----解説等-----

pythonでいうfor else みたいなのを書けばよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;
string numbers = "0123456789";
string lower_case = "abcdefghijklmnopqrstuvwxyz";
string upper_case = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string pecial_characters = "!@#$%^&*()-+";

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string S;
	cin >> S;
	ans = (6-SZ(S) >= 0 ? 6-SZ(S) : 0);
	int ad = 0;
	FOR(i, 0, N) {
		if (numbers.find(S[i]) < numbers.size())break;
		if (i == N - 1)ad++;
	}FOR(i, 0, N) {
		if (lower_case.find(S[i]) < lower_case.size())break;
		if (i == N - 1)ad++;
	}FOR(i, 0, N) {
		if (upper_case.find(S[i]) < upper_case.size())break;
		if (i == N - 1)ad++;
	}FOR(i, 0, N) {
		if (pecial_characters.find(S[i]) < pecial_characters.size())break;
		if (i == N - 1)ad++;
	}
	if (ans >= ad)ans = ans;
	else ans = ad;

	cout << ans << "\n";

	return 0;
}
