#ifndef DATABASE_H
#define DATABASE_H
#include "Menu.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
using namespace std;
struct Film {
	char *title = new char[10];
	char *country = new char[10];
	char *name = new char[10];
	int year, prises;
};
void Database();
void DrawMenu();
void ViewMenu();
void NewFilm();
void ShowBase();
void CreateBase();
void FindInBase();
void findCountry();
void findYear();
void findBooks();
#endif // !DATABASE_H