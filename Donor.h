#include<iostream>
using namespace std;
struct Dnr
{
    int id;
    string name;
    string mail;
    string password;
    int age;
    string gender;
    string bldtyp;
    string disease;
    string othrdisease;
    int lstdondate;

};


class donor
{
public:
    Dnr* arr;
    Dnr* request;
    int capacity, elems, requests;
    int index;


public:
    donor();
    void regist();
    void login();
    void logincheck(string, string);
    void deleteAcc(int);
    void requestdonation();
    void update();
    void updateVal(int);
    void pickVal(int);
    void mainmenu();
    void mainMenuVal(int);
    void userPickVal(int);
    void donoraccessmenu();
    void donoraccessmenuVal(int);
    void chooseVal(int);
    ~donor(void);

};