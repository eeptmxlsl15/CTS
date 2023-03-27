#include<iostream>

using namespace std;

int T;
int n;
long long dp[1000001];

int main() {
	cin >> T;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	
	for (int i = 0; i < T; i++) {
		cin >> n;

		if(n<4)
			cout << dp[n] % 1000000009 << endl;
		else {
			for (int j = 4; j < n; j++) {
				dp[j] = dp[j - 3] + dp[j - 2] + dp[j - 1];

			}
			cout << dp[n] % 1000000009 << endl;
		}
	}
	return 0;
}