#include <iostream>
#include "Matrix.h"
#include "SquareMatrix.h"

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
        arr = nullptr;
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
        else arr = nullptr;
    }
    ~MyStorage()
    {
        delete[] arr;
    }
    T& operator [] (int i)
    {
        if (i >= 0 && i < len) return arr[i];
    }
    void push_back(const T& element)
    {
        len += 1;
        T* tmp = new T[len];
        for (int i = 0; i < len; i++)
            tmp[i] = arr[i];
        tmp[len-1] = element;
        delete[] arr;
        arr = tmp;
    }
    void insert(const T& element, int pos)
    {
        len += 1;
        T* tmp = new T[len];
        for (int i = 0; i < pos; i++)
            tmp[i] = arr[i];
        tmp[pos] = element;
        for (int i = pos; i < len; i++)
            tmp[i+1] = arr[i];
        delete[] arr;
        arr = tmp;
    }
    void push_front(const T& element)
    {
        insert(element, 0);
    }
    void clear()
    {
        delete[] arr;
        arr = nullptr;
        len = 0;
    }
    void pop_back()
    {
        if (len != 0 && arr != nullptr) {
            len -= 1;
            T* tmp = new T[len];
            for (int i = 0; i < len; i++)
                tmp[i] = arr[i];
            delete[] arr;
            arr = tmp;
        }
        else return;
    }
    void erase(int pos)
    {
        if (len != 0 && arr != nullptr) {
            len -= 1;
            T* tmp = new T[len];
            for (int i = 0; i < pos; i++)
                tmp[i] = arr[i];
            for (int i = pos; i < len; i++)
                tmp[i] = arr[i+1];
            delete[] arr;
            arr = tmp;
        }
        else return;
    }
    int size()
    {
        return len;
    }
    T get(int index)
    {
        return arr[index];
    }
    void get_and_erase(int index)
    {
        cout << arr[index] << endl;;
        erase(index);
    }
    bool empty()
    {
        if (len == 0 || arr == nullptr) return true;
        else return true;
    }
};

SquareMatrix randSquareMatrix()
{
    srand(time(NULL));
    SquareMatrix tmp(1 + rand() % 5);
    tmp.random_fill();
    return tmp;
}

Matrix randMatrix()
{
    srand(time(NULL));
    Matrix tmp(1 + rand() % 5, 1 + rand() % 5);
    tmp.random_fill();
    return tmp;
} 

int main()
{
    srand(time(NULL));
    MyStorage <Matrix> storage(10);

    


}
