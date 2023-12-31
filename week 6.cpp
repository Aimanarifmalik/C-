#include<iostream>
#include<string>


using namespace std;


bool checkSack(string contents, double weight) 
{
    if ((contents == "C" && weight >= 24.9 && weight <= 25.1) || ((contents == "G" || contents == "S") && weight >= 49.9 && weight <= 50.1)) {
        
		
		cout<<"Accepted: \n\nContents: "<<contents<<"\nWeight: "<<weight<< " kilograms" <<"\n\n";
		
        return true;
        
    } 
	else 
	{
        cout<<"Rejected! Reason:\n\n ";
        if (contents != "C" && contents != "G" && contents != "S") 
		{
            cout << "Invalid contents\n";
        }
        if ((contents == "C" && (weight < 24.9 || weight > 25.1)) || ((contents == "G" || contents == "S") && (weight < 49.9 || weight > 50.1))) {
            
			cout << "Invalid weight\n";
        }
        cout<<"\n\n";
        return false;
    }
}

void checkOrder() 
{
    int numCement, numGravel, numSand;
    
    cout<<"Enter the number of sacks of cement: ";
    
    cin>>numCement;
    
    cout<<"Enter the number of sacks of gravel: ";
    
    cin>>numGravel;
    
    cout<<"Enter the number of sacks of sand: ";
    
    cin>>numSand;

    int rejectedSacks= 0;
    
    double totalWeight = 0;

    rejectedSacks = rejectedSacks + (numCement - checkSack("C", numCement * 25.0)) ? 0 : numCement;
    
	rejectedSacks = rejectedSacks + (numGravel - checkSack("G", numGravel * 50.0)) ? 0 : numGravel;
    
	rejectedSacks = rejectedSacks + (numSand - checkSack("S", numSand * 50.0)) ? 0 : numSand;

    totalWeight = (numCement * 25.0) + (numGravel * 50.0) + (numSand * 50.0);

    cout<<"\n\nTotal weight of the order: "<<totalWeight<<" kilograms"<<"\n\n";
    
    cout<<"\n\nNumber of sacks rejected from the order: "<<rejectedSacks<<"\n\n";
}

void calculatePrice() 
{
    checkOrder();
    
    int numCement, numGravel, numSand;
    
    cout<<"\n\nEnter the number of sacks of cement: ";
    
	cin>>numCement;
	
    cout<<"\n\nEnter the number of sacks of gravel: ";
    
    cin>>numGravel;
    
    cout<<"Enter the number of sacks of sand: ";
    
	cin>>numSand;

   	int specialPacks = numCement;
   	
    if (numGravel/2<specialPacks) 
	{
        specialPacks = numGravel / 2;
        
    }
    if (numSand / 2 < specialPacks) 
	{
        specialPacks = numSand / 2;
    }
    
	int regularPrice = (numCement * 3) + (numGravel * 2) + (numSand * 2);
    
	int discountPrice = regularPrice - (specialPacks * 10);

    if (specialPacks > 0) 
	{
        cout<<"Regular price for the order: $"<<regularPrice<<"\n\n";
        
        cout<<"Special packs in the order: "<<specialPacks<<"\n\n";
        
        cout<<"New price for the order: $"<<discountPrice<<"\n\n";
        
        cout << "Amount saved: $" <<(regularPrice - discountPrice)<<"\n\n";
    } 
	
	else 
	{
        cout<<"Regular price for the order: $"<<regularPrice<<"\n\n";
        
    }
}

int main() 
{
    int choice;
    
    cout<<"Choose an option:\n\n ";
    
    cout<<"1. Check the contents and weight of a single sack"<<"\n\n";
    
    cout<<"2. Check a customers order for delivery"<<"\n\n";
    
    cout<<"3. Calculate the price for a customer’s order"<<"\n\n";
    
    cout<<"Enter your choice: ";
    
    cin >> choice;

    if (choice == 1)
	{
			        	
            string contents;
            
            double weight;
            
            cout << "Enter the contents (C for cement, G for gravel, S for sand): ";
            
			cin >> contents;
            
			cout << "Enter the weight (in kg): ";
            
			cin >> weight;
            
			checkSack(contents, weight);

}

            
       else if(choice == 2)
	{
			 	
        checkOrder();
            
    }
       
		else if(choice == 3)
    	{
		    calculatePrice();
        
        }
		
		else
		{
            cout<<"Invalid choice"<<"\n\n";
        	
			return 0;
    	}

    return 0;
}

