/*
mathematical solutions::

set table size
struct node for linked list

set hash function

functiont  insert(node* hash_table[], int elements)
function insertBestCase(node* hash_table[], int elements)
function insertWorstCase(node* hash_table[], int elements)

print eache function
*/

#include <iostream>
#include <ctime> 
#include <cstdlib>
#include <vector>

using namespace std;

const int table_size = 1000;

//hash linkedList node
struct node {
    int data;
    node* next;
};
// hash function ::
int hash_function(int key) {
    return key % table_size;
}
// insetr function ::

void insert(node* hash_table[], int elements) {
    clock_t start = clock();

    for (int i = 0; i < elements; ++i) {
        int randomNum = rand() % 1000 + 1;  // Generate a random number between 1 and 1000
        int index = hash_function(randomNum);

        node* newnode = new node;
        newnode->data = randomNum;
        newnode->next = nullptr;

        if (hash_table[index] == nullptr) {
            hash_table[index] = newnode;
        } else {
            node* current = hash_table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newnode;
        }
    }

    cout << endl;
    clock_t end = clock();
    double executionTime = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    cout << "Execution time for inserting (Average " << elements << " elements): " << executionTime << " Microseconds " << endl;
}


//state in insertion
//1- insert in the best case
void insertBestCase(node* hash_table[], int elements) {
    clock_t start = clock();

    for (int i = 0; i < elements; ++i) {
        int randomNum = i; 
        int index = hash_function(randomNum);

        node* newnode = new node;
        newnode->data = randomNum;
        newnode->next = nullptr;

        if (hash_table[index] == nullptr) {
            hash_table[index] = newnode;
        } 
    }

    cout << endl;
    clock_t end = clock();
    double executionTime = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    cout << "execution time for inserting (best case) " << elements << " elements: " << executionTime << " Microsecond " << endl;
}

 //2- insert in worst case
void insertWorstCase(node* hash_table[], int elements) {
    clock_t start = clock();
    int index = rand() % table_size; 

    for (int i = 0; i < elements; ++i) {
        int randomNum = rand() % 1000 + 1;
        int Kindex = hash_function(randomNum);
        if (Kindex != index) {
            i--;
            continue;
        }
        cout << randomNum << ", ";

        node* newnode = new node;
        newnode->data = randomNum;
        newnode->next = nullptr;

        if (hash_table[index] == nullptr) {
            hash_table[index] = newnode;
        } else {
            node* current = hash_table[index];
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newnode;
        }
    }

    cout << endl;
    clock_t end = clock();
    double executionTime = (static_cast<double>(end - start) / CLOCKS_PER_SEC) * 1000000;
    cout << "Execution time for inserting (worst case) " << elements << " elements: " << executionTime << " Microseconds " << endl;
}
// 3- the avreage state withe in same insert function 

//___________________________________________



// function to print the output 

void print(node* Hash_table[]) {
    for (int i = 0; i < table_size; ++i) {
        cout << i << " | ";
        node* current = Hash_table[i];
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    srand(time(nullptr)); // Seed the random number generator

    node* hash_table[table_size] = {nullptr};
    node* hash_table_Worst[table_size] = {nullptr};
    node* hash_table_Best[table_size] = {nullptr};

    cout << "Best case:" << endl;
    insertBestCase(hash_table_Best, 10);
    insertBestCase(hash_table_Best, 100);
    insertBestCase(hash_table_Best, 1000);
    print(hash_table_Best);

    cout << "Average case:" << endl;
    insert(hash_table, 10);
    insert(hash_table, 100);
    insert(hash_table, 1000);
    print(hash_table);

    cout << "Worst case:" << endl;
    insertWorstCase(hash_table_Worst, 10);
    insertWorstCase(hash_table_Worst, 100);
    insertWorstCase(hash_table_Worst, 1000);
    print(hash_table_Worst);

    
    return 0;
}
