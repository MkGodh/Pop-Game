#include <iostream>
#include <vector>

using namespace std;

bool finish(bool bump[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (bump[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void bump_init(bool bump[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            bump[i][j] = true;
        }
    }

}

void bump_show(bool bump[12][12]) {
    for (int i = 0; i < 12; i++) {
        for (int j = 0; j < 12; j++) {
            if (bump[i][j]) {
                cout << "O" << " ";
            }
            else {
                cout << "X" << " ";
            }
        }
        cout << endl;
    }
}

void bump_pop(bool bump[12][12], int x1, int x2, int y1, int y2) {
    for (int i = x1; i <= x2; i++) {
        for (int j = y1; j <= y2; j++) {
            bump[i][j] = false;
            cout << "!POP! ";
        }
    }
}


int main()
{
    bool bump[12][12];
    int x1;
    int y1;
    int x2;
    int y2;
    bump_init(bump);

    cout << "Welcome to bump pop game. Iput regions for POP, from 0 to 11: " << "\n";


    while (!finish(bump)) {
        bump_show(bump);
        cout << "Pop from: " << "\n";
        cin >> x1 >> y1;
        cout << "To: " << "\n";
        cin >> x2 >> y2;
        if (x1 < 0 || x1 > 11 || x2 < 0 || x2 > 11 || y1 < 0 || y1 > 11 || y2 < 0 || y2 > 11) {
            cout << "invalid argumetns!";
            return 0;
        }
        bump_pop(bump, x1, x2, y1, y2);
        cout << "\n";
    }

    bump_show(bump);
    cout << "Thx for the game!";
}