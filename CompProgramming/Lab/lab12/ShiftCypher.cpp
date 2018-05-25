#include <iostream>
#include <string>

using namespace std;

int main() {
    string choice;
    cin >> choice;

    string object;
    cin >> object;

    int key;
    cin >> key;
    
    if (choice == "encrypt") {
        for (int i = 0; i < object.size(); i++) {
            object.at(i) = (object.at(i)+key) % 61;
        }
        cout << object << endl;
    } else if (choice == "decrypt") {
        for (int i = 0; i < object.size(); i++) {
            object.at(i) = (object.at(i)-key) % 61;
        }
        cout << object << endl;
    }

    return 0;
}
