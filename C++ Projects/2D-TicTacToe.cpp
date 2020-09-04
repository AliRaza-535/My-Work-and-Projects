#include<iostream>
using namespace std;
class TicTacToe
{
private:
	int board[3][3],turn;
public:
	TicTacToe()
	{
		turn=0;
		for(int i=0;i<3;i++)
			for(int j=0;j<3;j++)
				board[i][j]=0;
	}
	void changeTurn()
	{
		cout<<"Who wants to play first? player 1 or player 2? 1/2: ";
		cin>>turn;
	}
	void MakeAMove()
	{
		int r=0,c=0;
		while(true)
		{
			cout<<"\n where do you want to put "<<turn<<" ,give its coordinates (i,j): ";
			cin>>r>>c;
			if(r>=0 && r<=2 && c>=0 && c<=2)
			if(board[r][c]==0)
			{
				board[r][c]=turn;
				break;
			}
		}
	}
	bool IsWon()
	{
		int count=0;
		for(int i=0;i<3;i++)
		{
			count=0;
			for(int j=0;j<3;j++)
			{
				if(board[i][j]!=turn)
				{
					break;
				}
				else
					count++;
			}
			if(count==3)
			{
				//cout<<"\n player "<<turn<<" won the game ";
				return true;
				break;
			}
		}
		if(count!=3)
		for(int j=0;j<3;j++)
		{
			count=0;
			for(int i=0;i<3;i++)
			{
				if(board[i][j]!=turn)
				{
					break;
				}
				else
					count++;
			}
			if(count==3)
			{
				//cout<<"\n player "<<turn<<" won the game ";
				return true;
				break;
			}
		}
		if(count!=3)
		{
			for(int i=0;i<3;i++)
			{
				count=0;
				if(board[i][i]==turn)
				{
					count++;
				}
			}
			if(count==3)
			{
				//cout<<"\n player "<<turn<<" won"<<endl;
				return true;
			}
			else
			{
				int i=0;
				count=0;
				for(int j=2;j>=0;j--)
				{
					if(board[i][j]==turn)
					{
						count++;
					}
					i++;
				}
				if(count==3)
				{
					//cout<<"\n Player "<<turn<<" won the game";
					return true;
				}
			}
		}
		return false;
	}//IsWon is completed.

	bool IsDraw()
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(board[i][j]==0)
				return false;
			}
		}
		return true;
	}

	void SwitchTurn()
	{
		turn=3-turn;
	}

	void display()
	{
		int a=0;
		system("cls");
		cout<<"    0   "<<"1  "<<" 2  "<<endl;
		for(int i=0;i<3;i++)
		{
			cout<<"________________"<<endl;
			cout<<a;
			for(int j=0;j<3;j++)
			{
				cout<<" | "<<board[i][j];
			}
			a++;
			cout<<endl;
		}
		cout<<"________________"<<endl;
	}

	void play()
	{
		bool checkDraw=true;
		while(true)
		{
			display();
			MakeAMove();
			bool checkWon=true;
			checkWon=IsWon();
			if(checkWon==true)
			{
				cout<<"\n Player "<<turn<<" is won ";
				break;
			}
			else
			{
				checkDraw=IsDraw();
				if(checkDraw==true)
				{
					cout<<"\n The Game has been drawn ";
					break;
				}
				else
				{
					SwitchTurn();
				}
			}
		}
		
	}
};

int main()
{
	TicTacToe obj1;
	obj1.changeTurn();
	obj1.play();
	system("pause");
}