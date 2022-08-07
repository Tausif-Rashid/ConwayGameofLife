/*Name: Tausif Rashid
ID: 200041238 */

/*
Conway's Game of Life 20x60
Conditions:
1.Any live cell with two or three live neighbours survives.
2.Any dead cell with three live neighbours becomes a live cell.
3.All other live cells die in the next generation. Similarly, all other dead cells stay dead.
*/

#include <stdio.h>
#include<stdlib.h> //Needed for system("cls")

#define ROW 20   //Number of Rows and columns
#define COL 60

int field[ROW][COL]; //Main 2D array
int field_draft[ROW][COL]; //Secondary 2D array for modifying the cells 


int main()
{  
     
    //For setting all the values to zero
    for (int row = 0; row < ROW; row++)
    {
        for (int column = 0; column < COL;column++)
        {
            
            field[row][column]=0;
            field_draft[row][column]=0;
        }
        
    }

    int gen,x,y;  //generation,row number, column number

    
    printf("Conway's Game of Life 20x60\n(1<=Row<=20, 1<=Column<=60) \n");
    printf("Enter the Co-ordiantes (row,column) of live cells:(-1,-1 to terminate)\n");
    
    for (int i = 0; ; i++) //loop for taking inputs, Only ends if user inputs -1,-1
    {

        scanf("%d,%d",&x,&y);

        x--;//User input reduced by one to match array positions(row from 0 to 19)
        y--;
       
        if(x==-2){break;}// If user iputs -1, then stop taking inputs

        
        //for checking invalid inputs
        if(x<0 || x>19){printf("Please Enter a valid input\n"); continue;}
        else if(y<0 || y>59){printf("Please Enter a valid input\n"); continue;}

        field[x][y]=1; //Make the cell x,y a live cell represented by value 1
        field_draft[x][y]=1;// field_draft same ase field

    }
    
    printf("Enter generation:");
    scanf("%d",&gen);

    //for making the program wait, if ENTER pressed then continue to next part
    char c;
    scanf("%c",&c);
    system("cls");//clears everything printed on the command prompt
    

   
    

    while(gen--)// Loop for generations, if gen=5 then runs 5times
    { 
        for (int row = 0; row < ROW; row++)//For printing the array of present gen
        {
            for (int column = 0; column < COL;column++)
            {
                if(field[row][column]==1)printf("O");//Live cells are "O" and dead cells are "."
                else printf(".");
            }

            printf("\n");//A line break after all the columns of a same row finished printing
        }
      
        printf("\n");//2D array prining complete
      
        int live;//for storing number of live cells around a cell
       
       // Main part of the program. Checks the conditions for EVERY cell(and EVERY neighbour) in the Array
       //Prepares Next gen array
        for (int row = 0; row < ROW; row++)
        {
            for (int column = 0; column < COL;column++)
            {
               
            
                live=0;//initially live neighbours around current cell is 0

                if(row!=(ROW-1) && column!=(COL-1) && row!=0 && column!=0)// Check all the cells that are not in the edge
                {
                    //These 8 if coditions check whether 8 neighbours around the cell are alive or not
                    if(field[row+1][column]==1){live++;}       //
                    if(field[row+1][column-1]==1){live++;}     //for checking neighbours of next row,
                    if(field[row+1][column+1]==1){live++;}  //   if any alive cell found,then live increases
                
                    // if(field[row][column]==1)live++; //Commented out because the cell itself is not it's neighbour
                    if(field[row][column+1]==1){live++;}
                    if(field[row][column-1]==1){live++;}   // for checking neighbours of same row,

                    if(field[row-1][column]==1){live++;}    //
                    if(field[row-1][column-1]==1){live++; } //for checking neighbours of previous row
                    if(field[row-1][column+1]==1){live++;}  //
              


                }
            
            
                else if(row==(ROW-1) && column==(COL-1))// Extreme Case: a cell of Lower-right corner
                {

                    if(field[0][column]==1)live++;
                    if(field[0][column-1]==1)live++; //for checking neighbours of next row,
                    if(field[0][0]==1)live++;           //in this case the next row does not exist. Row after last row is considered 1st row.
                
                    // if(field[row][column]==1)live++;
                    if(field[row][0]==1)live++; //because the next column doesn't exist, next column is the 1st column
                    if(field[row][column-1]==1)live++; // for checking neighbours of same row,

                    if(field[row-1][column]==1)live++;
                    if(field[row-1][column-1]==1)live++;//for checking neighbours of previous row
                    if(field[row-1][0]==1)live++;
                
                }
                
                else if(row==0 && column==0)// Extreme Case: a cell of corner
                {

                    if(field[row+1][column]==1)live++;
                    if(field[row+1][(COL-1)]==1)live++; //because the previous column doesn't exist,previous column is the last column
                    if(field[row+1][column+1]==1)live++;
                
                    // if(field[row][column]==1)live++;
                    if(field[row][column+1]==1)live++;
                    if(field[row][(COL-1)]==1)live++;

                    if(field[(ROW-1)][column]==1)live++;
                    if(field[(ROW-1)][(COL-1)]==1)live++;  //for checking neighbours of previous row
                    if(field[(ROW-1)][column+1]==1)live++;  //because the previous row doesn't exist,previous row is the last row
            
                }

                else if(row==0 && column==(COL-1))//Extreme Case: a cell of corner
                {

                    if(field[row+1][column]==1)live++;
                    if(field[row+1][column-1]==1)live++;
                    if(field[row+1][0]==1)live++;
                
                    // if(field[row][column]==1)live++;
                    if(field[row][0]==1)live++;
                    if(field[row][column-1]==1)live++;

                    if(field[(ROW-1)][column]==1)live++;
                    if(field[(ROW-1)][column-1]==1)live++;
                    if(field[(ROW-1)][0]==1)live++;
                
                }

                else if(row==(ROW-1) && column==0)//Extreme Case: a cell of corner
                {

                    if(field[0][column]==1)live++;
                    if(field[0][(COL-1)]==1)live++;
                    if(field[0][column+1]==1)live++;
                
                    // if(field[row][column]==1)live++;
                    if(field[row][column+1]==1)live++;
                    if(field[row][(COL-1)]==1)live++;

                    if(field[row-1][column]==1)live++;
                    if(field[row-1][(COL-1)]==1)live++;
                    if(field[row-1][column+1]==1)live++;
                }

                else if(row==0 && (column!= (COL-1) && column!=0))//Extreme Case: a cell of top side(1st line) but not corner
                {

                    if(field[row+1][column]==1)live++;
                    if(field[row+1][column-1]==1)live++;
                    if(field[row+1][column+1]==1)live++;
                
                    // if(field[row][column]==1)live++;
                    if(field[row][column+1]==1)live++;
                    if(field[row][column-1]==1)live++;

                    if(field[(ROW-1)][column]==1)live++;
                    if(field[(ROW-1)][column-1]==1)live++;
                    if(field[(ROW-1)][column+1]==1)live++;
                }

                else if(row==(ROW-1) && (column!= (COL-1) && column!=0))//Extreme Case: a cell of bottom side but not corner
                {

                    if(field[0][column]==1)live++;
                    if(field[0][column-1]==1)live++;
                    if(field[0][column+1]==1)live++;
                    
                    // if(field[row][column]==1)live++;
                    if(field[row][column+1]==1)live++;
                    if(field[row][column-1]==1)live++;

                    if(field[row-1][column]==1)live++;
                    if(field[row-1][column-1]==1)live++;
                    if(field[row-1][column+1]==1)live++;
                }

                else if(column==0 && (row!= (ROW-1) && row!=0))//Extreme Case: a cell of left side but not corner
                {

                    if(field[row+1][column]==1)live++;
                    if(field[row+1][COL-1]==1)live++;
                    if(field[row+1][column+1]==1)live++;
                    
                    // if(field[row][column]==1)live++;
                    if(field[row][column+1]==1)live++;
                    if(field[row][COL-1]==1)live++;

                    if(field[row-1][column]==1)live++;
                    if(field[row-1][COL-1]==1)live++;
                    if(field[row-1][column+1]==1)live++;
                }

                else if(column==(COL-1) && (row!= (ROW-1) && row!=0))//Extreme Case: a cell of right side but not corner
                {

                    if(field[row+1][column]==1)live++;
                    if(field[row+1][0]==1)live++;
                    if(field[row+1][column-1]==1)live++;
                    
                    // if(field[row][column]==1)live++;
                    if(field[row][0]==1)live++;
                    if(field[row][column-1]==1)live++;

                    if(field[row-1][column]==1)live++;
                    if(field[row-1][0]==1)live++;
                    if(field[row-1][column-1]==1)live++;
                }
                // Checking of the neighbours done. The number of alive neighbours is stored in int live

                if(live==3){field_draft[row][column]=1;} //Condition: if 3 neighbours alive, cell will be alive(if it was dead, it becomes alive)
                else if(live==2){} //if 2 neighbours alive, cell does not change
                else {field_draft[row][column]=0;} //For any other condition, cell dies(if it was dead, it remains dead)

                // Done checking and modifying for the cell,loop moves on to the next cell
            
            }
        
        }
    //I Modified the field_Draft array according to present Generation of field
            
            //Now Copy the field_draft(modified, next gen) to field:
    
        for (int row = 0; row < ROW; row++)
        {
            for (int column = 0; column < COL;column++)
            {
            
                field[row][column]=field_draft[row][column];
            
            }
        
        }

    
        char tmp;
        scanf("%c",&tmp);//for making the system wait for an input, waits till user presses ENTER

        if(gen!=0)system("cls"); //Clears the output terminal(everything printed gets removed)

        //Move on to next gen
    }

    printf("Press enter to quit\ncode:238\n"); //Done message

    char j;
    scanf("%c",&j);//for making the system wait for an input, waits till user presses ENTER


    return 0;
}