#include <stdio.h>
#include<math.h>
#include<stdlib.h>

// simpson  rule

double f(double x) {
    return (x*x) + 1;
}

int main() {
    int n = 200;

    double a = 0, b = 1;
    double h = (b-a) / n;

    double x = 0;
    double area = f(a) + f(b);
    double odd = 0, even = 0;
    for(int i = 1; i < n; i++) {
        x += h;
        if(i%2) 
            odd += f(x);
        else
            even += f(x);
    }

    area = area + 4 * odd + 2 * even;
    area = area * (h/3);

    printf("Area(Simpson): %.9lf\n", area);
    
    return 0;
}