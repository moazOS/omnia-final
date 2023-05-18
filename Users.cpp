#include "Users.h"
#include<iostream>
#include<string>
using namespace std;
//---------------------global variables-----------------
fstream myfile;
string Myid;
vector<Users> users_vec;
unordered_map<string, Users>users;
unordered_map<string, Users >::iterator itr;
set<string> usersID;
Queue firstDoseWaitingList;
Queue secondDoseWaitingList;
Users user;
int Doses = 0, oneDose = 0, twoDose = 0;
int cairoCount = 0, alexCount = 0, gizaCount = 0, hurghadaCount = 0, otherCount = 0;
int female = 0, male = 0;
float TOTALUSERS = 0;
char c;
//---------------------Menus-----------------------
void Users::mainMenu()
{
    load();
    int choice = 0;
    while (choice != 3) {
        MainMenuChoices();

        while (!(cin >> choice)) { //make sure user entered an int only
            cout << "\tInvalid Choice\n ";
            system("pause");
            system("cls");
            cin.clear();
            MainMenuChoices();
            cin.ignore(123, '\n');
        }
        switch (choice)
        {
        case 1:
            MainMenuChoices();
            system("cls");
            Login();
            system("cls");
            break;

        case 2:
            system("cls");
            user.Register();
            user.insertUserData();
            system("PAUSE");
            system("cls");

            break;

        case 3:

            system("CLS");
            cout << "\t\t\t\t\t===================================" << endl;
            cout << "\t\t\t\t\tThank You for using our system ! :D" << endl;
            cout << "\t\t\t\t\tHope to see you again!" << endl;
            cout << "\t\t\t\t\t===================================\n\n";
            exit(3);
            break;

        default:

            cout << "\tInvalid Choice" << endl;
            returnBack();
            mainMenu();

            break;

        }
    }
}
void Users::MainMenuChoices() {

    cout << "               ***********************************************           " << endl;
    cout << "                    WELCOME TO OUR VACCINE TRACKING SYSTEM                    " << endl;
    cout << "               ***********************************************           " << endl;
    cout << endl;
    cout << endl;
    cout << "\t1. Log in" << endl;
    cout << "\t2. Register as a new user" << endl;
    cout << "\t3. Exit Program" << endl;
    cout << "\tPlease enter number of your choice: ";

}
void Users::returnBack() {

    system("pause");
    system("cls");

}
void Users::userMenu() {


    int userchoice;
    cout << "\t-------- USER MENU ---------\n";
    cout << "\t~choose one of the following choices~\n";
    cout << "\t1->Display Record.\n";
    cout << "\t2->Edit/Update Record.\n";
    cout << "\t3->Delete Record.\n";
    cout << "\t4->Log Out.\n";
    cout << "\tEnter your choice:";
    cin >> userchoice;

    switch (userchoice) {
    case 1:
        system("CLS");
        displayUserData();

        break;
    case 2:
        system("CLS");
        editUserData();

        break;
    case 3:
        system("CLS");
        deleteUserData();

        break;
    case 4:
        system("cls");
        save();
        mainMenu();
        break;
    default:
        cout << "\tInvalid choice!\n";
        returnBack();
        userMenu();
        break;
    }
}
//----------------------  user -----------------------------
void Users::Login() {

a:
    cout << "\tenter your id: ";
    cin >> user.id;


b:
    cout << "\tenter your password:";
    cin >> user.password_confirm;

    itr = users.find(user.id);
    if (user.id == "admin") {

        cout << "\n\n\n\t\t\t\t\ Checking admin..... \n\t\t\t\t\t";

        if (user.password_confirm == "admin") {
            cout << "\n\n\tyou are logged in successfully as an admin press enter to continue..\n\n";
            system("PAUSE");
            system("cls");
            adminMenu();
        }
        else {

            cout << "\n\n\tinvalid password!\n\n";
            int passchoice;
        jj:
            cout << "\tDo You want to ->\n";
            cout << "\t1->try again?\n";
            cout << "\t2->go back to the sign up page?\n";
            cout << "\tenter your choice:";
            cin >> passchoice;
            switch (passchoice) {
            case 1:
                system("cls");
                goto b;
                break;
            case 2:
                system("cls");
                mainMenu();
                break;
            default:
                cout << "\tinvalid Choice.";
                goto jj;
                break;
            }
            system("PAUSE");
            system("cls");
            goto b;
        }

    }
    else if (itr == users.end()) {
        cout << "\n\n\n\t\t\t\t\tCHECKING USER..\n\t\t\t\t\t";
        cout << "\n\tInvalid ID...\n";
        cout << "\tMake Sure You Sign Up First!\n\n";
        system("PAUSE");
        system("cls");
        mainMenu();
        goto a;
    }

    else {
        cout << "\n\n\n\t\t\t\t\tCHECKING USER....\n\t\t\t\t\t";

        if (user.password_confirm == itr->second.password_confirm) {
            cout << endl;
            cout << "\n\n\tYou are logged in successfully as a user press enter to continue..\n\n";
            system("PAUSE");
            system("cls");
            userMenu();

        }
        else {

            cout << "\n\n\tinvalid password!\n\n";
            int passchoice;
        j:
            cout << "\tDo You want to ->\n";
            cout << "\t1->try again?\n";
            cout << "\t2->go back to the sign up page?\n";
            cout << "\tenter your choice:";
            cin >> passchoice;
            switch (passchoice) {
            case 1:
                system("cls");
                goto b;
                break;
            case 2:
                system("cls");
                mainMenu();
                break;
            default:
                cout << "\tinvalid Choice.";
                goto j;
                break;
            }
            system("PAUSE");
            system("cls");
            goto b;
        }

        cout << endl;
        cout << "\n\n\tYou are logged in successfully\n\n";
        system("PAUSE");
        system("cls");
        userMenu();

        cout << endl;





    }
}
void Users::Register()
{

    cout << "-------------------------Fill in the following data to register with us------------------" << endl;
    cout << endl;

    cout << "\t \t Enter your full name: ";
    cin >> fullName;
    //check if entered name contains letters only or not
    for (int i = 0; i < fullName.length(); i++) {
        c = fullName.at(i);
        if (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || c == ' '))
        {
            cout << "\t \t Invalid, name must contain letters or spaces only!!" << endl;
            cin >> fullName;
            break;
        }
    }

    cout << endl;

    cout << "\t \t Enter your id and make sure it is 13 digits:";
    cin >> id;
    if (id.size() < 13) {
        cout << "\t \t Invalid ID , re-enter your ID: ";
        cin >> id;
    }
    ID_validation(id);

    createPass();

    cout << endl;


    cout << "\t \t Please enter your age: ";
    while (!(cin >> age)) {
        cout << "\tInvalid Age\n ";
        cin.clear();
        cin.ignore(123, '\n');
        cout << "\tplease enter a correct age: ";

    }

    cout << endl;

    cout << "\t \t Please choose gender female or  male: ";
    cin >> gender;
    while (gender != "female" && gender != "Female" && gender != "male" && gender != "Male") {
        cout << "\tInvalid value, please re-enter it correctly: ";
        cin >> gender;

    }

    cout << endl;

    GovernorateChoice();
    cout << endl;

    myfile.open("alldata.txt", ios::app);

    myfile << id << endl;
    myfile.close();
    string fn = id + ".txt";

    myfile.open(fn, ios::app);
    myfile << fullName << endl;
    myfile << id << endl;
    myfile << password_confirm << endl;
    myfile << age << endl;
    myfile << gender << endl;
    myfile << governorate << endl;

    VaccineCheck();

    myfile << num_of_dose << endl;
    myfile.close();

    cout << "Your record is saved............." << endl;


}
void Queue::enqueue(string id) {
    Node* temp = new Node(id);

    if (back == NULL) { //empty
        front = back = temp;
        return;
    }
    back->next = temp;
    back = temp;
}
void Queue::dequeue(string id)
{
    // If queue is empty, return NULL.
    if (front == NULL)
        return;

    // Store previous front and
    // move front one node ahead
    Node* temp = front;
    front = front->next;

    // If front becomes NULL, then
    // change rear also as NULL
    if (front == NULL)
        back = NULL;

    delete (temp);
}

