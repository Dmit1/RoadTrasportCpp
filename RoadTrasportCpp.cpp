#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <windows.h>

using namespace std;

struct COSTOMERS {           // Cтруктура заказчика 
public:
	int  id_Costomers;       // id клиента
	char Full_name[30];      // ФИО заказчика 
	char gender;             // пол      
	int  Age;                // возраст
	int  mobile;             // номер телефона
	char e_mail[30];             // Адресс электронной почты
};
struct CARGO {               // Массив структуры информации грузоперевозок
public:
	int id_Order;            // id заказа груза
	int id_Costomers;        // id клиента 
	int id_Cars;             // id авто
	char name_City[30];	     // Населенный пункт
	int  Distance;           // Расстояние до населенного пункта
	double height;           // Высота груза
	double width;            // Ширина груза
	double length;           // Длинна груза
	double weight;           // Вес груза
	double V;                // Объем авто
};
struct PASSENGER {           // Массив структуры информации пассажироперевозок
public:
	int  id_Order;           // id_пасажироперевозки
	int id_Costomers;        // id-клиента 
	int  id_Cars;            // id авто
	char name_City[30];      // Населенный пункт
	int  Distance;           // Расстояние до населенного пункта
};
struct CARS {
	int id_Cars;
	char mod_Cars[30];
	double cost_Cars;
	double cost_TO;
	double fuel_Pasxod;
};
void read_row(char* name, int* row);
void read_arrays1(char* name, COSTOMERS* costomers, int* p_row);     // Загрузка данных массива структур COSTOMERS
void read_arrays2(char* name, CARGO* cargo, int* p_row);             // ...  
void read_arrays3(char* name, PASSENGER* passenger, int* p_row);     // ...
void read_arrays4(char* name, CARS* cars, int* p_row);               // ...
void print_arrays1(COSTOMERS* costomers, int row);       // Вывод данных массива структур COSTOMERS
void print_arrays2(CARGO* cargo, int row);               // ...
void print_arrays3(PASSENGER* passenger, int row);       // ...
void print_arrays4(CARS* cars, int row);                 // ...
int menu_info(int);                                      // Меню выбора информации
int menu_load(int);                                      // Меню выбора загрузки и вывода информации
void count_poezdok(COSTOMERS* costomers, PASSENGER* passenger, int* row_costomers, int* row_passenger);  // Подсчет поездок
void count_reisov(COSTOMERS* costomers, CARGO* cargo, int* row_costomers, int* row_cargo);  // Подсчет рейсов
void info_joint(COSTOMERS* costomers, PASSENGER* passenger, CARGO* cargo, CARS* cars,       // Общая информация включает
	int* row_costomers, int* row_cargo, int* row_passenger, int* row_cars);     // данные трех структур
void contact_pass(COSTOMERS* costomers, PASSENGER* passenger, int* row_costomers, int* row_passenger); // контакты пасс  
void contact_cargo(COSTOMERS* costomers, CARGO* cargo, int* row_costomers, int* row_cargo);            // контакты груз
void cost_prime(CARS* cars, int* row_cars, double* prime_cost);                                 //стоимость за 1 км
void cost_renta(CARS* cars, int* row_cars, double* cost_r, double* procent_rent, double* cost_rent);// стоимость аренды в суткам

