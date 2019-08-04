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
const int INF = 2e9;                          const LL LINF = 1e18;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/07/28  Problem: GOOGLE_KICKSTART2019_ROUNDD C / Link: https://codingcompetitions.withgoogle.com/kickstart/round/0000000000051061  ----- */

// Food Stalls
void solve(int testcasenum) {
	int K, N; cin >> K >> N;

	vector<LL> X(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}
	vector<LL> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}

	LL ans = LINF;
	FOR(wpos, 0, N) {
		LL ret = C[wpos];
		VL cand;
		FOR(i, 0, N) {
			if (i == wpos)continue;
			cand.emplace_back(abs(X[i] - X[wpos]) + C[i]);
		}
		SORT(cand);
		FOR(i, 0, K) {
			ret += cand[i];
		}

		ans = min(ans, ret);
	}

	cout << "Case #" << testcasenum << ": ";
	cout << ans << endl;
}

template <std::size_t BitLength, class Abelian> struct foldable_wavelet_matrix {
	using mapped_structure = Abelian;
	using mapped_type = typename mapped_structure::value_type;
	using key_type = std::bitset<BitLength>;

	struct bitvector {
		struct node_type;
		using container_type = std::vector<node_type>;
		using size_type = typename container_type::size_type;
		struct node_type {
			size_type count;
			mapped_type sum;
			node_type()
				: count(static_cast<size_type>(0)),
				sum(mapped_structure::identity()) {}
		};

		container_type vec;

		bitvector() : vec() {}

		void resize(const size_type size) {
			vec.resize(size + static_cast<size_type>(1));
		}
		void set(const size_type index) {
			vec[index].count = static_cast<size_type>(1);
		}
		template <class InputIterator>
		void build(const std::vector<InputIterator> &a) {
			for (size_type i = a.size(); i != static_cast<size_type>(0);) {
				--i;
				vec[i].count += vec[i + static_cast<size_type>(1)].count;
				vec[i].sum = mapped_structure::operation(
					a[i]->second, vec[i + static_cast<size_type>(1)].sum);
			}
		}

		size_type count(const size_type index) const { return vec[index].count; }
		size_type zeros() const { return vec.front().count; }
		mapped_type fold(const size_type first, const size_type last) const {
			return mapped_structure::operation(
				vec[first].sum, mapped_structure::inverse(vec[last].sum));
		}
	};

	using size_type = typename bitvector::size_type;

	std::array<bitvector, BitLength> matrix;

	foldable_wavelet_matrix() :matrix() {}

	template <class InputIterator>
	explicit foldable_wavelet_matrix(InputIterator first,
		const InputIterator last) {
		using iterator = InputIterator;

		const size_type size = static_cast<size_type>(std::distance(first, last));
		std::vector<iterator> cur, pre;
		cur.reserve(size);
		for (; first != last; ++first) {
			cur.push_back(first);
		}
		pre = cur;
		std::size_t i = BitLength;
		while (i != static_cast<std::size_t>(0)) {
			--i;
			bitvector &vec = matrix[i];
			vec.resize(size);
			std::swap(cur, pre);
			typename std::vector<iterator>::iterator zero_itr = cur.begin(),
				one_itr = cur.end();
			for (size_type k = static_cast<size_type>(0); zero_itr != one_itr; ++k) {
				if (pre[k]->first.test(i)) {
					--one_itr;
					*one_itr = pre[k];
				}
				else {
					vec.set(k);
					*zero_itr = pre[k];
					++zero_itr;
				}
			}
			std::reverse(one_itr, cur.end());
			vec.build(cur);
		}
	}

	std::tuple<mapped_type, mapped_type, mapped_type>
		fold_leg(size_type first, size_type last, const key_type &key) const {
		mapped_type less = mapped_structure::identity(),
			greater = mapped_structure::identity();
		std::size_t i = BitLength;
		while (i != static_cast<std::size_t>(0)) {
			--i;
			const bitvector &vec = matrix[i];
			const size_type f = vec.count(first), l = vec.count(last),
				z = vec.zeros();
			if (key.test(i)) {
				less = mapped_structure::operation(std::move(less),
					vec.fold(z - f, z - l));
				first += f;
				last += l;
			}
			else {
				greater = mapped_structure::operation(vec.fold(first + f, last + l),
					std::move(greater));
				first = z - f;
				last = z - l;
			}
		}
		return std::forward_as_tuple(
			std::move(less), matrix.front().fold(first, last), std::move(greater));
	}

	std::pair<mapped_type, mapped_type>
		fold_quantile(size_type first, size_type last, size_type k) const {
		mapped_type less = mapped_structure::identity(),
			greater = mapped_structure::identity();
		std::size_t i = BitLength;
		while (i != static_cast<std::size_t>(0)) {
			--i;
			const bitvector &vec = matrix[i];
			const size_type f = vec.count(first), l = vec.count(last),
				z = vec.zeros();
			if (f - l <= k) {
				k -= f - l;
				less = mapped_structure::operation(std::move(less),
					vec.fold(z - f, z - l));
				first += f;
				last += l;
			}
			else {
				greater = mapped_structure::operation(vec.fold(first + f, last + l),
					std::move(greater));
				first = z - f;
				last = z - l;
			}
		}
		return std::make_pair(
			mapped_structure::operation(std::move(less),
				matrix.front().fold(first, first + k)),
			mapped_structure::operation(matrix.front().fold(first + k, last),
				std::move(greater)));
	}

	mapped_type fold_topk(size_type first, size_type last, size_type k) const {
		k = last - first - k;
		mapped_type ret = mapped_structure::identity();
		std::size_t i = BitLength;
		while (i != static_cast<std::size_t>(0)) {
			--i;
			const bitvector &vec = matrix[i];
			const size_type f = vec.count(first), l = vec.count(last),
				z = vec.zeros();
			if (f - l < k) {
				k -= f - l;
				first += f;
				last += l;
			}
			else {
				ret = mapped_structure::operation(vec.fold(first + f, last + l),
					std::move(ret));
				first = z - f;
				last = z - l;
			}
		}
		return mapped_structure::operation(matrix.front().fold(first + k, last),
			std::move(ret));
	}

	mapped_type fold_bottomk(size_type first, size_type last, size_type k) const {
		mapped_type ret = mapped_structure::identity();
		std::size_t i = BitLength;
		while (i != static_cast<std::size_t>(0)) {
			--i;
			const bitvector &vec = matrix[i];
			const size_type f = vec.count(first), l = vec.count(last),
				z = vec.zeros();
			if (f - l <= k) {
				ret = mapped_structure::operation(std::move(ret), vec.fold(z - f, z - l));
				k -= f - l;
				first += f;
				last += l;
			}
			else {
				first = z - f;
				last = z - l;
			}
		}
		return mapped_structure::operation(std::move(ret), matrix.front().fold(first, first + k));
	}
};

