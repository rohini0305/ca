#include <stdio.h>
int nqueen(int row,int n,int board[]);
int place(int row,int col,int board[]);
int main() 
{
  int n;
  printf("Enter the number of queens: ");
  scanf("%d", &n);
  int size;
  size=n*n;
  int board[size];
  if (nqueen(0, n, board)) 
  {
    printf("Solution exists:\n");
    int i,j;
    for(i=0;i<n;i++) 
	{
    	for (j=0;j<n;j++) 
		{
        	if(board[i]==j) 
			{
                printf("Q ");
            }   
			else 
			{
               printf(". ");
            }
        } 
        printf("\n");
    }
  }  
  else
  {
    printf("No solution exists for %d queens.\n", n);
  }  
  return 0;
}
int nqueen(int row, int n, int board[]) 
{
    if (row == n) 
	{
        return 1; 
    }
    int col;
    for(col=0;col<n;col++) 
	{
    	if(place(row,col,board)) 
		{
            board[row]=col;
            if(nqueen(row+1,n,board)) 
			{
                return 1;
            }
        }
    }
    return 0;   
}
int place(int row,int col,int board[]) 
{
	int i;
    for(i=0;i<row;i++) 
	{
        if(board[i]==col||abs(board[i]-col)==abs(i-row)) 
		{
            return 0;
        }
    }
    return 1;
}
