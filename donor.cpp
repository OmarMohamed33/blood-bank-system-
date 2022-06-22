#include<iostream>
#include "donor.h"
#include<assert.h>
#include<fstream>
using namespace std;

donor::donor()
{
    capacity = 1000;
    elems = 0;
    requests = 0;
    arr = new Dnr[capacity];
    request = new Dnr[capacity];
    index = 0;
}

fstream elemsfile;
fstream donorsavedata;


void donor::regist()
{


    elemsfile.open("elems.txt", ios::in);
    elemsfile >> elems;
    elemsfile.close();

    int a, e, m;
    string b, c, d, f, g, h, k;

    cout << "         -----------------------------------          " << endl;
    cout << "                   register page                      " << endl;
    cout << "         -----------------------------------          " << endl;
    cout << "id : " << endl;
    cin >> a;
    cout << "name : " << endl;
    cin >> b;
    cout << "mail : " << endl;
    cin >> c;
    cout << "password : " << endl;
    cin >> d;
    cout << "age : " << endl;
    cin >> e;
    cout << "gender : " << endl;
    cin >> f;
    cout << "blood type : " << endl;
    cin >> g;
    cout << "if you have any disease from this list type it(blood pressure disorders, thyroid disease, diabetes, cancer, heart disorders, hepatitis)" << endl;
    cout << "if you don't have disease form this list write \"no\" :" << endl;
    cin >> h;
    cout << "if you have anther disease or taking any medicine type it" << endl;
    cout << "if you don't have any another disease or taking any medicine \"no\" :" << endl;
    cin >> k;
    cout << "type the duration of last donation in months : " << endl;
    cin >> m;

    arr[elems].id = a;
    arr[elems].name = b;
    arr[elems].mail = c;
    arr[elems].password = d;
    arr[elems].age = e;
    arr[elems].gender = f;
    arr[elems].bldtyp = g;
    arr[elems].disease = h;
    arr[elems].othrdisease = k;
    arr[elems].lstdondate = m;

    donorsavedata.open("donorid.txt", ios::out | ios::app);
    donorsavedata << arr[elems].id << endl;
    donorsavedata.close();

    donorsavedata.open("donorname.txt", ios::out | ios::app);
    donorsavedata << arr[elems].name << endl;
    donorsavedata.close();

    donorsavedata.open("donormail.txt", ios::out | ios::app);
    donorsavedata << arr[elems].mail << endl;
    donorsavedata.close();

    donorsavedata.open("donorpassword.txt", ios::out | ios::app);
    donorsavedata << arr[elems].password << endl;
    donorsavedata.close();

    donorsavedata.open("donorage.txt", ios::out | ios::app);
    donorsavedata << arr[elems].age << endl;
    donorsavedata.close();

    donorsavedata.open("donorgender.txt", ios::out | ios::app);
    donorsavedata << arr[elems].gender << endl;
    donorsavedata.close();

    donorsavedata.open("donorbloodtype.txt", ios::out | ios::app);
    donorsavedata << arr[elems].bldtyp << endl;
    donorsavedata.close();

    donorsavedata.open("donordisease.txt", ios::out | ios::app);
    donorsavedata << arr[elems].disease << endl;
    donorsavedata.close();

    donorsavedata.open("donoranotherdisease.txt", ios::out | ios::app);
    donorsavedata << arr[elems].othrdisease << endl;
    donorsavedata.close();

    donorsavedata.open("donorlastdonationtime.txt", ios::out | ios::app);
    donorsavedata << arr[elems].lstdondate << endl;
    donorsavedata.close();

    elems++;

    elemsfile.open("elems.txt", ios::out);
    elemsfile << elems;
    elemsfile.close();

}








void donor::login() {
    string username2;
    string pass2;



    cout << "-------------------------------------------\n";
    cout << "             Log into your Account\n";
    cout << "-------------------------------------------\n" << endl;
    cout << "Enter your user name: ";
    cin >> username2;
    cout << "\nEnter your Password: ";
    cin >> pass2;

    logincheck(username2, pass2);

}










