#include <iostream>
#include <windows.h>
using namespace std;
class TicTacToe
{
	private:
	int board[4][4][4];
	int turn;
	public:
	TicTacToe()
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<4;k++)
				{
					board[i][j][k]==0;
				}
			}
		}
	}
	void Style(int& i, int& j, int& k)
	{
		if(board[i][j][k]!=4 && board[i][j][k]!=5)
		{
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
			cout<<"  ";
			board[i][j][k]=0;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),7);
			cout<<board[i][j][k];
		}
		else
		{
			if(board[i][j][k]==4)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
				cout<<" ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),175);
				cout<<" 1";
			}
			else if(board[i][j][k]==5)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),0);
				cout<<" ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
				cout<<" 2";
			}
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
		}
	}
	void Display()
	{
		int i,j,k;
		cout<<"  i=0                i=1                i=2                i=3\n";
		cout<<"  j,k=0-3            j,k=0-3            j,k=0-3            j,k=0-3\n\n\n";
		for(i=0;i<4;i++)
		{
			j=0;
			for(k=0;k<4;k++)
			{
				Style(i,j,k);
			}
			cout<<"       ";
		}
		cout<<"\n\n";
		for(i=0;i<4;i++)
		{
			j=1;
			for(k=0;k<4;k++)
			{
				Style(i,j,k);
			}
			cout<<"       ";
		}
		cout<<"\n\n";
		for(i=0;i<4;i++)
		{
			j=2;
			for(k=0;k<4;k++)
			{
				Style(i,j,k);
			}
			cout<<"       ";
		}
		cout<<"\n\n";
		for(i=0;i<4;i++)
		{
			j=3;
			for(k=0;k<4;k++)
			{
				Style(i,j,k);
			}
			cout<<"       ";
		}
	}
	void makeAmove()
	{	bool DoAgain=true;
		while(DoAgain)
		{
			cout<<"\n\n\n\tPlayer 1 : ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),175);
			cout<<" 1";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"\t\tPlayer 2 : ";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
			cout<<" 2";
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			cout<<"\n\n\nPlayer "<<turn-3<<" will enter (i,j,k) :\t";
			int r,s,t;
			cout<<"i = ";
			cin>>r;
			if(r>-1 && r<4)
			{
				cout<<"\t\t\t\tj = ";
				cin>>s;
				if(s>-1 && s<4)
				{
					cout<<"\t\t\t\tk = ";
					cin>>t;
					if(t>-1 && t<4)
					{
						if(board[r][s][t]!=4 && board[r][s][t]!=5)
						{
							board[r][s][t]=turn;
							cout<<"\n\n\tValue has been entered successfully...!\n\n";
							break;
						}
						else
						{
							system("cls");
							Display();
							cout<<"\n\n\n\n\tThis Place Is Not Available, Try Again\n\n";
							DoAgain=true;	
						}
					}
					else
					{
						system("cls");
						Display();
					cout<<"\n\n\n\n\tYou entered a wrong number, Try Again\n\n";
					DoAgain=true;	
					}
				}
				else
				{
					system("cls");
					Display();
					cout<<"\n\n\n\n\tYou entered a wrong number, Try Again\n\n";
					DoAgain=true;	
				}
			}
			else
			{
				system("cls");
				Display();
				cout<<"\n\n\n\n\tYou entered a wrong number, Try Again\n\n";
				DoAgain=true;	
			}
		}
	}
	bool IsWon() 
	{ for(int i=0;i<4;i++)
		for( int j=0;j<4;j++)
		{
			if(board[0][i][j]==turn && board[1][i][j]==turn && board[2][i][j]==turn && board[3][i][j]==turn)
			{
			return true;
			}
		    if(board[i][0][j]==turn && board[i][1][j]==turn && board[i][2][j]==turn && board[i][3][j]==turn)
			{
			return true;
			}
		    if(board[i][j][0]==turn && board[i][j][1]==turn && board[i][j][2]==turn && board[i][j][3]==turn)
			{
			return true;
			}
	  	}
		for(int j=0;j<4;j++)
		{
			if(board[j][0][0]==turn && board[j][1][1]==turn && board[j][2][2]==turn && board[j][3][3]==turn)
			{
			return true;
			}
			if(board[0][j][0]==turn && board[1][j][1]==turn && board[2][j][2]==turn && board[3][j][3]==turn)
			{
			return true;
			}
			if(board[0][0][j]==turn && board[1][1][j]==turn && board[2][2][j]==turn && board[3][3][j]==turn)
			{
			return true;
			}
			if(board[j][0][3]==turn && board[j][1][2]==turn && board[j][2][1]==turn && board[j][3][0]==turn)
			{
			return true;
			}
			if(board[0][j][3]==turn && board[1][j][2]==turn && board[2][j][1]==turn && board[3][j][0]==turn)
			{
			return true;
			}
			if(board[0][3][j]==turn && board[1][2][j]==turn && board[2][1][j]==turn && board[3][0][j]==turn)
			{
			return true;
			}
		}
		if(board[3][0][3]==turn && board[2][1][2]==turn && board[1][2][1]==turn && board[0][3][0]==turn)
		{
			return true;
		}
		if(board[0][0][3]==turn &&  board[1][1][2]==turn && board[2][2][1]==turn && board[3][3][0]==turn)
		{
			return true;
		}
		if(board[3][0][0]==turn && board[2][1][1]==turn && board[1][2][2]==turn && board[0][3][3]==turn)
		{
			return true;
		}
		if(board[0][0][0]==turn && board[1][1][1]==turn && board[2][2][2]==turn && board[3][3][3]==turn)
		{
			return true;
		}
	return false;
	}
	bool IsDraw()
	{
		for(int i=0;i<4;i++)
		{
			for(int j=0;j<4;j++)
			{
				for(int k=0;k<4;k++)
				{
					if(board[i][j][k]==0)
					{
						return false;
					}
				}
			}
		}
		return true;
	}
	void SwitchTurn()
	{
		turn=9-turn;
	}
	void Play()
	{
		cout<<" ############################################################################\n\n";
		cout<<" :::::::: :: ::::::::  :::::::: :::::::: ::::::::  :::::::: :::::::: ::::::::\n";
		cout<<"    ::    :: ::    ::     ::    ::    :: ::    ::     ::    ::    :: ::\n";
		cout<<"    ::    :: ::           ::    :::::::: ::           ::    ::    :: ::::::::\n";
		cout<<"    ::    :: ::    ::     ::    ::    :: ::    ::     ::    ::    :: ::\n";
		cout<<"    ::    :: ::::::::     ::    ::    :: ::::::::     ::    :::::::: ::::::::\n\n";
		cout<<" ############################################################################\n\n\n";
		cout<<"Who Want to Play First ?\nPlayer 1 OR Player 2 ?\nEnter  1 OR 2 : ";
		int e;
		cin>>e;
		turn=e+3;
		while(1)
		{
			system("cls");
			Display();
			makeAmove();
			if(IsWon())
			{
				system("cls");
				Display();
				cout<<"\n\n\tPlayer 1 : ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),175);
				cout<<" 1";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				cout<<"\t\tPlayer 2 : ";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),240);
				cout<<" 2";
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				cout<<"\n\n\n\t\t\t........Congratulations........\n\n";
				cout<<"\t\t\tPlayer "<<turn-3<<" Has Won The Match....!\n\n\n\n";
				break;
			}
			else if(IsDraw())
			{
				cout<<"Game is Draw...!";
				break;
			}
			SwitchTurn();
		}		
	}
};
int main()
{
	TicTacToe obj;
	obj.Play();
	return 0;
}
