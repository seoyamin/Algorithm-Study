#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    // 각 수포자의 패턴 
    vector<int> person1 = {1, 2, 3, 4, 5};
    vector<int> person2 = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> person3 = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int nums[3] = {0};  // 맞은 개수

    
    // 맞은 개수 카운트
    for(int i=0 ; i<answers.size() ; i++) {
        if(answers[i] == person1[i%5]) nums[0]++;
        if(answers[i] == person2[i%8]) nums[1]++;
        if(answers[i] == person3[i%10]) nums[2]++;
    }
    
    
    // 맞은 개수 최댓값
    int max = nums[0] > nums[1] ? nums[0] : nums[1];
    max = nums[2] > max ? nums[2] : max;
    
    
    for(int i=0 ; i<=2 ; i++)  if(nums[i] == max) answer.push_back(i+1);

    
    return answer;
}