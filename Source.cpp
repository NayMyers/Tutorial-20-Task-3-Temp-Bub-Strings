#pragma once
#include <iostream>
#include <string>
#include<fstream>
#include<vector>

#define WORDSFILE "words.txt"

using namespace std;

template<typename T>
class BubbleSort
{
private:
	vector<T> values;
	ifstream inputfile;
public:
	void addValue(T value);
	void displayValues(void);
	void sortValues(void);
	void loadWordsFromFile(string filename);
};

template <typename T>
void BubbleSort<T>::loadWordsFromFile(string filename)
{
	inputfile.open(WORDSFILE);//*****OOOOO
	int x = 0;
	string placeHolder = "";
	while (inputfile)
	{
		getline(inputfile, placeHolder);
		addValue(placeHolder);
		x++;
	}
	inputfile.close(); //*****CCCCC
}

template <typename T>
void BubbleSort<T>::addValue(T value)
{
	values.push_back(value);
}

template <typename T>
void BubbleSort<T>::displayValues(void)
{
	for (int x = 0; x < int(values.size()); x++)
	{
		cout << x << " =: " << values[x] << endl;
	}
}

template <typename T>
void BubbleSort<T>::sortValues(void)
{
	bool swap;
	T placeHolder = 0;
	do
	{
		swap = false;
		for (int x = 0; x < int(values.size() - 1); x++)
		{
			if (values[x] > values[x + 1])
			{
				placeHolder = values[x];
				values[x] = values[x + 1];
				values[x + 1] = placeHolder;
				swap = true;
			}
		}
	} while (swap);

}

void BubbleSort<string>::sortValues(void)
{
	bool swap;
	string placeHolder = "";
	do
	{
		swap = false;
		for (int x = 0; x< int(values.size() - 1); x++)
		{
			if (values[x].size() > values[x+1].size())
			{
				placeHolder = values[x];
				values[x] = values[x + 1];
				values[x + 1] = placeHolder;
				swap = true;
			}
		}
	} while (swap);
}

int main(void)
{
	int choice = 0;
	cout << "String or numbers? 1 string 2 numbers" << endl;
	cin >> choice;

	if (choice = 1)
	{
		BubbleSort<string> SortString;
		SortString.loadWordsFromFile(WORDSFILE);
		cout << "Display Values 1" << endl;
		SortString.displayValues();
		SortString.sortValues();
		cout << "Sorted Values" << endl;
		SortString.displayValues();
		cout << "END" << endl;
	}
	else
	{
		int amountToSort = 0;
		cout << "How many values do you want to enter into the vector? --> ";
		cin >> amountToSort;
		cout << endl;
		BubbleSort<double> Sort1;
		for (int x = 0; x < amountToSort; x++)
		{
			int value = 0;
			cout << "Enter value to add: ";
			cin >> value;
			cout << endl;
			Sort1.addValue(value);
		}

		Sort1.displayValues();
		cout << "DISPLAYED VALUES FIRST TIME" << endl;
		Sort1.sortValues();
		cout << endl;
		cout << "SORTED VALUES" << endl;
		cout << endl;
		Sort1.displayValues();
		cout << "DISPLAYED VALUES SECOND TIME" << endl;
	}




	return 0;
}