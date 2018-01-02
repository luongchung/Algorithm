#include <iostream>
using namespace std;
const int MAX = 100;
const int VC = 1000;
int n = 6, p = 0, q = 5;
int a[MAX][MAX] = {
	{  0,  5,  2, VC, VC, VC },
	{  5,  0,  2,  4,  7, VC },
	{  2,  2,  0,  2,  6, VC },
	{ VC,  4,  2,  0,  2,  1 },
	{ VC,  7,  6,  2,  0,  5 },
	{ VC, VC, VC,  1,  5,  0 },
};
int b[MAX], d[MAX];
bool c[MAX];

void printB() {
	cout << "B = ";
	for (int i = 0; i < n; i++)
		cout << b[i] << " ";
	cout << endl;
}

void dijkstra() {
	for (int i = 0; i < n; i++) b[i] = VC;
	b[p] = 0;
	for (int i = 0; i < n; i++) c[i] = false;
	c[p] = true;
	
	d[p] = -1;
	
	int k = p;
	printB();
	while (!c[q]) {
		for (int i = 0; i < n; i++)
			if (b[i] > (b[k] + a[k][i])) {
				b[i] = b[k] + a[k][i];
				d[i] = k;
			}
		printB();
		k = q;
		for (int i = 0; i < n; i++)
			if (!c[i])
				if (b[i] < b[k]) k = i;
		c[k] = true;
		cout << "Co dinh dinh " << k << endl;
	}
}

void induongdi(int q) {
	if (d[q] != -1) {
		induongdi(d[q]);
		cout << " ==> " << q;
	}
	else cout << q;
}

int main() {
	dijkstra();
	cout << "Duong di ngan nhat den " << q << " = " << b[q] << endl;
	induongdi(q);
}