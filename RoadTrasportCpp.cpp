#include <iostream>
#include <conio.h>
#include <iomanip>
#include <cstring>
#include <fstream>
#include <stdio.h>
#include <windows.h>

using namespace std;

class CUSTOMERS {           // Cтруктура заказчика 

	int  id_Customers;       // id клиента
	char Full_name[30];      // ФИО заказчика 
	char gender;             // пол      
	int  Age;                // возраст
	int  mobile;             // номер телефона
	char e_mail[30];             // Адресс электронной почты
public:
	CUSTOMERS();
	~CUSTOMERS();
	void Set_id_Customers(int valid_Customers);
	void Set_Full_name(char valid_Full_name[30]);      // ФИО заказчика 
	void Set_gender(char valid_gender);          // пол      
	void Set_Age(int valid_Age);                 // возраст
	void Set_mobile(int valid_mobile);           // номер телефона
	void Set_e_mail(char valid_e_mail[30]);      // Адресс электронной почты
	int Get_id_Customers();
	char *Get_Full_name();      // ФИО заказчика 
	char &Get_gender();          // пол      
	int Get_Age();                 // возраст
	int Get_mobile();           // номер телефона
	char *Get_e_mail();      // Адресс электронной почты
};
CUSTOMERS::CUSTOMERS()
{
	this->id_Customers = 0;
	strcpy_s(this->Full_name, "");
	this->gender = 'n';
	this->Age = 0;
	this->mobile = 0;
	strcpy_s(this->e_mail, "");
}
CUSTOMERS::~CUSTOMERS()
{
}
void CUSTOMERS::Set_id_Customers(int valid_Customers)
{
	id_Customers = valid_Customers;
}
void CUSTOMERS::Set_Full_name(char valid_Full_name[30])
{
	strcpy_s(Full_name, valid_Full_name);
}
void CUSTOMERS::Set_gender(char valid_gender)
{
	gender = valid_gender;
}
void CUSTOMERS::Set_Age(int valid_Age)
{
	Age = valid_Age;
}
void CUSTOMERS::Set_mobile(int valid_mobile)
{
	mobile = valid_mobile;
}
void CUSTOMERS::Set_e_mail(char valid_e_mail[30])
{
	strcpy_s(e_mail, valid_e_mail);
}
int  CUSTOMERS::Get_id_Customers()
{
	return id_Customers;
}
char* CUSTOMERS::Get_Full_name()
{
	return Full_name;
}
char& CUSTOMERS::Get_gender()
{
	return gender;
}
int  CUSTOMERS::Get_Age()
{
	return Age;
}
int  CUSTOMERS::Get_mobile()
{
	return mobile;
}
char* CUSTOMERS::Get_e_mail()
{
	return e_mail;
}
class CARGO {               // Массив структуры информации грузоперевозок
	int id_Order;            // id заказа груза
	int id_Customers;        // id клиента 
	int id_Cars;             // id авто
	char name_City[30];	     // Населенный пункт
	int  Distance;           // Расстояние до населенного пункта
	double height;           // Высота груза
	double width;            // Ширина груза
	double length;           // Длинна груза
	double weight;           // Вес груза
	double V;                // Объем авто
public:
	CARGO();
	~CARGO();
	void Set_id_Order(int valid_id_Order);
	void Set_id_Customers(int valid_id_Customers);
	void Set_id_Cars(int valid_id_Cars);
	void Set_name_City(char valid_name_City[30]);
	void Set_Distance(int valid_Distance);
	void Set_height(double valid_height);
	void Set_width(double valid_width);
	void Set_length(double valid_length);
	void Set_weight(double valid_weight);
	void Set_V(double valid_V);
	int  Get_id_Order();
	int  Get_id_Customers();
	int  Get_id_Cars();
	char* Get_name_City();
	int  Get_Distance();
	double  Get_height();
	double  Get_width();
	double  Get_length();
	double  Get_weight();
	double Get_V();
};
CARGO::CARGO()
{
	this->id_Order = 0;
	this->id_Customers = 0;
	this->id_Cars = 0;
	strcpy_s(this->name_City, "");
	this->Distance = 0;
	this->height = 0;
	this->width = 0;
	this->length = 0;
	this->weight = 0;
	this->V = 0;
}
CARGO::~CARGO()
{
}
void CARGO::Set_id_Order(int valid_id_Order)
{
	id_Order = valid_id_Order;
}
void CARGO::Set_id_Customers(int valid_id_Customers)
{
	id_Customers = valid_id_Customers;
}
void CARGO::Set_id_Cars(int valid_id_Cars)
{
	id_Cars = valid_id_Cars;
}
void CARGO::Set_name_City(char valid_name_City[30])
{
	strcpy_s(this->name_City, valid_name_City);
}
void CARGO::Set_Distance(int valid_Distance)
{
	Distance = valid_Distance;
}
void CARGO::Set_height(double valid_height)
{
	height = valid_height;
}
void CARGO::Set_width(double valid_width)
{
	width = valid_width;
}
void CARGO::Set_length(double valid_length)
{
	length = valid_length;
}
void CARGO::Set_weight(double valid_weight)
{
	weight = valid_weight;
}
void CARGO::Set_V(double valid_V)
{
	V = valid_V;
}
int  CARGO::Get_id_Order()
{
	return id_Order;
}
int  CARGO::Get_id_Customers()
{
	return id_Customers;
}
int  CARGO::Get_id_Cars()
{
	return id_Cars;
}
char* CARGO::Get_name_City()
{
	return name_City;
}
int  CARGO::Get_Distance()
{
	return Distance;
}
double CARGO::Get_height()
{
	return height;
}
double CARGO::Get_width()
{
	return width;
}
double CARGO::Get_length()
{
	return length;
}
double CARGO::Get_weight()
{
	return weight;
}
double CARGO::Get_V()
{
	return V;
}
class PASSENGER {           // Массив структуры информации пассажироперевозок

