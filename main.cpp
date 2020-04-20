#include "GrowableArray.h"
#include <iostream>
#include <string>
using namespace std;

int main(void) {

	cout << "GrowableArray<int> Test" << endl;
	GrowableArray<int> g(10);
	int i;
	for (i = 0; i < g.length(); i++) g[i] = 2 * i + 3;
	cout << "g(10)"; g.print();
	//g[-1] = -1; -> 이 명령문까지 하면 배열의 길이가 40이 된다. 
	g[13] = 13;
	g[16] = 16;
	cout << "g(20)"; g.print();


	cout << "GrowableArray<double> Test" << endl;
	GrowableArray<double> dg(10);
	//int i;
	for (i = 0; i < dg.length(); i++) dg[i] = 2.0 * i + 3.14;
	cout << "dg(10)"; dg.print();
	//dg[-1]=-1.11;
	dg[13] = 13.31;
	dg[18] = 19.22;
	cout << "dg(20)"; dg.print();


}
