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
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/23  Problem: DDCC-2018-qual D / Link: __CONTEST_URL__  ----- */
/* ------問題------

高橋君の飼い犬の BISCO は, ディスコ株式会社に 29 年務め, ついに退職の時を迎えた. 彼は会社に大きく貢献したため, 社長の WISCO から「黄金の正方形チップ」をプレゼントされた.
このチップには, 秘密の整数 N がデータとして入っており, BISCO は N が 1 以上 1012 以下の整数であることを知っている.
しかし, この整数 N の実際の値は社長しか閲覧することができない.
それでも BISCO が秘密の整数を知りたがったので, 社長の WISCO は, 以下の値をヒントとして与えた.
a2,a3,a4,…,a30 の 29 個の値.
ただし, ai は「整数 N を i 進数で表したときの各位の桁の和」である.
例えば, N=1123 のとき, N を 4 進数で表すと 101203 となるため, a4=1+0+1+2+0+3=7 となる.
BISCO のために, ヒントをもとにして秘密の整数 N を当てなさい.
ただし, 秘密の整数としてあり得る数が複数存在する場合はそのうちのどれを出力してもよく, そのような数が存在しない場合は invalid と出力しなさい.

-----問題ここまで----- */
/* -----解説等-----

整数問題が解けないときは、余剰に持っていくのが良い。
二次篩を考える第一歩は、差がKの倍数であるならば、剰余が等しい2つの整数、的な考えを用いると、
N = Ai*m^i + ... + A0*m^0
in_i = Ai + ... + A0であり、これらの差について、
N - in = (m-1)*(...)であるから、
Nとinはm-1の余剰で一致する値。
これが29本式があり、これはCRTなのであとは貼るだけ。
こういうのはできないとダメなんですよね…

----解説ここまで---- */

inline long long addmod(long long a, long long m) {
	return (a % m + m) % m;
}

long long extGCD(long long a, long long b, long long &p, long long &q) {
	if (b == 0) { p = 1; q = 0; return a; }
	long long d = extGCD(b, a%b, q, p);
	q -= a / b * p;
	return d;
}

pair<long long, long long> ChineseRem(const vector<long long> &b, const vector<long long> &m) {
	long long r = 0, M = 1;
	for (int i = 0; i < (int)b.size(); ++i) {
		long long p, q;
		long long d = extGCD(M, m[i], p, q);
		if ((b[i] - r) % d != 0) return make_pair(0, -1);
		long long tmp = (b[i] - r) / d * p % (m[i] / d);
		r += M * tmp;
		M *= m[i] / d;
	}
	return make_pair(addmod(r, M), M);
}
string to_any_base_String(int base, LL val)
{
	const int size = 60;
	int index = size - 1;
	string str(size, '0');
	while (val != 0) {
		str[index] = '0' + val % base;
		val /= base;
		index--;
	}
	return str;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VI a(31); VI b(31);
	FOR(i, 2, 30 + 1) {
		cin >> a[i];
		b[i] = i - 1;
	}
	VL B(29), M(29);
	FOR(i, 0, 29) {
		B[i] = a[i + 2] % b[i + 2];
		M[i] = b[i + 2];
	}
	// N%(i-1)≡digitsum(N)%(i-1)
	auto res = ChineseRem(B, M);
	if (res.second == -1) {
		cout << "invalid" << endl;
	}
	else {
		const LL Limit = 1000000000000LL;
		LL ans = res.first;
		auto digitsum = [](LL x, int mod) {
			string s = to_any_base_String(mod, x);
			int sum = 0;
			FOR(i, 0, SZ(s)) {
				sum += s[i] - '0';
			}
			return sum;
		};
		while (ans <= Limit) {
			bool f = 1;
			FOR(i, 0, 29) {
				LL sub = digitsum(ans, i + 2);
				f &= (sub == a[i + 2]);
			}
			if (f) {
				cout << ans << endl;
				return 0;
			}
			ans += res.second;
		}



		cout << "invalid" << endl;
	}


	return 0;
}
