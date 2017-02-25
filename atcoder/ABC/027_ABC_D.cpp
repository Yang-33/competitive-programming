#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
const int INF = 1e9;
typedef long long ll;

/* -----  2017/02/25  Problem: ABC027 D / Link: http://abc027.contest.atcoder.jp/tasks/abc027_d ----- */
/* ------問題------

数直線の原点にロボットが置かれている。 はじめ、ロボットの幸福度は 0 である。
このロボットに命令列が与えられる。 命令列は次の 3 文字のみからなり、先頭から末尾まで順に実行される。

M : 正または負の好きな向きに、距離 1 だけ移動する。
+ : 今の座標を x とすると、幸福度が +x だけ変化する。
- : 今の座標を x とすると、幸福度が ?x だけ変化する。
命令列を実行し終えた後、 ロボットは原点に戻っていなければならない 。 命令列を実行している間、ロボットの座標および幸福度は負になり得る。

最終的な幸福度を最大化するようにロボットが移動したとき、最終的な幸福度を求めよ。

-----問題ここまで----- */
/* -----解説等-----

Mが二択で分かれておりこれをすべて決めることは計算量的に不可能である。
+-が先に分かっていることから あるMの移動方向を決めた際に増加する幸福度を求めておき、
これを大きい順にとっていけばよい。
残った要素は逆の方向に移動するものと考えて減算すれば答えが求まる。

競技プログラミング以外の場所でやったことがある問題だった。

 ----解説ここまで---- */

string N;
vector<int>V;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    int Nsize = N.size();

    int p = 0, m = 0;
    FORR(i, Nsize - 1, -1) {
        if (N[i] == '+') {
            p++;
            continue;
        }
        else if (N[i] == '-') {
            m++;
            continue;
        }
        V.push_back(p - m);
    }

    int Vsize = V.size();

    sort(V.begin(), V.end());
    FOR(i, 0, Vsize / 2) {
        ans -= V[i];
    }
    FOR(i, Vsize / 2, Vsize) {
        ans += V[i];
    }

    cout << ans << endl;

    return 0;
}