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

/* -----  2019/07/27  Problem: AOJ 0192 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0192  ----- */


struct data {
	int t, id, id_park, type;
	data() {}
	data(int tt, int ii, int dd, int ttt) {
		t = tt;
		id = ii;
		id_park = dd;
		type = ttt;
	}
	bool operator<(const data &d1)const {
		if (t == d1.t) {
			if (type != d1.type)return type < d1.type;
			if (type == 0)return id > d1.id;
			return id_park > d1.id_park;
		}
		return t > d1.t;
	}
};

int m, n;
int t[120];
int res[120];
int park[11][2];

data park_car(data x) {
	data res = x;
	res.type = -1;
	res.t += t[x.id];
	for (int i = 0; i < m; i++) {
		if (park[i][1] == -1) {
			res.id_park = i * 2 + 1;
			res.type = 1;
			return res;
		}
	}
	int id = -1;
	for (int i = 0; i < m; i++) {
		if (park[i][0] == -1) {
			if (park[i][1] >= res.t) {
				if (id == -1)id = i;
				else if (park[id][1] > park[i][1])id = i;
			}
		}
	}
	if (id != -1) {
		res.id_park = id * 2;
		res.type = 1;
		return res;
	}
	for (int i = 0; i < m; i++) {
		if (park[i][0] == -1) {
			if (id == -1)id = i;
			else if (park[id][1] < park[i][1])id = i;
		}
	}
	if (id != -1) {
		res.id_park = id * 2;
		res.type = 1;
	}
	return res;
}

int main(void) {
	while (1) {
		scanf("%d%d", &m, &n);
		if (m + n == 0)break;
		priority_queue<data> que;
		for (int i = 0; i < n; i++) {
			scanf("%d", &t[i]);
			que.push(data(i * 10, i, -1, 0));
		}
		memset(park, -1, sizeof(park));
		int cnt = 0;
		while (que.size()) {
			data q = que.top();
			que.pop();
			if (q.type == 0) {
				data next = park_car(q);
				if (next.type == -1) {
					q.t++;
					que.push(q);
				}
				else {
					park[next.id_park / 2][next.id_park % 2] = next.t;
					que.push(next);
				}
			}
			else {
				if (q.id_park % 2 == 1 && park[q.id_park / 2][0] != -1) {
					q.t++;
					que.push(q);
				}
				else {
					res[cnt++] = q.id;
					park[q.id_park / 2][q.id_park % 2] = -1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			printf("%d%c", res[i] + 1, i == n - 1 ? '\n' : ' ');
		}
	}
	return 0;
}