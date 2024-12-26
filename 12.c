#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXADDR 100

struct employee
{
	int empid;	// 4-digit key to determine employee records uniquely
	int age;
	char name[20];
}ht[MAXADDR];

int hash(int key)	// Hash function to convert 4-digit key to 2-digit index (hash address)
{
	int index;
	index = key % MAXADDR; 
	return ( index );
}
void main( )
{
	int i, choice, count, key, age, index;
	char name[20];

	count = 0;

	// Initialize all the empid in hash table ht to -1
	for( i=0; i<MAXADDR; i++)
	{
		ht[i].empid = -1;
	}	

	for( ; ; )
	{
		printf("1. Insert Record	2. Search Record	3.Exit\n");

		printf("Enter your choice\n");
		scanf("%d", &choice);

		switch(choice)
		{

			case 1: if(count==MAXADDR)
				{
					printf("No Space Available\n");
				}
				else
				{
					printf("Enter the 4-digit unique key for employee\n");
					scanf("%d", &key);

					printf("Enter the Employee name\n");
					scanf("%s",name);

					printf("Enter the age\n");
					scanf("%d", &age);
										
					index = hash(key);

					if( ht[index].empid==-1) // Found free location (No Collision)
					{
						ht[index].empid = key;
						strcpy(ht[index].name, name);
						ht[index].age = age;
						count = count + 1;
						break;
					}
					else // Collision Resolution (Linear Probing)
					{
					    printf("Collision Detected!!!");
					    printf("Collision will be avoided using Linear Probing");
						for( i=1; i<MAXADDR; i++ )
						{
							index = ( hash(key) + i ) % MAXADDR;

							if( ht[index].empid==-1) // Found free location 									{
								ht[index].empid = key;
								strcpy(ht[index].name, name);
								ht[index].age = age;
								count = count + 1;
								break;
							}
						}
					}
				

				break;

			case 2: printf("Enter the 4-digit unique key of employee to search\n");
				scanf("%d", &key);

				index = hash(key);

				if( ht[index].empid==key) // Found Successfully
				{
					printf("Successful Search\n");
					printf("Name = %s\n", ht[index].name);
					printf("Age = %d\n", ht[index].age);
					
					break;
				}
				else if( ht[index].empid==-1 ) // Found Vacant Position
				{
					printf("Unsuccessful Search\n");
					printf("Key not found\n");
					
					break;
				}
				else // Search using Linear Probing
				{
					for( i=1; i<MAXADDR; i++ )
					{
						index = ( hash(key) + i ) % MAXADDR;
						
						if( ht[index].empid==key) // Found Successfully
						{
							printf("Successful Search\n");
							printf("Name = %s\n", ht[index].name);
							printf("Age = %d\n", ht[index].age);
					
							break;
						}
						else if( ht[index].empid==-1 ) // Found Vacant Position
						{
							printf("Unsuccessful Search\n");
							printf("Key not found\n");
					
							break;
						}
					}
				}

				printf("Unsuccessful Search\n");
				printf("Key not found\n");
				break;

			default: exit (0);
		}
	}
}
