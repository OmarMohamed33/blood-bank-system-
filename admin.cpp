#include "admin.h"
#include<fstream>
#include "Arr.cpp"
Arr<string>Frist, Last, EMail, ID_rec, AGe, PasSword, GeNder, Blood_Type, HospiTal, DocTor;
fstream id, frist, last, eMail, pass, aGe, geNder, blood, hospiTal, doctor;
fstream edit;
admin::admin()
{
    counter = 1000;
    elements = 0;
    requsts = 0;
    ids = new int[counter];
    age = new int[counter];
    lstdn = new int[counter];
    name = new string[counter];
    password = new string[counter];
    mails = new string[counter];
    bloods = new string[counter];
    gender = new string[counter];
    diseases = new string[counter];
    otherdis = new string[counter];
    elme = 0;
    arra = new bloo[counter];

}

void admin::login_admin() {
    string user;
    string pass;
    cout << "          ---------------------------------          " << endl;
    cout << "                  admin login page                   " << endl;
    cout << "          ---------------------------------          " << endl;
    cout << "enter user name" << endl;
    cin >> user;
    cout << "enter pass password" << endl;
    cin >> pass;
    if (true)
    {

        if (user == "admin" && pass == "admin")
        {
            cout << "valid admin data" << endl;
            admin_main();
        }
        else
        {
            cout << "invalid admin data" << endl;
            login_admin();
        }
    }
}

void admin::admin_main() {

    int admin_pick;

    cout << "-------------------------------------------------\n";
    cout << "  blood bank management system (admin main menu) \n";
    cout << "-------------------------------------------------\n" << endl;
    cout << "Please select an option from the menu below: \n";
    cout << "1.check donor requests\n";
    cout << "2.blood edit\n";
    cout << "3.about recipients\n";
    cout << "4.about donor\n";
    cout << "5.quit" << endl;
    cout << "Please select your choice: ";
    cin >> admin_pick;
    mainMenunew(admin_pick);
    adminPickVal(admin_pick);


}


void admin::adminPickVal(int admin_pick) {

    int d = admin_pick;
    // Validates the user's input & executes function calls.
    switch (d)
    {
        // Case 1 - check donor.
    case 1:
        check_donor();
        break;

        // Case 2 -  blood edit.
    case 2:
        blood_edit();
        break;
        // case 3 - about recipients data.
    case 3:
        about_recipient();
        break;
        // case 4 - about donors data.
    case 4:
        about_donor();
        break;
        // exit the program.
    case 5:
        exit(0);
        break;
        // TEST ERROR MESSAGE.
    default:
        cout << "INTERNAL ERROR" << endl;
    }

}
void admin::mainMenunew(int admin_pick) {
    int x = admin_pick;
    while (x < 1 || x > 5)
    {
        cout << "**ERROR** - Invalid option. Please enter 1, 2,3,4, or 5.\n" << endl;
        admin_main();
    }


}
fstream check;

