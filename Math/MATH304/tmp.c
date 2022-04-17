#include<stdio.h>
#include<math.h>

#define f(x) ((x)*(x))
#define df(x) (2*(x))
#define eps 1e-9

int main() {
    printf("%lf %lf\n", 1.0 + 1.0, f(1.0 + 1.0));
}