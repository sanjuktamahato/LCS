#include <stdio.h>
#include <string.h>

int lcs(char *X, char *Y, int m, int n) 
{
	int i,j;
    int L[m+1][n+1];
    for ( i = 0; i <= m; i++) 
	{
    	
        for ( j = 0; j <= n; j++)
		 {
            if (i == 0 || j == 0) 
			{
                L[i][j] = 0;
            } else if (X[i-1] == Y[j-1]) 
			{
                L[i][j] = L[i-1][j-1] + 1;
            } else 
			{
                L[i][j] = (L[i-1][j] > L[i][j-1]) ? L[i-1][j] : L[i][j-1];
            }
        }
    }
    
    return L[m][n];
}
void printLCS(char *X, char *Y, int m, int n, int L[m+1][n+1]) 
{
    int index = L[m][n];
    char lcs[index+1];
    lcs[index] = '\0';
    
    int i = m, j = n;
    while (i > 0 && j > 0) 
	{
        if (X[i-1] == Y[j-1]) 
		{
            lcs[index-1] = X[i-1];
            i--;
            j--;
            index--;
        } else if (L[i-1][j] > L[i][j-1]) 
		{
            i--;
        } else 
		{
            j--;
        }
    }
    printf("LCS: %s\n", lcs);
}

int main() {
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    
    int m = strlen(X);
    int n = strlen(Y);
    int L[m+1][n+1];
    printf("Length of LCS: %d\n", lcs(X, Y, m, n));
    printLCS(X, Y, m, n, L);
    
    return 0;
}