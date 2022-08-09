#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(string expression) { // ex) "100-200*300-500+20"

    long long answer = 0;
    vector<long long> num; // num:숫자 ex) 100 200 300 500 20
    vector<char> exp, location; // exp:연산자 location:연산자의 위치
    string n = "";

    for(int i = 0; i < expression.size(); i++)
    {
        // 연산자
        if(expression[i] == '+' || expression[i] == '-' || expression[i] == '*')
        {
            num.push_back(atoi(n.c_str())); // stoi: string->number
            n = "";
            if(find(exp.begin(), exp.end(), expression[i]) == exp.end())
                exp.push_back(expression[i]); // ex) - * +
            location.push_back(expression[i]); // ex) - * - +
        }
        // 연산자 외
        else
            n += expression[i]; //
    }

    num.push_back(atoi(n.c_str()));
    sort(exp.begin(), exp.end());


    do
    {
        vector<long long> tmp_num = num;
        vector<char> loc = location;

        // --- 어려웠던 부분 ---
        for(int i = 0; i < exp.size(); i++) // * + - (중요도 순서)
        {
            for(int j = 0; j < loc.size(); j++) // ex) - * - + (입력된 순서)
            {
                if(exp[i] == loc[j])
                {
                    if(loc[j] == '+')
                        tmp_num[j] = tmp_num[j] + tmp_num[j + 1];
                    else if(loc[j] == '-')
                        tmp_num[j] = tmp_num[j] - tmp_num[j + 1];
                    else if(loc[j] == '*')
                        tmp_num[j] = tmp_num[j] * tmp_num[j + 1];

                    tmp_num.erase(tmp_num.begin() + j + 1);
                    loc.erase(loc.begin() + j);
                    j--;
                }
            }
        }

        if(answer < abs(tmp_num[0]))
            answer = abs(tmp_num[0]);
    } while(next_permutation(exp.begin(), exp.end())); // - * + , * + -, ... 조합

    return answer;
}
