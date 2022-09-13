#include<iostream>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
#include<process.h>
#include<conio.h>
#include<fstream>



using namespace std;

class user
	{
	char name[20],mno[10],gender,condition[20];
	int age,dietplan;
	float weight,height,bmi,bfp;
	public:
	  user()
	 {
	 }
	void input();
	void cal();
	void bmi_show();
	void bfp_show();
	void diet_show();
}ob;

void loading();
void fitness();
void mainmenu();




void user::input()
{     	
	cout<<"\nEnter Name: ";
	cin>>name;
	cout<<"\nEnter Gender(m for male/f for female): ";
	gender=getche();
	cout<<"\nEnter Age: ";
	cin>>age;
	cout<<"\nEnter Weight(Should be in Kg): ";
	cin>>weight;
	cout<<"\nEnter Height(Should be in mtrs like 182cm= 1.82m): ";
	cin>>height;
	cout<<"\nMobile Number: ";
	cin>>mno;
	
}
void user::cal()
{
int g;
//bmi
bmi= weight/(height*height);
if(age<20&&gender=='m'||gender=='M')
g=1;
else if(age<20&&gender=='f'||gender=='F')
g=2;
else if(age>=20&&gender=='m'||gender=='M')
g=3;
else if(age>20&&gender=='f'||gender=='F')
g=4;

if(bmi<18.5)
	{
		strcpy(condition,"underweight");
	}
	else if(bmi>=18.5 && bmi<24.5)
	{
		strcpy(condition,"fit");
	}
	else if(bmi>=24.5 && bmi<30)
	{
		strcpy(condition,"overweight");
	}
	else if(bmi>=30)
	{
		strcpy(condition,"obese");
	}
	//BFP
switch(g)
	{
		case 1:
			bfp= (1.20*bmi)+(0.23*age)-5.4;
			break;
			case 2:
			bfp= (1.20*bmi)+(0.23*age)-16.2;
			break;
			case 3:
			bfp= (1.51*bmi)+(0.70*age)-2.2;
			break;
			case 4:
			bfp= (1.51*bmi)+(0.70*age)-1.4;
			break;
			default:
				break;
	}
	//dietplan
	if(strcmp(condition,"underweight")==0 && gender=='m'|| gender=='M')
	{
		dietplan=1;
	}
	else if(strcmp(condition,"fit")==0 && gender=='m'|| gender=='M')
	{
		dietplan=2;
    }
	else if(strcmp(condition,"overweight")==0 && gender=='m'|| gender=='M')
	{
		dietplan=3;
	}
    else if(strcmp(condition,"obese")==0 && gender=='m'|| gender=='M')
	{
		dietplan=4;
	}	
	else if(strcmp(condition,"underweight")==0 && gender=='f'|| gender=='F')
	{
		dietplan=5;
	}
	else if(strcmp(condition,"fit")==0 && gender=='f'|| gender=='F')
	{
		dietplan=6;
	}
	else if(strcmp(condition,"overweight")==0 && gender=='f'|| gender=='F')
	{
		dietplan=7;
	}
    else if(strcmp(condition,"obese")==0 && gender=='f'|| gender=='F')
	{
		dietplan=8;
	}

}