int main() {
	setlocale(LC_ALL, "Russian_Russia.1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, ".1251");
	setlocale(LC_ALL, "Russian");
	char name_file[4][50]{ {"COSTOMERS.txt"},{"CARGO.txt"},    // Массив с адрессами файлов тхт
						   {"PASSENGER.txt"},{"CARS.txt"} };
	int* row_costomers = new int{};               // Количество заказов в массиве структур заказчика
	int* row_cargo = new int{};                   // Количество заказов в массиве структур грузы
	int* row_passenger = new int{};               // Количество заказов в массиве структур пассажиры
	int* row_cars = new int{};                    // Количество используемых авто массиве авто
	read_row(name_file[0], row_costomers);
	read_row(name_file[1], row_cargo);
	read_row(name_file[2], row_passenger);
	read_row(name_file[3], row_cars);
	// Вывод информации о количестве данных 
	cout << "Количество клиентов:" << *row_costomers << endl; // Выводим количество заказчиков
	cout << "Количество заказов на перевозку грузов: " << *row_cargo << endl;      // Выводим количество заказов
	cout << "Количество пассажироперевозок: " << *row_passenger << endl;      //Выводим количество пассажироперевозок
	cout << "Количество автомобилей : " << *row_cars << endl;
	system("pause");
	COSTOMERS* costomers = new COSTOMERS[*row_costomers]; // Массив структур - информация о Заказчиках
	CARGO* cargo = new CARGO[*row_cargo];                 // Массив структур - информация о грузоперевозках
	PASSENGER* passenger = new PASSENGER[*row_passenger]; // Массив структур - информация о пассажироперевозках
	CARS* cars = new CARS[*row_cars];
	double* prime_cost = new double[*row_cars];   // Себестоимость 1 км авто
	double* cost_r = new double[*row_cars];       // Себестоимость аренды в день
	double* cost_rent = new double[*row_cars];    // Стоимость аренды в день
	double* procent_rent = new double[*row_cars]; // Процент прибыли
	int item{}, item1{};
	char otvet;
	//Меню(Исходные данные)
	do {
		system("cls");
		do {
			item = menu_info(item);                             // возврат item из функции menu_info
			if (item >= 13 || item <= 0) {
				system("cls");
			}
		} while (item > 12 || item <= 0);
		if (item > 0 && item < 6) {
			do {
				item1 = menu_load(item1);                           // возврат item из функции menu_load
				if (item1 >= 3 || item1 <= 0) {
					system("cls");
				}
			} while (item1 > 3 || item1 <= 0);
		}
		switch (item) {
		case 1:
			if (item1 == 1) {
				read_arrays1(name_file[0], costomers, row_costomers);                // Загрузка данных массива структур COSTOMERS                          
				cout << endl;
			}
			if (item1 == 2) {
				read_arrays1(name_file[0], costomers, row_costomers);                // Загрузка и вывод данных массива структур COSTOMERS                          
				cout << endl;
				print_arrays1(costomers, *row_costomers);
			}
			break;
		case 2:
			if (item1 == 1) {
				read_arrays2(name_file[1], cargo, row_cargo);                  // Загрузка данных массива структур CARGO   
				cout << endl;
			}
			if (item1 == 2) {
				read_arrays2(name_file[1], cargo, row_cargo);                  // Загрузка и вывод данных массива структур CARGO   
				cout << endl;
				print_arrays2(cargo, *row_cargo);
				cout << endl;
			}
			break;
		case 3:
			if (item1 == 1) {
				read_arrays3(name_file[2], passenger, row_passenger);             // Загрузка данных массива структур PASSENGER   
				cout << endl;
			}
			if (item1 == 2) {
				read_arrays3(name_file[2], passenger, row_passenger);             // Загрузка и вывод данных массива структур PASSENGER   
				cout << endl;
				print_arrays3(passenger, *row_passenger);
				cout << endl;
			}
			break;
		case 4:
			if (item1 == 1) {
				read_arrays4(name_file[3], cars, row_cars);             // Загрузка данных массива структур PASSENGER   
				cout << endl;
			}
			if (item1 == 2) {
				read_arrays4(name_file[3], cars, row_cars);             // Загрузка и вывод данных массива структур PASSENGER   
				cout << endl;
				print_arrays4(cars, *row_cars);
				cout << endl;
			}
			break;
		case 5:
			if (item1 == 1) {
				read_arrays1(name_file[0], costomers, row_costomers);             // Загрузка данных массива структур PASSENGER   
				read_arrays2(name_file[1], cargo, row_cargo);
				read_arrays3(name_file[2], passenger, row_passenger);
				read_arrays4(name_file[3], cars, row_cars);
				cout << endl;
			}
			if (item1 == 2) {
				read_arrays1(name_file[0], costomers, row_costomers);             // Загрузка данных массива структур PASSENGER   
				read_arrays2(name_file[1], cargo, row_cargo);
				read_arrays3(name_file[2], passenger, row_passenger);
				read_arrays4(name_file[3], cars, row_cars);
				cout << endl;
				print_arrays1(costomers, *row_costomers);
				print_arrays2(cargo, *row_cargo);
				print_arrays3(passenger, *row_passenger);
				print_arrays4(cars, *row_cars);
				cout << endl;
			}
			break;
		case 6: cout << "id_клиента,ФИО,поездки(пасс)" << endl;
			cout << endl;
			count_poezdok(costomers, passenger, row_costomers, row_passenger);
			break;
		case 7: cout << "id_клиента,ФИО,рейсов(груз)" << endl;
			cout << endl;
			count_reisov(costomers, cargo, row_costomers, row_cargo);
			break;
		case 8: cout << "id_клиента,ФИО,Город,id_авто,авто(общ.)" << endl;
			cout << endl;
			info_joint(costomers, passenger, cargo, cars, row_costomers, row_cargo, row_passenger, row_cars);
			break;
		case 9:cout << "id_заказа,ФИО,tel.,e_mail Пасс" << endl;
			cout << endl;
			contact_pass(costomers, passenger, row_costomers, row_passenger);
			break;
		case 10:cout << "id_заказа/ФИО/tel./e_mail(груз)" << endl;
			cout << endl;
			contact_cargo(costomers, cargo, row_costomers, row_cargo);
			break;
		case 11:
			cout << "Авто, Себестоимость километра" << endl;
			cout << endl;
			cost_prime(cars, row_cars, prime_cost);
			break;
		case 12:
			cout << "Авто, Себестоимость аренды, Стоимоимость аренды, Прибыль" << endl;
			cout << endl;
			cost_renta(cars, row_cars, cost_r, procent_rent, cost_rent);
			break;
		}
		cout << "Вернутся в главное меню? (Y/N)";
		cin >> otvet;
		cout << endl;
	} while (otvet == 'Y' || otvet == 'y');                       // Выход из меню

	delete row_costomers;                                         // Очистка динамической памяти
	row_costomers = nullptr;
	delete row_cargo;
	row_cargo = nullptr;
	delete row_passenger;
	row_passenger = nullptr;
	delete row_cars;
	row_cars = nullptr;
	delete[] costomers;
	costomers = nullptr;
	delete[] cargo;
	cargo = nullptr;
	delete[] passenger;
	passenger = nullptr;
	delete[] cars;
	cars = nullptr;
	delete[] prime_cost;
	prime_cost = nullptr;
	delete[] cost_rent;
	cost_rent = nullptr;
	delete[] cost_r;
	cost_r = nullptr;
	delete[] procent_rent;
	procent_rent = nullptr;

	system("pause");
	return 0;
}
void read_row(char* name, int* row) {
	ifstream flow;                                       // Поток ввода
	flow.open(name);                 // Открытие файла и связывание его с потоком flow_costomers.
	if (!flow.is_open())                                 // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;         // Если файл не может быть прочитан
	}
	else {
		char buffer[100];                                          // буфер для чтения одной строки файла
		while (flow.eof() == false)                      // цикл работает пока не конец файла и считаем количество строк в файле
		{
			flow.getline(buffer, 100, '\n');             // прочитать текущую строку из файла в буфер
			(*row)++;                                    //  увеличиваем счетчик количества строк
		}
		flow.close();                                    // закрытие текстового файла
	}
}
void read_arrays1(char* name, COSTOMERS* costomers, int* p_row) {

	ifstream flow;                                       // Поток ввода
	flow.open(name);                 // Открытие файла и связывание его с потоком flow_costomers.
	if (!flow.is_open())                                 // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;         // Если файл не может быть прочитан
	}
	else {
		flow.seekg(0, ios::beg);                         // Устанавливаем указатель на начало файла
		int i = 0;                                                 // Начальное значение индекса элементов массива costomers
		while (flow.eof() == false) {                    // Читаем данные пока не конец файла
			flow >> costomers[i].id_Costomers;
			flow >> costomers[i].Full_name;
			flow >> costomers[i].gender;
			flow >> costomers[i].Age;
			flow >> costomers[i].mobile;
			flow >> costomers[i].e_mail;
			i++;
		}
		*p_row = i;                                      // количество заказов
		flow.close();                                    // закрытие текстового файла
	}
}
void read_arrays2(char* name, CARGO* cargo, int* p_row) {
	ifstream flow;                                        // Cоздаем поток
	flow.open(name);                      // Открытие файла
	if (!flow.is_open())                                  // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;      // Если файл не может быть прочитан
	}
	else {
		flow.seekg(0, ios::beg);                           // Устанавливаем указатель на начало файла
		int i = 0;                                               // Начальное значение индекса элементов массива cargo
		while (flow.eof() == false) {                      // Читаем данные пока не конец файла
			flow >> cargo[i].id_Order;
			flow >> cargo[i].id_Costomers;
			flow >> cargo[i].id_Cars;
			flow >> cargo[i].name_City;
			flow >> cargo[i].Distance;
			flow >> cargo[i].height;
			flow >> cargo[i].width;
			flow >> cargo[i].length;
			flow >> cargo[i].weight;
			flow >> cargo[i].V;
			i++;                                         // Увеличиваем индекс массива cargo
		}
		*p_row = i;                                      // количество заказов
		flow.close();                                    // закрытие текстового файла
	}
}
void read_arrays3(char* name, PASSENGER* passenger, int* p_row) {
	ifstream flow;                                    // Поток ввода
	flow.open(name);              // Открытие файла и связывание его с потоком flow_passenger.
	if (!flow.is_open())                              // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;
	}
	else {
		flow.seekg(0, ios::beg);                      // Устанавливаем указатель на начало файла
		int i = 0;                                    //Начальное значение индекса элементов массива passenger
		while (flow.eof() == false) {                 //Читаем данные пока не конец файла									          
			flow >> passenger[i].id_Order;
			flow >> passenger[i].id_Costomers;
			flow >> passenger[i].id_Cars;
			flow >> passenger[i].name_City;
			flow >> passenger[i].Distance;
			i++;                                      // Увеличиваем индекс массива passanger
		}
		*p_row = i;                                   //Выводим количество заказов
		flow.close();                                 // закрытие текстового файла
	}
}
void read_arrays4(char* name, CARS* cars, int* p_row) {
	ifstream flow;                              // Поток ввода
	flow.open(name);              // Открытие файла и связывание его с потоком flow_passenger.
	if (!flow.is_open())                        // Проверка открытия файла
	{
		cout << "The data file cannot be opened!" << endl;
	}
	else {
		flow.seekg(0, ios::beg);                // Устанавливаем указатель на начало файла
		int i = 0;                              //Начальное значение индекса элементов массива passenger
		while (flow.eof() == false) {           //Читаем данные пока не конец файла									          
			flow >> cars[i].id_Cars;
			flow >> cars[i].mod_Cars;
			flow >> cars[i].cost_Cars;
			flow >> cars[i].cost_TO;
			flow >> cars[i].fuel_Pasxod;
			i++;                                // Увеличиваем индекс массива passanger
		}
		*p_row = i;                            // количество заказов
		flow.close();                           // закрытие текстового файла
	}
}
void print_arrays1(COSTOMERS* costomers, int row) {
	char zagolovki[6][30] = { "ID_клиента","Full_name","gender", "Age","mobile","e_mail" };  //массив заголовки
	for (int i = 0; i < 6; i++)                                                                        // вывод заголовки
		cout << left << setw(20) << zagolovki[i];
	cout << endl << endl;
	for (int i = 0; i < row; i++) {                                                                   // Вывод массива costomers
		cout << setw(20) << costomers[i].id_Costomers << setw(20) << costomers[i].Full_name <<
			setw(20) << costomers[i].gender << setw(20) << costomers[i].Age << setw(20) <<
			costomers[i].mobile << setw(20) << costomers[i].e_mail << endl;
	}
	cout << endl;
}
void print_arrays2(CARGO* cargo, int row) {
	char zagolovki[10][25] = { "ID-заказа","ID-клиента","ID-Авто","Город","Расстояние","Высота", "Ширина","Длинна","Масса","Объем" };      // массив заголовки
	for (int i = 0; i < 10; i++) cout << left << setw(12) << zagolovki[i];                                    //вывод заголовки
	cout << endl << endl;
	for (int i = 0; i < row; i++) {                                                                       // Вывод массива cargo
		cout << setw(12) << cargo[i].id_Order << setw(12) << cargo[i].id_Costomers <<
			setw(12) << cargo[i].id_Cars << setw(12) << cargo[i].name_City << setw(12) <<
			cargo[i].Distance << setw(12) << cargo[i].height << setw(12) << cargo[i].width
			<< setw(12) << cargo[i].length << setw(12) << cargo[i].weight
			<< setw(12) << cargo[i].V << endl;
	}
	cout << endl;
}
void print_arrays3(PASSENGER* passenger, int row) {
	char zagolovki[5][30] = { "ID_заказа", "ID-клиента", "ID-АВТО", "Город","Расстояние" };         //массив заголовки
	for (int i = 0; i < 5; i++) cout << left << setw(13) << zagolovki[i];                                     //вывод заголовки
	cout << endl << endl;
	for (int i = 0; i < row; i++) {                                                                          // Вывод массива passanger
		cout << setw(13) << passenger[i].id_Order << setw(13) << passenger[i].id_Costomers << setw(13) <<
			passenger[i].id_Cars << setw(13) << passenger[i].name_City << setw(13) << passenger[i].Distance << endl;
	}
	cout << endl;
}
void print_arrays4(CARS* cars, int row) {
	char zagolovki[5][30] = { "ID_Авто", "Модель", "Стоимость", "Стоим.ТО","Расход" };         //массив заголовки
	for (int i = 0; i < 5; i++) cout << left << setw(12) << zagolovki[i];                                     //вывод заголовки
	cout << endl << endl;
	for (int i = 0; i < row; i++) {                                                                          // Вывод массива passanger
		cout << setw(12) << cars[i].id_Cars << setw(12) << cars[i].mod_Cars << setw(12) <<
			cars[i].cost_Cars << setw(12) << cars[i].cost_TO << setw(12) << cars[i].fuel_Pasxod << endl;
	}
	cout << endl;
}
int menu_info(int item) {
	cout << " Меню " << endl;
	cout << "1-Информация о заказчиках" << endl;
	cout << "2-Информация о грузоперевозках" << endl;
	cout << "3-Информация о пассажироперевозках" << endl;
	cout << "4-Информация о автомобилях" << endl;
	cout << "5-Информация о данных" << endl;
	cout << "6-id_клиента,ФИО,поездок(пасс)" << endl;
	cout << "7-id_клиента,ФИО,рейсов(груз)" << endl;
	cout << "8-id_клиента,ФИО,Город,id_авто,авто,рейсов(общ.)" << endl;
	cout << "9-id_заказа,ФИО,Tel.,e_mail(пасс)" << endl;
	cout << "10-id_заказа,ФИО,Tel.,e_mail(груз)" << endl;
	cout << "11-Авто, Себестоимость километра" << endl;
	cout << "12-Авто, Себестоимость аренды, Стоимоимость аренды, Прибыль" << endl;
	cout << "Ваш выбор: ";
	cin >> item;
	return item;
}
int menu_load(int item) {
	cout << " Меню-1 " << endl;
	cout << "1-Загрузить" << endl;
	cout << "2-Загрузить и вывести на экран" << endl;
	cout << "Ваш выбор: ";
	cin >> item;
	return item;
}
void count_poezdok(COSTOMERS* costomers, PASSENGER* passenger, int* row_costomers, int* row_passenger) {
	cout << setw(15) << "id_клиента" << setw(15) << "ФИО" << setw(15) << "Поездки" << endl;
	for (int k = 0; k < *row_costomers; k++) {
		int count = 0;
		cout << setw(15) << costomers[k].id_Costomers << setw(15) << costomers[k].Full_name << setw(15);
		for (int p = 0; p < *row_passenger; p++) {
			if (costomers[k].id_Costomers == passenger[p].id_Costomers) {
				count++;
			}
		}
		cout << setw(15) << count << endl;
	}
}
void count_reisov(COSTOMERS* costomers, CARGO* cargo, int* row_costomers, int* row_cargo) {
	CARGO* pcargo = cargo;
	cout << setw(15) << "id_клиента" << setw(15) << "ФИО" << setw(15) << "Рейсов" << endl;
	for (int k = 0; k < *row_costomers; k++) {
		int count = 0;
		cout << costomers->id_Costomers << setw(15) << costomers->Full_name << setw(15);
		cargo = pcargo;
		for (int c = 0; c < *row_cargo; c++) {
			if (costomers->id_Costomers == cargo->id_Costomers) {
				count++;
			}
			cargo++;
		}
		cout << setw(15) << count << endl;
		costomers++;
	}
}
void info_joint(COSTOMERS* costomers, PASSENGER* passenger, CARGO* cargo, CARS* cars, int* row_costomers, int* row_cargo, int* row_passenger, int* row_cars) {
	cout << "id_клиента" << "\t" << "ФИО" << "\t" << "Город" << "\t" << "id_авто"
		<< "\t" << "Авто" << endl;
	for (int k = 0; k < *row_costomers; k++) {
		for (int p = 0; p < *row_passenger; p++) {
			for (int a = 0; a < *row_cars; a++) {
				if (costomers[k].id_Costomers == passenger[p].id_Costomers &&
					passenger[p].id_Cars == cars[a].id_Cars) {
					cout << costomers[k].id_Costomers << "\t\t" << costomers[k].Full_name
						<< "\t" << passenger[k].name_City << "\t" << passenger[k].id_Cars
						<< "\t" << cars[a].mod_Cars << endl;
				}
			}
		}
		for (int c = 0; c < *row_cargo; c++) {
			for (int a = 0; a < *row_cars; a++) {
				if (costomers[k].id_Costomers == cargo[c].id_Costomers &&
					cargo[c].id_Cars == cars[a].id_Cars) {
					cout << costomers[k].id_Costomers << "\t\t" << costomers[k].Full_name
						<< "\t" << cargo[k].name_City << "\t" << cargo[k].id_Cars << "\t "
						<< cars[a].mod_Cars << endl;
				}
			}
		}
	}
}
void contact_pass(COSTOMERS* costomers, PASSENGER* passenger, int* row_costomers, int* row_passenger) {
	cout << "id_заказа" << "\t" << "ФИО" << "\t" << "tel." << "\t" << "e_mail" << endl;
	for (int p = 0; p < *row_passenger; p++) {
		cout << passenger[p].id_Order << "\t";
		for (int k = 0; k < *row_costomers; k++) {
			if (passenger[p].id_Costomers == costomers[k].id_Costomers) {
				cout << costomers[k].id_Costomers << "\t" <<
					costomers[k].Full_name << "\t" << costomers[k].mobile << "\t"
					<< costomers[k].e_mail << endl;
			}
		}
	}
}
void contact_cargo(COSTOMERS* costomers, CARGO* cargo, int* row_costomers, int* row_cargo) {
	cout << "id_заказа" << "\t" << "ФИО" << "\t" << "tel." << "\t" << "e_mail" << endl;
	for (int c = 0; c < *row_cargo; c++) {
		cout << cargo[c].id_Order << "\t";
		for (int k = 0; k < *row_costomers; k++) {
			if (cargo[c].id_Costomers == costomers[k].id_Costomers) {
				cout << costomers[k].id_Costomers << "\t" <<
					costomers[k].Full_name << "\t" << costomers[k].mobile << "\t"
					<< costomers[k].e_mail << endl;
			}
		}
	}
}
void cost_prime(CARS* cars, int* row_cars, double* prime_cost) {
	double cost_fuel = 2.2;                     // средняя стоимость топлива 
	double amort = 700;                         // амортизационная стоимоть в км( примерно 7лет )
	cout << " Model cars" << "\t" << "prime_cost" << endl;
	for (int p = 0; p < *row_cars; p++) {
		prime_cost[p] = amort / cars[p].cost_Cars + cost_fuel * cars[p].fuel_Pasxod /
			static_cast <double>(100) + cars[p].cost_TO;
		cout << cars[p].mod_Cars << "\t\t" << prime_cost[p] << endl;
	}
}
void cost_renta(CARS* cars, int* row_cars, double* cost_r, double* procent_rent, double* cost_rent) {
	double с_inf = 0.1;      // Коэффициент инфляции (10%)
	double с_Am = 0.2;       // Коэфициент амортизации стоимость на дни использования
	double с_Prof = 0.6;       // Прибыль. Коэфициент рентабельности (устанавливаемая)
	double amort_d = 2492;   // дней эксплуатации
	cout << setw(10) << "Авто" << setw(20) << "Себестоим.Аренды" << setw(20) << "Стоим.Прибыль"
		<< setw(20) << "Стоим.Аренды" << endl;
	for (int a = 0; a < *row_cars; a++) {
		cost_r[a] = с_Am * с_inf * cars[a].cost_Cars / static_cast<double>(30);
		procent_rent[a] = с_Prof * cost_r[a];
		cost_rent[a] = cost_r[a] + procent_rent[a];
		cout << setw(10) << cars[a].mod_Cars << setw(20) << cost_r[a] << setw(20)
			<< procent_rent[a] << setw(20) << cost_rent[a] << endl;
	}
}
