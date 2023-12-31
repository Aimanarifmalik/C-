#include<iostream>
#include<vector>
#include<ctime>

using namespace std;

const int NUM_BOATS = 10;

const int HIRE_START_HOUR = 10;

const int HIRE_END_HOUR = 17;

const int FULL_HOUR_RATE = 20;

const int HALF_HOUR_RATE = 12;

struct Boat
{
    int boatNumber;
    
    int totalHoursHired;
    
    int returnHour;
};

void calculateMoneyTaken(Boat& boat) 
{
    int hours;
    
    cout<<"Enter the number of hours the boat " << boat.boatNumber << " was hired: ";
    
	cin>>hours;

    if (hours < 0 || hours > 7) 
	{
        cout<<"Invalid input. Hours must be between 0 and 7."<<endl;
        
        return;
    }

    boat.totalHoursHired += hours;
    
    boat.returnHour = (boat.returnHour + hours) > HIRE_END_HOUR ? HIRE_END_HOUR : (boat.returnHour + hours);

    int amount = 0;
    
    if (hours >= 1)
	{
        amount += hours * FULL_HOUR_RATE;
    } 
	
	else 
	{
        amount += HALF_HOUR_RATE;
    }

    cout<<"Money taken for boat "<<boat.boatNumber<<" today: $"<<amount<<endl;
}


void findNextAvailableBoat(const vector<Boat>& boats) 
{
    time_t now = time(0);
    
    tm* current_time = localtime(&now);
    
    int currentHour = current_time->tm_hour;

    int availableBoats = 0;
    
    for (const auto& boat : boats) 
	{
        if (currentHour >= boat.returnHour) 
		{
            availableBoats++;
        }
    }

    if (availableBoats == 0) 
	{
        cout<<"No boats are currently available. The earliest available time is 10:00 AM tomorrow." << endl;
    }
	else 
	{
        cout<<"There are "<<availableBoats<<" boats available for hire right now."<< endl;
    }

}

void calculateTotalMoneyTaken(const vector<Boat>& boats) 
{
    int totalMoney = 0;
    
    int totalHours = 0;
    
    int unusedBoats = 0;
    
    int maxHours = 0;
    
    int mostUsedBoatNumber = 0;

    
	for (const auto& boat : boats) 
	{
        totalMoney += boat.totalHoursHired >= 1 ? boat.totalHoursHired * FULL_HOUR_RATE : HALF_HOUR_RATE;
        
		totalHours += boat.totalHoursHired;
        
		if (boat.totalHoursHired == 0) 
		{
            unusedBoats++;
        }
        
		if (boat.totalHoursHired > maxHours)
		 {
            maxHours = boat.totalHoursHired;
            
            mostUsedBoatNumber = boat.boatNumber;
        }
    }

    cout<<"Total money taken today: $" << totalMoney<<endl;
    
    cout<<"Total hours boats were hired today: "<<totalHours<<endl;
    
	cout<<"Number of boats not used today: "<<unusedBoats<<endl;
	
    cout<<"Boat used the most: "<<mostUsedBoatNumber<<" with "<< maxHours << " hours hired." << endl;
}

int main() 
{
    vector<Boat> boats;
    
    for (int i = 1; i <= NUM_BOATS; ++i)
	{
        Boat boat;
        
        boat.boatNumber = i;
        
        boat.totalHoursHired = 0;
        
        boat.returnHour = HIRE_START_HOUR;
        
        boats.push_back(boat);
    }

    for (auto& boat : boats) 
	{
        calculateMoneyTaken(boat);
    }

    
    findNextAvailableBoat(boats);
	
	calculateTotalMoneyTaken(boats);

    return 0;
}

