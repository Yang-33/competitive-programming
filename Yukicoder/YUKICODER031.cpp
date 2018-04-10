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
const int INF = 1e9;                          const LL LINF = 1e18;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/10  Problem: yukicoder 031  / Link: http://yukicoder.me/problems/no/031  ----- */
/* ------問題------

ミックスジュースが切れました。
ミックスジュースの原材料の表示は、順番に、果物 1，果物 2，…，果物 N となっています。
既存のそれぞれの果物の100%ジュースを混ぜてミックスジュースを V リットルだけ作りたいです。
果物 k の100%ジュースは 1 リットルパックのみが売られていて、1 パックあたり Ck 円です。
V リットルのミックスジュースを、原材料の表示を変更することなく作るための、最小コストを求めるプログラムを書いてください。
つまり、ミックスジュースにおいて果物 k が占める割合 pk は p1≥p2≥⋯≥pN となる必要があり、更に、使われない果物があってもいけません。
1 リットルパックを買い、その一部のみを使用することも可能です。

-----問題ここまで----- */
/* -----解説等-----

p1≧p2...みたいな制約は、p3を選択したいときはp1~p3をすべて購入しなければならないということになる。
したがってこの問題は以下のように言い換えられる。

cost[i]:= [1:i]を使用するのにかかるコストとして、
長さi(0<i≦N≦10^2)の線分があり、これのコストはcost[i]である。
長さV以上(≦10^9)の線分を作るのに必要な最低コストは?
ただし必ずcost[N]は使用する。

一見DPでできそうだけど、O(NV)かかってしまう。
そこで線分の長さに着目すると、Vが大きいときにある程度はcost[i]が小さい線分を選択し、最後V以下の線分については最適値を当てはめなければならないことになる。
ある程度貪欲パートがつくことで、O(N*N*MAX_L)まで計算量を落とすことができ、これは簡単な組合せで解ける。

----解説ここまで---- */


LL solve(LL left, VL& a) {
	// left リットルつくるときにかかる最小コスト、ただしany i, a[i]>=a[i+1]
	int N = SZ(a);
	VL sum(N + 1, 0);
	FOR(i, 0, N) {
		sum[i + 1] = sum[i] + a[i];
	}

	VL dp(10001, LINF);
	dp[0] = 0;
	FOR(i, 1, N + 1) {
		FOR(j, 0, 10001) {
			if (i + j <= 10000)
				dp[i + j] = min(dp[i + j], dp[j] + sum[i]);
		}
	}

	LL ret = LINF;
	FOR(i, 1, N + 1) {
		FOR(l, 0, 10001) {
			if (left - l >= 0 && (left - l) % i == 0) {
				int backet = (left - l) / i;
				ret = min(ret, dp[l] + sum[i] * backet);
			}
		}

	}


	return ret; // min state{left L作るのに必要なコスト}
}

LL N, V;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> V;
	VL a(N);
	LL sum = 0;
	FOR(i, 0, N) {
		cin >> a[i];
		sum += a[i];
	}
	if (N >= V) {
		cout << sum << endl;
	}
	else {
		cout << sum + solve(V - N, a) << endl;
	}


	return 0;
}