void admin::check_donor()
{

    check.open("requests.txt", ios::in);
    check >> requsts;
    check.close();

    check.open("savedrequestsage.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> age[i];
    }
    check.close();

    check.open("savedrequestsdisease.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> diseases[i];
    }
    check.close();

    check.open("savedrequestsotherdiseases.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> otherdis[i];
    }
    check.close();

    check.open("savedrequestslastdonation.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> lstdn[i];
    }
    check.close();

    check.open("savedrequestsid.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> ids[i];
    }
    check.close();

    check.open("savedrequestsname.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> name[i];
    }
    check.close();

    check.open("savedrequestspassword.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> password[i];
    }
    check.close();

    check.open("savedrequestsmail.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> mails[i];
    }
    check.close();

    check.open("savedrequestsgender.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> gender[i];
    }
    check.close();

    check.open("savedrequestsbloodtype.txt", ios::in);
    for (int i = 0; i < requsts; i++)
    {
        check >> bloods[i];
    }
    check.close();


    for (int i = 0; i < requsts; i++)
    {
        if (age[i] >= 17 && age[i] <= 60)
        {

            if (diseases[i] == "no")
            {
                if (otherdis[i] == "no")
                {
                    if (lstdn[i] >= 3)
                    {
                        check.open("acceptedrequestsid.txt", ios::out | ios::app);
                        check << ids[i] << endl;
                        check.close();

                        check.open("acceptedrequestsname.txt", ios::out | ios::app);
                        check << name[i] << endl;
                        check.close();

                        check.open("acceptedrequestspass.txt", ios::out | ios::app);
                        check << password[i] << endl;
                        check.close();

                        check.open("acceptedrequestsmail.txt", ios::out | ios::app);
                        check << mails[i] << endl;
                        check.close();

                        check.open("acceptedrequestsgender.txt", ios::out | ios::app);
                        check << gender[i] << endl;
                        check.close();

                        check.open("acceptedrequestsblood.txt", ios::out | ios::app);
                        check << bloods[i] << endl;
                        check.close();

                        check.open("acceptedrequestsdis.txt", ios::out | ios::app);
                        check << diseases[i] << endl;
                        check.close();

                        check.open("acceptedrequestsothrdis.txt", ios::out | ios::app);
                        check << otherdis[i] << endl;
                        check.close();

                        check.open("acceptedrequestsage.txt", ios::out | ios::app);
                        check << age[i] << endl;
                        check.close();

                        check.open("acceptedrequestslstdn.txt", ios::out | ios::app);
                        check << lstdn[i] << endl;
                        check.close();
                        cout << "donor request number : " << i + 1 << " is safe and his/her request accepted" << endl;
                    }
                    else {
                        cout << "donor request number : " << i + 1 << " is not safe and his/her request denied" << endl;
                    }
                }
                else {
                    cout << "donor request number : " << i + 1 << " is not safe and his/her request denied" << endl;
                }
            }
            else {
                cout << "donor request number : " << i + 1 << " is not safe and his/her request denied" << endl;
            }
        }
        else {
            cout << "donor request number : " << i + 1 << " is not safe and his/her request denied" << endl;
        }
    }

    admin_main();

}
void admin::blood_edit()
{
    int adm;

    cout << "-------------------------------------------------\n";
    cout << "  blood bank management system (admin main menu) \n";
    cout << "-------------------------------------------------\n" << endl;
    cout << "Please select an option from the menu below: \n";
    cout << "1. choose insert blood ";
    cout << "2. choose update ";
    cout << "3.choose delete";
    cout << "4. Quit\n" << endl;
    cout << "Please select your choice: ";
    cin >> adm;
    mainMenu(adm);
    PickVal(adm);
}
void admin::mainMenu(int adm)
{
    int x = adm;
    // Displays an error if userPick is not 1, 2, or 3.
    // Directs the user back to the main menu.
    while (x < 1 || x > 4)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2, or 3.\n" << endl;
        blood_edit();
    }
}
void admin::PickVal(int adm)
{

    int d = adm;
    // Validates the user's input & executes function calls.
    switch (d)
    {
        // Case 1 - to insert blood.
    case 1:
        insert_blood();
        break;

        // Case 2 - to update data blood;.
    case 2:
        update_blood();
        break;
        // Case 3 - to delete date blood.
    case 3:
        delete_b();
        break;
        // Case 4 - The program exits.
    case 4:
        cout << "\nThank you for using our system!\n";
        exit(0);
        break;
        // TEST ERROR MESSAGE.
    default:
        cout << "INTERNAL ERROR" << endl;
    }

}
void admin::update_blood()
{
    string ty;

    cout << "-----------------------------------" << endl;
    cout << "        update data of blood       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "enter type of blood you need to update his data: " << endl;
    cin >> ty;
    bool valuefound = false;

    int searchedindex;
    edit.open("editelems.txt", ios::in);
    edit >> elme;
    edit.close();

    edit.open("editBloodtype.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].type;

    }
    edit.close();


    edit.open("editExpirydate.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].expiry;
    }
    edit.close();


    edit.open("editbloodquantity.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].quantity;
    }
    edit.close();


    edit.open("editRecevieddate.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].Recevied;

    }
    edit.close();

    for (int i = 0; (i < elme) && !valuefound; i++)
    {
        if (ty == arra[i].type)
        {
            searchedindex = i;
            valuefound = true;

        }
    }
    if (valuefound)
    {
        int pi;
        cout << "choose what do you need to update:" << endl;
        cout << "1.Blood_type" << endl;
        cout << "2.Expiry_date" << endl;
        cout << "3.quantity" << endl;
        cout << "4.Recevied_date" << endl;
        cin >> pi;
        while (pi < 1 || pi > 4)
        {
            cout << endl;
            cout << "**ERROR** - Invalid option. Please enter 1, 2, to 4.\n" << endl;
            update_blood();
        }
        if (pi == 1)
        {
            string a;
            cout << "enter the new Blood_type" << endl;
            cin >> a;
            arra[elme].type = a;
            edit.open("editBloodtype.txt", ios::out);
            for (int i = 0; i < elme; i++)
            {
                edit << arra[i].type << endl;
            }
            edit.close();
        }

        if (pi == 2)
        {
            string b;
            cout << "enter the new Expiry date" << endl;
            cin >> b;
            arra[elme].expiry = b;
            edit.open("editExpirydate.txt", ios::out);
            for (int i = 0; i < elme; i++)
            {
                edit << arra[i].expiry << endl;
            }
            edit.close();
        }
        if (pi == 3)
        {
            int c;
            cout << "enter the new quantity" << endl;
            cin >> c;
            arra[elme].quantity = c;
            edit.open("editbloodquantity.txt", ios::out);
            for (int i = 0; i < elme; i++)
            {
                edit << arra[i].quantity << endl;
            }
            edit.close();

        }
        if (pi == 4)
        {
            string m;
            cout << "enter the new Recevied date" << endl;
            cin >> m;
            arra[elme].Recevied = m;
            edit.open("editRecevieddate.txt", ios::out);
            for (int i = 0; i < elme; i++)
            {
                edit << arra[i].Recevied << endl;
            }
            edit.close();
        }
        blood_edit();
    }
    else
    {
        cout << "invalid blood type" << endl;
        update_blood();
    }
}
void admin::delete_b()
{
    string ty;

    cout << "-----------------------------------" << endl;
    cout << "        delete data of blood       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "enter type of blood you need to delete his data: " << endl;
    cin >> ty;
    bool valuefound = false;

    int searchedindex;

    edit.open("editelems.txt", ios::in);
    edit >> elme;
    edit.close();

    edit.open("editBloodtype.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].type;

    }
    edit.close();


    edit.open("editExpirydate.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].expiry;
    }
    edit.close();


    edit.open("editbloodquantity.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].quantity;
    }
    edit.close();


    edit.open("editRecevieddate.txt", ios::in);
    for (int i = 0; i < elme; i++)
    {
        edit >> arra[i].Recevied;

    }
    edit.close();



    for (int i = 0; (i < elme) && !valuefound; i++)
    {
        if (ty == arra[i].type)
        {
            searchedindex = i;
            valuefound = true;
        }
    }
    if (valuefound)
    {
        for (int i = searchedindex; i < elme - 1; i++)
        {
            arra[i].type = arra[i + 1].type;
            arra[i].expiry = arra[i + 1].expiry;
            arra[i].quantity = arra[i + 1].quantity;
            arra[i].Recevied = arra[i + 1].Recevied;

        }
        elme--;

        edit.open("editBloodtype.txt", ios::out);
        for (int i = 0; i < elme; i++)
        {
            edit << arra[i].type << endl;
        }
        edit.close();

        edit.open("editExpirydate.txt", ios::out);
        for (int i = 0; i < elme; i++)
        {
            edit << arra[i].expiry << endl;
        }
        edit.close();

        edit.open("editbloodquantity.txt", ios::out);
        for (int i = 0; i < elme; i++)
        {
            edit << arra[i].quantity << endl;
        }
        edit.close();

        edit.open("editRecevieddate.txt", ios::out);
        for (int i = 0; i < elme; i++)
        {
            edit << arra[i].Recevied << endl;
        }
        edit.close();

        edit.open("editelems.txt", ios::out);
        edit >> elme;
        edit.close();


        cout << "data of blood type who has type: " << ty << " was deleted." << endl;
    }
    blood_edit();

}
void admin::insert_blood() {
    string bl, ex, re;
    int qu;
    edit.open("editelems.txt", ios::out);
    edit << elme;
    edit.close();

    cout << "enter blood type" << endl;
    cin >> bl;
    cout << "enter blood Recevied date";
    cin >> re;
    cout << "enter blood Expiry date";
    cin >> ex;

    cout << "enter blood quantity";
    cin >> qu;

    edit.open("editelems.txt", ios::in);
    edit >> elme;
    edit.close();


    arra[elme].type = bl;
    arra[elme].expiry = ex;
    arra[elme].Recevied = re;
    arra[elme].quantity = qu;
    elme++;

    edit.open("editBloodtype.txt", ios::out | ios::app);
    edit << arra[elme].type << endl;
    edit.close();


    edit.open("editExpirydate.txt", ios::out | ios::app);
    edit << arra[elme].expiry << endl;
    edit.close();


    edit.open("editRecevieddate.txt", ios::out | ios::app);
    edit << arra[elme].Recevied << endl;
    edit.close();


    edit.open("editbloodquantity.txt", ios::out | ios::app);
    edit << arra[elme].quantity << endl;
    edit.close();


    edit.open("editelems.txt", ios::out);
    edit << elme;
    edit.close();

    blood_edit();
}
void admin::about_donor()
{
    int pick;
    cout << "----------------------------------" << endl;
    cout << "       control data of donors     " << endl;
    cout << "----------------------------------" << endl;
    cout << "1.insert donor." << endl;
    cout << "2.update data of donor." << endl;
    cout << "3.delete donor." << endl;
    cout << "4.display donor data." << endl;
    cout << "5.display all donors data." << endl;
    cout << "6.go back" << endl;
    cin >> pick;

    aboutdnrval(pick);
    aboutdnrpick(pick);

}

