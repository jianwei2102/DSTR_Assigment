#pragma once
#include <iostream>
#include <string>

using namespace std;

class HashTable {
private:
    static const int SIZE = 10;  // Size of the hash table
    struct Node {
        string key;
        int value;
        Node* next;
    };
    Node* table[SIZE];  // Array of linked lists

    int hashFunction(const string& key) {
        int hash = 0;
        for (char c : key) {
            hash += c;
        }
        return hash;
    }

public:
    HashTable() {
        for (int i = 0; i < SIZE; ++i) {
            table[i] = nullptr;  // Initialize all buckets as empty
        }
    }

    void insert(const string& key) {
        int index = hashFunction(key) % SIZE;

        Node* curr = table[index];
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value++;  // If the node with the same key exists, increment its count and return
                return;
            }
            curr = curr->next;
        }

        // If the node with the key does not exist, create a new node and insert it at the end of the linked list
        Node* newNode = new Node;
        newNode->key = key;
        newNode->value = 1;
        newNode->next = nullptr;

        if (table[index] == nullptr) {
            table[index] = newNode;  // If the bucket is empty, insert the node
        }
        else {
            // If there are already nodes in the bucket, append the new node to the end
            Node* curr = table[index];
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    void remove(const string& key) {
        int index = hashFunction(key) % SIZE;
        Node* curr = table[index];
        Node* prev = nullptr;

        while (curr != nullptr) {
            if (curr->key == key) {
                if (curr->value > 1) {
                    curr->value--;  // Decrease the value if it is greater than 1
                }
                else {
                    if (prev == nullptr) {
                        table[index] = curr->next;  // If the node to be removed is the head of the linked list
                    }
                    else {
                        prev->next = curr->next;  // Link the previous node to the next node
                    }
                    delete curr;  // Delete the node if the value is 1
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        }
    }

    void displaySortedUnis() {
        const int MAX_UNIS = 1422;  // Maximum number of universities to handle
        string unis[MAX_UNIS];
        int counts[MAX_UNIS];
        int count = 0;

        for (int i = 0; i < SIZE; ++i) {
            Node* curr = table[i];
            while (curr != nullptr) {
                unis[count] = curr->key;
                counts[count] = curr->value;
                curr = curr->next;
                count++;
                if (count >= MAX_UNIS) {
                    cout << "Maximum number of universities reached. Some data may be truncated." << endl;
                    break;
                }
            }
        }

        // Bubble sort the unis based on their count values in descending order
        bool swapped;  // Flag to track swaps
        for (int i = 0; i < count - 1; ++i) {
            swapped = false;  // Initialize the flag
            for (int j = 0; j < count - i - 1; ++j) {
                if (counts[j] < counts[j + 1]) {
                    swap(unis[j], unis[j + 1]);
                    swap(counts[j], counts[j + 1]);
                    swapped = true;  // Set the flag if a swap is made
                }
            }

            if (!swapped) {
                break;  // If no swaps were made, the array is already sorted
            }
        }

        // Display top 10 sorted fav unis 
        for (int i = 0; i < 10; ++i) {

            if (unis[i] != "") {
                cout << " | " << left << setw(14) << unis[i];
                cout << left << setw(31) << counts[i] << right << "|" << endl;
            }
            else {
                cout << " | " << left << setw(14) << "";
                cout << left << setw(31) << "" << right << "|" << endl;
            }
        }
        cout << "  ---------------------------------------------- " << endl;
    }
};

