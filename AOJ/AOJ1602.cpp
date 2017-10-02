#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define debug(x) cout << #x << ": " << x << endl
#define ALL(x) (x).begin(),(x).end()

const int INF = 1e9;
const ll LINF = 1e16;

/* -----  2017/10/02  Problem: ICPC国内2015 C / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1602  ----- */
/* ------問題------

逆ポーランド記法っぽいやつ
こたえは？

-----問題ここまで----- */
/* -----解説等-----

構文解析練習しなきゃ・・・

----解説ここまで---- */



int N;

int Count(string&s) {
	int count = 0;
	for (auto c : s) {
		if (c == '.')count++;
	}
	return count;
}

int f(bool x, int at, int n, vector<string>&s) {
	int ret;
	if (x) ret = 1;
	else ret = 0;
	for (int i = at; i < N; i++) {
		if (Count(s[i]) >= n) {
			if (s[i][n] == '*') { //ret *= f(true, i + 1, n + 1, s); 

				if (x) ret *= f(true, i + 1, n + 1, s); //(s[i][n] - '0');
				else ret += f(true, i + 1, n + 1, s);// (s[i][n] - '0');

				continue;
			}
			else if (s[i][n] == '+') {
				//ret += f(false, i + 1, n + 1, s); 

				if (x) ret *= f(false, i + 1, n + 1, s);
				//(s[i][n] - '0');
				else ret += f(false, i + 1, n + 1, s);
				//(s[i][n] - '0');

				continue;
			}
			else if (s[i][n] == '.')continue;

			if (x) ret *= (s[i][n] - '0');
			else ret += (s[i][n] - '0');

			//cout << "kassa" <<  ret << "/" << N << endl;
		}
		else break;
	}
	return ret;
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	while (1) {
		cin >> N;
		if (N == 0)break;
		if (N == 1) { int ans; cin >> ans; cout << ans << endl; continue; }
		vector<string>S(N + 5);
		FOR(i, 0, N)cin >> S[i];
		if (S[0][0] == '*') cout << f(true, 1, 1, S);
		else cout << f(false, 1, 1, S);
		cout << endl;
	}

	return 0;
}
