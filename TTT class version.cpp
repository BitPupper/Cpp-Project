#include <iostream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

using namespace std;

class Game
{
	private://:::::Variables::::://
		string name1, name2;
		int row, col;
		//int boardNum[3][3];
        char board[3][3];
        int turn;
		
	public:
		Game()//:::::Constructor::::://
		{
			name1="user";
			name2="computer";
			for(int i=0;i<3;i++)
			    for(int j=0;j<3;j++)
			    {
				    board[i][j]='-';
				    //boardNum[i][j]=0;
				}
			turn=0;
			row=col=-1;
		}
		
		//:::::Prints instructions if prompted, initializes all settings::::://
		void setup()
		{
			name1="user";
			name2="computer";
			for(int i=0;i<3;i++)
			    for(int j=0;j<3;j++)
			    {
				    board[i][j]='-';
				    //boardNum[i][j]=0;
				}
			turn=0;
			row=col=-1;
			char ans;
			cout<<"Hello! Welcome to Tic-Tac-Toe."<<endl<<"Do you wish for instructions?(y/n)";
			cin>>ans;
			while(ans!='y'&& ans!='Y'&& ans!='N'&& ans!='n')
			{
				cout<<"Sorry, I didn't understand that. Please enter y or n: ";
				cin>>ans;
			}
			if(ans=='y'||ans=='Y')
			{
				cout<<"Here are the rules:\nThe game starts with an empty 3x3 grid square, with two opposing players. User is O, the computer is X.\nPlayers take turns to place their mark on one of the empty cells.\nThe player to make 3 in a row (diagonal, vertical, norizontal) first, wins.\nThe program will ask players to input (x,y) coordinates of the slot they want to use."<<endl;
			}
	
			cout<<"By default, user is O and computer is X, and user goes first."<<endl<<"Would you like to change the player names? (y/n)";
			cin>>ans;
	
			while(ans!='y'&& ans!='Y'&& ans!='N'&& ans!='n')
			{
				cout<<"Sorry, I didn't understand that. Please enter y or n: ";
				cin>>ans;
			}
	        if(ans=='y'||ans=='Y')
			{
				cout<<"Enter user name: "<<endl;
				cin>>name1;
		
				cout<<"Enter the name for computer: "<<endl;
				cin>>name2;
			}

			cout<<endl<<"You're all set!";
			Sleep(2000);
			cout<<endl<<endl<<endl;
			//startGame();
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::://
        
		//:::::::::Prints whose turn it is, calls printBoard::::::::://
        void printTurn()
        {
        	switch(turn%2)
			{
			case 0:
			    cout<<endl<<name1<<"'s turn  "<<endl;
			    if(turn!=0)
			    	cout<<"last turn - "<<name2<<": "<<row<<","<<col<<endl;
				break;
			case 1:
				cout<<endl<<name2<<"'s turn  "<<endl;
				if(turn!=0)
			    	cout<<"last turn - "<<name1<<": "<<row<<","<<col<<endl;
				break;
			default:cout<<"Error: could not identify turn"<<endl;
			}
			printBoard();
		}
		//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//*****Prints the game board for every turn*****//
		void printBoard()
		{
			cout<<endl;
			for(int j=0; j<3; j++)
			{
				for(int i=0; i<3; i++)
				{
					cout<<setw(7)<<board[i][j];
				}
				cout<<endl<<endl;
			}
		}
		//::::::::::::::::::::::::::::::::::::::::::::://

		//:::::::::Gets input or runs AI, calls update function::::::::://
		void input()
		{
			if(turn%2==0)
			{
			cout<<"Enter the row number (x-coordnate): ";
			cin>>row;
			cout<<"Enter the column number (y-coordinate): ";
			cin>>col;
			while(row>2||row<0||col>2||col<0||board[row][col]!='-')
			{
				cout<<"You cannot use this slot. Please select an existing, unoccupied slot."<<endl;
                cout<<"Enter the row number: ";
			    cin>>row;
			    cout<<"Enter the column number: ";
			    cin>>col;
			}
		    }
		    else //AI
		    {
		    	AI();
			}
			update();
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//::::::::::::Updates boards based on input:::::::::::://
		void update()
		{
			switch(turn%2)
			{
			case 0:
				board[row][col]='O';
				//boardNum[row][col]=1;
				break;
			case 1:
				board[row][col]='X';
				//boardNum[row][col]=-1;
				break;
			default:cout<<"Error: could not overwrite board."<<endl;
			}
			turn++;
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//::::::::::::Checks for wins, returns boolean value:::::::::::://
		bool checkWin()
		{
			if(board[0][0]==board[1][1]&&board[1][1]==board[2][2])//diagonal, up left to bottom right
			{
				if(board[0][0]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[0][0]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(board[0][2]==board[1][1]&&board[1][1]==board[2][0])//diagonal, up right to bottom left
			{
					if(board[0][2]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[0][2]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(board[0][0]==board[1][0]&&board[1][0]==board[2][0])//vertical, left column
			{
					if(board[0][0]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[0][0]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(board[0][1]==board[1][1]&&board[1][1]==board[2][1])//vertical, middle column
			{
					if(board[0][1]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[0][1]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(board[0][2]==board[1][2]&&board[1][2]==board[2][2])//vertical, right column
			{
					if(board[0][2]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[0][2]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(board[0][0]==board[0][1]&&board[0][1]==board[0][2])//horizontal, first row
			{
					if(board[0][0]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[0][0]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(board[1][0]==board[1][1]&&board[1][1]==board[1][2])//horiontal, middle row
			{
					if(board[1][0]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[1][0]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(board[2][0]==board[2][1]&&board[2][1]==board[2][2])//horizontal, bottom row
			{
					if(board[2][0]=='O')
				{
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[2][0]=='X')
				{
					cout<<name2<<" wins!";
					return true;
				}
				else
				{
					return false;
				}
			}
			else if(fullboard()==true)
			{
				cout<<"No more slots left. It's a tie!";
				return true;
			}
			else{
				return false;
			}
		}
		
		void AI() // AI
		{
			srand (time(NULL));
			do{
			row=rand() % 3 ;
			col=rand() % 3 ;
		    }while(board[row][col]!='-');//places mark in random slot
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//::::::::::::Detects if there are no possible moves left:::::::::::://
		bool fullboard()
		{
			if(turn<9)
			{
				return false;
			}
			if(turn>=9)
			{
				return true;
			}
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
};


int main()
{
	Game TTT;
	char ans;
	do{
	
	TTT.setup();
	do{
		TTT.printTurn();
		TTT.input();
	}while(TTT.checkWin()==false&&TTT.fullboard()==false);
    TTT.printBoard();
    cout<<endl<<"Would you like to play again? (y/n): ";
    cin>>ans;
    while(ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N'){
    cout<<"Invalid response, please enter (y)es or (n)o: ";
    cin>>ans;
    }
    }while(ans=='y'||ans=='Y');
	return 0;
}

