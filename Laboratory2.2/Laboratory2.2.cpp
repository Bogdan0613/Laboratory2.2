#include<iostream>
#include<cmath>
using namespace std;
static void cin_check(int* x, int i) {
    if (!cin) {
        cout << "Bad value!";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter again:";
        cin >> x[i];
    }
}
static void extracted(int amount, int* coordinate1, int* coordinate2) {
    for (int i = 0; i < amount; i++) {
        cout << "Enter the x coordinate of the " << i + 1 << " top:";
        cin >> coordinate1[i];
        cin_check(coordinate1, i);
        cout << "Enter the y coordinate of the " << i + 1 << " top:";
        cin >> coordinate2[i];
        cin_check(coordinate2, i);
    }
}

int main() {
    int amount, max_y, max_x, length;
    float length_max;
    int x_middle, y_middle, is_cicle = 0;
    float radius;
    cout << "Enter the amount of the sides:";
    cin >> amount;
    int* coordinate1 = new int[amount];
    int* coordinate2 = new int[amount];
    extracted(amount, coordinate1, coordinate2);
    for (int i = 1; i < amount; i++) {
        coordinate1[0]; //беремо одну довільну точку та вимірюємо довжину до інших
        coordinate2[0];// найбільша довжина це й буде діагональ можливого кола
        length = (coordinate1[0] - coordinate1[i]) * (coordinate1[0] - coordinate1[i]) + (coordinate2[0] - coordinate2[i]) * (coordinate2[0] - coordinate2[i]);
        if (i == 0) {
            length_max = length;
            max_x = coordinate1[i];
            max_y = coordinate2[i];
        }
        if (length >= length_max) {
            length_max = length;
            max_x = coordinate1[i];
            max_y = coordinate2[i];
        }
    }
    x_middle = (max_x + coordinate1[0]) / 2; //координати імовірного центра описаного кола
    y_middle = (max_y + coordinate2[0]) / 2;
    for (int i = 1; i < amount; i++) {
        length = (coordinate1[i] - x_middle) * (coordinate1[i] - x_middle) + (coordinate2[i] - y_middle) * (coordinate2[i] - y_middle);
        if (length != length_max / 2) {//якщо довжини не співпадають то не можна описати коло
            cout << "This pollynom can't be outlined with any circle!";
            is_cicle = 0;
            break;
        }
        else {
            is_cicle = 1;
        }
    }
    if (is_cicle == 1) {
        cout << "The circle exists" << endl << "Coordinates of the circle center:";
        cout << "x=" << x_middle << endl << "y=" << y_middle;
        float a = 0.5;
        radius = pow(length_max, a);
        cout << "Radius=" << radius;
    }
}
