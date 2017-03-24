#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main() {
    int a, b;
    cin >> a >> b;
    double ans = 2000;
    for (int i = -720; i <= 720; i++) {
        int t = i;
        if ((2*a + t)%360 == (2*b - t)%360) {
          //  cout << "t: " << t << endl;

            if(abs(ans)>abs(t))
            ans = (double)t;
        }
    }
    ans = a + ans/2;
    printf("%.10lf\n", ans);
    return 0;
}