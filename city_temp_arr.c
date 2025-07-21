// WAP for a two dimensional to store and display the elements. 
// (Store temperature of two cities for a week and display it)
#include <stdio.h>
int main() {
    float temp[2][7];
    char cities[2][20] = {"Mumbai", "Delhi"};
    for(int city = 0; city < 2; city++) {
        printf("Enter temperatures for %s:\n", cities[city]);
        for(int day = 0; day < 7; day++) {
            printf("Day %d: ", day + 1);
            scanf("%f", &temp[city][day]);
        }
    }
    printf("\nTemperatures for the week:\n");
    printf("        Mon   Tue   Wed   Thu   Fri   Sat   Sun\n");
    for(int city = 0; city < 2; city++) {
        printf("%s: ", cities[city]);
        for(int day = 0; day < 7; day++) {
            printf("%.1f  ", temp[city][day]);
        }
        printf("\n");
    }
    return 0;
}