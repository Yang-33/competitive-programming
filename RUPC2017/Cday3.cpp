#include<iostream>
#include<string>
#define FOR(i,s,t) for(int (i)=(s);(i)<(t);i++)
using namespace std;
int a[30];

int main() {
    string S;
    cin >> S;
    FOR(i, 0, S.size()) {
        a[S[i] - 'a']++;
    }
    int cnt = 0;
    FOR(i, 0, 26) {
        if (a[i] % 2 == 1) {
            cnt++;
        }
    }
    if (cnt == 1) {
        cout << 0 << endl;
        return 0;
    }
    if (cnt % 2 == 1) {
        cnt -= 1;
    }
    cout << cnt / 2 << endl;


}