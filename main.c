#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

float train[][2] = {
    {0, 0},
    {1, 2},
    {2, 4},
    {3, 6},
    {4, 8},
    // {5, 10},
};

const int train_count = (sizeof(train) / sizeof(train[0]));

float rand_float(void)
{
    return (float)rand() / (float)RAND_MAX;
}

float cost_fuction(float w, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i)
    {
        float x = train[i][0];
        float y = x * w + b; 
        float d = y - train[i][1];
        result += d * d;
    }

    result /= train_count;
    return (result);
}

int main()
{
    // f(x) = x * w;
    srand(time(NULL));

    // srand(0);

    float w = rand_float() * 10.0f;
    float b = rand_float() * 5.0f;

    float eps = 1e-3;
    float rate = 1e-3;
    for (size_t i = 0; i < 500 ; ++i)
    {
        float dw = (cost_fuction(w + eps, b) - cost_fuction(w, b)) / eps;
        float db = (cost_fuction(w, b + eps) - cost_fuction(w, b)) / eps;

        w -= rate * dw;
        b -= rate * db;
        printf("const  : %f | w : %f | b : %f\n", cost_fuction(w, b), w, b);
    }

    printf("w = %f | b = %f\n", w, b);
    return 0;
}

