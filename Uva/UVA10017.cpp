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

/* -----  2017/10/20  Problem: Uva 10017  / Link:   ----- */
/* ------問題------

ハノイの塔のシュミレーション

-----問題ここまで----- */
/* -----解説等-----

再帰的にやる

----解説ここまで---- */

int bA[350], bB[350], bC[350];
int posA, posB, posC;
int step;

void print() {
	if (step < 0)return;
	int i;
	printf("A=>");
	FOR(i, 0, posA) {
		if (!i)  printf("  ");
		printf(" %d", bA[i]);
	}
	printf("\nB=>");
	FOR(i, 0, posB) {
		if (!i)  printf("  ");
		printf(" %d", bB[i]);
	}
	printf("\nC=>");
	FOR(i, 0, posC) {
		if (!i)  printf("  ");
		printf(" %d", bC[i]);
	}
	puts("");
	puts("");
	step--;
}
void move(char st, char ed) {
	if (st == 'A' && ed == 'B')
		bB[posB++] = bA[--posA];
	if (st == 'A' && ed == 'C')
		bC[posC++] = bA[--posA];
	if (st == 'B' && ed == 'A')
		bA[posA++] = bB[--posB];
	if (st == 'B' && ed == 'C')
		bC[posC++] = bB[--posB];
	if (st == 'C' && ed == 'A')
		bA[posA++] = bC[--posC];
	if (st == 'C' && ed == 'B')
		bB[posB++] = bC[--posC];
	print();
}
void hanoi(int n, char A, char B, char C) {
	if (step < 0)    return;
	if (n == 1) {
		move(A, C);
		return;
	}
	else {
		hanoi(n - 1, A, C, B);
		move(A, C);
		hanoi(n - 1, B, A, C);
	}
}


int main() {
	int n, cases = 0;
	while (scanf("%d %d", &n, &step), n || step) {
		printf("Problem #%d\n\n", ++cases);
		posA = posB = posC = 0;
		int i;
		for (i = n; i >= 1; i--)
			bA[posA++] = i;
		print();
		hanoi(n, 'A', 'B', 'C');
	}
	return 0;
}