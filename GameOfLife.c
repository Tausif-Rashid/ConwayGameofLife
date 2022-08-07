/* 
Conway's Game of Life 20x60

200041238 Tausif Rashid
200041256 Ahmed Fahim 
*/

#include<stdio.h>
#include<stdlib.h> 

#define ROW 22   //Number of Rows and columns
#define COL 62   //Extra two for the edges

int field[ROW][COL];        //Main 2D array
int field_draft[ROW][COL];  //Secondary 2D array for modifying the cells 

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

    int gen,x,y;  //generation,row number, column number input

    
    printf("Conway's Game of Life 20x60\n(0<=Row<=19, 0<=Column<=59) \n");
    
    printf("Enter the number of generations:");
    scanf("%d",&gen);
    
    printf("Enter the Co-ordiantes [row,column] of live cells:(-1,-1 to terminate)\n");
    
    for (int i = 0; ; i++) //loop for taking inputs, Only ends if user inputs -1,-1
    {

        scanf("%d,%d",&x,&y);

        x++;   // adjusting input: 0,0 will be stored in 1,1
        y++;
        
        if(x==0){break;}// If user iputs -1, then stop taking inputs

        //for checking invalid inputs
        if(x<1 || x>20){printf("Please Enter a valid input\n"); continue;}
        else if(y<1 || y>60){printf("Please Enter a valid input\n"); continue;}

        field[x][y]=1; //Make the cell x,y a live cell represented by value 1
        field_draft[x][y]=1;// field_draft same ase field

    }
    
    //for making the program wait, if ENTER pressed then continue to next part
    char temp;
    scanf("%c",&temp);
    system("cls");//clears everything printed 
    

    while(gen--)// Loop for generations, user input is cosidered 1st gen
    { 
        for (int row = 1; row < ROW-1; row++)//For printing the array of present gen
        {   
            printf("[%02d] ",row-1);
            for (int column = 1; column < COL-1;column++)
            {
                if(field[row][column]==1)printf("O");//Live cells are "O" and dead cells are "."
                else printf(".");
            }

            printf("\n"); //A line break after all the columns of a same row finished printing
        }
      
        printf("\n"); //2D array prining complete
      
        int live; //for storing number of live cells around a cell
       
        // Main part of the program. Checks the conditions for EVERY cell(EVERY neighbour) in the Array
        //Prepares Next gen array
        for (int row = 1; row < ROW-1; row++)
        {
            for (int column = 1; column < COL-1;column++)
            {
               
            
                live=0;//initially live neighbours around current cell is 0
                
                //These 8 if coditions check whether 8 neighbours around the cell are alive or not
                if(field[row+1][column]==1){live++;}       
                if(field[row+1][column-1]==1){live++;}     //for checking neighbours of next row,
                if(field[row+1][column+1]==1){live++;}     //if any alive cell found,then live increments
                
                // if(field[row][column]==1)live++; //Commented out because the cell itself is not it's neighbour
                if(field[row][column+1]==1){live++;}
                if(field[row][column-1]==1){live++;}   // for checking neighbours of same row,

                if(field[row-1][column]==1){live++;}    //
                if(field[row-1][column-1]==1){live++; } //for checking neighbours of previous row
                if(field[row-1][column+1]==1){live++;}  //
              
                // Checking of the neighbours done. The number of alive neighbours is stored in int live

                if(live==3){field_draft[row][column]=1;} //Condition: if 3 neighbours alive, cell will be alive(if it was dead, it becomes alive)
                else if(live==2){} //if 2 neighbours alive, cell does not change
                else {field_draft[row][column]=0;} //For any other condition, cell dies(if it was dead, it remains dead)

                // Done checking and modifying for the cell,loop moves on to the next cell
            
            }
        
        }
        //Modified the field_Draft array according to present Generation of field
            
        //For Copying the field_draft(modified, next gen) to field:
    
        for (int row = 0; row < ROW; row++)
        {
            for (int column = 0; column < COL;column++)
            {
            
                field[row][column]=field_draft[row][column];
            
            }
        
        }

        
        scanf("%c",&temp);//for making the system wait for an input, waits till user presses ENTER

        system("cls"); //Clears the output terminal

        //Move on to next gen
    }

    return 0;
}