	int  id_Order;           // id_пасажироперевозки
	int  id_Customers;        // id-клиента 
	int  id_Cars;            // id авто
	char name_City[30];      // Населенный пункт
	int  Distance;           // Расстояние до населенного пункта
public:
	PASSENGER();
	~PASSENGER();
	void Set_id_Order(int valid_id_Order);
	void Set_id_Customers(int valid_id_Customers);
	void Set_id_Cars(int valid_id_Cars);
	void Set_name_City(char valid_name_City[30]);
	void Set_Distance(int valid_Distance);
	int  Get_id_Order();
	int  Get_id_Customers();
	int  Get_id_Cars();
	char* Get_name_City();
	int  Get_Distance();
};
PASSENGER::PASSENGER()
{
	this->id_Order = 0;                    // id_пасажироперевозки
	this->id_Customers = 0;                // id-клиента 
	this->id_Cars = 0;                     // id авто
	strcpy_s(this->name_City, "");      // Населенный пункт
	this->Distance = 0;                    // Расстояние до населенного пункта
}
PASSENGER::~PASSENGER()
{
}
void PASSENGER::Set_id_Order(int valid_id_Order)
{
	id_Order = valid_id_Order;
}
void PASSENGER::Set_id_Customers(int valid_id_Customers)
{
	id_Customers = valid_id_Customers;
}
void PASSENGER::Set_id_Cars(int valid_id_Cars)
{
	id_Cars = valid_id_Cars;
}
void PASSENGER::Set_name_City(char valid_name_City[30])
{
	strcpy_s(this->name_City, valid_name_City);
}
void PASSENGER::Set_Distance(int valid_Distance)
{
	Distance = valid_Distance;
}
int PASSENGER::Get_id_Order()
{
	return id_Order;
}
int PASSENGER::Get_id_Customers()
{
	return id_Customers;
}
int PASSENGER::Get_id_Cars()
{
	return id_Cars;
}
char* PASSENGER::Get_name_City()
{
	return name_City;
}
int PASSENGER::Get_Distance()
{
	return Distance;
}
class CARS {
	int  id_Cars;
	char mod_Cars[30];
	double cost_Cars;
	double cost_TO;
	double fuel_Pasxod;
public:
	CARS();
	~CARS();
	void Set_id_Cars(int valid_id_Cars);
	void Set_mod_Cars(char valid_mod_Cars[30]);
	void Set_cost_Cars(double valid_cost_Cars);
	void Set_cost_TO(double valid_cost_TO);
	void Set_fuel_Pasxod(double valid_fuel_Pasxod);
	int  Get_id_Cars();
	char *Get_mod_Cars();
	double  Get_cost_Cars();
	double  Get_cost_TO();
	double  Get_fuel_Pasxod();
};
CARS::CARS() {
	id_Cars = 0;
	strcpy_s(mod_Cars, "");
	cost_Cars = 0;
	cost_TO = 0;
	fuel_Pasxod = 0;
}
CARS::~CARS() {
}
void CARS::Set_id_Cars(int valid_id_Cars)
{
	id_Cars = valid_id_Cars;
}
void CARS::Set_mod_Cars(char valid_mod_Cars[30])
{
	strcpy_s(mod_Cars, valid_mod_Cars);
}
void CARS::Set_cost_Cars(double valid_cost_Cars)
{
	cost_Cars = valid_cost_Cars;
}
void CARS::Set_cost_TO(double valid_cost_TO)
{
	cost_TO = valid_cost_TO;
}
void CARS::Set_fuel_Pasxod(double valid_fuel_Pasxod)
{
	fuel_Pasxod = valid_fuel_Pasxod;
}
int CARS::Get_id_Cars()
{
	return id_Cars;
}
char* CARS::Get_mod_Cars()
{
	return mod_Cars;
}
double CARS::Get_cost_Cars()
{
	return cost_Cars;
}
double CARS::Get_cost_TO()
{
	return cost_TO;
}
double CARS::Get_fuel_Pasxod()
{
	return fuel_Pasxod;
}
void read_row(char* name, int* row);
void read_CUSTOMERS(char* name, CUSTOMERS* costomers, int* p_row);
void read_CARGO(char* name, CARGO* cargo, int* p_row);
void read_PASSENGER(char* name, PASSENGER* passenger, int* p_row);
void read_CARS(char* name, CARS* cars, int* p_row);
void print_CUSTOMERS(CUSTOMERS* customers, int row);
void print_CARGO(CARGO* cargo, int row);
void print_CARS(CARS* cars, int row);
void print_PASSENGER(PASSENGER* passenger, int row);    
int menu_info(int);                             // Меню выбора информации
void count_poezdok(CUSTOMERS* customers, PASSENGER* passenger, int* row_customers, int* row_passenger);  // Подсчет поездок
void count_reisov(CUSTOMERS* customers, CARGO* cargo, int* row_customers, int* row_cargo);               // Подсчет рейсов
void info_joint(CUSTOMERS* customers, PASSENGER* passenger, CARGO* cargo, CARS* cars,        // Общая информация
	int* row_customers, int* row_cargo, int* row_passenger, int* row_cars);     
