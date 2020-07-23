#include <iostream>

using namespace std;

int g[100001], sum[100001];

int multiples(int number) {
    int multi = 1, temp;
    while (number > 0) {
        temp = number % 10;
        if (temp != 0)
            multi *= temp;
        number /= 10;
    }
    return multi;
}

void init() {
    
    int index = 1, total[10];
    
    for (; index <= 9; ++index) {
        g[index] = index;
        total[index] = sum[index] = 1;
    }
    
    for (index = 10; index <= 100000; ++index) {
        g[index] = g[multiples(index)];
        sum[index] = ++total[g[index]];  
    }
}

int main() {

    init();
    
    int left, right, query, target, count;
    
    cin >> query;
    
    while (query--) {
        
        cin >> left >> right >> target;
        
        if (left == right) {
            
            cout << 1 << endl;
            
            continue;
        }

        count = 0;

        while (right >= left && g[right] != target) --right;
    
        if (right >= left--) {
        
            while (left > 0 && g[left] != target) --left;
        
            if (left > 0)
                count = sum[right] - sum[left]; else count = sum[right];
        }

        cout << count << endl;
    }
    
    return 0;
}