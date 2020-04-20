#include <iostream>
using namespace std;

#ifndef __ARRAY__
#define __ARRAY__
template <typename T> // template으로 확장 
class Array{
protected:
	T* data;
	int len;
public:
	Array(int size) {
		if (size <= 0) {
			cout << "error size >0" << endl;
		}
		else {
			data = new T[size];
			len = size;
		}
	}
	~Array() {
		delete[]data;
	}

	int length() const {
		return len;
	}

	T& operator[](int i) {
		static int tmp;
		if (i<0 || i>len - 1) {
			cout << "Array bound error!" << endl;
			return tmp;
		}
		else return data[i];
	}
	T operator[](int i)const {
		if (i<0 || i>len - 1) {
			cout << "Array bound error" << endl;
			return 0;
		}
		else return data[i];
	}

	void print() {
		int i;
		cout << "[";
		for (i = 0; i < len - 1; i++) {
			cout << data[i] << ' ';
		}
		cout << data[len - 1] << "]" << endl;
	}
};
#endif
