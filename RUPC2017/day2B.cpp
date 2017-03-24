#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

int main() {
    int N;
    vector<double>a;
    vector<double>b;
    cin >> N;
    for (int i = 0; i < N; i++) {
        double s; cin >> s;
        a.push_back(s);
        b.push_back(s);
    }
    sort(b.begin(), b.end());
    for (int i = 0; i < N; i++) {
        //int big = N - (int)(upper_bound(b.begin(), b.end(), a[i]) - b.begin());
        int same = (upper_bound(b.begin(), b.end(), a[i]) - b.begin()) - (lower_bound(b.begin(), b.end(), a[i]) - b.begin())-1;
        int small = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
        cout << same + 3 * small << endl;;
       // cout <<same << " "<<small << endl;
    }
    return 0;
}