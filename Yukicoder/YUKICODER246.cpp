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

/* -----  2018/08/26  Problem: yukicoder 246  / Link: http://yukicoder.me/problems/no/246  ----- */
/* ------問題------

kamipeipaa君は1から109までの範囲に含まれるある整数xが大好きです。しかし、意地悪なのでkamipeipaa君がそれを教えてくれることはありませんでした。
その代わり「xがある整数y以上かどうか」という質問をすることが許されました。kamipeipaa君はその質問に正直に回答することを約束してくれました。
kamipeipaa君は多忙なので100回までしか質問に答えたくありません。100回までの質問でkamipeipaa君が大好きな整数を当ててください。

-----問題ここまで----- */
/* -----解説等-----

二分探索の発想そのもの

----解説ここまで---- */


bool ask(int x) {
	cout << "? " << x << endl;
	bool f; cin >> f;
	return f;
}

int main() {

	int L = 1, R = 1e9 + 1;
	FOR(i, 0, 30) {
		int mid = (L + R) / 2;
		if (ask(mid))L = mid;
		else R = mid;
	}
	int ans = L;
	cout <<"! "<< ans << "\n";

	return 0;
}
