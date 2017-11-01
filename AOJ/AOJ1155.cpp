#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i,s,e) for(int(i)=(s);(i) < (e);(i)++)
#define debug(x) cout << #x << ": " << x << endl
/* -----  2017/11/01  Problem: AOJ1155  / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1155   ----- */
/* ------問題------

三値論理は値として "真"，"偽" に加え "未知" を許す論理体系である． 以下では，"偽"，"未知"，"真" を 0, 1, 2 でそれぞれ表す．

"-" を単項演算子（すなわち，値ひとつを受け取る関数を表す記号）とし， "*" と "+" を二項演算子（すなわち，値ふたつを受け取る関数を表す記号）とする． これらは，それぞれ否定 (NOT), 論理積 (AND), 論理和 (OR) を表す演算子であり， 三値論理におけるこれらの演算は表 C-1 に示すように定義できる．

表 C-1: 三値論理演算子の真理値表
-X		(X*Y)		(X+Y)

P, Q, R を三値論理の変数とする． 与えられた論理式を満足する， つまり論理式の値が 2 になるような (P,Q,R) の三つ組が何通りあるかを答えるのがあなたの役割だ． 論理式は以下のいずれかの形式である（ここで X, Y はまた論理式であるとする）．

定数: 0, 1 または 2
変数: P, Q または R
否定: -X
論理積: (X*Y)
論理和: (X+Y)
上記のように，ふたつの論理式の論理積や論理和は必ず括弧で囲む．

たとえば，入力 (P*Q) に対しては，(P,Q,R) が (2,2,0)，(2,2,1)，(2,2,2) の場合， かつその場合のみ，この論理式の値が 2となるので，3を出力すればよい．

-----問題ここまで----- */
/* -----解説等-----

構文解析。
LL(1)なのでこれは3^3通りの組み合わせを全部検査すればよい。

----解説ここまで---- */
const int INF = 1e9;
const ll LINF = 1e16;
int N;
string expr0(int &i, string &s);
string expr1(int &i, string &s);

void changes(string &s, char a, char b, char c) {
	FOR(i, 0, s.size()) {
		if (s[i] == 'P') {
			s[i] = a;
		}
		else	if (s[i] == 'Q') {
			s[i] = b;
		}
		else	if (s[i] == 'R') {
			s[i] = c;
		}
	}
}

string expr1(int &i, string &s) {
	if (isdigit(s[i])) {
		string num = to_string(s[i] - '0');
		i++;
		return num;
	}
	if (s[i] == '-') {
		i++;
		string num = expr1(i, s);
		if (num == "2")return "0";
		if (num == "0")return "2";
		if (num == "1")return "1";
	}
	if (s[i] == '(') {
		i++;
		string num = expr0(i, s);
		i++;
		return num;
	}
	return "";
}

string expr0(int &i, string &s) {
	string num = expr1(i, s);
	int flag = -1;
	while (i < N && (s[i] == '+' || s[i] == '*')) {
		char op = s[i];
		i++;
		if (op == '+') {
			num += expr0(i, s);
			flag = 1;
		}
		else if (op == '*') {
			num += expr0(i, s);
			flag = 2;
		}
	}

	if (flag == 1) {
		FOR(k, 0, num.size()) {
			if (num[k] == '2')return "2";
		}
		FOR(k, 0, num.size()) {
			if (num[k] == '1')return "1";
		}
		return "0";
	}
	else if (flag == 2) {
		FOR(k, 0, num.size()) {
			if (num[k] == '0')return "0";
		}
		FOR(k, 0, num.size()) {
			if (num[k] == '1')return "1";
		}
		return  "2";
	}
	return num;

}


int main() {
	cin.tie(0); ios::sync_with_stdio(false);
	while (true) {
		string S; cin >> S;
		if (S[0] == '.')break;
		int ans = 0;
		N = S.size();
		FOR(i, 0, 3) {
			FOR(j, 0, 3) {
				FOR(k, 0, 3) {
					string ss = S;
					changes(ss, '0' + i, '0' + j, '0' + k);
					int p = 0;
					if (expr0(p, ss) == "2") {
						ans++;
					}
				}
			}
		}


		cout << ans << endl;
	}


	return 0;
}