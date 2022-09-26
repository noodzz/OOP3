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
    int size()
    {
        return len;
    }
    T get(int index)
    {
        return arr[index];
    }
};

int main()
{
    MyStorage <int> m(10);
    m.push_back(1);
    cout << m.get(9) << endl;
    for (int i = 0; i < m.size(); i++)
        cout << m[i] << " ";

}
