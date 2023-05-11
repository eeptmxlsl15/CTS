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
        if (dep == L) {//���� ���� �� 
            int m = 0, n = 0;
            for (int i = 0; i < C; i++) {//������ ������ m ����, �׿ܿ� n ����
                if (visited[i]) {
                    if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
                        m++;
                    else
                        n++;
                }
            }
            if (m >= 1 && n >= 2) {//���� �޼� ��
                for (int i = 0; i < C; i++) {
                    if (visited[i])//���� �鸰 �������� ���
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