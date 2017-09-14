#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/09/14  Problem: Codeforces Round #432 (Div. 2, based on IndiaHacks Final Round 2017) E  / Link: http://codeforces.com/contest/851/problem/E  ----- */
/* ------問題------

nこの数字のリストがある。2人のプレイヤーは次の操作ができなくなるまで交代で行う。
素数pに対して1≦K、p^Kでリスト内の数字を割ることができれば、リストの値を割ることのできる数字のみ更新する
最適な動きをするMojitaba,Arpaがいるのでどちらが勝つかを答えよ。

-----問題ここまで----- */
/* -----解説等-----

素数についてみればこれらの数字は素数の山でできている。
素数pについてp^kを引くと、P^k以上のものはP^(x-k)、未満のものはそのままである。これは特殊なNimともみれるので、素数についてのgrundy数を求めればよい。
各素数のxorがこのゲームのgrundy数になる。
mapにbitsetを乗っけたり、map<int,bitset<NUM>>とした際の操作が慣れていなくて大変だった。
後から考えればhashでもよかった。
あと適当にmapのオペレーターをかく(必要ないので本当に適当に書いた)

----解説ここまで---- */

ll N;

ll ans = 0LL;
template<size_t sz> struct bitset_comparer {
	bool operator() (const bitset<sz> &b1, const bitset<sz> &b2) const {
		return b1.to_ulong() < b2.to_ulong();
	}
};
map<int, bitset<35>>ma;
map<bitset<35>, int, bitset_comparer<35>>memo;

int game(bitset<35> b) {
	if (memo[b])return memo[b];
	if (b.count() == 0)return 0;
	int m = 0;
	FOR(i, 0, 35) {
		if (b[i])m = i;
	}

	set<int>se;
	FOR(i, 1, m + 1) {
		bitset<35> c(b);
		c[i] = 0;
		FOR(j, i + 1, 35) {
			if (c[j]) {
				c[j] = 0;
				c[j - i] = 1;
			}
		}
		se.insert(game(c));
	}
	int subg = 0;
	while (se.count(subg))subg++;

	return memo[b] = subg;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		int a; cin >> a;
		for (int p = 2; p*p <= a; p++) {
			int cnt = 0;
			while (a%p == 0) {
				cnt++;
				a /= p;
			}
			ma[p][cnt] = 1;
		}
		if (a > 1)ma[a][1] = 1;

	}


	int grundy = 0;
	for (auto itr : ma) {
		grundy ^= game(itr.second);
	}
	cout << ((grundy != 0) ? "Mojtaba" : "Arpa") << endl;

	return 0;
}
