#include<iostream>
#include<cmath>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/02  Problem: ABC010 C / Link: https://abc010.contest.atcoder.jp/tasks/abc010_3 ----- */
/* ------問題------

高橋君の秘書のなぎさちゃんは、高橋君が大好きです。今日も高橋君に電話をかけてみることにしました。
すると、どうでしょう？　電話口から、高橋君の声以外の、女の声が聞こえてきます。
なぎさちゃんは、高橋君と付き合ってはいませんが、高橋君に悪い虫が付いたら大変なので、浮気調査を行うことにしました。
高橋君の携帯に仕込んだアプリケーションから、高橋君の居場所をGPSで取得すると、高橋君は、電話をかける前は座標 (txa,tya) に、
電話をかけた後は、座標 (txb,tyb) にいることがわかりました。また、この間にかかった時間は T 分です。
高橋君は、最大毎分 V の距離を移動することが可能であり、家などの障害物を無視して同じ速度で移動することが可能です。
なぎさちゃんは、このデータを元に、高橋君が、近所の女の子の家に寄っていないかを調査することにしました。
近所の女の子は n 人おり、それぞれ座標 (xi,yi) に住んでいます。
高橋君が、他の女の子の家に寄った可能性が少しでもある場合はYES、そうでない場合はNOと出力しなさい。

-----問題ここまで----- */
/* -----解説等-----

誤差にだけ注意。

 ----解説ここまで---- */

ll N;
int sx, sy, tx, ty, T, V;
bool flag = false;
ll ans = 0LL;
double eps = 1e-6;

bool f(int X, int Y) {
    double l = sqrt((sx - X)*(sx - X) + (sy - Y)*(sy - Y)) + sqrt((tx - X)*(tx - X) + (ty - Y)*(ty - Y));
    if (l < T*V + eps)return true;
    else return false;

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> sx >> sy >> tx >> ty >> T >> V;
    cin >> N;

    FOR(i, 0, N) {
        int x, y;
        cin >> x >> y;
        if (f(x, y))flag = true;
    }

    if (flag)cout << "YES" << endl;
    else    cout << "NO" << endl;

    return 0;
}