#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

#define FOR(i,s,e) for(int (i)=(s);(i)<(e);(i)++)

/* 2017/01/15 問題 DPL_3_B Name/Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_3_B */
/* -----解説等-----
問題: 最大長方形
一辺が 1 cm のタイルが、H × W 個並べられています。
タイルは汚れているもの、綺麗なもののいずれかです。
綺麗なタイルのみを使ってできる長方形の面積の最大値を求めてください。

正方形の場合では純粋dpであったが長方形の場合には上手くいかないので
今回は各列に続くタイルの数をdpで求め、各行に対してヒストグラム長方形の最大値と同様の計算を行う。
計算量は H*ヒストグラム最大長方形 から、Ｏ(H*W)となる。


非単調減少である区間ではスタックに高さと区間を積む。（ただし非増加区間では何もしない）
そうでないときにはスタックのトップよりも現在の区間の先端が大きくなるまでスタックから取り出し、計算を行う。
条件外のときは、最後の区間左端と現在の高さを記録し次の区間へ移る。

*/

#define MAX_W 1400 
#define MAX_H 1400
int tile[MAX_H][MAX_W];
int dp[MAX_H][MAX_W];
struct Rectangle { int h; int pos; };//height and position
int ans = 0;

int LargestRectangle(int size, int buf[]) {
    stack<Rectangle> S;
    int maxv = 0;
    buf[size] = 0;

    FOR(i, 0, size + 1) {
        Rectangle rect;
        rect.h = buf[i];
        rect.pos = i;
        if (S.empty()) {
            S.push(rect);
        }
        else {
            if (S.top().h < rect.h) {
                S.push(rect);
            }
            else if (S.top().h > rect.h) { 
                //ループから外れた際の処理は通常通りスタックに積むこと
                int target = i; //pre.pos
                while (!S.empty() && S.top().h >= rect.h) {
                    Rectangle pre = S.top(); S.pop();
                    int area = pre.h * (i - pre.pos);
                    maxv = max(maxv, area);
                    target = pre.pos;
                }
                rect.pos = target;
                S.push(rect);
            }
        }
    }
    return maxv;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    FOR(i, 0, H) {
        FOR(j, 0, W) {
            cin >> tile[i][j];
        }
    }
    FOR(i, 0, H) {
        FOR(j, 0, W) {
            if (tile[i][j] == 1) { //dirty
                dp[i][j] = 0;
            }
            else { //clean
                if (i == 0) dp[i][j] = 1;
                else dp[i][j] = dp[i - 1][j] + 1;
            }
        }
    }

    FOR(i, 0, H) {
        ans = max(ans, LargestRectangle(W, dp[i]));
    }

    cout << ans << endl;

    return 0;
}OB
