
#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class TicTacToe
{
	private:

		char Board[3][3], playerAsymbol='\0',playerBsymbol='\0';
	public:

	 	TicTacToe()	       // Constructor
		{
			clearBoard();
		}
		//  TicTacToe ::  void clearBoard()  is an ERROR  "expected unidentified id before 'void '"


		void  clearBoard()   // To clear the Board
		{
			for( int i =0; i<3 ;i++)
			{
				for( int j =0; j<3 ; j++)
				{
					Board[i][j] = ' ';
				}
			}

		}

		void  printBoard()   // To print Board
		{

    		cout<<"----------------\n";
    		cout<<"|  ";

//			----------------
//			|  | 1 | 2 | 3 |	//First Row
//			----------------
//			|1 |   |   |   |	//Second Row
//			----------------
//			|2 |   |   |   |	//Third Row
//			----------------
//			|3 |   |   |   |	//Forth Row
//			----------------
//
			for(int i=0; i<3 ; i++ )
    	     	cout<<"| "<<i+1<<" ";   // first Row Completed
    		cout<<"|\n----------------\n";

			for(int i=0; i<3 ; i++ )
    		{
    			cout<< "|" << i+1 << " | "<< Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2] << " |";
    			cout<<"\n----------------\n";
    		}
		}

		int getXCoord()
		{
			int x;
			againx:

			cout<<"\nEnter the  X Co-Ordinate :" ;
			cin >> x;

			if(x<0 || x>3)      // if x is less than 1 whose ASCII Val  = 49
			{
			   cout<<"\n ********* Enter valid X Co ordinate *********";
			   goto againx;
			}
			else
				return (x-1);   // because this char x will store in the array starts from 0
	    }

		int getYCoord()
		{
			int y;
		againy:

			cout<<"\nEnter the  Y Co-Ordinate :" ;
			cin >>y;

			if(y<0 || y>3)	    // if y is less than 1 whose ASCII Val  = 51
			{
				cout<<"\n ********* Enter valid y Co ordinate *********";
		 	    goto againy;
		 	}
			else
				return (y-1);   // because this char y will store in the array starts from 0
	    }

 		bool play()
		{
			char playerAname[20] , playerBname[20];
			cout<<"\n\n*****************************************************************************";
			cout<<"\n*************************** Hello and Welcome !!! ***************************";
			cout<<"\n******************** This is a Tic Tac Toe Game for You..********************";
			cout<<"\n*****************************************************************************\n";


	        cout<<endl<<"Enter the Player 1 Good Name : ";                  // Taking Player A NAME
	        fflush(stdin);
	        gets(playerAname);
	        puts(playerAname);
  	        cout<<"\t... Please Enter 1 Your symbol : "; // Taking Player A SYMBOL
	        fflush(stdin);
	        playerAsymbol = getchar();

            cout<<endl<<"Enter the Player 2 Good Name : ";                  // Taking Player A NAME
	        fflush(stdin);
	        gets(playerBname);
	        puts(playerBname);
  	        cout<<"\t... Please Enter 2 Your symbol : "; // Taking Player A SYMBOL
	        fflush(stdin);
	        playerBsymbol = getchar();

            cout<<endl<<playerAname<<" chose : "<<playerAsymbol;
            cout<<endl<<playerBname<<" chose : "<<playerBsymbol;

 			return true;
		}


};

int main()
{
	bool playerMood = false;
	do
	{
		TicTacToe game;
		game.play();

		fflush(stdin);
		cout<<"\nDo You wanna Play Again ... Press 1 --> Yes or Press 0 --> No  : ";
		cin>>playerMood;

		if( playerMood != 1 && playerMood != 0)
		{
			cout<<"\n****************************** Invalid Option ******************************\n";
			cout<<"\n****************************** Press Any Key  ******************************\n";
			getch();
			exit(1);
		}

	}while( playerMood != false );
	cout<<"\n******************************** Game Ended ********************************\n";
	return 1;
}
