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

/* -----  2018/08/23  Problem: yukicoder 217  / Link: http://yukicoder.me/problems/no/217  ----- */
/* ------問題------

N 行 N 列の魔方陣を1つ作ってください。
一般に N 行 N 列の魔方陣は複数存在しますが、どれでも構いません。

この問題において、 N 行 N 列の魔方陣とは、
1 から N2 までの整数を N 行 N 列に並べたものであって、
各行、各列、及び2つの対角線それぞれについて、そこに並んだ数の総和がいずれも等しくなるもののことをいいます。

-----問題ここまで----- */
/* -----解説等-----

奇数、4の倍数、偶数をwikipediaを見て書く [リンク](http://ja.wikipedia.org/wiki/%E9%AD%94%E6%96%B9%E9%99%A3)

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

	cout << (f ? "TRUE" : "FALSE") << endl;
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


template<class T>
void rotate2dL(vector<vector<T>>& a) { // rorateToL
	vector<vector<T>> res((int)a.size(), vector<T>((int)a[0].size()));
	FOR(i, 0, (int)a.size())FOR(j, 0, (int)a[0].size())res[i][j] = a[j][a[0].size() - i - 1];
	a = res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	//FOR(N, 3, 21) {
		VVI ans = makeMagicSquare(N);
		//checker(ans);
	//}
	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cout << ans[i][j] << " ";
		}cout << endl;
	}

	rotate2dL(ans);

	FOR(i, 0, N) {
		FOR(j, 0, N) {
			cout << ans[i][j] << " ";
		}cout << endl;
	}

	return 0;
}
