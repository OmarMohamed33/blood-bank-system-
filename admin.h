#pragma once
#include<string>
#include<iostream>
using namespace std;

struct bloo
{
	int quantity;
	string type;
	string expiry;
	string Recevied;
};
struct Reci
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

class admin
{
public:
	bloo* arra;
	int counter;
	int elements;
	int requsts;
	int* age;
	int* lstdn;
	int* ids;
	int elme;
	string* name;
	string* bloods;
	string* diseases;
	string* otherdis;
	string* gender;
	string* password;
	string* mails;
public:
	admin();
	void admin_main();
	void login_admin();
	void check_donor();
	void blood_edit();
	void mainMenu(int);
	void PickVal(int);
	void update_blood();
	void delete_b();
	void insert_blood();
	void about_donor();
	void mainMenunew(int);
	void adminPickVal(int);
	void aboutdnrval(int);
	void aboutdnrpick(int);
	void insrtdnr();
	void updtdnr();
	void deldnr();
	void displaydnr();
	void displayalldnrs();
	void about_recipient();
	void aboutrecipentval(int);
	void aboutrecipentpick(int);
	void return_data();
	void update_recipient();
	void delete_recipient();
    void save_update();
	void save_delete();
	void displayrecipient();
};


