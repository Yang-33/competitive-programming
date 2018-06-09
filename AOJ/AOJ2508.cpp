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

/* -----  2018/06/10  Problem: AOJ 2508 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2508  ----- */
/* ------問題------

とある国の偉い王様が、突然友好国の土地を視察することになった。 その国は電車が有名で、王様はいろいろな駅を視察するという。

電車の駅は52個あり、それぞれに大文字か小文字のアルファベット1文字の名前がついている（重なっている名前はない）。 この電車の路線は環状になっていて、aの駅の次はbの駅、bの駅の次はcの駅と順に並んでいてz駅の次はA駅、その次はBの駅と順に進み、Z駅の次はa駅になって元に戻る。 単線であり、逆方向に進む電車は走っていない。

ある日、新聞社の記者が王様が訪れる駅の順番のリストを手に入れた。

「dcdkIlkP…」

最初にd駅を訪れ、次にc駅、次にd駅と順に訪れていくという。これで、偉い国の王様を追跡取材できると思った矢先、思わぬことが発覚した。そのリストは、テロ対策のため暗号化されていたのだ！記者の仲間が、その暗号を解く鍵を入手したという。早速この記者は鍵を譲ってもらい、リストの修正にとりかかった。鍵はいくつかの数字の列で構成されている。

「3 1 4 5 3」

この数字の意味するところは、はじめに訪れる駅は、リストに書いてある駅の3つ前の駅。 2番目に訪れる駅はリストの2番目の駅の前の駅、という風に、実際訪れる駅がリストの駅の何駅前かを示している。 記者は修正に取りかかったが、訪れる駅のリストの数よりも、鍵の数の方が小さい、どうするのかと仲間に聞いたところ、最後の鍵をつかったら、またはじめの鍵から順に使っていけばよいらしい。 そして記者はようやくリストを修正することができた。

「abZfFijL…」

これでもう怖い物は無いだろう、そう思った矢先、さらに思わぬ事態が発覚した。 偉い王様は何日間も滞在し、さらにそれぞれの日程ごとにリストと鍵が存在したのだ。 記者は上司から、すべてのリストを復号するように指示されたが、量が量だけに、彼一人では終わらない。 あなたの仕事は彼を助け、このリストの復号を自動で行うプログラムを作成することである。

-----問題ここまで----- */
/* -----解説等-----

適切にdecodeするだけ

----解説ここまで---- */

int f(char s) {
	if ('a' <= s && s <= 'z') {
		return s - 'a';
	}// 0-25
	if ('A' <= s && s <= 'Z') {
		return s - 'A' + 26;
	}// 26-51
}
string g(int x) {
	if (x < 26) {
		return string(1, 'a' + x);
	}
	else {
		x -= 26;
		return string(1, 'A' + x);
	}


}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		VI a(N);
		string s;
		FOR(i, 0, N) {
			cin >> a[i];
		}
		cin >> s;
		string ans = "";

		FOR(i, 0, SZ(s)) {
			string ss = string(1, s[i]);
			int id = i%N;
			int base = f(ss[0]);
			base = ((base - a[id]) % 52 + 52) % 52;
			ans += g(base);
		}
		cout << ans << endl;

	}

	return 0;
}
