#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define li 100  //liczba iteracji do szeregu

//tablicowanie funkcji D(x) = 1/sqrt(1+x) w <a,b> - szereg + funkcja liczona ze wzoru


//definicja funkcji szereg  x - parametr formalny

double szereg(double x){
    double s, w, m = 3, n = 2, sil = 2;
    int i;
    s = x;
    w = x;

    if (x == 0) return 1;
    else {
        for (i = 1; i <= li; i++) {
            if (i > 2) w = (-w * x * (m * (m + 2) / n * 2)) / (sil * (i + 1));
                else if (i == 1) w = (-w * x * (1 / n)) / 1;
                else if (i == 2) w = (-w * x * (m / n * 2)) / sil;
            s = s + w;
        }
        return s;
    }
}

double funkcja_d(double x){
    return 1/sqrt(1+x);
}
int main()
{
    int lp;
    double a, b, krok, x;

    printf("Podaj konce przedzialow (a,b) >= 0 i liczbe podprzedzialow\n");
    scanf("%lf %lf %d",&a,&b,&lp);
    krok=(b-a)/lp;
    printf("krok=%6.2lf\n\n\n",krok);
    printf("     ----------------------------\n\n");
    printf("        x    szereg(x)  funkcja D(x)\n     ----------------------------\n");
    for (x=a;x<=b;x+=krok)
        printf("%10.2lf    %7.4lf    %7.4lf\n",x , szereg(x), funkcja_d(x));
    printf("     ----------------------------\n\n");
    system("PAUSE");
    return 0;
}

