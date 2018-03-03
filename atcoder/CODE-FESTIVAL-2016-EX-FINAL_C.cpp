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

/* -----  2018/03/03  Problem: code-festival-2016-ex-final_c / Link: https://cf16-exhibition-final.contest.atcoder.jp/tasks/cf16_exhibition_final_c?lang=en  ----- */
/* ------問題------

チーターと不正者がニムをすることになりました。 このゲームでは、N 個の石の山を使います。 最初に i 番目の山には ai 個の石があります。 チーターが先手で、交互にターンを取ります。 それぞれのターンでは、プレイヤーは一つの山を選び、その山から一個以上の石を取り除きます。 ターンが回ってきたときに操作ができなくなったプレイヤーの負けです。
しかし、ゲームが始まる前に、不正者はチーターがどのような動きをしても必ず勝つことができるように少し不正をすることにしました。 それぞれの山から、不正者は 0 個または 1 個の石を取り除き、ゲームが始まる前に食べます。 不正者が必ず勝てるようにする方法が複数通りある場合は、食べる石の個数を最小にするようにしたいです。
不正者が食べる石の個数を求めてください。 不正をしても不正者が必ず勝つようにできない場合は、-1 を出力してください。

-----問題ここまで----- */
/* -----解説等-----

すごい時間がかかった
まず可能な操作は現在の数字に対して 何もしないあるいは (ゲーム値)^(a[i])^(a[i]-1)である。
何も考えないとより良い方法としてゲーム値の2進数表現でのビットが立っている場所をたくさん0にできそうだが、それは嘘。
というのはこの操作は最下位ビットを0にする操作だからである。
したがってa[i]の最下位bitを0にできるようになったので各桁について愚直にやっていけばよい

----解説ここまで---- */

LL N;

LL ans = 0LL;



int popcount2(int x) {//二進数中のbitが1の数
	int ret = 0;
	while (x) {
		x &= x - 1;
		++ret;
	}
	return ret;
}

string to_binString(unsigned int val) //二進数表示
{
	const int size = 30;
	int index = size - 1;
	string str(size, '0');
	while (val != 0) {
		if ((val & 1) == 0)  // val は偶数か？
			str[index] = '0';  //  偶数の場合
		else
			str[index] = '1';  //  奇数の場合
		val >>= 1, index--;
	}
	return str;
}
void print_bin(int a) {
	cout << to_binString(a) << endl;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);



	cin >> N;
	VI a(N);
	VI cnt(31, 0);
	LL res = 0;

	FOR(i, 0, N) {
		cin >> a[i];
		res ^= a[i];
		cnt[popcount2((a[i] & -a[i]) - 1)]++;
	}

	debug(res);
	FORR(i, 30, 0 - 1) {
		if (res &(1 << i)) {
			if (cnt[i]) {
				res ^= (1 << (i + 1)) - 1;
				//debug(res);
				ans++;
			}
			else {
				break;
			}
		}
	}
	if (res)ans = -1;

	cout << ans << "\n";


	return 0;
}
