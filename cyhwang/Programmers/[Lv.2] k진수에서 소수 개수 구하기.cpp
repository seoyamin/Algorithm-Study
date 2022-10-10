#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

string change_to_k(int n, int k);
int get_prime_number (string k_num);
bool is_prime (long long k_int);

int solution(int n, int k) {
    int answer = -1;
    string k_num;
    k_num = change_to_k(n,k);
    answer = get_prime_number(k_num);
    
    return answer;
}

string change_to_k(int n, int k) {
    string k_num = "";
    
    while (n) {
        k_num += to_string(n % k);
        n = n/k;
    }
    
    reverse(k_num.begin(), k_num.end());
    
    return k_num;
}

int get_prime_number (string k_num) {
    string tmp_string = "";
    int answer = 0;
    for (int i = 0; i < k_num.length(); i++) {
        if (k_num[i] == '0') {
            long long tmp_num = stoll(tmp_string);
            if (is_prime(tmp_num))
                answer++;
            tmp_string = "";
        }
        tmp_string += k_num[i];
    }
    
    if (!tmp_string.empty()) {
        long long tmp_num = stoll(tmp_string);
        if (is_prime(tmp_num))
            answer++;
    }
    return answer;
}

bool is_prime (long long k_int) {
    if (k_int < 2)
        return false;
    for (int i = 2; i <= sqrt(k_int); i++) {
        if (k_int % i == 0)
            return false;
    }
    return true;
}