void contact_pass(CUSTOMERS* customers, PASSENGER* passenger, int* row_customers, int* row_passenger); // контакты пасс  
void contact_cargo(CUSTOMERS* customers, CARGO* cargo, int* row_customers, int* row_cargo);            // контакты груз
void cost_prime(CARS* cars, int* row_cars, double* prime_cost);                                     //стоимость за 1 км
void cost_renta(CARS* cars, int* row_cars, double* cost_r, double* procent_rent, double* cost_rent);// стоимость аренды в суткам
void car_driven(CARS* cars, int* row_cars, CARGO* cargo, int* row_cargo, PASSENGER* passenger, int* row_passenger,double & price_distance);
void price_customers(CARS* cars, int* row_cars, double* prime_cost, double* price_distance);
int main() {
	setlocale(LC_ALL, "Russian_Russia.1251");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	setlocale(LC_ALL, ".1251");
	setlocale(LC_ALL, "Russian");
	char name_file[4][50]{{"COSTOMERS.txt"},{"CARGO.txt"},    // Массив с адрессами файлов тхт
						  {"PASSENGER.txt"},{"CARS.txt"}};
	int* row_customers = new int{};               // Количество заказов в массиве структур заказчика
	int* row_cargo = new int{};                   // Количество заказов в массиве структур грузы
	int* row_passenger = new int{};               // Количество заказов в массиве структур пассажиры
	int* row_cars = new int{};                    // Количество используемых авто массиве авто
	read_row(name_file[0], row_customers);
	read_row(name_file[1], row_cargo);
	read_row(name_file[2], row_passenger);
	read_row(name_file[3], row_cars);
	// Вывод информации о количестве данных 
	cout << "Количество клиентов:" << *row_customers << endl; // Выводим количество заказчиков
	cout << "Количество заказов на перевозку грузов: " << *row_cargo << endl;      // Выводим количество заказов
	cout << "Количество пассажироперевозок: " << *row_passenger << endl;      //Выводим количество пассажироперевозок
	cout << "Количество автомобилей : " << *row_cars << endl;
	system("pause");
	CUSTOMERS* customers = new CUSTOMERS[*row_customers]; // Массив структур - информация о Заказчиках
	CARGO* cargo = new CARGO[*row_cargo];                 // Массив структур - информация о грузоперевозках
	PASSENGER* passenger = new PASSENGER[*row_passenger]; // Массив структур - информация о пассажироперевозках
	CARS* cars = new CARS[*row_cars];
	double* prime_cost = new double[*row_cars]{};     // Себестоимость 1 км авто
	double* cost_r = new double[*row_cars]{};         // Себестоимость аренды в день
	double* cost_rent = new double[*row_cars]{};      // Стоимость аренды в день
	double* procent_rent = new double[*row_cars]{};   // Процент прибыли
	double* price_distance = new double[*row_cars]{};   // Себестоимость заказа
	int item{};
	char otvet;
	// Чтение данных 
	read_CUSTOMERS(name_file[0], customers,row_customers);             // Загрузка данных массива структур PASSENGER   
	read_CARGO(name_file[1], cargo, row_cargo);
	read_PASSENGER(name_file[2], passenger, row_passenger);
	read_CARS(name_file[3], cars, row_cars);
	//Меню(Исходные данные)
	do {
		system("cls");
		do {
			item = menu_info(item);                             // возврат item из функции menu_info
			if (item >= 15 || item <= 0)
				system("cls");
		} while (item > 14 || item <= 0);
		switch (item) {
		case 1:
			print_CUSTOMERS(customers, *row_customers);
			break;
		case 2:
			print_CARGO(cargo, *row_cargo);
			cout << endl;
			break;
		case 3:
			print_PASSENGER(passenger, *row_passenger);
			cout << endl;
			break;
		case 4:
			print_CARS(cars, *row_cars);
			cout << endl;
			break;
		case 5:
			print_CUSTOMERS(customers, *row_customers);
			print_CARGO(cargo, *row_cargo);
			print_PASSENGER(passenger, *row_passenger);
			print_CARS(cars, *row_cars);
			cout << endl;
			break;
		case 6: cout << "id_клиента,ФИО,поездки(пасс)" << endl;
			cout << endl;
			count_poezdok(customers, passenger, row_customers, row_passenger);
			break;
		case 7: cout << "id_клиента,ФИО,рейсов(груз)" << endl;
			cout << endl;
			count_reisov(customers, cargo, row_customers, row_cargo);
			break;
		case 8: cout << "id_клиента,ФИО,Город,id_авто,авто(общ.)" << endl;
			cout << endl;
			info_joint(customers, passenger, cargo, cars, row_customers, row_cargo, row_passenger, row_cars);
			break;
		case 9:cout << "id_заказа,ФИО,tel.,e_mail Пасс" << endl;
			cout << endl;
			contact_pass(customers, passenger, row_customers, row_passenger);
			break;
		case 10:cout << "id_заказа/ФИО/tel./e_mail(груз)" << endl;
			cout << endl;
			contact_cargo(customers, cargo, row_customers, row_cargo);
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
		case 13:
			cout << "Рабочий пробег авто" << endl;
			car_driven(cars, row_cars, cargo, row_cargo, passenger,row_passenger, *price_distance);
			break;
        case 14:
			cout << "Себестоимость заказов" << endl;
			price_customers(cars, row_cars, prime_cost, price_distance);
			break;
	    }
		cout << "Вернутся в главное меню? (Y/N)";
		cin >> otvet;
		cout << endl;
	} while (otvet == 'Y' || otvet == 'y');                       // Выход из меню

	delete row_customers;                                         // Очистка динамической памяти
	row_customers = nullptr;
	delete row_cargo;
	row_cargo = nullptr;
	delete row_passenger;
	row_passenger = nullptr;
	delete row_cars;
	row_cars = nullptr;
	delete[] customers;
	customers = nullptr;
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
	delete[] price_distance;
	price_distance = nullptr;
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
void read_CUSTOMERS(char* name, CUSTOMERS* customers, int* p_row) {
	int  id_Customers{};       // id клиента
	char Full_name[30]{};      // ФИО заказчика 
	char gender{};             // пол      
	int  Age{};                // возраст
	int  mobile{};             // номер телефона
	char e_mail[30]{};             // Адресс электронной почты
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
			flow >> id_Customers;
			customers[i].Set_id_Customers(id_Customers);
			flow >> Full_name;
			customers[i].Set_Full_name(Full_name);
			flow >> gender;
			customers[i].Set_gender(gender);
			flow >> Age;
			customers[i].Set_Age(Age);
			flow >> mobile;
			customers[i].Set_mobile(mobile);
			flow >> e_mail;
			customers[i].Set_e_mail(e_mail);
			i++;
		}
		flow.close();                                    // закрытие текстового файла
	}
}
void read_CARGO(char* name, CARGO* cargo, int* p_row) {
	int id_Order;            // id заказа груза
	int id_Customers;        // id клиента 
	int id_Cars;             // id авто
	char name_City[30];	     // Населенный пункт
	int  Distance;           // Расстояние до населенного пункта
	double height;           // Высота груза
	double width;            // Ширина груза
	double length;           // Длинна груза
	double weight;           // Вес груза
	double V;                // Объем авто
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
			flow >> id_Order;
			cargo[i].Set_id_Order(id_Order);
			flow >> id_Customers;
			cargo[i].Set_id_Customers(id_Customers);
			flow >> id_Cars;
			cargo[i].Set_id_Cars(id_Cars);
			flow >> name_City;
			cargo[i].Set_name_City(name_City);
			flow >> Distance;
			cargo[i].Set_Distance(Distance);
			flow >> height;
			cargo[i].Set_height(height);
			flow >> width;
			cargo[i].Set_width(width);
			flow >> length;
			cargo[i].Set_length(length);
			flow >> weight;
			cargo[i].Set_weight(weight);
			flow >> V;
			cargo[i].Set_V(V);
			i++;                                         // Увеличиваем индекс массива cargo
		}
		*p_row = i;                                      // количество заказов
		flow.close();                                    // закрытие текстового файла
	}
}
void read_PASSENGER(char* name, PASSENGER* passenger, int* p_row) {
	int  id_Order{};           // id_пасажироперевозки
	int  id_Customers{};        // id-клиента 
	int  id_Cars{};            // id авто
	char name_City[30]{};      // Населенный пункт
	int  Distance{};           // Расстояние до населенного пункта
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
			flow >> id_Order;
			passenger[i].Set_id_Order(id_Order);
			flow >> id_Customers;
			passenger[i].Set_id_Customers(id_Customers);
			flow >> id_Cars;
			passenger[i].Set_id_Cars(id_Cars);
			flow >> name_City;
			passenger[i].Set_name_City(name_City);
			flow >> Distance;
			passenger[i].Set_Distance(Distance);
			i++;                                      // Увеличиваем индекс массива passanger
		}
		*p_row = i;                                   //Выводим количество заказов
		flow.close();                                 // закрытие текстового файла
	}
}
void read_CARS(char* name, CARS* cars, int* p_row) {
	int  id_Cars;
	char mod_Cars[30];
	double cost_Cars;
	double cost_TO;
	double fuel_Pasxod;
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
			flow >> id_Cars;
			cars[i].Set_id_Cars(id_Cars);
			flow >> mod_Cars;
			cars[i].Set_mod_Cars(mod_Cars);
			flow >> cost_Cars;
			cars[i].Set_cost_Cars(cost_Cars);
			flow >> cost_TO;
			cars[i].Set_cost_TO(cost_TO);
			flow >> fuel_Pasxod;
			cars[i].Set_fuel_Pasxod(fuel_Pasxod);
			i++;                                // Увеличиваем индекс массива passanger
		}
		*p_row = i;                            // количество заказов
		flow.close();                           // закрытие текстового файла
	}
}
void print_CUSTOMERS(CUSTOMERS* customers, int row) {
	char zagolovki[6][30] = { "ID_клиента","Full_name","gender", "Age","mobile","e_mail" };  //массив заголовки
	for (int i = 0; i < 6; i++)                                                                        // вывод заголовки
		cout << left << setw(20) << zagolovki[i];
	cout << endl << endl;
	for (int i = 0; i < row; i++) {
		cout << setw(20) << customers[i].Get_id_Customers() << setw(20) << customers[i].Get_Full_name() <<
			setw(20) << customers[i].Get_gender() << setw(20) << customers[i].Get_Age() << setw(20) <<
			customers[i].Get_mobile() << setw(20) << customers[i].Get_e_mail() << endl;
	}
	cout << endl;
}
void print_CARGO(CARGO* cargo, int row) {
	char zagolovki[10][25] = { "ID-заказа","ID-клиента","ID-Авто","Город","Расстояние","Высота", "Ширина","Длинна","Масса","Объем" };      // массив заголовки
	for (int i = 0; i < 10; i++) cout << left << setw(12) << zagolovki[i];                                    //вывод заголовки
	cout << endl << endl;
	for (int i = 0; i < row; i++) {                                                                       // Вывод массива cargo
		cout << setw(12) << cargo[i].Get_id_Order() << setw(12) << cargo[i].Get_id_Customers() <<
			setw(12) << cargo[i].Get_id_Cars() << setw(12) << cargo[i].Get_name_City() << setw(12) <<
			cargo[i].Get_Distance() << setw(12) << cargo[i].Get_height() << setw(12) << cargo[i].Get_width()
			<< setw(12) << cargo[i].Get_length() << setw(12) << cargo[i].Get_weight()
			<< setw(12) << cargo[i].Get_V() << endl;
	}
	cout << endl;
}
void print_PASSENGER(PASSENGER* passenger, int row) {
	char zagolovki[5][30] = { "ID_заказа", "ID-клиента", "ID-АВТО", "Город","Расстояние" };         //массив заголовки
	for (int i = 0; i < 5; i++) cout << left << setw(13) << zagolovki[i];                                     //вывод заголовки
	cout << endl << endl;
	for (int i = 0; i < row; i++) {                                                                          // Вывод массива passanger
		cout << setw(13) << passenger[i].Get_id_Order() << setw(13) << passenger[i].Get_id_Customers() << setw(13) <<
			passenger[i].Get_id_Cars() << setw(13) << passenger[i].Get_name_City() << setw(13) << passenger[i].Get_Distance() << endl;
	}
	cout << endl;
}
void print_CARS(CARS* cars, int row) {
	char zagolovki[5][30] = { "ID_Авто", "Модель", "Стоимость", "Стоим.ТО","Расход" };         //массив заголовки
	for (int i = 0; i < 5; i++) cout << left << setw(12) << zagolovki[i];                                     //вывод заголовки
	cout << endl << endl;
	for (int i = 0; i < row; i++) {                                                                          // Вывод массива passanger
		cout << setw(12) << cars[i].Get_id_Cars() << setw(12) << cars[i].Get_mod_Cars() << setw(12) <<
			cars[i].Get_cost_Cars() << setw(12) << cars[i].Get_cost_TO() << setw(12) << cars[i].Get_fuel_Pasxod() << endl;
	}
	cout << endl;
}
int menu_info(int item){
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
	cout << "13- Рабочий пробег авто" << endl;
	cout << "14- Себестоимость заказов" << endl;
	cout << "Ваш выбор: ";
	cin >> item;
	return item;
}
void count_poezdok(CUSTOMERS* customers, PASSENGER* passenger, int* row_customers, int* row_passenger) {
	cout << setw(15) << "id_клиента" << setw(15) << "ФИО" << setw(15) << "Поездки" << endl;
	for (int k = 0; k < *row_customers; k++) {
		int count = 0;
		cout << setw(15) << customers[k].Get_id_Customers() << setw(15) << customers[k].Get_Full_name() << setw(15);
		for (int p = 0; p < *row_passenger; p++) {
			if (customers[k].Get_id_Customers() == passenger[p].Get_id_Customers()) {
				count++;
			}
		}
		cout << setw(15) << count << endl;
	}
}
void count_reisov(CUSTOMERS* customers, CARGO* cargo, int* row_customers, int* row_cargo) {
	CARGO* pcargo = cargo;
	cout << setw(15) << "id_клиента" << setw(15) << "ФИО" << setw(15) << "Рейсов" << endl;
	for (int k = 0; k < *row_customers; k++) {
		int count = 0;
		cout << customers->Get_id_Customers() << setw(15) << customers->Get_Full_name() << setw(15);
		cargo = pcargo;
		for (int c = 0; c < *row_cargo; c++) {
			if (customers->Get_id_Customers() == cargo->Get_id_Customers()) {
				count++;
			}
			cargo++;
		}
		cout << setw(15) << count << endl;
		customers++;
	}
}
void info_joint(CUSTOMERS* customers, PASSENGER* passenger, CARGO* cargo, CARS* cars, int* row_customers, int* row_cargo, int* row_passenger, int* row_cars) {
	cout << "id_клиента" << "\t" << "ФИО" << "\t" << "Город" << "\t" << "id_авто"
		<< "\t" << "Авто" << endl;
	for (int k = 0; k < *row_customers; k++) {
		for (int p = 0; p < *row_passenger; p++) {
			for (int a = 0; a < *row_cars; a++) {
				if (customers[k].Get_id_Customers() == passenger[p].Get_id_Customers() &&
					passenger[p].Get_id_Cars() == cars[a].Get_id_Cars()) {
					cout << customers[k].Get_id_Customers() << "\t\t" << customers[k].Get_Full_name()
						<< "\t" << passenger[k].Get_name_City() << "\t" << passenger[k].Get_id_Cars()
						<< "\t" << cars[a].Get_mod_Cars() << endl;
				}
			}
		}
		for (int c = 0; c < *row_cargo; c++) {
			for (int a = 0; a < *row_cars; a++) {
				if (customers[k].Get_id_Customers() == cargo[c].Get_id_Customers() &&
					cargo[c].Get_id_Cars() == cars[a].Get_id_Cars()) {
					cout << customers[k].Get_id_Customers() << "\t\t" << customers[k].Get_Full_name()
						<< "\t" << cargo[k].Get_name_City() << "\t" << cargo[k].Get_id_Cars() << "\t "
						<< cars[a].Get_mod_Cars() << endl;
				}
			}
		}
	}
}
void contact_pass(CUSTOMERS* customers, PASSENGER* passenger, int* row_customers, int* row_passenger) {
	cout << "id_заказа" << "\t" << "ФИО" << "\t" << "tel." << "\t" << "e_mail" << endl;
	for (int p = 0; p < *row_passenger; p++) {
		cout << passenger[p].Get_id_Order() << "\t";
		for (int k = 0; k < *row_customers; k++) {
			if (passenger[p].Get_id_Customers() == customers[k].Get_id_Customers()) {
				cout << customers[k].Get_id_Customers() << "\t" <<
					customers[k].Get_Full_name() << "\t" << customers[k].Get_mobile() << "\t"
					<< customers[k].Get_e_mail() << endl;
			}
		}
	}
}
void contact_cargo(CUSTOMERS* customers, CARGO* cargo, int* row_customers, int* row_cargo) {

	cout << "id_заказа" << "\t" << "ФИО" << "\t" << "tel." << "\t" << "e_mail" << endl;
	for (int c = 0; c < *row_cargo; c++) {
		cout << cargo[c].Get_id_Order() << "\t";
		for (int k = 0; k < *row_customers; k++) {
			if (cargo[c].Get_id_Customers() == customers[k].Get_id_Customers()) {
				cout << customers[k].Get_id_Customers() << "\t" <<
					customers[k].Get_Full_name() << "\t" << customers[k].Get_mobile() << "\t"
					<< customers[k].Get_e_mail() << endl;
			}
		}
	}
}
void cost_prime(CARS* cars, int* row_cars, double* prime_cost) {
	double cost_fuel = 2.2;                     // средняя стоимость топлива 
	double amort = 700;                         // амортизационная стоимоть в км( примерно 7лет )
	cout << " Model cars" << "\t" << "prime_cost" << endl;
	for (int p = 0; p < *row_cars; p++) {
		prime_cost[p] = amort / cars[p].Get_cost_Cars() + cost_fuel * cars[p].Get_fuel_Pasxod() /
			static_cast <double>(100) + cars[p].Get_cost_TO();
		cout << cars[p].Get_mod_Cars() << "\t\t" << prime_cost[p] << endl;
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
		cost_r[a] = с_Am * с_inf * cars[a].Get_cost_Cars() / static_cast<double>(30);
		procent_rent[a] = с_Prof * cost_r[a];
		cost_rent[a] = cost_r[a] + procent_rent[a];
		cout << setw(10) << cars[a].Get_mod_Cars() << setw(20) << cost_r[a] << setw(20)
			<< procent_rent[a] << setw(20) << cost_rent[a] << endl;
	}
}
void car_driven(CARS* cars, int* row_cars, CARGO* cargo, int* row_cargo, PASSENGER* passenger, int* row_passenger, double & price_distance) {
	double total_km = 0;
	cout <<setw(5) << "id_Cars" << "\t" << " Пробег" << endl;
	for (int a = 0; a < *row_cars; a++) {
		double sum_km = 0;
		for (int p = 0; p < *row_passenger; p++) {
			if (passenger[p].Get_id_Cars() == cars[a].Get_id_Cars()) {
				sum_km += passenger[p].Get_Distance();
			}
		}
		for (int c = 0; c < *row_cargo; c++) {
			if (cargo[c].Get_id_Cars() == cars[a].Get_id_Cars()) {
				sum_km += cargo[c].Get_Distance();
			}
		}
		cout <<setw(5) << cars[a].Get_id_Cars() << "\t" << sum_km << endl;
		total_km += sum_km;
	}
	cout << "TOTAL = " << total_km << endl;
}
void price_customers(CARS* cars, int* row_cars, double *prime_cost, double *price_distance) {
	cout << setw(5) << "id_Cars"<<"\t"<<"Model"<< "\t" << " Пробег"<<"\t"<<"Price"<< endl;
	for (int a = 0; a < *row_cars; a++) {
		cout << setw(5) << cars[a].Get_id_Cars() << "\t" << cars[a].Get_mod_Cars()<<"\t" <<
			price_distance[a]<<"\t"<< static_cast<int>(price_distance[a]* prime_cost[a]) << endl;
	}
}