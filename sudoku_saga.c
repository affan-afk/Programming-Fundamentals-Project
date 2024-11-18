#include <stdio.h>
#include<conio.h>
#include<windows.h>
#define red "\e[0;31m" // red color
#define def "\e[0m"   // set the color to default
int user_board[10][10] = {0}; //global 2-D Array containing the elements of user's sudoku board.

void print_board(char x) //x will specify which board to print. (user/possible answer/unsolved)
{
  switch (x) 
{
case 'u': //prints user_board.
            for(int j=0;j<10;j++){
                user_board[0][j]=j;
                user_board[j][0]=j;
            }
  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Adding color red to i=0 and j=0 as they will act as the coordinates 
            if(i==0 || j==0)  
           printf(red"%2d"def, user_board[i][j]);
           else 
            printf("%2d", user_board[i][j]);
            // Below some code to separate the 3x3 blocks horizontally 
            if(i==0 && (j==3 || j==6))
                printf("  ");
            else if(i!=0 && (j==3 || j==6))
                printf(" |");
        }
        // Below some code to separate the 3x3 blocks vertically 
        if(i==3 || i== 6){
                printf("\n");
            for(int j=0;j<10;j++){
                if(j<3)
                printf(" ");
                else
                printf("---");
            }
        }
        printf("\n");
    }
}
}

int main()
{
int i,j,spaces=0,x,y;
    // counting the places with zeros and storing the number in 'spaces', at first it will be 81.   
for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            if(user_board[i][j]==0){    
                spaces++;
            }
        }
}
    // For now the main condition is based on the number of spaces, as the checking is not added yet.
for(;spaces!=0;){ 
    system("cls");
    print_board('u');
    printf("\n");
    // The first column and the first row will act as the coordinates, just like a chess board, so they need to be fixed, that is why another do while loop is Added below in case the user enters the coordinates with x=0 or y=0.  
    do{
    printf("Enter the coordinates (x,y) = "); // For now here x is the row number and y is the column number 
    scanf("%d,%d",&x,&y);
    }while(x==0 || y==0);
    if(user_board[x][y]==0){
        spaces--;
    }
    // Another do while loop to prevent the user from entering numbers other than 0-9. 
    do{
    printf("Enter the value at %d row and %d column: ",x,y);
    scanf("%d",&user_board[x][y]);
    }while(user_board[x][y]<1 || user_board[x][y]>9);
    }
    getch();
    return 0;
}