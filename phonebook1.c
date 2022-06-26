#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <direct.h>
#include <string.h>
void menu(void);
void namefun(void);
void listfun(void);
void modifyfun(void);
void deletefun(void);
void exitfun(void);
void gotoxy(int x,int y){
	COORD c;
	c.X=x;
	c.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
int main(){
    menu();
}
void namefun(){
	system("cls");
	gotoxy(31,4);
	printf("NEW SECTION");
	FILE *fptr;
	char name[100];
	char address[100];
	char email[100];
	double phone;
	char gender[8];
	fptr=fopen("ebraj.txt","ab+");
	if(fptr==NULL){
		printf("Failed to create the required file.");
	}
	else{
		gotoxy(31,6);
		printf("Name:\t");
		gotoxy(52,6);
		gets(name);
		gotoxy(31,7);
		printf("Address:\t");
		gotoxy(52,7);
		gets(address);
		gotoxy(31,8);
		printf("Gender:\t");
		gotoxy(52,8);
		gets(gender);
		gotoxy(31,9);
		printf("Email:\t");
		gotoxy(52,9);
		gets(email);
		gotoxy(31,10);
		printf("Phone Number:\t");
		gotoxy(52,10);
		scanf("%lf",&phone);
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,email,phone);
	}
	fclose(fptr);
	system("cls");
	char ch;
	gotoxy(31,4);
	printf("Do you wanna add more datas.Press y for that:");
	fflush(stdin);
	while((ch=getch())=='y'){
		menu();
	}
}
void listfun(){
		FILE *fptr;
	char name[100],address[100],email[100],gender[8];
	double phone;
	int f;
	fptr=fopen("ebraj.txt","r");
	system("cls");
	gotoxy(31,2);
	printf("LIST SECTION OPENED ");
	printf("\n");
	while(fscanf(fptr,"%s %s %s %s %lf",name,address,gender,email,&phone)!=EOF){
			printf("------------------------------------------\n");
		printf("Name:%s\n",name);
		printf("Address:%s\n",address);
		printf("Gender:%s\n",gender);
		printf("email:%s\n",email);
		printf("Phone:%.0lf\n",phone);
			f=1;
				printf("------------------------------------------");
				printf("\n\n");
		}
		Sleep(1000);
		printf("Enter y for menu section:");
		while(getch()=='y'){
			menu();
		}
			fclose(fptr);
			}
void modifyfun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],email[100],email1[100],address1[100],name1[100],gender[8],gender1[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("ebraj.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(31,4);
	printf("Enter the name: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,email,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			gotoxy(31,4);
	printf("MODIFY SECTION OPENED ");
			gotoxy(31,6);
			printf("Enter the new address:");
			scanf("%s",address1);
				gotoxy(31,7);
			printf("Enter the gender:");
			scanf("%s",gender1);
			gotoxy(31,8);
			printf("Enter the new email:");
			scanf("%s",email1);
			gotoxy(31,9);
			printf("Enter the new phone number:");
			scanf("%lf",&phone1);
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address1,gender1,email1,phone1);
			
		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,email,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("ebraj.txt","w");
	fclose(fptr);
	fptr=fopen("ebraj.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,email,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,email,phone);	
	}
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	}
}
void deletefun(){
	FILE *fptr,*fptr1;
	char name[100],address[100],email[100],email1[100],address1[100],name1[100],gender[8];
	int res,f=0;
	double phone,phone1;
	fptr=fopen("ebraj.txt","r");
	fptr1=fopen("temp.txt","a");
	system("cls");
	gotoxy(31,4);
	printf("Enter the CONTACT name that you want to delete: ");
	gets(name1);
	system("cls");
	while(fscanf(fptr,"%s %s %s %s %lf\n",name,address,gender,email,&phone)!=EOF){
		res=strcmp(name,name1);
		if(res==0)
		{
			f=1;
			printf("Record deleted successfully");
			
		}else{
			fprintf(fptr1,"%s %s %s %s %.0lf\n",name,address,gender,email,phone);
		}
	}
	if(f==0){
		printf("Record Not found.");
			}
	fclose(fptr);
	fclose(fptr1);
	fptr=fopen("ebraj.txt","w");
	fclose(fptr);
	fptr=fopen("ebraj.txt","a");
	fptr1=fopen("temp.txt","r");
	while(fscanf(fptr1,"%s %s %s %s %lf\n",name,address,gender,email,&phone)!=EOF){
		fprintf(fptr,"%s %s %s %s %.0lf\n",name,address,gender,email,phone);		
	}
	fclose(fptr);
	fclose(fptr1);
	fptr1=fopen("temp.txt","w");
	fclose(fptr1);
	printf("\n\nPress y for menu option.");
	fflush(stdin);
	if(getch()=='y'){
		menu();
	};
}
void exitfun(){
	system("cls");
}
void menu(){
	system("cls");
	gotoxy(30,1);
	printf("PHONEBOOK DIRECTORY ");
	gotoxy(31,4);
	printf("1.Add New");
	gotoxy(31,7);
	printf("2.List");
	gotoxy(31,10);
	printf("3.Modify");
	gotoxy(31,13);
	printf("4.Delete");
	gotoxy(31,16);
	printf("5.Exit");
	gotoxy(31,19);
	printf("What do you want to do?");
	switch(getch()){
		case '1':
			namefun();
			break;
		case '2':
			listfun();
			break;
		case '3':
			modifyfun();
			break;
		case '4':
			deletefun();
			break;
		case '5':
			exitfun();
			break;
		default:
			system("cls");
			printf("Invalid Enter.");
			getch();
}
}