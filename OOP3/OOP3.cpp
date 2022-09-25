#include <iostream>

using namespace std;

template <class T>
class MyStorage 
{
private:
    int len;
    T* arr;
public:
    MyStorage()
    {
        len = 0;
        arr = 0;
    }
    MyStorage(int l)
    {
        if (l > 0)
        {
            arr = new T[l];
            len = l;
            for (int i = 0; i < len; i++)
                arr[i] = 0;
        }
        else arr = 0;
    }
    ~MyStorage()
    {
        delete[] arr;
    }
    T& operator [] (int i)
    {
        if (i >= 0 && i < len) return arr[i];
    }
    void push_back(const T& el)
    {
        len += 1;
        T* tmp = new T[len];
        for (int i = 0; i < len; i++)
            tmp[i] = arr[i];
        tmp[len-1] = el;
        delete[] arr;
        arr = tmp;
    }
};

int main()
{
    MyStorage <int> m(10);
    m.push_back(1);
    for (int i = 0; i < 11; i++)
        cout << m[i];

}
