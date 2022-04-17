#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x)*(x) + 4*(x)*(x) - 10)
#define df(x) (3*(x)*(x) + 8*(x))
#define eps 1e-9

int main() {
    int n = 0;
    double a = 5.0, b = 4.5;
    while(1) {
        double c = (a*f(b)-b*f(a))/(f(b)-f(a));
        n++;
        if(fabs(f(c)) <= eps) {
            printf("Root(Secant) = %.9lf\n", c);
            break;
        }
        a = b;
        b = c;
    }
    printf("No of Itr = %d\n", n);
}
