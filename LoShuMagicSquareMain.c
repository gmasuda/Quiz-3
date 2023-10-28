#include <stdio.h>
#include <stdlib.h>

int main(void){
    int LoShuMagicSquareTest(int square[3][3]);
    int sums(int square[3][3]);
    int unique(int square[3][3]);
    void LoShuMagicSquare();
    int squareTest[3][3] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    int test = LoShuMagicSquareTest(squareTest);
    if (test == 1){
        printf("This is a Lo Shu Magic Square\n"); 
    }
    else{
        printf("This is NOT a Lo Shu Magic Square\n");
    }
    LoShuMagicSquare();

    return EXIT_SUCCESS;
}
//command to run code gcc LoShuMagicSquareMain.c LoShuMagicSquareFunctions.c
