#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int i = s;i<e;i++)
#define debug(x) cout << #x << " : " << x << endl

const int INF = (1 << 30);
const ll LINF = (1LL << 60);
/* -----  2017/11/01  Problem: AOJ1142  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1142&lang=jp  ----- */
/* ------問題------

日本の鉄道会社RJ貨物は，横浜羽沢に操車場を完成させた．操車場の配線を図B-1に示す．
貨物列車は2両以上72両以下の貨車を連結している．貨車の種類は26あり，その種類をa～zの英小文字1文字で表す．同じ種類の貨車同士は互いに区別されず，また個々の貨車の向きも区別されない．したがって，2文字以上72文字以下の英小文字の並びで1つの列車の編成が完全に表せる．

操車場に到着した列車は， (storage linesに入る直前に)任意の連結箇所で2つに分割される．続いてそれぞれの部分は，その必要があれば(reversal lineを使って)前後反転される．最後にこれら2つの部分を任意の順序で再び連結することで，最終的な編成を作る．前後反転は，部分ごとに行っても行わなくてもよい．

たとえば，到着時の編成が「abcd」のとき，編成の分割のしかたは3:1，2:2，1:3のいずれかである．分割のしかたそれぞれについて，構成可能な最終編成は次のようになる(「+」は最後の連結位置を示す):

[3:1]
abc+d  cba+d  d+abc  d+cba
[2:2]
ab+cd  ab+dc  ba+cd  ba+dc  cd+ab  cd+ba  dc+ab  dc+ba
[1:3]
a+bcd  a+dcb  bcd+a  dcb+a
重複を除いて数えると，12種類の編成が作り出せることになる．

到着した列車の編成が与えられたとき，上記の操車場によって構成可能な，互いに異なる編成の数を回答せよ．

-----問題ここまで----- */
/* -----解説等-----

全部の区切りで分割して並び替えたもののsetをとればよい。

----解説ここまで---- */
int M;

int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	cin >> M;
	FOR(_i, 0, M) {
		string s;
		cin >> s;
		set<string>se;
		se.insert(s);
		FOR(i, 0, s.size() - 1) {
			string s1 = s.substr(0, 1 + i);
			string s1r = s.substr(0,1+i);
			string s2 = s.substr(1 + i);
			string s2r = s.substr(1 + i);
			reverse(s1r.begin(), s1r.end());
			reverse(s2r.begin(), s2r.end());
			se.insert(s1 + s2r);
			se.insert(s1r + s2);
			se.insert(s1r + s2r);
			se.insert(s2 + s1);
			se.insert(s2 + s1r);
			se.insert(s2r + s1);
			se.insert(s2r + s1r);
		}

		cout << se.size() << endl;
	}
}