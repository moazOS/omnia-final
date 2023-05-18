#pragma once
#include<string>
#include <fstream>
#include<iostream>
#include <vector>
#include <set>
#include<queue>
#include <map>
#include<unordered_map>
using namespace std;
class Users
{
public:
    string fullName;
    string id;
    string password;
    string password_confirm;
    string gender;
    string governorate;
    bool flag, vaccinated, fullyVaccinated, halfVaccinated;
    int age = 0;
    int num_of_dose = 0;

    //---------------------Menus-----------------------
    void mainMenu();
    void MainMenuChoices();
    void adminMenu();
    void userMenu();
    void returnBack();
    //--------------------- user ------------------------------
    void Register();
    void ID_validation(string id);
    bool ID_validation2(string id);
    void createPass();
    void displayGovernorate();
    void GovernorateChoice();
    void VaccineCheck();
    void insertUserData();
    void Login();
    void displayUserData();
    void diplayEditChoices();
    void editUserData();
    bool checknumber(string value);
    void editAgain(char);
    void deleteUserData();
    //--------------------- admin ------------------------------

    void display_perc_of_gender();
    void display_perc_of_doses();
    void display_record();
    void display_records_filterd();
    void delete_record();
    void display_ordered_by_age();
    void display_waitinglist_records();
    void ViewDeleteAll();
    //--------------------- file retated functions ------------------------------
    Users getData(string id);
    void load();
    void save();
    void deleteData();


    ~Users(void);

};
class Node
{
public:
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = NULL;
    }
};
class Queue
{
public:
    Node* front, * back;
    Queue() {
        front = back = NULL;
    }
    void enqueue(string);
    void dequeue(string);
    void display();
};