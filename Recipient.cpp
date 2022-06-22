#include "Recipient.h"
#include "Arrlist.cpp"
#include <fstream>
Arrlist<string> Frist_Name, Last_Name, Email, ID, Age, Password, Gender, Blood_type, Hospital, Doctor, Type, Received_Date, Expiry_date;
Arrlist<int> Quantity;
fstream Id, Frist_name, Last_name, email, password, age, gender, blood_type, hospital, Doctor_of, type, quantity, recived, expiry;
Recipient::Recipient()
{
	
}

void Recipient::user()
{
	char o;
	cout << "Register enter r or login enter l : ";
	cin >> o;
	switch (o)
	{
	case 'r':
		Register();
		break;
	case 'l':
		login();
		break;
	default:
		cout << "sorry, pleasa close app and enter r or l " << endl;
		break;
	}
}

void Recipient::operation()
{
	cout << "enter";
	int operation;
	for(int i=0;i == i;i++)
	{
		cout << "Choose the operation you want to perform :" << endl;
		cout << "Update data enter 1 " << endl;
		cout << "Delete Account enter 2" << endl;
		cout << "search blood type enter 3" << endl;
		cout << "display blood type available enter 4" << endl;
		cout << "Blood request enter 5" << endl;
		cout << "quit enter 6" << endl;
		cout << "enter operation : ";
		cin >> operation;
		if(operation==1)
		{
			Update_data();
		}
		else if (operation == 2)
		{
			delete_Account();
			break;
		}
		else if (operation == 3)
		{
			search_Blood();
		}
		else if(operation == 4)
		{
			Display();
		}
		else if(operation == 5)
		{
			requast_blood();
		}
		else if(operation == 6)
		{
			break;
		}
		else
		{
			cout << "this operation isn't found" << endl;
		}
	}
}

void Recipient::Register()
{
	cout << "-------------------------------------" << endl;
	cout << "         New Account Recipient       " << endl;
	cout << "-------------------------------------" << endl;
	cout << "please enter your data" << endl;
	cout << "ID : ";
	cin >> data.id;
	ID.Append(data.id);
	cout << "Frist Name : ";
	cin >> data.frist_name;
	Frist_Name.Append(data.frist_name);
	cout << "Last Name : ";
	cin >> data.last_name;
	Last_Name.Append(data.last_name);
	cout << "Email : ";
	cin >> data.Email;
	Email.Append(data.Email);
	cout << "Password : ";
	cin >> data.password;
	Password.Append(data.password);
	cout << "Age : ";
	cin >> data.age;
	Age.Append(data.age);
	cout << "Gender : ";
	cin >> data.gender;
	Gender.Append(data.gender);
	cout << "Blood type : ";
	cin >> data.blood_type;
	Blood_type.Append(data.blood_type);
	cout << "Hospital : ";
	cin >> data.hospital;
	Hospital.Append(data.hospital);
	cout << "Doctor of the case : ";
	cin >> data.doctor_of_the_case;
	Doctor.Append(data.doctor_of_the_case);
	Savedata();
	returndata();
	operation();
}

void Recipient::Savedata()
{
	Id.open("ID.txt", ios::app);
	Id << ID.At(0) << endl;
	Id.close();
	Frist_name.open("FristName.txt", ios::app);
	Frist_name << Frist_Name.At(0) << endl;
	Frist_name.close();
	Last_name.open("LastName.txt", ios::app);
	Last_name << Last_Name.At(0) << endl;
	Last_name.close();
	email.open("Email.txt", ios::app);
	email << Email.At(0) << endl;
	email.close();
	password.open("Password.txt", ios::app);
	password << Password.At(0) << endl;
	password.close();
	age.open("Age.txt", ios::app);
	age << Age.At(0) << endl;
	age.close();
	gender.open("Gender.txt", ios::app);
	gender << Gender.At(0) << endl;
	gender.close();
	blood_type.open("bloodtype.txt", ios::app);
	blood_type << Blood_type.At(0) << endl;
	blood_type.close();
	hospital.open("Hospital.txt", ios::app);
	hospital << Hospital.At(0) << endl;
	hospital.close();
	Doctor_of.open("Doctor.txt", ios::app);
	Doctor_of << Doctor.At(0) << endl;
	Doctor_of.close();
}

