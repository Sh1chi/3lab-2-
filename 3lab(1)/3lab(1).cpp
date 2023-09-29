#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int MAX_EMPLOYEES = 100;
const int MAX_CARS = 100;
const int MAX_DEALS = 100;
const int MAX_CUSTOMERS = 100;

struct Person {
    string first_name;
    string last_name;
};

struct Employee {
    Person person;
    string position;
    int salary;
};

struct Car {
    string brand_model;
    string country;
    int year;
    int price;
    string condition;
    int quantity;
};

struct Customer {
    Person person;
    string phone_number;
};

struct Dealership {
    string name;
    string address;
};

struct Deal {
    int deal_number;
    string date;
    Employee seller;
    Customer buyer;
    Car car_sold;
    int transaction_amount;
    Dealership dealership; // Информация об автосалоне
};

// Установка кодировки для консоли
void SetConsoleEncoding() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}

// Функция для ввода информации о сотруднике
void InputEmployeeInfo(Employee& employee) {
    cout << "Введите имя сотрудника: ";
    cin >> employee.person.first_name;

    cout << "Введите фамилию сотрудника: ";
    cin >> employee.person.last_name;

    cout << "Введите должность сотрудника: ";
    cin.ignore();
    getline(cin, employee.position);

    cout << "Введите зарплату сотрудника: ";
    cin >> employee.salary;
}

// Функция для ввода информации об автомобиле
void InputCarInfo(Car& car) {
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

// Функция для ввода информации о сделке
void InputDealInfo(Employee* employees, int numEmployees, Car* cars, int numCars, Deal& deal) {
    cout << "Введите номер сделки: ";
    cin >> deal.deal_number;

    cout << "Введите дату сделки: ";
    cin.ignore();
    getline(cin, deal.date);

    bool validChoice = false;

    do {
        cout << "Выберите продавца из списка:" << endl;
        for (int i = 0; i < numEmployees; i++) {
            cout << i + 1 << ". " << employees[i].person.first_name << " " << employees[i].person.last_name << endl;
        }
        int sellerIndex;
        cin >> sellerIndex;
        if (sellerIndex >= 1 && sellerIndex <= numEmployees) {
            deal.seller = employees[sellerIndex - 1];
            validChoice = true;
        }
        else {
            cout << "Ошибка... Неверный выбор продавца. Пожалуйста, повторите выбор." << endl;
        }
    } while (!validChoice);

    cout << "Введите имя покупателя: ";
    cin >> deal.buyer.person.first_name;
    cout << "Введите фамилию покупателя: ";
    cin >> deal.buyer.person.last_name;

    cout << "Введите номер телефона покупателя: ";
    cin >> deal.buyer.phone_number;

    validChoice = false;

    do {
        cout << "Выберите автомобиль из списка:" << endl;
        for (int i = 0; i < numCars; i++) {
            cout << i + 1 << ". " << cars[i].brand_model << endl;
        }
        int carIndex;
        cin >> carIndex;
        if (carIndex >= 1 && carIndex <= numCars) {
            deal.car_sold = cars[carIndex - 1];
            validChoice = true;
        }
        else {
            cout << "Ошибка... Неверный выбор автомобиля. Пожалуйста, повторите выбор." << endl;
        }
    } while (!validChoice);

    cout << "Введите сумму сделки: ";
    cin >> deal.transaction_amount;
}

// Функция для ввода информации об автосалоне
void InputDealershipInfo(Dealership& dealership) {
    cout << "Введите название автосалона: ";
    getline(cin, dealership.name);

    cout << "Введите адрес автосалона: ";
    getline(cin, dealership.address);
}

// Функция для вывода информации о сделке
void PrintDealInfo(const Deal& deal) {
    cout << " -- Сделка #" << deal.deal_number << ":" << endl;
    cout << "Дата сделки: " << deal.date << endl;
    cout << "Продавец: " << deal.seller.person.first_name << " " << deal.seller.person.last_name << endl;
    cout << "Покупатель: " << deal.buyer.person.first_name << " " << deal.buyer.person.last_name << endl;
    cout << "Номер телефона покупателя: " << deal.buyer.phone_number << endl;
    cout << "Проданный автомобиль: " << deal.car_sold.brand_model << endl;
    cout << "Сумма сделки: " << deal.transaction_amount << endl;
}

// Функция для вывода информации об автосалоне
void PrintDealershipInfo(const Dealership& dealership) {
    cout << "Название: " << dealership.name << endl;
    cout << "Адрес: " << dealership.address << endl;
}

// Функция для вывода информации о сотрудниках
void PrintEmployeeInfo(const Employee& employee) {
    cout << "Сотрудник: " << employee.person.first_name << " " << employee.person.last_name << endl;
    cout << "Должность: " << employee.position << endl;
    cout << "Зарплата: " << employee.salary << " руб." << endl;
}

// Функция для вывода информации об автомобилях
void PrintCarInfo(const Car& car) {
    cout << "Марка и модель: " << car.brand_model << endl;
    cout << "Страна производства: " << car.country << endl;
    cout << "Год выпуска: " << car.year << endl;
    cout << "Цена: " << car.price << " руб." << endl;
    cout << "Состояние: " << car.condition << endl;
    cout << "Количество: " << car.quantity << " шт." << endl;
}

int main() {
    SetConsoleEncoding();

    cout << "          -- Реализация АТД на языке С и С++ --" << endl;

    Dealership dealership; // Информация об автосалоне
    cout << endl;
    InputDealershipInfo(dealership); // Ввод информации об автосалоне

    Employee employees[MAX_EMPLOYEES];
    Car cars[MAX_CARS];
    int numEmployees;
    int numCars;

    cout << "Введите количество сотрудников: ";
    cin >> numEmployees;
    for (int i = 0; i < numEmployees; i++) {
        cout << endl;
        cout << "Сотрудник #" << (i + 1) << ":" << endl;
        InputEmployeeInfo(employees[i]);
    }

    cout << endl;
    cout << "Введите количество автомобилей: ";
    cin >> numCars;
    for (int i = 0; i < numCars; i++) {
        cout << endl;
        cout << "Автомобиль #" << (i + 1) << ":" << endl;
        InputCarInfo(cars[i]);
    }

    // Вывод информации об автосалоне
    cout << endl;
    cout << " -- Информация об автосалоне --" << endl;
    PrintDealershipInfo(dealership);

    // Вывод информации о сотрудниках
    cout << endl;
    cout << " -- Информация о сотрудниках --" << endl;
    for (int i = 0; i < numEmployees; i++) {
        cout << " -- Сотрудник #" << (i + 1) << ":" << endl;
        PrintEmployeeInfo(employees[i]);
    }

    // Вывод информации об автомобилях
    cout << endl;
    cout << " -- Информация об автомобилях --" << endl;
    for (int i = 0; i < numCars; i++) {
        cout << " -- Автомобиль #" << (i + 1) << ":" << endl;
        PrintCarInfo(cars[i]);
    }

    // Ввод информации о сделках и вывод информации о них
    int numDeals;
    cout << endl;
    cout << "Введите количество сделок: ";
    cin >> numDeals;
    Deal deals[MAX_DEALS];

    for (int i = 0; i < numDeals; i++) {
        cout << endl;
        cout << "Сделка #" << (i + 1) << ":" << endl;
        InputDealInfo(employees, numEmployees, cars, numCars, deals[i]);
    }

    cout << endl;
    cout << " -- Информация о сделках --" << endl;
    for (int i = 0; i < numDeals; i++) {
        PrintDealInfo(deals[i]);
    }

    return 0;
}