void Queue::display()
{


}
void Users::VaccineCheck() {
    char ans;
S:
    cout << "\t \t Did you take the Vaccine before ?: \n \t \t enter y for yes and n for no : ";
    while (!(cin >> ans)) {
        cout << "\t \t Invalid Input try again:";
        cin.clear();
        cin.ignore(123, '\n');
        goto S;
        break;

    }

    switch (ans)
    {
    case 'y':
    case'Y':
    {
    label:

        cout << "\t \t Did you take 1 or 2 doses ? : ";
        while (!(cin >> num_of_dose)) {
            cout << "\t \tInvalid Input, try again: ";
            cin.clear();
            cin.ignore(123, '\n');
        }

        switch (num_of_dose) {
        case 1:
        {
            cout << "\t \t You will be added on 2nd dose waiting list" << endl;
            secondDoseWaitingList.enqueue(id);
            break;
        }
        case 2:
        {
            fullyVaccinated = true;
            break;
        }
        default:
        {
            cout << "\tInvalid choice" << endl;
            goto label;
            break;
        }
        }

        break;
    }
    case 'n':
    case'N':
    {
        vaccinated = false;
        num_of_dose = 0; //in file
        cout << "\t \tYou will be registered into our waiting list" << endl;
        firstDoseWaitingList.enqueue(id);
        break;
    }
    default:
        cout << "\t \tInvalid input, try again:" << endl;
        VaccineCheck();
        break;

    }

}

