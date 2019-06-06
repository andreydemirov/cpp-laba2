#include "pch.h"
#include <Windows.H>
#include <iostream>
#include <conio.h>
#include <string>

using namespace std;

struct DATA // рождение 
{
	unsigned short day;
	unsigned short mounth;
	unsigned short year;
};

struct HOMEADRESS // домашний адресс и всё связаное с ним 
{
	unsigned short postcode; // почтовый индекс 
	string country; // страна
	string region; // область 
	string district; // район
	string city; // город 
	string street; // улица 
	unsigned short house; // дом 
	unsigned short apartment; // квартира

};

struct laba2 {
	string surname; // фамилия
	string name;  // имя
	string patronymic; // отчество
	string sex; // пол
	string nationality; // национальность
	unsigned short height; // рост
	unsigned short weight; // вес
	DATA date; // рождение
	string number_phone; // номер телефона
	HOMEADRESS home_adress; // дом.адресс
	string university; // ВУЗ
	unsigned short course; // курс
	unsigned short group; // группа
	unsigned short average_ball; // средний бал
	string specialty; // специальность
};


//Метод ввода с проверкой вводимого
int readInt() {
	unsigned short N;
	while (!(cin >> N) || (cin.peek() != '\n')) {
		cin.clear();
		while (cin.get() != '\n');
		cout << "" << endl;
	}
	return N;
}

// Метод ввода с проверкой, что вводимое число - позитивное
int readPositiveInt() {
	unsigned short N;
	bool check = false;
	unsigned short temp;
	while (check == false) {
		temp = readInt();
		if (temp & (1U << (sizeof(temp) * 8 - 1))) {
			cout << "Ошибка! введите положительное число - ";
		}
		else {
			N = temp;
			check = true;
		}
	}
	return N;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	// Определять количество студентов в массве
	unsigned short N;
	cout << "Введите кол-во студентов: ";
	N = readPositiveInt();
	cin.ignore();
	laba2 *arr = new laba2[N];

	for (int i = 0; i < N; i++) {
		cout << "Введите фамилию: ";
		getline(cin, arr[i].surname);
		cin.ignore();
		cout << "Введите имя: ";
		getline(cin, arr[i].name);
		cin.ignore();
		cout << "Введите отчество: ";
		getline(cin, arr[i].patronymic);
		cin.ignore();
		cout << "Введите пол: ";
		getline(cin, arr[i].sex);
		cin.ignore();
		cout << "Введите национальность: ";
		getline(cin, arr[i].nationality);
		cin.ignore();
		cout << "Введите рост: ";
		arr[i].height = readPositiveInt();
		cin.ignore();
		cout << "Введите вес: ";
		arr[i].weight = readPositiveInt();
		cin.ignore();
		cout << "Введите день рождения: ";
		arr[i].date.day = readPositiveInt();
		cin.ignore();
		cout << "Введите месяц рождения: ";
		arr[i].date.mounth = readPositiveInt();
		cin.ignore();
		cout << "Введите год рождения: ";
		arr[i].date.year = readPositiveInt();
		cin.ignore();
		cout << "Введите номер телефона: ";
		arr[i].number_phone = readPositiveInt();
		cin.ignore();
		cout << "Введите почтовый индекс: ";
		arr[i].home_adress.postcode = readPositiveInt();
		cin.ignore();
		cout << "Введите страну: ";
		getline(cin, arr[i].home_adress.country);
		cin.ignore();
		cout << "Введите область: ";
		getline(cin, arr[i].home_adress.region);
		cin.ignore();
		cout << "Введите район: ";
		getline(cin, arr[i].home_adress.district);
		cin.ignore();
		cout << "Введите город: ";
		getline(cin, arr[i].home_adress.city);
		cin.ignore();
		cout << "Введите улицу: ";
		getline(cin, arr[i].home_adress.street);
		cin.ignore();
		cout << "Введите дом: ";
		arr[i].home_adress.house = readPositiveInt();
		cin.ignore();
		cout << "Введите квартиру: ";
		arr[i].home_adress.apartment = readPositiveInt();
		cin.ignore();
	}

	//сортировка
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j].date.year > arr[j + 1].date.year) {
				laba2 tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	cout << "-----------------------" << endl;
	cout << "| Массив отсортирован |" << endl;
	cout << "-----------------------" << endl;
	cout << "Отсортированый массив: " << endl;

	for (int i = 0; i < N; i++) {
		cout << "Фамилия: " << arr[i].surname << endl;
		cout << "ИМЯ: " << arr[i].name << endl;
		cout << "ОТчество: " << arr[i].patronymic << endl;
		cout << "Стать: " << arr[i].sex << endl;
		cout << "Нац.: " << arr[i].nationality << endl;
		cout << "Рост: " << arr[i].height << endl;
		cout << "Вес: " << arr[i].weight << endl;
		cout << "День: " << arr[i].date.day << endl;
		cout << "Мес: " << arr[i].date.mounth << endl;
		cout << "Год: " << arr[i].date.year << endl;
		cout << "Тел " << arr[i].number_phone << endl;
		cout << "Индес: " << arr[i].home_adress.postcode << endl;
		cout << "Страна: " << arr[i].home_adress.country << endl;
		cout << "Область: " << arr[i].home_adress.region << endl;
		cout << "Район: " << arr[i].home_adress.district << endl;
		cout << "Одесса: " << arr[i].home_adress.city << endl;
		cout << "Улица: " << arr[i].home_adress.street << endl;
		cout << "Дом: " << arr[i].home_adress.house << endl;
		cout << "Квартира: " << arr[i].home_adress.apartment << endl;
	};
}
