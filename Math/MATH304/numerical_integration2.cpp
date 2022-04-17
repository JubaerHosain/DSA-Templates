#include <bits/stdc++.h>
using namespace std;
// area covered by sin(x), -sin(x);


double f(double x) {
    return abs(2 * sin(x));
}

int main() {
    int n = 200;

    double a = 0, b = 3.1416;
    double h = (b-a) / n;

    double area = f(a) + f(b);
    double odd = 0, even = 0, x = 0;
    for(int i = 1; i < n; i++) {
        x += h;
        if(i%2) 
            odd += f(x);
        else
            even += f(x);
    }

    area = (area + 4 * odd + 2 * even) * (h/3);

    printf("Area(covered by two function): %.9lf\n", area);
    cout << "Yes" << endl;
    
    return 0;
}
