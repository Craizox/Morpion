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

static int ask_for_player(char **board, char player, char *name)
{
    print_board(board);
    if (player == 'o')
        printf("Turn of %s: ", name);
    else
        printf("Turn of %s: ", name);

    char *buf;
    scanf("%ms", &buf);

    if (!check_valid(buf))
    {
        printf("Not a valid case try again\n");
        return 0;
    }

    return put_char_in_board(board, player, buf);
}

static void ask_player_name(char **p1, char **p2)
{
    printf("Name of player 1: ");
    scanf("%ms", p1);

    printf("Name of player 2: ");
    scanf("%ms", p2);
}

int main(void)
{
    char **board = board_init();
    int turn_player = 0;
    char *player1;
    char *player2;
    ask_player_name(&player1, &player2);
    int win_p1, full, win_p2;
    while (!(win_p2 = check_win(board, 'x')) && !(win_p1 = check_win(board, 'o')) && !(full = check_full_board(board)))
    {
        if (turn_player % 2 == 0)
        {
            if (ask_for_player(board, 'o', player1))
                turn_player++;
        }
        else
        {
            if (ask_for_player(board, 'x', player2))
                turn_player++;
        }

    }
    print_board(board);
    if (full)
        printf("Egality\n");
    if (win_p1)
        printf("%s Won\n", player1);
    if (win_p2)
        printf("%s Won\n", player2);
    free_board(board);
    return 0;
}
