#include <iostream>
#include <vector>
using namespace std;

// Struct for Entring key as integer and value as string
struct Entry{
    int key;
    string value;
};

// class for hash table
class HashTable{
    private:
        vector<Entry> *map;        // array of vectors, for chaning pupose of Entry datatype
        int size;

        // key can be any value, we have to apply an hash function on it
        int get_hash(int key){
            return key % size;
        }

    public:
        HashTable(){
            size = 10;
            map = new vector<Entry>[size]();      //array of empty vectors, small braces for initilization as null
        }

        // add function
        void add(int key, string value){
            int key_hash = get_hash(key);
            
            for(int i = 0; i < map[key_hash].size(); i++){
                if(map[key_hash][i].key == key){
                map[key_hash][i].value = value;  // key exists, update
                return;
                }
            }

            map[key_hash].push_back(Entry{key, value});  // key not found, insert
        }

        // remove function
        bool remove(int key){
            int key_hash = get_hash(key);

            // key not found
            if(map[key_hash].empty())
                return false;

            for(int i = 0; i < map[key_hash].size(); i++){
                if(map[key_hash][i].key == key){
                    // Removes the element at index i from the vector at map[key_hash]
                    // equilent to pop(i) in python
                    map[key_hash].erase(map[key_hash].begin()+ i);
                    return true;
                }
            }
            return false;
        }

        // get fun
        string get(int key){
            int key_hash = get_hash(key);

            // if that index is empty
            if(map[key_hash].empty())
                return "Key not found";

            // if key found, return it's value
            for(int i = 0; i < map[key_hash].size(); i++){
                if(map[key_hash][i].key == key)
                return map[key_hash][i].value;
            }

            // if key not found
            return "Key not found";
        }


        // print function
        void print(){
            for(int i = 0; i < size; i++){
                if(!map[i].empty()){
                    cout << "Bucket " << i << ": ";
                    for(int j = 0; j < map[i].size(); j++){
                        cout << "[" << map[i][j].key << " : " << map[i][j].value << "] ";
                    }
                    cout << endl;
                }
            }
            cout << endl;
        }
};

int main(){
    HashTable h;

    h.add(17, "seventeen");
    h.add(26, "twenty six");
    h.add(35, "thirty five");
    h.add(25, "twenty five");
    h.add(26, "twenty six updated");
    h.add(887, "large number, with repeated mod val");

    h.print();

    h.remove(25);
    h.print();

    cout << h.get(35) << endl;

    return 0;
}