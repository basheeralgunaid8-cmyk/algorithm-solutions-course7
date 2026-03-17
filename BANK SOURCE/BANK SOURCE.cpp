#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;
const string ClientsFileName = "Clients.txt";

void ShowMainMenu();
void ShowTransactionsMenu();

struct sClients
{

	string AccountNumber = "";
	string PinCode = "";
	string Name = "";
	string Phone = "";
	double AccountBalance = 0;
	bool MarkForDelete = false;
	double Balance = 0;

};

enum enMainMenuOptions
{
	enListClients = 1,
	enAddClient = 2,
	enDeleteClient = 3,
	enUpdateClient = 4,
	enFindClient = 5,
	enTransactions = 6,
	enExit = 7

};

enum enTransactionsMenuOptions
{
	enDeposit = 1,
	enWithdraw = 2,
	enTotalBalances = 3,
	enMainMenu = 4
};

short ReadMainMenuOption(int From, int To) {

	int Option = 0;
	do
	{

		cout << "Choose what do you want to do? [1 to 7]? ";
		cin >> Option;


	} while (Option < From || Option > To);

	return Option;


}

string Tabs(short TabsNumber)
{
	string tabs = "";

	for (short i = 0; i < TabsNumber; i++)
	{
		tabs += "\t";
	}

	return tabs;
}

string ReadClientAccountNumber() {

	string AccountNumber = "";
	cout << "Please Enter AccountNumber? ";
	cin >> AccountNumber;

	return AccountNumber;
}

vector<string> SpiltString(string S1, string delim) {


	vector<string> vClientData;

	short pos = 0;
	string sWord = "";

	while ((pos = S1.find(delim)) != std::string::npos)
	{
		sWord = S1.substr(0, pos);

		if (sWord != "")
		{
			vClientData.push_back(sWord);
		}

		S1.erase(0, pos + delim.length());
	}
	if (S1 != "")
	{
		vClientData.push_back(S1);
	}

	return vClientData;

}

sClients ConvertLineToRecord(string Line, string Seperator = "#//#") {

	vector<string> vClients = SpiltString(Line, Seperator);
	sClients Client;

	Client.AccountNumber = vClients[0];
	Client.PinCode = vClients[1];
	Client.Name = vClients[2];
	Client.Phone = vClients[3];
	Client.AccountBalance = stod(vClients[4]);

	return Client;

}

vector<sClients> LoadClientsFromFile(string FileName) {

	vector<sClients> vClients;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{
		string Line = "";
		sClients Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);

		}

		MyFile.close();

	}

	return vClients;

}

