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

/* -----  2017/10/25  Problem: AOJ 1518  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1518&lang=jp ----- */
/* ------問題------

あなたは、集合好きな友人Aと一風変わったゲームをしてみる事にした。
n個の要素からなる重複が許される非負の整数の集合Sが与えられる。集合Sに含まれる各要素は非負のpi進数である。集合Sに対して 以下のStep1~3を1つのターンとして、あなたと相手の二人が交互にターンを繰り返す。各ターンではこの番号の順に操作を行う。
Step 1: 集合Sに含まれる全ての要素を一度取り除き、その取り除いた各要素を2進数に変換して、0を消して1が1つ以上連続する部分に分割し、その分割された部分を全て集合Sに加える。
Step 2: このとき集合Sが空になっていたならば、現在このターンをプレイしているプレイヤーは負ける。
Step 3: 集合Sに含まれる要素aを1つ選び、そのaから 1 ≤ x ≤ a を満たす任意の整数xを引く。

-----問題ここまで----- */
/* -----解説等-----

一回0の削減をシュミレーションをする。その後の各数字の集合はゲームの直和としてみれるので、
各値のゲームの値が分かればよい。
これは簡単で、111...11からは1の数の削減しかできないのでgrundy数は1の数になってしまう。
あとはこれの直和をXORでとればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	string match = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	map<char, int>strmap;
	FOR(i, 0, SZ(match)) {
		strmap[match[i]] = i;
	}
	VI num(N, 0);
	FOR(i, 0, N) {
		int p;
		string m;
		cin >> p >> m;
		FOR(j, 0, SZ(m)) {
			num[i] *= p;
			num[i] += strmap[m[j]];
		}
	}


	//split
	VI v;
	int down = 1, bit = 1;
	//// 111011010101011101010001
	//FOR(i, 0, N)print_bin(num[i]);

	FOR(i, 0, N) {
		int a = num[i];
		while (a > 0) {
			if (a&bit) { bit *= 2; }
			else {
				bit *= 2;
				if (a%bit != 0)v.push_back(a%bit);
				a /= bit;
				bit = 1;
			}

		}
	}

	// ALL ^ g(v[i])
	int grundy = 0;
	VI g(SZ(v), 0);
	FOR(i, 0, SZ(v)) {
		int bit = 1;
		int subg = 0;;
		while (v[i] & bit) {
			bit *= 2, subg++;
		}

		grundy ^= subg;
	}


	cout << (grundy != 0 ? "win" : "lose") << "\n";

	return 0;
}
