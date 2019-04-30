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

/* -----  2019/04/30  Problem: AOJ 1314 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1314  ----- */


struct ParsingMC {
	using Matrix = VVI;
	using Vector = VI;
	ParsingMC() :mod(32768) {}
	map<char, Matrix>memo;
	string s;
	const int mod;
	Matrix matadd(const Matrix& a, const Matrix &b) {
		Matrix ret(a);
		FOR(i, 0, SZ(b)) {
			FOR(j, 0, SZ(b[0])) {
				(ret[i][j] += (b[i][j])) %= mod;
			}
		}
		return ret;
	}
	Matrix matminus(const Matrix a, const Matrix b) {
		Matrix ret(a);
		FOR(i, 0, SZ(b)) {
			FOR(j, 0, SZ(b[0])) {
				(ret[i][j] += (mod - b[i][j])) %= mod;
			}
		}
		return ret;
	}
	// num * mat
	Matrix matmul2(const Matrix a, const Matrix b) {
		Matrix res(b);
		DD(de("matmul2", a[0][0]))
			FOR(i, 0, SZ(b)) {
			FOR(j, 0, SZ(b[0])) {
				(res[i][j] *= a[0][0]) %= mod;
			}
		}
		return res;
	}
	Matrix matmul(const Matrix a, const Matrix b) {
		DD(de("matmul begin"));
		if (SZ(a) == 1 && SZ(a[0]) == 1) {
			return matmul2(a, b);
		}
		else if (SZ(b) == 1 && SZ(b[0]) == 1) {
			return matmul2(b, a);
		}
		// mul
		Matrix res(a.size(), Vector(b[0].size(), 0));
		FOR(i, 0, SZ(a)) {
			FOR(j, 0, SZ(b[0])) {
				FOR(k, 0, SZ(b)) {
					(res[i][j] += a[i][k] * b[k][j]) %= mod;
				}
			}
		}
		DD(de("matmul end"));
		return res;
	}


	Matrix program(const string &s) {
		this->s = s;
		DD(de(SZ(s)));
		char C = s.front();
		return memo[C] = assignment();
	}
	Matrix assignment() {
		int id = 2;
		Matrix ret = expr(id);
		DD(de("as end", id))
			return ret;
	}

	Matrix expr(int &i) {
		Matrix ret = term(i);
		while (i < SZ(s) && (s[i] == '+' || s[i] == '-')) {
			if (s[i] == '+') {
				i++;
				ret = matadd(ret, term(i));
			}
			else {
				i++;
				ret = matminus(ret, term(i));
			}
		}
		DD(de("expr end", i))
			return ret;
	}

	Matrix term(int &i) {
		Matrix ret = factor(i);
		while (i < SZ(s) && s[i] == '*') {
			i++;
			ret = matmul(ret, factor(i));
		}
		return ret;
	}

	Matrix factor(int &i) {
		if (s[i] == '-') {
			i++;
			Matrix f = factor(i);
			Matrix t(f);
			FOR(y, 0, SZ(t)) {
				FOR(x, 0, SZ(t[y])) {
					t[y][x] = 0;
				}
			}
			return matminus(t, f);
		}
		else {
			Matrix t = primary(i);
			DD(de("factor end"));
			return t;
		}
	}

	Matrix primary(int &i) {
		Matrix ret;
		if (isdigit(s[i])) {
			ret = inum(i);
		}
		else if (isalpha(s[i])) {
			ret = memo[s[i]];
			i++;
		}
		else if (s[i] == '[') {
			ret = matrix(i); // ?
			DD(de("primary -> matrix"))
				DD(De(ret));
		}
		else if (s[i] == '(') {
			i++;
			ret = expr(i);
			assert(s[i] == ')');
			i++;
		}
		while (i < SZ(s) && (s[i] == '\'' || s[i] == '(')) {
			DD(de(i));
			DD(de(s[i]));
			if (s[i] == '(') {
				// indexed_primary
				i++;
				ret = indexed_primary(ret, i);
				assert(s[i] == ')');
				i++;
			}
			else if (s[i] == '\'') {
				// transposed_primary
				i++;
				DD(de("trans"));
				ret = transposed_primary(ret);
				DD(de(i));
			}

		}
		DD(de("primary end,", ret, i))
			return ret;
	}
	Matrix indexed_primary(const Matrix & a, int &i) {
		Matrix b = expr(i);
		assert(s[i] == ',');
		i++;
		Matrix c = expr(i);
		// a(b,c)の演算:aからの選択
		Matrix ret(SZ(b[0]), Vector(SZ(c[0])));
		FOR(i, 0, SZ(b[0])) {
			FOR(j, 0, SZ(c[0])) {
				ret[i][j] = a[b[0][i] - 1][c[0][j] - 1];
			}
		}
		return ret;
	}

	Matrix transposed_primary(const Matrix & a) {
		Matrix ret(SZ(a[0]), Vector(SZ(a)));
		FOR(y, 0, SZ(a[0])) {
			FOR(x, 0, SZ(a)) {
				ret[y][x] = a[x][y];
			}
		}
		DD(de("transposed_primary"));
		DD(De(ret));
		return ret;
	}

	Matrix matrix(int &i) {
		assert(s[i] == '[');
		i++;
		Matrix ret = row_seq(i);
		assert(s[i] == ']');
		i++;
		return ret;
	}
	Matrix row_seq(int &i) {
		Matrix ret = row(i);
		while (i < SZ(s) && (s[i] == ';')) {
			if (s[i] == ';') {
				i++;
				Matrix t = row(i);
				// ;の演算:行を追加
				for (auto it : t) {
					ret.push_back(it);
				}
			}
		}
		DD(de("row_seq"));
		DD(De(ret));
		return ret;
	}
	Matrix row(int &i) {
		Matrix ret = expr(i);
		while (i < SZ(s) && (s[i] == ' ')) {
			if (s[i] == ' ') {
				i++;
				Matrix t = expr(i);
				// rowの演算:列を追加
				FOR(y, 0, SZ(t)) {
					FOR(x, 0, SZ(t[y])) {
						ret[y].push_back(t[y][x]);
					}
				}
			}
		}
		return ret;
	}
	Matrix inum(int &i) {
		int num = 0;
		while (i < SZ(s) && isdigit(s[i])) {
			num *= 10;
			num += s[i] - '0';
			num %= mod;
			i++;
		}
		Matrix ret(1);
		ret.front().push_back(num);
		DD(de("inum", i, num))
			return ret;
	}

};

int main() {
	int N;
	while (cin >> N, N) {
		ParsingMC p;
		cin.ignore();
		FOR(i, 0, N) {
			string s;
			getline(cin, s);
			VVI res = p.program(s);
			for (auto vec : res) {
				FOR(j, 0, SZ(vec)) {
					cout << vec[j] << " \n"[j + 1 == SZ(vec)];
				}
			}
		}
		cout << "-----" << endl;
	}

}