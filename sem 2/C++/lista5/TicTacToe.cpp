#include <iostream>
#include <string>

#include <conio.h>

#include "TicTacToe.hpp"
#include "console.hpp"

using namespace std;

void TicTacToe::newGame()
{
	map = vector<char>(size*size, ' ');
	if(team == 'R')
		team = rand()%2 ? 'X' : 'O';

	cx = 0;
	cy = 0;
	turn = 'X';
}

int TicTacToe::miniMax(vector <char> map, char turn, clock_t time, int depth)
{
	if(time < clock() || depth > MAX_DEPTH)
		return 0;

	char win = checkWin(map);
	if(win != 0)
		return win == -1 ? 0 : turn == team ? 100 : -100;

	vector <int> tab(map.size());
	int min = -1, max = -1;
	for(int n = 0; n < size*size; n++)
		if(map[n] == ' ')
		{
			vector <char> tmp = map;
			tmp[n] = turn;
			int res = miniMax(tmp, turn == 'X' ? 'O' : 'X', time, depth+1);
			tab[n] = res;
			if(min == -1) min = n;
			if(max == -1) max = n;
			if(tab[min] > tab[n]) min = n;
			if(tab[max] < tab[n]) max = n;
		}

	int i = turn == team ? min : max;
	if(depth == 1)
		return i;
	return tab[i];
}

void TicTacToe::play()
{
	newGame();
	bool check = false;
	while(1)
	{
		display();
		if(!ai || turn == team)
		{
			char key = getch();
			if(key == LEFT && cx > 0) cx--;
			else if(key == RIGHT && cx < size-1) cx++;
			else if(key == UP && cy > 0) cy--;
			else if(key == DOWN && cy < size-1) cy++;
			else if(key == ENTER && map[cx+cy*size] == ' ')
			{
				map[cx+cy*size] = turn;
				check = true;
			}
		}
		else
		{
			map[miniMax(map, turn, clock()+CLOCKS_PER_SEC*MAX_TIME)] = turn;
			check = true;
		}

		if(check)
		{
			check = false;
			char res = checkWin(map);
			if(res)
			{
				display();
				setColor(res == -1 ? WHITE : res == 'X' ? RED : BLUE);
				if(res > 0) cout<<"Player "<<turn<<" wins!"<<endl;
				else cout<<"It's draw."<<endl;

				setColor(WHITE);
				cout<<"Do you want to play again? [y/n]";
				char key = getch();
				if(key == 'y' || key == ENTER)
				{
					team = team == 'X' ? 'O' : 'X';
					newGame();
				}
				else break;
			}
			else
				turn = turn == 'X' ? 'O' : 'X';
		}
	}
}

void TicTacToe::display()
{
	system("cls");
	setColor(turn == 'X' ? RED : BLUE);
	cout<<"Player: "<<turn<<endl;
	for(int y = 0; y < size*2-1; y++)
	{
		for(int x = 0; x < size*2-1; x++)
			if(y%2 || x%2)
			{
				setColor(WHITE);
				cout<<(char)(y%2 ? x%2 ? CHAR2 : CHAR3 : CHAR1);
			}
			else
			{
				char c = cx == x/2 && cy == y/2 ? BG_WHITE : BG_BLACK;
				c |= map[(x/2)+(y/2)*size] == 'X' ? RED : BLUE;
				setColor(c);
				cout<<map[(x/2)+(y/2)*size];
			}
		cout<<endl;
	}
	setColor(BLACK | BG_BLACK);
}

char TicTacToe::checkWin(vector <char> map)
{
	int empty = 0, xu = 0, ou = 0, xd = 0, od = 0;
	for(int y = 0; y < size; y++)
	{
		int xh = 0, oh = 0, xv = 0, ov = 0;
		for(int x = 0; x < size; x++)
		{
			if(map[x+y*size] == ' ') empty++;
			if(map[x+y*size] == 'X') xh++;
			else if(map[x+y*size] == 'O') oh++;
			if(map[y+x*size] == 'X') xv++;
			else if(map[y+x*size] == 'O') ov++;
		}

		if(map[y+y*size] == 'X') xd++;
		else if(map[y+y*size] == 'O') od++;
		if(map[(size-y-1)+y*size] == 'X') xu++;
		else if(map[(size-y-1)+y*size] == 'O') ou++;

		if(xh == size || xv == size || xd == size || xu == size)
			return 'X';
		else if(oh == size || ov == size || od == size || ou == size)
			return 'O';
	}
	return empty ? 0 : -1;
}

void TicTacToe::menu()
{
	string tab[] = {"Play", "", "", "Size: ", "Exit"};
	enum {PLAY, TEAM, VS, SIZE, EXIT};
	const int posMax = sizeof(tab)/sizeof(tab[0]);
	int pos = 0;

	while(1)
	{
		tab[VS] = ai ? "P vs AI" : "P vs P";
		tab[TEAM] = team == 'R' ? "Random" : team == 'X' ? "X" : "O";

		system("cls");
		setColor(RED);
		cout<<"Tic Tac Toe\n";
		setColor(BLUE);
		cout<<"----Menu----\n";

		for(int n = 0; n < posMax; n++)
		{
			setColor(pos == n ? MAGENTA : WHITE);
			cout<<(pos == n ? "* " : "  ")<<tab[n];
			if(n == SIZE) cout<<size;
				cout<<endl;
		}

		setColor(BLACK | BG_BLACK);
		char key = getch();
		if(key == DOWN && pos < posMax-1) pos++;
		else if(key == UP && pos > 0) pos--;
		else if(key == ENTER)
		{
			if(pos == PLAY) play();
			else if(pos == VS) ai = !ai;
			else if(pos == EXIT) break;
			else if(pos == TEAM)
				team = team == 'R' ? 'X' : team == 'X' ? 'O' : 'R';
		}
		else if(key == RIGHT && pos == SIZE) size++;
		else if(key == LEFT && pos == SIZE && size > 3) size--;
	}
}
