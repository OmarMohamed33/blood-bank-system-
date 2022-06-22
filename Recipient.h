#pragma once
#include <iostream>
#include <string>
using namespace std;
struct Rec
{
	string id;
	string frist_name;
	string last_name;
	string Email;
	string password;
	string age;
	string gender;
	string blood_type;
	string hospital;
	string doctor_of_the_case;
};

class Recipient
{
	
public:
	Rec data;
	Recipient();
	void user();
	void operation();
	void Register();
	void Savedata();
	void returndata();
	void login();
	bool checklogin(string, string);
	void Update_data();
	void save_update();
	void delete_Account();
	void save_data();
	void search_Blood();
	void Blood_data();
	void Display();
	void requast_blood();
	~Recipient();
};

