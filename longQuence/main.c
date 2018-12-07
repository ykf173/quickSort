#include <stdio.h>
#include <stdlib.h>
#define MAX 500


void LCSLength(char *x, char *y, int m, int n, int (*c)[MAX], int **b)//动态传参 ，第一种（*c）[MAX]，第二种**b，访问方式如下
{
    int i,j;
    for(i=0; i<m; i++)    c[i][0] = 0;
    for(i=0; i<n; i++)    c[0][i] = 0;
    for(i=0; i<m; i++){
        for(j=0; j<n; j++){
            if(x[i] == y[j]){
                c[i][j] = c[i-1][j-1] + 1;
                *((int *)b+i*MAX+j) = 1;
            }
            else if(c[i-1][j] >= c[i][j-1]){
                c[i][j] = c[i-1][j];
                *((int *)b+i*MAX+j) = 2;
            }
            else{
                c[i][j] = c[i][j-1];
                *((int *)b+i*MAX+j) = 3;
            }
        }
    }
}

void LCS(int i, int j, char *x, int b[][MAX])
{
    if(i==-1 || j==-1)    return;
    if(b[i][j] == 1){
        LCS(i-1, j-1, x, b);
        printf("%c", x[i]);
    }
    else if(b[i][j] == 2){
        LCS(i-1, j, x, b);
    }
    else LCS(i, j-1, x, b);
}

int main()
{
    int b[MAX][MAX];
    int c[MAX][MAX];
    char x[7] = "3123456";
    char y[8] = "32468109";
    LCSLength(x, y, 7, 8, c, (int **)b);
    LCS(6, 7, x, b);
    return 0;
}