void user:: bmi_show()
{
	system("cls");
	system("color F1");
	cout<<"Body Mass Index : "<<bmi<<"\n\n\n";
	 if(strcmp(condition,"underweight")==0)
	 {
	 	cout<<"\n\n*UNDERWEIGHT";
	 	cout<<"\t\tFIT";
	 	cout<<"\t\tOVERWEIGHT";
	 	cout<<"\t\tOBESE";
	 }
	else if(strcmp(condition,"fit")==0)
	{cout<<"\n\nUNDERWEIGHT";
	 	cout<<"\t\t*FIT";
	 	cout<<"\t\tOVERWEIGHT";
	 	cout<<"\t\tOBESE";
	}
	else if(strcmp(condition,"overweight")==0)
	{cout<<"\n\nUNDERWEIGHT";
	 	cout<<"\t\tFIT";
	 	cout<<"\t\t*OVERWEIGHT";
	 	cout<<"\t\tOBESE";
	}
	else if(strcmp(condition,"obese")==0)
	{cout<<"\n\nUNDERWEIGHT";
	 	cout<<"\t\tFIT";
	 	cout<<"\t\tOVERWEIGHT";
	 	cout<<"\t\t*OBESE";
	}
	system("color F1");
	cout<<"\n\n>>For Go Back to the Main Menu Press b\n";
	char ch;
		c:
	ch=getche();
	if(ch=='b'||ch=='B')
	{
	mainmenu();	
	}
	else
	{cout<<"\n\nInvalid Key!!";
	cout<<"\n\nPress Again!!";
	goto c;
	}
	
}
void user::bfp_show()
{
	system("cls");
	system("color F1");
	char ch;
	cout<<"Body Fat Percentage : "<<bfp<<"\n";
	cout<<"\n\n>>For Go Back to the Main Menu Press b\n";
	b:
	ch=getche();
	if(ch=='b'||ch=='B')
	{
	mainmenu();	
	}
	else
	{cout<<"\n\nInvalid Key!!";
	cout<<"\n\nPress Again!!";
	goto b;
	}
}
void user::diet_show()
{
	system("color D7");
	string str;
	ifstream fr;
	system("cls");
	cout<<"According to your current body\n";
	
	if(dietplan==1)
	{
		cout<<"\nYou need 3361 calories/day To gain 2lb per week.\n";
	fr.open("1.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	
	}
	else if(dietplan==2)
	{
		cout<<"\nYou need 2361 calories/day To Maintain Your Weight.";
	fr.open("2.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	}
else if(dietplan==3)
	{
		cout<<"\nYou need 1861 calories/day To lose 1lb per week";
	fr.open("3.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	}
else if(dietplan==4)
	{
		cout<<"\nYou need 1361 calories/day To lose 2lb per week";
	fr.open("4.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	}
else if(dietplan==5)
	{
		cout<<"\nYou need 2861 calories/day To gain 2lb per week";
fr.open("5.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	}
else if(dietplan==6)
	{
		cout<<"\nYou need 2061 calories/day to maintain your weight";
	fr.open("6.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	}
else if(dietplan==7)
	{
		cout<<"\nYou need 1561 calories/day To lose 1lb per week";
	fr.open("7.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	
	}
else if(dietplan==8)
	{
		cout<<"\nYou need 1061 calories/day To lose 2lb per week";
fr.open("8.txt");
	while(!fr.eof())
	{
		getline(fr,str);
		cout<<str<<"\n";
	}
	}
	cout<<"\n\n>>For Go Back to the Main Menu Press b\n";
	char ch;
	d:
	ch=getche();
	if(ch=='b'||ch=='B')
	{
	mainmenu();	
	}
	else
	{cout<<"\n\nInvalid Key!!";
	cout<<"\n\nPress Again!!";
	goto d;
	}
	

}

void fitness()
{
	system("color E1");
	cout<<"\n\n\n\n\n\n\t\t********************************\n";
    cout<<"\t\t\t\t\tFitness\n";
	cout<<"\t\t\t\t\t*****************************************";
	
}
void loading()
{
	int i=0,j=0;
	fitness();
cout<<"\n\n\n\n\t\t\t\t\t";
cout<<i<<"%";
		cout<<"#";
		Sleep(200);
        cout<<"#";
		Sleep(200);
		cout<<"#";
		Sleep(200);
		cout<<"#";
		Sleep(200);
		
	
	while(1)
	{
		system("cls");
		fitness();
		cout<<"\n\n\n\n\t\t\t\t\t";
		if(j%3==0)
		i=i+20;
		cout<<i<<"%";
		cout<<"#";
		Sleep(200);
        cout<<"#";
		Sleep(200);
		cout<<"#";
		Sleep(200);
		cout<<"#";
		Sleep(200);
		
		j++;
		if(i==100)		
		break;
		
	}
}
void mainmenu()
{system("cls");
system("color E1");
char ch;
 cout<<"\n\n\t\t\t\t\tFitness Calculator\n\n";
 cout<<"\n\t\t\t\t\t1.Body Mass Index";
 cout<<"\n\t\t\t\t\t2.Body Fat Percentage";
 cout<<"\n\t\t\t\t\t3.Diet Plan";
 cout<<"\n\t\t\t\t\t4.Exit\n\n";
 cout<<">>Enter Your Choice...\n";
A:
 ch=getche();

switch(ch)
	{
		case '1':
			ob.bmi_show();
			break;
			case '2':
			ob.bfp_show();
			break;
			case '3':
			ob.diet_show();
			break;
			case '4':
				exit(0);
				break;
			default:
				
				cout<<"\n\nInvalid Key!!";
				cout<<"\n\nPress Again!!";
				goto A;
				break;
	}
 
}
int main()
{
	loading();
	system("color B1");
    system("cls");
    ob.input();
    ob.cal();
	mainmenu();
	return 0;
}
