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

/* -----  2018/04/08  Problem: yukicoder 012  / Link: http://yukicoder.me/problems/no/012  ----- */
/* ------問題------

'0'から'9'までの数字が重複せずN個与えられる。

次に、1以上5000000以下の範囲からK以上L以下の範囲を選ぶ。
K以上L以下の範囲から素数のみをすべて取り出す。
すべての素数について使われている数字を調べる。
例えば、K以上L以下の範囲で10以上20以下の範囲を選んだとき、
すべての素数は"11"、"13"、"17"、"19"の4つ。
使われている数字は'1'と'3'と'7'と'9'の4つである。
この使われている数字と最初に与えられた数字を等しくしたい。
（すべて使われないといけない）
この時のKとLの差L−Kの最大値を求めよ。
そのような場合がなければ−1を答えとせよ。

以下は無効な例
与えられた数字が[3,5,7]の場合
4以上7以下の範囲での素数は 5,7となるので3が含まれてないので無効な範囲である。
2以上10以下の範囲での素数は 2,3,5,7となるので2が余計に含まれており無効な範囲である。

この場合、「3以上7以下」や「3以上10以下」などが有効な範囲である。

-----問題ここまで----- */
/* -----解説等-----

しゃくとりすればよく、
右側一つ伸ばして、左側を条件を満たすまで縮めれば良い。

----解説ここまで---- */
#define primeN 5000006 
bool prime[primeN + 1];// 外部だとハッシュ表みたいになる
void make_prime() {
	FOR(i, 0, primeN + 1) {
		prime[i] = 1;
	}prime[0] = prime[1] = 0;

	for (int i = 2; i <= primeN; i++) {
		if (prime[i]) {
			for (int j = i * 2; j <= primeN; j += i)
				prime[j] = 0;
		}
	}
}
#undef primeN 

LL N;

LL ans = 0LL;

void change(VI& cnt, int n, int add) {
	while (n) {
		cnt[n % 10]+=add;
		n /= 10;
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	VI mustuse(10, 0);
	FOR(i, 0, N) {
		cin >> a[i];
		mustuse[a[i]] = 1;
	}
	make_prime();
	int i = 1; int j = 1;
	VI usecnt(10, 0);
	ans = -1;
	while (j <= 5000000) {
		if (prime[j]) {// 右をのばす
			change(usecnt, j, 1);
		}

		bool much = 0;
		do{
			FOR(k, 0, 10) {// 条件を満たすまで縮める
				if (!mustuse[k] && usecnt[k]) {
					much = 1;
				}
			}
			if (much) {
				while (!prime[i] && i < j)i++;
				change(usecnt, i, -1);
				i++;
			}
		} while (much && i<j);

		// 少なくとも余分な数字がはいのでここで完全なら
		bool ok = 1;
		FOR(k, 0, 10) {
			if (mustuse[k] && !usecnt[k]) ok = 0;
		}
		if (ok) {
			ans =max((int)ans,j-i );
		}

		j++;
	}

	cout << ans << "\n";

	return 0;
}
