#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include <math.h>

void readsave();
void writesave(int c1, int c2, int c3, int c4, int c5, float acc);
void calculator(int c1, int c2, int c3, int c4, int c5, float acc);
void setlevelacc(int *c1, int *c2, int *c3, int *c4, int *c5, float *acc);
int intcheck();
float accbonus(float acc);
int lvl(int x);
int lvlup(int x);
void cls();
bool strinput(char x[21]);


int main()
{
	int c1,c2,c3,c4,c5;
	int fn;
	char fnstring[21];
	float acc;
	readsave(&c1, &c2, &c3, &c4, &c5, &acc);
	while (1)
	{
		cls();
		printf(	"=============================\n"
				" maimai traveling calculator \n"
				"           Ver 2.0           \n"
				" Made by Thasyka (T-Koroshi) \n"
				"   Press any key to enter.   \n"
				"=============================\n");
		getch();
		cls();
		printf( "Main Menu\n"
				"1. Calculate\n"
				"2. Set default values\n"
				"0. Exit\n");
		printf("===+==+==+==+==+==+==+==+==+===\n");
		printf("Please select choice (0-2): ");
		while(1)
		{
			strcpy(fnstring, "\0");
			scanf("%s",fnstring);
			if (strinput(fnstring)==0)
			{
				printf("Invalid value. Please enter again (0-2): ");
			}
			else
			{
				fn = atoi(fnstring);
				if (fn < 0 || fn > 2)
				{
					printf("Invalid value. Please enter again (0-2): ");
				}
				else break;
			}
		}
		switch (fn)
		{
			case 1:
				calculator(c1,c2,c3,c4,c5,acc);
				break;
			case 2:
				setlevelacc(&c1,&c2,&c3,&c4,&c5,&acc);
				writesave(c1,c2,c3,c4,c5,acc);
				break;
			case 0:
				break;
			default: exit(1);
		}
		if (fn==0) break;
	}
	writesave(c1,c2,c3,c4,c5,acc);
}

void calculator(int c1, int c2, int c3, int c4, int c5, float acc)
{
	int distance, target, song;
	cls();
	printf("Please enter your current distance: ");
	scanf("%d",&distance);
	cls();
	printf("Please enter your target distance: ");
	scanf("%d",&target);
	printf("Member 1: Lvl %d\n"
               "Member 2: Lvl %d\n"
               "Member 3: Lvl %d\n"
               "Member 4: Lvl %d\n"
               "Member 5: Lvl %d\n"
               "Distance : %d\n"
               "Songs played: 0\n",c1,c2,c3,c4,c5,distance);
	printf("Press any key to start...");
	getch();
	cls();
	while (1)
	{
		printf("Member 1: Lvl %d\n"
               "Member 2: Lvl %d\n"
               "Member 3: Lvl %d\n"
               "Member 4: Lvl %d\n"
               "Member 5: Lvl %d\n"
               "Distance : %d\n"
               "Songs played: %d\n",c1,c2,c3,c4,c5,distance,song);
		if (distance>target) break;
        distance += ceil(accbonus(acc)*(lvl(c1)+lvl(c2)+lvl(c3)+lvl(c4)+lvl(c5)));
        song++;
        c1 = lvlup(c1);
        c2 = lvlup(c2);
        c3 = lvlup(c3);
        c4 = lvlup(c4);
        c5 = lvlup(c5);
	}
	printf("Calculation finished. Press any key to exit...");
	getch();
}

