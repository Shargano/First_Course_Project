#include "Database.h"
int n = 10;
Film *film = new Film[n];
void CreateBase() {
	char symbol = '1';
	ifstream fileForTitle("Title.txt", ios::in | ios::binary);
	for (int i = 0; i < 10; i++)
		fileForTitle.getline(film[i].title, 20, symbol);
	fileForTitle.close();
	ifstream fileForCountry("Country.txt", ios::in | ios::binary);
	for (int i = 0; i < 10; i++)
		fileForCountry.getline(film[i].country, 20, symbol);
	fileForCountry.close();
	ifstream fileForNames("Name.txt", ios::in | ios::binary);
	for (int i = 0; i < 10; i++)
	{
		fileForNames.getline(film[i].name, 20, symbol);
		film[i].year = rand() % 50 + 1960;
		film[i].prises = rand() % 10;
	}
	fileForNames.close();
}
void ShowBase() {
	CreateBase();
	printf(" __________________________________________________________________________\n");
	printf("| № |    Фильм    |   Страна    | Год выпуска |  Режиссер  | Кол-во наград |\n");
	printf("|---|-------------|-------------|-------------|------------|---------------|\n");
	for (int i = 0; i < n; i++)
	{
		printf("|%2d | %10s  |%10s   |     %4d    | %10s |     %4d      |\n", i + 1,film[i].title, film[i].country, film[i].year, film[i].name, film[i].prises);
	}
	printf(" __________________________________________________________________________\n");
	cin.get();
}
void Database() {
	do
	{
		ViewMenu();
	} while (true);
}
void ViewMenu() {
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE), hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	DWORD result;
	COORD position;
	INPUT_RECORD keyBuff;
	DrawMenu();
	ReadConsoleInput(hStdin, &keyBuff, 1, &result);
	switch (keyBuff.Event.KeyEvent.uChar.AsciiChar)
	{
	case '1':
		system("cls");
		ShowBase();
		system("cls");
		break;
	case '2':
		system("cls");
		FindInBase();
		break;
	case '3':
		system("cls");
		NewFilm();
		break;
	case '4':
		system("cls");
		Menu();
		break;
	default: ViewMenu();
	}
}
void NewFilm() {
	int size;
	cout << "Введите кол-во добавляемых элемнтов : ";
	cin >> size;
	Film *newfilm = new Film[n + size];
	for (int i = 0; i < (n + size); i++)
	{
		if (i < n) {
			newfilm[i].title = film[i].title;
			newfilm[i].country = film[i].country;
			newfilm[i].year = film[i].year;
			newfilm[i].name = film[i].name;
			newfilm[i].prises = film[i].prises;
		}
		else
		{
			cout << "Название : ";
			cin >> newfilm[i].title;
			cout << "Страна : ";
			cin >> newfilm[i].country;
			cout << "Год выпуска : ";
			cin >> newfilm[i].year;
			cout << "Режиссер : ";
			cin >> newfilm[i].name;
			cout << "Кол-во наград : ";
			cin >> newfilm[i].prises;
		}
	}
	n = n + size;
	film = new Film[n];
	film = newfilm;
	system("cls");
}
void DrawMenu() {
	HANDLE hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;
	position.X = 46;
	position.Y = 7;
	SetConsoleCursorPosition(hstdout, position);
	cout << "1.Просмотреть справочник" << endl;
	position.X = 47;
	position.Y = 9;
	SetConsoleCursorPosition(hstdout, position);
	cout << "2.Поиск по справочнику" << endl;
	position.X = 47;
	position.Y = 11;
	SetConsoleCursorPosition(hstdout, position);
	cout << "3.Пополнить справочник" << endl;
	position.X = 54;
	position.Y = 13;
	SetConsoleCursorPosition(hstdout, position);
	cout << "4.Выход" << endl;
}
void FindInBase() {
	CreateBase();
	int num;
	bool test;
	cout << "1)По стране." << endl;
	cout << "2)По году выпуска." << endl;
	cout << "3)По имени режиссера." << endl;
	cin >> num;
	switch (num)
	{
	case 1:
		system("cls");
		findCountry();
		cin.get();
		system("cls");
		break;
	case 2:
		system("cls");
		findYear();
		cin.get();
		system("cls");
		break;
	case 3:
		system("cls");
		findBooks();
		cin.get();
		system("cls");
		break;
	default:
		break;
	}
}
void findCountry() {
	bool test = false;
	string hisCountry;
	cout << "Введите страну фильма : ";
	cin >> hisCountry;
	for (int i = 0; i < n; i++)
	{
		if (film[i].country == hisCountry) {
			test = true;
			cout << "Название фильма : " << film[i].name << endl;
			cout << "Год его выпуска : " << film[i].year << endl;
			cout << "Имя режиссера фильма : " << film[i].name << endl;
			cout << "Количество наград : " << film[i].prises << endl;
			break;
		}
	}
	if (!test) {
		cout << "По введенному запросу ничего не найдено..." << endl;
	}
	cin.get();
}
void findYear() {
	bool test = false;
	int hisYear;
	cout << "Введите год выпуска фильма : ";
	cin >> hisYear;
	for (int i = 0; i < n; i++)
	{
		if (film[i].year == hisYear) {
			test = true;
			cout << "Название фильма : " << film[i].title << endl;
			cout << "Страна фильма : " << film[i].country << endl;
			cout << "Имя режиссера фильма : " << film[i].name << endl;
			cout << "Количество наград : " << film[i].prises << endl;
			break;
		}
	}
	if (!test) {
		cout << "По введенному запросу ничего не найдено..." << endl;
	}
	cin.get();
}
void findBooks() {
	bool test = false;
	string hisName;
	cout << "Введите имя режиссера : ";
	cin >> hisName;
	for (int i = 0; i < n; i++)
	{
		if (film[i].name == hisName) {
			test = true;
			cout << "Название фильма : " << film[i].title << endl;
			cout << "Год выпуска фильма : " << film[i].year << endl;
			cout << "Страна фильма : " << film[i].country << endl;
			cout << "Количество наград : " << film[i].prises << endl;
			break;
		}
	}
	if (!test) {
		cout << "По введенному запросу ничего не найдено..." << endl;
	}
	cin.get();
}