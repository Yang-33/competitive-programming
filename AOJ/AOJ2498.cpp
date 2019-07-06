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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/07  Problem: AOJ 2498 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2498  ----- */


void U(vector<string>& R) {
	auto A = R;

	A[0][3] = R[0][2];
	A[1][3] = R[0][3];
	A[1][2] = R[1][3];
	A[0][2] = R[1][2];

	for (int i = 0; i < 4; i++) {
		int to = (i + 3) % 4;
		A[2][to * 2] = R[2][i * 2];
		A[2][to * 2 + 1] = R[2][i * 2 + 1];

	}

	R = A;
}
void D(vector<string>& R) {
	auto A = R;

	A[4][3] = R[4][2];
	A[5][3] = R[4][3];
	A[5][2] = R[5][3];
	A[4][2] = R[5][2];

	for (int i = 0; i < 4; i++) {
		int to = (i + 1) % 4;
		A[3][to * 2] = R[3][i * 2];
		A[3][to * 2 + 1] = R[3][i * 2 + 1];

	}

	R = A;
}
void R(vector<string>& R) {
	auto A = R;

	A[2][5] = R[2][4];
	A[3][5] = R[2][5];
	A[3][4] = R[3][5];
	A[2][4] = R[3][4];


	A[3][3] = R[5][3];
	A[1][3] = R[3][3];
	A[2][6] = R[1][3];
	A[5][3] = R[2][6];

	A[2][3] = R[4][3];
	A[0][3] = R[2][3];
	A[3][6] = R[0][3];
	A[4][3] = R[3][6];

	R = A;
}
void L(vector<string>& R) {
	auto A = R;

	A[2][1] = R[2][0];
	A[3][1] = R[2][1];
	A[3][0] = R[3][1];
	A[2][0] = R[3][0];


	A[3][2] = R[1][2];
	A[5][2] = R[3][2];
	A[2][7] = R[5][2];
	A[1][2] = R[2][7];

	A[2][2] = R[0][2];
	A[4][2] = R[2][2];
	A[3][7] = R[4][2];
	A[0][2] = R[3][7];

	R = A;
}
void F(vector<string>& R) {
	auto A = R;


	A[2][3] = R[2][2];
	A[3][3] = R[2][3];
	A[3][2] = R[3][3];
	A[2][2] = R[3][2];


	A[3][4] = R[1][3];
	A[4][2] = R[3][4];
	A[2][1] = R[4][2];
	A[1][3] = R[2][1];

	A[2][4] = R[1][2];
	A[4][3] = R[2][4];
	A[3][1] = R[4][3];
	A[1][2] = R[3][1];

	R = A;
}
void B(vector<string>& R) {
	auto A = R;

	A[3][7] = R[2][7];
	A[3][6] = R[3][7];
	A[2][6] = R[3][6];
	A[2][7] = R[2][6];


	A[0][3] = R[3][5];
	A[2][0] = R[0][3];
	A[5][2] = R[2][0];
	A[3][5] = R[5][2];

	A[3][0] = R[0][2];
	A[5][3] = R[3][0];
	A[2][5] = R[5][3];
	A[0][2] = R[2][5];

	R = A;
}

int main() {
	string S; cin >> S;

	vector<string> state = {
		"..rr....",
		"..rr....",
		"ggyybbww",
		"ggyybbww",
		"..oo....",
		"..oo....",
	};

	for (auto c : S) {
		switch (c) {
		case 'U':
			U(state);
			break;
		case 'D':
			D(state);
			break;
		case 'F':
			F(state);
			break;
		case 'B':
			B(state);
			break;
		case 'L':
			L(state);
			break;
		case 'R':
			R(state);
			break;
		}
	}
	for (auto vec : state) {
		cout << vec << endl;
	}
}
