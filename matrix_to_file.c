#include <stdio.h>
int main()
{
    FILE *fp;
    int matrix[3][3];
    fp = fopen("matrix.txt", "w");
    if(fp == NULL)
    {
        printf("Unable to create file.");
        return 1;
    }
    printf("Enter 3x3 Matrix:\n");
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            scanf("%d", &matrix[i][j]);
            fprintf(fp, "%d ", matrix[i][j]);
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
    printf("Matrix saved successfully in matrix.txt");
    return 0;
}
