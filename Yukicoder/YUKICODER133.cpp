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

/* -----  2018/05/02  Problem: yukicoder 133  / Link: http://yukicoder.me/problems/no/133  ----- */
/* ------問題------

君とB君はカードゲームが好きである。
カードゲームは1から2*Nまでの数字が1つずつ書かれた2*N枚のカードで行う。
A君とB君にはそれぞれN枚ずつカードが配られる。
ゲームは簡単である。
自由にカードを1枚出して数字の大きい方が1試合の勝ちである。
試合で1度出したカードは2度使えない。
全部でN試合し勝ち数が多いほうをゲームの勝ちとする。
A君とB君の勝ち数が等しければゲームは引き分けとなる。
カードはすでに配られた状態である。
N試合が終わったときに、A君がゲームに勝つ確率を計算せよ。
お互い思考性がなくランダムでカードを出すとする。

-----問題ここまで----- */
/* -----解説等-----

適当にやる
next_permutationは一個でもいいかも？

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI a(N), b(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	FOR(i, 0, N) {
		cin >> b[i];
	}
	double ans = 0;
	int matchcnt = 0;
	SORT(a);
	do {
		SORT(b);
		do {
			matchcnt++;
			int A = 0;
			int B = 0;

			FOR(i, 0, N) {
				if (a[i] > b[i])A++;
				else B++;
			}
			if (A>B)ans++;
		} while (next_permutation(ALL(b)));
	} while (next_permutation(ALL(a)));
	ans = ans / matchcnt;
	cout <<fixed<<setprecision(10)<< ans << "\n";

	return 0;
}
