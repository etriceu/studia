#include <cstdlib>
#include <ctime>

#include "TicTacToe.hpp"

using namespace std;

int main()
{
	srand(time(NULL));
	TicTacToe ttt;
	ttt.start();
}
