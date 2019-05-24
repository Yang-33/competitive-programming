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

/* -----  2019/04/06  Problem: GCJ2019_qual C / Link: __CONTEST_URL__  ----- */

struct BigInt {
public:
	using LL = long long int;
	static const LL BASE = 1000000000;
	const int DIG = 9;

	bool neg;
	std::vector<LL> dig;

	BigInt() : neg(false), dig(1, 0ll) {}
	BigInt(const char* str) : BigInt(std::string(str)) {}
	BigInt(const std::string& str) : neg(false) {
		if (str.empty()) {
			dig.assign(1, 0);
			return;
		}

		int b = 0;
		if (str[b] == '-') {
			neg = true;
			++b;
		}

		LL crt = 0;
		LL p = 1;
		for (int i = (int)(str.size()) - 1; i >= b; --i, p *= 10) {
			if (p == BASE) {
				dig.emplace_back(crt);
				crt = 0;
				p = 1;
			}
			if (!isdigit(str[i])) {
				throw "Non digit is given.";
			}
			crt += p * (str[i] - '0');
		}
		dig.emplace_back(crt);
		norm();
	}
	BigInt(LL x) : neg(x < 0), dig(1, std::abs(x)) {
		for (unsigned int i = 0; i < dig.size(); ++i) {
			if (dig[i] >= BASE) {
				dig.emplace_back(dig[i] / BASE);
				dig[i] %= BASE;
			}
		}
	}
	BigInt& operator=(const BigInt& rhs) {
		neg = rhs.neg;
		dig = rhs.dig;
		return *this;
	}
	BigInt& operator=(LL x) { return *this = BigInt(x); }
	BigInt& operator=(const char* s) { return *this = BigInt(s); }
	BigInt& operator=(const std::string& s) { return *this = BigInt(s); }

	bool iszero() const {
		return dig.size() == 1 && dig[0] == 0;
	}

	BigInt operator-() const {
		BigInt res = *this;
		if (!res.iszero())
			res.neg = !res.neg;
		return res;
	}

	//! ignoring sign
	static int comp(const BigInt& l, const BigInt& r) {
		if (l.dig.size() != r.dig.size())
			return (l.dig.size() < r.dig.size() ? -1 : 1);

		for (int i = (int)(l.dig.size()) - 1; i >= 0; --i) {
			if (l.dig[i] != r.dig[i])
				return (l.dig[i] < r.dig[i] ? -1 : 1);
		}
		return 0;
	}
	//! add ignoring sign
	static void add(BigInt& l, const BigInt& rhs) {
		unsigned int i;
		for (i = 0; i < rhs.dig.size(); ++i) {
			if (l.dig.size() <= i) {
				l.dig.emplace_back(rhs.dig[i]);
			}
			else {
				l.dig[i] += rhs.dig[i];
				if (l.dig[i] >= BASE) {
					l.dig[i] -= BASE;
					if (l.dig.size() <= i + 1)
						l.dig.emplace_back(0);
					l.dig[i + 1]++;
				}
				else if (l.dig[i] < 0) {
					l.dig[i] += BASE;
					if (l.dig.size() <= i + 1)
						l.dig.emplace_back(0);
					l.dig[i + 1]--;
				}
			}
		}
		for (; i < l.dig.size(); ++i)
			if (l.dig[i] >= BASE) {
				l.dig[i] -= BASE;
				if (l.dig.size() <= i + 1)
					l.dig.emplace_back(0);
				l.dig[i + 1]++;
			}
	}
	// subtract ignoring sign, supposed to l >= rhs
	static void sub(BigInt& l, const BigInt& rhs) {
		unsigned int i;
		for (i = 0; i < rhs.dig.size(); ++i) {
			l.dig[i] -= rhs.dig[i];
			if (l.dig[i] < 0) {
				l.dig[i] += BASE;
				l.dig[i + 1]--;
			}
		}
		for (; i < l.dig.size(); ++i)
			if (l.dig[i] < 0) {
				l.dig[i] += BASE;
				l.dig[i + 1]--;
			}
	}

