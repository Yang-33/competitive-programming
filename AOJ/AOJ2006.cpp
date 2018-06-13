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

/* -----  2018/06/14  Problem: AOJ 2006 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2006  ----- */
/* ------問題------

Alice さんは Miku さんに携帯電話でメールを送ろうとしている。
携帯電話には入力に使えるボタンは数字のボタンしかない。 そこで、文字の入力をするために数字ボタンを何度か押して文字の入力を行う。携帯電話の数字ボタンには、次の文字が割り当てられており、ボタン 0 は確定ボタンが割り当てられている。この携帯電話では 1 文字の入力が終わったら必ず確定ボタンを押すことになっている。

1: . , ! ? (スペース)
2: a b c
3: d e f
4: g h i
5: j k l
6: m n o
7: p q r s
8: t u v
9: w x y z
0: 確定ボタン
例えば、ボタン 2、ボタン 2、ボタン 0 と押すと、文字が 'a' → 'b' と変化し、ここで確定ボタンが押されるので、文字 b が出力される。 同じ数字を続けて入力すると変化する文字はループする。すなわち、ボタン 2 を 5 回押して、次にボタン 0 を押すと、文字が 'a' → 'b' → 'c' → 'a' → 'b' と変化し、ここで確定ボタンを押されるから 'b' が出力される。

何もボタンが押されていないときに確定ボタンを押すことはできるが、その場合には何も文字は出力されない。

あなたの仕事は、Alice さんが押したボタンの列から、Alice さんが作ったメッセー

-----問題ここまで----- */
/* -----解説等-----

やっていけばいいため

----解説ここまで---- */

char img[9][5] = {
	{ '.',',','!','?',' ' },
	{ 'a','b','c' },
	{ 'd','e','f' },
	{ 'g','h','i' },
	{ 'j','k','l' },
	{ 'm','n','o' },
	{ 'p','q','r','s' },
	{ 't','u','v' },
	{ 'w','x','y','z' },
};
int in1[9] = { 5,3,3,3,3,3,4,3,4 };

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int Case;
	cin >> Case;
	FOR(kim, 0, Case) {
		string s;
		cin >> s;
		int i = 0;
		while (i != SZ(s)) {
			int co = 0;
			while (s[i] != '0') {
				co++;
				i++;
			}
			if (co) {
				int target = s[i - 1] - '0' - 1;
				int pos = (co - 1) % (in1[target]);
				cout << img[target][pos];
			}
			i++;
		}
		cout << endl;
	}
}