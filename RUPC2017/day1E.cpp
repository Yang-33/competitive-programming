#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
#define FOR(i, s, t) for (int i = s; i < t; i++)

/* -----  xtimex  Problem: RUPC2017 E / Link:
 * http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=E
 */
/* ------���------

�����N�Q��

-----��肱���܂�----- */
/* -----�����-----

������dp���ۂ��ł��˂ƃI������Ƙb���Ă���A�t�����猩�������悳�����H�Ȃǂƍl���Ă���
�l����Ԃ̎�������dp[���݂݂Ă��镶��][����܂�Ԃ�����]�ł͂悭�킩��Ȃ��ƌ���������ɔ��]�̕������㉺��[2][2]�Ŏ��Ă΂����̂ł́H
�Ƃ̃A�h�o�C�X���������������B�e���p���đJ�ڂ��킩��Ȃ��Ȃ�������������̂������Ă��܂�����j�Ɋւ��郋�[�v��K�܂ŉ񂵐؂�Ȃ��Ƃ����Ȃ�������
0~K�܂ŉ��͈قȂ邱�ƂɋC�t�������x�������Ă�������B
�r���p�\�R�����_�E�������肵����A�R���e�X�g�I���񕪌�ɂ`�b�B
�������G�G�@���l�X�Ȓm���𓾂��̂ŕ׋��ɂȂ����B
memset�ł͒ʂ�Ȃ����Ƃ�{���ɗ��������̂Ŏg�p�������J�ɏ�����������ׂ��B
�œK�ȃR�[�h�͋A�����珑��
dp[�����Ă��镶��][����Ђ�����Ԃ�����][�㉺�ɔ��]���Ă��邩][���E�ɔ��]���Ă��邩]
:= ���݂̐ݒ�̍ő�l�B
�����dp[S][0-K+1][0-2][0-2]�ōő�l���Ƃ�΂悢�B

----��������܂�---- */

int dp[2010][2010][2][2];

int main() {
  string S;
  int K;
  cin >> S >> K;
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {
    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;

            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  int ans = 0;
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  // cout << "ans? " << ans << endl;
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {
    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  // int ans = 0;
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {

    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  FOR(i, 0, 2010)
  FOR(j, 0, 2010) FOR(k, 0, 2) FOR(l, 0, 2) dp[i][j][k][l] = -1e9;
  FOR(k, 0, 2) FOR(l, 0, 2) dp[0][0][k][l] = 0;

  FOR(i, 0, S.size()) {
    FOR(k, 0, K + 1) {
      if (S[i] == 'U') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'D') {
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 1)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          int x = 1;
          if (u == 0)
            x = -1;
          FOR(r, 0, 2) {
            dp[i + 1][k + 1][(u + 1) % 2][r] =
                max(dp[i + 1][k + 1][(u + 1) % 2][r], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'R') { // 0 ??????0 ???
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      } else if (S[i] == 'L') {
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 1)
              x = -1;
            dp[i + 1][k][u][r] = max(dp[i + 1][k][u][r], dp[i][k][u][r] + x);
          }
        }
        FOR(u, 0, 2) {
          FOR(r, 0, 2) {
            int x = 1;
            if (r == 0)
              x = -1;
            dp[i + 1][k + 1][u][(r + 1) % 2] =
                max(dp[i + 1][k + 1][u][(r + 1) % 2], dp[i][k][u][r] + x);
          }
        }
      }
    }
  }
  FOR(k, 0, K + 1) FOR(u, 0, 2) FOR(r, 0, 2) {
    ans = max(ans, dp[S.size()][k][u][r]);
  }
  cout << ans << endl;
  return 0;
}