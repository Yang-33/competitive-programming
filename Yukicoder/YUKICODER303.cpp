#include "bits/stdc++.h"
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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/09/29  Problem: yukicoder 303  / Link: http://yukicoder.me/problems/no/303  ----- */
/* ------問題------

新婚の高橋くんは新築の一戸建てにある家庭菜園を囲む長さ L の塀を作りたいと思っています．
高橋くんの住む街では，全ての正整数 k について長さ k のブロックが k 円で売られています．
高橋くんは，このブロックを好きな数だけ買って，繋げて長さ L の塀にするつもりです．
買ったブロックは（長さを分割する方向に）自由に切っても構いませんが，1 回切るたびにコストが 1 円だけかかります．
ただし，新婚の高橋くんは 2 で割れることを忌み嫌います．
よって，偶数の長さのブロックは買わないこととしました．
また，長さ L の塀ができた時に，ちょうど半分の，端から長さ L/2 の部分がブロックの継ぎ目になっていてはいけません．
さて，このような条件を満たすように塀を作るときの最小コストを求めてください．
むっ，簡単すぎてつまらないという声が聞こえてきたので，最小コストを達成するような塀の作り方のパターンの数も求めてください．
2 つの塀の作り方が違うとは，構成するブロックの数が違う，または，ある i が存在して，左から i 個目のブロックの長さが違うかのどちらかを満たせば違う作り方とみなします．
また，どうやっても，作るのが不可能ならば，最小コストとして INF，パターンの数として 0 を，
最小コストを満たすような作り方が無限に存在する場合は，パターンの数として INF を出力してください．

-----問題ここまで----- */
/* -----解説等-----

まず、f(N):=長さがNで条件を満たすものという風に定義をする。
すると奇数はf(N),偶数は真ん中で割れてはいけないのでf(N) - f(N/2)^2となる。
f(N)について考えているが、不可能で、エスパーをするとfib数であることがわかる。
あとは実装すればよいが、Bigintがかなり厳しい。
いやBigIntいらないだろ！！！！！！！！

----解説ここまで---- */

class FFT
{
private:
	vector<complex<double> > v;

	void execute(const vector<complex<double> >& input, bool isInverse, vector<complex<double> >& output) const
	{
		int n = input.size();
		vector<complex<double> > x(input.begin(), input.end());
		vector<complex<double> > y(n);

		for (int h = 1; h<n; h *= 2) {
			int w = n / h / 2;
			for (int k = 0; k<h; ++k) {
				complex<double> omega = polar<double>(1, (isInverse ? -1 : 1) * M_PI * k / h);
				for (int j = 0; j<w; ++j) {
					complex<double> x0 = x[2 * w*k + j];
					complex<double> x1 = x[2 * w*k + j + w] * omega;
					y[w*k + j] = x0 + x1;
					y[w*(k + h) + j] = x0 - x1;
				}
			}
			x.swap(y);
		}
		output.swap(x);
	}
public:
	void dft(const vector<long long>& input)
	{
		if (input.size() == 0) {
			v.clear();
			return;
		}
		int n = 1;
		while (n < (int)input.size())
			n *= 2;

		vector<complex<double> > x(n, 0);
		for (unsigned i = 0; i<input.size(); ++i)
			x[i] = complex<double>((double)input[i], 0.0);
		execute(x, false, v);
	}
	void idft(vector<long long>& output) const
	{
		int n = v.size();
		vector<complex<double> > y;
		execute(v, true, y);

		output.resize(n);
		for (int i = 0; i<n; ++i) {
			double tmp = y[i].real() / n;
			if (tmp < 0)
				output[i] = (long long)(tmp - 0.5);
			else
				output[i] = (long long)(tmp + 0.5);
		}
	}
	FFT operator*(const FFT& other) const
	{
		int n = v.size();
		if (n != other.v.size())
			throw(exception());

		FFT ans;
		ans.v.resize(n);
		for (int i = 0; i<n; ++i)
			ans.v[i] = v[i] * other.v[i];
		return ans;
	}
};

