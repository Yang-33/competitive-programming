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

/* -----  2018/02/15  Problem: 057_abc_d / Link: https://abc057.contest.atcoder.jp/tasks/abc057_d?lang=en  ----- */
/* ------問題------

N 個の品物が与えられます。
i 番目の品物の価値は vi(1≦i≦N) です。
これらの品物から、A 個以上、B 個以下を選ばなければなりません。
この制約下において、選んだ品物の価値の平均の最大値を求めてください。
また、選んだ品物の平均が最大となるような品物の選び方が何通りあるかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

選択区間は二種類しかなく、これを場合分けする
1:全部A->たくさん選べるね
2:そうではない->最小の要素の選択

----解説ここまで---- */

#define nCk_MAX 100
long long  comb[nCk_MAX + 1][nCk_MAX + 1];
/* nCk を求める */
void calcomb() {
	int  i, j;
	for (i = 0; i <= nCk_MAX; i++) {
		for (j = 0; j <= i; j++) {
			if (j == 0 || j == i)
				comb[i][j] = 1;
			else
				comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
		}
	}
}
#undef nCk_MAX
LL N,A,B;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>A>>B;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}

	calcomb();
	double ave;
	SORT(a);
	reverse(ALL(a));
	if (a[0] == a[A - 1]) {
		int cnt = 0;
		FOR(i, 0, N) {
			if (a[0] == a[i])cnt++;
		}
		FOR(i, A, min((LL)cnt,B)+ 1) {
			ans += comb[cnt][i];
		}
		ave = a[0];
	}
	else {
		// A個が良いが、最後の選択ができる
		int cnt = 0;
		FOR(i, 0, N) {
			if (a[A - 1] == a[i])cnt++;
		}
		int cnt2 = 0;
		LL sum = 0;
		FOR(i, 0, A) {
			sum += a[i];
			if (a[A - 1] == a[i])cnt2++;
		}
		ans = comb[cnt][cnt2];
		ave = (double)sum / A;

	}
	cout <<fixed<<setprecision(10)<< ave << endl;
	cout << ans << "\n";

	return 0;
}
