#include <iostream>
#include <ncurses.h>
#include <curses.h>
#include <menu.h>
#include <thread>
using namespace std;



char const *choices[] = {
                        "Hello World Program",
                        "Choice 2",
                        "Choice 3",
                        "Choice 4",
												"Choice 5",
												"Choice 6",
												"Choice 7",
                        "Exit",
                  };

void selectionState(int selection)
{
	switch(selection)
	{
		case 7:
		
		break;
		case 0:
		cout << "Hello World!";
		break;
		default:

		break;
	}
}


int main()
{	
	bool close = false;
	initscr();
  noecho();
	raw();	
	keypad(stdscr, TRUE);
	start_color();
	mvprintw(1, 0, "Press <ENTER> to see the option selected");
	mvprintw(2, 0, "Up and Down arrow keys to naviage\n");

	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLACK, COLOR_WHITE);
	attron(COLOR_PAIR(1));
	
	int selection = 0;
	int selectionMax = 8;
	int selectionMin = 0;
	
	int key;
	do
	{
		
		if (close)
		{
			break;
		}
		if (key == 10)//enter key
		{
			close = true;
		}
		if (key == KEY_DOWN && selection < selectionMax-1)
		{
			selection++;
		}else if (key == KEY_UP && selection > selectionMin)
		{
			selection--;
		}
		for (int i = 0; i < 8; i++)
		{
			if (selection == i)
			{
				attron(COLOR_PAIR(2));
			}
			mvprintw(3+i, 0, choices[i]);
			attron(COLOR_PAIR(1));
		}
		
	}while (key = getch());
	attroff(COLOR_PAIR(1));
	
	refresh();			 
	endwin();

	selectionState(selection);
}
