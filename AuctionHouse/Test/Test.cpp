// AuctionHouse.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int removeInt(vector<int> *list, int choice);

int main()
{
	std::cout << "Hello World!\n";

	vector<int> list = { 10, 4, 7, 3, 5 };
	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << " ";

	cout << endl;
	removeInt(&list, 5);

	for (int i = 0; i < list.size(); i++)
		cout << list.at(i) << " ";
}

int removeInt(vector<int> *list, int choice) {
	auto it = find(list->begin(), list->end(), choice);

	if (it != list->end())
		cout << choice << " found. Remove from storage" << endl;
	else {
		cout << choice << " NOT found. Cancelling action" << endl;
		return choice;
	}

	int index = distance(list->begin(), it);
	cout << "Index is " << index << endl;
	int temp = list->at(index);
	list->erase(list->begin() + index);
	return temp;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file