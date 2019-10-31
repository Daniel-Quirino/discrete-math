#include <stdio.h>
#include <stdlib.h>

int** alocarMatriz(int squareSize){
  int i,j;

  int **matrix = (int**)malloc(squareSize * sizeof(int*));

  for (i = 0; i < squareSize; i++){
       matrix[i] = (int*) malloc(squareSize * sizeof(int));
       for (j = 0; j < squareSize; j++){
            matrix
            [i][j] = 0;
       }
  }
    return matrix;
}

void fillMatrix(int **matrix, int squareSize) {
    if (squareSize % 2 == 1) {
        fillOddSizeMagicBoard(matrix, squareSize);
    }

    if(squareSize % 2 == 0 && squareSize % 4 != 0){
        fillEvenMagicSquareSimple(matrix, squareSize, 0, 1, 3, 3, 0);
        fillEvenMagicSquareSimple(matrix, squareSize, 0, 4, 3, 6, 18);
        fillEvenMagicSquareSimple(matrix, squareSize, 3, 1, 6, 3, 27);
        fillEvenMagicSquareSimple(matrix, squareSize, 3, 4, 6, 6, 9);
    }
}

void fillEvenMagicSquareSimple(int **matrix, int squareSize, int inicialLine, int inicialColumn, int finalLinelength, int finalColumnLength, int count) {
    int cont = count;

    matrix[inicialLine][inicialColumn] = cont + 1;
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

        if (matrix[currentPositionLine][currentPositionColumn] == 0) {
            matrix[currentPositionLine][currentPositionColumn] = cont + 1;
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

            matrix[currentPositionLine][currentPositionColumn] = (cont + 1);
            cont++;
        }
    }
}

void fillOddSizeMagicBoard(int **matrix, int squareSize) {
    int cont = 0;

    matrix[0][(squareSize-1)/2] = cont + 1;
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

        if (matrix[currentPositionLine][currentPositionColumn] == 0) {
            matrix[currentPositionLine][currentPositionColumn] = cont + 1;
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

            matrix[currentPositionLine][currentPositionColumn] = (cont + 1);
            cont++;
        }
    }
}


int main()
{
    int squareSize;
    scanf("%d", &squareSize);

    int **matrix = alocarMatriz(squareSize);

    fillMatrix(matrix, squareSize);

    printf(" %d ", matrix[0][0]);printf(" %d ", matrix[0][1]);printf(" %d ", matrix[0][2]);printf(" %d ", matrix[0][3]);printf(" %d ", matrix[0][4]);printf(" %d ", matrix[0][5]);
    printf("\n %d ", matrix[1][0]);printf(" %d ", matrix[1][1]);printf(" %d ", matrix[1][2]);printf(" %d ", matrix[1][3]);printf(" %d ", matrix[1][4]);printf(" %d ", matrix[1][5]);
    printf("\n %d ", matrix[2][0]);printf(" %d ", matrix[2][1]);printf(" %d ", matrix[2][2]);printf(" %d ", matrix[2][3]);printf(" %d ", matrix[2][4]);printf(" %d ", matrix[2][5]);
    printf("\n %d ", matrix[3][0]);printf(" %d ", matrix[3][1]);printf(" %d ", matrix[3][2]);printf(" %d ", matrix[3][3]);printf(" %d ", matrix[3][4]);printf(" %d ", matrix[3][5]);
    printf("\n %d ", matrix[4][0]);printf(" %d ", matrix[4][1]);printf(" %d ", matrix[4][2]);printf(" %d ", matrix[4][3]);printf(" %d ", matrix[4][4]);printf(" %d ", matrix[4][5]);
    printf("\n %d ", matrix[5][0]);printf(" %d ", matrix[5][1]);printf(" %d ", matrix[5][2]);printf(" %d ", matrix[5][3]);printf(" %d ", matrix[5][4]);printf(" %d ", matrix[5][5]);

    return 0;
}
