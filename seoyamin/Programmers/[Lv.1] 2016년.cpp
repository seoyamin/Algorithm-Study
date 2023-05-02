#include <string>
#include <vector>

using namespace std;

string solution(int a, int b) {
    string days[7] = {"THU", "FRI", "SAT", "SUN", "MON", "TUE", "WED"};
    int count = 0;        // date -> day
    string answer = "";
    
    // day 
    count += b;                     
    
    // month -> day
    for(int i=1 ; i<a ; i++) {      
        if(i == 2) count += 29;
        else if ((i % 2 == 0 && i < 8) || (i % 2 == 1 && i > 8)) count += 30;
        else count += 31;
    }
    
    answer = days[count%7];
    
    return answer;
}