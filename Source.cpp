#include<iostream>
#include "DNSRecord.h"
#include "DNSCache.h"
using namespace std;

int main()
{
	DNSCache p;
	DNSRecord q;
	int n;

	char* arr1 = new char[50];
	char* arr2 = new char[50];

	cout << "Input number of recordings: ";
	cin >> n;
	//n = 3;

	for (int i = 0; i < n; i++)
	{
		cin >> arr1 >> arr2;

		//cout << arr1 << arr2;
		q.setDomainName(arr1);
		q.setIP(arr2);

		p.add(q);
	}
	
	p.print();

	char a[] = "abc";
	if (p.lookup(a) != NULL) cout << "Returned IP: " << p.lookup(a) << endl;
	cout << endl;

	delete[] arr1;
	delete[] arr2;

	//system("pause");
	return 0;
}

//f10 pri debugger vsi4ko ot do
//f11 pri debugger markirana funkcia otiva na neq


//markira se funciq i f12 da se otide na neq