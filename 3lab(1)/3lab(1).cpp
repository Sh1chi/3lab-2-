#define _CRT_SECURE_NO_WARNINGS
#define MAX 20

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <string>

using namespace std;

#define MAX_EMPLOYEES 100
#define MAX_CUSTOMERS 100
#define MAX_CARS 100
#define MAX_DEALS 100
#define MAX_DEALERSHIPS 10

struct Person {
    string first_name; // Имя человека
    string last_name;  // Фамилия человека
};

struct Employee {
    Person person;    // Информация о сотруднике
    string position;  // Должность сотрудника
    double salary;    // Зарплата сотрудника
};

struct Customer {
    Person person;       // Информация о покупателе
    string phone_number; // Номер телефона покупателя
};

struct Car {
    string brand_model; // Марка и модель автомобиля
    string country;     // Страна производства
    int year;           // Год выпуска
    double price;       // Цена
    string condition;   // Состояние (новый/подержанный)
    int quantity;       // Количество
};

struct Deal {
    int deal_number;         // Номер сделки
    string date;             // Дата сделки
    Employee seller;         // Продавец
    Customer buyer;          // Покупатель
    Car car_sold;            // Проданный автомобиль
    double transaction_amount; // Сумма сделки
};

struct Dealership {
    string name;                           // Название автосалона
    string address;                        // Адрес автосалона
    Employee employees[MAX_EMPLOYEES];    // Массив сотрудников автосалона
    Car cars[MAX_CARS];                   // Массив автомобилей автосалона
};

// Функция для ввода информации о сотруднике
void inputEmployeeInfo(Employee& employee) {
    cout << "Введите имя сотрудника: ";
    cin.ignore();
    getline(cin, employee.person.first_name);

    cout << "Введите фамилию сотрудника: ";
    getline(cin, employee.person.last_name);

    cout << "Введите должность сотрудника: ";
    getline(cin, employee.position);

    cout << "Введите зарплату сотрудника: ";
    cin >> employee.salary;
}

// Функция для ввода информации о сделке
void inputDealInfo(Employee* employees, int numEmployees, Customer* customers, int numCustomers, Car* cars, int numCars, Deal& deal) {
    cout << "Введите номер сделки: ";
    cin >> deal.deal_number;

    cout << "Введите дату сделки: ";
    cin.ignore();
    getline(cin, deal.date);

    cout << "Выберите продавца из списка:" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << i + 1 << ". " << employees[i].person.first_name << " " << employees[i].person.last_name << endl;
    }
    int sellerIndex;
    cin >> sellerIndex;
    if (sellerIndex < 1 || sellerIndex > numEmployees) {
        cout << "Неверный выбор продавца." << endl;
        return;
    }
    deal.seller = employees[sellerIndex - 1];

    cout << "Выберите покупателя из списка:" << endl;
    for (int i = 0; i < numCustomers; i++) {
        cout << i + 1 << ". " << customers[i].person.first_name << " " << customers[i].person.last_name << endl;
    }
    int buyerIndex;
    cin >> buyerIndex;
    if (buyerIndex < 1 || buyerIndex > numCustomers) {
        cout << "Неверный выбор покупателя." << endl;
        return;
    }
    deal.buyer = customers[buyerIndex - 1];

    cout << "Выберите автомобиль из списка:" << endl;
    for (int i = 0; i < numCars; i++) {
        cout << i + 1 << ". " << cars[i].brand_model << endl;
    }
    int carIndex;
    cin >> carIndex;
    if (carIndex < 1 || carIndex > numCars) {
        cout << "Неверный выбор автомобиля." << endl;
        return;
    }
    deal.car_sold = cars[carIndex - 1];

    cout << "Введите сумму сделки: ";
    cin >> deal.transaction_amount;
}

// Функция для вывода информации о сотруднике
void printEmployeeInfo(const Employee& employee) {
    cout << "Имя сотрудника: " << employee.person.first_name << " " << employee.person.last_name << endl;
    cout << "Должность: " << employee.position << endl;
    cout << "Зарплата: " << employee.salary << endl;
}

// Функция для вывода информации о сделке
void printDealInfo(const Deal& deal) {
    cout << "Информация о сделке #" << deal.deal_number << ":" << endl;
    cout << "Дата сделки: " << deal.date << endl;
    cout << "Продавец: " << deal.seller.person.first_name << " " << deal.seller.person.last_name << endl;
    cout << "Покупатель: " << deal.buyer.person.first_name << " " << deal.buyer.person.last_name << endl;
    cout << "Проданный автомобиль:" << endl;
    cout << "Марка и модель: " << deal.car_sold.brand_model << endl;
    cout << "Цена: " << deal.car_sold.price << endl;
    cout << "Сумма сделки: " << deal.transaction_amount << endl;
}

int main() {
    // Устанавливаем кодировку для консоли
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Employee employees[MAX_EMPLOYEES];
    Customer customers[MAX_CUSTOMERS];
    Car cars[MAX_CARS];
    Deal deals[MAX_DEALS];
    Dealership dealerships[MAX_DEALERSHIPS];

    int numDealerships;
    int numDeals;

    cout << "Введите количество автосалонов: ";
    cin >> numDealerships;

    for (int d = 0; d < numDealerships; d++) {
        Dealership& dealership = dealerships[d];

        cout << "Введите название автосалона: ";
        cin.ignore();
        getline(cin, dealership.name);

        cout << "Введите адрес автосалона: ";
        getline(cin, dealership.address);

        int numEmployees;
        cout << "Введите количество сотрудников в автосалоне: ";
        cin >> numEmployees;

        for (int i = 0; i < numEmployees; i++) {
            cout << "Сотрудник #" << (i + 1) << ":" << endl;
            inputEmployeeInfo(dealership.employees[i]);
        }

        int numCars;
        cout << "Введите количество автомобилей в автосалоне: ";
        cin >> numCars;

        for (int i = 0; i < numCars; i++) {
            cout << "Автомобиль #" << (i + 1) << ":" << endl;
            Car& car = dealership.cars[i];
            cout << "Введите марку и модель автомобиля: ";
            cin.ignore();
            getline(cin, car.brand_model);

            cout << "Введите страну производства: ";
            getline(cin, car.country);

            cout << "Введите год выпуска: ";
            cin >> car.year;

            cout << "Введите цену: ";
            cin >> car.price;

            cout << "Введите состояние (новый/подержанный): ";
            cin.ignore();
            getline(cin, car.condition);

            cout << "Введите количество: ";
            cin >> car.quantity;
        }
    }

    // Введите количество сделок
    cout << "Введите количество сделок: ";
    cin >> numDeals;

    cout << "Введите информацию о сделках:" << endl;
    for (int i = 0; i < numDeals; i++) {
        cout << "Сделка #" << (i + 1) << ":" << endl;
        inputDealInfo(employees, MAX_EMPLOYEES, customers, MAX_CUSTOMERS, cars, MAX_CARS, deals[i]);
    }

    // Вывод информации
    cout << "Информация о сделках:" << endl;
    for (int i = 0; i < numDeals; i++) {
        Deal& deal = deals[i];
        printDealInfo(deal);
    }

    return 0;
}