void Users::createPass()
{
    bool msg = true;
    password = "";
    password_confirm = "";
    cout << endl;
    cout << "\t \t Create a new password : ";
    cin >> password;

    cout << "\t \t Confirm your password : ";
    cin >> password_confirm;

    if (msg) {

        if (password == password_confirm) {
            cout << "\n \t \t Password created successfully !!!!!!" << endl;

        }
        else {
            cout << "\n\t \t Passwords don't match , please try again:" << endl;
            createPass();
        }
    }
}
void Users::displayGovernorate() {
    cout << "\t \t Please enter number of governorate you are from : " << endl;
    cout << "\t \t1 )  Cairo " << endl;
    cout << "\t \t2 ) Alexandria " << endl;
    cout << "\t \t3 ) Giza " << endl;
    cout << "\t \t4 ) Hurghada " << endl;
    cout << "\t \t5 ) Other " << endl;
    cout << "\t \t Governorate number is : ";

}
void Users::GovernorateChoice() {
    int choice;
    displayGovernorate();
    while (!(cin >> choice)) {
        cout << "\t \t Invalid governorate " << endl;
        cin.clear();
        cin.ignore(123, '\n');
        displayGovernorate();

    }


    switch (choice) {
    case 1:
        governorate = "Cairo";
        break;
    case 2:
        governorate = "Alexandria";
        break;
    case 3:
        governorate = "Giza";
        break;
    case 4:
        governorate = "Hurghada";
        break;
    case 5:
        governorate = "other";
        break;
    default:
    {
        cout << "\t \tInvalid value entered.\n\t \tPlease make sure to enter a value from the  options below." << endl;
        GovernorateChoice();

    }
    }
}
void Users::displayUserData() {
    cout << "\t-----------------Recorded Data-----------------\n\n";
    cout << "\Fullname:" << "  " << itr->second.fullName << endl;
    cout << "\tNational ID:" << "  " << itr->first << endl;
    cout << "\tPassword:" << "  " << itr->second.password << endl;
    cout << "\tAge:" << "  " << itr->second.age << endl;
    cout << "\tGender:" << "  " << itr->second.gender << endl;
    cout << "\tGovernorate:" << "  " << itr->second.governorate << endl;
    cout << "\tDoses taken:" << "  " << itr->second.num_of_dose << endl;
    returnBack();
    userMenu();
}
void Users::diplayEditChoices() {
    cout << "\t\t\t\t\t----------Pick Your Choice!----------\n\n\n";
    cout << "\t1->Full Name.\n";
    cout << "\t2->Password.\n";
    cout << "\t3->Age.\n";
    cout << "\t4->Gender.\n";
    cout << "\t5->Governorate.\n";
    cout << "\t6->Doses taken.\n";
    cout << "\tenter your choice:";
}
bool Users::checknumber(string value) {
    for (int i = 0; i < value.length(); i++)
        if (isdigit(value[i]) == false) {
            return false;
        }
    return true;
}
void Users::editUserData() {

    char answer;
    int editoption;
    string option;
    string optionNum;
    string optionChar;

    diplayEditChoices();
    cin >> editoption;



    switch (editoption)
    {
    case 1:
    {

        cout << "\Full Name:";
        cin >> option;
        if (checknumber(option) == false) {
            itr->second.fullName = option;
            cout << "\tdo you want to edit anything else?";
            cin >> answer;
            editAgain(answer);
        }
        else {
            cout << "\tInvalid Input!\n";
            cout << "\tdo you want to edit anything else?";
            cin >> answer;
            editAgain(answer);
        }
        break;
    }
    



    case 2:
    {
        cout << "\tpassword:";
        cin >> option;
        itr->second.password = option;
        cout << "\tdo you want to edit anything else?";
        cin >> answer;
        editAgain(answer);

        break;
    }

    case 3:
    {
        cout << "\tcurrent age:" << itr->second.age << endl;
        cout << "\tAge:";
        cin >> optionNum;
        editoption = stoi(optionNum);
        if (editoption < itr->second.age) {
            cout << "\tInvalid Age. Please enter a correct one" << endl;
            cout << "\tdo you want to edit anything else?";
            cin >> answer;
            editAgain(answer);

        }
        else {
            if (checknumber(optionNum) == false) {
                cout << "\tInvalid Input!\n";
                cout << "\tdo you want to edit anything else?";
                cin >> answer;
                editAgain(answer);
            }
            else {

                itr->second.age = editoption;
                cout << "\tdo you want to edit anything else?";
                cin >> answer;
                editAgain(answer);
            }
        }
        break;
    }

    case 4:
    {
        cout << "\tGender F/M:";
        cin >> optionChar;
        if (checknumber(optionChar) == false) {
            itr->second.gender = optionChar[0];
            cout << "\tdo you want to edit anything else?";
            cin >> answer;
            editAgain(answer);
        }
        else {
            cout << "\tInvalid Input!\n";
            cout << "\tdo you want to edit anything else?";
            cin >> answer;
            editAgain(answer);

        }


        break;
    }

    case 5:
    {
        cout << "\t-------Governorates-------" << endl;
        cout << "\t1) Cairo " << endl;
        cout << "\t2) Alexandria " << endl;
        cout << "\t3) Giza " << endl;
        cout << "\t4) Hurghada " << endl;
        cout << "\t6) Other " << endl;
        cout << "\tgovernorate:";
        cin >> optionNum;
        if (checknumber(optionNum) == true) {
            editoption = stoi(optionNum);

            switch (editoption) {
            case 1:
                cairoCount++;
                itr->second.governorate = "Cairo";
                break;
            case 2:
                itr->second.governorate = "Alexandria";
                alexCount++;
                break;
            case 3:
                itr->second.governorate = "Giza";
                gizaCount++;
                break;
            case 4:
                itr->second.governorate = "Hurghada";
                hurghadaCount++;
                break;

            case 5:
                itr->second.governorate = "other";
                otherCount++;
                break;
            default:
            {
                cout << "\tInvalid value entered.\n\tPlease make sure to enter a value from the  options below." << endl;
                GovernorateChoice();
                break;
            }

            cout << "\tdo you want to edit anything else?";
            cin >> answer;
            editAgain(answer);
            }
        }
        else {
            cout << "\tInvalid Input!\n";
            cout << "\tdo you want to edit anything else?";
            cin >> answer;
            editAgain(answer);
        }


        break;
    }

    case 6:
    {
        cout << "\tDoses taken(1 Or 2):";
        cin >> optionNum;
        if (checknumber(optionNum) == true) {
            editoption = stoi(optionNum);
            if ((editoption == 1) || (editoption == 2)) {
                itr->second.num_of_dose = editoption;
                if (editoption == 1) {
                    firstDoseWaitingList.dequeue(user.id);
                    secondDoseWaitingList.enqueue(user.id);
                    cout << "\n\tyou have been added to the second dose waiting list\n";
                }
                else if (editoption == 2) {
                    secondDoseWaitingList.dequeue(user.id);

                    cout << "\n\tyou have been fully vaccinated!\n ";
                }
                cout << "\tdo you want to edit anything else?";
                cin >> answer;
                editAgain(answer);
            }
            else {
                cout << "\tInvalid Input!\n";
                cout << "\tdo you want to edit anything else?";
                cin >> answer;
                editAgain(answer);
            }

        }
        break;
    }

    default: {
        system("cls");
        cout << "\tinvalid choice\n";
        returnBack();
        userMenu();
        break;
    }
    }
    returnBack();
    userMenu();
    system("cls");
    if (itr->second.gender == "female" || itr->second.gender == "Female") {
        female--;
    }
    if (itr->second.gender == "male" || itr->second.gender == "Male") {
        male--;
    }
    if (itr->second.num_of_dose == 0) {
        Doses--;
    }
    if (itr->second.num_of_dose == 1) {
        oneDose--;
    }
    if (itr->second.num_of_dose == 2) {
        twoDose--;
    }
    if (itr->second.governorate == "Cairo") {
        cairoCount--;
    }
    if (itr->second.governorate == "Alexandria") {
        alexCount--;
    }
    if (itr->second.governorate == "Giza") {
        gizaCount--;
    }

    if (itr->second.governorate == "Hurghada") {
        hurghadaCount--;
    }
    if (itr->second.governorate == "other") {
        otherCount--;
    }


}
void Users::editAgain(char ans) {

    if (ans == 'y' || ans == 'Y') {
        system("cls");
        editUserData();
    }
    else if (ans == 'n' || ans == 'N') {
        system("cls");
        userMenu();
    }
    else {
        cout << "\tinvalid choice\n";
        returnBack();
        userMenu();
    }

}
void Users::deleteUserData() {

    string verify;

VV:
    cout << "\tenter your ID for verfication:";
    cin >> verify;
    itr = users.find(user.id);
    if (verify != itr->second.id) {
        cout << "\tWrong ID\n";
        goto VV;
    }

    else if (verify == itr->second.id) {

        if (itr->second.gender == "female" || itr->second.gender == "Female") {
            female--;
        }
        if (itr->second.gender == "male" || itr->second.gender == "Male") {
            male--;
        }
        if (itr->second.num_of_dose == 0) {
            Doses--;
        }
        if (itr->second.num_of_dose == 1) {
            oneDose--;
        }
        if (itr->second.num_of_dose == 2) {
            twoDose--;
        }
        if (itr->second.governorate == "Cairo") {
            cairoCount--;
        }
        if (itr->second.governorate == "Alexandria") {
            alexCount--;
        }
        if (itr->second.governorate == "Giza") {
            gizaCount--;
        }

        if (itr->second.governorate == "Hurghada") {
            hurghadaCount--;
        }
        if (itr->second.governorate == "other") {
            otherCount--;
        }

    }
    char* fullName;
    string filename = itr->first + ".txt";
    fullName = &filename[0];
    remove(fullName);
    users.erase(user.id);
    cout << "\tDeleted Successfully!\n";
    save();
    returnBack();
    mainMenu();

}
void Users::insertUserData() {

    users[user.id] = user;

}
void Users::ID_validation(string user_id)
{

    char choice;
    for (itr = users.begin(); itr != users.end(); itr++) {
        if (user_id == itr->first) {
            cout << "\t \t ID already Registered!" << endl;
        q:
            cout << "\t \t Do you want to log in ? (y/n) ";
            cin >> choice;
            switch (choice) {
            case 'y':
                system("cls");
                Login();
                break;
            case'n':
                system("cls");
                mainMenu();
                break;
            default:
                cout << "\t \t Invalid choice , try again.";
                goto q;
                break;
            }

            cout << " \t \t Enter your id and make sure it is 13 digits:";
            cin >> id;
            while (id.size() != 13) {
                cout << "\t \t Invalid ID , re-enter your ID: ";
                cin >> id;
            }
            break;


        }


    }
}

