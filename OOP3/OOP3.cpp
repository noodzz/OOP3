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
    T begin()
    {
        return arr[0];
    }
    T end()
    {
        return arr[len - 1];
    }
    T* next(T* it)
    {
        T* ptr = it + 1;
        return ptr;
    }
    T* next(T* it, int n)
    {
        T* ptr = it + n;
        return ptr;
    }
    T* prev(T* it)
    {
        if (it != 0)
        {
            T* ptr = it - 1;
            return ptr;
        }
    }
    T* prev(T* it, int n)
    {
        if (it - n >= 0) {
            T* ptr = it - n;
            return ptr;
        }
    }
};

int main()
{
    MyStorage <int> m(10);
    m.push_back(1);
    m.push_front(2);
    m[5] = 5;
    cout << m.end();

}
