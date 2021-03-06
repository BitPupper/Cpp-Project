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
        char board[3][3];
        int turn, score;
		
	public:
		Game()//:::::Constructor::::://
		{
			name1="user";
			name2="computer";
			for(int i=0;i<3;i++)
			    for(int j=0;j<3;j++)
			    {
				    board[i][j]='-';
				}
			turn=0;
			row=col=-1;
			score=0;
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
				cout<<"Here are the rules:\nThe game starts with an empty 3x3 grid square, with two opposing players. \nPlayers take turns to place their mark on one of the empty cells.\nThe player to make 3 in a row (diagonal, vertical, norizontal) first, wins.\nThe program will ask players to input (x,y) coordinates of the slot they want to use."<<endl;
			}
	
			cout<<"By default, user is X and computer is O, and user goes first."<<endl<<"Would you like to change the player names? (y/n)";
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
			Sleep(2000);//I thought too much text at once is confusing for the player, so I put some time before the game actually starts
			cout<<endl<<endl<<endl;
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
			default:cout<<"Error: could not identify turn"<<endl;//this is to make it easier for me to know where a problem is occuring
			}
			printBoard();
		}
		//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//*****Prints the game board for every turn*****//
		void printBoard()
		{
			cout<<endl<<setw(22)<<" 0      1      2"<<endl;
			for(int j=0; j<3; j++)
			{
				cout<<j;
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
				board[row][col]='X';
				break;
			case 1:
				board[row][col]='O';
				break;
			default:cout<<"Error: could not overwrite board."<<endl;
			}
			turn++;
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//::::::::::::Checks for wins, returns boolean value:::::::::::://
		bool checkWin()
		{
		    for (int i=0; i<3; i++)
			{
				//Horizontal wins
                if (board[i][0]=='X' && board[i][1]=='X' && board[i][2]=='X')
                {
                	cout<<name1<<" wins!";
                	return true;
                }
                else if (board[i][0]=='O' && board[i][1]=='O' && board[i][2]=='O')
                {
                	cout<<name2<<" wins!";
                	return true;
				}
				
				//Vertical wins
                else if (board[0][i]=='X' && board[1][i]=='X' && board[2][i]=='X')
                {
                	cout<<name1<<" wins!";
                	return true;
				}
				else if (board[0][i]=='O' && board[1][i]=='O' && board[2][i]=='O')
				{
					cout<<name2<<" wins!";
                	return true;
				}
            }
               if(board[0][0]=='X'&&board[1][1]=='X'&&board[2][2]=='X')//diagonal, up left to bottom right
			    {
					cout<<name1<<" wins!";
					return true;
					
				}
				else if(board[0][0]=='O'&&board[1][1]=='O'&&board[2][2]=='O')//diagonal, up left to bottom right
			    {
					cout<<name2<<" wins!";
					return true;
					
				}
			    else if(board[0][2]=='X'&&board[1][1]=='X'&&board[2][0]=='X')//diagonal, up right to bottom left
			    {
			    	cout<<name1<<" wins!";
			    	return true;
			    }
			    else if(board[0][2]=='O'&&board[1][1]=='O'&&board[2][0]=='O')//diagonal, up right to bottom left
		        {
		        	cout<<name2<<" wins!";
					return true;
				}
				else if(fullboard()) //Tie
				{
					cout<<"Board full, no possible moves left. It's a tie!";
					return true;
				}
				else //Game is continued
				{
					return false;
				}
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//::::::::::::CPU, calls calc():::::::::::://
		void AI() // "AI"
		{
			//If an almost-win is not detected, put mark in random slot
			if(!calc())
			{
			    srand (time(NULL));
			    do{
			    row=rand() % 3 ;
			    col=rand() % 3 ;
		        }while(board[row][col]!='-');
			}
		}
		//::::::::::::::::::::::::::::::::::::::::::::::::::::::://
		
		//::::::::::::Checks almost-wins by the user, blocks it:::::::::::://
		bool calc()
		{
			
			for (int i=0; i<3; i++)
			{
				//horizontal check
				score=0;
				for(int j=0; j<3; j++)
				{
					if (board[i][j]=='X')
					score+=10;
				}
				
				if(score==20)
			    {
				    for(int k; k<3; k++)
				    {
				    	if(board[i][k]=='-')
				    	{
				    		row=i;
				    		col=k;
				    		return true;
						}
					}
			    }
			}
			    
			for (int i=0; i<3; i++)
			{
			    //vertical check
			    score=0;
			    for(int j=0; j<3; j++)
				{
					if (board[j][i]=='X')
					score+=10;
				}
				
				if(score==20)
			    {
				    for(int k=0; k<3; k++)
				    {
				    	if(board[k][i]=='-')
				    	{
				    		row=k;
				    		col=i;
				    		return true;
						}
					}
			    }
			}
			
			//diagonal check
			score=0;
			for(int x=0;x<3;x++)
			{
				if(board[x][x]=='-')
				{
					score+=10;
				}
			}
			if(score==20)
			{
				for(int x=0;x<3;x++)
			    {
			    	if(board[x][x]=='-')
			    	{
			    		row=x;
			    		col=x;
			    		return true;
					}
				}
				
			}
			
			
			score=0;
			for(int x=0;x<3;x++)
			{
				if(board[x][2-x]=='-')
				{
					score+=10;
				}
			}
			if(score==20)
			{
				for(int x=0;x<3;x++)
			    {
			    	if(board[x][2-x]=='-')
			    	{
			    		row=x;
			    		col=2-x;
			    		return true;
					}
				}
				
			}
			
			//if program could not detect an almost-win from player
			return false;
			
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
    cout<<endl<<"Would you like to play again? (y/n): ";//allows player to do a rematch without restarting program
    cin>>ans;
    while(ans!='y'&&ans!='Y'&&ans!='n'&&ans!='N'){
    cout<<"Invalid response, please enter (y)es or (n)o: ";
    cin>>ans;
    }
    }while(ans=='y'||ans=='Y');
	return 0;
}
