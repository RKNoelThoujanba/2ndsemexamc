#include <stdio.h>

#define MAT_MAX_DIMENSION 256

void AddMat(
    const float matA[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION], unsigned int rowA, unsigned int colA,
    const float matB[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION], unsigned int rowB, unsigned int colB,
    float matRes[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION], unsigned int rowRes, unsigned int colRes
)
{
    if(matA == NULL || matB == NULL || matRes == NULL) return;
    if(rowA == 0 || rowB == 0 || rowRes == 0 || colA == 0 || colB == 0 || colRes == 0) return;

    if(! (rowA == rowB && rowB == rowRes) ) return;
    if(! (colA == colB && colB == colRes) ) return;

    for(unsigned int i = 0; i < rowRes; ++i)
        for(unsigned int j = 0; j < colRes; ++j)
            matRes[i][j] = matA[i][j] + matB[i][j];


}

void ReadMat(float mat[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION], unsigned int row, unsigned int col)
{
    if(mat == NULL || row == 0 || col == 0) return;

    for(unsigned int i = 0; i < row; ++i)
        for(unsigned int j = 0; j < col; ++j)
            scanf("%f", &mat[i][j]);
}

void PrintMat(const float mat[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION], unsigned int row, unsigned int col)
{
    if(mat == NULL || row == 0 || col == 0) return;

    for(unsigned int i = 0; i < row; ++i)
    {
        for(unsigned int j = 0; j < col; ++j)
        {
            printf(" %f ", mat[i][j]);
        }
        putchar('\n');
    }
}


int main(void)
{
    float 
        matA[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION] = {{0}}, 
        matB[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION] = {{0}}, 
        matRes[MAT_MAX_DIMENSION][MAT_MAX_DIMENSION] = {{0}};

    unsigned int rowA, colA;
    printf("Enter dimenstions of Matrix A: ");
    scanf("%u%u", &rowA, &colA);
    if(rowA == 0 || colA == 0 || rowA > MAT_MAX_DIMENSION || colA > MAT_MAX_DIMENSION)
    {
        printf("Invalid Dimension\n");
        return 1;
    }
    printf("Enter matrix A: \n");
    ReadMat(matA, rowA, colA);

    unsigned int rowB, colB;
    printf("Enter dimenstions of Matrix B: ");
    scanf("%u%u", &rowB, &colB);
    if(rowB == 0 || colB == 0 || rowB > MAT_MAX_DIMENSION || colB > MAT_MAX_DIMENSION)
    {
        printf("Invalid Dimension\n");
        return 2;
    }

    if(! (rowA == rowB && colA == colB) )
    {
        printf("Incompatable Dimensions\n");
        return 3;
    }

    printf("Enter matrix B: \n");
    ReadMat(matB, rowB, colB);

    unsigned int rowRes = rowA, colRes = colA;
    AddMat(matA, rowA, colA, matB, rowB, colB, matRes, rowRes, colRes);

    printf("A + B: \n");
    PrintMat(matRes, rowRes, colRes);
}