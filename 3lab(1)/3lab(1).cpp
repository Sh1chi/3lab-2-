#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#define MAX_CUSTOMERS 100
#define MAX_DEALS 100
using namespace std;

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>
#include <string>



const int MAX_EMPLOYEES = 100; // Максимальное количество сотрудников
const int MAX_CARS = 100;     // Максимальное количество автомобилей

struct Car {
    string brand_model; // Марка и модель автомобиля
    string country;     // Страна производства
    int year;           // Год выпуска
    double price;       // Цена
    string condition;   // Состояние (новый/подержанный)
    int quantity;       // Количество
};

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

struct Dealership {
    string name;                           // Название автосалона
    string address;                        // Адрес автосалона
    Employee employees[MAX_EMPLOYEES];    // Массив сотрудников автосалона
    Car cars[MAX_CARS];                   // Массив автомобилей автосалона
};

struct Deal {
    int deal_number;         // Номер сделки
    string date;             // Дата сделки
    Employee seller;         // Продавец
    Customer buyer;          // Покупатель
    Car car_sold;            // Проданный автомобиль
    double transaction_amount; // Сумма сделки
};

// Функция для ввода информации об автомобиле
void inputCarInfo(Car& car) {
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

// Функция для ввода информации о покупателе
void inputCustomerInfo(Customer& customer) {
    cout << "Введите имя покупателя: ";
    cin.ignore();
    getline(cin, customer.person.first_name);

    cout << "Введите фамилию покупателя: ";
    getline(cin, customer.person.last_name);

    cout << "Введите номер телефона покупателя: ";
    getline(cin, customer.phone_number);
}

// Функция для ввода информации о сделке
void inputDealInfo(Deal& deal) {
    cout << "Введите номер сделки: ";
    cin >> deal.deal_number;

    cout << "Введите дату сделки: ";
    cin.ignore();
    getline(cin, deal.date);

    cout << "Введите информацию о продавце:" << endl;
    inputEmployeeInfo(deal.seller);

    cout << "Введите информацию о покупателе:" << endl;
    inputCustomerInfo(deal.buyer);

    cout << "Введите информацию о купленном автомобиле:" << endl;
    inputCarInfo(deal.car_sold);

    cout << "Введите сумму сделки: ";
    cin >> deal.transaction_amount;
}

int main() {
    // Создание структур и ввод информации
    Car car1;
    cout << "Введите информацию об автомобиле:" << endl;
    inputCarInfo(car1);

    Employee employee1;
    cout << "Введите информацию о сотруднике:" << endl;
    inputEmployeeInfo(employee1);

    // Дополнительные операции с данными

    return 0;
}

