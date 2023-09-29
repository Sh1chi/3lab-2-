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
    double salary;
};

struct Car {
    string brand_model;
    string country;
    int year;
    double price;
    string condition;
    int quantity;
};

struct Dealership {
    string name;
    string address;
};

struct Customer {
    Person person;
    string phone_number;
};

struct Deal {
    int deal_number;
    string date;
    Employee seller;
    Customer buyer;
    Car car_sold;
    double transaction_amount;
    Dealership dealership; // Используем одну переменную для автосалона
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

// Функция для ввода информации о покупателе
void InputCustomerInfo(Customer& customer) {
    cout << "Введите имя покупателя: ";
    cin >> customer.person.first_name;
    cout << "Введите фамилию покупателя: ";
    cin >> customer.person.last_name;
    cout << "Введите номер телефона покупателя: ";
    cin >> customer.phone_number;
}

// Функция для ввода информации о сделке
void InputDealInfo(Employee* employees, int numEmployees, Customer* customers, int numCustomers, Car* cars, int numCars, Deal& deal, Dealership& dealership) {
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
            cout << "Неверный выбор продавца. Пожалуйста, повторите выбор." << endl;
        }
    } while (!validChoice);

    InputCustomerInfo(deal.buyer); // Вызываем функцию для ввода информации о покупателе

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
            cout << "Неверный выбор автомобиля. Пожалуйста, повторите выбор." << endl;
        }
    } while (!validChoice);

    deal.dealership = dealership; // Записываем информацию об автосалоне в сделку

    cout << "Введите сумму сделки: ";
    cin >> deal.transaction_amount;
}

// Функция для вывода информации о сделке
void PrintDealInfo(const Deal& deal) {
    cout << "Информация о сделке #" << deal.deal_number << ":" << endl;
    cout << "Дата сделки: " << deal.date << endl;
    cout << "Продавец: " << deal.seller.person.first_name << " " << deal.seller.person.last_name << endl;
    cout << "Покупатель: " << deal.buyer.person.first_name << " " << deal.buyer.person.last_name << endl;
    cout << "Номер телефона покупателя: " << deal.buyer.phone_number << endl;
    cout << "Проданный автомобиль: " << deal.car_sold.brand_model << endl;
    cout << "Сумма сделки: " << deal.transaction_amount << endl;
    cout << "Автосалон: " << deal.dealership.name << " (" << deal.dealership.address << ")" << endl;
}

int main() {
    SetConsoleEncoding();

    Employee employees[MAX_EMPLOYEES];
    Car cars[MAX_CARS];
    Customer customers[MAX_CUSTOMERS]; // Используем структуру Customer для покупателей
    int numEmployees;
    int numCars;
    int numCustomers; // Переменная для количества покупателей

    // Ввод информации об автосалоне в самом начале
    Dealership dealership;
    cout << "Введите название автосалона: ";
    cin.ignore();
    getline(cin, dealership.name);

    cout << "Введите адрес автосалона: ";
    getline(cin, dealership.address);

    cout << "Введите количество сотрудников: ";
    cin >> numEmployees;

    for (int i = 0; i < numEmployees; i++) {
        cout << "Сотрудник #" << (i + 1) << ":" << endl;
        InputEmployeeInfo(employees[i]);
    }

    cout << "Введите количество автомобилей: ";
    cin >> numCars;

    for (int i = 0; i < numCars; i++) {
        cout << "Автомобиль #" << (i + 1) << ":" << endl;
        InputCarInfo(cars[i]);
    }

    // Ввод информации о сделках и вывод информации о них
    int numDeals;
    cout << "Введите количество сделок: ";
    cin >> numDeals;
    Deal deals[MAX_DEALS];

    for (int i = 0; i < numDeals; i++) {
        cout << "Сделка #" << (i + 1) << ":" << endl;
        InputDealInfo(employees, numEmployees, customers, numCustomers, cars, numCars, deals[i], dealership);
    }

    cout << "Информация о сделках:" << endl;
    for (int i = 0; i < numDeals; i++) {
        cout << "Сделка #" << (i + 1) << ":" << endl;
        PrintDealInfo(deals[i]);
    }

    return 0;
}
