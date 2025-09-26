#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
using namespace std;

class Event{
	
	//private members
	private:
		const double costPerHour = 18.50;
		const double costPerMinute = 0.40;
		const double costOfDinner = 20.70;
		int numSrv, numGuests, dur;
		double costPerSrv, foodCost, avgCostPerPerson, ttlCost, depAmt, cost1, cost2;
		string evt_name, org;
		
		//function to calculate the costs of event
		void calculateCosts(){
			numSrv = (int)ceil(numGuests/20.0);
			
			cost1 = dur/60*costPerHour;
			cost2 = (dur % 60) * costPerMinute;
			costPerSrv = cost1 + cost2;
		
			foodCost = numGuests*costOfDinner;
			avgCostPerPerson = foodCost/numGuests;
			
			ttlCost = foodCost + (costPerSrv*numSrv);
			
			depAmt = ttlCost * 0.25;
		}
	
	//public members	
	public:
		//Constructor with arguments
		Event (string event_name, string organiser, int num_guests, int duration){
			evt_name = event_name;
			org = organiser;
			numGuests = num_guests;
			dur = duration;
			
			calculateCosts();			
		}
		
		// Display a neat summary to the user
    	void displaySummary() {
        	cout << fixed << setprecision(2); // show currency-like 2 decimal places
       		cout << "\n-------------Event estimate for " << org << "-------------------\n";
        	cout << "Number of servers required : " << numSrv << "\n";
        	cout << "The Cost per Server        : " << costPerSrv << "\n";
        	cout << "The Cost for food is       : " << foodCost << "\n";
        	cout << "Average cost per person    : " << avgCostPerPerson << "\n";
        	cout << "\nTotal cost of event is       : " << ttlCost << "\n";
        	cout << "\nPlease pay 25% of total cost as a deposit, to reserve the event\n";
        	cout << "The deposit needed is: " << depAmt << "\n";
        	cout << "--------------------------------------------------------------\n\n";
    	}

};




// ===== main program flow =====
int main() {

	string name, eventName;
	int numOfGuests, duration;
	
	cout << "\n------------------Event Management System-------------------\n";
    cout << "\nWelcome to Event Manager\n";
    cout << "This program will ask for event details and then estimate costs.\n\n";

    // We allow the user to create and compute multiple events in a single run.
    // This demonstrates loops and gives the user some flexibility.
    char continueChoice = 'Y';
    do {

    	cout << "Enter name of the event: ";
		getline(cin, eventName);
		while (eventName.empty()) {   // keep asking
   			cout << "Enter name of the event: ";
   			getline(cin, eventName);
		}
		
  		cout << "Enter customer's first and last name: ";
		getline(cin, name);
		while(name.empty()){
			cout << "Enter customer's first and last name: ";
			getline(cin, name);
		}
		
  	  	cout << "Enter number of Guests: ";
    	cin >> numOfGuests;
    
		cout << "Enter duration of event (in minutes): ";
    	cin >> duration;

        Event ev(eventName, name, numOfGuests, duration);
        ev.displaySummary();

        // Ask whether user wants to estimate another event (simple loop)
        cout << "Do you want to estimate another event? (Y/N): ";
        cin >> continueChoice;
        cout << "\n";
        cin.ignore();
    } while (continueChoice == 'Y' || continueChoice == 'y');

    cout << "Thank you for using Event Organiser. Goodbye!\n";
    return 0;
}
