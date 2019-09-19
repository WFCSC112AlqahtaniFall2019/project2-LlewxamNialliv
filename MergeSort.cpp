//project: mergesort
//author: Zexuan Huang
//course: CSC 112
//professor: Sarra Alqahtani

#include <iostream>
#include <vector>
#include <assert.h>
using namespace std;

// function declarations
void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right);
void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right);

int main() {

    // get input: first is random seed, second is vector length
    int seed, length;
    cout << "Please enter the seed for this run:";
    cin >> seed;
    cout << "Please enter the desired vector length:";
    cin >> length;
    srand(seed);

    vector<int> v(length);  // vector to be sorted
    vector<int> t(length);  // temporary workspace

    // unit test for merge
    vector<int> test = {0, 2000, -30, 726}; //test vector
    vector<int> expected = {-30, 0, 726, 2000};
    cout << endl << "Testing started" << endl;
    cout << "{0, 2000, -30, 726}, expecting {-30, 0, 726, 2000}, got:"; //print expected output

    mergeSortedLists(test, expected, 0, (test.size() - 1)/2, (test.size() - 1));
    for(int i = 0; i < test.size(); i++) {
        cout << test.at(i) << '\t';
    }
    cout << endl; //print test output

    for(int i = 1; i < test.size(); i++) { //check test vector using assert
        assert(test.at(i-1) == expected.at(i-1));
    }
    cout << "Test passed." << endl << endl;

    // initialize and print input
    cout << "Initial values of the vector:" << endl;
    for(int i = 0; i < v.size(); i++) {
        v.at(i) = rand() % 100;
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // sort v
    mergeSort(v, t, 0, (v.size() - 1));

    // print output
    cout << "Sorted vector is:" << endl;
    for(int i = 0; i < v.size(); i++) {
        cout << v.at(i) << '\t';
    }
    cout << endl;

    // check output, make sure it's sorted
    for(int i = 1; i < v.size(); i++) {
        assert(v.at(i-1) <= v.at(i));
    }

    return 0;
}

void mergeSort(vector<int>& a, vector<int>& tmp, int left, int right){
    int middle = (right + left)/2;

    if(left < right){
        mergeSort(a,tmp, left, middle);
        mergeSort(a, tmp,middle + 1, right); //divide vectors

        mergeSortedLists(a, tmp, left, middle, right); //merge vectors
    }
    else{ //base case of vector length 1
        return;
    }
}

void mergeSortedLists(vector<int>& a, vector<int>& tmp, int left, int middle, int right){
    int i, j, k; //variables for for loops
    int LeftSize = middle - left + 1;
    int RightSize = right - middle; //Size of temporary vectors

    int Left[LeftSize];
    int Right[RightSize]; //declare temporary vectors

    //copy data to temporary vectors
    for (i = 0; i < LeftSize; i++){
        Left[i] = a[left + i];
    }
    for (j = 0; j < RightSize; j++){
        Right[j] = a[middle + 1 + j];
    }

    i = 0; // Initial index of first temporary vector
    j = 0; // Initial index of second temporary vector
    k = left; // Initial index of merged vector

    //assign merged vector with elements from both temporary vectors sorted by magnitude ascending
    while (i < LeftSize && j < RightSize)
    {
        if (Left[i] <= Right[j])
        {
            a[k] = Left[i];
            i++;
        }
        else
        {
            a[k] = Right[j];
            j++;
        }
        k++;
    }

    while (j < RightSize) // if the Left temporary vector is reached to end first
    {
        a[k] = Right[j];
        j++;
        k++;
    }

    while (i < LeftSize) // if the Right temporary vector is reached to end first
    {
        a[k] = Left[i];
        i++;
        k++;
    }
}

