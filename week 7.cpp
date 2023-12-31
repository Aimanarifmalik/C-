#include<iostream>
#include<vector>
#include<string>

using namespace std;


int main() 
{
	string charityName;
	
    vector<string> charities;
    
    for(int i = 0; i<3; ++i) 
	{
        cout<<"Enter name of charity "<<i + 1<< ": ";
        
		cin>>charityName;
        
		charities.push_back(charityName);
    }


    for(int i = 0; i<3 ; ++i)
	{
        cout<<"\n"<<i + 1<<". "<<charities[i]<<"\n\n";
    }

	int choice;
    
	while(1) 
	{
        cout<<"Enter the number of the charity you want to donate to (1, 2, or 3): ";
        
		cin>>choice;
		
        if(choice >= 1 && choice <= 3) 
		{
            break;
        } 
		else 
		{
            cout<<"Invalid input. Please enter 1, 2, or 3." << endl;
        }
    }

    double bill;
    cout << "Enter the customer's shopping bill: ";
    cin >> bill;

    double donation = bill * 0.01;


    vector<double> totals(3, 0);

    while(1) 
	{
        cout<<"Enter the number of the charity you want to donate to (1, 2, or 3), or enter 4 to show totals: ";
        cin >> choice;
        
        
        if (choice == 4) 
		{
            
            double totalDonated = 0;
            
            cout<<"\nCharity Totals:"<<endl;
            
            for (int i = 0; i < 3; ++i) 
			{
                cout<<charities[i]<<": "<<totals[i]<<endl;
                
				totalDonated = totalDonated + totals[i];
				
            }
            
            cout<<"\nGRAND TOTAL DONATED TO CHARITY: "<<totalDonated<<"\n\n";
            
			break;
			
        } 
		else if (choice >= 1 && choice <= 3) 
		{
            cout<<"Enter the customer's shopping bill: ";
            
            cin >> bill;
            
            donation = bill * 0.01;
            
            totals[choice - 1] += donation;
            
            cout<<"Donation of "<<donation<<"to "<<charities[choice - 1]<<" recorded."<<endl;
            
        } 
		else 
		{
            cout<<"Invalid input. Please enter 1, 2, 3, or -1."<<endl;
            continue;
        }
    }

    return 0;
}

