#include <curses.h>
#include <unistd.h>

#define  LEFTEDGE    10
#define  RIGHTEDGE   30
#define  ROW         10

int
main(void)
{
    int  dir     = +1;
    int  pos     = LEFTEDGE;
    
    initscr();
    clear();
    while(1)
    {
        move(ROW,pos);
    	addstr("Hello");
    	move(LINES - 1, COLS - 1);
	    refresh();
	    sleep(1);
	    move(ROW,pos);
	    addstr("     ");
        pos += dir;
        if (pos >= RIGHTEDGE)
            {
                dir = -1;
            }
        if (pos <= LEFTEDGE)
            {
                dir = +1;
            }
    }
}
