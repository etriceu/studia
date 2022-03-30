#include <windows.h>

#define CHAR_SET 3

#if CHAR_SET == 1
	#define CHAR1 '│'
	#define CHAR2 '┼'
	#define CHAR3 '─'
#elif CHAR_SET == 2
	#define CHAR1 179
	#define CHAR2 197
	#define CHAR3 196
#else
	#define CHAR1 '|'
	#define CHAR2 '+'
	#define CHAR3 '-'
#endif

enum {	BLACK = 0, BLUE = 9, GREEN, CYAN, RED, MAGENTA, YELLOW, WHITE,
		BG_WHITE = 0x70, BG_BLACK = 0x00};

void setColor(char color)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, color);
}
