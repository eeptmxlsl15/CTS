#include <vector> 
using namespace std;

bool check[200];

void dfs(int curComputer, int n, vector< vector<int> > computers) {
    // 현재 컴퓨터를 가르키는 인덱스에 check
    check[curComputer] = true;

    for (int i = 0; i < n; i++) {
        
        if (check[i] == false && computers[curComputer][i] == 1) {
            //탐색하지 않았고 현재 컴퓨터와 연결되어있는 컴퓨터 찾기
            dfs(i, n, computers);
        }
    }
}

int solution(int n, vector< vector<int> > computers) {
    int answer = 0;

    for (int i = 0; i < n; i++) {
        
        if (check[i] == false) {//검사하지 않았을때
            dfs(i, n, computers);

            //dfs가 연결된 점들을 다 돌고 끝났을때 +1
            answer++;
        }
    }

    return answer;
}
