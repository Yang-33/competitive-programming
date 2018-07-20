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

/* -----  2018/07/23  Problem: AOJ 0301 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0301  ----- */
/* ------問題------

アカベ高校では、毎年全校生徒が参加するゲームを行っています。まず、校庭に N 人の全校生徒が円形に並びます。図のように、各生徒は 0 から N-1 までの番号が書かれたゼッケンを付けています。
ゲームではバトンを１本使い、最初はゼッケン 0 番の生徒がバトンを持っています。そこから、以下の手順を M 回繰り返します。まず、現時点でバトンを持っている生徒が適当な正の整数 a を宣言します。a が偶数のときは時計回り、奇数のときは反時計回りに隣の生徒にバトンを渡していき、a 番目にバトンを受け取った生徒が脱落します。脱落した生徒は、時計回りで隣の生徒にバトンを渡し、円から抜けます。
ゲームが終わった後に円に残った生徒は、放課後の掃除が１年間免除されます。しかし、ここ数年は生徒数が増えたため、全校生徒を集めるのが難しくなってきています。そこで、競技プログラミング部のあなたは、シミュレーションで掃除が免除される生徒を求めるプログラムを作成するよう頼まれました。
指定した生徒が掃除を免除されているかどうかを質問したとき、それに答えるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

BIT.lower_boundって知ってますか？という問題
僕は知っているので、動的に区間和を変更して、ある点からのkthを求めることが可能。
いい練習になりそう

----解説ここまで---- */

template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;

template<typename type>
struct BIT0 { // 0-index
	int N;
	int nn;
	vector<type> data;
	//動的はmap<int?,type>data
	BIT0(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		i++;
		for (int x = i; x < N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [0,i)
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r)
	type sum(int l, int r) {
		return sum(r) - sum(l);
	}

	/*	BIT 上で二分探索
	二分木の分かれ方に従って二分探索する
	左の子に進むか右の子に進むかを知るためには，左の子の範囲の和がわかればよい
	ちょうど BIT がもっている情報，O(1) 時間で得られる
	a[1] + a[2] + a[3] + ... a[x] >= w となる最小のxを返す、ただしa[i] >= 0	*/

	int lower_bound(type w) {//  w≦[0,x]以上となる最小のindex,x
		if (w <= 0) return 0;
		int x = 0;
		for (int k = nn; k > 0; k /= 2) {
			if (x + k <= N && data[x + k] < w) {
				w -= data[x + k];
				x += k;
			}
		}
		return x;
	}
};

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int N, M, Q;
	cin >> N >> M >> Q;
	V<int>a(M);
	FOR(i, 0, M) {
		cin >> a[i];
	}
	BIT0<int>bit(N);
	FOR(i, 0, N) {
		bit.add(i, 1);
	}
	// 常に右にわたすことに注意
	int button = 0;

	auto buttonPass = [&bit, N](int target) {
		// targetからみて次の増加番号の人にバトンを渡す
		int presum = bit.sum(0, target);// bit[target]は0

		if (bit.sum(target, N)) {//1人でもいる
			return  bit.lower_bound(presum + 1);
		}
		else {
			return bit.lower_bound(1);
		}
	};

	FOR(i, 0, M) {
		int plus = a[i];
		if (plus % 2 == 0) {// 右
			plus %= bit.sum(0, N);
			if (bit.sum(button + 1, N) >= plus) {// 渡せる
				int sum = bit.sum(0, button + 1);
				int target = bit.lower_bound(sum + plus);
				bit.add(target, -1);
				// バトンをtargetの右に渡す
				button = buttonPass(target);
			}
			else { // またいで渡す
				plus -= bit.sum(button + 1, N);
				button = 0;
				int target = bit.lower_bound(plus);
				bit.add(target, -1);

				// バトンをtargetの右に渡す
				button = buttonPass(target);
			}
		}
		else { //左
			plus %= bit.sum(0, N);
			if (bit.sum(0, button) >= plus) {// ぽい
				int sum = bit.sum(0, button);
				int target = bit.lower_bound(sum - plus + 1);
				bit.add(target, -1);
				//バトンをtargetの右に渡す
				button = buttonPass(target);

			}
			else {// ぽいではない
				plus -= bit.sum(0, button);
				button = N - 1;
				int sum = bit.sum(0, button + 1);
				int target = bit.lower_bound(sum - plus + 1);
				bit.add(target, -1);

				//バトンをtargetの右に渡す
				button = buttonPass(target);
			}
		}
	}

	FOR(i, 0, Q) {
		int q; cin >> q;
		cout << bit.sum(q, q + 1) << endl;
		// 1(免除)->存在 or 0
	}
	return 0;
}
