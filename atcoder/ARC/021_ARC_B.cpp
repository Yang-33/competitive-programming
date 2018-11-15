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

/* -----  2018/11/15  Problem: ARC 021 B / Link: http://arc021.contest.atcoder.jp/tasks/arc021_b  ----- */
/* ------問題------

書類には L 個の非負整数 A1，A2，…，AL が書いてありました。これらの数は今や書類には書き残されていません。妹の目的は、これらの数を知ることです。
書類には L 個の非負整数 B1，B2，…，BL が書いてあります。これらの数は書類に書き残されているので知ることができます。
B1，B2，…，BL は、以下の定義で表される数です。

1≦i≦L−1 を満たす整数 i に関して、Bi の値は Ai と Ai+1 を排他的論理和した値に等しい。
BL の値は AL と A1 を排他的論理和した値に等しい。
大変残念なことに場合によっては該当する元の数列が存在しないことや、複数通り存在する場合があります。どうしましょう！

困った妹は、今日の占いのラッキーアイテムが辞書であったことを思い出しました。辞書、じしょ、辞書順…

最終的に、以下のルールを追加することにしました。

該当する元の数列が存在しない場合は、仕方がないので存在しないむねを示す -1 を答えとします。
該当する元の数列が複数存在する場合は、辞書順最小な数列を出力します。
ここで、2 つの数列 S1，S2，…，SL と T1，T2，…，TL に関して、 S1，S2，…，SL が T1，T2，…，TL より辞書順で小さいというのは、以下の条件を満たす場合とします。

ある整数 i (1≦i≦L) に関して、1≦j≦i−1 を満たすどの整数 j に関しても Sj=Tj が成立し、かつ Si<Ti が成立する。
あなたは妹の代わりに上記の条件を満たす数列を出力するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

式変形すると、A1=B1^b2^...^B{N-1}^AN,A1=BN^ANとなる。
当然一緒でないとダメなので、Bの比較を行う。
正しい時を考える。A1を決めると全部決まる。
辞書順最小で良いので、A1=0として、あとは計算して求めるだけでよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;
	cin >> N;
	VL b(N);
	FOR(i, 0, N) {
		cin >> b[i];
	}
	LL B = 0;
	FOR(i, 0, N - 1) {
		B ^= b[i];
	}
	if (B != b.back()) {
		cout << -1 << endl;
	}
	else {
		cout << 0 << endl;
		LL val = 0;
		FOR(i, 1, N) {
			cout << (val ^ b[i - 1]) << endl;
			val ^= b[i - 1];
		}

	}


	return 0;
}