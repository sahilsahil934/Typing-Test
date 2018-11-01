
#include "typing.h"

Ty obj;

Ty *start = NULL, *last = NULL;

void main_menu()
{
	int choice;
	do
	{
		system("cls");
		cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";	
		cout<<"\n\n\t\t\t\t\t\t========================== MAIN MENU =================================";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t Press 1 to Register";
		cout<<"\n\t\t\t\t\t\t\t\t\t Press 2 to LogIn";
		cout<<"\n\t\t\t\t\t\t\t\t\t Press 3 to Exit";
		cout<<"\n\t\t\t\t\t\t\t\t\t Enter Choice ";
		choice = getch() - 48;
	
		switch(choice)
		{
			case 1:
				{
					obj.reg();
					break;
				}
			case 2:
				{
					obj.login();
					break;
				}
			case 3:
				{
					exit(0);
				}
			default:
				{
					cout<<"\n Wrong Input";
				}
		}
	}
	while (choice != '3');
}

void Ty :: usermenu(char *user)
{
	system("cls");
	fstream f;
	f.open(user, ios::app|ios::in);
	int choice;
		do
	{
		cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";	
		cout<<"\n\n\t\t\t\t\t\t========================== MENU =================================";
		cout<<"\n\n\t\t\t\t\t\t\t\t\t Press 1 to Start Ty";
		cout<<"\n\t\t\t\t\t\t\t\t\t Press 2 to See Profile";
		cout<<"\n\t\t\t\t\t\t\t\t\t Press 3 to Logout";
		cout<<"\n\t\t\t\t\t\t\t\t\t Press 4 to Exit";
		cout<<"\n\t\t\t\t\t\t\t\t\t Enter Choice ";
		choice = getch() - 48;
	
		switch(choice)
		{
			case 1:
				{
					obj.listTest(user);
					break;
				}
			case 2:
				{
					obj.myprofile(user);
					break;
				}
			case 3:
				{
      				main_menu();
					break;
				}
			case 4:
				{
					exit(0);
				}
			default:
				{
					cout<<"\n Wrong Input";
				}
		}
	}
	while (choice != '3');

}

void Ty :: myprofile(char *user)
{
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";
	ifstream f;
	f.open(user);
	f.read((char*)&obj, sizeof(obj));
	cout<<"\n Name : "<<fname<<" "<<lname;
	cout<<"\n User name : "<<username;
	char ch;
	f.get(ch);
	cout<<"\n Your Record \n";
	while (!f.eof())
	{
		cout<<ch;
		f.get(ch);
		
	}
	cout<<"\n Press any key to exit ";
	system("pause");
}


void Ty :: listTest(char *user)
{
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";	
	fstream f;
	f.open("test.txt", ios::in);
	
	char ch;
	f.get(ch);
	int count = 0;
	start = NULL;
	while (!f.eof())
	{
		Ty *newnode = new Ty;
		int i = 0;
		while (ch != '\n')
		{
			newnode->tests[i] = ch;
			f.get(ch);
			i++;
		}
		newnode->num = count;
		newnode->next = NULL;
		
		if (start == NULL)
		{
			start = newnode;
			last = newnode;
		}
		else
		{
			last->next = newnode;
			last = newnode;
		}
		count++;
		f.get(ch);
	}
	f.close();
	
	Ty *ptr;
	ptr = start;
	cout<<"\n";
	while(ptr != NULL)
	{
		cout<<ptr->num<<"-"<<ptr->tests<"\n";
		ptr = ptr->next;
		cout<<"\n";
	}
	char choose[2];
	cout<<"\n Choose Test ";
	cin>>choose;
	Test(choose, user);
	usermenu(user);
	system("pause");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";
}

