#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    string x_str = to_string(x);
    int sum = 0;
    
    for(int i=0; i<x_str.size() ; i++) {
        sum += (x_str[i] - '0');
    }
    
    return (x%sum == 0);
}