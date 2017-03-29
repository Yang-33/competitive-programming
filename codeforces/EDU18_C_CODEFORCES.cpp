#include <iostream>
#include <string>
using namespace std;

#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)

/* -----  2017/03/29  Problem: codeforces Educatinal18 C / Link: http://codeforces.com/contest/792/problem/C  ----- */
/* ------問題------

10^10000までの大きさの文字列が与えられるので、３の倍数になるように任意の桁を最小回数削除して３の倍数にせよ。
ただし０以外の数字では頭に０はついてはならない。

-----問題ここまで----- */
/* -----解説等-----

頭の数を消さない方がいいので右から見ていけばよさそう。
桁を足してその総和を３で割った余りと同じ数が桁に存在すればその一桁のみを削除すればよい。
そうでない場合は２桁を削除しなければならないので、なるべく右側のものを削除する。
削除した際に残った数字の頭に０がついていたらこれを削除する。

----解説ここまで---- */

string s, ss, ans;

int main()
{
    cin >> s;
    int dig = 0;
    FOR(i, 0, s.size()) {
        dig += s[i] - '0';
    }
    if (dig % 3 == 0)
        cout << s << endl;
    else
    {
        int t = dig % 3;
        for (int i = s.size() - 1; i >= 0; i--) {
            if ((s[i] - '0') % 3 == t) {
                ss = s;
                ss.erase(i, 1);
                while (ss.size() > 1 && ss[0] == '0')
                    ss.erase(0, 1);
                ans = ss;
                break;
            }
        }
        bool flag = false;
        for (int i = s.size() - 1; i >= 0; i--) {
            if ((s[i] - '0') * 2 % 3 == t) {
                s.erase(i, 1);
                if (flag) {
                    while (s.size() > 1 && s[0] == '0')
                        s.erase(0, 1);
                    if (s.size() > ans.size())
                        ans = s;
                    break;
                }
                flag = true;
            }
        }
        if (ans.size() > 0)
            cout << ans << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}