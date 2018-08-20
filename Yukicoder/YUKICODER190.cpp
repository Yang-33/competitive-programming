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

/* -----  2018/07/30  Problem: yukicoder 190  / Link: http://yukicoder.me/problems/no/190  ----- */
/* ------問題------

kamipeipaa君は理系学生なので、実験が大好きです。今日はある湿気を持った２つの試料を合成する実験をしています。
kamipeipaa君は2N個の試料を持っています。i番目の試料の湿気は整数Aiで表されます。これらのうち2つを選んで合成するという作業をN回繰り返します。合成された物質の湿気は合成に用いた2つの試料の湿気の和で表されます。合成後の物質の湿気が負のときDry、正のときWet、ゼロのときはMoistと呼ばれます。合成後の物質は危険なので使ってはいけません。なお、当然のことながら合成に用いた試料はなくなります。

kamipeipaa君はこれから実験を行いますが、合成結果としてDryなもの、Wetなもの、Moistなものを最大どれだけ作ることが可能か気になっています。kamipeipaa君に教えてあげてください。

-----問題ここまで----- */
/* -----解説等-----

まずsortをする。
a[i]+a[j]==0は簡単。
a[i]+a[j]>0について、マイナスのものを考える。a[i]<0として、|a[i]|<|a[j]|なら採用し、
そうでないならiを捨てて次へ進む。これは以降jを他に選択しても最良な選択にならないため。
これを負についてもやればよい。
したがって線形でできる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;  cin >> N;
	N *= 2;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	SORT(a);
	auto dry = [&N](const VL& a) {
		int i = N - 1;
		int j = 0;
		int ret = 0;
		for (;j<i;) {
			if (a[i] + a[j] < 0) {
				ret++;
				i--; j++;
			}
			else {
				i--;
			}

		}
		return ret;
	};
	auto wet = [&N](const VL& a) {
		int i = N - 1;
		int j = 0;
		int ret = 0;
		for (; j<i;) {
			if (a[i] + a[j] > 0) {
				ret++;
				i--; j++;
			}
			else {
				j++;
			}

		}
		return ret;
	};
	auto moist = [&N](const VL& a) {
		int ret = 0;
		VL b(1e5 + 1, 0);
		int zero = 0;
		FOR(i, 0, N) {
			if (a[i] == 0)zero++;
			else if (a[i] < 0)b[-a[i]]++;
			else {
				if (b[a[i]]) {
					ret++;
					b[a[i]]--;
				}
			}
		}
		ret += zero / 2;
		return ret;
	};

	cout << dry(a) << " " << wet(a) << " " << moist(a) << endl;

	return 0;
}
