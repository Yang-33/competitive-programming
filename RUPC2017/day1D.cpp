#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
using namespace std;

/* -----  2017/03/22  Problem: RUPC2017 DAY1 D / Link:
 * http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=D
 */
/* ------問題------

リンク参照

-----問題ここまで----- */
/* -----解説等-----

c7c7さんとomuさんの考察と実装。
考察は分かったが実装を見るまで解法を理解していなかった。
unorderde_setはハッシュになっているので検索が対象のサイズで済む。
制約から解答が４文字以内であることが確定しているので
これを詰めていってのちに辞書順最小から検索していけばよい。
setでは通らないので注意。

----解説ここまで---- */

int main() {
  unordered_set<string> a;
  int n;
  cin >> n;
  string s[n];
  r(i, n) cin >> s[i];
  for (int i = 1; i < 5; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < s[j].size(); k++) {
        if (k + i <= s[j].size())
          a.insert(s[j].substr(k, i));
      }
    }
  }
  r(k, 27) {
    r(l, 27) {
      r(m, 27) {
        r(o, 26) {
          string t;
          if (k)
            t += 'a' + k - 1;
          if (l)
            t += 'a' + l - 1;
          if (m)
            t += 'a' + m - 1;
          t += 'a' + o;
          if (!a.count(t)) {
            cout << t << endl;
            return 0;
          }
        }
      }
    }
  }
}