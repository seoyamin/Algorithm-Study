
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(string name) {
    int answer = 0;
    vector<int> v;
    int n= name.size();
    // 0이 하나도 없을 때
    int cnt=0;
    int turn=0;

    for(int i=0; i<n; i++){
        if(name[i]-'A'<14){
            answer += name[i]-'A';
        }
        else{
            answer += 'Z'-name[i]+1;
        }
    }
    cout << answer << endl; // 5

    if(find(name.begin(), name.end(), 'A')==name.end()) {
        cnt=n-1;
        //cout << cnt << endl;
    }
    else{
        for(int j=0; j<n/2; j++){
            //cout << name[n-j-1] << ' '; // ABAAA
            if(name[n-j-1]!='A'){
                turn = j+1;
                cnt += turn;
                //cout <<"here " << cnt << endl;
                break;
            }
        }
        for(int j=n/2-1; 0<j; j--){
            //cout << name[j] << ' ';
            if(name[j]!='A'){
                cnt+=turn;
                cnt+=j;
                //cout << cnt << endl;
                break;
            }
        }
    }

    answer += cnt;

    return answer;
}
