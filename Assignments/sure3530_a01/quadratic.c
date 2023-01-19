/**
--------------------------------------------------
Project: cp264-a1q3
File:    quadratic.c
Author:  Sanjae Suresh Kumar
Version: 2022-01-18
--------------------------------------------------
*/
#include <stdio.h>
#include <math.h>

int main3(int argc, char* argv[]){
    float a, b, c, discriminant, r1, r2;
    float p1, p2;
    float EPSILON = 0.000001;

    if (argc < 2) {
       printf("argument input:missing\n");
    } else {
        int n = sscanf(argv[1], "%f,%f,%f", &a, &b, &c);
        if (n != 3) {
            printf("input:invalid\n");
        } else {

            printf("(%f)x^2+(%f)x+(%f)=0 ", a, b, c);

            p1 = b*b;
            p2 = 4*a*c;
            discriminant = p1 - p2;

            if (fabs(a) < EPSILON) {
                printf("is not a quadratic equation\n");

            } else if (discriminant == 0){
                r1 = -b / (2 * a);
                printf("has two equal real roots: %f", r1);

            } else if (discriminant > 0){
                r1 = (-b + sqrtf(discriminant))/(2 * a);
                r2 = (-b - sqrtf(discriminant))/(2 * a);

                if (discriminant > 0)
                	printf("has two distinct real roots: %f, %f", r1, r2);
                else
                	printf("has two complex roots: %f, %f", r1, r2);
            }
        }
    }
    return 0;
}
