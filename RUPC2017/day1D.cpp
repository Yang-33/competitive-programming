#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
using namespace std;

/* -----  2017/03/22  Problem: RUPC2017 DAY1 D / Link:
 * http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=D
 */
/* ------���------

�����N�Q��

-----��肱���܂�----- */
/* -----�����-----

c7c7�����omu����̍l�@�Ǝ����B
�l�@�͕�������������������܂ŉ�@�𗝉����Ă��Ȃ������B
unorderde_set�̓n�b�V���ɂȂ��Ă���̂Ō������Ώۂ̃T�C�Y�ōςށB
���񂩂�𓚂��S�����ȓ��ł��邱�Ƃ��m�肵�Ă���̂�
������l�߂Ă����Ă̂��Ɏ������ŏ����猟�����Ă����΂悢�B
set�ł͒ʂ�Ȃ��̂Œ��ӁB

----��������܂�---- */

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