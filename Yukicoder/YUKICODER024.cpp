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

/* -----  2018/04/09  Problem: yukicoder 024  / Link: http://yukicoder.me/problems/no/024  ----- */
/* ------問題------

太郎君と二郎君はゲームをしています。

まず最初に二郎君は 0から9までの数字を1つ、心の中で思い浮かべます。

太郎君は、重複しないような0から9までの数字から 4つ 二郎君に提示し、
二郎君は心の中で思い浮かべた数字が、提示された4つの数字の中にあれば YES 、
無ければ NO と答えます。
これを1ターンとし、次のターンにまた太郎君は4つの数字を提示することを繰り返します。
前に出した数字と同じ数字を提示しても構いません。

入力に太郎君が提示した数字と、二郎君の答えが与えられるので、
二郎君が思い浮かべたであろう数字を出力してください。
必ず出力する数字が1つと確定できるような入力が与えられます。

-----問題ここまで----- */
/* -----解説等-----

yes -> 現れていない数字を候補から外す
no  -> 現れている数字を候補から外す

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI cndt(10, 1);
	FOR(i, 0, N) {
		set<int>s;
		FOR(k, 0, 4) {
			int a; cin >> a;
			s.insert(a);
		}
		string str; cin >> str;
		if (str == "YES") {
			FOR(k, 0, 10) {
				if (!s.count(k))cndt[k] = 0;
			}
		}
		else {
			FOR(k, 0, 10) {
				if (s.count(k))cndt[k] = 0;
			}
		}
	}
	FOR(k, 0, 10) {
		if (cndt[k])ans = k;
	}
	cout << ans << "\n";

	return 0;
}
