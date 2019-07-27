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

/* -----  2019/07/26  Problem: AOJ 0190 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0190  ----- */


const int N = 13;
const VVI NEXT = {
	{2},
	{2, 5},
	{0, 1, 3, 6},
	{2, 7},
	{5},
	{1, 4, 6, 9},
	{2, 5, 7, 10},
	{3, 6, 8, 11},
	{7},
	{5, 10},
	{6, 9, 11, 12},
	{7, 10},
	{10},
};

class Node {
public:
	VI puzzle;
	int depth;
	Node(const VI& p, int d) :puzzle(p), depth(d) {}
};


void bfs(const VI& puzzle, map<VI, int>& memo) {
	queue<Node> q;
	q.emplace(puzzle, 0);
	while (!q.empty()) {
		Node current(q.front()); q.pop();
		if (current.depth > 10) continue;
		if (memo.count(current.puzzle)) continue;
		memo[current.puzzle] = current.depth;
		FOR(i, 0, N) {
			if (current.puzzle[i] != 0) continue;
			for (const auto& j : NEXT[i]) {
				VI next(current.puzzle);
				swap(next[i], next[j]);
				q.emplace(next, current.depth + 1);
			}
		}
	}
}

int main() {
	const VI complete = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 0 };
	VI puzzle(N);
	map<VI, int> memo1, memo2;
	bfs(complete, memo1);
	while (cin >> puzzle[0], puzzle[0] != -1) {
		FOR(i, 1, N)cin >> puzzle[i];
		memo2.clear();
		bfs(puzzle, memo2);
		int answer = 21;
		for (auto& i : memo1) {
			if (memo2.count(i.first)) {
				answer = min(answer, i.second + memo2[i.first]);
			}
		}
		if (answer > 20) cout << "NA" << endl;
		else cout << answer << endl;
	}
}