#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
vector<int> arr;

void main() {
	int n;
	int input;
	int answer=0;

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> input;
		arr.push_back(input);
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] > arr[i + 1])
			answer++;
	}
	cout << answer;
}