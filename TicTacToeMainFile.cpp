// FINAL VERSION //

#include <iostream>
#include <conio.h>
#include <string.h>
using namespace std;

class TicTacToe
{
	private:

		char Board[3][3], playerAsymbol='\0',playerBsymbol='\0';
		char playerAname[20] , playerBname[20];
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

    		cout<<"\t\t\t----------------\n";
    		cout<<"\t\t\t|  ";

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
    		cout<<"|\n\t\t\t----------------\n\t\t\t";

			for(int i=0; i<3 ; i++ )
    		{
    			cout<< "|" << i+1 << " | "<< Board[i][0] << " | " << Board[i][1] << " | " << Board[i][2] << " |";
    			cout<<"\n\t\t\t----------------\n\t\t\t";
    		}
		}


        char checkVictory()
        {

                for(int i=0;i<3;i++)
                {
                   // ROWS CHECKED //
                   if(( Board[i][0] == Board[i][1]) && (Board[i][1] == Board[i][2]) )
                   {
                        if(Board[i][0] != ' ')
                        {
                            printBoard();
                            cout<<"\n*************************** "<< i+1 <<"th ROW MATCHED ***************************\n";
                            return (Board[i][0]);   // THIS CHARACTER WON //
                        }
                   }
                }
                // columns checked //
                for(int j=0;j<3;j++)
                {
                    // ROWS CHECKED //
                   if(( Board[0][j] == Board[1][j]) && (Board[1][j] == Board[2][j]) )
                   {
                        if(Board[0][j] != ' ')
                        {
                            printBoard();
                            cout<<"\n************************* "<< j+1 <<"th COLUMN MATCHED ************************\n";
                            return (Board[0][j]);   // THIS CHARACTER WON //
                        }
                   }
                }

                if( (Board[0][0] == Board[1][1]) && (Board[1][1] == Board[2][2] ) && Board[2][2] != ' ')    // left diagonal
                {
                       printBoard();
                       cout<<"\n************************ LEFT DIAGONAL MATCHED ***********************\n";
                       return (Board[0][0]);
                }

                if( Board[0][2] == Board[1][1] && (Board[1][1] == Board[2][0]) && Board[1][1] !=' ' )       // right diagonal
                {
                       printBoard();
                       cout<<"\n************************ RIGHT DIAGONAL MATCHED *********************\n";
                       return (Board[0][2]);
                }
                else
                    return ('\0');

            // to UNDERSTAND THIS FUNCTIONS ' FUNCTIONALITY    JUST DRAW A BOARD[3][3] ON PAPER
        }
        char takeValidCoordsPutOnBoard(int turnCounter)
        {
           if(turnCounter%2 != 0)
           {
               char retValFromVictoryFunc='s';

                cout<<endl<<"\n*************************** PLAYER 1 *******************************\n";
                short int x,y,flag = 0;   // CO ORDINATES //
                do
                {
                    printBoard();
                    cout<<endl<<playerAname<<" : Enter X-Co ordinate :-> ";
                    cin>>x;

                    cout<<endl<<playerAname<<" : Enter Y-Co ordinate :-> ";
                    cin>>y;

                    if( (x<1 || x>3 ) || (y<1 || y>3))
                    {
                        cout<<endl<<"\n************************ INVALID CO-ORDINATES *************************\n";
                        getch();
                        continue;
                    }
                    else
                    {
                        flag=1; // THIS DENOTES VALID CO-ORDINATES //
                    }

                    if( Board[x-1][y-1] != ' ')
                    {
                        cout<<endl<<"\n******************* THAT PLACE IS ALREADY OCCUPIED ********************\n";
                        getch();
                        continue;
                    }
                    else
                    {
                        flag=2;
                        Board[x-1][y-1] = playerAsymbol;
                        retValFromVictoryFunc = checkVictory();
                    }

                }while ( flag != 2 );
                return retValFromVictoryFunc;

           }    // IF BLOCK ENDED FOR 1st PALYER //

            else
            {
               char retValFromVictoryFunc='s';

                cout<<endl<<"\n*************************** PLAYER 2 *******************************\n";
                short int x,y,flag=0;   // CO ORDINATES //
                do
                {
                    printBoard();
                    cout<<endl<<playerBname<<" : Enter X-Co ordinate :-> ";
                    cin>>x;

                    cout<<endl<<playerBname<<" : Enter Y-Co ordinate :-> ";
                    cin>>y;

                    if( (x<1 || x>3 ) || (y<1 || y>3))
                    {
                        cout<<endl<<"\n************************ INVALID CO-ORDINATES *************************\n";
                        getch();
                        continue;
                    }
                    else
                    {
                        flag=1; // THIS DENOTES VALID CO-ORDINATES //
                    }

                    if( Board[x-1][y-1] != ' ')
                    {
                        cout<<endl<<"\n******************* THAT PLACE IS ALREADY OCCUPIED ********************\n";
                        getch();
                        continue;
                    }
                    else
                    {
                        flag=2;
                        Board[x-1][y-1] = playerBsymbol;
                        retValFromVictoryFunc = checkVictory();
                    }

                }while ( flag != 2 );
                return retValFromVictoryFunc;
           }
        }

 		bool play()
		{

			bool validSymbols = false;
			cout<<"\n\n*****************************************************************************";
			cout<<"\n*****************************************************************************";
			cout<<"\n*************************** Hello and Welcome !!! ***************************";
			cout<<"\n******************** This is a Tic Tac Toe Game for You..********************";
			cout<<"\n*****************************************************************************";
			cout<<"\n*****************************************************************************\n";


	        cout<<endl<<"Enter the Player 1 Good Name : ";                  // Taking Player A NAME
	        fflush(stdin);
	        gets(playerAname);

            cout<<endl<<"Enter the Player 2 Good Name : ";                  // Taking Player A NAME
	        fflush(stdin);
	        gets(playerBname);

	        short int flagForSym=0;
	        do          //******************************* input symbols .****************************";
            {

                cout<<endl<<playerAname<<" : Enter your Symbol :-> ";
                cin>>playerAsymbol;

                cout<<endl<<playerBname<<" : Enter your Symbol :-> ";
                cin>>playerBsymbol;

                if( playerAsymbol == playerBsymbol )
                {
                    cout<<"\n********************* Warning!!! Enter different symbols .****************************\n";

                }
                else { flagForSym=1; }

            }while ( flagForSym != 1 );

                cout<<"\n********************** Game is Going to start....****************************\n";

                short int turnCounter=0;
                char flagTillVictory = '\0'; // IT WILL CONT. SHOW THE VALIDITY OF ENTERED COORDS FOR EACH PLAYERS
                do
                {
                    if(++turnCounter < 10)
                    {
                        flagTillVictory  =  takeValidCoordsPutOnBoard (turnCounter);
                        cout<<"\n******************* Symbol Successfully Inserted ********************\n";
                    }
                    else
                    {
                        printBoard();
                        cout<<"\n\n*****************************************************************************";
                        cout<<"\n*************************** OOPs!!! Match Draw ******************************";
                        cout<<"\n*****************************************************************************";
                        getch();
                        return false;
                    }
                }while ( flagTillVictory == '\0' );

                if( flagTillVictory == playerAsymbol)
                {
                    cout<<"\n\n*************************************************************************************";
                    cout<<"\n************************* WOOH!!!"<<playerAname<<" Won The Match *************************";
                    cout<<"\n*************************************************************************************";
                    getch();
                }

                // changes can be done here //
                else if( flagTillVictory == playerBsymbol)
                {
                    cout<<"\n\n*************************************************************************************";
                    cout<<"\n************************* WOOH!!!"<<playerBname<<" Won The Match *************************";
                    cout<<"\n*************************************************************************************";
                    getch();
                }
                else
                {
                    cout<<"\n******************************** Something Went Wrong ************************************";
                    getch();
                }
                return true;
		}// play() ended
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

		if( playerMood == (bool)1 )
            playerMood = true;
        else
            playerMood = false;

	}while( playerMood != false );
	cout<<"\n******************************** Game Ended ********************************\n";
	return 1;
}
