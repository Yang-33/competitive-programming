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

/* -----  2017/10/20  Problem: uva 11616  / Link:   ----- */
/* ------問題------

roma<->number変換

-----問題ここまで----- */
/* -----解説等-----

実装を工夫する！

----解説ここまで---- */

LL N;

LL ans = 0LL;
map<string, string >Map;
int val[13] = { 1,4,5,9,10,40,50,90,100,400,500,900,1000};
string romastr[13] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
void romanum_make() {
	/*FOR(i, 0, 13) {
		cout << val[i] << " " << romastr[i] << endl;
	}*/
	FOR(i, 0, 4000) {
		int n = i;
		string roma;
		for (int p = 12; p >= 0&&n; p--){
			while (n >= val[p]) {
				roma += romastr[p];
				n -= val[p];
			}
		}
		string number = to_string(i);
		//cout << number << " " << roma << endl;
		Map[number] = roma;
		Map[roma] = number;
	}
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	romanum_make();

	string S;
	while (cin >> S) {
		cout << Map[S] << endl;
	}

	return 0;
}