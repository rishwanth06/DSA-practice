#include<stdio.h>
#include<stdlib.h>
#define DIM 9
#define SAFE 0
#define UNSAFE 1
void printGrid ( int grid [ DIM ] [ DIM ] )
{
    int row;
    int col;
    for( row =0; row < DIM; row+=1, printf("\n"))

    {
        for( col = 0; col < DIM; col +=1)
        {
            printf("%d ", grid [ row ] [ col ]);
        }
    }
}
int isSafe(int wg[DIM][DIM], int row, int col, int trialValue)
{
    
    int r;
    int c;
    for(  c = 0; c < DIM; c+=1)
    {
        if ( wg [ row ][c] == trialValue)
            return UNSAFE;
    }
    
    for( r = 0; r < DIM; r+=1)
    {
        if ( wg [ r ] [ col ] == trialValue)
            return UNSAFE;
    }
  
    int corRow;
    int corCol;
    corRow = (row / 3) * 3;
    corCol = (col / 3) * 3;
    for( r = 0; r < 3; r+=1)
    {
        for(c= 0; c< 3; c+=1)
        {
            if ( wg [ corRow + r] [ corCol + c] == trialValue )
                return UNSAFE;
        }
    }
    return SAFE;
}
void sudokuSolver_helper( int grid [ DIM ] [DIM ], int wg[ DIM][DIM], int r, int c)
{
    int wr;
    int wc;
    wr = r;
    wc = c;
    static int solutionFound ;
    if ( wc == DIM)
    {
        wc = 0;
        wr += 1;
        if ( wr == DIM) 
        {
           
            printGrid(wg);
            solutionFound = 1;
            return;
        }
    }
    if ( grid[ wr ] [wc] != 0)
    {
        sudokuSolver_helper(grid, wg, wr,wc+1);
        return;
    }
    else
    {
        int trialValues;
        for( trialValues = 1; trialValues <= DIM && solutionFound == 0; trialValues+=1)
        {
            if ( isSafe(wg,wr,wc,trialValues) == SAFE)
            {
                wg [ wr] [ wc] = trialValues;
                sudokuSolver_helper(grid, wg, wr, wc+1);
                wg [ wr] [ wc ] = 0;
            }
        }
    }
}
void sudokuSolver( int grid [ DIM ] [DIM])
{
    int workGrid[ DIM ] [ DIM ];
    int row;
    int col;
    for( row = 0; row< DIM; row+=1)
    {
        for ( col = 0; col < DIM; col +=1)
        {
            workGrid [ row ] [ col ] = grid [ row ][ col];
        }
    }
    sudokuSolver_helper(grid, workGrid, 0, 0);

}
int main()
{
  
  int grid[DIM][DIM] = {
                      {0,0,0,8,0,1,0,0,0},
                      {0,0,0,0,0,0,0,4,3},
                      {5,0,0,0,0,0,0,0,0},
                      {0,0,0,0,7,0,8,0,0},
                      {0,0,0,0,0,0,1,0,0},
                      {0,2,0,0,3,0,0,0,0},
                      {6,0,0,0,0,0,0,7,5},
                      {0,0,3,4,0,0,0,0,0},
                      {0,0,0,2,0,0,6,0,0}
                      };

     sudokuSolver(grid);

    return EXIT_SUCCESS;
}
