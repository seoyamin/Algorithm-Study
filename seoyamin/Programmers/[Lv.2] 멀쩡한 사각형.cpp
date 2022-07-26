using namespace std;

// 최대공약수 리턴 함수
int gcd(int x, int y) {
    long long mod = x % y;
    
    while(mod != 0) {
        x = y;
        y = mod;
        mod = x % y;
    }
    
    return y;
}


long long solution(int w,int h) {
    long long answer = (long long)w * (long long)h;
    long long g = gcd(w, h);     // 최대공약수 g
    
    long long cannot = ( (w/g) + (h/g) - 1 ) * g;    // 잘리는 직사각형 개수 cannot
    answer -= cannot;
    
    return answer;
}