#include <cstddef>
#include <iostream>
using namespace std;

template <typename K, typename V>
class HashNode {

    public:
        V value;
        K key;

        HashNode(K key, V value)
        {
            this->value = value;
            this->key = key;
        }

};


template <typename K, typename V>

class HashMap {
    HashNode<K, V> **arr; // what is this
    int capacity;
    int size;

    HashNode<K, V> * dummy;

    public: 
        HashMap() {
            capacity = 20;
            size = 0;

            arr = new HashNode<K, V> * [capacity];

            for(int i = 0; i < capacity; i++) {
                arr[i] = NULL;

            }

            dummy = new HashNode<K, V>(-1, -1);
        }

        //hash function
        int hashCode(K key) {
            return key % capacity;
        }

        // INSERT
        void insertNode(K key, V value) {

            HashNode<K, V> * temp = new HashNode<K, V>(key, value);
            int hashIndex = hashCode(key);

            while (arr[hashIndex] != NULL
                    && arr[hashIndex]->key != key
                    && arr[hashIndex]->key != -1) {
                        hashIndex++;
                        hashIndex %= capacity;
            }

            if(arr[hashIndex] == NULL || arr[hashIndex]->key == -1) {
                size++;
                arr[hashIndex] = temp;
            }
            
        }

        //DELETE 
        V deleteNode(int key) {
            int hashIndex = hashCode(key);

            while (arr[hashIndex] != NULL) {
                if(arr[hashIndex]->key == key) {
                    HashNode<K, V> * temp = arr[hashIndex];
                    arr[hashIndex] = dummy;
                    size--;
                    return temp->value;
                }
                hashIndex++;
                hashIndex %= capacity;
            
            
            }
            return NULL;
        }


        //GET VALUE
        V get(int key) {
            int hashIndex = hashCode(key);

            int counter = 0;

            while (arr[hashIndex] != NULL) {

                if(counter++ > capacity) {
                    return NULL;
                }

                if(arr[hashIndex]->key == key) {
                    return arr[hashIndex]->value;
                }

                hashIndex++;
                hashIndex %= capacity;
            
            }
            return NULL;
        }

        //SIZE
        int sizeofMap() {
            return size;
        }

        //CHECK EMPTY
        bool isEmpty() {
            return size == 0;
        }


        //DISPLAY HASHTABLE
        void display() {

            for(int i = 0; i < capacity; i++) {
                if(arr[i] != NULL && arr[i]->key != -1) {
                    cout << "Key = " << arr[i]->key;
                    cout << "value = ";
                    cout << arr[i]->value;
                    cout << endl;
                }
            }
        }
        
};


int main() {
    HashMap<int, int> *h = new HashMap<int, int>;
    h->insertNode(1, 1);
    h->insertNode(2, 2);
    h->insertNode(2, 3);
    h->display();
    cout << "size: " << h->sizeofMap() << endl;
    cout << "delete: " << h->deleteNode(2) << endl;
    cout << "size: " << h->sizeofMap() << endl;
    cout << "is empty: " << h->isEmpty() << endl;
    cout << "get: " << h->get(2) << endl;
    return 0;
}