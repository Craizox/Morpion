#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "check_win.h"
#include "board.h"

static int check_valid(char *buf)
{
    if (strlen(buf) != 2)
        return 0;
    if ((buf[0] < 'a' || buf[0] > 'c') && (buf[0] < 'A' || buf[0] > 'C'))
        return 0;
    if ((buf[1] < '0' || buf[1] > '2'))
        return 0;
    return 1;
}

static int ask_for_player(char **board, char player)
{
    print_board(board);
    if (player == 'o')
        printf("Turn of player 1: ");
    else
        printf("Turn of player 2: ");

    char *buf;
    scanf("%ms", &buf);

    if (!check_valid(buf))
    {
        printf("Not a valid case try again\n");
        return 0;
    }

    return put_char_in_board(board, player, buf);
}


int main(void)
{
    char **board = board_init();
    int turn_player = 0;
    int win_p1, full, win_p2;
    while (!(win_p2 = check_win(board, 'x')) && !(win_p1 = check_win(board, 'o')) && !(full = check_full_board(board)))
    {
        if (turn_player % 2 == 0)
        {
            if (ask_for_player(board, 'o'))
                turn_player++;
        }
        else
        {
            if (ask_for_player(board, 'x'))
                turn_player++;
        }

    }
    print_board(board);
    if (full)
        printf("Egality\n");
    if (win_p1)
        printf("Player 1 Won\n");
    if (win_p2)
        printf("Player 2 won\n");
    return 0;
}
