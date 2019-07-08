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

/* -----  2019/07/08  Problem: AOJ 1513 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1513  ----- */




template<typename T, size_t X>
struct BinaryTrie {
	struct Node {
		size_t cnt;
		Node *p, *l, *r;
		Node(Node* p) :cnt(0), p(p) { l = r = nullptr; }
	};

	T acc;
	Node *root;
	BinaryTrie() :acc(0) { root = emplace(nullptr); }

	inline Node* emplace(Node* p) {
		return new Node(p);
	}

	inline size_t count(Node* a) {
		return a ? a->cnt : 0;
	}
	// 値bをk個追加する
	void add(const T b, size_t k = 1) {
		const T nb = b ^ acc;
		Node* a = root;
		for (int i = X - 1; i >= 0; i--) {
			bool f = (nb >> i) & 1;
			if (!f && !a->l) a->l = emplace(a);
			if (f && !a->r) a->r = emplace(a);
			a = f ? a->r : a->l;
		}
		a->cnt += k;
		while ((a = a->p)) a->cnt = count(a->l) + count(a->r);
	}

	void sub(Node* a, size_t k = 1) {
		assert(a&&a->cnt >= k);
		a->cnt -= k;
		while ((a = a->p)) {
			a->l = check(a->l);
			a->r = check(a->r);
			a->cnt = count(a->l) + count(a->r);
		}
	}
	// 値*aをk個削除する
	void sub(const T b, size_t k = 1) {
		Node* it = this->find_by_order(b);
		sub(it, k);
	}

	// 全体をbでxorする
	void update(const T b) { acc ^= b; }

	Node* check(Node *a) {
		if (!a || count(a)) return a;
		delete(a);
		return nullptr;
	}


	// bでxorをとったときの最大値をもつnodeを返す
	Node* xmax(const T b) {
		assert(count(root));
		const T nb = b ^ acc;
		Node* a = root;
		for (int i = X - 1; i >= 0; i--) {
			bool f = (nb >> i) & 1;
			if (!a->l || !a->r) a = a->l ? a->l : a->r;
			else a = f ? a->l : a->r;
		}
		return a;
	}
	// bでxorをとったときの最小値をもつnodeを返す
	Node* xmin(const T b) {
		return xmax(~b&((T(1) << X) - 1));
	}

	Node* ge(Node *a, int i) {
		if (!a) return a;
		Node *l = a->l, *r = a->r;
		if ((acc >> i) & 1) swap(l, r);
		if (l || r) return ge(l ? l : r, i + 1);
		return a;
	}

	Node* next(Node* a, int i) {
		if (!(a->p)) return nullptr;
		Node *l = a->p->l, *r = a->p->r;
		if ((acc >> (i + 1)) & 1) swap(l, r);
		if (a == l && r) return ge(r, i);
		return next(a->p, i + 1);
	}

	// b以上の最小のnodeを返す．
	Node* lower_bound(const T b) {
		const T nb = b ^ acc;
		Node* a = root;
		for (int i = X - 1; i >= 0; i--) {
			bool f = (nb >> i) & 1;
			if (!f&&a->l) { a = a->l; continue; }
			if (f&&a->r) { a = a->r; continue; }
			if ((b >> i) & 1) return next(a, i);
			return ge(a, i);
		}
		return a;
	}

	// node a の値
	T val(Node* a) {
		T res(0);
		for (int i = 0; i < (int)X; i++) {
			assert(a->p);
			res |= (T(a == a->p->r) << i);
			a = a->p;
		}
		return res ^ acc;
	}

	// k番目のnode(0-index)
	Node* find_by_order(size_t k) {
		Node *a = root;
		if (count(a) <= k) return nullptr;
		for (int i = X - 1; i >= 0; i--) {
			bool f = (acc >> i) & 1;
			if (count(f ? a->r : a->l) <= k) {
				k -= count(f ? a->r : a->l);
				a = f ? a->l : a->r;
			}
			else {
				a = f ? a->r : a->l;
			}
		}
		return a;
	}
	// bは木全体で何番目か?
	size_t order_of_key(const T b) {
		Node *a = root;
		size_t res = 0;
		for (int i = X - 1; i >= 0; i--) {
			Node *l = a->l, *r = a->r;
			if ((acc >> i) & 1) swap(l, r);
			bool f = (b >> i) & 1;
			if (f) res += count(l);
			a = f ? r : l;
			if (!a) break;
		}
		return res;
	}

	// 全体にXORをしたときに，b未満の値の数
	size_t countless(const T b, T XOR = 0) {
		this->update(XOR);
		size_t sum = this->order_of_key(b);
		this->update(XOR);
		return sum;
	}
};


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	using BT = BinaryTrie<LL, 62 >;
	LL Q, L;
	while (cin >> Q >> L, Q&&L) {
		BT se;
		LL base = 0;
		FOR(_, 0, Q) {
			int mode; cin >> mode;
			if (mode == 0) {
				se.add(base + L, 1);
			}
			else if (mode == 1) {
				LL d; cin >> d;
				base += d;

				int cnt = 0;
				while (se.countless(1e18 + 5) && se.val(se.xmin(0)) <= base) {
					auto head = se.xmin(0);
					cnt += se.count(head);
					if (head->cnt == 0)assert(0);
					se.sub(head, se.count(head));
				}
				if (cnt) {
					cout << "damage " << cnt << "\n";
				}
			}
			else if (mode == 2) {
				LL k; cin >> k;
				auto tail = se.find_by_order(k - 1);
				if (tail == nullptr)cout << "miss\n";
				else {
					if (tail->cnt == 0)assert(0);
					se.sub(tail, 1);
					cout << "hit\n";
				}

			}
			else if (mode == 3) {
				LL x, r; cin >> x >> r;
				LL segL = base + x - r, segR = base + x + r;
				segL = max(0LL, segL);
				// [L,R]delete
				int cnt = 0;
				while (se.countless(segR + 1) - se.countless(segL) > 0) {
					auto head = se.lower_bound(segL);
					cnt += se.count(head);
					if (head->cnt == 0)assert(0);
					se.sub(head, se.count(head));
				}
				cout << "bomb " << cnt << "\n";

			}
			else if (mode == 4) {
				LL k; cin >> k;
				auto tail = se.find_by_order(k - 1);
				if (tail == nullptr)cout << "distance -1\n";
				else {
					LL v = se.val(tail);
					cout << "distance " << v - base << "\n";
				}
			}
		}
		cout << "end" << "\n";
	}
}