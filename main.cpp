#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;


vector<string> getAnimalNameFromFile(string fileName);

void linearSearch(vector<string> arr, string item);

void binarySearch(vector<string> arr, string item);

int main()
{

    vector<string> animals = getAnimalNameFromFile("animals.txt");

    string animal;
    cout << "Enter an animal name: ";
    getline(cin, animal);



    linearSearch(animals, animal);
    binarySearch(animals, animal);




}

vector<string> getAnimalNameFromFile(string fileName)
{
    ifstream file;
    file.open("./animals.txt");


    vector<string> animals;


    string animal;
    while (getline(file,animal))
    {
        animals.push_back(animal);
    }
    

    return animals;
}



void linearSearch(vector<string> arr, string item)
{
    int index = 0;
    int n = 0;
    bool isFound = false;

    while (n < arr.size() - 1 && !isFound)
    {
        cout << n << endl;
        n++;
        if (arr[index] == item)
        {
            isFound = true;
            break;
        }

        index++;

        
    }

    if (isFound == true)
    {
        cout << "The item, " << item << ", was found at the index " << index << " after " << n << " tries" << endl;
    }
    else
    {
        cout << "The item, " << item << ", was not found after " << n << " tries" << endl;
    }

}


void binarySearch(vector<string> arr, string item)
{
    int n = 0;
    int rightIndex = arr.size() - 1;

    int leftIndex = 0;


    int middleIndex = (leftIndex + rightIndex) / 2;


    bool isFound = false;
    while (!isFound && n < arr.size() - 1)
    {
        cout << n << endl;
        // cout << middleIndex << endl;
        n++;

        if (arr[middleIndex] == item)
        {
            isFound = true;
        }

        else if (arr[middleIndex] > item)
        {
        rightIndex = middleIndex - 1;

        
        }
        else
        {
        leftIndex = middleIndex + 1;
        }

        middleIndex = (rightIndex + leftIndex) / 2;

        // cout << "Left: " << leftIndex << " and Right: " << rightIndex << endl;

  
    }


    if (isFound == true)
    {
        cout << "The item, " << item << ", was found at the index " << middleIndex << " after " << n << " tries" << endl;
    }
    else
    {
        cout << "The item, " << item << ", was not found after " << n << " tries" << endl;
    }

}