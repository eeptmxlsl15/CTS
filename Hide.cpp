#include<iostream>
#include<queue>
#include<stack>
#include<string>

using namespace std;

queue<int> que;
stack<int> path;
int time = 0;
bool visit[100000];
int parent[100000];

int N, K;


void bfs() {
    while (!que.empty()) {
        int first = que.front();//°¡Àå ¸ÕÀú µé¾î¿Â °ª º¹»ç
        que.pop();
        
        if (first == K) {
            path.push(first);
            while (first!=N) {
                path.push(parent[first]);
                first = parent[first];
                time++;
            }
            break;
        }


        if (first*2 >= 0 && visit[first*2] == false && first*2 <= 100000) {
            que.push(first*2);
            parent[first * 2] = first;
            visit[first*2] = true;
        }
        if (first + 1 >= 0 && visit[first + 1] == false && first + 1 <= 100000) {
            que.push(first + 1);
            parent[first +1] = first;
            visit[first +1] = true;
        }
        if (first - 1 >= 0 && visit[first - 1] == false && first - 1 <= 100000) {
            que.push(first - 1);
            parent[first - 1] = first;
            visit[first -1] = true;
        }


        
    }
}


int main() {
    cin >> N >> K;
    que.push(N);
    bfs();
    cout << time << endl;
    while (!path.empty()) {
        cout << path.top() << " ";
        path.pop();
        
    }
}
