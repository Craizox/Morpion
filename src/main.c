#include <stdio.h>
#include <stdlib.h>


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

static int check_win(char **board, char player)
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


static void print_board(char **board)
{
    for (int i = 0; i < 3; i++)
    {
        printf(" -----------\n");
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                printf("| %c |", board[i][j]);
            else
                printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf(" -----------\n");
}

static char **board_init(void)
{
    char **board = calloc(3, sizeof(char *));
    for (int i = 0; i < 3; i ++)
    {
        board[i] =  calloc(3, sizeof(char));
        for (int j = 0; j < 3; j++)
        {
            board[i][j] = ' '; // 32 white space
        }
    }
    return board;
}

static int check_full_board(char **board)
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (board[i][j] == ' ')
                return 0;
        }
    }
    return 1;
}

int main(void)
{
    char **board = board_init();
    print_board(board);
    int win_p1, full;
    while ((win_p1 = check_win(board, 'x')) && (full = check_full_board(board)))
    {
        // ask for player where he wants to play
    }
    char *b[3] =
    {
        "xxo",
        "xox",
        "oxo"
    };
    print_board(b);
    printf("%d\n", check_win(b, 'o'));
    printf("%d\n", check_win(b, 'x'));
    return 1;
}
