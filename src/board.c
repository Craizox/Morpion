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
            {
                if (board[i][j] == 'o')
                    printf("%d | \033[34;01m%c\033[00m |", i, board[i][j]);
                else if (board[i][j] == 'x')
                    printf("%d | \033[31;01m%c\033[00m |", i, board[i][j]);
                else
                    printf("%d | \033[31;01m%c\033[00m |", i, board[i][j]);
            }
            else
            {
                if (board[i][j] == 'o')
                    printf(" \033[34;01m%c\033[00m |", board[i][j]);
                else if (board[i][j] == 'x')
                    printf(" \033[31;01m%c\033[00m |", board[i][j]);
                else
                    printf(" %c |", board[i][j]);
            }
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

static int check_if_already_set(char **board, char player, int line, int col)
{
    if (board[line][col] != ' ')
    {
        printf("This case is already use try another one\n");
        return 0;
    }
    board[line][col] = player;
    return 1;
}

int put_char_in_board(char **board, char player, char *input)
{
    if (input[0] == 'A' || input[0] == 'a')
        return check_if_already_set(board, player, input[1] - '0', 0);
    else if (input[0] == 'B' || input[0] == 'b')
        return check_if_already_set(board, player, input[1] - '0', 1);
    else
        return check_if_already_set(board, player, input[1] - '0', 2);
    return 0;
}

void free_board(char **board)
{
    for (int i = 0; i < 3; i++)
    {
        free(board[i]);
    }
    free(board);
}
