#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long LL;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/09  Problem: POJ 1082 / Link: http://poj.org/problem?id=1082  ----- */
/* ------問題------

かれんだー上でのゲーム
一日先か、一か月後にジャンプできるので、指定の日からはじめておわるようにしたとき、
先手は必勝か？

-----問題ここまで----- */
/* -----解説等-----

蟻本練習問題における貴重なやるだけ問題
負けへ遷移できるものは勝ち、全ての遷移先が勝ちになるものは負けの盤面。
カレンダーの状態は少ないので、末尾へ再帰をしていけばよい。

----解説ここまで---- */

static const int YEAR = 2001 - 1900, MON = 11, MDAY = 4;

bool overrun(int year, int mon, int mday)
{
	if (year > YEAR) {
		return true;
	}
	else if (year < YEAR) {
		return false;
	}
	if (mon > MON) {
		return true;
	}
	else if (mon < MON) {
		return false;
	}
	if (mday > MDAY) {
		return true;
	}
	return false;
}

bool leap(int y)
{
	y += 1900;
	if (y % 400 == 0) {
		return true;
	}
	else if (y % 100 == 0) {
		return false;
	}
	else if (y % 4 == 0) {
		return true;
	}
	else {
		return false;
	}
}

int days(int y, int m)
{
	static const int t[] = { -1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (m == 2) {
		return t[m] + leap(y);
	}
	else {
		return t[m];
	}
}

void fix(int& y, int& m, int& d)
{
	if (d > days(y, m)) {
		d = 1;
		++m;
	}
	if (m > 12) {
		m = 1;
		++y;
	}
}

int memo[YEAR + 1][13][40];

bool solve(int year, int mon, int mday)
{
	if (year == YEAR && mon == MON && mday == MDAY) {
		return false;
	}
	else if (overrun(year, mon, mday)) {
		throw "err";
	}
	else {
		int& ans = memo[year][mon][mday];
		if (ans != -1) {
			return ans;
		}
		int y = year, m = mon, d = mday + 1;
		fix(y, m, d);
		if (!solve(y, m, d)) {
			return ans = true;
		}
		y = year, m = mon + 1, d = mday;
		fix(y, m, d);
		if (d == mday && !overrun(y, m, d) && !solve(y, m, d)) {
			return ans = true;
		}
		return ans = false;
	}
}

int main()
{
	for (int i = 0; i <= YEAR; i++) {
		for (int j = 1; j <= 12; j++) {
			for (int k = 1; k < 40; k++) {
				memo[i][j][k] = -1;
			}
		}
	}
	int T;
	cin >> T;
	while (T-- > 0) {
		int y, m, d;
		cin >> y >> m >> d;
		y -= 1900;
		cout << (solve(y, m, d) ? "YES" : "NO") << endl;
	}
	return 0;
}
