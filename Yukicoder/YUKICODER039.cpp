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

/* -----  2018/04/10  Problem: yukicoder 039  / Link: http://yukicoder.me/problems/no/039  ----- */
/* ------問題------

2桁以上9桁以下の数字Nが与えられる。
数字Nはいずれの桁にも数字の0を含まない。
どの桁の数字も1から9の数字で構成される。
いま、2つの桁の数字を自由に選んで、
1回だけ入れ替えることが許される。
入れ替えないという選択もできる。
最も大きな数字を作ろうとするとき、
その最も大きな数字はいくつか？

-----問題ここまで----- */
/* -----解説等-----

string to longlong + swap でO(N^2)
後ろからa[i]:= [i+1,N)にある最大値、として、
前から順にs[i]<a[i]となった時点で交換すれば O(N)

----解説ここまで---- */


LL ans = 0LL;

LL f(string& s) {
	LL ret = stoll(s);
	vector<PLL> a(SZ(s),PII(0,0));
	PII Max = PII(0,0);
	FORR(i, SZ(s) - 1, 0 - 1) {
		a[i] = Max;
		Max = max(Max, PII(s[i] - '0',i));
	}
	FOR(i, 0, SZ(s)) {
		if (s[i] - '0' < a[i].first) {
			swap(s[i], s[a[i].second]);
			return stoll(s);
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s;
	cin >> s;
	ans = stoll(s);
	FOR(i, 0, SZ(s)) {
		FOR(j, i+1, SZ(s)) {
			swap(s[i], s[j]);
			ans = max(ans, stoll(s));
			swap(s[i], s[j]);

		}
	}
	assert(ans == f(s));
	cout << ans << "\n";

	return 0;
}
