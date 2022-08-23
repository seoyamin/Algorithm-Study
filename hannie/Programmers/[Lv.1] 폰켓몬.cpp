#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> nums)
{
    vector<int> v;

    for(int i=0; i<nums.size()/2; i++){
        for(int j=i; j<nums.size();j++){
            // 같은 원소가 없을 때만 v 벡터에 push
            if(find(v.begin(), v.end(), nums[j])==v.end()){ 
                v.push_back(nums[j]);
                break;
            }
        }
    }

    return v.size();
}
