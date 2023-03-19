#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 16

int N;
int T[MAX] = { 0, };
int P[MAX] = { 0, };
int res[MAX] = { 0, };




void dp() {
	int deadline;

	for (int i = N; i > 0; i--) {
		deadline = i + T[i];
		if (deadline > N + 1) {
			
			res[i] = res[i + 1];
		}
		else {
			
			res[i] = max(res[i + 1], res[deadline] + P[i]);
		}
	}
}

int main() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> T[i] >> P[i];
	}
	dp();

	cout << res[1] << endl;
	return 0;
}