void Ty :: reg()
{
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";
	fstream f;
	cout<<"\n Enter First name ";
	cin>>fname;
	cout<<"\n Enter last name : ";
	cin>>lname;
	cout<<"\n Enter Username :";
	cin>>username;
	f.open(username, ios::in);
	if (f)
	{
		cout<<"\n User Already Exist\n";
		char opt;
		cout<<"\n Press X to return to main menu or any other key to try again: ";
		cin>>opt;
		if (opt == 'x' || opt == 'X')
		{
			main_menu();
		}
		system("pause");
		f.close();
		reg();
	}
	cout<<"\n Enter password : ";
	cin>>password;
	
	f.open(username, ios::out);
	if(!f)
	{
		cout<<"\n User Not created\n";
		reg();
	}
	f.write((char*)&obj, sizeof(obj));
	cout<<"\n User Created Successfully";
	f.close();

	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************\n";
		system("pause");
}

void Ty :: login()
{
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";
	char user[20], pass[20];
	cout<<"\n Enter Username : ";
	cin>>user;
	fstream f;
	f.open(user, ios::in);
	if (!f)
	{
		cout<<"\n User does not exist!\n";
		char opt;
		cout<<"\n Press X to return to main menu or any other key to try again: ";
		cin>>opt;
		if (opt == 'x' || opt == 'X')
		{
			main_menu();
		}
		system("pause");
		f.close();
		login();
	}
	cout<<"\n Enter Password : ";
	cin>>pass;

	f.read((char*)&obj, sizeof(obj));
	if (strcmp(pass, password) == 0)
	{
		cout<<"\n Log IN Successful\n";
		system("pause");
		usermenu(user);
	}
	else
	{
		char opt;
		cout<<"\n Wrong Password\n";
		cout<<"\n Press X to return to main menu or any other key to try again: ";
		cin>>opt;
		if (opt == 'x' || opt == 'X')
		{
			main_menu();
		}
		system("pause");
		login();
	}

	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************";
	system("pause");
}

void Ty :: Test(char *value, char* user)
{
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************\n\n";
	fstream f,f1;
	int count = 0, wrong = 0, line;
	f.open(value, ios::in);
	if (!f)
	{
		cout<<"\n Nope";
		return;
	}
	char ch;
	f.get(ch);
	while (!f.eof())
	{
		cout<<ch;
		f.get(ch);
	}
	cout<<"\n How many lines do you want to write of above paragraph : ";
	cin>>line;
	
	cout<<"\n Start Writing ";
	cout<<"\n\n";
	f.close();
	f.open("check.txt",ios::out);
	char text[2000];
	cout<<"\n Press any key to start";
	system("pause");
	clock_t tStart = clock();
	while (count != line + 1)
	{
		gets(text);
		f<<text;
		f<<"\n";
		count++;
	}
	clock_t tend = clock();
	count = 0;
	f.close();
	
	ifstream f10, f20;
	string s1,s2, file1, file2;
	file1 = "check.txt";
	file2 = value;
	f10.open(file1.c_str());
	f20.open(file2.c_str());
	
	while (f10>>s2)
	{
		f20>>s1;
		if (s1 == s2)
		{
			count++;
		}
		else
		{
			wrong++;
		}
	}
	cout<<"\n No of words correct : "<<count;
	cout<<"\n No of words Incorrect : "<<wrong;
	float c1 = count;
	float avg = c1/(count + wrong) * 100;
	cout<<"\n Accuracy is : "<<avg<<" %";
	f.close();
	f1.close();
	f.open(user, ios::app);
	f<<"\n";
	f<<"This test result correct words : "<<count<<" Wrong words : "<<wrong<<" Accuracy : "<<avg;
	float time = (tend - tStart)/1000;
	float exact = time/60;
	int speed = count/exact;
	cout<<"\n Typing Time : "<<time<<" Seconds";
	f<<" Test Time : "<<time;
	cout<<"\n Speed : "<<speed<<" WPM";
	f<<" Speed : "<<speed<<" WPM";
	cout<<"\n\n\n\n\n\t\t\t\t\t\t*************************** TYPING TEST ******************************\n";
	system("pause");
}
		
