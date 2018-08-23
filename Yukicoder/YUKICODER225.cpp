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

/* -----  2018/08/23  Problem: yukicoder 225  / Link: http://yukicoder.me/problems/no/225  ----- */
/* ------問題------

長さnの文字列Sと長さmの文字列Tが与えられます。文字列を構成する各文字は、'a'～'z'です。
今、Sに以下の3種類の操作のいずれかを順次実施してTに変換したいです。
そのような一連の操作のうち、操作回数の最小となるものについて、その最小値を出力するプログラムを書いて下さい。

(操作)
【変更】 Sの中から文字S[ i ]を1個選んで、その文字を'a'～'z'のいずれかの好きな文字に変更します。
【削除】 Sの中から文字S[ i ]を1個選んで、その文字を削除します。削除によって空文字列になることも許容します。
【挿入】 Sの好きな箇所に、'a'～'z'のいずれかの文字を挿入します。特に、Sの先頭や最後尾に文字を追加することもできます。

-----問題ここまで----- */
/* -----解説等-----

基本的なDP

----解説ここまで---- */

int LevenshteinDistance(const string& str1, const string& str2){
	int lenstr1 = str1.length() + 1;
	int lenstr2 = str2.length() + 1;
	vector<vector<int>> d(lenstr1+1,vector<int>(lenstr2+1,0));
	int i1 = 0, i2 = 0, cost = 0;

	for (; i1 < lenstr1; i1++) d[i1][0] = i1;
	for (; i2 < lenstr2; i2++) d[0][i2] = i2;

	for (i1 = 1; i1 < lenstr1; i1++) {
		for (i2 = 1; i2 < lenstr2; i2++) {
			cost = str1[i1 - 1] == str2[i2 - 1] ? 0 : 1;
			d[i1][i2] = min({ d[i1 - 1][i2] + 1, d[i1][i2 - 1] + 1, d[i1 - 1][i2 - 1] + cost });
		}
	}

	return d[lenstr1 - 1][lenstr2 - 1];
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N >> N;
	string s, t; cin >> s >> t;
	cout << LevenshteinDistance(s, t) << "\n";

	return 0;
}
