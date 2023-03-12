#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int map[100][100];

int solution(int m, int n, vector<vector<int>> puddles) {
    map[2][1] = 1; //시작점 위 아래 1로 시작
    map[1][2] = 1;


    for (int i = 0; i < puddles.size(); i++)
        map[puddles[i][0]][puddles[i][1]] = -1;//웅덩이 위치에 -1

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (map[i][j] == -1) continue;//웅덩이 지나감
            if (map[i][j - 1] != -1)
                map[i][j] = (map[i][j] + map[i][j - 1]) % 1000000007;
            if (map[i - 1][j] != -1)
                map[i][j] = (map[i][j] + map[i - 1][j]) % 1000000007;
        }

    }
    return map[m][n];
}