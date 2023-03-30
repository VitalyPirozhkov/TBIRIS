#include <chrono>
#include <iostream>
#include <algorithm>
int SIZE = 1200;


void clear_martix(int**& c)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            c[i][j] = 0;
        }
    }
}
void sequential_multiplication(int**& c, int**& a, int**& b)
{
    clear_martix(std::ref(c));
    auto m_StartTime = std::chrono::system_clock::now();
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++) 
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    auto m_EndTime = std::chrono::system_clock::now();
    std::cout << "sequential ijk " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms \n";

    clear_martix(std::ref(c));
    m_StartTime = std::chrono::system_clock::now();
    for (int i = 0; i < SIZE; i++)
    {
        for (int k = 0; k < SIZE; k++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    m_EndTime = std::chrono::system_clock::now();
    std::cout << "sequential ikj " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms\n";

    clear_martix(std::ref(c));
    m_StartTime = std::chrono::system_clock::now();
    for (int j = 0; j < SIZE; j++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    m_EndTime = std::chrono::system_clock::now();
    std::cout << "sequential jik " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms\n";

    clear_martix(std::ref(c));
    m_StartTime = std::chrono::system_clock::now();
    for (int j = 0; j < SIZE; j++)
    {
        for (int k = 0; k < SIZE; k++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    m_EndTime = std::chrono::system_clock::now();
    std::cout << "sequential jki " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms\n";

    clear_martix(std::ref(c));
    m_StartTime = std::chrono::system_clock::now();
    for (int k = 0; k < SIZE; k++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int i = 0; i < SIZE; i++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    m_EndTime = std::chrono::system_clock::now();
    std::cout << "sequential kji " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms\n";

    clear_martix(std::ref(c));
    m_StartTime = std::chrono::system_clock::now();
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    m_EndTime = std::chrono::system_clock::now();
    std::cout << "sequential kij " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms\n";
    clear_martix(std::ref(c));
}
void parallel_multiplication(int**& c, int**& a, int**& b)
{
    clear_martix(std::ref(c));
    auto m_StartTime = std::chrono::system_clock::now();
    #pragma omp parallel for
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            for (int k = 0; k < SIZE; k++)
            {
                c[i][j] += a[i][k] * b[k][j];   
            }
        }
    }
    auto m_EndTime = std::chrono::system_clock::now();
    std::cout << "parallel " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms\n";
    clear_martix(std::ref(c));
}


int main()
{
    srand(time(NULL));
    int** a, ** b, ** c;
    a = new int* [SIZE];
    for (int i = 0; i < SIZE; i++) 
    {
        a[i] = new int[SIZE];
        for (int j = 0; j < SIZE; j++) 
        {
            a[i][j] = rand();
        }
    }
    b = new int* [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        b[i] = new int[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            b[i][j] = rand();
        }
    }
    c = new int* [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        c[i] = new int[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            c[i][j] = 0;
        }
    }
    sequential_multiplication(std::ref(c), std::ref(a), std::ref(b));
    parallel_multiplication(std::ref(c), std::ref(a), std::ref(b));
}
