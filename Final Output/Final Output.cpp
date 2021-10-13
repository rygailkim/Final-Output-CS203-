// Final Output.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int const arraySize = 10;

// general functions
int promptUserInput();
void getArrNumber(int arr[]);
void printArray(int arr[]);
bool promptUserYesNo();

// case 1 by Ryanne Gail Kim
int partition(int arr[], int start, int end, bool isAscending); 
void quicksort(int arr[], int start, int end, bool isAscending);

// case 2 by Jaime Lorenzo Cunanan
int linearSearch(int arr[]);

// case 3 by Mariselle Jelina Berones
void count(); 


int main()
{
    bool flag = true;
    int arr[arraySize] = { 0 };
    while (flag)
    {
        int input = promptUserInput();

        switch(input)
        {
            case 1:
                cout << "\nYou chose sorting. This program will sort an array of 10 integers.\n";
                getArrNumber(arr);
                cout << "\n=======================================================\n";
                cout << "Quick Sort\n";

                bool ascendingFlag;
                cout << "Do you want to sort in ascending order? [y/n] ";
                ascendingFlag = promptUserYesNo();

                quicksort(arr, 0, arraySize - 1, ascendingFlag);
                printArray(arr);
                break;
            case 2:
                cout << "\nYou chose searching. This program will search for the location of a chosen integer in an array of 10 integers.\n";
                getArrNumber(arr);
                cout << "\n=======================================================\n";
                cout << "Linear Search\n";
                linearSearch(arr);
                break;
            case 3:
                cout << "\nYou chose counting. This program will count the number of occurrences of each character in a string.\n";
                cout << "\nCount\n";
                count();
                break;
            default:
                cout << "Error";
        }

        cout << "\nDo you want to try again? [y/n]: ";
        flag = promptUserYesNo();
        cout << "\n=======================================================\n";
    }
}

int partition(int arr[], int start, int end, bool isAscending)
{
    int pivot = arr[end];
    int partIndex = start;
    for (int i = start; i < end; i++)
    {
        if (isAscending)
        {
            if (arr[i] <= pivot)
            {
                int temp = arr[i];
                arr[i] = arr[partIndex];
                arr[partIndex] = temp;

                partIndex++;
            }
        }
        else
        {
            if (arr[i] > pivot)
            {
                int temp = arr[i];
                arr[i] = arr[partIndex];
                arr[partIndex] = temp;

                partIndex++;
            }
        } 
    }

    int temp = arr[end];
    arr[end] = arr[partIndex];
    arr[partIndex] = temp;

    return partIndex;
}

void quicksort(int arr[], int start, int end, bool isAscending)
{    
    if (start < end)
    {
        int partIndex = partition(arr, start, end, isAscending);
        quicksort(arr, start, partIndex - 1, isAscending);
        quicksort(arr, partIndex + 1, end, isAscending);
    }
}

void count() {
    string om;
    char input[101];
    char check[sizeof(input)];
    int count[101] = { 0 };
    int i, j;
    string rar;

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Enter String Value: ";
    getline(cin, om);
    strcpy_s(input, om.c_str());
    strcpy_s(check, input);

    for (i = 0; i < strlen(input); i++) {
        count[i] = 0;
        for (j = 0; j < strlen(input); j++) {
            if (input[i] == input[j])
            {
                count[i] += 1;
            }
        }
    }

    for (i = 0; i < strlen(check); i++)
    {
        char c = check[i];
        for (int j = i + 1; j < strlen(check); j++)
        {
            if (c == check[j])
            {
                check[j] = ' ';
            }
        }
    }

    cout << "\n=======================================================\n";
    for (int i = 0; i < strlen(check); i++) {
        if (check[i] != ' ') {
            cout << "Number of " << check[i] << " = " << count[i] << endl;
        }
        else {}
    }
}

int linearSearch(int arr[])
{
    int numberToSearch;
    cout << "\n\nWhat number would you like to search for: ";

    while (true)
    {
        cin >> numberToSearch;
        if (!cin)
        {
            cout << "Invalid input. Please enter a valid integer: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        break;
    }

    for (int i = 0; i < 10; i++)
    {
        if (arr[i] == numberToSearch)
        {
            cout << "Element is present at index[" << i << "]" << endl;
            return 0;
        }
    }
    cout << "Element is not present in array" << endl;
    return -1;
}

int promptUserInput()
{
    string input;
    cout << "Please choose '1', '2', or '3': ";
    cin >> input;
    while (!cin.fail() && input != "1" && input != "2" && input != "3")
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Please choose '1', '2', or '3': ";
        cin >> input;
    }

    return stoi(input);
}


void getArrNumber(int arr[])
{
    int x = 0;
 
    for (int i = 0; i < arraySize; i++)
    {
        printf("Enter 10 integers (%i/%i): ", i + 1, arraySize);
        while (!(cin >> x))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        arr[i] = x;
    }

    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void printArray(int arr[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%i\t", arr[i]);
    }
    cout << "\n";
}

bool promptUserYesNo()
{
    string input;

    while (true)
    {
        cin >> input;
        transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input == "y" || input == "n")
        {
            return (input == "y") ? true : false;
        }
        cout << "Please enter 'y' or 'n' only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } 
}





