#include "Array.h"
#include <iostream>
using namespace std;

#ifndef __GRA__
#define __GRA__

template <typename T> // template으로 확장 
class GrowableArray : public Array<T>{ // Array클래스를 상속  
	protected :
        int low;
		int high;
		            
	public :
		GrowableArray();   
		GrowableArray(int size) : Array<T>(size) {//RangeArray와 같이 배열이 0부터 시작하지 않을 경우를 대비	
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
			T* temp; // 임시로 저장할 배열의 포인터  
			if (i > 2 * this->len) { //입력된 인덱스가 Range의 2배값보다 클 때 
				cout << "Array bound error!" << endl;
				return tmp;
			}
			else if (i > this->high) { //입력된 인덱스가 Range의 양의 방향으로 밖에 있을 때  
				temp = new T[this->len];
				for (j = 0; j < this->len; j++) { //원래 배열의 값을 임시 배열에 저장 
					temp[j] = this->data[j];
				}
				delete[] this->data; //원래 배열 메모리 해제 
				int size = this->len;
				this->len *= 2;
				this->data = new T[this->len]; //길이가 2배인 배열 생성 
				for (j = 0; j < this->len/2; j++) { //원래 배열 만큼 앞부분에 저장 
					this->data[j] = temp[j];
				}
				for (j=this->len/2; j < this->len; j++) {//그 뒤는 0으로 초기화 
					this->data[j] = 0;
				}
				this->high = this->low + this->len - 1;  
				return this->data[i-this->low];
			}
			else if (i < -(this->len*2)) { //입력된 인덱스가 음의 방향으로 Range의 2배값보다 작을 때 
				cout<< "Array bound error"<< endl;
				return tmp;
			}
			else if (i < this->low) { //입력된 인덱스가 Range의 음의 방향으로 밖에 있을 때 
				temp = new T[this->len];
				for (j = 0; j < this->len; j++) { //원래 배열의 값 임시배열에 저장 
					temp[j]= this->data[j];
				}
				delete[] this->data; //원래 배열 메모리 해제 
				int size = this->len;
				this->len *= 2;
				this->data = new T[this->len];//길이가 2배인 배열 생성 
				for (j=0; j<this->high-1; j++) {//앞부분을 0으로 초기화 
					this->data[j] = 0;
				}
				for(j=0; j <= size; j++) {//그 뒤에 원래 배열의 값 저장 
					this->data[j+this->high+1] = temp[j];
				}
				this->low = this->high - this->len + 1;
				return this->data[i-this->low];
				}
				else { //인덱스가 배열 내부에 있을 때 
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
		for (i = this->low; i <= this->high; i++) { //basevalue ~ endvalue까지 배열 값 출력 
			cout << this->data[i-this->low] << ", ";
		}
		cout << "\b\b]" << endl;
	}
};
#endif

