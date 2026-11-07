#include <iostream>
#include "PriorityQueue.h"

using namespace std;

int main() {

    PriorityQueue pq;
    int value;
    int choice;

    // Step 1: Build the initial Priority Queue
    cout << "====================================\n";
    cout << "       PRIORITY QUEUE - HW4\n";
    cout << "====================================\n";

    cout << "\nEnter positive integers to build the heap.\n";
    cout << "Enter -1 when finished.\n\n";

    while (true) {

        cout << "Enter a number: ";
        cin >> value;

        if (value == -1) {
            break;
        }

        if (value <= 0) {
            cout << "Please enter a positive integer or -1.\n";
            continue;
        }

        pq.insert(value);
    }

    cout << "\nInitial Priority Queue created!\n";
    pq.printArray();

    // Step 2: Display the menu
    do {

        cout << "\n====================================\n";
        cout << "          PRIORITY QUEUE MENU\n";
        cout << "====================================\n";
        cout << "1. Insert an item into the heap\n";
        cout << "2. Delete the minimum\n";
        cout << "3. Print the array representation\n";
        cout << "4. Exit\n";
        cout << "====================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                cout << "Enter a positive integer to insert: ";
                cin >> value;

                if (value > 0) {
                    pq.insert(value);

                    cout << value << " inserted successfully!\n";
                }
                else {
                    cout << "Please enter a positive integer.\n";
                }
                break;

            case 2:
                try {
                    value = pq.deleteMin();

                    cout << "Minimum value deleted: "
                         << value << endl;
                }
                catch (const underflow_error& e) {
                    cout << "Error: " << e.what() << endl;
                }
                break;

            case 3:
                cout << "\nArray Representation:\n";
                pq.printArray();
                break;

            case 4:
                cout << "\nExiting Priority Queue program.\n";
                cout << "Thank you for using HW4!\n";
                break;

            default:
                cout << "Invalid choice! Please select 1-4.\n";
        }

    } while (choice != 4);

    return 0;
}