#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double P, S, pt;
    int n, i, k;

    // 1) while(…) {… while(…) {…} …};
    P = 0;
    n = 1;
    while (n <= 13) {
        S = 0;
        i = 1;
        while (i <= n) {
            pt = 1; 
            k = 1;
            while (k <= i) {
                pt *= sqrt(k);
                k++;
            }
            S += (sin(10 * i) + cos(10 * i)) / pt; 
            i++;
        }
        P += S;
        n++;
    }
    cout << "while: " << P << endl;

    // 2) do{… do{…} while(…) …} while(…);
    P = 0;
    n = 1;
    do {
        S = 0;
        i = 1;
        do {
            pt = 1; 
            k = 1;
            do {
                pt *= sqrt(k);
                k++;
            } while (k <= i);
            S += (sin(10 * i) + cos(10 * i)) / pt; 
            i++;
        } while (i <= n);
        P += S;
        n++;
    } while (n <= 13);
    cout << "do-while: " << P << endl;

    // 3) for(…; …; n++) {… for(…; …; k++) {…} …};
    P = 0;
    for (n = 1; n <= 13; n++) {
        S = 0;
        for (i = 1; i <= n; i++) {
            pt = 1;
            for (k = 1; k <= i; k++) {
                pt *= sqrt(k);
            }
            S += (sin(10 * i) + cos(10 * i)) / pt;
        }
        P += S;
    }
    cout << "for ++: " << P << endl;

    // 4) for(…; …; n--) {… for(…; …; k--) {…} …}.
    P = 0;
    for (n = 13; n >= 1; n--) {
        S = 0;
        for (i = n; i >= 1; i--) {
            pt = 1;
            for (k = i; k >= 1; k--) {
                pt *= sqrt(k);
            }
            S += (sin(10 * i) + cos(10 * i)) / pt;
        }
        P += S;
    }
    cout << "for --: " << P << endl;

    return 0;
}
