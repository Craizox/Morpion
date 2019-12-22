#ifndef BOARD_H
#define BOARD_H

/**
** \brief function that print the board on the standart output
**
** \param board: board to be printed
*/
void print_board(char **board);

/**
** \brief function that initialized the board
**
** \return the newly alloacted board
*/
char **board_init(void);


/**
** \brief function that check if the board is full
**
** \param board: board to be checked
**
** \return 1 if the board is full, 0 otherwise
*/
int check_full_board(char **board);

/**
** \brief function that put the caracter of the player in the corresponding
**  case inlcude in input
**
** \param board: board where to put the char
** \param player: char to be placed
** \param input: char containing the location of where the char shall be placed
**
** \return 1 on sucess, 0 otherwise
*/
int put_char_in_board(char **board, char player, char *input);

/**
** \brief free the board
**
** \param board: board to be freed
*/
void free_board(char **board);

#endif /* !BOARD_H */
