#include <stdio.h>
#include <stdlib.h>
#include "MatFuncs.h"
#include "StateMachine.h"
/*
Nno momento usa-se o scanf como input
Creio que o comportamento da matriz esteje  correto mas e possivel que não
Para mover os numeros na matriz foi adaptado bublesort dentro de um laço for
Algumas direçõe presisaram de mais laços por causa da ordem de varredura
As funçoes de Input retornam a matriz
    (n sei se vale a mão de mudar o retorno para void e usar pointer?)
*/
int main() 
{
    int mat[MAX][MAX];
    StartState(mat);
    return 0;
}



