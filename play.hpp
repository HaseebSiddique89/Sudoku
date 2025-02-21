#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void Color(int color)	//Copied from google
{
 SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
						//*****Global variables*****
int sbe[9][9]={			// sbe(SudokuBoard External) used to reset values of sb before every game. 0 means empty cell
    {0,7,9,0,4,0,5,0,0},
    {1,8,0,3,5,0,0,0,0},
    {0,0,0,1,0,0,0,6,0},
    {4,1,0,2,0,9,6,7,5},
    {0,0,0,7,0,8,0,3,0},
    {3,2,7,5,0,4,8,0,1},
    {0,3,1,0,0,0,0,4,6},
    {9,0,0,0,7,0,0,0,0},
    {0,0,0,4,0,0,1,0,9}
    };
int sb[9][9];			// sb(SudokuBoard) used to display BOARD, also its value changes through input(if !default)
int sbs[9][9]={			// sbs(SudokuBoard Solution) holds correct values
    		{6,7,9,8,4,2,5,1,3},
    		{1,8,4,3,5,6,9,2,7},
    		{2,5,3,1,9,7,4,6,8},
   			{4,1,8,2,3,9,6,7,5},
   			{5,9,6,7,1,8,2,3,4},
    		{3,2,7,5,6,4,8,9,1},
    		{8,3,1,9,2,5,7,4,6},
    		{9,4,5,6,7,1,3,8,2},
    		{7,6,2,4,8,3,1,5,9}
    	};
int i=1,lives=5;		// i is used to run the loop that resets sb array
						//*****Set Color*****
void clr(int a,int b){	// clr(two parameters) for color of non-default values
	if(a==0)
		Color(255);		//White(invisible because its = background color
	else if(a==b)
		Color(241);		//Blue
	else{
		Color(244);		//Red
	}
}
void clr(int a){		// clr(single parameter) for color of Default values and border(|,||,-,_ e.t.c)
	if(a==1){
		Color(247);		//Light-gray for light border
	}
	else if(a==2){
		Color(240);		//Black for default values and dark border
	}
	else
		Color(250);		//green just to check and avoid wrong parameter
}
void Clr(int a){		//used during comparison after losing the game
	if(a==0){
		Color(255);		//White
	}
	else{
		Color(241);		//Blue
	}
}
						//*****9x9 Board*****
char sudokuBoard(){
	if(i!=1)
		goto print;
	if(i==1){
		for(int i=0;i<9;i++){		//resetting values of sb
			for(int j=0;j<9;j++){
				sb[i][j]=sbe[i][j];
			}
		}
		i++;						//increamented i so resetting only happens once in whole game
	}
	print:
	char cont='y';					// cont(continue) to ask user if want to change values or move to result
	bool filled=false;				// Empty to check that board is empty or not
								//********Display********
		cout<<"-------------------------SUDOKU-------------------------\n";
		cout<<"                          HARD           \n";
		cout<<"--------------------------------------------------------\n\n";
	cout<<"\t				lives: "; 
	for(int l=1;l<=lives;l++){		// Displaying lives
		cout<<"+";
	}
	cout<<endl<<endl;		//Displaying sudokuBoard below
	clr(2);cout<<"\t      1   2   3    4   5   6    7   8   9   \n";
		   cout<<"\t   =========================================\n";
	clr(2);cout<<"\t1. || ";clr(sb[0][0],sbs[0][0]);cout<<sb[0][0];clr(1);cout<<" | ";Color(240);cout<<sb[0][1];clr(1);cout<<" | ";Color(240);cout<<sb[0][2];
	clr(2);cout<<" || ";clr(sb[0][3],sbs[0][3]);cout<<sb[0][3];clr(1);cout<<" | ";Color(240);cout<<sb[0][4];clr(1);cout<<" | ";clr(sb[0][5],sbs[0][5]);cout<<sb[0][5];
	clr(2);cout<<" || ";Color(240);cout<<sb[0][6];clr(1);cout<<" | ";clr(sb[0][7],sbs[0][7]);cout<<sb[0][7];clr(1);cout<<" | ";clr(sb[0][8],sbs[0][8]);cout<<sb[0][8];clr(2);cout<<" ||\n";
	Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
	
	clr(2);cout<<"\t2. || ";Color(240);cout<<sb[1][0];clr(1);cout<<" | ";Color(240);cout<<sb[1][1];clr(1);cout<<" | ";clr(sb[1][2],sbs[1][2]);cout<<sb[1][2];
	clr(2);cout<<" || ";Color(240);cout<<sb[1][3];clr(1);cout<<" | ";Color(240);cout<<sb[1][4];clr(1);cout<<" | ";clr(sb[1][5],sbs[1][5]);cout<<sb[1][5];
	clr(2);cout<<" || ";clr(sb[1][6],sbs[1][6]);cout<<sb[1][6];clr(1);cout<<" | ";clr(sb[1][7],sbs[1][7]);cout<<sb[1][7];clr(1);cout<<" | ";clr(sb[1][8],sbs[1][8]);cout<<sb[1][8];clr(2);cout<<" ||\n";
	Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
	
	clr(2);cout<<"\t3. || ";clr(sb[2][0],sbs[2][0]);cout<<sb[2][0];clr(1);cout<<" | ";clr(sb[2][1],sbs[2][1]);cout<<sb[2][1];clr(1);cout<<" | ";clr(sb[2][2],sbs[2][2]);cout<<sb[2][2];
	clr(2);cout<<" || ";Color(240);cout<<sb[2][3];clr(1);cout<<" | ";clr(sb[2][4],sbs[2][4]);cout<<sb[2][4];clr(1);cout<<" | ";clr(sb[2][5],sbs[2][5]);cout<<sb[2][5];
	clr(2);cout<<" || ";clr(sb[2][6],sbs[2][6]);cout<<sb[2][6];clr(1);cout<<" | ";Color(240);cout<<sb[2][7];clr(1);cout<<" | ";clr(sb[2][8],sbs[2][8]);cout<<sb[2][8];clr(2);cout<<" ||\n";
	cout<<"\t   ||===|===|===||===|===|===||===|===|===||\n";
	
	clr(2);cout<<"\t4. || ";Color(240);cout<<sb[3][0];clr(1);cout<<" | ";Color(240);cout<<sb[3][1];clr(1);cout<<" | ";clr(sb[3][2],sbs[3][2]);cout<<sb[3][2];
	clr(2);cout<<" || ";Color(240);cout<<sb[3][3];clr(1);cout<<" | ";clr(sb[3][4],sbs[3][4]);cout<<sb[3][4];clr(1);cout<<" | ";Color(240);cout<<sb[3][5];
	clr(2);cout<<" || ";Color(240);cout<<sb[3][6];clr(1);cout<<" | ";Color(240);cout<<sb[3][7];clr(1);cout<<" | ";Color(240);cout<<sb[3][8];clr(2);cout<<" ||\n";
	Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
	
	clr(2);cout<<"\t5. || ";clr(sb[4][0],sbs[4][0]);cout<<sb[4][0];clr(1);cout<<" | ";clr(sb[4][1],sbs[4][1]);cout<<sb[4][1];clr(1);cout<<" | ";clr(sb[4][2],sbs[4][2]);cout<<sb[4][2];
	clr(2);cout<<" || ";Color(240);cout<<sb[4][3];clr(1);cout<<" | ";clr(sb[4][4],sbs[4][4]);cout<<sb[4][4];clr(1);cout<<" | ";Color(240);cout<<sb[4][5];
	clr(2);cout<<" || ";clr(sb[4][6],sbs[4][6]);cout<<sb[4][6];clr(1);cout<<" | ";Color(240);cout<<sb[4][7];clr(1);cout<<" | ";clr(sb[4][8],sbs[4][8]);cout<<sb[4][8];clr(2);cout<<" ||\n";
	Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
	
	clr(2);cout<<"\t6. || ";Color(240);cout<<sb[5][0];clr(1);cout<<" | ";Color(240);cout<<sb[5][1];clr(1);cout<<" | ";Color(240);cout<<sb[5][2];
	clr(2);cout<<" || ";Color(240);cout<<sb[5][3];clr(1);cout<<" | ";clr(sb[5][4],sbs[5][4]);cout<<sb[5][4];clr(1);cout<<" | ";Color(240);cout<<sb[5][5];
	clr(2);cout<<" || ";Color(240);cout<<sb[5][6];clr(1);cout<<" | ";clr(sb[5][7],sbs[5][7]);cout<<sb[5][7];clr(1);cout<<" | ";Color(240);cout<<sb[5][8];clr(2);cout<<" ||\n";
	cout<<"\t   ||===|===|===||===|===|===||===|===|===||\n";
	
	clr(2);cout<<"\t7. || ";clr(sb[6][0],sbs[6][0]);cout<<sb[6][0];clr(1);cout<<" | ";Color(240);cout<<sb[6][1];clr(1);cout<<" | ";Color(240);cout<<sb[6][2];
	clr(2);cout<<" || ";clr(sb[6][3],sbs[6][3]);cout<<sb[6][3];clr(1);cout<<" | ";clr(sb[6][4],sbs[6][4]);cout<<sb[6][4];clr(1);cout<<" | ";clr(sb[6][5],sbs[6][5]);cout<<sb[6][5];
	clr(2);cout<<" || ";clr(sb[6][6],sbs[6][6]);cout<<sb[6][6];clr(1);cout<<" | ";Color(240);cout<<sb[6][7];clr(1);cout<<" | ";Color(240);cout<<sb[6][8];clr(2);cout<<" ||\n";
	Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
	
	clr(2);cout<<"\t8. || ";Color(240);cout<<sb[7][0];clr(1);cout<<" | ";clr(sb[7][1],sbs[7][1]);cout<<sb[7][1];clr(1);cout<<" | ";clr(sb[7][2],sbs[7][2]);cout<<sb[7][2];
	clr(2);cout<<" || ";clr(sb[7][3],sbs[7][3]);cout<<sb[7][3];clr(1);cout<<" | ";Color(240);cout<<sb[7][4];clr(1);cout<<" | ";clr(sb[7][5],sbs[7][5]);cout<<sb[7][5];
	clr(2);cout<<" || ";clr(sb[7][6],sbs[7][6]);cout<<sb[7][6];clr(1);cout<<" | ";clr(sb[7][7],sbs[7][7]);cout<<sb[7][7];clr(1);cout<<" | ";clr(sb[7][8],sbs[7][8]);cout<<sb[7][8];clr(2);cout<<" ||\n";
	Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
	
	clr(2);cout<<"\t9. || ";clr(sb[8][0],sbs[8][0]);cout<<sb[8][0];clr(1);cout<<" | ";clr(sb[8][1],sbs[8][1]);cout<<sb[8][1];clr(1);cout<<" | ";clr(sb[8][2],sbs[8][2]);cout<<sb[8][2];
	clr(2);cout<<" || ";Color(240);cout<<sb[8][3];clr(1);cout<<" | ";clr(sb[8][4],sbs[8][4]);cout<<sb[8][4];clr(1);cout<<" | ";clr(sb[8][5],sbs[8][5]);cout<<sb[8][5];
	clr(2);cout<<" || ";Color(240);cout<<sb[8][6];clr(1);cout<<" | ";clr(sb[8][7],sbs[8][7]);cout<<sb[8][7];clr(1);cout<<" | ";Color(240);cout<<sb[8][8];clr(2);cout<<" ||\n";
	cout<<"\t   =========================================\n";
	
	Color(253);
	for(int c=0;c<9;c++){		//Checks if there is any empty cell in board(sb[r][c]==0)
		for(int d=0;d<9;d++){
			if(sb[c][d]==0){
				filled=true;
				cont='y';		//if board is empty it automatically set cont(continue) to y(yes)
				break;
			}
		}
		if(filled){
				break;
		}
	}	
	if(!filled){				//if board has no empty cell, it asks user if he/she wants to make changes
		cout<<"Do you want to make changes(y/n)? ";
		cont=getch();
		if(cont!='y'&&cont!='Y'&&cont!='n'&&cont!='N'){
			cout<<"\a";
			goto print;
		}
	}

		return cont;
}
						//*****Original_Part*****
void Sudoku9x9(){
	char con;			// con means continue, recieves value of cont(continue) from sudokuBoard return
	int r=1,c=2,in=7;	// r is for row input, c for column, in for input value of rxc 
	int a=2;			// a is for cout displaying error for invalid input, also lives finished wali cout
	do{
		if(lives<1){
		a=3;
		goto discontinue;
	}
		input:
			system("cls");
			system("Color F0");
			con=sudokuBoard();
			if(con=='n'||con=='N')
				goto discontinue;
			if(a==1){
				cout<<"\n\aError:Default values can't be changed!\n";
				a=2;
			}
			do{
    			cout<<"\n         Enter row(1-9): ";
    			cin>>r;
    			if(r<1||r>9){
    				cin.clear();
					cin.ignore();
    				system("cls");
    				sudokuBoard();
    				cout<<"\n\aError: Unexpected input of row!\n\n";
    			}
			}while(r<1||r>9);
		
			do{
    			cout<<"      Enter column(1-9): ";
    			cin>>c;
    			if(c<1||c>9){
    				cin.clear();
					cin.ignore();
    				system("cls");
    				sudokuBoard();
    				cout<<"\n\aError: Unexpected input of column!\n";
    			//	goto input;
    				cout<<"\n         Enter row(1-9): "<<r<<endl;
    			}
			}while(c<1||c>9);
			if(r==1){
				if(c==2||c==3||c==5||c==7){
					a=1;
					goto input;
				}
			}
			else if(r==2){
				if(c==1||c==2||c==4||c==5){
					a=1;
					goto input;
				}
			}
			else if(r==3){
				if(c==4||c==8){
					a=1;
				goto input;
				}
			}
			else if(r==4){
				if(c!=3&&c!=5){
					a=1;
					goto input;
				}
			}
			else if(r==5){
				if(c==4||c==6||c==8){
					a=1;
					goto input;
				}
			}
			else if(r==6){
				if(c!=5&&c!=8){
					a=1;
					goto input;
				}
			}
			else if(r==7){
				if(c==2||c==3||c==8||c==9){
					a=1;
					goto input;
				}
			}
			else if(r==8){
				if(c==1||c==5){
					a=1;
					goto input;
				}
			}
			else if(r==9){
				if(c==4||c==7||c==9){
					a=1;
					goto input;
				}
			}
			do{
    			cout<<"Entre value of "<<r<<"x"<<c<<"(1-9): ";
    			cin>>in;
    			if(in<1||in>9){
    				cin.clear();
					cin.ignore();
    				system("cls");
    				sudokuBoard();
    				cout<<"\n\aError: Unexpected input!\n";
    				goto input;
    		//		cout<<"\n         Enter row(1-9): "<<r;
    		//		cout<<"\n      Enter column(1-9): "<<c<<endl;
    			}
			}while(in<1||in>9);
		
			sb[r-1][c-1]=in;
			if(sb[r-1][c-1]!=sbs[r-1][c-1]){
				lives-=1;       //lives=lives-1;
			}
			
	}while(con=='y'||'Y');
	discontinue:
		system("cls");
		bool solved=true;
    	for(int y=0;y<9;y++){
    		for(int z=0;z<9;z++){
    			if(sbs[y][z]!=sb[y][z]){
    				solved=false;
    				break;
    			}
			}
			if(!solved)
			break;
		}
		if(!solved){
			if(a==3)
				cout<<"\n\tOops, You lost all the five lives\n";
			lives=5;
			a=2;
			cout<<"\n\tYou lost, Next screen will compare your board!...\n";
			system("pause");
			system("cls");
			cout<<"\n\t\t\tYour Board\t\t\t\t\t\t\tCorrect Solution\n\n";
			clr(2);cout<<"\t      1   2   3    4   5   6    7   8   9   \t\t";
			clr(2);cout<<"\t      1   2   3    4   5   6    7   8   9   \n";
			cout<<"\t   =========================================\t\t";
			cout<<"\t   =========================================\n";	
			clr(2);cout<<"\t1. || ";clr(sb[0][0],sbs[0][0]);cout<<sb[0][0];clr(1);cout<<" | ";Color(240);cout<<sb[0][1];clr(1);cout<<" | ";Color(240);cout<<sb[0][2];
			clr(2);cout<<" || ";clr(sb[0][3],sbs[0][3]);cout<<sb[0][3];clr(1);cout<<" | ";Color(240);cout<<sb[0][4];clr(1);cout<<" | ";clr(sb[0][5],sbs[0][5]);cout<<sb[0][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[0][6];clr(1);cout<<" | ";clr(sb[0][7],sbs[0][7]);cout<<sb[0][7];clr(1);cout<<" | ";clr(sb[0][8],sbs[0][8]);cout<<sb[0][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t1. || ";Clr(sbs[0][0]);cout<<sbs[0][0];clr(1);cout<<" | ";Color(240);cout<<sbs[0][1];clr(1);cout<<" | ";Color(240);cout<<sbs[0][2];
				clr(2);cout<<" || ";Clr(sbs[0][3]);cout<<sbs[0][3];clr(1);cout<<" | ";Color(240);cout<<sbs[0][4];clr(1);cout<<" | ";Clr(sbs[0][5]);cout<<sbs[0][5];
				clr(2);cout<<" || ";Color(240);cout<<sbs[0][6];clr(1);cout<<" | ";Clr(sbs[0][7]);cout<<sbs[0][7];clr(1);cout<<" | ";Clr(sbs[0][8]);cout<<sbs[0][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\t\t";
				Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			clr(2);cout<<"\t2. || ";Color(240);cout<<sb[1][0];clr(1);cout<<" | ";Color(240);cout<<sb[1][1];clr(1);cout<<" | ";clr(sb[1][2],sbs[1][2]);cout<<sb[1][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[1][3];clr(1);cout<<" | ";Color(240);cout<<sb[1][4];clr(1);cout<<" | ";clr(sb[1][5],sbs[1][5]);cout<<sb[1][5];
			clr(2);cout<<" || ";clr(sb[1][6],sbs[1][6]);cout<<sb[1][6];clr(1);cout<<" | ";clr(sb[1][7],sbs[1][7]);cout<<sb[1][7];clr(1);cout<<" | ";clr(sb[1][8],sbs[1][8]);cout<<sb[1][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t2. || ";Color(240);cout<<sbs[1][0];clr(1);cout<<" | ";Color(240);cout<<sbs[1][1];clr(1);cout<<" | ";Clr(sbs[1][2]);cout<<sbs[1][2];
				clr(2);cout<<" || ";Color(240);cout<<sbs[1][3];clr(1);cout<<" | ";Color(240);cout<<sbs[1][4];clr(1);cout<<" | ";Clr(sbs[1][5]);cout<<sbs[1][5];
				clr(2);cout<<" || ";Clr(sbs[1][6]);cout<<sbs[1][6];clr(1);cout<<" | ";Clr(sbs[1][7]);cout<<sbs[1][7];clr(1);cout<<" | ";Clr(sbs[1][8]);cout<<sbs[1][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\t\t";
				Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			clr(2);cout<<"\t3. || ";clr(sb[2][0],sbs[2][0]);cout<<sb[2][0];clr(1);cout<<" | ";clr(sb[2][1],sbs[2][1]);cout<<sb[2][1];clr(1);cout<<" | ";clr(sb[2][2],sbs[2][2]);cout<<sb[2][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[2][3];clr(1);cout<<" | ";clr(sb[2][4],sbs[2][4]);cout<<sb[2][4];clr(1);cout<<" | ";clr(sb[2][5],sbs[2][5]);cout<<sb[2][5];
			clr(2);cout<<" || ";clr(sb[2][6],sbs[2][6]);cout<<sb[2][6];clr(1);cout<<" | ";Color(240);cout<<sb[2][7];clr(1);cout<<" | ";clr(sb[2][8],sbs[2][8]);cout<<sb[2][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t3. || ";Clr(sbs[2][0]);cout<<sbs[2][0];clr(1);cout<<" | ";Clr(sbs[2][1]);cout<<sbs[2][1];clr(1);cout<<" | ";Clr(sbs[2][2]);cout<<sbs[2][2];
				clr(2);cout<<" || ";Color(240);cout<<sbs[2][3];clr(1);cout<<" | ";Clr(sbs[2][4]);cout<<sbs[2][4];clr(1);cout<<" | ";Clr(sbs[2][5]);cout<<sbs[2][5];
				clr(2);cout<<" || ";Clr(sbs[2][6]);cout<<sbs[2][6];clr(1);cout<<" | ";Color(240);cout<<sbs[2][7];clr(1);cout<<" | ";Clr(sbs[2][8]);cout<<sbs[2][8];clr(2);cout<<" ||\n";
			cout<<"\t   ||===|===|===||===|===|===||===|===|===||\t\t";
				cout<<"\t   ||===|===|===||===|===|===||===|===|===||\n";
			clr(2);cout<<"\t4. || ";Color(240);cout<<sb[3][0];clr(1);cout<<" | ";Color(240);cout<<sb[3][1];clr(1);cout<<" | ";clr(sb[3][2],sbs[3][2]);cout<<sb[3][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[3][3];clr(1);cout<<" | ";clr(sb[3][4],sbs[3][4]);cout<<sb[3][4];clr(1);cout<<" | ";Color(240);cout<<sb[3][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[3][6];clr(1);cout<<" | ";Color(240);cout<<sb[3][7];clr(1);cout<<" | ";Color(240);cout<<sb[3][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t4. || ";Color(240);cout<<sbs[3][0];clr(1);cout<<" | ";Color(240);cout<<sbs[3][1];clr(1);cout<<" | ";Clr(sbs[3][2]);cout<<sbs[3][2];
				clr(2);cout<<" || ";Color(240);cout<<sbs[3][3];clr(1);cout<<" | ";Clr(sbs[3][4]);cout<<sbs[3][4];clr(1);cout<<" | ";Color(240);cout<<sbs[3][5];
				clr(2);cout<<" || ";Color(240);cout<<sbs[3][6];clr(1);cout<<" | ";Color(240);cout<<sbs[3][7];clr(1);cout<<" | ";Color(240);cout<<sbs[3][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\t\t";
				Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			clr(2);cout<<"\t5. || ";clr(sb[4][0],sbs[4][0]);cout<<sb[4][0];clr(1);cout<<" | ";clr(sb[4][1],sbs[4][1]);cout<<sb[4][1];clr(1);cout<<" | ";clr(sb[4][2],sbs[4][2]);cout<<sb[4][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[4][3];clr(1);cout<<" | ";clr(sb[4][4],sbs[4][4]);cout<<sb[4][4];clr(1);cout<<" | ";Color(240);cout<<sb[4][5];
			clr(2);cout<<" || ";clr(sb[4][6],sbs[4][6]);cout<<sb[4][6];clr(1);cout<<" | ";Color(240);cout<<sb[4][7];clr(1);cout<<" | ";clr(sb[4][8],sbs[4][8]);cout<<sb[4][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t5. || ";Clr(sbs[4][0]);cout<<sbs[4][0];clr(1);cout<<" | ";Clr(sbs[4][1]);cout<<sbs[4][1];clr(1);cout<<" | ";Clr(sbs[4][2]);cout<<sbs[4][2];
				clr(2);cout<<" || ";Color(240);cout<<sbs[4][3];clr(1);cout<<" | ";Clr(sbs[4][4]);cout<<sbs[4][4];clr(1);cout<<" | ";Color(240);cout<<sbs[4][5];
				clr(2);cout<<" || ";Clr(sbs[4][6]);cout<<sbs[4][6];clr(1);cout<<" | ";Color(240);cout<<sbs[4][7];clr(1);cout<<" | ";Clr(sbs[4][8]);cout<<sbs[4][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\t\t";
				Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			clr(2);cout<<"\t6. || ";Color(240);cout<<sb[5][0];clr(1);cout<<" | ";Color(240);cout<<sb[5][1];clr(1);cout<<" | ";Color(240);cout<<sb[5][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[5][3];clr(1);cout<<" | ";clr(sb[5][4],sbs[5][4]);cout<<sb[5][4];clr(1);cout<<" | ";Color(240);cout<<sb[5][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[5][6];clr(1);cout<<" | ";clr(sb[5][7],sbs[5][7]);cout<<sb[5][7];clr(1);cout<<" | ";Color(240);cout<<sb[5][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t6. || ";Color(240);cout<<sbs[5][0];clr(1);cout<<" | ";Color(240);cout<<sbs[5][1];clr(1);cout<<" | ";Color(240);cout<<sbs[5][2];
				clr(2);cout<<" || ";Color(240);cout<<sbs[5][3];clr(1);cout<<" | ";Clr(sbs[5][4]);cout<<sbs[5][4];clr(1);cout<<" | ";Color(240);cout<<sbs[5][5];
				clr(2);cout<<" || ";Color(240);cout<<sbs[5][6];clr(1);cout<<" | ";Clr(sbs[5][7]);cout<<sbs[5][7];clr(1);cout<<" | ";Color(240);cout<<sbs[5][8];clr(2);cout<<" ||\n";
			cout<<"\t   ||===|===|===||===|===|===||===|===|===||\t\t";
				cout<<"\t   ||===|===|===||===|===|===||===|===|===||\n";
			clr(2);cout<<"\t7. || ";clr(sb[6][0],sbs[6][0]);cout<<sb[6][0];clr(1);cout<<" | ";Color(240);cout<<sb[6][1];clr(1);cout<<" | ";Color(240);cout<<sb[6][2];
			clr(2);cout<<" || ";clr(sb[6][3],sbs[6][3]);cout<<sb[6][3];clr(1);cout<<" | ";clr(sb[6][4],sbs[6][4]);cout<<sb[6][4];clr(1);cout<<" | ";clr(sb[6][5],sbs[6][5]);cout<<sb[6][5];
			clr(2);cout<<" || ";clr(sb[6][6],sbs[6][6]);cout<<sb[6][6];clr(1);cout<<" | ";Color(240);cout<<sb[6][7];clr(1);cout<<" | ";Color(240);cout<<sb[6][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t7. || ";Clr(sbs[6][0]);cout<<sbs[6][0];clr(1);cout<<" | ";Color(240);cout<<sbs[6][1];clr(1);cout<<" | ";Color(240);cout<<sbs[6][2];
				clr(2);cout<<" || ";Clr(sbs[6][3]);cout<<sbs[6][3];clr(1);cout<<" | ";Clr(sbs[6][4]);cout<<sbs[6][4];clr(1);cout<<" | ";Clr(sbs[6][5]);cout<<sbs[6][5];
				clr(2);cout<<" || ";Clr(sbs[6][6]);cout<<sbs[6][6];clr(1);cout<<" | ";Color(240);cout<<sbs[6][7];clr(1);cout<<" | ";Color(240);cout<<sbs[6][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\t\t";
				Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			clr(2);cout<<"\t8. || ";Color(240);cout<<sb[7][0];clr(1);cout<<" | ";clr(sb[7][1],sbs[7][1]);cout<<sb[7][1];clr(1);cout<<" | ";clr(sb[7][2],sbs[7][2]);cout<<sb[7][2];
			clr(2);cout<<" || ";clr(sb[7][3],sbs[7][3]);cout<<sb[7][3];clr(1);cout<<" | ";Color(240);cout<<sb[7][4];clr(1);cout<<" | ";clr(sb[7][5],sbs[7][5]);cout<<sb[7][5];
			clr(2);cout<<" || ";clr(sb[7][6],sbs[7][6]);cout<<sb[7][6];clr(1);cout<<" | ";clr(sb[7][7],sbs[7][7]);cout<<sb[7][7];clr(1);cout<<" | ";clr(sb[7][8],sbs[7][8]);cout<<sb[7][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t8. || ";Color(240);cout<<sbs[7][0];clr(1);cout<<" | ";Clr(sbs[7][1]);cout<<sbs[7][1];clr(1);cout<<" | ";Clr(sbs[7][2]);cout<<sbs[7][2];
				clr(2);cout<<" || ";Clr(sbs[7][3]);cout<<sbs[7][3];clr(1);cout<<" | ";Color(240);cout<<sbs[7][4];clr(1);cout<<" | ";Clr(sbs[7][5]);cout<<sbs[7][5];
				clr(2);cout<<" || ";Clr(sbs[7][6]);cout<<sbs[7][6];clr(1);cout<<" | ";Clr(sbs[7][7]);cout<<sbs[7][7];clr(1);cout<<" | ";Clr(sbs[7][8]);cout<<sbs[7][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\t\t";
				Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			clr(2);cout<<"\t9. || ";clr(sb[8][0],sbs[8][0]);cout<<sb[8][0];clr(1);cout<<" | ";clr(sb[8][1],sbs[8][1]);cout<<sb[8][1];clr(1);cout<<" | ";clr(sb[8][2],sbs[8][2]);cout<<sb[8][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[8][3];clr(1);cout<<" | ";clr(sb[8][4],sbs[8][4]);cout<<sb[8][4];clr(1);cout<<" | ";clr(sb[8][5],sbs[8][5]);cout<<sb[8][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[8][6];clr(1);cout<<" | ";clr(sb[8][7],sbs[8][7]);cout<<sb[8][7];clr(1);cout<<" | ";Color(240);cout<<sb[8][8];clr(2);cout<<" ||\t\t";
				clr(2);cout<<"\t9. || ";Clr(sbs[8][0]);cout<<sbs[8][0];clr(1);cout<<" | ";Clr(sbs[8][1]);cout<<sbs[8][1];clr(1);cout<<" | ";Clr(sbs[8][2]);cout<<sbs[8][2];
				clr(2);cout<<" || ";Color(240);cout<<sbs[8][3];clr(1);cout<<" | ";Clr(sbs[8][4]);cout<<sbs[8][4];clr(1);cout<<" | ";Clr(sbs[8][5]);cout<<sbs[8][5];
				clr(2);cout<<" || ";Color(240);cout<<sbs[8][6];clr(1);cout<<" | ";Clr(sbs[8][7]);cout<<sbs[8][7];clr(1);cout<<" | ";Color(240);cout<<sbs[8][8];clr(2);cout<<" ||\n";
			cout<<"\t   =========================================\t\t";
				cout<<"\t   =========================================\n";	
		}
		else{
			cout<<"Congratulations, You won the game!\n\n";
			clr(2);cout<<"\t      1   2   3    4   5   6    7   8   9   \n";
			cout<<"\t   =========================================\n";
			clr(2);cout<<"\t1. || ";clr(sb[0][0],sbs[0][0]);cout<<sb[0][0];clr(1);cout<<" | ";Color(240);cout<<sb[0][1];clr(1);cout<<" | ";Color(240);cout<<sb[0][2];
			clr(2);cout<<" || ";clr(sb[0][3],sbs[0][3]);cout<<sb[0][3];clr(1);cout<<" | ";Color(240);cout<<sb[0][4];clr(1);cout<<" | ";clr(sb[0][5],sbs[0][5]);cout<<sb[0][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[0][6];clr(1);cout<<" | ";clr(sb[0][7],sbs[0][7]);cout<<sb[0][7];clr(1);cout<<" | ";clr(sb[0][8],sbs[0][8]);cout<<sb[0][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			
			clr(2);cout<<"\t2. || ";Color(240);cout<<sb[1][0];clr(1);cout<<" | ";Color(240);cout<<sb[1][1];clr(1);cout<<" | ";clr(sb[1][2],sbs[1][2]);cout<<sb[1][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[1][3];clr(1);cout<<" | ";Color(240);cout<<sb[1][4];clr(1);cout<<" | ";clr(sb[1][5],sbs[1][5]);cout<<sb[1][5];
			clr(2);cout<<" || ";clr(sb[1][6],sbs[1][6]);cout<<sb[1][6];clr(1);cout<<" | ";clr(sb[1][7],sbs[1][7]);cout<<sb[1][7];clr(1);cout<<" | ";clr(sb[1][8],sbs[1][8]);cout<<sb[1][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			
			clr(2);cout<<"\t3. || ";clr(sb[2][0],sbs[2][0]);cout<<sb[2][0];clr(1);cout<<" | ";clr(sb[2][1],sbs[2][1]);cout<<sb[2][1];clr(1);cout<<" | ";clr(sb[2][2],sbs[2][2]);cout<<sb[2][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[2][3];clr(1);cout<<" | ";clr(sb[2][4],sbs[2][4]);cout<<sb[2][4];clr(1);cout<<" | ";clr(sb[2][5],sbs[2][5]);cout<<sb[2][5];
			clr(2);cout<<" || ";clr(sb[2][6],sbs[2][6]);cout<<sb[2][6];clr(1);cout<<" | ";Color(240);cout<<sb[2][7];clr(1);cout<<" | ";clr(sb[2][8],sbs[2][8]);cout<<sb[2][8];clr(2);cout<<" ||\n";
			cout<<"\t   ||===|===|===||===|===|===||===|===|===||\n";
			
			clr(2);cout<<"\t4. || ";Color(240);cout<<sb[3][0];clr(1);cout<<" | ";Color(240);cout<<sb[3][1];clr(1);cout<<" | ";clr(sb[3][2],sbs[3][2]);cout<<sb[3][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[3][3];clr(1);cout<<" | ";clr(sb[3][4],sbs[3][4]);cout<<sb[3][4];clr(1);cout<<" | ";Color(240);cout<<sb[3][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[3][6];clr(1);cout<<" | ";Color(240);cout<<sb[3][7];clr(1);cout<<" | ";Color(240);cout<<sb[3][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			
			clr(2);cout<<"\t5. || ";clr(sb[4][0],sbs[4][0]);cout<<sb[4][0];clr(1);cout<<" | ";clr(sb[4][1],sbs[4][1]);cout<<sb[4][1];clr(1);cout<<" | ";clr(sb[4][2],sbs[4][2]);cout<<sb[4][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[4][3];clr(1);cout<<" | ";clr(sb[4][4],sbs[4][4]);cout<<sb[4][4];clr(1);cout<<" | ";Color(240);cout<<sb[4][5];
			clr(2);cout<<" || ";clr(sb[4][6],sbs[4][6]);cout<<sb[4][6];clr(1);cout<<" | ";Color(240);cout<<sb[4][7];clr(1);cout<<" | ";clr(sb[4][8],sbs[4][8]);cout<<sb[4][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			
			clr(2);cout<<"\t6. || ";Color(240);cout<<sb[5][0];clr(1);cout<<" | ";Color(240);cout<<sb[5][1];clr(1);cout<<" | ";Color(240);cout<<sb[5][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[5][3];clr(1);cout<<" | ";clr(sb[5][4],sbs[5][4]);cout<<sb[5][4];clr(1);cout<<" | ";Color(240);cout<<sb[5][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[5][6];clr(1);cout<<" | ";clr(sb[5][7],sbs[5][7]);cout<<sb[5][7];clr(1);cout<<" | ";Color(240);cout<<sb[5][8];clr(2);cout<<" ||\n";
			cout<<"\t   ||===|===|===||===|===|===||===|===|===||\n";
			
			clr(2);cout<<"\t7. || ";clr(sb[6][0],sbs[6][0]);cout<<sb[6][0];clr(1);cout<<" | ";Color(240);cout<<sb[6][1];clr(1);cout<<" | ";Color(240);cout<<sb[6][2];
			clr(2);cout<<" || ";clr(sb[6][3],sbs[6][3]);cout<<sb[6][3];clr(1);cout<<" | ";clr(sb[6][4],sbs[6][4]);cout<<sb[6][4];clr(1);cout<<" | ";clr(sb[6][5],sbs[6][5]);cout<<sb[6][5];
			clr(2);cout<<" || ";clr(sb[6][6],sbs[6][6]);cout<<sb[6][6];clr(1);cout<<" | ";Color(240);cout<<sb[6][7];clr(1);cout<<" | ";Color(240);cout<<sb[6][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			
			clr(2);cout<<"\t8. || ";Color(240);cout<<sb[7][0];clr(1);cout<<" | ";clr(sb[7][1],sbs[7][1]);cout<<sb[7][1];clr(1);cout<<" | ";clr(sb[7][2],sbs[7][2]);cout<<sb[7][2];
			clr(2);cout<<" || ";clr(sb[7][3],sbs[7][3]);cout<<sb[7][3];clr(1);cout<<" | ";Color(240);cout<<sb[7][4];clr(1);cout<<" | ";clr(sb[7][5],sbs[7][5]);cout<<sb[7][5];
			clr(2);cout<<" || ";clr(sb[7][6],sbs[7][6]);cout<<sb[7][6];clr(1);cout<<" | ";clr(sb[7][7],sbs[7][7]);cout<<sb[7][7];clr(1);cout<<" | ";clr(sb[7][8],sbs[7][8]);cout<<sb[7][8];clr(2);cout<<" ||\n";
			Color(240); cout<<"\t   ||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---"; Color(240); cout<<"||"; Color(247); cout<<"---|---|---";Color(240); cout<<"||\n";
			
			clr(2);cout<<"\t9. || ";clr(sb[8][0],sbs[8][0]);cout<<sb[8][0];clr(1);cout<<" | ";clr(sb[8][1],sbs[8][1]);cout<<sb[8][1];clr(1);cout<<" | ";clr(sb[8][2],sbs[8][2]);cout<<sb[8][2];
			clr(2);cout<<" || ";Color(240);cout<<sb[8][3];clr(1);cout<<" | ";clr(sb[8][4],sbs[8][4]);cout<<sb[8][4];clr(1);cout<<" | ";clr(sb[8][5],sbs[8][5]);cout<<sb[8][5];
			clr(2);cout<<" || ";Color(240);cout<<sb[8][6];clr(1);cout<<" | ";clr(sb[8][7],sbs[8][7]);cout<<sb[8][7];clr(1);cout<<" | ";Color(240);cout<<sb[8][8];clr(2);cout<<" ||\n";
			cout<<"\t   =========================================\n";
		}
		system("pause");	
}
						//*****How_To Play*****
void rules(){
	system("cls");
	cout<<"----------------------------SUDOKU-----------------------------\n";
	cout<<"                             HELP                              \n";
	cout<<"---------------------------------------------------------------\n\n";
	cout<<"                   Press 1 to start the game                   \n";
	cout<<"          It will prompt to difficulty level screen.           \n";
	cout<<"                         Select Level!                         \n";
	cout<<"                  Easy means 6x6 Sudoku Board                  \n";
	cout<<"                              and                              \n";
	cout<<"                  Hard means 9x9 Sudoku Board                  \n\n";
	cout<<"       Sudoku is played on a grid of 9x9 or 6x6 spaces.        \n";
	cout<<"       Within the rows and columns are 9 or 6 \"squares\"      \n";
	cout<<"       made up of 3x3 or 2x3 spaces depending on level.        \n";
	cout<<"       Each row, column and square (9 or 6 spaces each)        \n";
	cout<<"      needs to be filled out with the numbers 1-9 or 1-6       \n";
	cout<<"without repeating any numbers within the row, column or square.\n";
	cout<<"                         Best of Luck!                         \n\n";
	cout<<"---------------------------------------------------------------\n\n";
}

void developer(){
	system("cls");
	system("Color 70");
	cout<<"\t  __________     __________     ___________    ___________      ___        ___________      \n";
	cout<<"\t |          >   |          >   <           >  |           |    /   \\      |           |     \n";
	cout<<"\t |   .---.   |  |   .---.   |  |   .---.   |  '---.   .---'   /  _  \\     |   .-------'     \n";
	cout<<"\t |   |   |   |  |   |   |   |  |   |   |   |      |   |      /  / \\  \\    |   |             \n";
	cout<<"\t |   '---'   |  |   '---'   |  |   |   |   |      |   |     /  /   \\  \\   |   |   _______  \n";
	cout<<"\t |   .______>   |       ___>   |   |   |   |      |   |    /   '---'   \\  |   |  |       |  \n";
	cout<<"\t |   |          |   .   \\      |   |   |   |      |   |    /           \\  |   |  '---.   |  \n";
	cout<<"\t |   |          |   |\\   \\     |   |   |   |      |   |    |   .---.   |  |   |      |   |  \n";
	cout<<"\t |   |          |   | \\   \\    |   '---'   |      |   |    |   |   |   |  |   '------'   |  \n";
	cout<<"\t :___:          :___:  \\___;   <___________>      :___:    |___|   |___|  |______________>  \n";
	
	cout<<"\t  ___________    ______        ___    ___    ___________    ___________    ___________  \n";
	cout<<"\t <           >  |      \\      |   |  |   |  <           |  |           |  <           | \n";
	cout<<"\t |   .---.   |  |       \\     |   |  |   |  |   .-------'  '---.   .---'  |   .-------' \n";
	cout<<"\t |   |   |   |  |   '\\   \\    |   |  |   |  |   |              |   |      |   |         \n";
	cout<<"\t |   |   |   |  |   | \\   \\   |   |  |   |  |   '-------.      |   |      |   '-------. \n";
	cout<<"\t |   |   |   |  |   |  \\   \\  |   |  |   |  |           |      |   |      |           | \n";
	cout<<"\t |   |   |   |  |   |   \\   \\ |   |  |   |  '-------.   |      |   |      '-------.   | \n";
	cout<<"\t |   |   |   |  |   |    \\   `;   |  |   |          |   |      |   |              |   | \n";
	cout<<"\t |   '---'   |  |   |     \\       |  |   |  .-------'   |      |   |      .-------'   | \n";
	cout<<"\t <___________>  |___|      \\______|  |___|  |___________>      :___:      |___________> \n";
	cout<<"\n\n\t\t\t\t   *************Developers************\n";
	cout<<"\t\t\t\t   Abdullah Faisal\t   F2021376111\n";
	cout<<"\t\t\t\t   Muhammad Haseeb\t   F2021376117\n";
	cout<<"\t\t\t\t   ***********************************";
	cout<<"\n\n\t\t\t\t   **************Recources************\n";
	cout<<"\n\t\t\t\t     Instructer:";Color(114);cout<<" Sir Naveed Hussain\n\n";
	Color(112);
	cout<<"\t\t\t\t   w3schools.com\n";
	cout<<"\t\t\t\t   cplusplus.com\n";
	cout<<"\t\t\t\t   javatpoint.com/cpp-tutorial\n";
	cout<<"\t\t\t\t   geeksforgeeks.org\n";
	cout<<"\t\t\t\t\t\t  Brain\n";
	cout<<"\t\t\t\t   ***********************************\n";
	Color(120);
	cout<<"\t\t\t\t  /*1st Semester Final Project from Y9*/\n";
	getch();
}

void exit(){
	system("Color 07");
	system("cls");
	cout<<"||||||||  ||||||||  ||||||||  ||||||\\ \n";
	cout<<"||        ||    ||  ||    ||  ||    || \n";
	cout<<"|| |||||  ||    ||  ||    ||  ||    || \n";
	cout<<"||    ||  ||    ||  ||    ||  ||    || \n";
	cout<<"||||||||  ||||||||  ||||||||  ||||||/ \n";
	cout<<endl;
	cout<<"     ||||||\\   ||    ||  ||||||||\n";
	cout<<"     ||    ||   ||  ||   ||      \n";
	cout<<"     ||||||*     ||||    ||||||| \n";
	cout<<"     ||    ||     ||     ||      \n";
	cout<<"     ||||||/      ||     ||||||||\n";
}
