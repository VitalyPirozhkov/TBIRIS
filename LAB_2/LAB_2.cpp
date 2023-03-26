#include <chrono>
#include <iostream>
#include <algorithm>
int SIZE = 2000;

void clear_martix(double**& c)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            c[i][j] = 0;
        }
    }
}
void sequential_multiplication(double**& c, double**& a, double**& b)
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
    std::cout << "sequential ijk " << std::chrono::duration_cast<std::chrono::milliseconds>(m_EndTime - m_StartTime).count() << " ms\n";

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




int main()
{
    double** a, ** b, ** c;
    a = new double* [SIZE];
    for (int i = 0; i < SIZE; i++) 
    {
        a[i] = new double[SIZE];
        for (int j = 0; j < SIZE; j++) 
        {
            a[i][j] = rand();
        }
    }
    b = new double* [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        b[i] = new double[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            b[i][j] = rand();
        }
    }
    c = new double* [SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        c[i] = new double[SIZE];
        for (int j = 0; j < SIZE; j++)
        {
            c[i][j] = 0;
        }
    }
    sequential_multiplication(std::ref(c), std::ref(a), std::ref(b));
}