void PrintClientRecord(sClients Client) {

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(10) << left << Client.PinCode;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.Phone;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

void PrintAllClientsData(vector<sClients> vClientsData) {

	cout << "\n" << Tabs(5) << "Clients List (" << vClientsData.size() << ") Client(s).";
	cout << "\n_________________________________________________________________";
	cout << "_____________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Acount Number ";
	cout << "| " << left << setw(10) << "Pin Code";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Phone";
	cout << "| " << left << setw(12) << "Balance";

	cout << "\n_________________________________________________________________";
	cout << "_____________________________________________\n" << endl;


	if (vClientsData.size() == 0)
	{
		cout << "\n" << Tabs(5) << "No Clients Exists.!\n";
	}
	else
	{
		for (sClients& Client : vClientsData) {

			PrintClientRecord(Client);
			cout << endl;

		}
	}



	cout << "\n_________________________________________________________________";
	cout << "_____________________________________________\n" << endl;

}

string ConvertRecordToLine(sClients Client, string Seperator = "#//#") {

	string ClientDataLine = "";

	ClientDataLine += Client.AccountNumber + Seperator;
	ClientDataLine += Client.PinCode + Seperator;
	ClientDataLine += Client.Name + Seperator;
	ClientDataLine += Client.Phone + Seperator;
	ClientDataLine += to_string(Client.AccountBalance);


	return ClientDataLine;

}

/*
bool IsClientExitInTheFile(string AccountNumber) {

vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);

for (sClients & C : vClients) {

if (C.AccountNumber == AccountNumber)
{
return true;
}

}

return false;

}
*/

bool IsClientExistsByAccountNumber(string AccountNumber, string FileName) {

	vector<sClients> vClients;
	fstream MyFile;

	MyFile.open(FileName, ios::in);

	if (MyFile.is_open())
	{

		string Line;
		sClients Client;

		while (getline(MyFile, Line))
		{

			Client = ConvertLineToRecord(Line);
			if (Client.AccountNumber == AccountNumber)
			{
				MyFile.close();
				return true;
			}
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return false;

}

sClients ReadNewClient() {

	sClients Client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, Client.AccountNumber);

	while (IsClientExistsByAccountNumber(Client.AccountNumber, ClientsFileName))
	{
		cout << "\nClient with [" << Client.AccountNumber << "] already exists, Enter another Account Number? ";
		getline(cin, Client.AccountNumber);
	}


	cout << "Enter PinCode? ";
	getline(cin, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;


	return Client;

}

void AddClientToFile(string FileName, string Line) {

	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app);

	if (MyFile.is_open())
	{

		MyFile << Line << endl;
		MyFile.close();

	}

}

void AddNewClient() {

	sClients Client;
	Client = ReadNewClient();
	AddClientToFile(ClientsFileName, ConvertRecordToLine(Client));

}

void AddClients() {

	char AddMore = 'Y';

	do
	{
		system("cls");
		cout << "\n-------------------------------------\n";
		cout << Tabs(1) << "Add New Clients Screen";
		cout << "\n-------------------------------------\n";
		cout << "Adding New Client:\n\n";

		AddNewClient();

		cout << "\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> AddMore;


	} while (toupper(AddMore) == 'Y');


}

void ShowAddNewClientsScreen() {

	AddClients();

}

void ShowClientsScreen() {

	vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);
	PrintAllClientsData(vClients);

}

void PrintClientCardRecord(sClients Client) {

	cout << "\n-------------------------------------------";
	cout << "\nThe following is the extracted Client details: \n\n";
	cout << "| Account Number  :" << Client.AccountNumber << endl;
	cout << "| PinCode         :" << Client.PinCode << endl;
	cout << "| Name            :" << Client.Name << endl;
	cout << "| Phone           :" << Client.Phone << endl;
	cout << "| Account Balance :" << Client.AccountBalance << endl;
	cout << "-------------------------------------------\n";

}

bool FindClientByAccountNumber(vector<sClients> vClients, sClients& Client, string AccountNumber) {


	for (sClients& C : vClients) {

		if (C.AccountNumber == AccountNumber)
		{
			Client = C;
			return true;
		}

	}

	return false;

}

bool MarkClientForDeleteByAccountNumber(vector<sClients>& vClients, string AccountNumber) {

	for (sClients& C : vClients) {

		if (C.AccountNumber == AccountNumber)
		{
			C.MarkForDelete = true;
			return true;
		}

	}

	return false;

}

vector<sClients> SaveClientsDataToFile(string FileName, vector<sClients> vClients) {

	fstream MyFile;
	string DataLine = "";

	MyFile.open(FileName, ios::out);

	if (MyFile.is_open())
	{
		for (sClients& C : vClients) {

			if (C.MarkForDelete == false)
			{
				DataLine = ConvertRecordToLine(C);
				MyFile << DataLine << endl;
			}

		}
		MyFile.close();
	}

	return vClients;
}

bool DeleteClientByAccountNumber(vector<sClients>& vClients, string AccountNumber)
{

	sClients Client;
	char Answer = 'n';

	if (FindClientByAccountNumber(vClients, Client, AccountNumber))
	{

		PrintClientCardRecord(Client);

		cout << "\n\nAre you sure you want to delete this client? Y/N? ";
		cin >> Answer;
		if (Answer == 'y' || Answer == 'Y')
		{
			MarkClientForDeleteByAccountNumber(vClients, AccountNumber);
			SaveClientsDataToFile(ClientsFileName, vClients);

			vClients = LoadClientsFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}

	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Fount.!";
		return false;
	}


}

void ShowDeleteClientScreen() {

	cout << "\n-------------------------------------\n";
	cout << Tabs(1) << "Delete Client Screen";
	cout << "\n-------------------------------------\n\n";

	vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	DeleteClientByAccountNumber(vClients, AccountNumber);

}

void ShowFindClientScreen() {

	cout << "\n-------------------------------------\n";
	cout << Tabs(1) << "Find Client Screen";
	cout << "\n-------------------------------------\n\n";

	sClients Client;
	string AccountNumber = ReadClientAccountNumber();
	vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);

	if (FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		PrintClientCardRecord(Client);
	}
	else
	{
		cout << "\n\nClient with Account Number (" << AccountNumber << ") Not Found.!";
	}

}

