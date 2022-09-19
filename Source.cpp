#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

class user {
private:
	string name;
	string type;
	string userAccNum;
	vector <string> listsOfBook;
public:
	user() {
		name = "";
		type = "";
		userAccNum = "";
	}
	void userSetter(string n, string t, string uan, string naob) {
		name = n;
		type = t;
		userAccNum = uan;
		listsOfBook.push_back(naob);
	}
	void userInfo() {
		int j = 1;
		cout << "\n\t\tName: " << name << endl;
		cout << "\t\tType of the user: " << type << endl;
		cout << "\t\tUser Account number: " << userAccNum << endl;
		cout << "\t\tFollowing are the lists of the books previously issued: " << endl;
		for (int i = 0; i < listsOfBook.size(); i++) {
			cout << "\n\t\t"<< j <<") " << listsOfBook[i] << endl;
			j++;
		}
	}
};
vector<user> allUsersInfo;
void userInput() {
	user obj;
	string name;
	string type;
	string userAccNum;
	string nameOfthebook;
	cout << "\t\tEnter the name: ";
	cin.ignore();
	getline(cin, name);
	cout << "\t\tEnter the type: ";
	getline(cin, type);
	cout << "\t\tEnter the User Account number: ";
	getline(cin, userAccNum);
	cout << "\t\tEnter the name of the book: ";
	getline(cin, nameOfthebook);
	obj.userSetter(name, type, userAccNum, nameOfthebook);
	allUsersInfo.push_back(obj);
	
}
void displayAllUsers() {
	cout << "\n\t\tfollowing are All users in the system along side there issued books till now: ";
	for (int i = 0; i < allUsersInfo.size(); i++) {
		allUsersInfo[i].userInfo();
		cout << endl;
	}
}

class books {
private:
	string title,author,yearOfPub,ISNB,category,status,holder,noOfCopies;
public:
	books() {
		title = "";
		author = "";
		yearOfPub = "";
		ISNB = "";
		category = "";
		status = "";
		holder = "";
		noOfCopies = "";
	}
	void bookSetter(string t, string aut, string yofp, string isnb, string cat, string stat, string noc) {
		title = t;
		author = aut;
		yearOfPub = yofp;
		ISNB = isnb;
		category = cat;
		status = stat;
		noOfCopies = noc;
	}
	void bookInfo() {
		cout << "\t\tTitle: " << title << endl;
		cout << "\t\tAuthor: " << author << endl;
		cout << "\t\tYear of Publication: " << yearOfPub << endl;
		cout << "\t\tISNB: " << ISNB << endl;
		cout << "\t\tCategory of the book: " << category << endl;
		cout << "\t\tStatus: " << status << endl;
		cout << "\t\tNumber of copies: " << noOfCopies << endl;

	}
};
vector<books>allBooks;
void booksInput() {
	string title, author, yearOfPub, ISNB, category, status, noOfCopies;
	cout << "\t\tEnter the title of the book: " << title;
	cin.ignore();
	getline(cin, title);
	cout << "\t\tEnter the author of the book: " << author;
	getline(cin, author);
	cout << "\t\tEnter the Year of publication of the book: " << yearOfPub;
	getline(cin, yearOfPub);
	cout << "\t\tEnter the ISNB of the book: " << ISNB;
	getline(cin, ISNB);
	cout << "\t\tEnter the category of the book: " << category;
	getline(cin, category);
	cout << "\t\tEnter the status of the book: " << status;
	getline(cin, status);
	cout << "\t\tEnter the no of copies available: " << noOfCopies;
	getline(cin, noOfCopies);
	books obj;
	obj.bookSetter(title, author,yearOfPub, ISNB, category, status, noOfCopies);
	allBooks.push_back(obj);
}
void displayAllbooks() {
	cout << "\n\t\tfollowing are All books in the system :";
	for (int i = 0; i < allBooks.size(); i++){
		allBooks[i].bookInfo();
		cout << endl;
	}
}

void mainMenu() {
	int choice;
	cout << "\n\n\t\tLibrary Management system\n\n";
	cout << "\t\tPress enter to continue: ";
	_getch();
menu:
	system("cls");
	cout << "\t\tPlease enter the following choice";
	cout << "\n\t\t1) Enter user info ";
	cout << "\n\t\t2) Display the users ";
	cout << "\n\t\t3) Enter the books ";
	cout << "\n\t\t4) Display the books ";
	cout << "\n\t\t5) Exit";
	cout << "\n\n\t\t Your choice: ";
	cin >> choice;
	if (choice == 1) {
		system("cls");
		userInput();
		cout << "\n\n\t\tPress enter to go to menu:";
		_getch();
		goto menu;
	}
	else if (choice == 2) {
		system("cls");
		displayAllUsers();
		cout << "\n\n\t\tPress enter to go to menu:";
		_getch();
		goto menu;
	}
	else if (choice == 3) {
		system("cls");
		booksInput();
		cout << "\n\n\t\tPress enter to go to menu:";
		_getch();
		goto menu;
	}
	else if (choice == 4) {
		system("cls");
		displayAllbooks();
		cout << "\n\n\t\tPress enter to go to menu:";
		_getch();
		goto menu;
	}
	else if (choice == 5) {
		exit(0);
	}
	else {
		cout << "Wrong input press enter to continue";
		_getch();
		goto menu;
	}
}

int main() {
	mainMenu();
	return 0;
}