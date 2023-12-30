#include <iostream>
using namespace std;

class IntCollection {

private:
  int size;
  int capacity;
  int *data;
  void addCapacity();

public:
  IntCollection();
  ~IntCollection();
  IntCollection(const IntCollection&);
  void add(int);
  int get(int);
  int getSize();
  IntCollection& operator=(const IntCollection&);
  bool operator==(const IntCollection&);
  IntCollection& operator>>(int);
  friend ostream& operator<<(ostream&, IntCollection&);
};

IntCollection::IntCollection() {
  size = 0;
  capacity = 1;
  data = new int[capacity]{0};
}

IntCollection::~IntCollection() {
  delete[] data;
}

IntCollection::IntCollection(const IntCollection& c) {
  size = c.size;
  capacity = c.capacity;
  data = new int[capacity];
  for (int i = 0; i < size; ++i) {
    data[i] = c.data[i];
  }
}

void IntCollection::addCapacity() {
  capacity *= 2;
  int* newData = new int[capacity];
  for (int i = 0; i < size; ++i) {
    newData[i] = data[i];
  }
  delete[] data;
  data = newData;
}

void IntCollection::add(int value) {
  if (size == capacity) 
    addCapacity();
  data[size] = value;
  size++;
}

int IntCollection::get(int index) {
  if (index >= getSize() || index < 0) {
    return -1;
  }
  else
    return data[index]; 
}

int IntCollection::getSize() { 
  return size; 
}

IntCollection& IntCollection::operator=(const IntCollection& c) {
  if (this != &c) {
    delete[] data;
    size = c.size;
    capacity = c.capacity;
    data = new int[capacity];
    for (int i = 0; i < size; ++i) {
      data[i] = c.data[i];
    }
  }
  return *this;
}

bool IntCollection::operator==(const IntCollection& c) {
  if (size != c.size) {
    return false;
  }
  for (int i = 0; i < size; ++i) {
    if (data[i] != c.data[i]) {
      return false;
    }
  }
  return true;
}

IntCollection& IntCollection::operator>>(int value) {
  add(value);
  return *this;
}

ostream& operator<<(ostream& out, IntCollection& c) {
  out << "{";
  for (int i = 0; i < c.size; ++i) {
    out << c.data[i];
    if (i < c.size - 1) {
      out << ", ";
    }
  }
  out << "}";
  return out;
}

int main() {

  // Don't change anything in the main function 
  IntCollection a, b, d;
  a.add(33);
  a.add(44);
  a.add(55);
  a.add(66);

  b >> 33 >> 44 >> 55 >> 66;

  if (a == b)
    cout << "The collections are equal.\n";
  else
    cout << "The collections are not equal.\n";
  
  b >> 77;
  if (a == b)
    cout << "The collections are equal.\n";
  else
    cout << "The collections are not equal.\n";

  a >> 77 >> 88 >> 99;

  IntCollection c = b;
  c >> 100;

  cout << "a = " << a;
  cout << "b = " << b;
  cout << "c = " << c;

  cout << "a[6] = " << a.get(6) << endl;
  cout << "b[2] = " << a.get(2) << endl;

  cout << "a.size = " << a.getSize() << endl;
  cout << "b.size = " << b.getSize() << endl;

  d = c = b = a;
  d >> 100;
  c >> 22;
  cout << a << b << c << d;

  cout << "c[0] = " << c.get(0) << endl;
  cout << "d[6] = " << d.get(6) << endl;
  cout << "d[-1] = "  << d.get(-1) << endl;
}