void setlevelacc(int *c1, int *c2, int *c3, int *c4, int *c5, float *acc)
{
	char setstring[21];
	int setin;
	while (1)
	{
		cls();
		printf( "Member 1: Lvl %d\n"
				"Member 2: Lvl %d\n"
				"Member 3: Lvl %d\n"
				"Member 4: Lvl %d\n"
				"Member 5: Lvl %d\n"
				"Accuracy: %.4f%% (%.2fx)",*c1,*c2,*c3,*c4,*c5,*acc,accbonus(*acc));
		printf( "===+==+==+==+==+==+==+==+==+===\n");
		printf( "Input 1-5 to modify the Tour Member's level.\n"
				"Input 6 to modify your accuracy. (%%)\n"
				"Input 0 to go back.\n"
				"\n");
		while(1)
			{
				strcpy(setstring, "\0");
				scanf("%s",setstring);
				if (strinput(setstring)==0)
				{
					printf("Invalid value. Please enter again (0-6): ");
				}
				else
				{
					setin = atoi(setstring);
					if (setin < 0 || setin > 6)
					{
						printf("Invalid value. Please enter again (0-6): ");
					}
					else break;
				}
			}
			switch (setin)
			{
				case 1:
					printf("Input new value: ");
					*c1=intcheck();
					break;
				case 2:
					printf("Input new value: ");
					*c2=intcheck();
					break;
				case 3:
					printf("Input new value: ");
					*c3=intcheck();
					break;
				case 4:
					printf("Input new value: ");
					*c4=intcheck();
					break;
				case 5:
					printf("Input new value: ");
					*c5=intcheck();
					break;
				case 6:
					printf("Input new value: ");
					scanf("%f",acc);	//find a way to idiot-proof this
					break;
				case 0:
					break;
				default: exit(1);
			}
		if (setin==0) break;
	}
}

int intcheck()
{
	char valuestring[11];
	int x;
	while(1)
	{
		strcpy(valuestring, "\0");
		scanf("%s",valuestring);
		if (strinput(valuestring)==0)
		{
			printf("Invalid value. Please enter again (0-999): ");
		}
		else
		{
			x = atoi(valuestring);
			if (x < 0 || x > 999)
			{
				printf("Invalid value. Please enter again (0-999): ");
			}
			else return x;
		}
	}
}

float accbonus(float acc)
{
	if (0 <= acc && acc < 80) return 1;
	if (80 <= acc && acc < 99) return 1+(acc-80)/100;
	if (99 <= acc && acc < 100) return 1.2;
	if (100 <= acc && acc <= 101) return 1.2+(acc-100)/10;
}

int lvl(int x)
{
    int m;
    if (x==0) m = 1;
    else if (x<9) m = x;
    else if (x<49) m = x + 100;
    else if (x<99) m = x + 200;
    else if (x<299) m = x + 300;
    else if (x<999) m = x + 400;
    else if (x==999) m = 1499;
    return m;
}

int lvlup(int x)
{
    if (x==0) return 0;
    else if (x<999) return ++x;
    else return 999;
}

void readsave(int *c1, int *c2, int *c3, int *c4, int *c5, float *acc)
{
	FILE *mn = fopen("maitraveldata.txt", "r");
	if (mn == NULL)
	{
		mn = fopen("maitraveldata.txt", "w");
		fprintf(mn, "c1= 1\n"
					"c2= 1\n"
					"c3= 1\n"
					"c4= 1\n"
					"c5= 1\n"
					"acc= 101");
		*c1=1;	//temporary fix via assigning the values manually. pls help
		*c2=1;
		*c3=1;
		*c4=1;
		*c5=1;
		*acc=101;
		fclose(mn);
	}
	else
	{
		fscanf(mn, "c1= %d\n", &*c1);
		fscanf(mn, "c2= %d\n", &*c2);
		fscanf(mn, "c3= %d\n", &*c3);
		fscanf(mn, "c4= %d\n", &*c4);
		fscanf(mn, "c5= %d\n", &*c5);
		fscanf(mn, "acc= %f", &*acc);
		fclose(mn);
	}
}

void writesave(int c1, int c2, int c3, int c4, int c5, float acc)
{
	FILE *mn = fopen("maitraveldata.txt", "w");
	fprintf(mn, "c1= %d\n"
				"c2= %d\n"
				"c3= %d\n"
				"c4= %d\n"
				"c5= %d\n"
				"acc= %f",c1,c2,c3,c4,c5,acc);
	fclose(mn);
}

void cls()
{
	system("cls");
}

bool strinput(char x[21])
{
	char lncom[21];
	sprintf(lncom, "%d", atoi(x));
	if (strcmp(x, lncom)==0) return 1;
	else return 0;
}
