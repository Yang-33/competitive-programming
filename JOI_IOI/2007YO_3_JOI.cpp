#include <iostream>
#include <string>
using namespace std;
typedef long long ll;
#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/27  Problem: JOI莠磯∈2007 3  / Link: http://www.ioi-jp.org/joi/2006/2007-yo-prob_and_sol/2007-yo-problems/2007-yo-t3/2007-yo-t3.html  ----- */
/* ------蝠城｡

ガイウス・ユリウス・カエサル（Gaius Julius Caesar)， 英語読みでジュリアス・シーザー（Julius Caesar）は， 古代ローマの軍人であり政治家である． 
カエサルは， 秘密の手紙を書くときに， 'A' を 'D' に， 'B' を 'E' に， 'C' を 'F' に， というように3つずらして表記したという記録が残っている．

大文字のアルファベット26文字だけからなる文字列を， カエサルがしたように3文字ずつずらす変換を施し得られた文字列がある． 
このような文字列を元の文字列に戻すプログラムを作成せよ．

各文字の変換前と変換後の対応は次のようになる．

変換前    A B C D E F G H I J K L M N O P Q R S T U V W X Y Z
変換後    D E F G H I J K L M N O P Q R S T U V W X Y Z A B C
例えば， この方法で文字列 JOI を変換すると MRL が得られ， この方法で変換された文字列 FURDWLD の元の文字列は CROATIA である．

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

string S;
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(false);

  cin >>S;
  FOR(i, 0, (int)S.size()) {
      S[i] = (S[i] - 'A' + 26 - 3) % 26 + 'A';
  }

  cout << S << endl;

  return 0;
}
