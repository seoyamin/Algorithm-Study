
#include <string>
#include <vector>
#include <queue>
 
using namespace std;
 
vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer; // 배포 
    queue<int> current; // 큐
    
    for (auto p : progresses)
        current.push(p);
  
    while (!current.empty()){
      // 작업 진도
        for (int i = 0; i < current.size(); i++){
            int p = current.front();
            current.pop();
            current.push(p + speeds.at(i));
        }
        int count = 0;

        while (true){
          // 작업 진도가 100 이상
            if (current.size() >0 && current.front() >= 100){
                current.pop();
                speeds.erase(speeds.begin());
                count++;
                continue;
            }
            break;
        }
      
        // 배포 추가
        if (count > 0)
            answer.push_back(count);
    }
    return answer;
}
