#include<iostream>
#include<string>
using namespace std;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/09  Problem: ARC052 A / Link: http://arc052.contest.atcoder.jp/tasks/arc052_a ----- */
/* ------問題------

高橋くんの通う学校では、創立された年に入学した生徒を 1 期生、その次の年に入学した生徒を 2 期生、といったように呼びます。
つまり、(入学した年?創立された年)+1=n の時に n 期生と呼ばれることとなります。
また、高橋くんの学校内では生徒がみな ID を持っており、それぞれの ID には必ず自分の期の数字が含まれることがわかっています。

ある生徒の ID が文字列 S として与えられるとき、その生徒が何期生であるかを回答してください。

また、数字が 2 つ連続して並んでいる場合は 2 桁の数字を意味するものとします。

-----問題ここまで----- */
/* -----解説等-----

正規表現が使えたらもっと簡単なのに・・・

 ----解説ここまで---- */

string N;

string ans;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N.size()) {
        if (N[i] >= '0'&&N[i] <= '9') {
            ans += N[i];
        }
    }
    cout << ans << endl;
    
    return 0;
}