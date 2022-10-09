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
    void erase(int pos)
    {
        if (len != 0 && arr != nullptr) {
            len -= 1;
            T* tmp = new T[len];
            for (int i = 0; i < pos; i++)
                tmp[i] = arr[i];
            for (int i = pos; i < len; i++)
                tmp[i] = arr[i + 1];
            delete[] arr;
            arr = tmp;
        }
        else return;
    }
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
        else
        {
            arr = nullptr;
            len = 0;
        }
    }
    ~MyStorage()
    {
        delete[] arr;
    }
    T& operator [] (int i)
    {
        if (i >= 0 && i < len) return arr[i];
    }
    void addObject(const T& element, int pos)
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
    void setObject(const T& element, int pos)
    {
        if (pos >= 0 && pos < len)
            arr[pos] = element;
        else return;
    }
    int size()
    {
        return len;
    }
    T getObject(const int &index)
    {
        if (index >= 0 && index < len)
            return arr[index];
        else exit(-1);
    }
    T getObjectAndDelete(const int &index)
    {
        if (index >= 0 && index < len && empty() == false)
        {
            T tmp = getObject(index);
            erase(index);
            return tmp;
        }
        else exit(-1);

    }
    bool empty()
    {
        if (len == 0 || arr == nullptr) return true;
        else return false;
    }
    void resize(int l)
    {
        if (l <= 0)
        {
            l = 0;
            arr = nullptr;
        }
        else {
            len = l;
            T* tmp = new T[len];
            for (int i = 0; i < len; i++)
                tmp[i] = 0;
            delete[] arr;
            arr = tmp;
        }
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
        int randpos = rand() % storage.size();
        switch (random)
        {
        case 0:
            cout << i << ". " << "add Matrix at " << randpos <<endl;
            storage.addObject(new Matrix(), randpos);
            break;
        case 1:
            cout << i << ". " << "add SquareMatrix at " << randpos << endl;
            storage.addObject(new SquareMatrix(), randpos);
            break;
        case 2:
            cout << i << ". " << "add Matrix(rows, cols) at " << randpos << endl;
            storage.addObject(new Matrix(rows, cols), randpos);
            break;
        case 3:
            cout << i << ". " << "add SquareMatrix(n) at " << randpos << endl;
            storage.addObject(new SquareMatrix(n), randpos);
            break;
        case 4:
            cout << i << ". " << "set Matrix at " << randpos << endl;
            storage.setObject(new Matrix(), randpos);
            break;
        case 5:
            cout << i << ". " << "set SquareMatrix at " << randpos << endl;
            storage.setObject(new SquareMatrix(), randpos);
            break;
        case 6:
            cout << i << ". " << "set Matrix(rows, cols) at " << randpos << endl;
            storage.setObject(new Matrix(rows, cols), randpos);
            break;
        case 7:
            cout << i << ". " << "set SquareMatrix(n) at " << randpos << endl;
            storage.setObject(new SquareMatrix(n), randpos);
            break;
        case 8:
            cout << i << ". " <<"get object at " << randpos << endl;
            storage.getObject(randpos);
            break;
        case 9:
            cout << i << ". " << "get object and delete at " << randpos << endl;
            storage.getObjectAndDelete(randpos);
            break;
        case 10:
            cout << i << ". ";
            if (storage[randpos] != NULL) {
                storage[randpos]->random_fill();
                cout << "random_fill()" << endl;
            }
            else cout << "couldn't do random_fill(), storage[" <<
                randpos << "] == NULL" << endl;
            break;
        case 11:
            cout << i << ". ";
            if (storage[randpos] != NULL) {
                cout << "transpose()" << endl;
                storage[randpos]->transpose().print();
                
            }
            else cout << "couldn't do transpose(), storage[" <<
                randpos << "] == NULL" << endl;
            break;
        case 12: 
            cout << i << ". ";
            if (storage[randpos] != NULL && storage[randpos]->type() == 2)
            {
                cout << "current pos " << randpos << "; ";
                cout << "determinant = " << storage[randpos]->determinant() << endl;

            }
            else cout << "couldn't do random_fill(), storage[" <<
                randpos << "] == NULL or == Matrix" << endl;
            break;
        }
    }
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by program is : " << fixed
        << time_taken << setprecision(5);
    cout << " sec " << endl;
}