	void flip() {
		for (unsigned int i = 0; i < dig.size(); ++i)
			dig[i] *= -1;
	}
	void norm() {
		while (dig.size() > 1 && dig.back() == 0) dig.pop_back();
		if (iszero()) neg = false;
	}
	bool operator==(const BigInt& rhs) const {
		if (neg != rhs.neg || dig.size() != rhs.dig.size()) return false;
		return comp(*this, rhs) == 0;
	}
	bool operator<(const BigInt& rhs) const {
		if (neg != rhs.neg) return neg ? true : false;
		if (neg) return comp(rhs, *this) == -1;
		return comp(*this, rhs) == -1;
	}
	bool operator<=(const BigInt& rhs) const {
		if (neg != rhs.neg) return neg ? true : false;
		if (neg) return comp(rhs, *this) <= 0;
		return comp(*this, rhs) <= 0;
	}
	bool operator!=(const BigInt& rhs) const { return !(*this == rhs); }
	bool operator>(const BigInt& rhs)  const { return rhs < *this; }
	bool operator>=(const BigInt& rhs) const { return rhs <= *this; }

	// ignoring sign
	void incl() {
		for (unsigned int i = 0; i < dig.size(); ++i)
			if (++dig[i] == BASE) {
				dig[i] = 0;
				if (i + 1 == dig.size()) {
					dig.push_back(1);
					break;
				}
			}
			else break;
	}
	// ignoring sign
	void decl() {
		if (iszero()) {
			dig[0] = 1;
			neg = true;
			return;
		}
		for (unsigned int i = 0; i < dig.size(); ++i)
			if (--dig[i] == -1)
				dig[i] = BASE - 1;
			else break;
		norm();
	}
	BigInt& operator++() {
		if (!neg) incl(); else decl();
		return *this;
	}
	BigInt operator++(int) {
		BigInt res = *this;
		if (!neg) incl(); else decl();
		return res;
	}
	BigInt& operator--() {
		if (!neg) decl(); else incl();
		return *this;
	}
	BigInt operator--(int) {
		BigInt res = *this;
		if (!neg) decl(); else incl();
		return res;
	}

	BigInt& operator+=(const BigInt& rhs) {
		if (!this->neg) {
			if (!rhs.neg)
				add(*this, rhs);
			else {
				if (comp(*this, rhs) >= 0)
					sub(*this, rhs);
				else {
					flip();
					add(*this, rhs);
					neg = true;
				}
			}
		}
		else {
			if (!rhs.neg) {
				if (comp(rhs, *this) >= 0) {
					flip();
					add(*this, rhs);
					neg = false;
				}
				else
					sub(*this, rhs);
			}
			else
				add(*this, rhs);
		}

		norm();
		return *this;
	}
	BigInt& operator-=(const BigInt& rhs) { return *this += -rhs; }
	BigInt operator+(const BigInt& rhs) const { BigInt res = *this; return res += rhs; }
	BigInt operator-(const BigInt& rhs) const { BigInt res = *this; return res -= rhs; }
	BigInt operator*(const BigInt& rhs) const {
		BigInt res;
		res.dig.assign(dig.size() + rhs.dig.size() + 1, 0ll);
		res.neg = neg ^ rhs.neg;

		for (unsigned i = 0; i < rhs.dig.size(); ++i) {
			if (rhs.dig[i] == 0) continue;
			for (unsigned j = 0; j < dig.size(); ++j) {
				res.dig[i + j] += rhs.dig[i] * dig[j];
				if (res.dig[i + j] >= BASE) {
					res.dig[i + j + 1] += res.dig[i + j] / BASE;
					res.dig[i + j] %= BASE;
				}
			}
		}
		res.norm();

		return res;
	}
	BigInt operator*=(const BigInt& rhs) { return *this = *this * rhs; }

	static void divll(BigInt& x, LL& r, LL d) {
		bool lneg = x.neg;
		x.neg ^= (d < 0);
		if (d < 0) d *= -1;

		r = 0;
		for (int i = (int)x.dig.size() - 1; i >= 0; --i) {
			r = r * BASE + x.dig[i];
			x.dig[i] = r / d;
			r %= d;
		}
		x.norm();

		if (r != 0 && lneg)
			r *= -1;
	}