void donor::logincheck(string namekey, string passkey) {

    bool valuefound = false;
    int searchedindex;

    elemsfile.open("elems.txt", ios::in);
    elemsfile >> elems;
    elemsfile.close();

    donorsavedata.open("donorname.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].name;

    }
    donorsavedata.close();


    donorsavedata.open("donorpassword.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].password;
    }
    donorsavedata.close();


    donorsavedata.open("donorid.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].id;
    }
    donorsavedata.close();


    donorsavedata.open("donorage.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].age;

    }
    donorsavedata.close();


    donorsavedata.open("donoranotherdisease.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].othrdisease;

    }
    donorsavedata.close();


    donorsavedata.open("donorbloodtype.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].bldtyp;
    }
    donorsavedata.close();


    donorsavedata.open("donordisease.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].disease;
    }
    donorsavedata.close();


    donorsavedata.open("donorgender.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].gender;
    }
    donorsavedata.close();


    donorsavedata.open("donorlastdonationtime.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].lstdondate;
    }
    donorsavedata.close();


    donorsavedata.open("donormail.txt", ios::in);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata >> arr[i].mail;
    }
    donorsavedata.close();


    for (int i = 0; (i < elems) && !valuefound; i++)
    {
        if (namekey == arr[i].name)
        {
            searchedindex = i;
            index = searchedindex;
            valuefound = true;
        }
    }
    if (valuefound)
    {
        cout << "valid username" << endl;
        if (passkey == arr[searchedindex].password)
        {
            cout << "valid password" << endl;
            donoraccessmenu();
        }
        else
        {
            cout << "invalid password" << endl;
            mainmenu();
        }
    }
    else
    {
        cout << "invalid username or password" << endl;
        mainmenu();
    }

}







void donor::mainmenu()
{
    int userpick;

    cout << "-------------------------------------------------\n";
    cout << "  blood bank management system (donor main menu) \n";
    cout << "-------------------------------------------------\n" << endl;
    cout << "Please select an option from the menu below: \n";
    cout << "1. Login\n";
    cout << "2. Create a New Account\n";
    cout << "3. Quit\n" << endl;
    cout << "Please select your choice: ";
    cin >> userpick;
    mainMenuVal(userpick);
    userPickVal(userpick);
}








void donor::mainMenuVal(int userpick)
{
    int x = userpick;
    // Displays an error if userPick is not 1, 2, or 3.
    // Directs the user back to the main menu.
    while (x < 1 || x > 3)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2, or 3.\n" << endl;
        mainmenu();
    }
}







void donor::userPickVal(int userpick)
{
    int d = userpick;
    // Validates the user's input & executes function calls.
    switch (d)
    {
        // Case 1 - Displays the login menu.
    case 1:
        login();
        break;

        // Case 2 - Creates a user name & password & (register the data of donor).
    case 2:
        regist();
        mainmenu();
        break;

        // Case 3 - The program exits.
    case 3:
        cout << "\nThank you for using our system!\n";
        exit(0);
        break;

        // TEST ERROR MESSAGE.
    default:
        cout << "INTERNAL ERROR" << endl;
    }

}









void donor::donoraccessmenu()
{
    int choose;
    cout << "------------------------------" << endl;
    cout << "        donor menu            " << endl;
    cout << "------------------------------" << endl;
    cout << "1.request a donation" << endl;
    cout << "2.update your data" << endl;
    cout << "3.delete your account" << endl;
    cout << "4.log out" << endl;
    cout << "5.quit" << endl;
    cin >> choose;
    donoraccessmenuVal(choose);
    chooseVal(choose);
}






void donor::donoraccessmenuVal(int choose)
{
    int x = choose;

    while (x < 1 || x > 5)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2, or 3.\n" << endl;
        donoraccessmenu();
    }
}







void donor::chooseVal(int choose)
{
    int d = choose;

    switch (d)
    {

    case 1:
        requestdonation();
        break;


    case 2:
        update();
        break;


    case 3:
        deleteAcc(index);
        break;

    case 4:
        mainmenu();
        break;

    case 5:
        exit(0);
        break;

    default:
        cout << "INTERNAL ERROR" << endl;
    }

}






