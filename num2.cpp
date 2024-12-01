#include <iostream>
#include <random>

using namespace std;

struct Matrix{
    int** data = nullptr;
    unsigned int m; // количество строк
    unsigned int n; // количество столбцов
};

void Construct(Matrix& out, unsigned int m, unsigned int n) // в условии ошибка, матрица с n столбцами и m строками это матрица m x n, а не n x m
{
    // инициализирует матрицу
    out.data = new int*[m]; // создает количество строк-матриц
    for(int i = 0; i < m; ++i)
    {
        out.data[i] = new int[n]; // инициализирует строки матрицы
    }
    
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            out.data[i][j] = 0;
        }
    }
}

void Destruct(Matrix& in) // очищает память
{
    if(in.data != nullptr)
    {
        for(int i = 0; i < in.m; ++i)
        {
            delete[] in.data[i];
        }
        delete[] in.data;
        in.data = nullptr;
    }
}

Matrix Copy(const Matrix& matrix)
{
    Matrix copy;
    copy.m = matrix.m;
    copy.n = matrix.n;
    copy.data = new int*[copy.m]; // создает количество строк-матриц
    for(int i = 0; i < copy.m; ++i)
    {
        copy.data[i] = new int[copy.n]; // инициализирует строки матрицы
    }
    
    for(int i = 0; i < copy.m; ++i)
    {
        for(int j = 0; j < copy.n; ++j)
        {
            copy.data[i][j] = matrix.data[i][j];
        }
    }
    return copy;
}

Matrix Add(const Matrix& matrix_A, const Matrix& matrix_B)
{
    Matrix sum;
    if(matrix_A.m != matrix_B.m or matrix_A.n != matrix_B.n) // если не выполннено условие сложения
    {
        cerr << "operation of adding is not available. matrix dimension is not coinside" << '\n';
        return sum;
    }
    sum.m = matrix_A.m;
    sum.n = matrix_A.n;
    
    sum.data = new int*[sum.m]; // инициализируем
    for(int i = 0; i < sum.m; ++i)
    {
        sum.data[i] = new int[sum.n];
    }
    
    for(int i = 0; i < sum.m; ++i)
    {
        for(int j = 0; j < sum.n; ++j)
        {
            sum.data[i][j] = matrix_A.data[i][j] + matrix_B.data[i][j];
        }
    }
    return sum;
}

Matrix Sub(const Matrix& matrix_A, const Matrix& matrix_B) // разность матриц А - B
{
    Matrix sub;
    if(matrix_A.m != matrix_B.m or matrix_A.n != matrix_B.n) // если не выполннено условие сложения
    {
        cerr << "operation of subtraction is not available. matrix dimension is not coinside" << '\n';
        return sub;
    }
    sub.m = matrix_A.m;
    sub.n = matrix_A.n;
    
    sub.data = new int*[sub.m]; // инициализируем
    for(int i = 0; i < sub.m; ++i)
    {
        sub.data[i] = new int[sub.n];
    }
    
    for(int i = 0; i < sub.m; ++i)
    {
        for(int j = 0; j < sub.n; ++j)
        {
            sub.data[i][j] = matrix_A.data[i][j] - matrix_B.data[i][j];
        }
    }
    return sub;
}

Matrix Multi(const Matrix& a, const Matrix& b) // A * B
{
    Matrix multi;
    if (a.n != b.m) // если не выполннено условие произведения
    {
        cerr << "operation of multiple is not available. 'A' matrix-rows dimension is not coinside with 'B' matrix-columns dimesion" << '\n';
        return multi;
    }
    multi.m = a.m;
    multi.n = b.n;
    
    Construct(multi, multi.m, multi.n);
    
    for(int i = 0; i < multi.m; ++i) // умножение матриц A * B и вывод получившейся матрицы
    {
        for(int j = 0; j < multi.n; ++j)
        {
            for(int k = 0; k < a.n; ++k)
            {
                multi.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return multi;
}

Matrix Transposition(Matrix& old)
{
    Matrix matrix;
    matrix.m =old.n;
    matrix.n = old.m;
    matrix.data = new int*[matrix.m];
    for(int i = 0; i < matrix.m; ++i)
    {
        matrix.data[i] = new int[matrix.n];
    }
    
    for(int i = 0; i < matrix.m; ++i)
    {
        for(int j = 0; j < matrix.n; ++j)
        {
            matrix.data[i][j] = old.data[j][i];
        }
    }
    
    return matrix;
}

bool operator==(const Matrix& a, const Matrix& b)
{
    if(a.m == b.m and a.n == b.n)
    {
        for(int i = 0; i < a.m; ++i)
        {
            for(int j = 0; j < a.n; ++j)
            {
                if(a.data[i][j] != b.data[i][j]) return 0;
            }
        }
        return 1;
    } else return 0;
}

Matrix RandConstruct(unsigned int m, unsigned int n) // создает матрицу с рандомными значениями
{
    Matrix matrix;
    matrix.n = n;
    matrix.m = m;
    matrix.data = new int*[m];
    for(int i = 0; i < m; ++i)
    {
        matrix.data[i] = new int[n];
    }
    
    for(int i = 0; i < m; ++i)
    {
        for(int j = 0; j < n; ++j)
        {
            matrix.data[i][j] = rand() % 5;
        }
    }
    return matrix;
}

void MatrixView(Matrix& matrix) // выводит матрицу в терминале
{
    for(int i = 0; i < matrix.m; ++i)
    {
        for(int j = 0; j < matrix.n; ++j)
        {
            cout << matrix.data[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}


int main()
{
    Matrix A;
    Matrix B;
    
    A = RandConstruct(10, 8);
    B = RandConstruct(10, 8);
    
    cout << "матрица A" << '\n';
    MatrixView(A);
    cout << "матрица B" << '\n';
    MatrixView(B);
    
    Matrix add = Add(A, B); // Сумма
    if(add.data != nullptr)
    {
        cout << "Сумма матриц A и B" << '\n';
        MatrixView(add);
    }
    
    Matrix sub = Sub(A, B); // Разность
    if(sub.data != nullptr)
    {
        cout << "Разность матриц A и B" << '\n';
        MatrixView(sub);
    }
    
    Matrix multi = Multi(A, B); // Произведение
    if(multi.data != nullptr)
    {
        cout << "Произведение матриц A и B" << '\n';
        MatrixView(multi);
    }
    
    Matrix transpon = Transposition(B); // Транспонирование
    if(transpon.data != nullptr)
    {
        cout << "Транспонированная B" << '\n';
        MatrixView(transpon);
    }

    Destruct(A);
    Destruct(B);
    Destruct(add);
    Destruct(sub);
    Destruct(multi);
    Destruct(transpon);
    
    return 0;
}

