#include <iostream>

using namespace std;

char* CopyString(const char* str)
{
    int count = 0;
    while(str[count] != '\0')
    {
        ++count;
    }
    
    char* ptr = new char[count + 1];
    memcpy(ptr, str, count * sizeof(char));
    return ptr;
}

char* ConcatinateStrings(const char* a, const char* b)
{
    int len_a = 0;
    int len_b = 0;
    while(a[len_a] != '\0')
    {
        ++len_a;
    }
    while(b[len_b] != '\0')
    {
        ++len_b;
    }
    
    char* sum_str = new char[(len_a + len_b) * sizeof(char) + 1];
    
    for(int i = 0; i < len_a; ++i)
    {
        sum_str[i] = a[i];
    }
    
    for(int i = 0; i < len_b; ++i)
    {
        sum_str[len_a + i] = b[i];
    }
    
    sum_str[len_a + len_b + 1] = '\0';
    return sum_str;
}


int main()
{
    char str_a[]{'C', 'a', 'n', ' ', 'y', 'o', 'u', ' ', 'c', 'o', 'u', 'l', 'd', '\0'};
    char str_b[]{'C', 'a', 'n', ' ', 'y', 'o', 'u', ' ', 'c', 'o', 'u', 'l', 'd', '\0'};
    
    char* ptr = CopyString(str_a);

  for (int i = 0; i < 14; ++i)
    {
        cout << *(ptr + i);
    }
    cout << '\n';
    
    delete[] ptr;
    ptr = nullptr;
    
    char* ptr2 = ConcatinateStrings(str_a, str_b);
    
    for (int i = 0; i < 27; ++i)
    {
        cout << *(ptr2 + i);
    }
    cout << '\n';
    
  delete[] ptr2;
  ptr2 = nullptr;
    return 0;
}
