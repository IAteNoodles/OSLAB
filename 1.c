#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Day {
    char *name;
    int date;
    char *description;
};

struct Day* create() {
    struct Day *calendar;
    calendar = (struct Day*)malloc(sizeof(struct Day) * 7);
    return calendar;
}

void read(struct Day *calendar) {
    char name[10];
    char description[25];
    int i, date;
    for(i = 0; i < 7; i++) {
        printf("Enter the day name : ");
        scanf("%s", name);
        calendar[i].name = (char *)malloc(strlen(name) + 1);
        strcpy(calendar[i].name, name);
        printf("Enter the date : ");
        scanf("%d", &date);
        calendar[i].date = date;
        getchar();
        printf("Enter description of the activity : "); 
        scanf("%[^\n]s", description);
        calendar[i].description = (char *)malloc(strlen(description) + 1);
        strcpy(calendar[i].description, description);
    }
}

void display(struct Day *calendar) {
    int i;
    printf("\n\nYour calendar\n");
    printf("Weekly Activity Details:\n");
    for(i = 0; i < 7; i++) {
        printf("Day %d: Name: %s, Date: %d, Description: %s\n", i + 1, calendar[i].name, calendar[i].date, calendar[i].description);
    }
}

void main() {
    struct Day *calendar;
    calendar = create();
    read(calendar);
    display(calendar);
    free(calendar);
}
