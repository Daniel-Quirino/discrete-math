#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int max(int number1, int number2){
    return number1 > number2 ? number1 : number2;
}

void getNumbersWithSpace(char *numbersWithSpace){
    scanf("%[^\n]", numbersWithSpace);
    getchar();
}

int getLowerIndex(int *numbers, int maiorIndice) {
    int result=0, sequence=0, menorIndice = 0;

    for(int i=maiorIndice-1; i>=
    0; i--) {
        sequence = max(0,sequence+numbers[i]);
		result = max(result,sequence);

		menorIndice = (result == sequence) ? i : menorIndice;
    }
    return menorIndice;
}

int maxSum(int *numbers, int vectorSize){
	int result=0, sequence=0;
	int menorIndice = 0, maiorIndice = 0;

	for(int i=0;i<vectorSize;i++){

		sequence = max(0,sequence+numbers[i]);
		result = max(result,sequence);

        maiorIndice = (result == sequence) ? i : maiorIndice;
	}

	menorIndice = getLowerIndex(numbers, maiorIndice);

	printf("\nIndice: %d %d\n", menorIndice, maiorIndice);

	return result;
}


int main()
{
    int vectorSize;
    scanf("%d\n", &vectorSize);

    char numbersWithSpace[100];
    getNumbersWithSpace(numbersWithSpace);

    int *numbers = (int *) malloc(vectorSize * sizeof(int));
    char * token = strtok(numbersWithSpace, " ");

    int index = 0;
    while( token != NULL ) {
      numbers[index] = atoi(token);
      token = strtok(NULL, " ");

      index++;
    }

    printf("Soma: %d \n", maxSum(numbers, vectorSize));

    return 0;
}
