#include<bits/stdc++.h>
using namespace std;


#define FOR(i,s,t) for(int i = s; i< t; i++)

class Deadfish
{
public:
	int f(int x) {
		string s;
		while (x) {
			s += string(1, x % 10 + '0');
			x /= 10;
		}
		sort(s.rbegin(), s.rend());
		return stoi(s);
	}
	int shortestCode(int N)
	{
		vector<long long> dp(400005, 1e18);
		dp[0] = 0;
		map<int, int>Map;
		FOR(i, 1, 400005) {
			Map[i] = f(i);
		}
		queue<int>q;
		q.push(0);
		map<int, int>visit;
		while (!q.empty()) {
			long long i = q.front(); q.pop();
			if (visit[i])continue;
			visit[i] = 1;
			if (i + 1 <= 400000 && dp[i + 1] > dp[i] + 1) {
				dp[i + 1] = dp[i] + 1;
				q.push(i + 1);
			}
			if (i >= 1 && dp[i - 1] > dp[i] + 1) {
				dp[i - 1] = dp[i] + 1;
				q.push(i - 1);
			}if (i*i <= 400000 && dp[i*i] > dp[i] + 1) {
				dp[i*i] = dp[i] + 1;
				q.push(i*i);
			}if (Map[i] <= 400000 && dp[Map[i]] > dp[i] + 1) {
				dp[Map[i]] = dp[i] + 1;
				q.push(Map[i]);
			}

		}
		return dp[N];
	}
};

int main() {
	int N; cin >> N;
	Deadfish a;
	cout<<a.shortestCode(N)<<endl;

}