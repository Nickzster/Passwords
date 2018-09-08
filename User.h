#ifndef USER
#define USER
#include <string>
#include <vector>
using std::string;
using std::vector;

class User
{
private:
	string username;
	string password;
	string phoneNumber;
	bool loggedIn;
public:

	User();
	~User();

	void registerUser(string user, string password, string phoneNumber);
	bool login(string username, string password);
	void logout();
	string getPhoneNumber();
	bool isLoggedIn();
	string getUserName();
	void printAll();
};
#endif
