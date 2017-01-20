#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/20 問題 -----  ABC047 C /Link http://abc047.contest.atcoder.jp/tasks/arc063_a */
/* -----解説等-----
問題: きつねの次郎と三郎が一次元リバーシで遊んでいます。
一次元リバーシでは、盤面には白か黒の石が一列に並んだ状態となっており、列の右端か左端に新たに石を打っていきます。
通常のリバーシと同じように、たとえば白の石を打つことで黒の石を挟むと、挟まれた黒の石は白い石に変わります。

ゲームの途中で三郎に急用ができて帰ってしまうことになりました。
このとき、盤面の状態は文字列 S で表されます。石は |S| (文字列の長さ) 個並んでおり、
左から i (1≦i≦|S|) 個目の石の色は、S の i 文字目が B のとき黒、W のとき白です。

次郎は現在の盤面に対して、できるだけ少ない個数の石を新たに打つことで全ての石を同じ色にしようと考えました。
最小で何個の石を打てばよいかを求めてください。


左右どちらから置くに関わらず、更新回数は片方から連続するオセロの色を見て
黒白が交わる回数である。
WWWWWW => 0
WWWBBB => 1
BWBWWW => 3
スタックに積んだら判定が楽になったが、一つ手前の色が何であったかを保存できれば何でもよい。


*/

string S;
stack<int>sta;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> S;
    sta.push(S[0]);
    FOR(i, 0, S.size()) {
        if (sta.top() != S[i]) {
            sta.push(S[i]);
        }
    }

    cout << sta.size()-1 << endl;

    return 0;
}