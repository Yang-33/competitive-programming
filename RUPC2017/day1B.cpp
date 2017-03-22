//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define FOR(i, s, t) for (int i = s; i < t; i++)
/* -----  2017/03/22  Problem: RUPC2017 DAY1 B / Link:
 * http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day1&pid=B
 */
/* ------���------

�����N�Q��

-----��肱���܂�----- */
/* -----�����-----

��肽���O���[�v����lcm(N,M)/M�ł��邱�Ƃ��ł���̂Ŋe�O���[�v�̒���
a[i]�����Ă����΂悢�Bvector�Ŏ��Ƃ������񂶂�sort�ł���̂ōŏ��l�ƍő�l���ȒP�Ɏ��o�����Ƃ��ł���B
���c�̐�͂����Ɏ����ł������Y����������Ă������Ƃœ��������������Ȃ�ł�����WA�Ȃ���AC�B

----��������܂�---- */

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
  int M, N;
  int a[1010];
  cin >> N >> M;
  FOR(i, 0, N) {
    cin >> a[i];
    //
  }

  int T = lcm(N, M) / M;
  vector<int> box[T];
  int next = 0;

  FOR(i, 0, T) {
    FOR(j, 0, M) {
      box[i].push_back(a[(next + j) % N]);
      //
    }
    next = (next + M) % N;
  }

  long long ans = 0;
  FOR(i, 0, T) {
    sort(box[i].begin(), box[i].end());
    ans += (box[i][M - 1] - box[i][0]);
  }

  cout << ans << endl;
}
