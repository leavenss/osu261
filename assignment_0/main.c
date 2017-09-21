/* CS261 - Fall2017 - Oregon State University
 * triangleArea program by Taylor A. Liss
 *
 * This program asks the user to input the 3
 * side lengths of a triangle. If the sides
 * lengths are valid, the area of the triangle
 * is returned.*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {

    float a, b, c, p, area;
    bool valid = false;

    while (valid == false) {
        printf("Enter three values to act as side lengths\n");
        scanf("%f", &a);
        scanf("%f", &b);
        scanf("%f", &c);

        if (a+b < c || a+c < b || b+c < a) {
            printf( "Sorry but that is an impossible triangle!\n");
        } else {
            valid = true;
        }
    }
    p = (a + b + c) / 2;

    area = sqrt(p * (p-a) * (p-b) * (p-c));

    printf("Area is %.2f\n", area);
}
