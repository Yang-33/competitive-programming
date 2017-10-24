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

/* -----  2017/10/20  Problem: uva 00344  / Link:   ----- */
/* ------問題------

Nページまでに出てくるローマ数字の総数

-----問題ここまで----- */
/* -----解説等-----

規則性があるのでmodulo,をとる

----解説ここまで---- */

LL N;
int num1[10];
int num5[10];
int num10[100];
int num50[100];
int num100[1000];
void f() {
	FOR(i, 1, 10) {// I
		num1[i] += num1[i - 1] + ((i == 4 || i == 9) ? 1 : (i == 5 ? 0 : i % 5));
	}
	FOR(i, 1, 10) {// V
		num5[i] += num5[i - 1]+((i>=4&&i<=8)?1:0);
	}
	FOR(i, 1, 100) {// X
		num10[i] += num10[i - 1] + ((i/10==4|| i/10==9) ? 1 : (i/10==5 ? 0 : (i/10) % 5));
		if (i % 10 == 9)num10[i]++;
	}
	FOR(i,1,100) {// L 50   40 50 60 70 80 
		num50[i]+=num50[i-1] + ((i/10 >= 4 && i/10 <= 8) ? 1 : 0);
	}
	FOR(i, 1, 1000) { // C 100    90XC 100(1),2,3,1,0,1,2,3,1
		num100[i] += num100[i - 1];
		if ((i >= 90 && i <= 199) || (i / 100) == 4 ||(i/100==6) ||(i / 100 == 9))num100[i]++;
		if (i / 100 == 2 || i / 100 == 7)num100[i]++;
		if ((i / 100) % 5 == 3)num100[i]++;
	}
}
// 1 5 10 50 100
string solve(int id) {
	string ans;
	ans = to_string(id) + ": " +to_string((id/10)*num1[9]+num1[id%10])+" i, " ;
	ans += to_string((id/10)*num5[9]+num5[id%10]) + " v, ";
	ans += to_string((id/100)*num10[99]+num10[id%100]) + " x, ";
	ans += to_string((id/100)*num50[99]+num50[id%100]) + " l, ";
	ans += to_string((id/1000)*num100[999]+num100[id%1000]) + " c";
	return ans;

}

int main() {

	f();

	while (cin >> N, N) {

		cout << solve(N) << endl;
	}

	return 0;
}