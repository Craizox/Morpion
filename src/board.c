#include "board.h"
#include <stdio.h>
#include <stdlib.h>

void print_board(char **board)
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

char **board_init(void)
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


int check_full_board(char **board)
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

int put_char_in_board(char **board, char player, char *input)
{
    if (input[0] == 'A' || input[0] == 'a')
        board[input[1] - '0'][0] = player;
    else if (input[0] == 'B' || input[0] == 'b')
        board[input[1] - '0'][1] = player;
    else
        board[input[1] - '0'][2] = player;
    return 1;
}

void free_board(char **board)
{
    for (int i = 0; i < 3; i++)
    {
        free(board[i]);
    }
    free(board);
}