void Recipient::returndata()
{
	string data;
	Id.open("ID.txt", ios :: in);
	while (! Id.eof())
	{
		Id >> data;
		ID.Append(data);
	}
	Id.close();
	Frist_name.open("FristName.txt", ios::in);
	while (!Frist_name.eof())
	{
		Frist_name >> data;
		Frist_Name.Append(data);
	}
	Frist_name.close();
	Last_name.open("LastName.txt", ios::in);
	while (!Last_name.eof())
	{
		Last_name >> data;
		Last_Name.Append(data);
	}
	Last_name.close();
	email.open("Email.txt", ios::in);
	while (!email.eof())
	{
		email >> data;
		Email.Append(data);
	}
	email.close();
	password.open("Password.txt", ios::in);
	while (!password.eof())
	{
		password >> data;
		Password.Append(data);
	}
	password.close();
	age.open("Age.txt", ios::in);
	while (!age.eof())
	{
		age >> data;
		Age.Append(data);
	}
	age.close();
	gender.open("Gender.txt", ios::in);
	while (!gender.eof())
	{
		gender >> data;
		Gender.Append(data);
	}
	gender.close();
	blood_type.open("Bloodtype.txt", ios::in);
	while (!blood_type.eof())
	{
		blood_type >> data;
		Blood_type.Append(data);
	}
	blood_type.close();
	hospital.open("Hospital.txt", ios::in);
	while (!hospital.eof())
	{
		hospital >> data;
		Hospital.Append(data);
	}
	hospital.close();
	Doctor_of.open("Doctor.txt", ios::in);
	while (!Doctor_of.eof())
	{
		Doctor_of >> data;
		Doctor.Append(data);
	}
	Doctor_of.close();
}

void Recipient::login()
{	
	cout << "          ---------------------------------          " << endl;
	cout << "               Recipitent login page                 " << endl;
	cout << "          ---------------------------------          " << endl;
	bool found = true;
	returndata();
	for(int i=0;i<5;i++)
	{
		string username, password;
		cout << "please enter your Email : ";
		cin >> username;
		cout << "enter your password : ";
		cin >> password;
		if(checklogin(username, password)==false)
		{
			cout << "login successfully" << endl;
			found = false;
			operation();
			break;
		}
		if(i != 4)
		{
			cout << "please enter your Email and password again : "<< endl;
		} 
	}
	if(found)
	{
		cout << "sorry,you enter Email and password incorrect please  close app and return again " << endl;
	}

}

bool Recipient::checklogin(string username,string password)
{
	
	bool disfind = true;
	
	
	for (int i = 0; i < Email.length(); i++)
	{
		if (Email.At(i) == username && Password.At(i) == password) 
		{
			disfind = false;
			break;
		}
	}
	return disfind;
}

void Recipient::Update_data()
{
	
	string username, password;
	cout << "To keep your data private, enter your email and password : " << endl;
	cout << "please enter your Email : ";
	cin >> username;
	cout << "enter your password : ";
	cin >> password;
	Rec new_data;
	for (int i = 0; i < ID.length(); i++)
	{
		if (Email.At(i) == username && Password.At(i) == password)
		{
			cout << "enter new data" << endl;
			ID.DeleteAt(i);
			cout << "ID : ";
			cin >> new_data.id;
			ID.insertAt(i, new_data.id);
			Frist_Name.DeleteAt(i);
			cout << "Frist Name : ";
			cin >> new_data.frist_name;
			Frist_Name.insertAt(i, new_data.frist_name);
			Last_Name.DeleteAt(i);
			cout << "Last Name : " ;
			cin >> new_data.last_name;
			Last_Name.insertAt(i, new_data.last_name);
			Email.DeleteAt(i);
			cout << "Email : ";
			cin >> new_data.Email;
			Email.insertAt(i, new_data.Email);
			Password.DeleteAt(i);
			cout << "Password : ";
			cin >> new_data.password;
			Password.insertAt(i, new_data.password);
			Age.DeleteAt(i);
			cout << "Age : ";
			cin >> new_data.age;
			Age.insertAt(i, new_data.age);
			Gender.DeleteAt(i);
			cout << "Gender : ";
			cin >> new_data.gender;
			Gender.insertAt(i, new_data.gender);
			Blood_type.DeleteAt(i);
			cout << "Blood type : ";
			cin >> new_data.blood_type;
			Blood_type.insertAt(i, new_data.blood_type);
			Hospital.DeleteAt(i);
			cout << "Hospital : ";
			cin >> new_data.hospital;
			Hospital.insertAt(i, new_data.hospital);
			Doctor.DeleteAt(i);
			cout << "Doctor of the case : ";
			cin >> new_data.doctor_of_the_case;
			Doctor.insertAt(i, new_data.doctor_of_the_case);
			break;
		}
	}
	save_update();
}

void Recipient::save_update()
{
	Id.open("ID.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		Id << ID.At(i) << endl;
	}
	Id.close();
	Frist_name.open("FristName.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		Frist_name << Frist_Name.At(i) << endl;
	}
	Frist_name.close();
	Last_name.open("LastName.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		Last_name << Last_Name.At(i) << endl;
	}
	Last_name.close();
	email.open("Email.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		email << Email.At(i) << endl;
	}
	email.close();
	password.open("Password.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		password << Password.At(i) << endl;
	}
	password.close();
	age.open("Age.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		age << Age.At(i) << endl;
	}
	age.close();
	gender.open("Gender.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		gender << Gender.At(i) << endl;
	}
	gender.close();
	blood_type.open("bloodtype.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		blood_type << Blood_type.At(i) << endl;
	}
	blood_type.close();
	hospital.open("Hospital.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		hospital << Hospital.At(i) << endl;
	}
	hospital.close();
	Doctor_of.open("Doctor.txt", ios::out);
	for (int i = 0; i < ID.length(); i++)
	{
		Doctor_of << Doctor.At(i) << endl;
	}
	Doctor_of.close();
}

