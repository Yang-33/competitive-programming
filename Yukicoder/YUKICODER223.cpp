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

/* -----  2018/08/23  Problem: yukicoder 223  / Link: http://yukicoder.me/problems/no/223  ----- */
/* ------問題------

N 行 N 列の魔方陣を1つ作ってください。
但し、 Y 行目 X 列目の数は Z にしてください。

この問題において、 N 行 N 列の魔方陣とは、
1 から N2 までの整数1つずつを N 行 N 列に並べたものであって、
各行、各列、及び2つの対角線それぞれについて、そこに並べた数の総和がいずれも等しくなるもののことをいいます。

N=4,8,16しかない

-----問題ここまで----- */
/* -----解説等-----

証明できてなさそうだけど解法↓
なんか全体に1を加えたり引いたりしても問題ない。
xorgaussみたいなことをしても問題ない気がしてくる
xorをとったら関係は正しかったので、値を調整した(1-index->0-index->1-indexをした)

----解説ここまで---- */


void rotate2d(VVI& a) { // rorateToR
	VVI res(a.size(), VI(a[0].size()));
	FOR(i, 0, a.size())	FOR(j, 0, a[0].size())res[j][a[0].size() - i - 1] = a[i][j];
	a = res;
}
void checker(VVI a) {
	int n = (int)a.size();
	int rightval = n * (n*n + 1) / 2;
	int f = 1;
	FOR(_, 0, 2) {
		FOR(i, 0, n) {
			f &= (rightval == accumulate(ALL(a[i]), 0));
		}
		int sum = 0;
		FOR(i, 0, n) {
			sum += a[i][i];
		}
		f &= (sum == rightval);
		rotate2d(a);
	}
	assert(f);
	//	cout << (f ? "TRUE" : "FALSE") << endl;
}


void odd(VVI &a, int N) { // 斜めにやる
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			int x = N / 2 - i + j, y = j * 2 - x;
			x = (x + N) % N;
			y = (y + N) % N;
			a[y][x] = i * N + j + 1;
		}
	}
}

void four(VVI &a, int N) {
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			if ((i - j + N) % 4 == 0 || (i + j) % 4 == 3) a[i][j] = i * N + j + 1;
			else a[i][j] = N * N - (i*N + j);
		}
	}
}

void even(VVI &a, int N) {
	const int d[3][2][2] = { { { 4,1 },{ 2,3 } },{ { 1,4 },{ 2,3 } },{ { 1,4 },{ 3,2 } } };
	VVI b(N / 2, VI(N / 2));
	odd(b, N / 2);
	FOR(i, 0, N / 2)FOR(j, 0, N / 2) {
		b[i][j] = (b[i][j] - 1) * 4;
		int p = 0;
		if (i > N / 2 / 2 + 1) p = 2;
		if (i == N / 2 / 2 + 1) p = 1;
		if (i == N / 2 / 2 + 1 && j == N / 2 / 2) p = 0;
		if (i == N / 2 / 2 && j == N / 2 / 2) p = 1;
		FOR(ai, 0, 2)FOR(aj, 0, 2) {
			a[i * 2 + ai][j * 2 + aj] = b[i][j] + d[p][ai][aj];
		}
	}
}

VVI makeMagicSquare(int N) {
	VVI a(N, VI(N));
	if (N & 1)odd(a, N);
	else if (N % 4 == 0)four(a, N);
	else even(a, N);
	return a;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	int X, Y, Z; cin >> X >> Y >> Z;

	VVI ans = makeMagicSquare(N);
	//FOR(k, 1, N+1) {
	//	int shif = k-1;
	//	int twos = pow(2, k);
	//	debug(shif); debug(twos);
	//	FOR(i, 0, N) {
	//		FOR(j, 0, N) {
	//			cout << (((ans[i][j]) %twos)>>shif) << " ";
	//		}cout << endl;
	//	}

	//}

	FOR(i, 0, N) { FOR(j, 0, N) { --ans[i][j]; } }

	X--, Y--, Z--;
	int xorVal = ans[Y][X] ^ Z;
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			ans[i][j] ^= xorVal, ans[i][j]++;
		}
	}
	checker(ans);
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cout << ans[i][j] << " ";
		}cout << endl;
	}

	return 0;
}