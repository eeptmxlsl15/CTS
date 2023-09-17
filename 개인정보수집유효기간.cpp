#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <map>


using namespace std;

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    vector<char> termAlphabet;
    vector<int> termLong;
    vector<int> privacyValue;
    vector<char> pAlphatbet;

    int todayValue;
    //today를 날짜로 환산
    todayValue = stoi(today.substr(0, 4)) * 12*28 + (stoi(today.substr(5, 2))-1) * 28 + stoi(today.substr(8, 2));
    
    //terms을 termAlphabet과 termLong으로 나눔 termLong에는 날짜를 계산해서 넣음
    for (int i = 0; i < terms.size(); i++) {
        termAlphabet.push_back(terms[i][0]);
        termLong.push_back((stoi(terms[i].substr(2))) * 28);
        
    }

    //privacies 를 2개로 분리
    for (int i = 0; i < privacies.size(); i++) {
        int pYear = stoi(privacies[i].substr(0, 4));
        int pMonth = stoi(privacies[i].substr(5, 2));
        int pDay = stoi(privacies[i].substr(8, 2));

        pAlphatbet.push_back(privacies[i][11]);
        privacyValue.push_back(pYear * 12*28 + (pMonth-1) * 28 + pDay);
        cout << pAlphatbet[i] << privacyValue[i] << endl;
    }

    //today와 비교
    for (int i = 0; i < privacies.size(); i++) {
        int index;
        //약관 기간 찾기
        for (int j = 0; j < terms.size(); j++) {
            if (pAlphatbet[i] == termAlphabet[j]) {
                index = j;

                break;
            }

        }
        //비교
        if (privacyValue[i] + termLong[index] <= todayValue) {
            answer.push_back(i+1);

        }
    }

    return answer;
}

