
#include <iostream>
#include <random>
#include <chrono>
#include <ctime>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <conio.h>
#include <cstdlib>
using namespace std;

void shuffle_array(int arr[], int n, int size_array)      //shuffling our array
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();  //seed for shuffling. every compilation seed will be different
	shuffle(arr, arr + size_array, default_random_engine(seed));				//shuffling
}

// Driver code
int main()
{
	cout << "Welcome to the Memory game\n";										//Beginning
	int size_array, choice1, choice2, N = 1, attempts = 3;
	cout << "Enter the size of array(only even number from 6 to 20)\n";
	cout << "Size of array: ";
	cin >> size_array;
	cout << endl;
	cout << endl;
	if (size_array % 2 != 0||size_array<6)
	{
		cout << "Error, only even number\n";
		exit(0);
	}
	cout << "You also have 3 attempts\n";
	int a[20];
	string b[20];
	for (int i = 0; i < size_array; i += 2)
	{
		a[i] = N;
		a[i + 1] = N;
		N++;
	}
	for (int i = 0; i < size_array; i++)
	{
		b[i] = "?";
	}
	int n = sizeof(a) / sizeof(a[0]);
	shuffle_array(a, n, size_array);      //shuffling array
	string A[20];
	for (int i = 0; i < size_array; i++)
	{
		A[i] = to_string(a[i]);			//converting array to string type
	}
	cout << endl;
	for (int i = 0; i < size_array / 2; i++)	//main part of the game
	{
		cout << "Current array\n";
		for (int i = 0; i < size_array; i++)
		{
			cout << b[i] << " ";
		}
		cout << endl;
		cout << "Enter the index to show: ";
		cin >> choice1;								//turning up first card
		cout << endl;
		b[choice1 - 1] = A[choice1 - 1];
		for (int i = 0; i < size_array; i++)
		{
			cout << b[i] << " ";
		}
		cout << endl;
		cout << "Enter the index to show: ";
		cin >> choice2;								//turning up second card
		cout << endl;
		b[choice2 - 1] = A[choice2 - 1];
		for (int i = 0; i < size_array; i++)
		{
			cout << b[i] << " ";
		}
		cout << endl;
		if (b[choice1 - 1] != b[choice2 - 1])				//"if" for wrong answers
		{
			b[choice1 - 1] = "?";
			b[choice2 - 1] = "?";
			cout << "Cards do not match! Try again!\n";
			attempts--;
			cout << "Attempts left: " << attempts << endl;
			if (attempts == 0)								//condition for loosing
			{
				cout << "You have lost! Try again!\n";
				exit(0);
			}
		}
		cout << "Press Enter to continue...";				//clearing the screen
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cin.get();
		system("cls");
	}
	cout << endl;
	cout << "Congratulations!! You have won\n";
	return 0;
}
