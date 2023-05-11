#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <time.h>

using namespace std;

int L, C;
char arr[20];

bool visited[20];
char temp[20];

void dfs(int dep, int index) {
    for (int i = index; i < C; i++) {
        if (dep == L) {//길이 충족 시 
            int m = 0, n = 0;
            for (int i = 0; i < C; i++) {//모음이 있을때 m 증가, 그외에 n 증가
                if (visited[i]) {
                    if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                        m++;
                    else
                        n++;
                }
            }
            if (m >= 1 && n >= 2) {//조건 달성 시
                for (int i = 0; i < C; i++) {
                    if (visited[i])//현재 들린 곳에서만 출력
                        cout << arr[i];

                }
                cout << endl;
            }
            return;
        }
        
        if (!visited[i]) {
            visited[i] = true;
            dfs(dep + 1, i);
            visited[i] = false;
        }

    }
}

int main() {
    cin >> L >> C;
    for (int i = 0; i < C; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + C);
    
    dfs(0,0);
    
    

}