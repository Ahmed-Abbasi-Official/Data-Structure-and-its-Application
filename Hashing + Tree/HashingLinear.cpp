#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // Needed for std::find
using namespace std;

class Hashing
{
public:
    vector<list<int>> hashTable;
    int buckets;

    Hashing(int size)
    {
        buckets = size;
        hashTable.resize(size);
    }

    // * HASH VALUE

    int hashValue(int key)
    {
        return key % buckets;
    }

    // * ADD

    void addKey(int key)
    {
        int idx = hashValue(key);

        hashTable[idx].push_back(key);
    }

    // * SEARCH

    list<int>::iterator search(int key)
    {
        int idx = hashValue(key);
        return find(hashTable[idx].begin(), hashTable[idx].end(), key);
    }

    // * DELETE

    void deleteKey(int key)
    {
        int idx = hashValue(key);
        if (search(key) != hashTable[idx].end())
        {
            hashTable[idx].erase(search(key));
            cout << "Is Deleted";
        }
        else
        {
            cout << "Not Found";
        }
    };
};

// * CLOSED COLLISION ;

class Hash
{
public:
    int hashTable[10];

    Hash()
    {
        for (int i = 0; i < 10; i++)
        {
            hashTable[i] = -1;
        }
    };

    // * HASH VALUE FUNCTION

    int hashValue(int key)
    {
        return key % 10;
    }

    // * ADD KEY

    void addKey(int key)
    {
        int idx = hashValue(key);
        int i = 0;

        while (hashTable[idx] != -1)
        {
            idx = (idx + i) % 10;
            i++;
            if (idx == key % 10) {
                cout << "Hash table is full!" << endl;
                return;
            }
        }

        hashTable[idx] = key;
    }

    // * SEARCH

    void searchKey(int key)
    {
        int idx = hashValue(key);
        int i = 0;

        while( hashTable[idx] != key  )
        {
            if(idx == key%10)
            {
                cout << "Value is not Found";
                return;
            }
            idx = (idx + i) % 10;
            i++;
        }

        cout<<"Value Found at idx : "<<idx<<" "<<key<<endl;
    }


    // * DELETE

    void deleteKey(int key)
    {
        int idx = hashValue(key);
        int i = 0 ;

        while(hashTable[idx] != key)
        {
            if(idx == key%10)
            {
                cout<<"Value Not Found!"<<endl;
                return;
            };

            idx = (idx+i)%10;
            i++;

        }
            hashTable[idx]=-1;
    }

    // * DISPLAY

    void displayHashTable()
    {
        for (int i = 0; i < 10; i++)
        {
            cout << "Index : " << i << " " << hashTable[i] << endl;
            ;
        }
    }
};

int main()
{

    /*  SOLVE USING VECTOR

    Hashing hash(10);
    hash.addKey(12);
    hash.addKey(13);
    hash.addKey(14);
    hash.addKey(15);
    hash.addKey(16);
    hash.addKey(17);
    hash.addKey(18);
    hash.addKey(19);
    hash.addKey(20);
    hash.addKey(21);

    hash.search(16);
    cout<<"GOOD";

    */

    // * CLOSED COLLISION

    Hash h;

    h.addKey(12);
    h.addKey(23);
    h.addKey(34);
    h.addKey(35);
    h.addKey(36);
    h.addKey(37);
    h.addKey(38);
    h.addKey(39);
    h.addKey(40);
    h.addKey(41);

    h.searchKey(40);
    h.deleteKey(40);

    h.displayHashTable();
};