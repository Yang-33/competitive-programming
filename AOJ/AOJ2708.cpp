#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i < e;i++)
#define debug(x) cout << #x << ": " << x << endl
const int INF = (1 << 30);
const ll LINF = (1LL << 60);

/* -----  2017/11/01  Problem: AOJ2708 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2708  ----- */
/* ------問題------

文字列 ABC で表される遺伝子配列がある。あなたは次の操作を何回か行い、この遺伝子配列を書き換えていくことができる。
文字 A，B，C のうち 1 つを選ぶ。これを x とおく。遺伝子配列に含まれるすべての x をそれぞれ ABC へ同時に置き換える。
A，B，C だけからなる文字列 S が与えられる。遺伝子配列を S に一致させられるか判定せよ。

-----問題ここまで----- */
/* -----解説等-----

はまり続けた。
逆をシュミレーションしたときにABCになればよい。
が、一回置換を行った後に選択した文字列が存在しないかをチェックしなければならなかった！

----解説ここまで---- */
string S;

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