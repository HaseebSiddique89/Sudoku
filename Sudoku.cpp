#include<iostream>
#include<conio.h>
#include "play.hpp"
#include "haseeb.hpp"
using namespace std;
						//*****Menu*****
int main()
{
	menu:
		system("cls");
		system("Color BD");
			
	char input;
	cout<<"-----------SUDOKU-----------\n";
	cout<<"            MENU            \n";
	cout<<"----------------------------\n\n";
	cout<<"\t1. Play\n";
	cout<<"\t2. Help\n";
	cout<<"\t3. Developers\n";
	cout<<"\t4. Exit\n\n";
	cout<<"--------------------------\n\n";
	cout<<"Select option from menu.\n ";
	input=getch();
	
    switch(input){
    	case '1':
    		level:
    		char ask;
    		system("cls");
    		cout<<"-----------SUDOKU-----------\n";
			cout<<"            PLAY            \n";
			cout<<"----------------------------\n\n";
			cout<<"\t1. Easy\n";
			cout<<"\t2. Hard\n";
			cout<<"\n\t0. Go Back";
			cout<<"\n--------------------------\n\n";
			cout<<"Choose difficulty level.\n ";
			ask=getch();
			switch(ask){
				case '1':
					Sudoku6x6();
					break;
				case '2':
					i=1;
					Sudoku9x9();
					break;
				case '0':
					goto menu;
				default:
					cout<<"\a";
					goto level;
			}
    		goto menu;
    	case '2':
    		rules();
    		cout<<"Press any key to return to menu...";
    		getch();
    		goto menu;
    	case '3':
    		developer();
    		goto menu;
    	case '4':
    		exit();
    		break;
    	default:
    		cout<<"\a";
			goto menu;
	}
	
	return 0;
}
