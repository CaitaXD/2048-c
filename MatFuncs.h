#pragma once
#define MAX 10

int FillMat(int mat[][MAX], int l, int c);
int InputA(int mat[][MAX], int l, int c);

int InitMat(int mat[][MAX], int l, int c)
{
    int count = 2;
    system("cls");
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y < c; y++)
        {
            int  sort = rand() % 100;
            if (sort < 90 && count > 0)
            {
                count--;
                mat[x][y] = 2;
            }
            else if (sort >= 90 && count > 0)
            {
                count--;
                mat[x][y] = 4;
            }
            else
                mat[x][y] = 0;
        }
    }
    return mat;
}
int FillMat(int mat[][MAX], int l, int c)
{
    int count = 2;
    system("cls");
    for (int x = 0; x < l; x++)
    {
        for (int y = 0; y < c; y++)
        {
            int  sort = rand() % 100;
            if (sort < 90 && count > 0 && mat[x][y] == 0)
            {
                count--;
                mat[x][y] = 2;
            }
            else if (sort > 90 && count > 0 && mat[x][y] == 0)
            {
                count--;
                mat[x][y] = 2;
            }
        }
    }
    return mat;
}
int InputD(int mat[][MAX], int l, int c)
{
    //Slide the matrix
    int k, j, aux;
    for (int h = 0; h < l; h++)
    {
        for (k = l - 1; k > 0; k--)
        {

            for (j = 0; j < k; j++)
            {

                if (mat[h][j + 1] == 0) {
                    aux = mat[h][j];
                    mat[h][j] = mat[h][j + 1];
                    mat[h][j + 1] = aux;
                }
                if (mat[h][j] == mat[h][j + 1])
                { 
                    aux = 2*mat[h][j];
                    mat[h][j] =0;
                    mat[h][j + 1] = aux;
                }
            }
        }
    }
    FillMat(mat, l, c);
    return mat;
}
int InputA(int mat[][MAX], int l, int c)
{
    int aux = 1;
    // Double The Equal Values
    for (int h = 0; h < l; h++)
    {
        for (int k = l - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (mat[h][j] == mat[h][j + 1])
                {
                    aux = 2 * mat[h][j];
                    mat[h][j] = 0;
                    mat[h][j + 1] = aux;
                }
            }
        }
    }
    for (int h = 0; h < l; h++)
    {
        for (int k = l - 1; k > 0; k--)
        {
          for (int j = 0; j < k; j++)
            {
                if (mat[h][j] == 0) 
                {
                    aux = mat[h][j];
                    mat[h][j] = mat[h][j + 1];
                    mat[h][j + 1] = aux;
                }

            }
        }
    }
    FillMat(mat, l, c);
    return mat;
}

int InputW(int mat[][MAX], int l, int c)
{
    int aux;
    for (int h = 0; h < l; h++)
    {
        for (int k = l - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (mat[j + 1][h] == mat[j][h])
                {
                    aux = 2 * mat[j][h];
                    mat[j][h] = 0;
                    mat[j+1][h] = aux;
                }
            }
        }
    }
    for (int h = 0; h < l; h++)
    {
        for (int k = l - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (mat[j][h] == 0)
                {
                    aux = mat[j+1][h];
                    mat[j+1][h] = mat[j][h];
                    mat[j][h] = aux;
                }
            }
        }
    }
    FillMat(mat, l, c);
    return mat;
}
int InputS(int mat[][MAX], int l, int c)
{
    int aux;

    //Slide Matrix == Para Baixo
    for (int h = 0; h < l; h++)
    {
        for (int k = l - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (mat[j + 1][h] == 0)
                {
                    aux = mat[j][h];
                    mat[j][h] = mat[j + 1][h];
                    mat[j + 1][h] = aux;
                }
            }
        }
    }
    //Dobra os Valores Repetido
    for (int h = 0; h < l; h++)
    {
        for (int k = l - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (mat[j + 1][h] == mat[j][h])
                {
                    aux = 2 * mat[j][h];
                    mat[j + 1][h] = 0;
                    mat[j][h] = aux;
                }
            }
        }
    }
    //Slide Matrix De pq sobra um 0 entre os valors visto que e função le em pares
    for (int h = 0; h < l; h++)
    {
        for (int k = l - 1; k > 0; k--)
        {
            for (int j = 0; j < k; j++)
            {
                if (mat[j + 1][h] == 0)
                {
                    aux = mat[j][h];
                    mat[j][h] = mat[j + 1][h];
                    mat[j + 1][h] = aux;
                }
            }
        }
    }
    FillMat(mat, l, c);
    return mat;
}
