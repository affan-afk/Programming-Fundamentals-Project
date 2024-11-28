#include <stdio.h>
#include<conio.h>
#include<windows.h>
#define red "\e[0;31m" // red color
#define blue "\e[1;34m" // blue color
#define def "\e[0m"   // set the color to default



void input();
int user_solution_checker(int, int);
void print_board(char);
int end_input();
int user_board[10][10] = {{0}}; //global 2-D Array containing the elements of user's sudoku board.
int unsolved[10][10] = {0};
void box_checker(int i , int j ,int value ){
	int c,d, k,l;
	if (i>=1 && i<=3){
    	c=3 ;
	}
	else if (i>=4 && i<=6){
    	c=6 ;
	}
	else if (i>=7 && i<=9){
    	c=9 ;
	}
	if (j>=1 && j<=3){
    	d=3 ;
	}
	else if (j>=4 && j<=6){
    	d=6 ;
	}
	else if (j>=7 && j<=9){
    	d=9 ;
    }
	for (k=c-2;k<=c;k++){
		for (l=d-2;l<=d;l++){
			
					if (i==k && j==l ){
					}
					else {
						if (user_board[k][l]==value){
							printf (red"Warning!!\nTHE  %d IN ROW %d AND COLOUMN %d is present more than once in the 3 by 3 block\nPRESS ANY KEY TO CONTINUE\n "def,user_board[i][j],i,j);getch();
}
}
}
}
}
void input(){
    int i,j,x,y,_continue = 1;
    char input[10];
do
{
    system("cls");
    print_board('u');
    printf("\n");
    
    // The first column and the first row will act as the coordinates, just like a chess board, so they need to be fixed, that is why another do while loop is Added below in case the user enters the coordinates with x=0 or y=0.  
     if (end_input() == 1)
    {
        printf("Sudoku Board is complete! Press 0 to end the game or 1 if you wish to continue the game: ");
        fgets(input,sizeof(input),stdin);
        if (input[strlen(input) - 1] == '\n') {
                input[strlen(input) - 1] = '\0';
            }
        sscanf(input,"%d",&_continue);
    }
    if (_continue == 0){
        break;
    } 
    do{
    printf("Enter the coordinates (x,y) = "); // For now here x is the row number and y is the column number 
    if(fgets(input,sizeof(input),stdin)!= NULL){
      if(sscanf(input,"%d,%d",&x,&y) ==2){
         if (x >=1 && x<=9 && y>=1 && y <=9)
         {
            break;
             
         }
         else{
            printf(red"Error: Coordinates must be between 1 and 9.\n"def);
         }
    }
      else{
         printf(red"Error: Invalid input. Enter coordinates in the format x,y.\n"def);
         }
    }
   else{
      printf(red"Error: Input could not be read.\n"def);
      }
    
    }while(1);
    // Another do while loop to prevent the user from entering anything except numbers from 1-9. 
    do{
    printf("Enter the value for (%d,%d) = ",x,y); // For now here x is the row number and y is the column number 
    if(fgets(input,sizeof(input),stdin)!= NULL){
      if(sscanf(input,"%d",&user_board[x][y]) == 1){
         if (user_board[x][y] >=1 && user_board[x][y]<=9)
         {
            break;
         }
         else{
            printf(red"Error: Value must be between 1 and 9.\n"def);
         }
    }
      else{
         printf(red"Error: Invalid input. Enter value and press enter.\n"def);
         }
    }
   else{
      printf(red"Error: Input could not be read.\n"def);
      }
    
    }while(1);
     int value = user_board[x][y];
    box_checker(x ,  y , value );
    if (user_solution_checker(x,y) == 1){
        printf(red"Warning! There is repitition in row %d. Press any key to Continue \n"def,x);
        getch();
    }
    if (user_solution_checker(x,y) == 2){
        printf(red"Warning! There is repitition column %d. Press any key to Continue\n"def,y);
        getch();
    }
   
    
} while (end_input() == 0 && _continue == 1);
if (_continue == 0) {
        printf("Game Over. Thanks for playing!\n");
}
}
int end_input(){
    for (int i = 1; i < 10; i++)
    {
        for (int j = 1; j < 10; j++)
        {
            if(user_board[i][j] == 0){
                return 0;
            }
        }
        
    }
   return 1; 
}
int user_solution_checker(int row,int col){
    int arr[10] = {0};
    for (int i = 1; i < 10; i++)
    {
       arr[user_board[row][i]]++;
    }
    for (int i = 1; i < 10; i++)
    {
       if (arr[i] > 1){
       return 1;
       }
    }
    for (int i = 1; i < 10; i++)
    {
        arr[i] = 0;
    }
    for (int i = 1; i < 10; i++)
    {
       arr[user_board[i][col]]++;
    }
    for (int i = 1; i < 10; i++)
    {
       if (arr[i] > 1){
       return 2;
       }
    }
    return 0;
}
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
           printf(blue"%2d"def, user_board[i][j]);
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
    break;
    case 'q': //prints unsolved board
    for(int j=0;j<10;j++){
                unsolved[0][j]=j;
                unsolved[j][0]=j;
            }
  for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            // Adding color red to i=0 and j=0 as they will act as the coordinates 
            if(i==0 || j==0)  
           printf(red"%2d"def, unsolved[i][j]);
           else 
            printf("%2d", unsolved[i][j]);
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
    break;
    
}
}

int main()
{
    input();
    return 0;
}
