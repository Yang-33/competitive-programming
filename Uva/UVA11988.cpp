#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

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

/* -----  2017/10/25  Problem: uva 11988  / Link:   ----- */
/* ------問題------

文字列が与えられる。この中には[]で囲まれた文字列があったりなかったりする。
あるときはこれを先頭に出して文字列を再構成せよ。

-----問題ここまで----- */
/* -----解説等-----

構文解析?
[]を一区切りにしてこれごとカットして先頭にくっつければよい。
abc[A]def[B]gはBAabcdefgにすればいいらしい
ABabcdefgだとおもっていた
区間を返すようにすることで余分な部分をカットすることができ、O(|S|)で解ける

----解説ここまで---- */

char input[1000006];

int main()
{
	while (scanf("%s", input) != EOF) {

		int len = strlen(input);

		list <char> output;

		list <char>::iterator it = output.begin();

		for (int i = 0; i < len; i++) {

			if (input[i] == '[') it = output.begin();
			else if (input[i] == ']') it = output.end();
			else output.insert(it, input[i]);
		}

		for (it = output.begin(); it != output.end(); it++)
			printf("%c", *it);

		printf("\n");
	}

	return 0;
}

//// 末尾をかえす
//int solve(int &i, string &ans, string &s) {
//
//	vector<int>v;
//	v.push_back(i);// "[" の位置
//	i++;
//	while (i < SZ(s)) {
//		if (s[i] == '[') {
//			v.push_back(i);
//			v.push_back(solve(i, ans, s));//
//			i++;
//		}
//		else if (s[i] == ']') {//ここでは終わり
//			break;
//		}
//		else {
//			i++;
//		}
//	}
//	if (s[i] == ']')
//		v.push_back(i);
//	else v.push_back(i + 1);
//
//	string p;
//	FOR(j, 0, SZ(v) / 2) {// ans
//		FOR(k, v[2 * j] , v[2 * j + 1]) {
//			if (s[k] == '[')continue;
//			if (s[k] == ']')continue;
//		p += s[k];
//		}
//	}
//	//debug(p);
//	ans += p;
//
//	return v.back();
//}
//
//
//int main() {
//	cin.tie(0);
//	ios_base::sync_with_stdio(false);
//	string s;
//	while (cin >> s) {
//		string ans;
//		int i = 0;
//		while (i < SZ(s)) {
//			i = solve(i, ans, s);
//			//debug(i);
//		}
//		cout << ans << endl;
//	}
//
//	return 0;
//}