#include<iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 3;


void displayMenu(int studentID);
void costSlab1(int electricityMatrix[ROWS][COLS]);
void costSlab2(int electricityMatrix[ROWS][COLS]);
void costSlab3(int electricityMatrix[ROWS][COLS]);

int main() {
    
    int electricityMatrix[ROWS][COLS] = {
        {55, 65, 75},
        {120, 150, 170},
        {210, 230, 240}
    };

   
    int studentID =1234578;

    char choice;

    do {
        displayMenu(studentID);

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                costSlab1(electricityMatrix);
                costSlab2(electricityMatrix);
                break;
            case '2':
                costSlab3(electricityMatrix);
                break;
            default:
                std::cout << "Exiting the program.\n";
                break;
        }

    } while (choice == '1' || choice == '2');

    return 0;
}

void displayMenu(int studentID) {
    cout << "Student ID: " << studentID << "\n";
    cout << "1. Display the bill of slab 1 and slab 2.\n";
   cout << "2. Display the bill of slab 3.\n";
 cout << "Press any other key to exit.\n";
}

void costSlab1(int electricityMatrix[ROWS][COLS]) {
    int slab1Units = electricityMatrix[0][0];
    int slab2Units = electricityMatrix[0][1];

    int slab1Cost = slab1Units * 10;
    int slab2Cost = slab2Units * 15;

    cout << "Cost for slab 1: Rs. " << slab1Cost <<endl;
    cout << "Cost for slab 2: Rs. " << slab2Cost <<endl;
}

void costSlab2(int electricityMatrix[ROWS][COLS]) {
    int slab2Units = electricityMatrix[1][1];

    int slab2Cost = slab2Units * 15;

    cout << "Cost for slab 2: Rs. " << slab2Cost <<endl;
}

void costSlab3(int electricityMatrix[ROWS][COLS]) {
    int slab3Units = electricityMatrix[2][2];

    int slab3Cost = slab3Units * 20;

    cout << "Cost for slab 3: Rs. " << slab3Cost <<endl;
}

