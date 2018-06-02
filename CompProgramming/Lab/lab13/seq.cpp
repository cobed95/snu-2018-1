#include <iostream>
#include <fstream>

using namespace std;

int compare(int i, int j) {
    int result = i - j;
    if (result > 0) return 0;
    if (result < 0) return 1;
    if (result == 0) return 2;
}

int countLines(ifstream &fin) {
    cnt = 0;
    int buffer;
    while (fin >> buffer) {
        cnt++;
    }
    return cnt;
}

int main(int argc, char *argv[]) {
    ifstream fin("input.txt");
    int cnt = countLines(fin);
    
    ifstream newFin("input.txt");
    int numbers[cnt];
    for (int i = 0; i < cnt; i++) {
        newFin >> numbers[i];
    }

    int result = compare(numbers[0], numbers[1]);
    if (result == 0) {
        int i = 0;
        while (i < cnt-1 && numbers[i] < numbers[i+1])
            if (numbers[i] <= numbers[i-1]) {
                cout << "Ambiguous" << endl;
                break;
            }
        }
        cout << "Increasing" << endl;
    } else if (result == 1) {
        for (int i = 0; i < cnt-1; i++) {
            if (numbers[i] >= numbers[i+1]) {
                cout << "Ambiguous" << endl;
                break;
            }
        }
        cout << "Decreasing" << endl;
    } else if (result == 2) {
        for (int i = 0; i < cnt-1; i++) {
            if (numbers[i] != numbers[i+1]) {
                cout << "Ambiguous" << endl;
                break;
            }
        }
        cout << "Constant" << endl;
    }

    return 0;
}
