#include<stdio.h>
#include<math.h>

/*****user defined function*****/
double eps = 1e-9;

// given function
double func(double x) {
    double ans = x * x * x;
    ans += 4 * x * x;
    ans -= 10;
    return ans;
}

void solve_problem() {
    double a = 1, b = 2;

    if(func(a) * func(b) > 0) {
        printf("Solutin dosen't exixts in this range.");
        return;
    }
    else if(fabs(func(a)*func(b)) <= eps) {
        if(fabs(func(a)) <= eps) {
            printf("x: %lf\n", a); 
        }
        else if(fabs(func(b)) <= eps) {
            printf("x: %lf\n", b);
        }
        return;
    }

    double c;
    int it = 0;
    while(1) {
        it += 1;
        c = a * func(b) - b * func(a);
        c /= (func(b) - func(a));
        if(fabs(func(c)) <= eps) {
            printf("X(FP): %.9lf\n", c);
            break;
        }
        if(func(a)*func(c) < 0) {
            b = c;
        }
        else {
            a = c;
        }
    }

    printf("iteration: %d\n", it);
}

/*****main function*****/
int main() {
    
    solve_problem();

} 