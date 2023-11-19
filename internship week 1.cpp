#include<iostream>
#include<string>
#include<vector>

using namespace std;

void welcome()
{
	cout << "\n\nWelcome to Computer Tech Shop!";
}

void menu()
{
	cout << "\n\nPress 1 to add a case \n\n";
	cout << "Press 2 to add Ram \n\n";
	cout << "Press 3 to add a main Hard Disk Drive (HDD)\n\n";
	cout << "Press 4 to add a Solid State Drive (SSD) \n\n";
	cout << "Press 5 to add a secondary Hard disk drive \n\n";
	cout << "Press 6 to add an optical drive \n\n";
	cout << "Press 7 to add an Operating system \n\n";
	cout << "Press 8 to exit\n\n";
	cout << "Your choice: ";
}

int main()
{
	string array[] = {"Compact Case", "Tower Case", "8 GB RAM", "16 GB RAM", "32 GB RAM", "1 TB HDD", "2 TB HDD", "4 TB HDD", "240 GB SSD", "480 GB SSD", "Additional 1 TB HDD", "Additional 2 TB HDD", "Additional 4 TB HDD", "DVD/Blu-Ray Player", "DVD/Blu-Ray Re-writer", "Standard Windows", "Professional windows"};
	string items[7];
	int a;

	int choice, case_choice, ram_choice, hdd, ssd, aHDD, odd, os;

	float total = 0;

	welcome();

	while (1)
	{
		menu();
		cin >> choice;

		if (choice == 1)
		{
			cout << "\n\nSelect a case:\n\n1. Compact ($75)\n2. Tower ($150)\nYour choice: ";
			cin >> case_choice;

			if (case_choice == 1)
			{
				total = total + 75;
				items[0] = array[0];
			}
			else if (case_choice == 2)
			{
				total = total + 150;
				items[0] = array[1];
			}
		}
		else if (choice == 2)
		{
			cout << "\n\nSelect Ram Size:\n\n1. 8 GB ($79.99)\n2. 16 GB ($149.99)\n3. 32 GB ($299.99)\nYour choice: ";
			cin >> ram_choice;

			if (ram_choice == 1)
			{
				total = total + 79.99;
				items[1] = array[2];
			}
			else if (ram_choice == 2)
			{
				total = total + 149.99;
				items[1] = array[3];
			}
			else if (ram_choice == 3)
			{
				total = total + 299.99;
				items[1] = array[4];
			}
		}
		else if (choice == 3)
		{
			cout << "\n\nSelect the size of the main Hard disk drive (HDD):\n\n1. 1 TB ($49.99)\n2. 2 TB ($89.99)\n3. 4 TB ($129.99)\nYour choice: ";
			cin >> hdd;

			if (hdd == 1)
			{
				total = total + 49.99;
				items[2] = array[5];
			}
			else if (hdd == 2)
			{
				total = total + 89.99;
				items[2] = array[6];
			}
			else if (hdd == 3)
			{
				total = total + 129.99;
				items[2] = array[7];
			}
		}
		else if (choice == 4)
		{
			cout << "\n\nSelect the size of the SSD:\n\n1. 240 GB ($59.99)\n2. 480 GB ($119.99)\nYour choice: ";
			cin >> ssd;

			if (ssd == 1)
			{
				total = total + 59.99;
				items[3] = array[8];
			}
			else if (ssd == 2)
			{
				total = total + 119.99;
				items[3] = array[9];
			}
		}
		else if (choice == 5)
		{
			cout << "\n\nSelect the size of the additional Hard disk drive (HDD):\n\n1. 1 TB ($49.99)\n2. 2 TB ($89.99)\n3. 4 TB ($129.99)\nYour choice: ";
			cin >> aHDD;

			if (aHDD == 1)
			{
				total = total + 49.99;
				items[4] = array[10];
			}
			else if (aHDD == 2)
			{
				total = total + 89.99;
				items[4] = array[11];
			}
			else if (aHDD == 3)
			{
				total = total + 129.99;
				items[4] = array[12];
			}
		}
		else if (choice == 6)
		{
			cout << "\n\nSelect the Optical Drive:\n\n1. DVD/Blu-Ray Player ($50.00)\n2. DVD/Blu-Ray Re-writer ($119.99)\nYour choice: ";
			cin >> odd;

			if (odd == 1)
			{
				total = total + 50.00;
				items[5] = array[13];
			}
			else if (odd == 2)
			{
				total = total + 119.99;
				items[5] = array[14];
			}
		}
		else if (choice == 7)
		{
			cout << "\n\nSelect the Operating System:\n\n1. Standard Version ($100.00)\n2. Professional Version ($175.00)\nYour choice: ";
			cin >> os;

			if (os == 1)
			{
				total = total + 100.00;
				items[6] = array[15];
			}
			else if (os == 2)
			{
				total = total + 175.00;
				items[6] = array[16];
			}
		}
		else if (choice == 8)
		{
			cout << "Your order: \n";
			for (int x = 0; x < 7; x++)
			{
				cout << "\n" << x + 1 << ". " << items[x];
			}
			cout << "\nTotal bill: $" << total;
			cout << "\nThank you for shopping with us";
			return 0;
		}
	}
}

