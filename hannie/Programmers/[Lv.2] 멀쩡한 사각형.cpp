using namespace std;

long long get_gcd(int w, int h){

    int mod = w % h;

    while (mod > 0)
    {
        w = h;
        h = mod;
        mod = w % h;
    }

    return h;
}

long long solution(int w, int h) {

    long long answer = 1;
    answer = (long long)w*h-(w+h-get_gcd(w,h)); // w*h 앞에 long long 붙이기!

    return answer;
}

