#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void welcome_page();
void create_acc();
void delete_acc();
void creadite();
void debite();
void bln_check();
void alter();

int main()
{
	welcome_page();
	create_acc();

}

void welcome_page()
{
	system("clear");
	printf("\n\n\t\t\tHi, There Welcome to Our SP BANK\n\n");
	sleep(2.5);
}

void create_acc()
{
	char f_name[20], l_name[20], dob[20], location[20], p_number[10];
	printf("\tEnetr Your Detailes Here\n\n");
	printf("\t\tfirst name     : ");
	scanf("%s",f_name);
	printf("\t\tlast name      : ");
	scanf("%s",l_name);
	printf("\t\tDate of Birth  : ");
	scanf("%s",dob);
	printf("\t\tLocation       : ");
	scanf("%s",location);
	printf("\t\tPhone number   : ");
	scanf("%s",p_number);

	printf("\n\n\t\tThank For the Creating Account Our Bank\n\n");
	printf("\n\tHere you Filled Your details\n\n");
	sleep(0.5);
	printf("\tName           : %s %s\n",f_name,l_name);
	printf("\tDate Of Birth  : %s\n",dob);
	printf("\tLocation       : %s\n",location);
	printf("\tPhone Number   : %s\n",p_number);

printf("\n");
}
void delete_acc(){}
void creadite(){}
void debite(){}
void bln_check(){}
void alter(){}
