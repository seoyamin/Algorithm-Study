#include <string>
#include <vector>
#include <iostream>

using namespace std;
bool check_alphabet(string last_word, string next_word) ;
bool check_same_word(vector<string> checked_words, string next_word);


vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    vector<string> checked_words;
    checked_words.push_back(words[0]);
    int index = 1;
    
    while (index < words.size() && answer.size() != 2) {
        if (words[index].size() == 1 || check_alphabet(checked_words[checked_words.size() - 1], words[index]) || check_same_word(checked_words, words[index])) {
            answer.push_back(index % n + 1);
            answer.push_back(index / n + 1);
        }
        else {
            checked_words.push_back(words[index]);
        }
        index++;
    }
     
    if (answer.size() != 2) {
        answer.push_back(0);
        answer.push_back(0);
    }

    return answer;
}

bool check_alphabet(string last_word, string next_word) {
    if (last_word.back() == next_word.front())
        return false;
    else {
        return true;
    }
}

bool check_same_word(vector<string> checked_words, string next_word) {
    for (int i = 0; i < checked_words.size(); i++) {
        if (checked_words[i] == next_word) {
            return true;
        }
    }
    return false;
}
