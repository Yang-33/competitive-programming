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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/05  Problem: ARC 047 C / Link: http://arc047.contest.atcoder.jp/tasks/arc047_c  ----- */
/* ------問題------

高橋語には N 種類の文字があります。
この問題では便宜上、各文字に辞書順で小さい順に 1 ～ N の整数を割り振って扱うことにします。
高橋語の単語は全て N 文字からなり、N 種類の文字が全てちょうど 1 個ずつ含まれます。 また、そのような文字列は全て高橋語の単語です。
つまり、高橋語の単語は N! 個あります。
ある N 以下の正の整数 K が与えられるので、高橋語の単語の中で辞書順で小さい方から N!÷K 番目の単語を求めてください。

-----問題ここまで----- */
/* -----解説等-----

M!を大きい方から順に見ていけば良い。具体的には、最初の桁は、N!/K に対して、> p1(N-1)!が存在して、p1+1がその桁の数字になる。
次は(N-2)!をみればいいので、残った数にN-1をかけて、同様にp2を選択すれば良い。選択する数字は今まで使ってないもののうち、小さいものからp2+1番目のモノ。
これはBITを簡易setにするいつもので可能。
よって解けた。

これ本番20人はウソでは…??8thですが…

----解説ここまで---- */

template<typename type>
struct BIT {
	int N;
	int nn;
	vector<type> data;
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) {
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}

	int lower_bound(type w) {
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k <= N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x + 1;
	}
};



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, K; cin >> N >> K;
	BIT<int> bit1index(N + 1);
	FOR(i, 1, N + 1) {
		bit1index.add(i, 1);
	}
	LL s=1;
	FOR(i, 0, N) {
		s *= (N - i);
		int p = s / K;
		if (s == p * K) {
			p--;
		}
		s -= p * K;
		p++;
		int digit = bit1index.lower_bound(p);
		cout << digit << endl;
		bit1index.add(digit, -1);
	}

	return 0;
}
