#define _CRT_SECURE_NO_WARNINGS
#define MAX 20
#define MAX_EMPLOYEES 100
#define MAX_CARS 100
#define MAX_CUSTOMERS 100
#define MAX_DEALS 100

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <windows.h>
#include <string.h>


// Структура "Автомобиль"
typedef struct {
    char brand_model[100];
    char country[50];
    int year;
    double price;
    char condition[20];
    int quantity;
} Car;

// Структура "Человек"
typedef struct {
    char first_name[50];
    char last_name[50];
} Person;

// Структура "Сотрудник автосалона"
typedef struct {
    Person person;
    char position[50];
    double salary;
} Employee;

// Структура "Покупатель"
typedef struct {
    Person person;
    char phone_number[20];
} Customer;

// Структура "Автосалон"
typedef struct {
    char name[100];
    char address[200];
    Employee employees[MAX_EMPLOYEES];
    Car cars[MAX_CARS];
    int num_employees;
    int num_cars;
} Dealership;

// Структура "Сделка"
typedef struct {
    int deal_number;
    char date[20];
    Employee seller;
    Customer buyer;
    Car car_sold;
    double transaction_amount;
} Deal;

int main(){
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUS");
}

