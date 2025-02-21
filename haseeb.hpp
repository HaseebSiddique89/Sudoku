#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;
int lives7=7;
void livesf(int a,int b)
{
	if(a==b)
	{
		lives7=lives7;
	}
	else
	{
		lives7--;
	}
}
void livesf()
{
	for(int i=0;i<lives7;i++)
	{
		cout<<"+";
	}
}
void color(int color)
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void paint(int a, int b)
{
	if(a==0)
	{
		color(255);
	}
	else if(a==b)
	{
		color(241);
	}
	else
	{
		color(244);
	}
}
int arro[6][6]={0,0,1,5,0,0,
               0,3,0,0,0,1,
               1,0,0,0,3,0,
               0,4,0,0,0,2,
               4,0,0,0,5,0,
               0,0,3,2,0,0};
int arr[6][6]={0,0,1,5,0,0,
               0,3,0,0,0,1,
               1,0,0,0,3,0,
               0,4,0,0,0,2,
               4,0,0,0,5,0,
               0,0,3,2,0,0};
int arrs[6][6]={2,6,1,5,4,3,
                5,3,4,6,2,1,
				1,2,6,4,3,5,
				3,4,5,1,6,2,
				4,1,2,3,5,6,
				6,5,3,2,1,4};
void sudoko()
{
	system("Color F0");
	if(lives7!=8)
	{
		cout<<"-------------------------SUDOKU-------------------------\n";
		cout<<"                          EASY           \n";
		cout<<"--------------------------------------------------------\n\n";
		cout<<"\t\t\tlives: ";livesf();cout<<endl;
	}
	cout<<endl;
	color(240);cout<<"\t      1   2   3    4   5   6"<<endl;
	color(240);cout<<"\t   ============================"<<endl;
	color(240);cout<<"\t1  || ";paint(arr[0][0],arrs[0][0]);cout<<arr[0][0];color(247);cout<<" | ";paint(arr[0][1],arrs[0][1]);cout<<arr[0][1];color(247);cout<<" | ";color(240);cout<<arr[0][2];color(240);cout<<" || ";color(240);cout<<arr[0][3];color(247);cout<<" | ";paint(arr[0][4],arrs[0][4]);cout<<arr[0][4];color(247);cout<<" | ";paint(arr[0][5],arrs[0][5]);cout<<arr[0][5];color(240);cout<<" || "<<endl;	
	cout<<"\t   ||";color(247);cout<<"---|---|---";color(240);cout<<"||";color(247);cout<<"---|---|---";color(240);cout<<"||"<<endl;
	color(240);cout<<"\t2  || ";paint(arr[1][0],arrs[1][0]);cout<<arr[1][0];color(247);cout<<" | ";color(240);cout<<arr[1][1];color(247);cout<<" | ";paint(arr[1][2],arrs[1][2]);cout<<arr[1][2];color(240);cout<<" || ";paint(arr[1][3],arrs[1][3]);cout<<arr[1][3];color(247);cout<<" | ";paint(arr[1][4],arrs[1][4]);cout<<arr[1][4];color(247);cout<<" | ";color(240);cout<<arr[1][5];;color(240);cout<<" || "<<endl;
	cout<<"\t   ||===|===|===||===|===|===||"<<endl;
	color(240);cout<<"\t3  || ";color(240);cout<<arr[2][0];color(247);cout<<" | ";paint(arr[2][1],arrs[2][1]);cout<<arr[2][1];color(247);cout<<" | ";paint(arr[2][2],arrs[2][2]);cout<<arr[2][2];color(240);cout<<" || ";paint(arr[2][3],arrs[2][3]);cout<<arr[2][3];;color(247);cout<<" | ";color(240);cout<<arr[2][4];color(247);cout<<" | ";paint(arr[2][5],arrs[2][5]);cout<<arr[2][5];color(240);cout<<" || "<<endl;
	cout<<"\t   ||";color(247);cout<<"---|---|---";color(240);cout<<"||";color(247);cout<<"---|---|---";color(240);cout<<"||"<<endl;
	color(240);cout<<"\t4  || ";paint(arr[3][0],arrs[3][0]);cout<<arr[3][0];color(247);cout<<" | ";color(240);cout<<arr[3][1];color(247);cout<<" | ";paint(arr[3][2],arrs[3][2]);cout<<arr[3][2];color(240);cout<<" || ";paint(arr[3][3],arrs[3][3]);cout<<arr[3][3];color(247);cout<<" | ";paint(arr[3][4],arrs[3][4]);cout<<arr[3][4];color(247);cout<<" | ";color(240);cout<<arr[3][5];color(240);cout<<" || "<<endl;
	cout<<"\t   ||===|===|===||===|===|===||"<<endl;
    color(240);cout<<"\t5  || ";color(240);cout<<arr[4][0];color(247);cout<<" | ";paint(arr[4][1],arrs[4][1]);cout<<arr[4][1];color(247);cout<<" | ";paint(arr[4][2],arrs[4][2]);cout<<arr[4][2];color(240);cout<<" || ";paint(arr[4][3],arrs[4][3]);cout<<arr[4][3];color(247);cout<<" | ";color(240);cout<<arr[4][4];color(247);cout<<" | ";paint(arr[4][5],arrs[4][5]);cout<<arr[4][5];color(240);cout<<" || "<<endl;
    cout<<"\t   ||";color(247);cout<<"---|---|---";color(240);cout<<"||";color(247);cout<<"---|---|---";color(240);cout<<"||"<<endl;
	color(240);cout<<"\t6  || ";paint(arr[5][0],arrs[5][0]);cout<<arr[5][0];color(247);cout<<" | ";paint(arr[5][1],arrs[5][1]);cout<<arr[5][1];color(247);cout<<" | ";color(240);cout<<arr[5][2];color(240);cout<<" || ";color(240);cout<<arr[5][3];color(240);cout<<" | ";paint(arr[5][4],arrs[5][4]);cout<<arr[5][4];color(247);cout<<" | ";paint(arr[5][5],arrs[5][5]);cout<<arr[5][5];color(240);cout<<" || "<<endl;
	cout<<"\t   ============================"<<endl;
}
void Sudoku6x6()
{
	system("Color F1");
	int a,b,c,d,e,g,h;
	char f;
	bool check=true,filled=true;
	jump:
	jump3:
	system("cls");
		jump6:
		system("cls");
		sudoko();
		jump7:
		cout<<endl<<"Enter Row Number: ";
		cin>>b;
		if(b<1||b>6)
		{
			jump4:
			cin.clear();
			cin.ignore();
			system("cls");
			sudoko();
			cout<<endl;
			cout<<"Error! Please enter Row number from 1 to 6"<<'\a'<<endl<<endl;
			cout<<"Enter Row Number: ";
			cin>>b;
			if(b<1||b>6)
			{
			   goto jump4;	
			}
			else
			{
				system("cls");
				sudoko();
				cout<<endl<<"Row Number: "<<b<<endl;
			}
		}
		cout<<"Enter Column Number: ";
		cin>>c;
		if(c<1||c>6)
		{
			jump5:
			cin.clear();
			cin.ignore();
			system("cls");
			sudoko();
			cout<<endl;
			cout<<"Row Number: "<<b<<endl;
		    cout<<"Error! Please Enter column Number From 1 To 6."<<'\a'<<endl;
			cout<<"Enter Column Number: ";
			cin>>c;
			if(c<1||c>6)
			{
				goto jump5;
			}
			else
			{
				system("cls");
				sudoko();
				cout<<endl<<"Row Number: "<<b<<endl;
    			cout<<"Column Number: "<<c;
			}
		}
		if(b==1&&c==3||b==1&&c==4||b==2&&c==2||b==2&&c==6||b==3&&c==1||b==3&&c==5||b==4&&c==2||b==4&&c==6||b==5&&c==1||b==5&&c==5||b==6&&c==3||b==6&&c==4)
		{
			system("cls");
			sudoko();
			cout<<endl<<"Error! Default Value can not be change."<<'\a'<<endl;
			goto jump7;				
		}
		cout<<endl<<"Enter Number You Want To Put In "<<b<<":"<<c<<" ";
		cin>>d;
		if(d>=1&&d<=6)
		{
			arr[b-1][c-1]=d;	
			livesf(arr[b-1][c-1],arrs[b-1][c-1]);
			jump8:
			system("cls");
			sudoko();
			jump10:
			if(lives7>0)
			{	
				for(int i=0;i<6;i++)
				{
					for(int j=0;j<6;j++)
					{
						if(arr[i][j]==0)
						{
							filled=false;
							break;
						}
						else
							filled=true;
					}
					if(!filled)
					{
						break;
					}
				}
				if(filled)
				{
					cout<<endl<<"Do You want to make Changes? "<<endl<<"Y for yes. N for No."<<endl;
					f=getch();
				}
				else
					f='y';
				if(f=='y'||f=='Y')
					{
						goto jump6;
					}
				else if(f=='n'||f=='N')
					{
						for(g=0; g<=5; g++)
						{
							for(h=0; h<=5; h++)
							{
							
								if(arr[g][h]!=arrs[g][h])
								{
								check=false;
								break;
								}
							}
						}
						if(check)
						{
							system("cls");
							cout<<endl<<endl;
							cout<<"Congratulations, You won the game."<<endl;
						}
					else
					{
						lost:
							system("cls");
							if(lives7<=0)
							{
								cout<<endl<<"Ran Out of Lives."<<endl;
							}
							cout<<"Sorry! you Lose!"<<endl;
							for(int i=0;i<6;i++)
							{
								for(int j=0;j<6;j++)
								{
									arr[i][j]=arrs[i][j];
								}
							}
							lives7=8;
							cout<<"Here is the Correct solution."<<endl;
							sudoko();
							lives7=7;
							for(int i=0;i<6;i++)
							{
								for(int j=0;j<6;j++)
								{
									arr[i][j]=arro[i][j];
								}
							}
					}
				}
				else if(f!='Y'||f!='y'||f!='n'||f!='N')
				{
					cin.clear();
					cin.ignore();
					cout<<'\a';
					goto jump8;					
				}
				}
				else if(lives7<=0)
				{
					goto lost;
				}
				system("pause");
			}
			else if(d<1||d>6)
			{
				jump9:
				cin.clear();
				cin.ignore();
				system("cls");
				sudoko();
				cout<<endl;
				cout<<"Please enter number from 1 to 6"<<'\a'<<endl;
				cin>>d;
				if(d<1||d>6)
				{
					goto jump9;
				}
				else if(d>=1&&d<=6)
				{
					arr[b-1][c-1]=d;
					livesf(arr[b-1][c-1],arrs[b-1][c-1]);
					system("cls");
					sudoko();
					goto jump10;
				}
			}	
}
