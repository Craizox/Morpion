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
    printf("    A   B   C\n");
    for (int i = 0; i < 3; i++)
    {
        printf("   -----------\n");
        for (int j = 0; j < 3; j++)
        {
            if (j == 0)
                printf("%d | %c |", i, board[i][j]);
            else
                printf(" %c |", board[i][j]);
        }
        printf("\n");
    }
    printf("   -----------\n");
    printf("\n");
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

static void put_char_in_board(char **board, char player, char *input)
{
    if (input[0] == 'A')
        board[input[1] - '0'][0] = player;
    else if (input[0] == 'B')
        board[input[1] - '0'][1] = player;
    else
        board[input[1] - '0'][2] = player;
}

static void ask_for_player(char **board, char player)
{
    print_board(board);
    if (player == 'o')
        printf("Turn of player 1: ");
    else
        printf("Turn of player 2: ");

    char buf[3];
    scanf("%s", buf);

    put_char_in_board(board, player, buf);
}




int main(void)
{
    char **board = board_init();
    int turn_player = 0;
    int win_p1, full, win_p2;
    while (!(win_p2 = check_win(board, 'x')) && !(win_p1 = check_win(board, 'o')) && !(full = check_full_board(board)))
    {
        if (turn_player % 2 == 0)
            ask_for_player(board, 'o');
        else
            ask_for_player(board, 'x');
        turn_player++;

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
