#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void)
{
    // print
    printf("This Program multiplies various matrices together\n\n");

    // create a function to multiply two NxN matrices together
    time_t t;

    // initialize random num generator
    srand((unsigned)time(&t));

    // Create Matrices of size N = 256, 512, and 1024
    int matrix_a_256[256][256];
    int matrix_b_256[256][256];
    int matrix_c_256[256][256];

    int matrix_a_512[512][512];
    int matrix_b_512[512][512];
    int matrix_c_512[512][512];

    int matrix_a_1024[1024][1024];
    int matrix_b_1024[1024][1024];
    int matrix_c_1024[1024][1024];

    //  create a smaller testing matrix
    int matrix_a_2[2][2];
    int matrix_b_2[2][2];
    int matrix_c_2[2][2];

    int N = 0;
    int mat_num = 0;

    // Assign the matrices with values randomly generated
    for (int z = 0; z < 2; z++)
    {
        switch (z)
        {
        case 0:
            N = 256;
            mat_num = 0;
            break;
        case 1:
            N = 512;
            mat_num = 1;
            break;
        case 2:
            N = 1024;
            mat_num = 2;
            break;

        case 3:
            N = 2;
            mat_num = 3;
            break;
        }

        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                // assign random nums
                if (mat_num == 0)
                {
                    matrix_a_256[i][j] = rand() % 10;
                    matrix_b_256[i][j] = rand() % 10;
                    matrix_c_256[i][j] = 0; // -- initialize to 0

                    //  multiply the two matrices together and store in c
                    // C = AB -> Cij = sum(from 0 - n-1) aik * bij
                    for (int k = 0; k < N; k++)
                    {
                        matrix_c_256[i][j] += matrix_a_256[i][k] * matrix_b_256[k][i];
                    }
                }
                else if (mat_num == 1)
                {
                    matrix_a_512[i][j] = rand() % 10;
                    matrix_b_512[i][j] = rand() % 10;
                    matrix_c_512[i][j] = 0; // -- initialize to 0

                    //  multiply the two matrices together and store in c
                    // C = AB -> Cij = sum(from 0 - n-1) aik * bij
                    for (int k = 0; k < N; k++)
                    {
                        matrix_c_512[i][j] += matrix_a_512[i][k] * matrix_b_512[k][i];
                    }
                }
                else if (mat_num == 2)
                {
                    matrix_a_1024[i][j] = rand() % 10;
                    matrix_b_1024[i][j] = rand() % 10;
                    matrix_c_1024[i][j] = 0; // -- initialize to 0

                    //  multiply the two matrices together and store in c
                    // C = AB -> Cij = sum(from 0 - n-1) aik * bij
                    for (int k = 0; k < N; k++)
                    {
                        matrix_c_1024[i][j] += matrix_a_1024[i][k] * matrix_b_1024[k][i];
                    }
                }
                else if (mat_num == 3)
                {
                    printf("-----Test Matrix C-----\n");
                    // TESTING BRANCH
                    matrix_a_2[i][j] = rand() % 10;
                    matrix_b_2[i][j] = rand() % 10;
                    matrix_c_2[i][j] = 0; // initialize to 0

                    // multiply through
                    for (int k = 0; k < N; k++)
                    {
                        matrix_c_2[i][j] += matrix_a_2[i][k] * matrix_b_2[k][i];
                        printf("matrix_c[%d][%d] = %d", i, j, matrix_c_2[i][j]);
                    }
                }
            }
        }
    }

    //   should have three matrices with products stored in them now
    return 0;
}