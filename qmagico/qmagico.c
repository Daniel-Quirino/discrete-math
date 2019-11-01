#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int squareSize){
  int i,j;

  int **matriz = (int**)malloc(squareSize * sizeof(int*));

  for (i = 0; i < squareSize; i++){
       matriz[i] = (int*) malloc(squareSize * sizeof(int));
       for (j = 0; j < squareSize; j++){
            matriz
            [i][j] = 0;
       }
  }
    return matriz;
}

void fillMatrix(int **matriz, int squareSize) {
    if (squareSize % 2 == 1) {
        fillOddSizeMagicBoard(matriz, squareSize);
    }

    else if(squareSize % 2 == 0 && squareSize % 4 != 0){
        fillEvenMagicSquareSimple(matriz, squareSize, 0, 1, 3, 3, 0);
        fillEvenMagicSquareSimple(matriz, squareSize, 0, 4, 3, 6, 18);
        fillEvenMagicSquareSimple(matriz, squareSize, 3, 1, 6, 3, 27);
        fillEvenMagicSquareSimple(matriz, squareSize, 3, 4, 6, 6, 9);
        showMatrix(matriz, squareSize);
    }

    else if (squareSize % 2 == 0) {
        fillEvenMagicSquare(matriz, squareSize);
    }
}

void fillEvenMagicSquare(int **matriz, int squareSize) {
    int count = 0;

    for(int i=0; i<(squareSize); i++) {
        for(int j=0; j<(squareSize); j++) {
            count++;

            if(i == j) {
                matriz[i][j] = count;
            }
            else if(i+j==3) {
                matriz[i][j] = count;
            }
        }
    }

    count = 0;

    for(int i=squareSize-1; i>=0; i--) {
        for(int j=squareSize-1; j>=0; j--) {
            count++;

            if(matriz[i][j] == 0) {
                matriz[i][j] = count;
           }
        }
    }

    printf("numero = %d, Soma = %d \n", squareSize, soma(squareSize));
    printf(" %d ", matriz[0][0]);printf(" %d ", matriz[0][1]);printf(" %d ", matriz[0][2]);printf(" %d ", matriz[0][3]);
    printf("\n %d ", matriz[1][0]);printf(" %d ", matriz[1][1]);printf(" %d ", matriz[1][2]);printf(" %d ", matriz[1][3]);
    printf("\n %d ", matriz[2][0]);printf(" %d ", matriz[2][1]);printf(" %d ", matriz[2][2]);printf(" %d ", matriz[2][3]);
    printf("\n %d ", matriz[3][0]);printf(" %d ", matriz[3][1]);printf(" %d ", matriz[3][2]);printf(" %d ", matriz[3][3]);
}

void fillEvenMagicSquareSimple(int **matriz, int squareSize, int inicialLine, int inicialColumn, int finalLinelength, int finalColumnLength, int count) {
    int cont = count;

    matriz[inicialLine][inicialColumn] = cont + 1;
    cont++;

    int currentPositionLine = inicialLine;
    int currentPositionColumn = inicialColumn;

    for(int i=0; i<(3*3 - 1); i++) {

        if((currentPositionLine - 1) < inicialLine) {
            currentPositionLine = finalLinelength - 1;
        } else {
            currentPositionLine--;
        }

        if (currentPositionColumn + 1 > (finalColumnLength-1)) {
            currentPositionColumn = inicialColumn-1;
        } else {
            currentPositionColumn++;
        }

        if (matriz[currentPositionLine][currentPositionColumn] == 0) {
            matriz[currentPositionLine][currentPositionColumn] = cont + 1;
            cont++;
        } else {
            if((currentPositionLine + 2) > (finalLinelength-1)) {
                    if ((currentPositionLine + 2) - (finalLinelength-1) == 1) {
                        currentPositionLine = inicialLine;
                    } else if ((currentPositionLine + 2) - (finalLinelength-1) == 2) {
                        currentPositionLine = inicialLine + 1;
                    }
            } else {
                currentPositionLine = currentPositionLine + 2;
            }

            if((currentPositionColumn - inicialColumn) < 0) {
                currentPositionColumn = (finalColumnLength - 1);
            } else {
                currentPositionColumn--;
            }

            matriz[currentPositionLine][currentPositionColumn] = (cont + 1);
            cont++;
        }
    }
}