void admin::aboutdnrval(int pick)
{
    int x = pick;
    while (x < 1 || x > 6)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2,3,4,5, or 6.\n" << endl;
        about_donor();
    }
}
void admin::aboutdnrpick(int pick)
{

    int d = pick;

    switch (d)
    {

    case 1:
        insrtdnr();
        break;
    case 2:
        updtdnr();
        break;
    case 3:
        deldnr();
        break;
    case 4:
        displaydnr();
        break;
    case 5:
        displayalldnrs();
        break;
    case 6:
        admin_main();
        break;

    default:
        cout << "INTERNAL ERROR" << endl;
    }
}
fstream elementsfile;
fstream dnrsavedata;

void admin::insrtdnr()
{
    elementsfile.open("elems.txt", ios::in);
    elementsfile >> elements;
    elementsfile.close();

    int a, e, m;
    string b, c, d, f, g, h, k;

    cout << "         -----------------------------------          " << endl;
    cout << "                   insert donor                       " << endl;
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

    ids[elements] = a;
    name[elements] = b;
    mails[elements] = c;
    password[elements] = d;
    age[elements] = e;
    gender[elements] = f;
    bloods[elements] = g;
    diseases[elements] = h;
    otherdis[elements] = k;
    lstdn[elements] = m;

    dnrsavedata.open("donorid.txt", ios::out | ios::app);
    dnrsavedata << ids[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donorname.txt", ios::out | ios::app);
    dnrsavedata << name[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donormail.txt", ios::out | ios::app);
    dnrsavedata << mails[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donorpassword.txt", ios::out | ios::app);
    dnrsavedata << password[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donorage.txt", ios::out | ios::app);
    dnrsavedata << age[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donorgender.txt", ios::out | ios::app);
    dnrsavedata << gender[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donorbloodtype.txt", ios::out | ios::app);
    dnrsavedata << bloods[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donordisease.txt", ios::out | ios::app);
    dnrsavedata << diseases[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donoranotherdisease.txt", ios::out | ios::app);
    dnrsavedata << otherdis[elements] << endl;
    dnrsavedata.close();

    dnrsavedata.open("donorlastdonationtime.txt", ios::out | ios::app);
    dnrsavedata << lstdn[elements] << endl;
    dnrsavedata.close();

    elements++;

    elementsfile.open("elems.txt", ios::out);
    elementsfile << elements;
    elementsfile.close();
}

void admin::updtdnr()
{
    int idkey;

    cout << "-----------------------------------" << endl;
    cout << "        update data of donor       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "enter id of donor you need to update his data: " << endl;
    cin >> idkey;



    bool valuefound = false;
    int searchedindex;

    elementsfile.open("elems.txt", ios::in);
    elementsfile >> elements;
    elementsfile.close();

    dnrsavedata.open("donorname.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> name[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorpassword.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> password[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorid.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> ids[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorage.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> age[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donoranotherdisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> otherdis[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorbloodtype.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> bloods[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donordisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> diseases[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorgender.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> gender[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorlastdonationtime.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> lstdn[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donormail.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> mails[i];
    }
    dnrsavedata.close();


    for (int i = 0; (i < elements) && !valuefound; i++)
    {
        if (idkey == ids[i])
        {
            searchedindex = i;
            valuefound = true;
        }
    }
    if (valuefound)
    {
        int a;
        cout << "choose what do you need to update for donor:" << endl;
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
        cin >> a;

        while (a < 1 || a > 10)
        {
            cout << endl;
            cout << "**ERROR** - Invalid option." << endl;
            updtdnr();
        }

        if (a == 1)
        {
            int d;
            cout << "enter the new id" << endl;
            cin >> d;
            ids[searchedindex] = d;
            dnrsavedata.open("donorid.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << ids[i] << endl;
            }
            dnrsavedata.close();
            cout << "id updated successfully" << endl;
        }

        if (a == 2)
        {
            string b;
            cout << "enter the new name" << endl;
            cin >> b;
            name[searchedindex] = b;
            dnrsavedata.open("donorname.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << name[i] << endl;
            }
            dnrsavedata.close();
            cout << "name updated successfully" << endl;
        }
        if (a == 3)
        {
            string c;
            cout << "enter the new email" << endl;
            cin >> c;
            mails[searchedindex] = c;
            dnrsavedata.open("donormail.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << mails[i] << endl;
            }
            dnrsavedata.close();
            cout << "email updated successfully" << endl;

        }
        if (a == 4)
        {
            string m;
            cout << "enter the new password" << endl;
            cin >> m;
            password[searchedindex] = m;
            dnrsavedata.open("donorpassword.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << password[i] << endl;
            }
            dnrsavedata.close();
            cout << "password updated successfully" << endl;

        }
        if (a == 5)
        {
            int e;
            cout << "enter the new age" << endl;
            cin >> e;
            age[searchedindex] = e;
            dnrsavedata.open("donorage.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << age[i] << endl;
            }
            dnrsavedata.close();
            cout << "age updated successfully" << endl;

        }
        if (a == 6)
        {
            string k;
            cout << "enter the new gender" << endl;
            cin >> k;
            gender[searchedindex] = k;
            dnrsavedata.open("donorgender.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << gender[i] << endl;
            }
            dnrsavedata.close();
            cout << "gender updated successfully" << endl;
        }
        if (a == 7)
        {
            string f;
            cout << "enter the new blood type" << endl;
            cin >> f;
            bloods[searchedindex] = f;
            dnrsavedata.open("donorbloodtype.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << bloods[i] << endl;
            }
            dnrsavedata.close();
            cout << "blood type updated successfully" << endl;
        }
        if (a == 8)
        {
            string g;
            cout << "enter the new disease of listed disease" << endl;
            cin >> g;
            diseases[searchedindex] = g;
            dnrsavedata.open("donordisease.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << diseases[i] << endl;
            }
            dnrsavedata.close();
            cout << "diseases updated successfully" << endl;
        }
        if (a == 9)
        {
            string h;
            cout << "enter the new medicine or disease" << endl;
            cin >> h;
            otherdis[searchedindex] = h;
            dnrsavedata.open("donoranotherdisease.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << otherdis[i] << endl;
            }
            dnrsavedata.close();
            cout << "the medicine or another disease updated successfully" << endl;
        }
        if (a == 10)
        {
            int i;
            cout << "enter the new duration of last donation" << endl;
            cin >> i;
            lstdn[searchedindex] = i;
            dnrsavedata.open("donorlastdonationtime.txt", ios::out);
            for (int i = 0; i < elements; i++)
            {
                dnrsavedata << lstdn[i] << endl;
            }
            dnrsavedata.close();
            cout << "the duration of last donation updated successfully" << endl;
        }
    }
    else
    {
        cout << "invalid id" << endl;
        updtdnr();
    }
    about_donor();
}

void admin::deldnr()
{
    int idkey;

    cout << "-----------------------------------" << endl;
    cout << "        delete data of donor       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "enter id of donor you need to delete his data: " << endl;
    cin >> idkey;



    bool valuefound = false;
    int searchedindex;

    elementsfile.open("elems.txt", ios::in);
    elementsfile >> elements;
    elementsfile.close();

    dnrsavedata.open("donorname.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> name[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorpassword.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> password[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorid.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> ids[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorage.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> age[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donoranotherdisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> otherdis[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorbloodtype.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> bloods[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donordisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> diseases[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorgender.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> gender[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorlastdonationtime.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> lstdn[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donormail.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> mails[i];
    }
    dnrsavedata.close();


    for (int i = 0; (i < elements) && !valuefound; i++)
    {
        if (idkey == ids[i])
        {
            searchedindex = i;
            valuefound = true;
        }
    }
    if (valuefound)
    {
        for (int i = searchedindex; i < elements - 1; i++)
        {
            age[i] = age[i + 1];
            bloods[i] = bloods[i + 1];
            diseases[i] = diseases[i + 1];
            gender[i] = gender[i + 1];
            ids[i] = ids[i + 1];
            lstdn[i] = lstdn[i + 1];
            mails[i] = mails[i + 1];
            name[i] = name[i + 1];
            otherdis[i] = otherdis[i + 1];
            password[i] = password[i + 1];
        }
        elements--;

        dnrsavedata.open("donorid.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << ids[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donorname.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << name[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donormail.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << mails[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donorpassword.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << password[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donorage.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << age[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donorgender.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << gender[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donorbloodtype.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << bloods[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donordisease.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << diseases[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donoranotherdisease.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << otherdis[i] << endl;
        }
        dnrsavedata.close();

        dnrsavedata.open("donorlastdonationtime.txt", ios::out);
        for (int i = 0; i < elements; i++)
        {
            dnrsavedata << lstdn[i] << endl;
        }
        dnrsavedata.close();

        elementsfile.open("elems.txt", ios::out);
        elementsfile << elements;
        elementsfile.close();

        cout << "data of donor who has id: " << idkey << " was deleted." << endl;

    }
    else
    {
        cout << "invalid id" << endl;
        deldnr();

    }
    about_donor();
}

void admin::displaydnr()
{
    int idkey;

    cout << "-----------------------------------" << endl;
    cout << "        display data of donor       " << endl;
    cout << "-----------------------------------" << endl;
    cout << "enter id of donor you need to display his data: " << endl;
    cin >> idkey;



    bool valuefound = false;
    int searchedindex;

    elementsfile.open("elems.txt", ios::in);
    elementsfile >> elements;
    elementsfile.close();

    dnrsavedata.open("donorname.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> name[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorpassword.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> password[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorid.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> ids[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorage.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> age[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donoranotherdisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> otherdis[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorbloodtype.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> bloods[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donordisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> diseases[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorgender.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> gender[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorlastdonationtime.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> lstdn[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donormail.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> mails[i];
    }
    dnrsavedata.close();


    for (int i = 0; (i < elements) && !valuefound; i++)
    {
        if (idkey == ids[i])
        {
            searchedindex = i;
            valuefound = true;
        }
    }
    if (valuefound)
    {
        cout << "name : " << name[searchedindex] << endl;
        cout << "id : " << ids[searchedindex] << endl;
        cout << "age : " << age[searchedindex] << endl;
        cout << "email : " << mails[searchedindex] << endl;
        cout << "password : " << password[searchedindex] << endl;
        cout << "gender : " << gender[searchedindex] << endl;
        cout << "blood type : " << bloods[searchedindex] << endl;
        cout << "last donation time (in months) : " << lstdn[searchedindex] << endl;
        cout << "diseases : " << diseases[searchedindex] << endl;
        cout << "other diseases or medicine : " << otherdis[searchedindex] << endl;

    }
    else
    {
        cout << "invalid id" << endl;
        displaydnr();

    }
    about_donor();
}

void admin::displayalldnrs()
{
    elementsfile.open("elems.txt", ios::in);
    elementsfile >> elements;
    elementsfile.close();

    dnrsavedata.open("donorname.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> name[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorpassword.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> password[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorid.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> ids[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorage.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> age[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donoranotherdisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> otherdis[i];

    }
    dnrsavedata.close();


    dnrsavedata.open("donorbloodtype.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> bloods[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donordisease.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> diseases[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorgender.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> gender[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donorlastdonationtime.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> lstdn[i];
    }
    dnrsavedata.close();


    dnrsavedata.open("donormail.txt", ios::in);
    for (int i = 0; i < elements; i++)
    {
        dnrsavedata >> mails[i];
    }
    dnrsavedata.close();

    for (int i = 0; i < elements; i++)
    {
        cout << "name : " << name[i] << endl;
        cout << "id : " << ids[i] << endl;
        cout << "age : " << age[i] << endl;
        cout << "email : " << mails[i] << endl;
        cout << "password : " << password[i] << endl;
        cout << "gender : " << gender[i] << endl;
        cout << "blood type : " << bloods[i] << endl;
        cout << "last donation time (in months) : " << lstdn[i] << endl;
        cout << "diseases : " << diseases[i] << endl;
        cout << "other diseases or medicine : " << otherdis[i] << endl;
    }

    about_donor();
}

void admin::about_recipient()
{
    int pck;
    cout << "-------------------------------------" << endl;
    cout << "       control data of recipient     " << endl;
    cout << "-------------------------------------" << endl;
    cout << "1.update data of recipient." << endl;
    cout << "2.delete recipient." << endl;
    cout << "3.display recipient data." << endl;
    cout << "4.display all recipient data." << endl;
    cout << "5.go back" << endl;
    cin >> pck;

    aboutrecipentval(pck);
    aboutrecipentpick(pck);

}
void admin::aboutrecipentval(int pck)
{
    int x = pck;
    while (x < 1 || x > 6)
    {
        cout << endl;
        cout << "**ERROR** - Invalid option. Please enter 1, 2,3,4,5, or 6.\n" << endl;
        about_donor();
    }
}

void admin::aboutrecipentpick(int pck)
{

    int d = pck;

    switch (d)
    {

    case 1:
        update_recipient();
        break;
    case 2:
         delete_recipient();
        break;
    case 3:
        break;
    case 4:
        displayrecipient();
        break;
    default:
        cout << "INTERNAL ERROR" << endl;
        break;
    }
}

void admin::return_data()
{
    string d;
    id.open("ID.txt", ios::in);
    while (!id.eof())
    {
        id >> d;
        ID_rec.Append(d);
    }
    id.close();
    frist.open("FristName.txt", ios::in);
    while (!frist.eof())
    {
        frist >> d;
        Frist.Append(d);
    }
    frist.close();
    last.open("LastName.txt", ios::in);
    while (!last.eof())
    {
        last >> d;
        Last.Append(d);
    }
    last.close();
    eMail.open("Email.txt", ios::in);
    while (!eMail.eof())
    {
        eMail >> d;
        EMail.Append(d);
    }
    eMail.close();
    pass.open("Password.txt", ios::in);
    while (!pass.eof())
    {
        pass >> d;
        PasSword.Append(d);
    }
    pass.close();
    aGe.open("Age.txt", ios::in);
    while (!aGe.eof())
    {
        aGe >> d;
        AGe.Append(d);
    }
    aGe.close();
    geNder.open("Gender.txt", ios::in);
    while (!geNder.eof())
    {
        geNder >> d;
        GeNder.Append(d);
    }
    geNder.close();
    blood.open("FristName.txt", ios::in);
    while (!blood.eof())
    {
        blood >> d;
        Blood_Type.Append(d);
    }
    blood.close();
    hospiTal.open("FristName.txt", ios::in);
    while (!hospiTal.eof())
    {
        hospiTal >> d;
        HospiTal.Append(d);
    }
    hospiTal.close();
    doctor.open("FristName.txt", ios::in);
    while (!doctor.eof())
    {
        doctor >> d;
        DocTor.Append(d);
    }
    doctor.close();
}

void admin::update_recipient()
{
    return_data();
    string username, password;
    bool disfind = true;
    cout << "To keep your data private, enter your email and password : " << endl;
    cout << "please enter your Email : ";
    cin >> username;
    cout << "enter your password : ";
    cin >> password;
    Reci data;
    for (int i = 0; i < ID_rec.length(); i++)
    {
        if (EMail.At(i) == username && PasSword.At(i) == password)
        {
            cout << "enter new data" << endl;
            ID_rec.DeleteAt(i);
            cout << "ID : ";
            cin >> data.id;
            ID_rec.insertAt(i, data.id);
            Frist.DeleteAt(i);
            cout << "Frist Name : ";
            cin >> data.frist_name;
            Frist.insertAt(i, data.frist_name);
            Last.DeleteAt(i);
            cout << "Last Name : ";
            cin >> data.last_name;
            Last.insertAt(i, data.last_name);
            EMail.DeleteAt(i);
            cout << "Email : ";
            cin >> data.Email;
            EMail.insertAt(i, data.Email);
            PasSword.DeleteAt(i);
            cout << "Password : ";
            cin >> data.password;
            PasSword.insertAt(i, data.password);
            AGe.DeleteAt(i);
            cout << "Age : ";
            cin >> data.age;
            AGe.insertAt(i, data.age);
            GeNder.DeleteAt(i);
            cout << "Gender : ";
            cin >> data.gender;
            GeNder.insertAt(i, data.gender);
            Blood_Type.DeleteAt(i);
            cout << "Blood type : ";
            cin >> data.blood_type;
            Blood_Type.insertAt(i, data.blood_type);
            HospiTal.DeleteAt(i);
            cout << "Hospital : ";
            cin >> data.hospital;
            HospiTal.insertAt(i, data.hospital);
            DocTor.DeleteAt(i);
            cout << "Doctor of the case : ";
            cin >> data.doctor_of_the_case;
            DocTor.insertAt(i, data.doctor_of_the_case);
            disfind = false;
            break;
        }
    }
    save_update();
    if (disfind)
    {
        cout << "Email and password is incorrect" << endl;
    }
    admin_main();
}

void admin::delete_recipient()
{
    return_data();
    bool disfind = true;
    string username, password;
    cout << "To keep your data private, enter your email and password : " << endl;
    cout << "please enter your Email : ";
    cin >> username;
    cout << "enter your password : ";
    cin >> password;
    for (int i = 0; i < ID_rec.length(); i++)
    {
        if (EMail.At(i) == username && PasSword.At(i) == password)
        {
            ID_rec.DeleteAt(i);
            Frist.DeleteAt(i);
            Last.DeleteAt(i);
            EMail.DeleteAt(i);
            PasSword.DeleteAt(i);
            AGe.DeleteAt(i);
            GeNder.DeleteAt(i);
            Blood_Type.DeleteAt(i);
            HospiTal.DeleteAt(i);
            DocTor.DeleteAt(i);
            cout << "Delete account successful" << endl;
            disfind = false;
            break;
        }
    }
    save_delete();
    if (disfind)
    {
        cout << "Email and password is incorrect" << endl;
    }
    admin_main();
}

void admin::save_update()
{
    id.open("ID.txt", ios::out);
    for (int i = 0; i < ID_rec.length(); i++)
    {
        id << ID_rec.At(i) << endl;
    }
    id.close();
    frist.open("FristName.txt", ios::out);
    for (int i = 0; i < Frist.length(); i++)
    {
        frist << Frist.At(i) << endl;
    }
    frist.close();
    last.open("LastName.txt", ios::out);
    for (int i = 0; i < Last.length(); i++)
    {
        last << Last.At(i) << endl;
    }
    last.close();
    eMail.open("Email.txt", ios::out);
    for (int i = 0; i < EMail.length(); i++)
    {
        eMail << EMail.At(i) << endl;
    }
    eMail.close();
    pass.open("Password.txt", ios::out);
    for (int i = 0; i < PasSword.length(); i++)
    {
        pass << PasSword.At(i) << endl;
    }
    pass.close();
    aGe.open("Age.txt", ios::out);
    for (int i = 0; i < AGe.length(); i++)
    {
        aGe << AGe.At(i) << endl;
    }
    aGe.close();
    geNder.open("Gender.txt", ios::out);
    for (int i = 0; i < GeNder.length(); i++)
    {
        geNder << GeNder.At(i) << endl;
    }
    geNder.close();
    blood.open("bloodtype.txt", ios::out);
    for (int i = 0; i < Blood_Type.length(); i++)
    {
        blood << Blood_Type.At(i) << endl;
    }
    blood.close();
    hospiTal.open("Hospital.txt", ios::out);
    for (int i = 0; i < HospiTal.length(); i++)
    {
        hospiTal << HospiTal.At(i) << endl;
    }
    hospiTal.close();
    doctor.open("Doctor.txt", ios::out);
    for (int i = 0; i < DocTor.length(); i++)
    {
        doctor << DocTor.At(i) << endl;
    }
    doctor.close();
}

void admin::save_delete()
{
    id.open("ID.txt", ios::out);
    for (int i = 0; i < ID_rec.length() - 1; i++)
    {
        id << ID_rec.At(i) << endl;
    }
    id.close();
    frist.open("FristName.txt", ios::out);
    for (int i = 0; i < Frist.length() - 1; i++)
    {
        frist << Frist.At(i) << endl;
    }
    frist.close();
    last.open("LastName.txt", ios::out);
    for (int i = 0; i < Last.length() - 1; i++)
    {
        last << Last.At(i) << endl;
    }
    last.close();
    eMail.open("Email.txt", ios::out);
    for (int i = 0; i < EMail.length() - 1; i++)
    {
        eMail << EMail.At(i) << endl;
    }
    eMail.close();
    pass.open("Password.txt", ios::out);
    for (int i = 0; i < PasSword.length() - 1; i++)
    {
        pass << PasSword.At(i) << endl;
    }
    pass.close();
    aGe.open("Age.txt", ios::out);
    for (int i = 0; i < AGe.length() - 1; i++)
    {
        aGe << AGe.At(i) << endl;
    }
    aGe.close();
    geNder.open("Gender.txt", ios::out);
    for (int i = 0; i < GeNder.length() - 1; i++)
    {
        geNder << GeNder.At(i) << endl;
    }
    geNder.close();
    blood.open("bloodtype.txt", ios::out);
    for (int i = 0; i < Blood_Type.length() - 1; i++)
    {
        blood << Blood_Type.At(i) << endl;
    }
    blood.close();
    hospiTal.open("Hospital.txt", ios::out);
    for (int i = 0; i < HospiTal.length() - 1; i++)
    {
        hospiTal << HospiTal.At(i) << endl;
    }
    hospiTal.close();
    doctor.open("Doctor.txt", ios::out);
    for (int i = 0; i < DocTor.length() - 1; i++)
    {
        doctor << DocTor.At(i) << endl;
    }
    doctor.close();
}

void admin::displayrecipient()
{
    return_data();
    for (int i = 0; i < ID_rec.length()-1; i++)
    {
        cout << "Recipent-" << i + 1 << "  ID : " << ID_rec.At(i) << "  Frist Name : " << Frist.At(i) << "  Last Name : " << Last.At(i) << endl;
        cout << "  Email : " << EMail.At(i) << "  password : " << PasSword.At(i) << "  Age : " << AGe.At(i) << "  Gender : " << GeNder.At(i) << endl;
        cout << "  Blood type : " << Blood_Type.At(i) << "  Hospital : " << HospiTal.At(i) << "  Doctor Name : " << DocTor.At(i) << endl;
    }
    admin_main();
}


