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

/* -----  2017/07/11  Problem: AOJ 2708  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2708  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

逆順にたどっていく。
作成の際はA,B,Cのうち任意の文字を全てABCに置換していた。
逆の操作ではABCを何かに置き換えてABCに縮約できるかを見ればよい。
愚直にやるとWAなりTLEで、ダメなケースをはじかないといけない。
一度確認しないといけないケースがあるっぽい？

----解説ここまで---- */

string S;

//S の fromをtoに置換 ex:  string U = replace(S, "ABC", "X");
string replace(string S, string from, string to) {
	auto pos = S.find(from);
	while (pos != string::npos) {
		S.replace(pos, from.size(), to);
		pos = S.find(from, pos + to.size());
	}
	return S;
}

void dfs(string S) {
	if (S == "ABC") {
		cout << "Yes" << endl;
		exit(0);
	}
	string T[3] = { "A","B","C" };
	string U = replace(S, "ABC", "X");
	if (S == U) return;

	FOR(i, 0, 3) if (count(U.begin(), U.end(), T[i][0]) == 0) dfs(replace(U, "X", T[i]));

}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> S;
	dfs(S);
	cout << "No" << endl;

	return 0;
}
