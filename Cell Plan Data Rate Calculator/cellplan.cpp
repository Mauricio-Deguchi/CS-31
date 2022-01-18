#include <iostream>
#include <string>
using namespace std;

// start the body of our program
int main()
{
	// ensures we will print in money format
	cout.setf(ios::showpoint);
	cout.setf(ios::fixed);
	cout.precision(2);

	// establish variables which should be used later:
	// gives them placehold variables to easily check their names later & ensure that it is not assigned a random value
	string plan_name = "placeholder_name", autopay = "placeholder_name", paperless = "placeholder_name", error = "placeholder_name";
	int lines = 0, gigabytes = 0;
	double bill = 0, line_rate = 0, discount = 0;

	// begin by asking for the type of cell phone plan
	cout << "What type of cell plan do you have? ";
	getline(cin, plan_name);

	// this block of code will sort through the plan name entered and assign the value of the rate per line
	if (plan_name == "Unlimited Elite") {
		line_rate = 85.00;
	}
	else if (plan_name == "Unlimited Extra") {
		line_rate = 75.00;
	}
	else if (plan_name == "Unlimited Starter") {
		line_rate = 65.00;
	}
	else if (plan_name == "Prepaid") {
		line_rate = 50.00;
	}
	else {										// if none of the select plan names are entered, we have a cell plan error and will store this in our error variable
		error = "Your cell plan is not valid!";		
	}
	

	// next, ask if they are on autopay
	cout << "Are you on autopay? ";
	getline(cin, autopay);

	// this will check for a discount or potential error message
	if (autopay == "Yes") {
		discount += 2;			// we establish a discount variable which contains all the discounts per line (this will be multiplied by the number of lines later)
	}
	else {
		if (autopay != "No") {							// if our answer is not Yes or No
			if (error == "placeholder_name") {			// and if we have not already picked up an error, (this ensures we display our first error if multiple errors are included)
				error = "Your autopay is not valid!";	// we will assign the appropriate error message
			}
		}
	}

	// 3rd, we will ask if they have paperless billing
	cout << "Are you on paperless billing? ";
	getline(cin, paperless);
	if (paperless == "Yes") {
		discount += 3;			// follows the same format as the previous block of code
	}
	else {
		if (paperless != "No") {
			if (error == "placeholder_name") {
				error = "Your paperless billing is not valid!";
			}
		}
	}

	// then, we will ask for the number of lines on the plan
	cout << "How many lines will be on your plan? ";
	cin >> lines;
	switch (lines) {
	case 1: discount += 0; break;		// if we have 1 line, there will be no discount
	case 2: discount += 10; break;		// if we have two lines, a $10 discount per line will be deducted
	case 3: discount += 10; break;		// like case 2, a $10 discount per line will be deducted
	default: 							// if we do not have 1, 2, or 3 lines:
		if (error == "placeholder_name") {			// we check if we have already had an error
			error = "Your lines are not valid!";	// if not, then we assign this error message
		} 
		break;
	}

	// lastly, we will ask for the number of gigabytes used for the month
	cout << "How many gigabytes did you consume this month? ";
	cin >> gigabytes;
	if ((gigabytes < 0) || (gigabytes > 30)) {			// we cannot have less than 0 or more than 30 gigabytes
		if (error == "placeholder_name") {				// if we have not picked up an error
			error = "Your gigabytes are not valid!";	// we will assign this error message if an invalid number of gigabytes is entered
		}
	}

	// time to calculate our bill

	if ((plan_name == "Prepaid") && (gigabytes > 4)) {
		bill = line_rate * lines - discount * lines + 10 * ((gigabytes - 4) / 2);
	}
	else {
		bill = line_rate * lines - discount * lines;
	}


	// checks if we picked up an error message along the way, if not we are set to print our exit message with the appropriate bill 
	if (error == "placeholder_name") {											// if we did not obtain an error
		cout << "Your " << plan_name << " cell plan costs $" << bill << ".";	// we can print our bill message
	}
	else {													// otherwise, let's print out which error we first picked up
		cout << error;
	}


	return(0);
}
