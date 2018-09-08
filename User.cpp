#include <iostream>
#include <fstream>
#include <istream>
#include <ostream>
#include <vector>
#include <string>
#include "User.h"


using namespace std;

User::User()
{
	this->loggedIn = false;
	ifstream file;
	file.open("UserData.txt");
	if (!file.is_open())
	{
		cout << "File does not exist!" << endl;
	}
	else
	{
		while (file >> this->username) //while I can still read into the user name
		{
			file >> this->password;
			file >> this->phoneNumber;
		}
	}
}
User::~User()
{
	ofstream file("UserData.txt");
	file << this->username;
	file << " ";
	file << this->password;
	file << " " ;
	file << this->phoneNumber;
	file << " ";
}

void User::registerUser(string user, string password, string phoneNumber)
{
	this->username = user;
	string encPass;
	string encPhone;
	char key = 'x';
	for (int i = 0; i < password.size(); i++)
	{
		encPass += password[i] ^ (int)key % 21;
	}
	this->password = encPass;
	for (int i = 0; i < phoneNumber.size(); i++)
	{
		encPhone += phoneNumber[i] ^ (int)key % 21;
	}
	this->phoneNumber = encPhone;
}
bool User::login(string username, string password)
{
	if (username != this->username)
	{
		return false;
	}
	else
	{
		string decPass;
		char key = 'x';
		for (int i = 0; i < password.size(); i++)
		{
			decPass += this->password[i] ^ (int)key % 21;
		}
		if (decPass == password)
		{
			this->loggedIn = true;
			return true;
		}
		else
		{
			return false;
		}
	}
}

void User::logout()
{
	this->loggedIn = false;
}

string User::getPhoneNumber()
{
	string decPhone;
	string temp = this->phoneNumber;
	char key = 'x';
	for (int i = 0; i < temp.size(); i++)
	{
		decPhone += temp[i] ^ (int)key % 21;
	}
	return decPhone;
}

bool User::isLoggedIn()
{
	return this->loggedIn;
}

string User::getUserName()
{
	return this->username;
}

void User::printAll()
{
	cout << this->username << endl;
	cout << this->password << endl;
	cout << this->phoneNumber << endl;
}