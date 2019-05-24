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

/* -----  2019/05/18  Problem: GCJ2019_R2 C / Link: __CONTEST_URL__  ----- */

// name: pottery lottery

void solve(int testcasenum) {
	cerr << "case: " << testcasenum << " ";
	const int asks = 4;
	int cnt = 0;
	FOR(t, 0, 20 - asks) {
		FOR(i, 0, 5 + (t % 2 != 1)) {
			// tにiを置く*6
			int day; cin >> day;

			cnt++;
			cout << t + 1 << " " << i + 1 << endl;
		}
	}
	// 91-99でなんとかする
	vector<PII> a(asks);
	VVI aid(asks);
	FOR(i, 0, asks) {
		int day; cin >> day;
		cout << 20 - asks + 1 + i << " " << 0 << endl;
		int c; cin >> c;
		cerr << c << ", ";
		FOR(s, 0, c) {
			int x; cin >> x;
			aid[i].push_back(x);
		}
		a[i] = PII(c, 20 - asks + 1 + i);
	}
	cerr << "|";

	// 2ndに少ない場所におく
	SORT(a);
	VI pos;
	PII minc = (*min_element(ALL(a)));
	PII min2c = PII(INF, 20);
	set<PII>se;
	FOR(i, 0, asks) {
		if (minc == a[i])continue;
		se.insert(PII(a[i]));
		if (minc.first + 2 >= a[i].first)pos.push_back(a[i].second);
		min2c = min(min2c, a[i]);
	}

	// min2cのidにはいっている数字でやる
	int insertnum = aid[min2c.second - (20 - asks + 1)].front();
	if (SZ(pos) == 0)pos.push_back(min2c.second);
	cerr << "pos:[";
	for (auto it : pos) {
		cerr << it << ",";
	}cerr << "]";
	FOR(i, 0, 100 - cnt - 1 - asks) {
		int day; cin >> day;
		int id = i % SZ(pos);
		//cout << pos[id] << " " << insertnum << endl;
		//cerr << pos[id] << ".";
		{
			auto it = *se.begin();
			se.erase(it);
			id = it.second;
			it.first++;
			se.insert(it);
		}
		cout << id << " " << insertnum << endl;
		cerr << id << ".";
	}


	int day; cin >> day;
	cout << minc.second << " " << 100 << endl; // last !!
	cerr << "post [" << minc.second << "]" << endl;

	LL ans = 0;

	//cout << "Case #" << testcasenum << ": " << ans << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	int T; cin >> T;
	FOR(c, 0, T) {
		solve(c + 1);
	}

	return 0;
}