class Bigint
{
private:
	static const int LEN = 5;
	static const int MAX = 100000;
	vector<long long> a;
	bool sign;
	void normalize() {
		while (!a.empty() && a.back() == 0)
			a.pop_back();
		if (a.empty())
			sign = true;
	}
	Bigint(const vector<long long>& x) {
		a = x;
		sign = true;
		normalize();
	}
public:
	Bigint() {
		sign = true;
	}
	Bigint(long long x) {
		sign = (x >= 0);
		x = abs(x);
		while (x > 0) {
			a.push_back(x % MAX);
			x /= MAX;
		}
	}
	Bigint(const string& s) {
		sign = true;
		long long tmp = MAX;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (tmp == MAX) {
				a.push_back(0);
				tmp = 1;
			}
			if ('0' <= s[i] && s[i] <= '9') {
				a.back() += (s[i] - '0') * tmp;
				tmp *= 10;
			}
			else if (i == 0 && s[0] == '-') {
				sign = false;
			}
			else {
				throw(exception());
			}
		}
		normalize();
	}
	long long getNum() const {
		long long ans = 0;
		for (int i = a.size() - 1; i >= 0; --i) {
			ans *= MAX;
			ans += a[i];
		}
		return ans * (sign ? 1 : -1);
	}
	string getStr() const {
		ostringstream oss;
		if (a.size() == 0)
			return "0";
		if (!sign)
			oss << '-';
		for (int i = a.size() - 1; i >= 0; --i) {
			oss << a[i];
			oss << setw(LEN) << setfill('0');
		}
		return oss.str();
	}
	Bigint operator+(const Bigint& x) const {
		if (sign ^ x.sign) {
			Bigint tmp = x;
			tmp.sign = !tmp.sign;
			return *this - tmp;
		}
		Bigint ans;
		ans.sign = sign;
		long long carry = 0;
		unsigned i = 0;
		while (i < a.size() || i < x.a.size() || carry > 0) {
			if (i < a.size())
				carry += a[i];
			if (i < x.a.size())
				carry += x.a[i];
			ans.a.push_back(carry % MAX);
			carry /= MAX;
			++i;
		}
		return ans;
	}
	Bigint operator-(const Bigint& x) const {
		if (sign ^ x.sign) {
			Bigint tmp = x;
			tmp.sign = !tmp.sign;
			return *this + tmp;
		}
		Bigint ans;
		long long carry = 0;
		unsigned i = 0;
		while (i < a.size() || i < x.a.size()) {
			if (i < a.size())
				carry += a[i];
			if (i < x.a.size())
				carry -= x.a[i];
			if (carry < 0) {
				ans.a.push_back(MAX + carry);
				carry = -1;
			}
			else {
				ans.a.push_back(carry);
				carry = 0;
			}
			++i;
		}
		if (carry == -1) {
			ans.sign = !ans.sign;
			for (unsigned j = 0; j<ans.a.size(); ++j)
				ans.a[j] = MAX - ans.a[j] - 1;
			++ans.a[0];
		}
		ans.normalize();
		return ans;
	}
	Bigint operator*(const Bigint& x) const {
		vector<long long> b = a;
		vector<long long> c = x.a;
		int n = max(b.size(), c.size());
		b.resize(n * 2, 0);
		c.resize(n * 2, 0);

		FFT p, q, r;
		p.dft(b);
		q.dft(c);
		r = p * q;

		Bigint ans;
		ans.sign = !(sign ^ x.sign);
		r.idft(ans.a);
		for (int i = 0; i<2 * n - 1; ++i) {
			ans.a[i + 1] += ans.a[i] / MAX;
			ans.a[i] %= MAX;
		}
		ans.normalize();
		return ans;
	}
	bool operator<(const Bigint& x) const {
		if (sign ^ x.sign)
			return x.sign;
		if (a.size() != x.a.size())
			return !(sign ^ (a.size() < x.a.size()));
		for (int i = a.size() - 1; i >= 0; --i) {
			if (a[i] != x.a[i])
				return !(sign ^ (a[i] < x.a[i]));
		}
		return false;
	}
};

//a*B
template<typename T>
vector<vector<T>> mul(vector<vector<T>> &A, vector<vector<T>> &B) {
	vector<vector<T>> C(A.size(), vector<T>(B[0].size()));
	FOR(i, 0, (int)A.size()) {
		FOR(k, 0, (int)B.size()) {
			{
				FOR(j, 0, (int)B[0].size()) {
					C[i][j] = (C[i][j] + (A[i][k]) * (B[k][j]));
				}
			}
		}
	}
	return C;
}

//a^N べき乗法 logN
template<typename T>
vector<vector<T>> pow(vector<vector<T>> A, long long n) {
	vector<vector<T>> B((int)A.size(), vector<T>((int)A.size()));
	FOR(i, 0, (int)A.size()) {
		B[i][i] = 1;
	}
	while (n > 0) {
		if (n & 1) B = mul(B, A);
		A = mul(A, A);
		n >>= 1;
	}
	return B;
}

Bigint fib(LL n) {
	n--;
	vector<vector<Bigint>>mat(2, vector<Bigint>(2, 1));
	mat[1][1] = 0;
	mat = pow<Bigint>(mat, n);
	return mat[0][0];
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	if (N == 2) {
		cout << 3 << endl;
		cout << "INF" << endl;

	}
	else {
		cout << N << endl;
		if (N & 1) {
			cout << fib(N).getStr() << endl;
		}
		else {
			auto divfib = fib(N / 2);
			Bigint ans = fib(N) - divfib * divfib;
			cout << (fib(N) - divfib * divfib).getStr() << endl;
		}

	}

	return 0;
}
