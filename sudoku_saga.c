#include <stdio.h>

int user_board[9][9] = {0}; //global 2-D Array containing the elements of user's sudoku board.

void print_board(char x) //x will specify which board to print. (user/possible answer/unsolved)
{
  switch (x) 
{
case 'u': //prints user_board.
  for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("|%d| ", user_board[i][j]);
        }
        printf("\n");
    }
}
}
int main()
{
    print_board('u');
}
