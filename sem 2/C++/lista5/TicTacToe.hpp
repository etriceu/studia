#include <vector>

class TicTacToe
{
	enum {UP = 72, DOWN = 80, LEFT = 75, RIGHT = 77, ENTER = 13};
public:
	void start()
	{
		menu();
	}
	
private:
	
	void newGame();
	int miniMax(std::vector <char> map, char turn, clock_t time, int depth = 1);
	void play();
	void display();
	char checkWin(std::vector <char> map);
	void menu();
	
	int size = 3;
	char team = 'R';
	bool ai = false;
	std::vector <char> map;
	int cx, cy;
	char turn;
	
	static constexpr int MAX_TIME = 10;
	static constexpr int MAX_DEPTH = 7;
};