void Recipient::delete_Account()
{
	string username, password;
	cout << "To keep your data private, enter your email and password : " << endl;
	cout << "please enter your Email : ";
	cin >> username;
	cout << "enter your password : ";
	cin >> password;
	for(int i=0 ; i<ID.length() ; i++)
	{
		if(Email.At(i) == username && Password.At(i) == password)
		{
			ID.DeleteAt(i);
			Frist_Name.DeleteAt(i);
			Last_Name.DeleteAt(i);
			Email.DeleteAt(i);
			Password.DeleteAt(i);
			Age.DeleteAt(i);
			Gender.DeleteAt(i);
			Blood_type.DeleteAt(i);
			Hospital.DeleteAt(i);
			Doctor.DeleteAt(i);
			cout << "Delete account successful" << endl;
			break;
		}
	}
	save_data();
}

void Recipient::save_data()
{
	Id.open("ID.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		Id << ID.At(i) << endl;
	}
	Id.close();
	Frist_name.open("FristName.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		Frist_name << Frist_Name.At(i) << endl;
	}
	Frist_name.close();
	Last_name.open("LastName.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		Last_name << Last_Name.At(i) << endl;
	}
	Last_name.close();
	email.open("Email.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		email << Email.At(i) << endl;
	}
	email.close();
	password.open("Password.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		password << Password.At(i) << endl;
	}
	password.close();
	age.open("Age.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		age << Age.At(i) << endl;
	}
	age.close();
	gender.open("Gender.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		gender << Gender.At(i) << endl;
	}
	gender.close();
	blood_type.open("bloodtype.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		blood_type << Blood_type.At(i) << endl;
	}
	blood_type.close();
	hospital.open("Hospital.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		hospital << Hospital.At(i) << endl;
	}
	hospital.close();
	Doctor_of.open("Doctor.txt", ios::out);
	for (int i = 0; i < ID.length()-1; i++)
	{
		Doctor_of << Doctor.At(i) << endl;
	}
	Doctor_of.close();
}

void Recipient::search_Blood()
{
	Blood_data();
	string type;
	bool disfind = true;
	cout << "Enter the blood type you want to search for : ";
	cin >> type;

	for (int  i = 0; i < Received_Date.length(); i++)
	{
		if (Type.At(i) == type)
		{
			cout << "This blood type is available" << endl;
			cout << Type.At(i) << "   ";
			cout << Quantity.At(i) << "   ";
			cout << Received_Date.At(i) << "   ";
			cout << Expiry_date.At(i) << endl;
			disfind = false;
			break;
		}
	}
	if (disfind)
	{
		cout << "This blood type is not available" << endl;
	}
}

void Recipient::Blood_data()
{
	string data;
	int d;
	type.open("editBloodtype.txt", ios::in);
	while (!type.eof())
	{
		type >> data;
		Type.Append(data);
	}
	type.close();
	quantity.open("editbloodquantity.txt", ios::in);
	while (!quantity.eof())
	{
		quantity >> d;
		Quantity.Append(d);
	}
	quantity.close();
	recived.open("editRecevieddate.txt", ios::in);
	while (!recived.eof())
	{
		recived >> data;
		Received_Date.Append(data);
	}
	recived.close();
	expiry.open("editExpirydate.txt", ios::in);
	while (!expiry.eof())
	{
		expiry >> data;
		Expiry_date.Append(data);
	}
	expiry.close();


}

void Recipient::Display()
{
	Blood_data();
	for (int i = 0; i < 8; i++)
	{
		cout << Type.At(i) << "   " << Quantity.At(i) << "   " << Received_Date.At(i) << "   " << Expiry_date.At(i) << endl;
	}
}

void Recipient::requast_blood()
{
	Blood_data();
	string blood_type, confirm;
	int quantity;
	bool requast =true;
	cout << "enter blood type : ";
	cin >> blood_type;
	cout << "enter quantity : ";
	cin >> quantity;
	cout << "enter confirm hospital : ";
	cin >> confirm;
	for(int i = 0; i <Type.length();i++)
	{
		if(Type.At(i)==blood_type)
		{
			if (Quantity.At(i) >= quantity)
			{
				if (confirm == "yes")
				{
					cout << "Your request is being processed" << endl;
					requast = false;
					break;
				}
			}
		}
	}
	if (requast)
	{
		cout << "sorry The amount of blood required is not available" << endl;
	}
}

Recipient::~Recipient()
{
}
