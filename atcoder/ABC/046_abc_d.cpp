#include<iostream>
#include<string>
#include<stack>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 問題 -----  ABC046 D /Link http://abc046.contest.atcoder.jp/tasks/arc062_b */
/* -----解説等-----
問題: シカのAtCoDeerくんは友達のTopCoDeerくんとあるゲームをして対戦しています。
このゲームは N ターンからなります。各ターンではそれぞれのプレイヤーはじゃんけんのグーかパーを出します。
ただし、各プレイヤーは次の条件を満たす必要があります。

(※) 各ターンの後で、(今までにパーを出した回数)≦(今までにグーを出した回数)　を満たす

このゲームでの各プレイヤーの得点は、(勝ったターンの数) ? (負けたターンの数) です。 
AtCoDeerくんは特殊能力を持っているので、ゲームが始まる前にTopCoDeerくんの出す N ターンの手を全て知ることが出来ました。 
AtCoDeerくんの各ターンでの手を決めて、AtCoDeerくんの得点を最大化してください。
TopCoDeerくんの出す手の情報は文字列 s で与えられます。 
s の i(1≦i≦N) 文字目が gのときは i ターン目でTopCoDeerくんがグーを出すことを、 pのときはパーを出すことを表します。

制約
1≦N≦10^5
N=|s|
s の各文字はgかp
s で表される手は、条件(※)を満たしている

AtCoDeerくんの得点の最大値を出力せよ。


部分問題。順番に勝てるときに勝ち、負けないという選択ができれば負けないようにする。
おわり。

*/

string S;
stack<int> sta;
int ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    FOR(i, 0, S.size()) {
        if (!sta.empty()) {
            if (S[i] == 'g') {
                sta.pop();
                ans++;
            }
            else {
                sta.pop();
            }
        }
        else {
            if (S[i] == 'g') {
                sta.push(1);
            }
            else {
                sta.push(1);
                ans--;
            }
        }
    }

    cout << ans << endl;

    return 0;
}