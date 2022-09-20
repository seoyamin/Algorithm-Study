#include <string>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string,bool> m;
    char last = words[0][0];
    
    for(int i=0;i<words.size();i++){
        
        string word = words[i];
        if(m[word]==true || last != words[i][0]) 
            return {(i%n)+1,(i/n)+1};
        else
            m[word]= true;
        last = words[i][word.length()-1];
    }

    return {0,0};
}
