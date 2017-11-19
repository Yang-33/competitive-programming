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

/* -----  2017/11/19  Problem: CODEFESRIVAL2014_QUAL_A_D_2 / Link: https://code-festival-2014-quala.contest.atcoder.jp/tasks/code_festival_qualA_d  ----- */
/* ------問題------

高橋君の電卓は壊れてしまっています。 K 種類より多くの種類の数字を打つと、電卓が壊れてしまいます。
整数 A が与えられます。高橋君は、この整数を入力したいです。 ですが、普通にその整数を打とうとすると、電卓が壊れてしまうことがあるため、 電卓が壊れない範囲で、出来るだけ整数 A との差の大きさが小さい整数を入力します。
この時、高橋君が入力する整数と、整数 A の差の大きさがいくつになるかを出力しなさい。

-----問題ここまで----- */
/* -----解説等-----

貪欲さん…

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string a;
	int k;
	cin >> a >> k;
	int N = a.size();

	LL ret = LLONG_MAX;
	for (int i = 1; i < 1024; ++i) {
		bitset<10> digitbit(i);
		if (k < (int)digitbit.count()) { continue; }

		int DigitMin = 0;
		int DigitMax = 9;
		while (!digitbit[DigitMin])
			++DigitMin;
		while (!digitbit[DigitMax])
			--DigitMax;

		bool match = true;
		for (int j = 0; j < N; ++j) {
			for (int num = 0; num < 10; ++num) {
				if (!digitbit[num]) { continue; }

				LL x = num;
				if (num <= a[j] - '0') {
					for (int l = 0; l < N - j - 1; ++l) {
						x *= 10;
						x += DigitMax;
					}
				}
				else {
					for (int l = 0; l < N - j - 1; ++l) {
						x *= 10;
						x += DigitMin;
					}
				}
				ret = min(ret, abs(stoll(a) - x));
				if (match)
					ret = min(ret, abs(stoll(a.substr(j)) - x));
			}
			if (!digitbit[a[j] - '0'])
				match = false;
		}
	}

	cout << ret << endl;

	return 0;
}
