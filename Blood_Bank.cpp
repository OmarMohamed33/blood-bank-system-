#include <iostream>
#include"donor.h"
#include"admin.h"
#include"Recipient.h"
using namespace std;

void choicetypemenu();
void userchoicevalidation(int);

int main()
{
	

	system("color f0");

	choicetypemenu();
}




void choicetypemenu()
{


	int userchoice;
	cout << "-------------------------------------------" << endl;
	cout << "        welcome to our blood bank          " << endl;
	cout << "-------------------------------------------" << endl;
	cout << "choose the type of email " << endl;
	cout << "1.donor" << endl;
	cout << "2.Recipient" << endl;
	cout << "3.admin" << endl;
	cout << "4.quit" << endl;
	cin >> userchoice;

	userchoicevalidation(userchoice);


}



void userchoicevalidation(int userchoice)
{
	int c = userchoice;
	if (c == 1)
	{
		donor dnor;
		dnor.mainmenu();
	}
	if (c == 2)
	{
		 Recipient recipient;
		recipient.user();
	}
	if (c == 3)
	{
		admin admn;
		admn.login_admin();

	}
	if (c == 4)
	{
		cout << "thank you for using our system" << endl;
		exit(0);
	}
	if (c < 1 || c>4)
	{
		cout << "please enter valid choice" << endl;
		choicetypemenu();
	}
}


