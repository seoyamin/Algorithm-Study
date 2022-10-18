#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare_HEAD (string file1, string file2);
string convert_capital (string HEAD);
bool compare_NUMBER (string file1, string file2, int file1_head_size, int file2_head_size);


vector<string> solution(vector<string> files) {
    stable_sort(files.begin(), files.end(), compare_HEAD);
    
    return files;
}

bool compare_HEAD (string file1, string file2) {
    string file1_HEAD, file2_HEAD;
    
    for (int i = 0; i < file1.size(); i++) {
        if (file1[i] >= 48 && file1[i] <= 57) {
            file1_HEAD = file1.substr(0,i);
            break;
        }
    }
    for (int i = 0; i < file2.size(); i++) {
        if (file2[i] >= 48 && file2[i] <= 57) {
            file2_HEAD = file2.substr(0,i);
            break;
        }
    }
    file1_HEAD = convert_capital(file1_HEAD);
    file2_HEAD = convert_capital(file2_HEAD);
    
    if (file1_HEAD == file2_HEAD) {
        return compare_NUMBER(file1, file2, file1_HEAD.size(), file2_HEAD.size());
    }

    return file1_HEAD < file2_HEAD;
}

string convert_capital (string HEAD) {
    for (int i = 0; i < HEAD.size(); i++) {
        if (HEAD[i] <= 90 && HEAD[i] >= 65) {
            HEAD[i] += 32;
        }
    }
    return HEAD;
}

bool compare_NUMBER (string file1, string file2, int file1_head_size, int file2_head_size) {
    int file1_NUMBER, file2_NUMBER;
    bool start_flag = false;
    int start_number;
    
    for (int i = file1_head_size; i < file1.size(); i++) {
        if (!(file1[i] >= 48 && file1[i] <= 57)) {
            if (i - start_number > 5) {
                file1_NUMBER = stoi(file1.substr(file1_head_size, 5));
                break;
            }
            else {
                file1_NUMBER = stoi(file1.substr(file1_head_size, i - file1_head_size));
                break;
            }
        }
        else if (i == file1.size() - 1) { //숫자로 파일명이 끝날 경우
            file1_NUMBER = stoi(file1.substr(file1_head_size, i - file1_head_size + 1));
        }
    }
    
    for (int i = file2_head_size; i < file2.size(); i++) {
        if (!(file2[i] >= 48 && file2[i] <= 57)) {
            if (i - start_number > 5) {
                file2_NUMBER = stoi(file2.substr(file2_head_size, 5));
                break;
            }
            else {
                file2_NUMBER = stoi(file2.substr(file2_head_size, i - file2_head_size));
                break;
            }
        }
        else if (i == file2.size() - 1) { //숫자로 파일명이 끝날 경우
            file2_NUMBER = stoi(file2.substr(file2_head_size, i - file2_head_size + 1));
        }
    }
    
    return file1_NUMBER < file2_NUMBER;
}
