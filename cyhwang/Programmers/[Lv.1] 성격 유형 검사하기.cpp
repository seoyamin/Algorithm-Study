#include <string>
#include <vector>
#include <map>

using namespace std;
vector<int> change_score(vector<int> choices);

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    map<char, int> type;
    
    for (int i = 0; i < survey.size(); i++) {
        if (choices[i] >= 5)
            type[survey[i][1]] += choices[i] - 4;
        else if (choices[i] <= 3)
            type[survey[i][0]] += 4- choices[i];
    }
    
    if (type['R'] >= type['T'])
        answer += "R";
    else
        answer += "T";
    if (type['C'] >= type['F'])
        answer += "C";
    else
        answer += "F";
    if (type['J'] >= type ['M'])
        answer += "J";
    else
        answer += "M";
    if (type['A'] >= type['N'])
        answer += "A";
    else
        answer += "N";
    
    return answer;
}