void showMatrix(int **matriz, int squareSize) {
    int aux = matriz[0][0];

    matriz[0][0] = matriz[3][0];
    matriz[3][0] = aux;

    aux =  matriz[1][1];
    matriz[1][1] = matriz[4][1];
    matriz[4][1] = aux;

    aux =  matriz[2][0];
    matriz[2][0] = matriz[5][0];
    matriz[5][0] = aux;

    printf("numero = %d, Soma = %d \n", squareSize, soma(squareSize));
    printf(" %d ", matriz[0][0]);printf(" %d ", matriz[0][1]);printf(" %d ", matriz[0][2]);printf(" %d ", matriz[0][3]);printf(" %d ", matriz[0][4]);printf(" %d ", matriz[0][5]);
    printf("\n %d ", matriz[1][0]);printf(" %d ", matriz[1][1]);printf(" %d ", matriz[1][2]);printf(" %d ", matriz[1][3]);printf(" %d ", matriz[1][4]);printf(" %d ", matriz[1][5]);
    printf("\n %d ", matriz[2][0]);printf(" %d ", matriz[2][1]);printf(" %d ", matriz[2][2]);printf(" %d ", matriz[2][3]);printf(" %d ", matriz[2][4]);printf(" %d ", matriz[2][5]);
    printf("\n %d ", matriz[3][0]);printf(" %d ", matriz[3][1]);printf(" %d ", matriz[3][2]);printf(" %d ", matriz[3][3]);printf(" %d ", matriz[3][4]);printf(" %d ", matriz[3][5]);
    printf("\n %d ", matriz[4][0]);printf(" %d ", matriz[4][1]);printf(" %d ", matriz[4][2]);printf(" %d ", matriz[4][3]);printf(" %d ", matriz[4][4]);printf(" %d ", matriz[4][5]);
    printf("\n %d ", matriz[5][0]);printf(" %d ", matriz[5][1]);printf(" %d ", matriz[5][2]);printf(" %d ", matriz[5][3]);printf(" %d ", matriz[5][4]);printf(" %d ", matriz[5][5]);
}

void fillOddSizeMagicBoard(int **matriz, int squareSize) {
    int cont = 0;

    matriz[0][(squareSize-1)/2] = cont + 1;
    cont++;

    int currentPositionLine = 0;
    int currentPositionColumn = (squareSize-1)/2;

    for(int i=0; i<(squareSize*squareSize - 1); i++) {

        if((currentPositionLine - 1) < 0) {
            currentPositionLine = squareSize - 1;
        } else {
            currentPositionLine--;
        }

        if (currentPositionColumn + 1 > (squareSize-1)) {
            currentPositionColumn = 0;
        } else {
            currentPositionColumn++;
        }

        if (matriz[currentPositionLine][currentPositionColumn] == 0) {
            matriz[currentPositionLine][currentPositionColumn] = cont + 1;
            cont++;
        } else {
            if((currentPositionLine + 2) > (squareSize-1)) {
                    if ((currentPositionLine + 2) - (squareSize-1) == 1) {
                        currentPositionLine = 0;
                    } else if ((currentPositionLine + 2) - (squareSize-1) == 2) {
                        currentPositionLine = 1;
                    }
            } else {
                currentPositionLine = currentPositionLine + 2;
            }

            if((currentPositionColumn - 1) < 0) {
                currentPositionColumn = (squareSize - 1);
            } else {
                currentPositionColumn--;
            }

            matriz[currentPositionLine][currentPositionColumn] = (cont + 1);
            cont++;
        }
    }

    printf("numero = %d, Soma = %d \n", squareSize, soma(squareSize));
    printf(" %d ", matriz[0][0]);printf(" %d ", matriz[0][1]);printf(" %d ", matriz[0][2]);printf(" %d ", matriz[0][3]);printf(" %d ", matriz[0][4]);
    printf("\n %d ", matriz[1][0]);printf(" %d ", matriz[1][1]);printf(" %d ", matriz[1][2]);printf(" %d ", matriz[1][3]);printf(" %d ", matriz[1][4]);
    printf("\n %d ", matriz[2][0]);printf(" %d ", matriz[2][1]);printf(" %d ", matriz[2][2]);printf(" %d ", matriz[2][3]);printf(" %d ", matriz[2][4]);
    printf("\n %d ", matriz[3][0]);printf(" %d ", matriz[3][1]);printf(" %d ", matriz[3][2]);printf(" %d ", matriz[3][3]);printf(" %d ", matriz[3][4]);
    printf("\n %d ", matriz[4][0]);printf(" %d ", matriz[4][1]);printf(" %d ", matriz[4][2]);printf(" %d ", matriz[4][3]);printf(" %d ", matriz[4][4]);

}

int soma(int squareSize) {
    return (squareSize * (squareSize*squareSize + 1))/2;
}


int main()
{
    int squareSize;
    scanf("%d", &squareSize);
    printf("\n");

    int **matriz = alocarMatriz(squareSize);

    fillMatrix(matriz, squareSize);

    return 0;
}