//----------------------  admin -----------------------------
void Users::adminMenu()
{
    bool done = true;
    do
    {
        int c;
        cout << "               ***********************************************           " << endl;
        cout << "                            WELCOME TO Admin page                        " << endl;
        cout << "               ***********************************************           " << endl;
        cout << "1 -> Display/Delete all records" << endl;
        cout << "2 -> Display a record" << endl;
        cout << "3 -> Delete a record" << endl;
        cout << "4 -> Display records filtered by doses" << endl;
        cout << "5  -> Display records ordered by age" << endl;
        cout << "6 -> Display peopele that need to be vaccinated from the waiting list" << endl;
        cout << "7 -> Display percentage of gender" << endl;
        cout << "8-> Display percentage of records filtered by doses" << endl;
        cout << "9 -> Exit" << endl;
        cout << "Choose a number : ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            ViewDeleteAll();
            break;
        }


        case 2:
        {
            display_record();
            break;
        }
        case 3: {
            delete_record();
            break;
        }
        case 4:
        {
            display_records_filterd();
            break;
        }

        case 5:
        {
            display_ordered_by_age();
            break;
        }
        case 6:
        {
            display_waitinglist_records();
            break;
        }
        case 7:
        {
            display_perc_of_gender();
            break;
        }
        case 8:
        {
            display_perc_of_doses();
            break;
        }

        default:
            done = false;
            break;
        }
    } while (done);
    system("cls");
    mainMenu();
}
void Users::display_perc_of_gender()
{
    if (users.size() == 0) {
        cout << "\t\t\t\t\tno users to display their statistics.....\n";

    }
    else {

        float statfemale = (female / (float)users.size()) * 100;
        cout << "\tPercentage of Females registered in the system: " << statfemale << "%" << endl;

        float statmale = (male / (float)users.size()) * 100;
        cout << " \tPercentage of Males registered in the system: " << statmale << "%" << endl;
    }
    returnBack();
    adminMenu();
}
void Users::display_record()
{
    cout << "\tPlease enter the National ID of the User whose data you would like displayed:";
    cin >> user.id;
    system("cls");

    itr = users.find(user.id);

    if (itr == users.end()) {
        cout << "\tno record!\n";
        returnBack();
        adminMenu();

    }
    else {

        cout << "\t-----------------Recorded Data-----------------\n\n";
        cout << "\tFull name:" << "  " << itr->second.fullName << endl;
        cout << "\tNational ID:" << "  " << itr->first << endl;
        cout << "\tPassword:" << "  " << itr->second.password << endl;
        cout << "\tAge:" << "  " << itr->second.age << endl;
        cout << "\tGender:" << "  " << itr->second.gender << endl;
        cout << "\tgovernorate:" << "  " << itr->second.governorate << endl;
        cout << "\tDoses taken:" << "  " << itr->second.num_of_dose << endl;
        returnBack();
        adminMenu();
    }



}
void Users::display_perc_of_doses()
{
    if (users.size() == 0)
    {
        cout << "\t\t\t\t\tno users to display their statistics.....\n";

    }
    else {


        float statdoseone = (oneDose / (float)users.size()) * 100;
        cout << "\tPercentage of people registered in the system that has received the first dose: " << statdoseone << "%" << endl;


        float statdosetwo = (twoDose / (float)users.size()) * 100;
        cout << "\tPercentage of people registered in the system that has received both doses: " << statdosetwo << "%" << endl;


    }
    returnBack();
    adminMenu();
}
void Users::delete_record()
{
    cout << "\tPlease enter the National ID of the User whose data you would like deleted:";
    cin >> user.id;
    string verify;

mm:
    cout << "\tenter your ID for verfication:";
    cin >> verify;
    itr = users.find(user.id);
    if (verify != itr->second.id) {
        cout << "\tWrong ID\n";
        goto mm;
    }


    else if (verify == itr->second.id) {

        if (itr->second.gender == "female" || itr->second.gender == "Female") {
            female--;
        }
        if (itr->second.gender == "male" || itr->second.gender == "Male") {
            male--;
        }
        if (itr->second.num_of_dose == 0) {
            Doses--;
        }
        if (itr->second.num_of_dose == 1) {
            oneDose--;
        }
        if (itr->second.num_of_dose == 2) {
            twoDose--;
        }
        if (itr->second.governorate == "Cairo") {
            cairoCount--;
        }
        if (itr->second.governorate == "Alexandria") {
            alexCount--;
        }
        if (itr->second.governorate == "Giza") {
            gizaCount--;
        }

        if (itr->second.governorate == "Hurghada") {
            hurghadaCount--;
        }
        if (itr->second.governorate == "other") {
            otherCount--;
        }


    }
    char* fullName;
    string filename = itr->first + ".txt";
    fullName = &filename[0];
    remove(fullName);
    users.erase(user.id);
    cout << "\tDeleted Successfully!\n";
    save();
    returnBack();
    adminMenu();

}
void Users::ViewDeleteAll() {
    int adchoice;


    cout << "\t--- Choose one of the following choices. ---\n";
    cout << "\t1-> Display All Records\n";
    cout << "\t2-> Delete All Records\n";
    cout << "\t3->Go back?\n";
    cout << "\tEnter your choice:";

    cin >> adchoice;
    switch (adchoice) {
    case 1:
        system("CLS");

        for (itr = users.begin(); itr != users.end(); ++itr) {
            cout << "\t-----------------Recorded Data-----------------\n\n";
            cout << "\Full name:" << "  " << itr->second.fullName << endl;
            cout << "\tNational ID:" << "  " << itr->first << endl;
            cout << "\tPassword:" << "  " << itr->second.password << endl;
            cout << "\tAge:" << "  " << itr->second.age << endl;
            cout << "\tGender:" << "  " << itr->second.gender << endl;
            cout << "\tgovernorate:" << "  " << itr->second.governorate << endl;
            cout << "\tDoses taken:" << "  " << itr->second.num_of_dose << endl;
        }
        returnBack();
        adminMenu();

        break;

    case 2:
        system("CLS");
        if (users.empty()) {
            cout << "\tNo records found!\n";
        }
        else {
            deleteData();
            users.clear();
            cout << "\tAll Records Deleted Successfully!\n";
        }
        returnBack();
        adminMenu();


        break;
    case 3:
        system("CLS");
        returnBack();
        adminMenu();
        break;
    default:
        system("CLS");
        cout << "\tinvalid choice\n";
        returnBack();
        adminMenu();

    }
}
void Users::display_records_filterd() {
    if (users.size() == 0)
    {
        cout << "\tno record available\n";
        returnBack();
        adminMenu();

    }
    else {

        if (user.num_of_dose == 0) {
            cout << "\tno record!\n";
            returnBack();
            adminMenu();

        }
        else {

            cout << "\t-----------------Recorded Data Filtered by only doses-----------------\n\n";
            cout << "\fullName:" << "  " << user.fullName << endl;
            cout << "\tDoses taken:" << "  " << user.num_of_dose << endl;
            returnBack();
            adminMenu();
        }
    }
}
void Users::display_ordered_by_age() {
    if (users.size() == 0) {
        cout << "\tno record!\n";
        returnBack();
        adminMenu();

    }
    else if (user.num_of_dose == 0 && user.vaccinated == false) {
        cout << "\tno record is still vaccinated\n";
        returnBack();
        adminMenu();

    }
    else {
        if (user.num_of_dose == 1) {
            for (itr = users.begin(); itr != users.end(); ++itr) {
                cout << "\t-----------------Vaccinated users ordered by The age-----------------\n\n";
                cout << "\fullName:" << "  " << itr->second.fullName << endl;
                cout << "\tNational ID:" << "  " << itr->first << endl;
                cout << "\tPassword:" << "  " << itr->second.password << endl;
                cout << "\tAge:" << "  " << itr->second.age << endl;
                cout << "\tGender:" << "  " << itr->second.gender << endl;
                cout << "\tgovernorate:" << "  " << itr->second.governorate << endl;
                cout << "\tDoses taken:" << "  " << itr->second.num_of_dose << endl;
            }
        }
        if (user.num_of_dose == 2) {
            for (itr = users.begin(); itr != users.end(); ++itr) {
                cout << "\fullName:" << "  " << itr->second.fullName << endl;
                cout << "\tNational ID:" << "  " << itr->first << endl;
                cout << "\tPassword:" << "  " << itr->second.password << endl;
                cout << "\tAge:" << "  " << itr->second.age << endl;
                cout << "\tGender:" << "  " << itr->second.gender << endl;
                cout << "\tgovernorate:" << "  " << itr->second.governorate << endl;
                cout << "\tDoses taken:" << "  " << itr->second.num_of_dose << endl;

            }
        }

        returnBack();
        adminMenu();
    }
}
void Users::display_waitinglist_records() {
    if (users.size() == 0) {
        cout << "\tno waiting list!\n";
        returnBack();
        adminMenu();

    }
    else {
        firstDoseWaitingList.display();
        secondDoseWaitingList.display();

    }
   
    returnBack();
    adminMenu();

}


