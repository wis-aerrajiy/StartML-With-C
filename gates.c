#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>

// activation function (i have no idea what this is yet)

float sigmoid(float x) {
    return (1.0f / (1.0f + expf(-x)));
}

// a freaking OR operation data 
const float train[][3] = {
    {0, 0, 0},
    {1, 0, 1},
    {0, 1, 1},
    {1, 1, 1},
};

const int train_count = (sizeof(train) / sizeof(train[0]));

float cost_function(float w1, float w2, float b)
{
    float result = 0.0f;
    for (size_t i = 0; i < train_count; ++i)
    {
        float x1 = train[i][0];
        float x2 = train[i][1];
        float y = sigmoid(x1 * w1 + x2 * w2 + b);
        float d = y - train[i][2];
        result += d * d;
    }

    result /= train_count;
    return (result);
}

float rand_float(void) {
    return (float)rand() / (float)RAND_MAX;
}

int main()
{
    srand(time(NULL));

    float w1 = rand_float() * 10.0f;
    float w2 = rand_float() * 10.0f;
    float b = rand_float() * 5.0f;

    float eps = 1.01;
    float rate = 1.01;

    for (size_t i = 0; i < 2000 * 1000; ++i)
    {
        float c   = cost_function(w1, w2, b);
        float dw1 = (cost_function(w1 + eps, w2, b) - c) / eps;
        float dw2 = (cost_function(w1, w2 + eps, b) - c) / eps;
        float db = (cost_function(w1, w2, b + eps) - c) / eps;

        w1 -= rate * dw1;
        w2 -= rate * dw2;
        b -= rate * db;

        printf("%f\n", c);
    }

    float x1 = 0;
    float x2 = 1;
    float y = sigmoid(x1 * w1 + x2 * w2 + b);
    printf("x1 : %f OR x2 = %f | y : %f\n", x1, x2, y);
}