void donor::update()
{
    int pick;
    cout << "choose what do you need to update:" << endl;
    cout << "1.id" << endl;
    cout << "2.name" << endl;
    cout << "3.email" << endl;
    cout << "4.password" << endl;
    cout << "5.age" << endl;
    cout << "6.gender" << endl;
    cout << "7.blood type" << endl;
    cout << "8.listed diseases" << endl;
    cout << "9.any other diseases" << endl;
    cout << "10.the duration of last donation" << endl;
    cin >> pick;
    updateVal(pick);
    pickVal(pick);
    donoraccessmenu();
}






void donor::updateVal(int pick)
{
    int x = pick;

    while (x < 1 || x > 10)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2, to 10.\n" << endl;
        update();
    }
}






void donor::pickVal(int pick)
{
    int d = pick;


    if (d == 1)
    {
        int a;
        cout << "enter the new id" << endl;
        cin >> a;
        arr[index].id = a;
        donorsavedata.open("donorid.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].id << endl;
        }
        donorsavedata.close();
        cout << "id updated successfully" << endl;
    }

    if (d == 2)
    {
        string b;
        cout << "enter the new name" << endl;
        cin >> b;
        arr[index].name = b;
        donorsavedata.open("donorname.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].name << endl;
        }
        donorsavedata.close();
        cout << "name updated successfully" << endl;
    }
    if (d == 3)
    {
        string c;
        cout << "enter the new email" << endl;
        cin >> c;
        arr[index].mail = c;
        donorsavedata.open("donormail.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].mail << endl;
        }
        donorsavedata.close();
        cout << "email updated successfully" << endl;

    }
    if (d == 4)
    {
        string m;
        cout << "enter the new password" << endl;
        cin >> m;
        arr[index].password = m;
        donorsavedata.open("donorpassword.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].password << endl;
        }
        donorsavedata.close();
        cout << "password updated successfully" << endl;

    }
    if (d == 5)
    {
        int e;
        cout << "enter the new age" << endl;
        cin >> e;
        arr[index].age = e;
        donorsavedata.open("donorage.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].age << endl;
        }
        donorsavedata.close();
        cout << "age updated successfully" << endl;

    }
    if (d == 6)
    {
        string k;
        cout << "enter the new gender" << endl;
        cin >> k;
        arr[index].gender = k;
        donorsavedata.open("donorgender.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].gender << endl;
        }
        donorsavedata.close();
        cout << "gender updated successfully" << endl;
    }
    if (d == 7)
    {
        string f;
        cout << "enter the new blood type" << endl;
        cin >> f;
        arr[index].bldtyp = f;
        donorsavedata.open("donorbloodtype.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].bldtyp << endl;
        }
        donorsavedata.close();
        cout << "blood type updated successfully" << endl;
    }
    if (d == 8)
    {
        string g;
        cout << "enter the new disease of listed disease" << endl;
        cin >> g;
        arr[index].disease = g;
        donorsavedata.open("donordisease.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].disease << endl;
        }
        donorsavedata.close();
        cout << "diseases updated successfully" << endl;
    }
    if (d == 9)
    {
        string h;
        cout << "enter the new medicine or disease" << endl;
        cin >> h;
        arr[index].othrdisease = h;
        donorsavedata.open("donoranotherdisease.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].othrdisease << endl;
        }
        donorsavedata.close();
        cout << "the medicine or another disease updated successfully" << endl;
    }
    if (d == 10)
    {
        int i;
        cout << "enter the new duration of last donation" << endl;
        cin >> i;
        arr[index].lstdondate = i;
        donorsavedata.open("donorlastdonationtime.txt", ios::out);
        for (int i = 0; i < elems; i++)
        {
            donorsavedata << arr[i].lstdondate << endl;
        }
        donorsavedata.close();
        cout << "the duration of last donation updated successfully" << endl;
    }


}
fstream requestssaved;
fstream requestsfile;

