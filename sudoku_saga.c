#include <stdio.h>
#include<conio.h>
#include<windows.h>
#include<time.h>
// Define color codes for normal versions
    #define red "\e[0;31m" // red color
    #define blue "\e[1;34m" // blue color
    #define green "\e[1;32m" // green color
    #define yello "\e[1;33m" // yellow color
    #define magneta "\e[1;35m"//
    #define def "\e[0m"   // set the color to default
// Define color codes for dark versions
    #define DARK_RED 4       // Dark Red
    #define DARK_BLUE 1      // Dark Blue
    #define DARK_GREEN 2     // Dark Green
    #define DARK_MAGENTA 5   // Dark Magenta



void input();
int user_solution_checker(int, int);
void print_board(char);
int end_input();
char level ;
int score ;
int user_board[10][10] = {{0}}; //global 2-D Array containing the elements of user's sudoku board.
int unsolved[10][10] = {0};
void box_checker(int i , int j ,int value ){   // checks if there is repeatition in the 3x3 small blocks of sudoku 
	int a=0;
	int c,d, k,l;
	if (i>=1 && i<=3){       // these set of conditional statements sets the borderline of rows to check 
    	c=3 ;
	}
	else if (i>=4 && i<=6){
    	c=6 ;
	}
	else if (i>=7 && i<=9){
    	c=9 ;
	}
	
	if (j>=1 && j<=3){    // these set of conditional statements sets the borderline of coloumns to check 
    	d=3 ;
	}
	else if (j>=4 && j<=6){
    	d=6 ;
	}
	else if (j>=7 && j<=9){
    	d=9 ;
    }
	for (k=c-2;k<=c;k++){    // loop to check for repitition in the 3x3 small boxes 
		for (l=d-2;l<=d;l++){
			
					if (i==k && j==l ){  // condition to bypass the location of the value being checked
					}
					else {
						if (user_board[k][l]==value ){  // if there is a repition this conditional statement then sets value of a variable a to 1
						a=1;
}
}   
}
}
 if (a==1){  // warning to the user in case of repitition in the 3x3 block 
     		printf (red"Warning!!\nThe number %d is present more than once in the 3 by 3 block.\nPRESS ANY KEY TO CONTINUE\n"def,user_board[i][j],i,j);getch();
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
    fflush(stdin);
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
    if (user_solution_checker(x,y) == 1 ){
        printf(red"Warning! There is repitition in row %d. Press any key to Continue \n"def,x);
        getch();
    }
    if (user_solution_checker(x,y) == 2){
        printf(red"Warning! There is repitition in column %d. Press any key to Continue \n"def,y);
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
void menu(){ // gives user a startup menu 
	int Opt ;
	printf (red"MENU"def);
	printf (green"\nOption 1 : Information about sudoku and its rules  \nOption 2 : Start game  "def);
	printf (red"\nYour option : "def);
	scanf ("%d",&Opt);
	while (Opt!=1 && Opt !=2){
		printf ("Invalid input !!!\nKindly input option 1 or 2\nYour option :");
		scanf ("%d",&Opt);
		
	}
	if (Opt==1){      // prints details and rules about sudoku 
		printf (blue"\nSudoku Rule Number 1: Use Numbers 1-9"def);getch();
		printf (magneta"\n\n  Sudoku is played on a grid of 9 x 9 spaces.\n  Within the rows and columns are 9 squares (made up of 3 x 3 spaces).\n  Each row, column and square (9 spaces each) needs to be filled out with the numbers\n  1-9,without repeating any numbers within the row, column or square.\n  Does it sound complicated?\n  Each Sudoku grid comes with a few spaces already filled in;the more spaces filled in, the easier the game - \n  The more difficult Sudoku puzzles have very few spaces that are already filled in."def);getch();
		printf (blue"\n\nSudoku Rule Number 2: Don't Repeat Any Numbers"def);getch();
		printf (magneta"\n\n  You can not repeat any numbers in the 3 x 3 grid .\n  Moreover you also cannot repeat the numbers in any rows or coloums of the whole 9 x 9 grid of sudoku "def);
		printf (blue"\n\nSudoku Rule Number 3: Don't Guess\n"def);getch();
		printf (magneta"\n  Sudoku is a game of logic and reasoning, so you shouldn't have to guess.\n  If you don't know what number to put in a certain space,keep scanning the other areas of the grid until you seen an \n  opportunity to place a number.\n  But don't try to force anything - Sudoku rewards patience, insights, and recognition of patterns, not blind luck or\n  guessing."def);getch();
		printf (blue"\n\nSudoku Rule Number 4: Use Process of Elimination\n"def);getch();
		printf (magneta"\n  One way to figure out which numbers can go in each space is to use - process of elimination by checking to see which other numbers are already\n  included within each square - since there can be no duplication of numbers 1-9 within each square (or row or column).\n  Sudoku rules are relatively uncomplicated -but the game is infinitely varied, with millions of possible number combinations and a wide range of levels of difficulty.\n  But it's all based on the simple principles of using numbers 1-9, filling in the blank spaces based on deductive reasoning, and never repeating any numbers within\n  each square, row or column."def);getch();
		system ("cls");
		printf (red"\nYou will understand better with an example------------------\n\nUnsolved sudoku grid:-\n\n"def);getch();
		 
		 int sudoku[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    // Print the Sudoku for visualization
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            printf("%d ", sudoku[i][j]);

			if (j==2 ||j==5 || j==8){
				printf ("|");
			}
        }
        if (i==2 || i==5 || i==8){
        printf ("\n---------------------");
    }
		printf("\n");
    }
    getch();
     int sudoku_solved[9][9] = {
        {5, 3, 4, 6, 7, 8, 9, 1, 2},
        {6, 7, 2, 1, 9, 5, 3, 4, 8},
        {1, 9, 8, 3, 4, 2, 5, 6, 7},
        {8, 5, 9, 7, 6, 1, 4, 2, 3},
        {4, 2, 6, 8, 5, 3, 7, 9, 1},
        {7, 1, 3, 9, 2, 4, 8, 5, 6},
        {9, 6, 1, 5, 3, 7, 2, 8, 4},
        {2, 8, 7, 4, 1, 9, 6, 3, 5},
        {3, 4, 5, 2, 8, 6, 1, 7, 9}
    };

    // Print the solved Sudoku grid
    printf(red"\n\nSolved Sudoku:\n\n"def);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
        	 printf("%d ", sudoku_solved[i][j]);
//        	if (i%3==0){
//        		printf ("_");
//			}
			if (j==2 || j==5 ||j==8){
				printf ("|");
			}
           
        }
        if (i==2 || i==5 || i==8){
        printf ("\n---------------------");
    }
		printf("\n");
     
    }
    getch();
    printf ("\nNow let's start the game ");getch();
    printf ("Choose from the options below\nEASY:E\nMEDIUM:M\nHARD:H\nYour option : ");getch(); // asks the user's choice about difficulty level
    scanf (" %c",&level);
	system("cls");
    input ();

	}
	else if (Opt==2){
	printf ("Choose from the options below\nEASY:E\nMEDIUM:M\nHARD:H\nYour option : ");getch(); // asks the user's choice about difficulty level
    scanf (" %c",&level);
	system("cls");
		input();
	}
	
}

void setColor(int color) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  //add colours to the messages and outputs
    SetConsoleTextAttribute(hConsole, color);
}


	
	



int main(){
    setColor(DARK_RED);
	printf ("WELCOME TO THE SUDOKU SAGA");getch();system("cls");
	menu();
}
