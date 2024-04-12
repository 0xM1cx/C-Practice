#include <stdio.h>

int main() {
    int day, month, year;

    printf("Enter day/month/year: ");
    scanf("%d %d %d", &day, &month, &year);

    // Displaying the complete date
    switch (month) {
    case 1:
        printf("January");
        break;
    case 2:
        printf("February");
        break;
    case 3:
        printf("March");
        break;
    case 4:
        printf("April");
        break;
    case 5:
        printf("May");
        break;
    case 6:
        printf("June");
        break;
    case 7:
        printf("July");
        break;
    case 8:
        printf("August");
        break;
    case 9:
        printf("September");
        break;
    case 10:
        printf("October");
        break;
    case 11:
        printf("November");
        break;
    case 12:
        printf("December");
        break;
    default:
        printf("Invalid month");
        return 0;
    }

    printf(" %d %d\n", day, year);

    return 0;
}
