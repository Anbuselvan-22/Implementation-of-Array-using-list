#include<iostream>
using namespace std;

#define Maxsize 50
int arr[Maxsize];
int arrsize = 0;

void insertAtEnd(int no) {
    if (arrsize == Maxsize) {
        cout << "Array is Full\n";
        return;
    }
    arr[arrsize++] = no;
    cout<<"Inserted succesfully";
}

void insertAtSpec(int pos, int no) {
    if (arrsize == Maxsize) {
        cout << "Array is Full\n";
        return;
    }
    if (pos < 0 || pos > arrsize) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = arrsize - 1; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }
    arr[pos] = no;
    arrsize++;
    cout<<"Inserted at spec pos done succesfully";
}

void deleteAtPos(int pos) {
    if (arrsize == 0) {
        cout << "Array is Empty\n";
        return;
    }
    if (pos < 0 || pos >= arrsize) {
        cout << "Invalid position\n";
        return;
    }
    for (int i = pos; i < arrsize - 1; i++) {
        arr[i] = arr[i + 1];
    }
    arrsize--;
    cout<<"Delected succesfully";
}

void display() {
    if (arrsize == 0) {
        cout << "Array is Empty\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < arrsize; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int ch;
    while (true) {
        cout << "\n------------------ Array Implementation ------------------\n";
        cout << "1. Insert at End\n2. Insert at specified position\n3. Delete at specified position\n4. Display\n5. Exit\n";
        cout << "Enter your Choice: ";
        cin >> ch;

        if (cin.fail()) {
            cout << "Invalid input. Exiting.\n";
            break;
        }

        switch (ch) {
            case 1: {
                int no;
                cout << "Enter the number: ";
                cin >> no;
                insertAtEnd(no);
                break;
            }
            case 2: {
                int no, pos;
                cout << "Enter the number: ";
                cin >> no;
                cout << "Enter the position(0-49): ";
                cin >> pos;
                insertAtSpec(pos, no);
                break;
            }
            case 3: {
                int pos;
                cout << "Enter the position to delete: ";
                cin >> pos;
                deleteAtPos(pos);
                break;
            }
            case 4:
                display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid Choice\n";
        }
    }
    return 0;
}
