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

/* -----  2018/07/26  Problem: AOJ 0261 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0261  ----- */
/* ------問題------

真也君はテレビで「マヤの大予言！2012年で世界が終る？」という番組を見ました。結局、世界が終るかどうかはよくわかりませんでしたが、番組で紹介されていたマヤの「長期暦」という暦に興味を持ちました。その番組では以下のような説明をしていました。
マヤ長期暦は、右の表のような単位からなる、全部で13バクトゥン(187万2000日)で構成される非常に長い暦である。ある計算法では、この暦は紀元前3114年8月11日に始まり2012年12月21日に終わると考えられていて、このため今年の12月21日で世界が終るという説が唱えられている。しかし、13バクトゥンで１サイクルとなり、今の暦が終わったら新しいサイクルに入るだけという考えもある。
１キン＝１日
１ウィナル＝２０キン
１トゥン＝１８ウィナル
１カトゥン＝２０トゥン
１バクトゥン＝２０カトゥン	 
「ぼくの二十歳の誕生日はマヤ暦だと何日になるのかな？」真也君はいろいろな日をマヤ長期暦で表してみたくなりました。
では、真也君の代わりに、西暦とマヤ長期暦とを相互変換するプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

しんどいだけ
定数をゴリゴリ埋め込む

----解説ここまで---- */

template<class T> using V = vector <T>; template <class T> using VV = V<V<T>>;

#include<time.h>
// poi!
LL gettime64(LL y, LL m, LL d) {
	struct tm poi;
	poi.tm_year = y - 1900;
	poi.tm_mon = m - 1;
	poi.tm_mday = d;
	poi.tm_hour = poi.tm_min = poi.tm_sec = 0;
	poi.tm_isdst = -1;
	return mktime(&poi);
}


V<int> split(string base, char spl) {
	V<int> res;
	int pos = 0;
	int bef = 0;
	base += spl;
	while ((pos = base.find_first_of(spl, bef)) != string::npos) {
		auto toint = [](const string& s) {
			return atoi(s.c_str());
		};
		res.push_back(toint(base.substr(bef, pos - bef)));
		bef = pos + 1;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	const int AD = 146097;
	const int MAYA = 1872000;
	string s;
	while (cin >> s, s != "#") {
		if (s == "#")break;
		V<int> input = split(s, '.');
		if (SZ(input) == 3) {
			// y. m. d
			LL y = input[0];
			LL m = input[1];
			LL d = input[2];

			LL year_down = (y - 2013) / 400;
			y -= year_down * 400;

			LL birth = gettime64(y, m, d);
			LL origin = gettime64(2012, 12, 21);
			LL sub = (birth - origin) / 24 / 60 / 60;

			sub += year_down * AD%MAYA;
			sub %= MAYA;
			// uku

			int ki = sub % 20; sub /= 20;
			int w = sub % 18;  sub /= 18;
			int t = sub % 20;  sub /= 20;
			int ka = sub % 20;
			int b = sub / 20;
			printf("%d.%d.%d.%d.%d\n", b, ka, t, w, ki);
		}
		else {
			// b. ka. t. w. ki
			V<LL>mul({ 20,20,18,20,1 });
			LL val = 0;
			FOR(i, 0, 5) {
				val += input[i];
				val *= mul[i];
			}
			LL year_add = val / AD;
			val %= AD;
			val *= 24 * 60 * 60;
			val += gettime64(2012, 12, 22);
			struct tm *birth = gmtime((time_t*)&val);
			int year = birth->tm_year + 1900 + year_add * 400;
			int month = birth->tm_mon + 1;
			int day = birth->tm_mday;
			printf("%d.%d.%d\n", year, month, day);
		}// YU RU SAN
	}
	return 0;
}