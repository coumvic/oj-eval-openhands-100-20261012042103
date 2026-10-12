#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPerfectNumber(long long n) {
    if (n <= 1) {
        return false;
    }
    
    long long sum = 1; // 1 is always a proper divisor for n > 1
    
    // Check divisors from 2 to sqrt(n)
    for (long long i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            long long divisor = i;
            long long pairedDivisor = n / i;
            
            sum += divisor;
            
            // Add the paired divisor if it's different and not n itself
            if (pairedDivisor != divisor && pairedDivisor != n) {
                sum += pairedDivisor;
            }
        }
    }
    
    return sum == n;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int m;
    cin >> m;
    
    vector<long long> numbers(m);
    for (int i = 0; i < m; ++i) {
        cin >> numbers[i];
    }
    
    for (int i = 0; i < m; ++i) {
        if (isPerfectNumber(numbers[i])) {
            cout << 1 << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
    
    return 0;
}