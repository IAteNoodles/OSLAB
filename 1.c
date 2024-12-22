#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct calElement
{
char *day;
int date;
char *activity;
};
struct calElement* create() // it creates calendar structure for 7 days
{
struct calElement *calendar;
// dynamic allocation for calendar
calendar = (struct calElement *)malloc(sizeof(struct calElement)*7);
return calendar;
}
void read(struct calElement *calendar)
{
// Local Variable to store string elements
char day[10];
char activity[25];
int i, date;
for(i = 0; i<7; i++)
{
printf("Enter the day : ");
scanf("%s",day);
""
calendar[i].day = (char *)malloc(strlen(day)+1); // dynamically allocated memory for day
strcpy(calendar[i].day, day); // copy day from local variable to heap
printf("Enter the date : ");
scanf("%d",&date);
calendar[i].date = date;
getchar();
printf("Enter description of the activity : ");
scanf("%[^\n]s",activity);
// dynamically allocate memory for activity
calendar[i].activity = (char *)malloc(strlen(activity)+1);
strcpy(calendar[i].activity, activity); // copy activity from local variable to heap
}
}
void display(struct calElement *calendar)
{
int i;
printf("\n\nYour calendar\n");
printf("Day\t\tDate\t\tActivity");
//Display the calendar
for(i = 0; i<7; i++){
printf("\n%s\t\t%d\t\t%s",calendar[i].day,calendar[i].date,calendar[i].activity );
}
void main()
{
struct calElement *calendar; // create structure variable of type pointer
calendar=create(); //call create function
read(calendar); // read function to read all inputs
display(calendar); // Function to print calendar
free(calendar); // Release the memory allocated dynamically
}