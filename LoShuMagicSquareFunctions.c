#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//returns 1 if all the sums of the rows, columns, and diagonals add up to 15, 0 otherwise
int sums(int square[3][3]){
    int num;
    for (int i = 0; i < 3; i++)
    {
        int rowSum = 0;
        int columnSum = 0;
        for (int j = 0; j < 3; j++)
        {
            num = square[i][j];
            rowSum = rowSum + num;
            num = square[j][i];
            columnSum = columnSum + num;
        }
        if (rowSum != 15 || columnSum != 15) {
            return 0;
        }
    }
    if (square[0][0] + square[1][1] + square[2][2] != 15 && square[0][2] + square[1][1] + square[2][0] != 15){
        return 0;
    }
    return 1;
}

//returns 1 if every item in the square is unique, 0 otherwise
int unique(int square[3][3]){
    int array[9];
    int index = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            array[index] = square[i][j];
            index++;
        }
    }
    for (int i = 0; i < 9; i++)
    {
        int temp = array[i];
        for (int j = i + 1; j < 9; j++)
        {
            if (array[i] == array[j])
            {
                return 0;
            }
        }
    }
    return 1; 
}

int repeatChecker(int array[], int num, int size){
    for (int i = 0; i < size; i++)
    {
        if (num == array[i]){
            return 0;
        }
    }
    return 1;
}

int LoShuMagicSquareTest(int square[3][3]){
    int test1 = sums(square);
    int test2 = unique(square);
    if (test1 == 1 && test2 == 1){
        return 1;
    }
    else {
        return 0;
    }
}

void LoShuMagicSquare(){
    srand(time(NULL)); 
    int squareCount = 0; 
    int magicSquare[3][3];
    int true = 0;
    while (true == 0)
    {
        int array[9];
        int arrayIndex = 0;
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                int r = (rand() % 9) + 1;
                if (repeatChecker(array, r, arrayIndex) == 1){
                    magicSquare[i][j] = r;
                    array[arrayIndex] = r;
                    arrayIndex++;
                }
                else
                    j--;
            }
        }
        if (LoShuMagicSquareTest(magicSquare) == 1){
            printf("The amount of squares created was %d\n", squareCount);
            for (int i = 0; i < 3; i++)
            {
                printf("[");
                for (int j = 0; j < 3; j++)
                {
                    int temp = magicSquare[i][j];
                    printf("%d", temp);
                    if (j != 2){
                        printf(" ");
                    }
                }
                printf("]\n");
            }
            true = 1;
        }
        else {
            squareCount++;
            for (int i = 0; i < 9; i++)
            {
                array[i] = 0;
            }
        }
    }
    return;
}