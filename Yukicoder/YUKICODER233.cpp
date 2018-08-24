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
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/24  Problem: yukicoder 233  / Link: http://yukicoder.me/problems/no/233  ----- */
/* ------問題------

あ、センパーイ、ちゃろー！
え、今インストールしてるのですか？
これ、明日からサービス開始するソーシャルゲームです！
センパイも何かソーシャルゲームやるんですかね…？
センパイ、yukicoderやってるんですね！
めぐるもyukicoderやってて、結構ランキング上位なんですよ！
他にもあのゲームやこのゲームでめぐるはランカーですよ。
そんないろんなゲームでランカーやってる人って見たことないって？
めぐるはゲームごとに使う名前変えてて、同じ名前は使わないって決めてますからね。
めぐるが使う名前は、inabameguru のアナグラムでローマ字読みできるものって決めてるんです。
ローマ字読みできるってのは、子音が連続してなくて、母音で終わるものですね。
え、母音は a,i,u,e,o の 5 文字ですよ…、そんなの小学生でも知ってますよ？
今までどうやって生きてきたんですか、センパイ…？
今まで N 個のゲームで、それぞれ S1,S2,…,SN って名前を使ったんですけど、次に使う名前どうしようかなって…。
ちょうどいいからセンパイ！選んでください！！

-----問題ここまで----- */
/* -----解説等-----

abageminuru
がんばって全部作る。

----解説ここまで---- */

set<string> allAnagram(string& vowels, string& consonants) {
	set<string>res;
	SORT(vowels);
	SORT(consonants);
	do {
		do {
			FOR(i, 0, 5) {
				string ret;
				FOR(j, 0, 5) {
					if (i == j) {
						ret += vowels[5];
					}
					ret += consonants[j];
					ret += vowels[j];
				}
				res.insert(ret);
			}
		} while (next_permutation(ALL(consonants)));
	} while (next_permutation(ALL(vowels)));


	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	string vowels = "iaaeuu"; string consonants = "nbmgr";
	set<string>se = allAnagram(vowels, consonants);
	FOR(i, 0, N) {
		string s; cin >> s;
		se.erase(s);
	}
	cout << (SZ(se) ? *se.begin() : "NO") << endl;

	return 0;
}
