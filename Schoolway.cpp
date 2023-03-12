#include <algorithm>
#include <string>

using namespace std;

int solution(string name) {
    int answer = 0;
    int n = name.length();
    int move = n - 1; //커서의 최대 움직임
    for (int i = 0; i < n; i++) {//a가 아닌 알파벳을 이동하는 최소의 수
        if (name[i] - 'A' < 14)
            answer += name[i] - 'A';
        else
            answer += 'Z' - name[i] + 1;

        int next = i + 1;
        while (next < n && name[next] == 'A')
            next++;//만약 다음 알파벳이 a라면 

        move = min(move, i + n - next + min(i, n - next));
    }

    answer += move;
    return answer;
}
