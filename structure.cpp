#include <iostream>
using namespace std;

// class declaration
class Array1D
{
private:
  int capacity;
  int size;
  int *array;

public:
  Array1D(int Arraycap = 10)
  {
    capacity = Arraycap;
    size = 0;
    array = new int[capacity];
  }

  // deletes the array for free memory allocation
  ~Array1D()
  {
    delete[] array; // free memory allocation
  }

  // returns the size of the array
  int Getsize()
  {
    return size;
  }

  // checks if array is empty
  bool isEmpty() const
  {
    return size == 0;
  }

  // checks if array is full
  bool isFull() const
  {
    return size == capacity; // returns size = capacity, meaning kung ano yung capacity yung lang limit ng size
  }

  // insert an item to the list
  void InsertItem(int pos, int val)
  {

    if (isFull()) // pag full na yung array, magrereturn ng true which display this block of code, else proceed
    {
      cout << "Cannot insert item. Array is full!" << endl;
      return;
    }

    if (pos < 0 || pos > size)
    {
      cout << "Invalid position!" << endl; // if less than 0 or more then the size, invalid yung irereturn
      return;
    }
    
    // Shift elements to the right
    for (int i = size; i > pos; i--)
    {
      array[i] = array[i - 1];
    }
    array[pos] = val;
    size++;
  }

  // removes an item from the list
  void RemoveItem(int pos)
  {
    if (isEmpty()) // pag empty na yung array, magrereturn ng true which display this block of code, else proceed
    {
      cout << "Cannot insert item. Array is empty!" << endl;
      return;
    }

    if (pos < 0 || pos > size)
    {
      cout << "Invalid position!" << endl; // if less than 0 or more then the size, invalid yung irereturn
      return;
    }
    for(int i = pos; i < size - 1; i++){
      array[i] = array[i + 1];
    }
    size--;
  }

  // adds an item from the list
  void AddItem(int val)
  {
    if (isFull()) // pag full na yung array, magrereturn ng true which display this block of code, else proceed
    {
      cout << "Cannot add item. Array is full!" << endl;
      return;
    }

    array[size] = val;
    size++;
  }

  // displays all of the elements
  void DisplayElements()
  {
    if (isEmpty()) {
            cout << "Array is empty!" << endl;
            return;
        }
        for (int i = 0; i < size; i++) {
            cout << array[i] << " ";
        }
        cout << endl;
  }

};