void donor::requestdonation()
{
    requestsfile.open("requests.txt", ios::in);
    requestsfile >> requests;
    requestsfile.close();

    int a;

    cout << "are you sure to request donation:" << endl;
    cout << "1.yes" << endl;
    cout << "2.no" << endl;
    cin >> a;


    switch (a)
    {
    case 1:
        request[requests].id = arr[index].id;
        request[requests].name = arr[index].name;
        request[requests].age = arr[index].age;
        request[requests].bldtyp = arr[index].bldtyp;
        request[requests].disease = arr[index].disease;
        request[requests].gender = arr[index].gender;
        request[requests].lstdondate = arr[index].lstdondate;
        request[requests].mail = arr[index].mail;
        request[requests].othrdisease = arr[index].othrdisease;
        request[requests].password = arr[index].password;

        requestssaved.open("savedrequestsid.txt", ios::out | ios::app);
        requestssaved << request[requests].id << endl;
        requestssaved.close();

        requestssaved.open("savedrequestsname.txt", ios::out | ios::app);
        requestssaved << request[requests].name << endl;
        requestssaved.close();

        requestssaved.open("savedrequestsage.txt", ios::out | ios::app);
        requestssaved << request[requests].age << endl;
        requestssaved.close();

        requestssaved.open("savedrequestsbloodtype.txt", ios::out | ios::app);
        requestssaved << request[requests].bldtyp << endl;
        requestssaved.close();

        requestssaved.open("savedrequestsdisease.txt", ios::out | ios::app);
        requestssaved << request[requests].disease << endl;
        requestssaved.close();

        requestssaved.open("savedrequestsgender.txt", ios::out | ios::app);
        requestssaved << request[requests].gender << endl;
        requestssaved.close();

        requestssaved.open("savedrequestslastdonation.txt", ios::out | ios::app);
        requestssaved << request[requests].lstdondate << endl;
        requestssaved.close();

        requestssaved.open("savedrequestsmail.txt", ios::out | ios::app);
        requestssaved << request[requests].mail << endl;
        requestssaved.close();

        requestssaved.open("savedrequestsotherdiseases.txt", ios::out | ios::app);
        requestssaved << request[requests].othrdisease << endl;
        requestssaved.close();

        requestssaved.open("savedrequestspassword.txt", ios::out | ios::app);
        requestssaved << request[requests].password << endl;
        requestssaved.close();

        requests++;
        requestsfile.open("requests.txt", ios::out);
        requestsfile << requests;
        requestsfile.close();
        cout << "request done" << endl;
        donoraccessmenu();
        break;
    case 2:
        donoraccessmenu();
        break;
    default:
        cout << "please enter valid option" << endl;
        requestdonation();
        break;

    }


}



void donor::deleteAcc(int index)
{
    elemsfile.open("elems.txt", ios::in);
    elemsfile >> elems;
    elemsfile.close();

    for (int i = index; i < elems - 1; i++)
    {
        arr[i].age = arr[i + 1].age;
        arr[i].bldtyp = arr[i + 1].bldtyp;
        arr[i].disease = arr[i + 1].disease;
        arr[i].gender = arr[i + 1].gender;
        arr[i].id = arr[i + 1].id;
        arr[i].lstdondate = arr[i + 1].lstdondate;
        arr[i].mail = arr[i + 1].mail;
        arr[i].name = arr[i + 1].name;
        arr[i].othrdisease = arr[i + 1].othrdisease;
        arr[i].password = arr[i + 1].password;
    }
    elems--;

    donorsavedata.open("donorid.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].id << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donorname.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].name << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donormail.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].mail << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donorpassword.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].password << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donorage.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].age << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donorgender.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].gender << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donorbloodtype.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].bldtyp << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donordisease.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].disease << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donoranotherdisease.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].othrdisease << endl;
    }
    donorsavedata.close();

    donorsavedata.open("donorlastdonationtime.txt", ios::out);
    for (int i = 0; i < elems; i++)
    {
        donorsavedata << arr[i].lstdondate << endl;
    }
    donorsavedata.close();


    elemsfile.open("elems.txt", ios::out);
    elemsfile << elems;
    elemsfile.close();

    cout << "account deleted successfully" << endl;
    mainmenu();
}




donor::~donor(void)
{
    delete[] arr;
}
