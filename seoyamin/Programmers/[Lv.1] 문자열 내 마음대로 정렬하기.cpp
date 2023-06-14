#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N;

bool compare(string a, string b) {
    int aSize = a.size();
    int bSize = b.size();
    
    if(a[N] == b[N]) {
        int minLen = aSize < bSize ? aSize : bSize;
        
        for(int i=0 ; i<minLen ; i++) {
            if(a[i] != b[i]) return a[i] < b[i];
        }
    }
    return a[N] < b[N];
}

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    N = n;
    
    sort(strings.begin(), strings.end(), compare);
    answer = strings;
    
    return answer;
}