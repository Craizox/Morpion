#include "check_win.h"

static int check_line(char **board, char player)
{
    for (int i = 0; i < 3; i++)
    {
        int win = 0;
        for (int j = 0; j < 3 && board[i][j] == player; j++)
        {
            win++;
        }
        if (win == 3)
            return 1;
    }
    return 0;
}


static int check_col(char **board, char player)
{
    for (int i = 0; i < 3; i++)
    {
        int win = 0;
        for (int j = 0; j < 3 && board[j][i] == player; j++)
        {
            win++;
        }
        if (win == 3)
            return 1;
    }
    return 0;
}

static int check_ldiag(char **board, char player)
{
    int win = 0;
    for (int i = 0, j = 0; i < 3 && j < 3 && board[i][j] == player; j++, i++)
    {
        win ++;
    }
    if (win == 3)
        return 1;
    return 0;
}


static int check_rdiag(char **board, char player)
{
    int win = 0;
    for (int i = 2, j = 0; i >= 0 && j < 3 && board[i][j] == player; j++, i--)
    {
        win ++;
    }
    if (win == 3)
        return 1;
    return 0;
}

int check_win(char **board, char player)
{
    if (check_line(board, player))
        return 1;
    if (check_col(board, player))
        return 1;
    if (check_ldiag(board, player))
        return 1;
    if (check_rdiag(board, player))
        return 1;
    return 0;
}
