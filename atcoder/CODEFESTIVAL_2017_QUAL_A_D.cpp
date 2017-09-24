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

/* -----  2017/09/23  Problem: codefestival_2017_qual_a_d  / Link:   ----- */
/* ------–â‘è------



-----–â‘è‚±‚±‚Ü‚Å----- */
/* -----‰ðà“™-----



----‰ðà‚±‚±‚Ü‚Å---- */

LL H, W, D;

LL ans = 0LL;
string num = "0123";
string alpha = "RYGB";

//void solve_even1(VS &a, int s, int t) {
//	int c = ans % 4;
//	ans++;
//	for (int i = s; i < H; i += D) {//Žl•ûŒü‚Ì‚Ý
//		for (int j = t; j < W; j += D) {
//			if (j - D >= 0 && a[i][j - D] != '.') {
//				a[i][j] = num[(a[i][j - D] - '0' + 1) % 4];
//			}
//
//			else if (a[i][j] == '.') {
//				a[i][j] = num[c];
//			}
//		}
//		c = (c + 1) % 4;
//	}
//	//ŠÔ‚É–„‚Ü‚é‚â‚Â
//	for (int i = D / 2 + s; i < H; i += D) {
//		for (int j = D / 2 + t; j < W; j += D) {
//			if (j - D >= 0 && a[i][j - D] != '.') {
//				a[i][j] = num[(a[i][j - D] - '0' + 1) % 4];
//			}
//			else {
//				if (i - D / 2 >= 0 && j - D / 2 >= 0)a[i][j] = num[(a[i - D / 2][j - D / 2] - '0' + 3) % 4];
//				else if (i - D / 2 >= 0 && j + D / 2 < W)a[i][j] = num[(a[i - D / 2][j + D / 2] - '0' + 2) % 4];
//				else if (i + D / 2 < H && j - D / 2 >= 0)a[i][j] = num[(a[i + D / 2][j - D / 2] - '0' + 2) % 4];
//				else if (i + D / 2 < H  && j + D / 2 < W)a[i][j] = num[(a[i + D / 2][j + D / 2] - '0' + 1) % 4];
//			}
//		}
//	}
//
//}

void solve_even2(VS &a, int s, int t) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			int x = i + j + 1000;
			int y = i - j + 1000;
			x /= D;
			y /= D;
			if (x % 2 == 0 && y % 2 == 0) { a[i][j] = '0'; }
			if (x % 2 == 0 && y % 2 == 1) { a[i][j] = '1'; }
			if (x % 2 == 1 && y % 2 == 0) { a[i][j] = '2'; }
			if (x % 2 == 1 && y % 2 == 1) { a[i][j] = '3'; }
		}
		//cout << endl;
	}
}
void solve_odd(VS &a, int s, int t) {
	int c = ans % 4;
	ans++;
	for (int i = s; i < H; i += D) {//Žl•ûŒü‚Ì‚Ý
		for (int j = t; j < W; j += D) {
			if (j - D >= 0 && a[i][j - D] != '.') {
				a[i][j] = num[(a[i][j - D] - '0' + 1) % 4];
			}

			else if (a[i][j] == '.') {
				a[i][j] = num[c];
			}
		}
		c = (c + 1) % 4;
	}
	for (int i = 1 + s; i < H; i++) {//¶‰º‚É
		for (int j = 0 + t; j < W - 1; j += D) {
			if (a[i][j] == '.'&&a[i - 1][j + 1] != '.')a[i][j] = a[i - 1][j + 1];
		}
	}
	for (int i = 1 + s; i < H; i++) {//‰E‰º‚É
		for (int j = 1 + t; j < W; j += D) {
			if (a[i][j] == '.'&&a[i - 1][j - 1] != '.')a[i][j] = a[i - 1][j - 1];
		}
	}


}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> H >> W >> D;
	VS a(H, string(W, '.'));

	if (D % 2 == 0) {//‚±‚Á‚¿‚Åwa
		solve_even2(a, 0, 0);
	}
	else {
		FOR(i, 0, D) {
			FOR(j, 0, D) {
				solve_odd(a, i, j);
				/*FOR(k, 0, H) {
					cout << a[k] << endl;
				}
				LL ss; cin>>ss;*/
			}
		}
	}
	FOR(i, 0, H) {
		FOR(j, 0, W) {
			a[i][j] = alpha[a[i][j]-'0'];
		}
	}
	FOR(i, 0, H) {
		cout << a[i] << endl;
	}

	return 0;
}