#include<iostream>
#include<map>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 問題 ----- ABC045 D /Link http://abc045.contest.atcoder.jp/tasks/arc061_b */
/* -----解説等-----
問題: 縦 H 行、横 W 列のマス目からなる盤があります。最初、どのマス目も白く塗られています。
すぬけ君が、このうち N マスを黒く塗りつぶしました。i 回目 ( 1≦i≦N ) に塗りつぶしたのは、 上から ai 行目で左から bi 列目のマスでした。
すぬけ君がマス目を塗りつぶした後の盤の状態について、以下のものの個数を計算してください。
各整数 j ( 0≦j≦9 ) について、盤の中に完全に含まれるすべての 3 行 3 列の連続するマス目のうち、黒いマスがちょうど j 個あるもの。

制約
3≦H≦109
3≦W≦109
0≦N≦min(105,H×W)
1≦ai≦H (1≦i≦N)
1≦bi≦W (1≦i≦N)
(ai,bi)≠(aj,bj) (i≠j)

各マスがカウント結果に影響を及ぼすのは最大９マス、かつ走査の対象になるのは 2 ~ W-1 and 2 ~ H-1
mapで数え上げすれば楽。
mapの値のほうをキーとしてansを増やす

*/

ll H, W, N;
map<pair<int, int>, int>mp;
ll left0;
ll ans[10];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> H >> W >> N; //y,x

    int a, b; //1 -> H or W

    FOR(i, 0, N) {
        cin >> b >> a;
        FOR(x, -1, 2)FOR(y, -1, 2) {
            if (a + x >= 2 && a + x <= W - 1 && b + y >= 2 && b + y <= H - 1)
                mp[make_pair(a + x, b + y)]++;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); it++) {
        ans[it->second]++;
    }

    left0 = (H - 2)*(W - 2)-mp.size();

    cout << left0 << endl;

    FOR(i, 1, 10)
        cout << ans[i] << endl;

    return 0;
}