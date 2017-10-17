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

/* -----  2017/10/17  Problem: Uva 10114  / Link:   ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

.

----解説ここまで---- */

LL N;

LL ans = 0LL;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int loanDur, nRec;
	double downPayment, loan, decP[101];

	while (true) {
		cin >> loanDur >> downPayment >> loan >> nRec;
		if (loanDur < 0)
			break;

		int m;
		double p;
		while (nRec--) {
			cin >> m >> p;
			for (int i = m; i < 101; i++)
				decP[i] = p;
		}

		int now = 0;
		double monthlyPayment = loan / loanDur;
		double curVal = (loan + downPayment) * (1 - decP[0]);
		double curLoan = loan;
		while (curVal < curLoan) {
			now++;
			curLoan -= monthlyPayment;
			curVal = curVal * (1 - decP[now]);
		}

		cout << now << " month";
		if (now != 1)
			cout << "s";
		cout << endl;
	}

	return 0;
}