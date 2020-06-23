// listspractice.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "QueType.h"
#include <iostream>
using namespace std;


int main()
{
	char Item;
	QueType<char> q;
	q.Enqueue('A');
	q.Enqueue('B');
	q.Enqueue('C');
	q.Dequeue(Item);
	cout << "Removed " << Item << endl;
	q.Enqueue('D');
	q.Dequeue(Item);
	cout << "Removed " << Item << endl;
	q.Enqueue('E');
	q.Enqueue('F');
	q.Print(Item); 	// the code for this function is missing
// This function will print the contents of 
// the queue
	char target;
	cout << "Enter a value to search for in the Queue : ";
	cin >> target;
	if (q.SearchQ(target) == true)
		cout << "Found " << target;
	else
		cout << target << "Not Found ";

	return 0;
}


