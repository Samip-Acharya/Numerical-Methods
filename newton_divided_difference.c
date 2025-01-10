#include<stdio.h>
#include<stdlib.h>

typedef struct data
{
    float x; 
    float y; 
}data; 

int main()
{
    //Inputting Data
    int n; 
    printf("Enter the number of nodes/data sets\n");
    scanf("%d",&n); 
    data *dataArray = (data *) malloc(n*sizeof(data)); 
    for(int i=0;i<n;i++)
    {
        data temp; 
        printf("Node %d:\n",i); 
        printf("x: "); 
        scanf("%f",&temp.x); 
        printf("y: "); 
        scanf("%f",&temp.y); 
        dataArray[i] = temp; 
    }

    //Creating a divided difference table
    float **dividedDiffTable = (float **)malloc(n*sizeof(float*));
    float **temp = dividedDiffTable; 
    for(int i = 0; i<n; i++)
    {
        *temp = (float *)malloc(n*sizeof(float)); 
        temp++; 
    }
    // A simple alternative of above code is to create a variable length 2-D array like float dividedDiffTable[n][n]
    //Filling 1st column with f(xi) i.e. O order divided difference
    for(int i = 0; i<n; i++)
        dividedDiffTable[i][0] = dataArray[i].y;  
    //Filling successive columns for 1st,2nd,...,(n-1)th order difference where each is calucated using preceding difference
    for(int j = 1; j<n; j++)
    {
        for(int i = 0 ; i<n-j; i++)
            dividedDiffTable[i][j] = (dividedDiffTable[i+1][j-1] - dividedDiffTable[i][j-1])/(dataArray[i+j].x-dataArray[i].x); 
    } 

    //Calculate the interpolated value for given value say val
    float val; 
    printf("Enter the value of 'x' for which you want interpolated value(y):\n");
    scanf("%f",&val); 
    float result = dataArray[0].y; 
    float product = 1; 
    for(int j = 1; j<n; j++)
    {
        product *= (val-dataArray[j-1].x); 
        result += dividedDiffTable[0][j]*product; 
    }
    printf("The interpolated value at x=%.5f is %.5f\n",val,result); 
    return 0; 
}