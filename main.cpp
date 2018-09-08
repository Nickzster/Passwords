#include <iostream>
#include <string>
#include "User.h"
using namespace std;

string inputPassword() //Hides the input of the password in the console.
{
	string passWord;
	cin >> passWord;
	return passWord;
}

int main()
{
	bool goAgain = true;
	User u;
	string username;
	string password;
	string phoneNumber;
	int choice;
	while (goAgain)
	{
		//If the user is not logged in
		if (!u.isLoggedIn())
		{
			cout << "----------------------" << endl;
			cout << "1. Login" << endl;
			cout << "2. Register" << endl;
			cout << "3. Quit" << endl;
			cout << "----------------------" << endl;
			cout << "==>";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << "## Please enter your username: ##" << endl;
				cout << "==> ";
				cin >> username;
				cout << " ## Please enter your password: ##" << endl;
				cout << "==> ";
				password = inputPassword();
				if (u.login(username, password) == false)
				{
					cout << endl;
					cout << "####" << endl;
					cout << "#### LOGIN FAILED. Check your username and password! ####" << endl;
					cout << "####" << endl;
					cout << endl;
				}
				else
				{
					cout << endl;
					cout << "####" << endl;
					cout << "#### Successful! ####" << endl;
					cout << "####" << endl;
					cout << endl;
				}
				break;
			case 2:
				cout << "## Please enter a username ## " << endl;
				cout << "==> ";
				cin >> username;
				cout << "## Please enter a password ##" << endl;
				cout << "==> ";
				password = inputPassword();
				cout << "## Please enter a phone number ##" << endl;
				cout << "==> ";
				cin >> phoneNumber;
				u.registerUser(username, password, phoneNumber);
				cout << "## You are now registered! ##" << endl;
				break;
			case 3: goAgain = false; break;
			default:
				cout << "Not a valid option" << endl;
			}
		}
		else //if the user is logged in
		{
			cout << "## Here are your choices, " << u.getUserName() << " ##" << endl;
			cout << "======================" << endl;
			cout << "1. Get Phone Number" << endl;
			cout << "2. Logout" << endl;
			cout << "3. Quit" << endl;
			cout << "======================" << endl;
			cout << "==>";
			cin >> choice;
			switch (choice)
			{
			case 1:
				cout << endl;
				cout << "## " << u.getUserName() << ", your phone number is ";
				cout << u.getPhoneNumber();
				cout << " ##" << endl << endl;
				break;
			case 2:
				u.logout();
				break;
			case 3: goAgain = false; break;
			default: cout << "Not a valid option." << endl; break;
			}
		}
	}
}