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

/* -----  2018/04/23  Problem: yukicoder 103  / Link: http://yukicoder.me/problems/no/103  ----- */
/* ------問題------

ちょっと前に素因数を習ったばかりのAliceとBobが再び数字に関するゲームをします。

ゲームの内容は以下のとおりです。
・N個の整数が与えられます。M1 M2 …Mi… MNと表します。
・その番のプレイヤーは、N個の整数のうち、i番目の数字を選び「Miの素因数」のどれかで割り、i番目の数をその商で更新します。
・この時、同じ素因数であれば、割り切れる限り1回以上、2回まで割ることができます。
例えば、i番目の値が24だった場合、その素因数は 2,3 (24=2×2×2×3) であるため 24を2で2回割った数の6に更新することができます。
・以上の手順をプレイヤーを入れ替え繰り返し、N個のすべての数を1にしたプレイヤーが勝ちです。


まずAliceが先攻となりゲームを始めます。
この時、どちらも最善を尽くすと考えたとき、N個の整数が与えられた時の勝者を求めてください。

-----問題ここまで----- */
/* -----解説等-----

各数についてgrundy数を求めれば良い。
各数は素因数に対応した山を持つと見ると、(石の数)%3が素因数に対応したgrundy数になる。

----解説ここまで---- */

LL N;

LL ans = 0LL;

void div(int n, map<int,int> &cnt) {
	for (int i = 2; i*i <= n; i++) {
		while (n%i == 0) {
			cnt[i]++;
			n /= i;
		}
	}
	if(n>1)cnt[n]++;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	
	FOR(i, 0, N) {
		int a; cin >> a;
		map<int, int>cnt;
		div(a, cnt);
		for (auto it : cnt) {
			ans ^= it.second % 3;
		}
	}

	cout << (ans?"Alice":"Bob") << "\n";

	return 0;
}
