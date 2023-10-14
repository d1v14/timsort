#include <iostream>

using namespace std;

class stack {
public:
    int num;
    class stack* next;
};

class head {
public:
    class stack* top;
};

void push(int num, class head* head)
{
    class stack* element = new class stack;
    element->num = num;
    element->next = head->top;
    head->top = element;
}

string pop(class head* head, class stack* element)
{
    string line;
    line = element->num;
    head->top = element->next;
    delete(element);
    return line;
}


void insertionsort(int* array, int size)             // сортировка выборкой
{
    for (int i = 1; i <= size - 1; i++)
    {
        int num = array[i];
        int j = i - 1;

        while ((num < array[j]) && (j >= 0))
        {
            array[j + 1] = array[j];
            j = j - 1;
        }

        array[j + 1] = num;

    }
}




void mergeAlghoritm(int merged[], int leftArr[], int lenghtLeft, int rightArr[], int lenghtRight) {          // алгоритм для сортировки слиянием
    int firstCounter = 0;
    int secondCounter = 0;
    while (firstCounter < lenghtLeft || secondCounter < lenghtRight) {
        if (firstCounter < lenghtLeft & secondCounter < lenghtRight) {
            if (leftArr[firstCounter] <= rightArr[secondCounter]) {
                merged[firstCounter + secondCounter] = leftArr[firstCounter];
                firstCounter++;
            }
            else {
                merged[firstCounter + secondCounter] = rightArr[secondCounter];
                secondCounter++;
            }
        }
        else if (firstCounter < lenghtLeft) {
            merged[firstCounter + secondCounter] = leftArr[firstCounter];
            firstCounter++;
        }
        else if (secondCounter < lenghtRight) {
            merged[firstCounter + secondCounter] = rightArr[secondCounter];
            secondCounter++;
        }
    }
}

void mergesort(int array[], int length)         // разбиение для сортировки слиянием 
{
    if (length > 1) {
        int mid = length / 2;
        int rem = length - mid;
        int* L = new int[mid];
        int* R = new int[rem];
        for (int i = 0; i < length; i++) {
            if (i < mid) {
                L[i] = array[i];
            }
            else {
                R[i - mid] = array[i];
            }
        }
        mergesort(L, mid);
        mergesort(R, rem);
        mergeAlghoritm(array, L, mid, R, rem);
    }
}



void timsort(int array[], int length)       // реализация тимсорта
{
    int n = length;
    int r = 0;
    while (n >= 64)
    {
        r |= n & 1;
        n >>= 1;
    }
    for (unsigned int counter = 0; counter < length; counter += n + r)
        insertionsort(array, n + r);
    for (int size = n + r; size < length; size = 2 * size)
    {
        for (int left = 0; left < length; left += 2 * size)
        {
            int mid = left + size - 1;
            int right = min((left + 2 * size - 1), (length - 1));
            mergesort(array, length);
        }
    }
}

int main()
{
    int array[] = { 205, 2 ,-100 , 1 ,2 , 6, -5, 8, 2, 1, 205, 2 ,-100 };
    cout << "Initial array: " << endl;
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
        cout << array[i] << " ";
    timsort(array, sizeof(array) / sizeof(int));
    cout << endl << "Array after sorting:" << endl;
    for (int i = 0; i < sizeof(array) / sizeof(int); i++)
        cout << array[i] << " ";
    return 0;
}
