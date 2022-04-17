#include<stdio.h>
#include<math.h>

#define f(x) (x*x*x + 4*x*x - 10)
#define df(x) (3*x*x + 8*x)
#define eps 1e-9

int main() {
    int n = 0;
    double a = 1, x0;
    while(1) {
        x0 = a - (f(a) / df(a));
        n++;
        if(fabs(f(x0)) <= eps) {
            printf("Root(NR) = %.9lf\n", x0);
            break;
        }
        a = x0;
    }
    printf("No of Itr. = %d\n", n);
}