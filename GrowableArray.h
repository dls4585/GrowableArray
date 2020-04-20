#include "Array.h"
#include <iostream>
using namespace std;

#ifndef __GRA__
#define __GRA__

template <typename T> // template���� Ȯ�� 
class GrowableArray : public Array<T>{ // ArrayŬ������ ���  
	protected :
        int low;
		int high;
		            
	public :
		GrowableArray();   
		GrowableArray(int size) : Array<T>(size) {//RangeArray�� ���� �迭�� 0���� �������� ���� ��츦 ���	
			low = 0, high = size -1;
		}
		~GrowableArray() {
		
		}
		int baseValue(){
		        return this->low;
		}

		int endValue(){
		        return this->high;
		}
		int length() {
			return this->len;
		}
		T& operator[](int i) {
			static T tmp;
			int j;
			T* temp; // �ӽ÷� ������ �迭�� ������  
			if (i > 2 * this->len) { //�Էµ� �ε����� Range�� 2�谪���� Ŭ �� 
				cout << "Array bound error!" << endl;
				return tmp;
			}
			else if (i > this->high) { //�Էµ� �ε����� Range�� ���� �������� �ۿ� ���� ��  
				temp = new T[this->len];
				for (j = 0; j < this->len; j++) { //���� �迭�� ���� �ӽ� �迭�� ���� 
					temp[j] = this->data[j];
				}
				delete[] this->data; //���� �迭 �޸� ���� 
				int size = this->len;
				this->len *= 2;
				this->data = new T[this->len]; //���̰� 2���� �迭 ���� 
				for (j = 0; j < this->len/2; j++) { //���� �迭 ��ŭ �պκп� ���� 
					this->data[j] = temp[j];
				}
				for (j=this->len/2; j < this->len; j++) {//�� �ڴ� 0���� �ʱ�ȭ 
					this->data[j] = 0;
				}
				this->high = this->low + this->len - 1;  
				return this->data[i-this->low];
			}
			else if (i < -(this->len*2)) { //�Էµ� �ε����� ���� �������� Range�� 2�谪���� ���� �� 
				cout<< "Array bound error"<< endl;
				return tmp;
			}
			else if (i < this->low) { //�Էµ� �ε����� Range�� ���� �������� �ۿ� ���� �� 
				temp = new T[this->len];
				for (j = 0; j < this->len; j++) { //���� �迭�� �� �ӽù迭�� ���� 
					temp[j]= this->data[j];
				}
				delete[] this->data; //���� �迭 �޸� ���� 
				int size = this->len;
				this->len *= 2;
				this->data = new T[this->len];//���̰� 2���� �迭 ���� 
				for (j=0; j<this->high-1; j++) {//�պκ��� 0���� �ʱ�ȭ 
					this->data[j] = 0;
				}
				for(j=0; j <= size; j++) {//�� �ڿ� ���� �迭�� �� ���� 
					this->data[j+this->high+1] = temp[j];
				}
				this->low = this->high - this->len + 1;
				return this->data[i-this->low];
				}
				else { //�ε����� �迭 ���ο� ���� �� 
					return this->data[i-this->low];
				}
			}
	T operator[](int i)const{
		if (i < this->low || i >this->high) {
			cout << "Array bound error" << endl;
			return 0;
		}
		else return this->data[i-this->low];
	}
	void print() {
		int i;
		cout << "[";
		for (i = this->low; i <= this->high; i++) { //basevalue ~ endvalue���� �迭 �� ��� 
			cout << this->data[i-this->low] << ", ";
		}
		cout << "\b\b]" << endl;
	}
};
#endif