sClients ChangeClientRecord(string AccountNumber) {

	sClients Client;
	Client.AccountNumber = AccountNumber;

	cout << "\nEnter PinCode? ";
	getline(cin >> ws, Client.PinCode);

	cout << "Enter Name? ";
	getline(cin, Client.Name);

	cout << "Enter Phone? ";
	getline(cin, Client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> Client.AccountBalance;


	return Client;

}

bool UpdateClientByAccountNumber(vector <sClients>& vClients, string AccountNumber) {

	char Answer = 'n';
	sClients Client;

	if (FindClientByAccountNumber(vClients, Client, AccountNumber))
	{

		PrintClientCardRecord(Client);

		cout << "\n\nAre you sure you want update this client? Y/N? ";
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{

			for (sClients& C : vClients) {

				if (C.AccountNumber == AccountNumber)
				{
					C = ChangeClientRecord(AccountNumber);
					break;
				}

			}

			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfullyt.";
			return true;

		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") Not Found.!";
		return false;
	}


}

void ShowUpdateClientScreen() {

	cout << "\n-------------------------------------\n";
	cout << Tabs(1) << "Update Client Info Screen";
	cout << "\n-------------------------------------\n\n";

	vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	UpdateClientByAccountNumber(vClients, AccountNumber);


}

void ShowExitScreen() {

	cout << "\n-------------------------------\n";
	cout << Tabs(1) << "Program Ends (-:";
	cout << "\n-------------------------------\n";

}

bool DepositBalanceToClientByAccountNumber(vector<sClients>& vclients, string AccountNumber, double Amount) {

	char Answer = 'n';


	cout << "\n\nAre you sure you want perform this transaction? y/n? ";
	cin >> Answer;

	if (Answer == 'Y' || Answer == 'y')
	{

		for (sClients& C : vclients) {

			if (C.AccountNumber == AccountNumber)
			{
				C.AccountBalance += Amount;
				SaveClientsDataToFile(ClientsFileName, vclients);
				cout << "\nDone Successfully, [" << C.Name << "] New Balance become : [" << C.AccountBalance << "].";
				return true;
			}

		}
	}

	return false;

}

void ShowDepositScreen() {

	cout << "\n-------------------------------------\n";
	cout << Tabs(1) << "Deposit Screen";
	cout << "\n-------------------------------------\n\n";

	sClients Client;

	vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);
	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCardRecord(Client);

	double Amount = 0;
	cout << "\nPlease enter deposit amount? ";
	cin >> Amount;

	DepositBalanceToClientByAccountNumber(vClients, AccountNumber, Amount);

}

void ShowWithdrawScreen() {

	cout << "\n-------------------------------------\n";
	cout << Tabs(1) << "Withdraw Screen";
	cout << "\n-------------------------------------\n\n";

	sClients Client;

	string AccountNumber = ReadClientAccountNumber();
	vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);

	while (!FindClientByAccountNumber(vClients, Client, AccountNumber))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCardRecord(Client);

	double Amount = 0;
	cout << "\nPlease enter withdraw amount? ";
	cin >> Amount;

	while (Amount > Client.AccountBalance)
	{
		cout << "\nAmount Exceeds the balance, you can withdraw up to : [" << Client.AccountBalance << "].\n";
		cout << "Please enter another amount? ";
		cin >> Amount;
	}

	DepositBalanceToClientByAccountNumber(vClients, AccountNumber, Amount * -1);

}

void PrintClientRecordBalanceLine(sClients Client) {

	cout << "| " << setw(15) << left << Client.AccountNumber;
	cout << "| " << setw(40) << left << Client.Name;
	cout << "| " << setw(12) << left << Client.AccountBalance;

}

void ShowTotalBalances() {


	double TotalBalances = 0;
	vector<sClients> vClients = LoadClientsFromFile(ClientsFileName);

	cout << "\n" << Tabs(5) << "Balances List (" << vClients.size() << ") Client(s).";
	cout << "\n_________________________________________________________________";
	cout << "_____________________________________________\n" << endl;

	cout << "| " << left << setw(15) << "Acount Number ";
	cout << "| " << left << setw(40) << "Client Name";
	cout << "| " << left << setw(12) << "Balance";

	cout << "\n_________________________________________________________________";
	cout << "_____________________________________________\n" << endl;


	if (vClients.size() == 0)
	{
		cout << "\n" << Tabs(5) << "No Clients Exists In The System.!\n";
	}
	else
	{

		for (sClients& Client : vClients) {

			TotalBalances += Client.AccountBalance;
			PrintClientRecordBalanceLine(Client);
			cout << endl;
		}
	}


	cout << "\n_________________________________________________________________";
	cout << "_____________________________________________\n" << endl;

	cout << Tabs(5) << "Total Balances = " << TotalBalances << endl;


}

