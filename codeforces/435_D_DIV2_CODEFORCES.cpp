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


/* -----  2017/09/19  Problem: CodeForces435 D div2 / Link: http:codeforces.com/contest/862/problem/D ----- */
/* ------–â‘è------



-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



----‰ðà‚±‚±‚Ü‚Å---- */


int N;

LL ans = 0LL;

void solve(int N) {//NŒ…‚É‚Â‚¢‚Ä“ñ•ª’Tõ
	int zero, one;
	int sa;
	string s = "";
	FOR(i, 0, N)s += "1";
	cout << "? " << s << endl;
	cin >> sa;
	int n = N;

	while (1) {
		n /= 2;
		string sc = s;
		FOR(i, 0, n)
			sc[N - 1 - i] = '0';
		cout << "? " << sc << endl;
		int nsa; cin >> nsa;

		if (sa !=nsa) {//‰E‘¤‚É01‚ð”­Œ©
			one = i + 1;
		}
		else if (sa + 1 == nsa) {
			zero = i + 1;
		}

	}
	cout << "! " << zero << " " << one << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	int n = 0;
	while (N) {
		n++;
		N /= 2;
	}
	//debug(n);
	solve(n);
	return 0;
}