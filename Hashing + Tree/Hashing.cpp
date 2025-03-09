#include <iostream>
#include <vector>
#include <list>
#include <algorithm> // Needed for std::find
using namespace std;

class Hashing{
    public:
    vector<list<int>> hashTable;
    int buckets;

    Hashing(int size){
        buckets = size ;
        hashTable.resize(size);
    }

    // * HASH VALUE

    int hashValue(int key){
        return key%buckets;
    }

    // * ADD 

    void addKey(int key){
        int idx = hashValue(key);

        hashTable[idx].push_back(key);
    }

    // * SEARCH

    list<int>::iterator search(int key){
        int idx = hashValue(key);
        return find(hashTable[idx].begin(),hashTable[idx].end(),key);
    }

    // * DELETE 

    void deleteKey(int key){ 
        int idx = hashValue(key);
        if(search(key)!=hashTable[idx].end()){
            hashTable[idx].erase(search(key));
            cout<<"Is Deleted";
        }else{
            cout<<"Not Found";
        }
    };

      

};

int main(){
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
};