#include <iostream>


using namespace std;
int visit[11] = { false, };
int N;
int W[11][11];
int minvalue = 1000001;


void dfs(int start, int index,int count,int sum) {
    if (count == N) {
        if (W[index][start] == 0)
            return;
        if (minvalue > sum + W[index][start])
            minvalue = sum + W[index][start];
        return;
    }
    for (int i = 0; i < N; i++) {
        if (visit[i] || W[index][i] == 0)
            continue;
        visit[i] = true;
        dfs(start, i, count + 1, sum + W[index][i]);
        visit[i] = false;
    }
}

int main(void) {
    
    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> W[i][j];

        }
    }
    for (int i = 0; i < N; i++) {
        visit[i] = true;
        dfs(i, i, 1, 0);
        visit[i] = true;
    }

    cout << minvalue;
    return 0;
}