//----------------------  files -----------------------------
Users Users::getData(string file) {

    Users u;

    myfile.open(file, ios::in);
    myfile >> fullName;
    u.fullName = fullName;
    myfile >> id;
    u.id = id;
    myfile >> password_confirm;
    u.password_confirm = password_confirm;
    myfile >> age;
    u.age = age;
    myfile >> gender;
    u.gender = gender;
    myfile >> governorate;
    u.governorate = governorate;
    myfile >> num_of_dose;
    u.num_of_dose = num_of_dose;
    myfile.close();
    return u;
}
void Users::load() {
    string line;
    string filename;
    vector<string> v;
    myfile.open("alldata.txt", ios::in);
    for (string line; getline(myfile, line);) {
        v.push_back(line);
    }
    myfile.close();
    for (int i = 0; i < v.size(); i++)
    {
        filename = v[i] + ".txt";
        Users u = getData(filename);
        users[u.id] = u;
    }
    for (itr = users.begin(); itr != users.end(); ++itr) {
        if (itr->second.num_of_dose == 1) {
            oneDose++;
        }
        if (itr->second.num_of_dose == 2) {
            twoDose++;
        }
        if (itr->second.num_of_dose == 0) {
            Doses++;
        }
        if (itr->second.gender == "female" || itr->second.gender == "Female") {
            female++;
        }
        if (itr->second.gender == "male" || itr->second.gender == "Male") {
            male++;
        }
        if (itr->second.governorate == "Cairo") {
            cairoCount++;
        }
        if (itr->second.governorate == "Giza") {
            gizaCount++;
        }
        if (itr->second.governorate == "Alexandria") {
            alexCount++;
        }
        if (itr->second.governorate == "Hurghada") {
            hurghadaCount++;
        }

        if (itr->second.governorate == "Others") {
            otherCount++;
        }
    }
}
void Users::save() {
    vector<string> v;
    for (itr = users.begin(); itr != users.end(); itr++) {
        string filename = itr->first + ".txt";
        myfile.open(filename);
        if (myfile.is_open()) {
            myfile.close();
            char* fullName;
            fullName = &filename[0];
            remove(fullName);
            myfile.open(filename, ios::app);
            myfile << itr->second.fullName << endl;
            myfile << itr->second.id << endl;
            myfile << itr->second.password_confirm << endl;
            myfile << itr->second.age << endl;
            myfile << itr->second.gender << endl;
            myfile << itr->second.governorate << endl;
            myfile << itr->second.num_of_dose << endl;
            myfile.close();
            v.push_back(itr->first);
        }
        else {
            cout << "failed to open file\n";
        }
        

    }
    string all = "alldata.txt";
    char* alldata;
    alldata = &all[0];
    remove(alldata);
    myfile.open("alldata.txt", ios::app);
    for (int i = 0; i < v.size(); i++) {
        myfile << v[i] << endl;
    }
    myfile.close();
}
void Users::deleteData() {
    for (itr = users.begin(); itr != users.end(); itr++) {
        string filename = itr->first + ".txt";
        char* fullName;
        fullName = &filename[0];
        remove(fullName);
    }
    string all = "alldata.txt";
    char* alldata;
    alldata = &all[0];
    remove(alldata);
}

Users::~Users(void) {

}