template <class T> class plus_abelian {
public:
	using value_type = T;
	static value_type operation(const value_type &x, const value_type &y) {
		return x + y;
	}
	static value_type identity() { return static_cast<value_type>(0); }
	static value_type inverse(const value_type &x) { return -x; }
	static value_type reverse(const value_type &x) { return x; }
};

void solve2(int testcasenum) {
	LL K, N; cin >> K >> N;

	vector<LL> X(N);
	for (int i = 0; i < N; ++i) {
		cin >> X[i];
	}
	vector<LL> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}

	{ // change order

		VI idx(N);
		iota(ALL(idx), 0);
		sort(ALL(idx), [&](const int L, const int R) {
			return X[L] < X[R];
		});

		VL xx(N), cc(N); {
			FOR(i, 0, N) {
				xx[i] = X[idx[i]];
				cc[i] = C[idx[i]];
			}
		}
		FOR(i, 0, N) {
			X[i] = xx[i];
			C[i] = cc[i];
		}
	}
	FOR(i, 0, N) {
		DD(de(X[i], C[i]));
	}

	static constexpr int BitLen = 60;
	foldable_wavelet_matrix<BitLen, plus_abelian<LL>> fwmL; {
		std::vector<std::pair<std::bitset<BitLen>, LL>> b(N);
		for (int i = 0; i < N; ++i) {
			b[i].first = C[i] - X[i] + INF;
			b[i].second = C[i] - X[i] + INF;
		}
		fwmL = foldable_wavelet_matrix<BitLen, plus_abelian<LL>>(b.cbegin(),
			b.cend());
	}
	foldable_wavelet_matrix<BitLen, plus_abelian<LL>> fwmR; {
		std::vector<std::pair<std::bitset<BitLen>, LL>> b(N);
		for (int i = 0; i < N; ++i) {
			b[i].first = C[i] + X[i] + INF;
			b[i].second = C[i] + X[i] + INF;
		}
		fwmR = foldable_wavelet_matrix<BitLen, plus_abelian<LL>>(b.cbegin(),
			b.cend());
	}

	LL ans = LINF;
	FOR(wpos, 0, N) {
		// じつはCiがあっても真ん中が良い
		// というか，wposを全部やる過程で，absに関係する部分は均等にやったほうがよい
		auto score = [&](int a, int b) {
			LL ret = C[wpos];
			if (a > wpos || N - 1 - wpos < b)return LINF;
			// a+b=K
			//assert(a + b == K);
			LL A = fwmL.fold_bottomk(0, wpos, a) + a * X[wpos];
			LL B = fwmR.fold_bottomk(wpos + 1, N, b) - b * X[wpos];
			ret += A + B;
			return ret - K * INF;
		};
		int a = K / 2;
		int b = K - a;
		ans = min(ans, score(a, b));
		DD(de(ans));
	}


	cout << "Case #" << testcasenum << ": ";
	cout << ans << "\n";
}



int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		//solve2(t + 1);
		solve(t + 1);
	}

	return 0;
}

/*
[1 input]:
3
2 4
1 2 3 10
100 70 80 20
1 5
150 300 301 400 700
8 35 26 5 2
6 7
22 21 20 23 26 25 24
10 10 10 10 10 10 10
[1 output]:
Case #1: 178
Case #2: 62
Case #3: 82
*/