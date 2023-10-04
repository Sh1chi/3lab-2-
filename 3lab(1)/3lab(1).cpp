#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

const int MAX_EMPLOYEES = 100;
const int MAX_CARS = 100;
const int MAX_DEALS = 100;

// Структура для хранения информации о человеке (имя и фамилия)
struct Person {
    string first_name;
    string last_name;
};

// Структура для хранения информации о сотруднике (персональные данные и должность)
struct Employee {
    Person person;
    string position;
    int salary;
};

// Структура для хранения информации об автомобиле
struct Car {
    string brand_model;
    string country;
    int year;
    int price;
    string condition;
    int quantity;
};

// Структура для хранения информации о покупателе (персональные данные и номер телефона)
struct Customer {
    Person person;
    string phone_number;
};

// Структура для хранения информации об автосалоне
struct Dealership {
    string name;
    string address;
};

// Структура для хранения информации о сделке
struct Deal {
    int deal_number;
    string date;
    Employee seller;
    Customer buyer;
    Car car_sold;
    int transaction_amount;
    Dealership dealership;
};

// Функция для установки кодировки для консоли (для поддержки кириллицы)
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
    cin.ignore();  // Игнорируем символ новой строки, оставшийся в буфере
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
void InputDealInfo(Employee* employees, int numEmployees, Car* cars, int& numCars, Deal& deal) {
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

    for (int i = 0; i < numCars; i++) {
        if (cars[i].brand_model == deal.car_sold.brand_model) {
            cars[i].quantity--;
            if (cars[i].quantity == 0) {
                for (int j = i; j < numCars - 1; j++) {
                    cars[j] = cars[j + 1];
                }
                numCars--;
            }
            break;
        }
    }
}

// Функция для ввода информации об автосалоне
void InputDealershipInfo(Dealership& dealership) {
    cout << "Введите название автосалона: ";
    cin.ignore();
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

    // Вывод заголовка программы
    cout << "          -- Реализация АТД на языке С и С++ --" << endl;

    // Ввод информации о автосалоне
    Dealership dealership;
    cout << endl;
    InputDealershipInfo(dealership);

    // Ввод информации о сотрудниках
    Employee employees[MAX_EMPLOYEES]; // Объявление массива employees
    int employeeCount;
    cout << endl;
    cout << "  -- Ввод данных о сотрудниках --" << endl;
    cout << "Введите количество сотрудников: ";
    cin >> employeeCount;
    for (int i = 0; i < employeeCount; i++) {
        cout << "Сотрудник #" << (i + 1) << ":" << endl;
        InputEmployeeInfo(employees[i]);
        cout << endl;
    }

    // Ввод информации о автомобилях
    Car cars[MAX_CARS]; // Объявление массива cars
    int carCount;

    cout << endl;
    cout << "  -- Ввод данных об автомобилях --" << endl;
    cout << "Введите количество автомобилей: ";
    cin >> carCount;
    for (int i = 0; i < carCount; i++) {
        cout << "Автомобиль #" << (i + 1) << ":" << endl;
        InputCarInfo(cars[i]);
        cout << endl;
    }

    cout << endl;
    cout << endl;
    cout << " __--Вся введенная информация--__" << endl;
    cout << endl;

    // Вывод информации о автосалоне
    cout << endl << "-- Информация об автосалоне --" << endl;
    PrintDealershipInfo(dealership);

    // Вывод информации о сотрудниках
    cout << endl << "-- Информация о сотрудниках --" << endl;
    for (int i = 0; i < employeeCount; i++) {
        cout << endl;
        cout << "Сотрудник #" << (i + 1) << ":" << endl;
        PrintEmployeeInfo(employees[i]);
    }

    // Вывод информации о автомобилях
    cout << endl << "-- Информация об автомобилях --" << endl;
    for (int i = 0; i < carCount; i++) {
        cout << endl;
        cout << "Автомобиль #" << (i + 1) << ":" << endl;
        PrintCarInfo(cars[i]);
    }

    // Ввод информации о сделках
    Deal deals[MAX_DEALS]; // Объявление массива deals
    int dealCount;
    cout << endl;
    cout << "Введите количество сделок: ";
    cin >> dealCount;

    cout << endl;
    cout << "  -- Ввод данных о сделках --" << endl;
    for (int i = 0; i < dealCount; i++) {
        InputDealInfo(employees, employeeCount, cars, carCount, deals[i]);
        PrintDealInfo(deals[i]);
        cout << endl;
    }

    // Вывод информации о каждой сделке
    cout << endl;
    cout << " __-- Информация о сделках --__" << endl;

    for (int i = 0; i < dealCount; ++i) {
        cout << endl;
        PrintDealInfo(deals[i]);
    }

    return 0;
}

