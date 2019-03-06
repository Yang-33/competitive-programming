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

/* -----  2019/02/24  Problem: ABC 119 A / Link: http://abc119.contest.atcoder.jp/tasks/abc119_a  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

場合分け4つ(3:1)で解いた．
カレンダーライブラリの確認も行った．

----解説ここまで---- */

struct Date {
	typedef long long Integer; Integer offset;
	static const int days[12], dayscumsum[13], dayscumsuml[13];
	struct YMD {
		Integer Y; int M, D;
		YMD(Integer Y_, int M_, int D_) : Y(Y_), M(M_), D(D_) { }
	};
	Date() : offset(0) { }
	explicit Date(Integer offset_) : offset(offset_) { }
	Date(Integer Y, int M, int D) : offset(toOffset(Y, M, D)) { }

	static bool isLeapYear(Integer Y) {
		return Y % 4 == 0 && (Y % 100 != 0 || Y % 400 == 0);
	}
	static int getDays(Integer Y, int M) {
		return days[M - 1] + (M == 2 && isLeapYear(Y));
	}
	static Integer toOffset(Integer y, int m, int d) {
		if (m <= 2) y--, m += 12;
		return y * 365 + div(y, 4) - div(y, 100) + div(y, 400) + 153 * (m + 1) / 5 + d - 428;
	}
	void getYearMonthDay(Integer &Y, int &M, int &D) const {
		Integer a = offset - 1, quadcent = div(a, 146097);
		Integer b = a - quadcent * 146097, cent = min(b / 36524, Integer(3));
		Integer c = b - cent * 36524, quad = c / 1461;
		Integer d = c - quad * 1461, y = min(d / 365, Integer(3));
		Y = quadcent * 400 + cent * 100 + quad * 4 + y + 1;
		int yd = (int)(d - y * 365 + 1);
		fromOrdinalDate(Y, yd, M, D);
	}
	static void fromOrdinalDate(const Integer &Y, int yd, int &M, int &D) {
		const int *cumsum = isLeapYear(Y) ? dayscumsuml : dayscumsum;
		M = upper_bound(cumsum, cumsum + 13, yd - 1) - cumsum;
		D = yd - cumsum[M - 1];
	}

	Integer getYear() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return Y; }
	int getMonth() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return M; }
	int getDay() const { Integer Y; int M, D; getYearMonthDay(Y, M, D); return D; }
	int getDayOfWeek() const { return offset % 7; }

	Date operator+(Integer that) const { return Date(offset + that); }
	Date &operator+=(Integer that) { offset += that; return *this; }
	Integer operator-(const Date &that) const { return offset - that.offset; }

	bool operator==(const Date &that) const { return offset == that.offset; }
	bool operator!=(const Date &that) const { return offset != that.offset; }
	bool operator< (const Date &that) const { return offset <  that.offset; }
	bool operator> (const Date &that) const { return offset >  that.offset; }
	bool operator<=(const Date &that) const { return offset <= that.offset; }
	bool operator>=(const Date &that) const { return offset >= that.offset; }

	friend ostream &operator<<(ostream &o, const Date &that) {
		Date::Integer Y; int M, D; that.getYearMonthDay(Y, M, D);
		return o << Y << "/" << M << "/" << D;
	}
private:
	static inline Integer div(Integer x, int y) { return x / y - (x % y != 0 && x < 0); };
};
const int Date::days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
const int Date::dayscumsum[13] = { 0,31,59,90,120,151,181,212,243,273,304,334,365 };
const int Date::dayscumsuml[13] = { 0,31,60,91,121,152,182,213,244,274,305,335,366 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int y, m, d;
	scanf("%d/%d/%d", &y, &m, &d);
	Date in(y, m, d);
	Date target(2019, 4, 30);
	if (in>target) {
		cout << "TBD" << endl;
	}
	else {
		cout << "Heisei" << endl;
	}

	return 0;
}
