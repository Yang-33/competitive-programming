#include "bits/stdc++.h"
using namespace std;

typedef long long ll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/04/08  Problem: ARC 071 A / Link: http://arc071.contest.atcoder.jp/tasks/arc071_a  ----- */
/* ------問題------

すぬけ君は、文字列の書かれた紙から文字をいくつか切り抜いて、並び替えて別の文字列を作るのが好きです。
明日になると、すぬけ君は文字列 S1,…,Sn のうちどれか 1 つが書かれた紙がもらえます。 
すぬけ君は文字列を作る事をとても楽しみにしているので、どんな文字列を作るか計画を立てることにしました。 ただし、すぬけ君はまだどの文字列が書かれた紙がもらえるかを知らないため、 どの文字列が書かれていた場合にも作れる文字列を考えることにしました。
S1,…,Sn のどの文字列が書かれていても作れる文字列のうち、最長のものを求めてください。 
最長のものが複数ある場合は、辞書順で最小のものを求めてください。

-----問題ここまで----- */
/* -----解説等-----

順番に依存しないので各文字列に含まれるアルファベットをカウントし、最小の数を求める。
その後最小のアルファベットをaから順番に出力していけばよい。

----解説ここまで---- */

ll N;

int ans = 0;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  int a[50][30];
  FOR(i, 0, 50)FOR(j, 0, 30)a[i][j] = 0;

  cin >> N;
  FOR(i, 0, N) {
	  string s;
	  cin >> s;
	  FOR(j, 0, s.size()) {
		  a[i][s[j]-'a']++;
	  }
  }
  FOR(i, 0, 30) {
	  ans = INF;
	  FOR(j, 0, N) {
		  ans = min(ans, a[j][i]);

	  }
	  char c = 'a' + i;
	  FOR(j, 0, ans) {
		  
		  cout << c;
	  }
  }
  cout << endl;
  return 0;
}
