#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
/* -----  2017/03/30  Problem: CodeForces407 B div2 / Link: http://codeforces.com/contest/789/problem/B ----- */
/* ------���------

���� b_i+1=b_i * q���l����B
��q,b1�ƁA����an��l���^������̂ŁA|bi|��l�͈̔͂Ŏ�肤��i����Ȃ�bi�̂����Aa_k �Ƃ͈قȂ���̂̌������߂�B
���������ɏ����o����ۂɂ�inf�Əo�͂���B

-----��肱���܂�----- */
/* -----�����-----

q=0,q=1,q=1,b1=0, |b1|>l�̂Ƃ��ɏꍇ���������A����ȊO�͎w���֐��I�ɐ������傷��̂ŐV�����l������A
���ꂪan�ɂȂ����ǂ�����log���炢�Ŕ��肷��΂悢�B
set or unordered_set�Œʂ�B
�{�Ԃł͒ʂ炸�炢�v���������������悭�ǂ݂܂��傤�B

----��������܂�---- */

ll N;
unordered_set<ll> ss;
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    ll b, q, l, m;
    cin >> b >> q >> l >> m;
    vector<ll> a;
    FOR(i, 0, m) {
        ll s; cin >> s;
        a.push_back(s);
        ss.insert(s);
    }
    sort(a.begin(), a.end());
    if (b == 0) {// 0
        FOR(i, 0, m) {
            if (a[i] == b) {
                cout << 0 << endl;
                return 0;
            }
        }
        cout << "inf" << endl;
        return 0;
    }
    if (abs(b) > l) {
        cout << 0 << endl;
        return 0;
    }

    if (q == 0) {
        if (abs(b) > l) {
            FOR(i, 0, m) {
                if (a[i] == 0) {
                    cout << 0 << endl; return 0;
                }
            }
            cout << "inf" << endl; return 0;
        }

        bool f = false;//0*
        bool f2 = false;//b
        FOR(i, 0, m) {
            if (a[i] == 0) {
                f = true;
            }
            if (b == a[i]) f2 = true;
        }
        if ((f&&f2)||(f&&(b==0)))cout << 0 << endl;
        else if (f) cout << 1 << endl;
        else cout << "inf" << endl;

            return 0;
    }
    if (q == 1 ) {
        if (abs(b) <= l) { //b�̂�
            bool flag = false;
            FOR(i, 0, m) {
                if (b == a[i]) {
                    flag = true;
                    break;
                }
            }
            if (flag) {
                cout << 0 << endl; return 0;
            }
            else {
                cout << "inf" << endl; return 0;
            }
        }
        else cout << 0 << endl;
            return 0;
    }
    if (q == -1) {
        if (abs(b) <= l) { // b, -b*
            bool f = false, f2 = false;
            FOR(i, 0, m) {
                if (a[i] == b)f2 = true;
                if (a[i] == (-1)*b)f = true;
            }
            if (f&&f2)cout << 0 << endl;
            else cout << "inf" << endl;
            return 0;
        }
        else cout << 0 << endl; return 0;
    }
    else {
        ll nb = b;
        while (abs(nb) <= l) {
            //ll k = upper_bound(a.begin(), a.end(), nb) - lower_bound(a.begin(), a.end(), nb);
            ll k = ss.count(nb);
            if (k == 0)ans++;
            nb = nb*q;
        }
        if (ans >= 1e6)cout << "inf" << endl;
        else cout << ans << endl;
    }
    return 0;
}