#include <iostream>
#include "Matrix.h"
#include "SquareMatrix.h"
#include <time.h>
#include <iomanip>

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
    T get_and_erase(int index)
    {
        return get(index);
        erase(index);
    }
    bool empty()
    {
        if (len == 0 || arr == nullptr) return true;
        else return false;
    }
    void resize(int l)
    {
        len = l;
        T* tmp = new T[len];
        for (int i = 0; i < len; i++)
            tmp[i] = 0;
        delete[] arr;
        arr = tmp;
    }
};

int main()
{
    srand(time(NULL));
    clock_t start, end;
    MyStorage <Matrix*> storage(10);
    start = clock();
    for (int i = 0; i < 100; i++)
    {
        
        int random = rand() % 13;
        int rows = 1 + rand() % 7;
        int cols = 1 + rand() % 7;
        int n = 1 + rand() % 7;
        if (storage.size() == 0) storage.resize(10);
        int randpos = rand() % storage.size();
        switch (random)
        {
        case 0:
            cout << i << ". " << "insert Matrix at " << randpos <<endl;
            storage.insert(new Matrix(rows, cols), randpos);
            break;
        case 1:
            cout << i << ". " << "insert SquareMatrix at " << randpos << endl;
            storage.insert(new SquareMatrix(n), randpos);
            break;
        case 2:
            cout << i << ". " << "clear()" << endl;
            storage.clear();
            break;
        case 3:
            cout << i << ". " << "get() at " << randpos << " ";
            if (storage.get(randpos) != NULL) storage.get(randpos)->print();
            else cout << storage.get(randpos) << endl;
            break;
        case 4:
            cout << i << ". " << "get_and_erase() at " << randpos << " ";
            if (storage.get_and_erase(randpos) != NULL) 
                storage.get_and_erase(randpos)->print();
            else cout << storage.get_and_erase(randpos) << endl;
            break;
        case 5:
            cout << i << ". " << "pop_back()" << endl;
            storage.pop_back();
            break;
        case 6:
            cout << i << ". " << "push_back Matrix" << endl;
            storage.push_back(new Matrix(rows, cols));
            break;
        case 7:
            cout << i << ". " << "push_back SquareMatrix" << endl;
            storage.push_back(new SquareMatrix(n));
            break;
        case 8:
            cout << i << ". " <<"push_front SquareMatrix" << endl;
            storage.push_front(new SquareMatrix(n));
            break;
        case 9:
            cout << i << ". " << "push_front Matrix" << endl;
            storage.push_front(new Matrix(rows, cols));
            break;
        case 10:
            cout << i << ". ";
            if (storage[randpos] != NULL) {
                storage[randpos]->random_fill();
                cout << "random_fill()" << endl;
            }
            else cout << "random_fill isnt done, bc of NULL" << endl;
            break;
        case 11:
            cout << i << ". ";
            if (storage[randpos] != NULL) {
                cout << "transpose()" << endl;
                storage[randpos]->transpose().print();
                
            }
            else cout << "transpose isnt done, bc of NULL" << endl;
            break;
        case 12: 
            cout << i << ". ";
            if (storage[randpos] != NULL && storage[randpos]->type() == 2)
            {
                cout << "current pos " << randpos << "; ";
                cout << "determinant = " << storage[randpos]->determinant() << endl;

            }
            else cout << "determinant isnt done, bc of NULL" << endl;
            break;
        }
    }
    end = clock();
    for (int i = 0; i < storage.size(); i++)
    {
        if (storage[i] != NULL)
            cout << i << endl << *(storage[i]) << endl;
        else cout << i << " NULL" << endl;
    }
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
}
