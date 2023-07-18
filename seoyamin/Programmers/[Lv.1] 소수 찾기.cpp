#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<bool> check(n+1, false);
  
    for(int i=2; i<=n; i++){
        if(check[i])
            continue;
        
        for(int j=i*2; j<=n; j+=i){
            check[j] = true;
        }
    }
    
    for(int i=2; i<=n; i++){
        if(!check[i]){
            answer++;
        }
    }
    
    return answer;
}

/* 
int solution(int n) {
    int answer = 0;
    
    while(n > 1) {
        bool isPrime = true;
        
        for(int i=2 ; i<=sqrt(n) ; i++) {
            if(n % i == 0) {
                isPrime = false;
                break;
            }
        }
        
        if(isPrime) answer++;
        n--;
    }
    
    return answer;
}
*/