void ShowTotalBalancesScreen() {

	ShowTotalBalances();

}

void GoBackToMainMenu() {

	cout << "\n\n\nPress any key to go back to Main Menu...";
	system("pause>0");
	ShowMainMenu();

}

void GoBackToTransactionsMenu() {

	cout << "\n\n\nPress any key to go back to Transactions Menu...";
	system("pause>0");
	ShowTransactionsMenu();

}

short ReadTransactionsMenuOption(short From, short To) {

	int Choice = 0;

	do
	{

		cout << "Choose	what do you want to do? [" << From << " to " << To << "]? ";
		cin >> Choice;

	} while (Choice < From || Choice > To);

	return Choice;

}

void PerformTransactionsMenuOption(enTransactionsMenuOptions TransactionOption) {

	switch (TransactionOption)
	{

	case enTransactionsMenuOptions::enDeposit: {

		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenu();
		break;

	}

	case enTransactionsMenuOptions::enWithdraw: {

		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenu();
		break;

	}

	case enTransactionsMenuOptions::enTotalBalances: {

		system("cls");
		ShowTotalBalancesScreen();
		GoBackToTransactionsMenu();
		break;

	}

	case enTransactionsMenuOptions::enMainMenu: {

		ShowMainMenu();

	}

	}

}

void ShowTransactionsMenu() {

	system("cls");
	cout << "=============================================\n";
	cout << Tabs(1) << "Transactions Menu Screen \n";
	cout << "=============================================\n";
	cout << Tabs(1) << "[1] Deposit.\n";
	cout << Tabs(1) << "[2] Withdraw.\n";
	cout << Tabs(1) << "[3] Total Balances.\n";
	cout << Tabs(1) << "[4] Main Menu.\n";
	cout << "=============================================\n";

	PerformTransactionsMenuOption((enTransactionsMenuOptions)ReadTransactionsMenuOption(1, 4));

}

void PerformMainMenuOption(enMainMenuOptions MainMenuOption) {

	switch (MainMenuOption)
	{
	case enMainMenuOptions::enListClients: {

		system("cls");
		ShowClientsScreen();
		GoBackToMainMenu();
		break;

	}

	case enMainMenuOptions::enAddClient: {

		system("cls");
		ShowAddNewClientsScreen();
		GoBackToMainMenu();
		break;

	}

	case enMainMenuOptions::enDeleteClient: {

		system("cls");
		ShowDeleteClientScreen();
		GoBackToMainMenu();
		break;

	}

	case enMainMenuOptions::enUpdateClient: {
		system("cls");
		ShowUpdateClientScreen();
		GoBackToMainMenu();
		break;
	}

	case enMainMenuOptions::enFindClient: {

		system("cls");
		ShowFindClientScreen();
		GoBackToMainMenu();
		break;

	}

	case enMainMenuOptions::enTransactions: {

		system("cls");
		ShowTransactionsMenu();
		break;

	}

	case enMainMenuOptions::enExit: {

		system("cls");
		ShowExitScreen();
		break;
	}
	}

}

void ShowMainMenu() {

	system("cls");
	cout << "=============================================\n";
	cout << Tabs(2) << "Main Menu Screen \n";
	cout << "=============================================\n";
	cout << Tabs(1) << "[1] Show Clients List.\n";
	cout << Tabs(1) << "[2] Add New Client.\n";
	cout << Tabs(1) << "[3] Delete Client.\n";
	cout << Tabs(1) << "[4] Update Client.\n";
	cout << Tabs(1) << "[5] Find Client.\n";
	cout << Tabs(1) << "[6] Transactions.\n";
	cout << Tabs(1) << "[7] Exit.\n";
	cout << "=============================================\n";

	PerformMainMenuOption((enMainMenuOptions)ReadMainMenuOption(1, 7));

}

int main() {

	ShowMainMenu();

	system("pause>0");
}
