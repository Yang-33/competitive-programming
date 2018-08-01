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

/* -----  2018/07/31  Problem: yukicoder 195  / Link: http://yukicoder.me/problems/no/195  ----- */
/* ------問題------

スーパーフィボナッチ数列を理解したyuki君は、またシンプルなフィボナッチ数列について理解を深めることにした。

今度は正整数A,Bから生成される(A,B)フィボナッチ数列というものを考える。
これは最初の２項がA,Bで、３項目以降は通常のフィボナッチ数列と同様に直前２項の和となっているものである。
厳密に書くと、(A,B)フィボナッチ数列の第k項FA,B(k)は以下の通りである。
- FA,B(1)=A
- FA,B(2)=B
- k≥3のとき、FA,B(k)=FA,B(k−1)+FA,B(k−2)

yuki君が周りを見ると、３つの正整数X,Y,Zが目についた。
(A,B)フィボナッチ数列がこれらX,Y,Zすべてを含む(FA,B(i)=X,FA,B(j)=Y,FA,B(k)=Zとなる正整数i,j,kが存在する)ような正整数A,Bの対を答えよ。
条件を満たす(A,B)の対が複数存在する場合、Aが最小のものを答えよ。Aが最小のものが複数ある場合、その中でBが最小なものを答えよ。
条件を満たす(A,B)の対が存在しない場合、-1を出力せよ。

-----問題ここまで----- */
/* -----解説等-----

F:A,B(k)について、これはフィボナッチ数にA,Bを掛けたものとなっている。
F:A,B(k) = A*Fib(k) + B*Fib(k+1)
よって、x,y,zになるようなfib(i,j,k)を全探索して、方程式を解けば良い。
ただしx=y=zのときはよくわからないので、別で考える。
[解説をみた]
A=1としても問題ない。(らしい)　なぜ
- まずfib()=1,1のときに、A+B=xを考えることになる。B=xもあるので、A=1は確定できる。
- Bは更新されうるので、あとは全探索する。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL X, Y, Z; cin >> X >> Y >> Z;
	set<LL>Se({ X,Y,Z });
	VL Xs(ALL(Se));
	VL FibA(50, 0);
	VL FibB(50, 0);
	FibA[0] = 1, FibA[2] = 1;
	FibB[1] = 1, FibB[2] = 1;
	FOR(i, 3, 50) {
		FibA[i] = FibA[i - 1] + FibA[i - 2];
		FibB[i] = FibB[i - 1] + FibB[i - 2];
	}

	PLL ans = PLL(LINF, LINF);

	if (SZ(Xs) == 1) {
		FOR(i, 1, 50) {
			LL ret = Xs.front() - FibA[i];
			if (ret <= 0)break;
			if (ret%FibB[i] == 0) {
				ans.first = 1;
				ans.second = min(ans.second, ret / FibB[i]);
			}
		}
	}

	else {
		FOR(i, 0, 50) {
			FOR(j, 0, 50) {
				if (i == j)continue;
				FOR(k, 0, 50) {
					LL D = FibB[i] * FibA[j] - FibB[j] * FibA[i];
					LL E = FibA[j] * Xs[0] - FibA[i] * Xs[1];
					if (D < 0)D = -D, E = -E;
					if (E <= 0 || E%D != 0)continue;
					LL B = E / D;
					LL A = 0;
					if (FibA[i] != 0) {
						A = Xs[0] - FibB[i] * B;
						if (A <= 0 || A%FibA[i])continue;
						A /= FibA[i];
					}
					else {
						A = Xs[1] - FibB[j] * B;
						if (A <= 0 || A%FibA[j])continue;
						A /= FibA[j];
					}
					if (SZ(Xs) == 3 && FibA[k] * A + FibB[k] * B == Xs[2]) {
						ans = min(ans, PLL(A, B));
					}
					else if (SZ(Xs) != 3) {
						ans = min(ans, PLL(A, B));
					}
				}
			}
		}

	}
	if (ans.first == LINF) {
		cout << -1 << endl;
	}
	else {
		cout << ans.first << " " << ans.second << endl;
	}
	return 0;
}
