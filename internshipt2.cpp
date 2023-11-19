#include <iostream>
#include <vector>
using namespace std;

class Ticket {
public:
    Ticket(int numPassengers, double totalPrice) : numPassengers(numPassengers), totalPrice(totalPrice) {}

    int getNumPassengers() const {
        return numPassengers;
    }

    double getTotalPrice() const {
        return totalPrice;
    }

private:
    int numPassengers;
    double totalPrice;
};

class TrainJourney {
public:
    TrainJourney() : availableSeats(NUM_COACHES * SEATS_PER_COACH), totalPassengers(0), totalRevenue(0.0) {}

    bool purchaseTickets(int numTickets);

    int getAvailableSeats() const {
        return availableSeats;
    }

    int getTotalPassengers() const {
        return totalPassengers;
    }

    double getTotalRevenue() const {
        return totalRevenue;
    }

private:
    int availableSeats;
    int totalPassengers;
    double totalRevenue;
};

bool TrainJourney::purchaseTickets(int numTickets) {
    // Check if there are enough seats available
    if (availableSeats >= numTickets) {
        // Calculate total price
        double totalPrice = numTickets * TICKET_PRICE;

        // Apply group discount if applicable
        if (numTickets >= 10) {
            int freeTickets = numTickets / 10;
            totalPrice -= freeTickets * TICKET_PRICE;
        }

        // Update data members
        availableSeats -= numTickets;
        totalPassengers += numTickets;
        totalRevenue += totalPrice;

        return true;
    } else {
        cout << "Not enough seats available for the selected journey.\n";
        return false;
    }
}

class ElectricMountainRailway {
public:
    ElectricMountainRailway() {
        // Initialize train journeys
        for (int i = 0; i < NUM_JOURNEYS; ++i) {
            upTrains.push_back(TrainJourney());
            downTrains.push_back(TrainJourney());
        }
    }

    void displayScreen() const;

    bool purchaseTickets(int journeyIndex, int numTickets);

    void endOfDayReport() const;

private:
    vector<TrainJourney> upTrains;
    vector<TrainJourney> downTrains;
};

void ElectricMountainRailway::displayScreen() const {
    // Display train times and available seats for each journey
    std::cout << "Train Times (Up and Down):\n";
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        cout << "Up:   " << i + 9 << ":00   ";
        cout << "Down: " << i + 10 << ":00   ";
        std::cout << "Available Seats: " << upTrains[i].getAvailableSeats() << "\n";
    }
}

bool ElectricMountainRailway::purchaseTickets(int journeyIndex, int numTickets) {
    // Check if it's a valid journey index
    if (journeyIndex < 0 || journeyIndex >= NUM_JOURNEYS) {
        std::cout << "Invalid journey index.\n";
        return false;
    }

    // Purchase tickets for the specified journey
    return upTrains[journeyIndex].purchaseTickets(numTickets);
}

void ElectricMountainRailway::endOfDayReport() const {
    // Display end-of-day report for each journey
    std::cout << "\nEnd of Day Report:\n";
    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        cout << "Journey " << i + 1 << " - Up Train:\n";
        cout << "   Passengers: " << upTrains[i].getTotalPassengers() << "\n";
    cout << "   Revenue: $" << upTrains[i].getTotalRevenue() << "\n";
        cout << "Journey " << i + 1 << " - Down Train:\n";
        cout << "   Passengers: " << downTrains[i].getTotalPassengers() << "\n";
        cout << "   Revenue: $" << downTrains[i].getTotalRevenue() << "\n";
    }

    // Calculate and display total passengers and revenue for the day
    int totalPassengers = 0;
    double totalRevenue = 0.0;

    for (int i = 0; i < NUM_JOURNEYS; ++i) {
        totalPassengers += upTrains[i].getTotalPassengers() + downTrains[i].getTotalPassengers();
        totalRevenue += upTrains[i].getTotalRevenue() + downTrains[i].getTotalRevenue();
    }

    std::cout << "\nTotal Passengers for the Day: " << totalPassengers << "\n";
    std::cout << "Total Revenue for the Day: $" << totalRevenue << "\n";
}

int main() {
    ElectricMountainRailway railway;

    // Display initial screen
    railway.displayScreen();

    // Example: Purchasing tickets for the first up train
    int journeyIndex = 0;
    int numTickets = 5;
    if (railway.purchaseTickets(journeyIndex, numTickets)) {
        cout << "Tickets purchased successfully!\n";
    } else {
        cout << "Failed to purchase tickets. Please try again.\n";
    }

    // Display end-of-day report
    railway.endOfDayReport();

    return 0;
}

