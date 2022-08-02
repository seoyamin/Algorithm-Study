#include <string>
#include <vector>
#include <algorithm>
#include <sstream>


using namespace std;

// s를 사이즈가 짧은 순서로 정렬하기
bool compare(string a, string b){
    return a.size()<b.size();
}


vector<string> split(string str, char delimiter) {
    vector<string> internal; string temp;
    stringstream ss(str);
    while (getline(ss, temp, delimiter)) {
        internal.push_back(temp);
    }
    return internal;
}


vector<int> solution(string s) {
    vector<int> answer;
    vector<string> v;

    string tmpstr = "";
    for(int i=2; i<s.length()-2; i++){
        if(s[i-1]=='{') tmpstr = "";
        tmpstr += s[i];
        if(s[i+1]=='}'){ // 집합 종료
            v.push_back(tmpstr);
            tmpstr = "";
        }
    }

    sort(v.begin(), v.end(), compare);
    answer.push_back(stoi(v[0]));

    for(int i=1; i<v.size(); i++){
        string str = v[i];
        vector<string> elements = split(str, ',');
        for(int j=0; j<elements.size(); j++){
            int element = stoi(elements[j]);
            auto itr = find(answer.begin(), answer.end(), element);
            if(itr==answer.end()){
                answer.push_back(element);
            }
        }
    }

    return answer;
}