	void powB(LL x) {
		if (iszero()) return;
		while (x > 0) {
			dig.insert(dig.begin(), 0ll);
			--x;
		}
	}
	static void divmod(BigInt& q, BigInt& r, const BigInt& lhs, const BigInt& rhs) {
		int cmp = comp(lhs, rhs);
		if (cmp < 0) {
			q.dig = std::vector<LL>(1, 0ll);
			q.neg = false;
			r = lhs;
			return;
		}
		else if (cmp == 0) {
			q.dig = std::vector<LL>(1, 1ll);
			q.neg = false;
			r.dig = std::vector<LL>(1, 0ll);
			r.neg = false;
			return;
		}
		if (rhs.dig.size() == 1) {
			LL rl;
			q = lhs;
			divll(q, rl, rhs.dig[0] * (rhs.neg ? -1ll : 1ll));
			r = rl;
			return;
		}

		q.neg = r.neg = false;

		int u = lhs.dig.size() - rhs.dig.size() + 1;
		q.dig.assign(u + 1, 0ll);

		LL K = BASE / (rhs.dig.back() + 1);
		BigInt ltmp = lhs, rtmp = rhs;
		ltmp.neg = rtmp.neg = false;

		if (K > 1) {
			ltmp *= K;
			rtmp *= K;
		}

		LL x = ltmp.dig.back() / rtmp.dig.back();
		if (x == 0) {
			--u;
			x = (ltmp.dig.back() * BASE + ltmp.dig[ltmp.dig.size() - 2]) / rtmp.dig.back();
		}
		BigInt w = 0ll;
		while (true) {
			w = rtmp;
			w.powB(u);
			if (comp(w, ltmp) > 0) {
				--u;
				continue;
			}
			while (true) {
				w = rtmp * x;
				w.powB(u);
				if (comp(w, ltmp) <= 0) break;
				--x;
			}

			q.dig[u--] = x;
			ltmp -= w;
			if (ltmp == 0ll || u < 0) break;

			x = std::min(BASE - 1,
				(ltmp.dig.back() * BASE + ltmp.dig[ltmp.dig.size() - 2]) / rtmp.dig.back());
		}
		q.norm();

		r = ltmp;
		if (ltmp != 0ll) divll(r, x, K);
		q.neg = lhs.neg ^ rhs.neg;
		r.neg = lhs.neg;
		r.norm();
	}

	BigInt operator/(const BigInt& rhs) const {
		BigInt q, r;
		divmod(q, r, *this, rhs);
		return q;
	}
	BigInt operator%(const BigInt& rhs) const {
		BigInt q, r;
		divmod(q, r, *this, rhs);
		return r;
	}
	BigInt& operator/=(BigInt rhs) { return *this = *this / rhs; }
	BigInt& operator%=(BigInt rhs) { return *this = *this % rhs; }

	std::string to_string() const {
		//assert(!dig.empty());
		std::string res = neg ? "-" : "";

		std::ostringstream os;
		os << std::to_string(dig.back());
		for (int i = (int)(dig.size()) - 2; i >= 0; --i) {
			os << std::setfill('0') << std::setw(DIG) << dig[i];
		}
		res += os.str();
		return res;
	}
	// convert long long int anyway
	LL to_ll() const {
		LL res = 0, p = 1;
		for (unsigned int i = 0; i < dig.size(); ++i) {
			res += dig[i] * p;
			p *= BASE;
		}
		return res * (neg ? -1ll : 1);
	}


};

int xx = 0;
BigInt zero(xx);

BigInt gcd(const BigInt &a, const BigInt &b) {
	return b == zero ? a : gcd(b, a % b);
}
std::ostream& operator<<(std::ostream& os, const BigInt& x) { return os << x.to_string(); }
std::istream& operator>>(std::istream& is, BigInt& x) { string s; is >> s; x = s; return is; }


void solve(int testcaseid) {
	string base; cin >> base;
	LL N; cin >> N;
	vector<BigInt> a(N + 10);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	BigInt second_common = gcd(a.at(0), a.at(1));
	BigInt first_elem = a.front() / second_common;
	vector<BigInt>b(N + 1);
	b.at(0) = (first_elem);
	FOR(i, 0, N) {
		b.at(i + 1) = a.at(i) / b.at(i);
	}
	auto c = b;
	SORT(c);
	UNIQ(c);
	string ans = string(N + 1, 'A');
	FOR(i, 0, N + 1) {
		int  id = lower_bound(ALL(c), b[i]) - c.begin();
		ans.at(i) = id + 'A';
	}


	std::cout << "Case #" << testcaseid << ": ";
	std::cout << ans << endl;
}

int main() {

	int T; cin >> T;
	FOR(_, 0, T) {
		solve(_ + 1);
	}

	return 0;
}

