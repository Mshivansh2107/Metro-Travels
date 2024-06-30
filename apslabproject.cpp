#include <iostream>
#include <cstring>
#include <fstream>
#include <windows.h>

#define infinity 999999999

using namespace std;

struct store {
    long long int cost[20];
    int array[20];
} travel[15];

struct initialdata {
    long long int cost[20];
} ini[15];

class datamodule {
public:
    string city[15];

    datamodule() : city{"Mehrouli", "Noida Electronic City", "Sector 18", "Hauz Khaz", "CP", "Okla", "shaheen Bagh", "Chirag Delhi", "INA", "Sector 52", "Indirapuram", "Botanical Garden", "Sector 59", "Sikandarpur", "Preet Vihar"} {}

    void costdeclaration() {
        int N, i, j;
        N = 15;
        long long int arr[15][15] = {
            {0, 35, 20, infinity, 10, infinity, infinity, infinity, infinity, 70, 40, 15, infinity, 65, infinity},
            {35, 0, infinity, 15, infinity, infinity, infinity, 25, infinity, infinity, infinity, infinity, infinity, infinity, 50},
            {20, infinity, 0, 15, infinity, 30, infinity, infinity, infinity, infinity, 20, 10, infinity, infinity, 15},
            {infinity, 15, 15, 0, infinity, 12, 45, infinity, 60, infinity, infinity, infinity, infinity, infinity, 10},
            {10, infinity, infinity, infinity, 0, 15, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity},
            {infinity, infinity, 30, 12, 15, 0, 19, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity},
            {infinity, infinity, infinity, 45, infinity, 19, 0, infinity, infinity, 20, infinity, infinity, infinity, infinity, infinity},
            {infinity, 25, infinity, infinity, infinity, infinity, infinity, 0, 50, infinity, infinity, infinity, infinity, infinity, infinity},
            {infinity, infinity, infinity, 60, infinity, infinity, infinity, 50, 0, 70, infinity, infinity, infinity, infinity, infinity},
            {70, infinity, infinity, infinity, infinity, infinity, 20, infinity, 70, 0, infinity, infinity, infinity, infinity, infinity},
            {40, infinity, 20, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity, infinity, infinity, infinity},
            {15, infinity, 10, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity, infinity, infinity},
            {infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity, infinity},
            {65, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0, infinity},
            {infinity, 50, 150, 10, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, infinity, 0}
        };

        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                travel[i].cost[j] = arr[i][j];
                travel[i].array[j] = j;
                ini[i].cost[j] = arr[i][j];
            }
        }
    }
};

class bellmanfordalgorithm : public datamodule {
public:
    int N, i, j, k;

    bellmanfordalgorithm() {
        N = 15;
    }

    void algorithmic_implementation() {
        for (i = 0; i < N; i++) {
            for (j = 0; j < N; j++) {
                for (k = 0; k < N; k++) {
                    if (travel[i].cost[j] > travel[i].cost[k] + travel[k].cost[j]) {
                        travel[i].cost[j] = travel[i].cost[k] + travel[k].cost[j];
                        travel[i].array[j] = k;
                    }
                }
            }
        }
    }
};

class filehandlingmodule {
public:
    string username1, password1;

    bool duplicatecheck(string username) {
        ifstream fileread("login.txt");
        while (fileread >> username1) {
            if (username1 == username) {
                fileread.close();
                return false;
            }
        }
        fileread.close();
        return true;
    }

    void forgot(string username) {
        system("cls");
        int flag1 = 0;
        string su, sp;
        ifstream searchu("login.txt");
        while (searchu >> su >> sp) {
            if (su == username) {
                flag1 = 1;
                break;
            }
        }
        searchu.close();
        if (flag1 == 1) {
            cout << "Congratulations " << su << " ! account found !" << endl;
            cout << "Your password is: " << sp;
            cin.get();
            cin.get();
        } else {
            cout << "Sorry, your account is not found." << endl;
            cin.get();
            cin.get();
        }
    }

    bool log_in(string username, string password) {
        ifstream fileread("login.txt");
        while (fileread >> username1 >> password1) {
            if ((username == username1) && (password == password1)) {
                cout << endl << " Account Login Successful..." << endl;
                fileread.close();
                return true;
            }
        }
        fileread.close();
        cout << "\n\n\t\tSorry, Login Error." << endl;
        char f1;
        cout << "\n\n\t\tRetrieve password by Username (Y/N): " << endl;
        cin >> f1;
        switch (f1) {
            case 'Y':
            case 'y':
                forgot(username);
                break;
            case 'N':
            case 'n':
                return false;
        }
        return false;
    }

    void createaccount(string username, string password) {
        ofstream filewrite("login.txt", ios::app);
        filewrite << username << " " << password << "\n";
        filewrite.close();
        cout << endl << " Account is successfully Created ..." << endl;
    }

    void ticket(string username, string firstname[], string lastname[], string sex[], int age[], int no) {
        ofstream filewrite("ticket.txt", ios::app);
        for (int i = 0; i < no; i++) {
            filewrite << username << " " << firstname[i] << " " << lastname[i] << " " << sex[i] << " " << age[i] << "\n";
        }
        filewrite.close();
    }
};

class inputmodule {
public:
    string source, destination;
    string username, password;

    void user_input(string userchoice[]) {
        system("CLS");
        cout << "\n\n *************************************************" << endl;
        cout << endl;
        cout << " *****************************************" << endl;
        cout << " Enter Your City:";
        cin >> source;
        cout << " *****************************************" << endl;
        cout << " Enter Your Destination:";
        cin >> destination;
        cout << " *****************************************" << endl;
        userchoice[0] = source;
        userchoice[1] = destination;
    }

    string login() {
        while (true) {
            cout << "\n\n ****************************WELCOME TO METRO PATH GENERATOR**************************" << endl;
            cout << "\n\n\n\n";
            cout << " ENTER " << endl;
            cout << " *****************************************" << endl;
            cout << " **** 1. To Login *****" << endl;
            cout << " *****************************************" << endl;
            cout << " **** 2. To Create New Account ****" << endl;
            cout << " *****************************************" << endl;
            cout << "\n Enter Your Choice:";
            int ch;
            bool res;
            filehandlingmodule fobj;
            cin >> ch;
            switch (ch) {
                case 1:
                    system("CLS");
                    cout << "\n\n**************************** WELCOME TO METRO PATH GENERATOR**************************" << endl;
                    cout << endl;
                    cout << "*****************************************" << endl;
                    cout << " Enter Username:";
                    cin >> username;
                    cout << "*****************************************" << endl;
                    cout << " Enter Your Password:";
                    cin >> password;
                    cout << "*****************************************" << endl;
                    res = fobj.log_in(username, password);
                    break;
                case 2: {
                    int res2 = 0;
                    system("CLS");
                    cout << "\n\n**************************** WELCOME TO METRO PATH GENERATOR**************************" << endl;
                    cout << endl;
                    cout << "*****************************************" << endl;
                    cout << " Enter Username:";
                    cin >> username;
                    cout << "*****************************************" << endl;
                    cout << " Enter Your Password:";
                    cin >> password;
                    cout << "*****************************************" << endl;
                    res2 = fobj.duplicatecheck(username);
                    if (res2 == 1)
                        fobj.createaccount(username, password);
                    else
                        cout << "Duplicate account found, Try again" << endl;
                    break;
                }
            }
            if (res == true)
                return username;
        }
    }

    int noofpassenger() {
        int no;
        cout << endl << " Enter the no of passengers:";
        cin >> no;
        return no;
    }
};

class outputmodule {
public:
    string source, destination;

    void initial() {
        system("CLS");
        cout << "\n\n ****************************WELCOME TO METRO PATH GENERATOR**************************" << endl;
        cout << "\n\n";
        cout << " ***************************" << endl;
        cout << " * Facilities Available: *" << endl;
        cout << " ***************************" << endl;
        cout << "\n\n";
        cout << " ENTER " << endl;
        cout << " **** 1. To Display List of Metros ****" << endl;
        cout << " *****************************************" << endl;
        cout << " **** 2. To Book Ticket ****" << endl;
        cout << " *****************************************" << endl;
        cout << " **** 3. Exit ****" << endl;
        cout << " *****************************************" << endl;
    }

    void list_cities(int N) {
        datamodule o;
        cout << endl;
        system("CLS");
        cout << "\n\n ****************************WELCOME TO METRO PATH GENERATOR**************************" << endl;
        cout << "\n\n";
        cout << " The listed cities are:" << endl;
        cout << " *****************************************" << endl;
        for (int i = 0; i < N; i++) {
            cout << " * " << o.city[i] << " " << endl;
            cout << " *" << endl;
        }
        cout << " *****************************************" << endl;
    }

    void ticket(int total_price, int no, string source, string destination, string username) {
        system("CLS");
        cout << "\n\n **************************** E-TICKET**************************" << endl;
        cout << endl << " This Ticket is issued for :" << username << endl;
        cout << endl << " Source:" << source << endl;
        cout << endl << " Destination:" << destination << endl;
        cout << endl << " Total No of Passengers:" << no << endl;
        cout << endl << " Total Cost:" << total_price << endl;
        cout << "\n\n****************************************************************************" << endl;
    }

    void passengerdetailedticket(int no, string firstname[], string lastname[], string sex[], int age[]) {
        for (int i = 0; i < no; i++) {
            cout << " Passenger " << (i + 1) << " Details:" << endl << endl;
            cout << " First Name: " << firstname[i] << endl;
            cout << " Last Name: " << lastname[i] << endl;
            cout << " Sex: " << sex[i] << endl;
            cout << " Age: " << age[i] << endl;
            cout << "\n\n****************************************************************************" << endl;
        }
        int ch;
        cout << endl << " Enter 1 to continue:";
        cin >> ch;
        if (ch == 1) {
            initial();
        }
    }

    int display_price(string source, string destination, int N, string username) {
        datamodule o;
        inputmodule in;
        int choiceofpassenger;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (source == o.city[i] && destination == o.city[j]) {
                    cout << endl;
                    if (ini[i].cost[j] == infinity && travel[i].cost[j] == infinity) {
                        cout << " Sorry, There are no METRO available connecting the destination" << endl;
                        return 0;
                    } else if (ini[i].cost[j] == infinity) {
                        cout << " There is no direct metro from" << source << " to " << destination << ". So, Travel via other metro is only possible." << endl;
                        cout << " The Price is:" << travel[i].cost[j] << endl << endl;
                        cout << " The Route is:" << source;
                        int c1 = i, c2 = j;
                        while (c1 != c2) {
                            cout << "-->" << o.city[travel[c1].array[j]];
                            c1 = travel[c1].array[j];
                        }
                        cout << endl << endl;
                    } else if ((ini[i].cost[j] == 0) || (travel[i].cost[j] == 0)) {
                        cout << " You are here only xD " << endl;
                        return 0;
                    } else if ((ini[i].cost[j] != infinity) && (ini[i].cost[j] == travel[i].cost[j])) {
                        cout << " There is direct metro available from" << source << " to " << destination << " . And, it is cheapest among all other paths..." << endl;
                        cout << " The Price is:" << travel[i].cost[j] << endl;
                    } else if ((ini[i].cost[j] != infinity) && (ini[i].cost[j] > travel[i].cost[j])) {
                        cout << " There is direct metro available from" << source << " to " << destination << " ." << endl;
                        cout << " The Price is:" << ini[i].cost[j] << endl << endl;
                        cout << " *****************************************" << endl << endl;
                        cout << " You can go via other metro that will cost you less than direct flight." << endl;
                        cout << " The Price is:" << travel[i].cost[j] << endl << endl;
                        cout << " The Route is:" << source;
                        int c1 = i, c2 = j;
                        while (c1 != c2) {
                            cout << "-->" << o.city[travel[c1].array[j]];
                            c1 = travel[c1].array[j];
                        }
                        cout << endl << endl;
                        cout << " Press 1 to go by direct metro and Press 2 to go via other metro: ";
                        cin >> choiceofpassenger;
                    }
                    char c;
                    cout << endl;
                    cout << " Do You want to Continue(Y/N)?";
                    cin >> c;
                    if (c == 'Y' || c == 'y') {
                        int no = in.noofpassenger();
                        string firstname[no], lastname[no], sex[no];
                        int age[no];
                        for (int i = 0; i < no; i++) {
                            cout << endl;
                            cout << "*****************************************" << endl;
                            cout << " Passenger" << (i + 1) << ":" << endl << endl;
                            cout << " First Name:";
                            cin >> firstname[i];
                            cout << endl << " Last Name:";
                            cin >> lastname[i];
                            cout << endl << "Sex(Male/Female/Other):";
                            cin >> sex[i];
                            cout << endl << " Age:";
                            cin >> age[i];
                        }
                        int total_price;
                        if (choiceofpassenger == 1) {
                            total_price = no * ini[i].cost[j];
                        } else {
                            total_price = no * travel[i].cost[j];
                        }
                        cout << endl << " The total Price is:" << total_price << endl;
                        char y;
                        cout << " Do You want to confirm Your Ticket(Y/N)?";
                        cin >> y;
                        if (y == 'Y' || y == 'y') {
                            filehandlingmodule f;
                            f.ticket(username, firstname, lastname, sex, age, no);
                            ticket(total_price, no, source, destination, username);
                            passengerdetailedticket(no, firstname, lastname, sex, age);
                        } else {
                            cout << endl << " Thank You For choosing Us...";
                            cout << endl << " Do You Want to Continue(Y/N)?";
                            char ch;
                            cin >> ch;
                            if (ch == 'Y' || ch == 'y') {
                                initial();
                            }
                            return 0;
                        }
                    } else {
                        cout << endl << " Thank You For choosing Us...";
                        cout << endl << " Do You Want to Continue(Y/N)?";
                        char ch;
                        cin >> ch;
                        if (ch == 'N' || ch == 'n') {
                            initial();
                        }
                        return 0;
                    }
                }
            }
        }
        cout << " Sorry, There are no metros available connecting the destination!" << endl;
        cout << endl << " Do You Want to Continue(Y/N)?";
        char ch;
        cin >> ch;
        if (ch == 'Y' || ch == 'y') {
            initial();
        }
        return 0;
    }
};

int main() {
    int N;
    N = 15;
    datamodule obj;
    obj.costdeclaration();
    bellmanfordalgorithm ob1;
    ob1.algorithmic_implementation();
    string userchoice[2];
    inputmodule obj1;
    string username;
    username = obj1.login();
    outputmodule object;
    object.initial();
    while (true) {
        int choice;
        cout << "\n Enter Your Choice:";
        cin >> choice;
        switch (choice) {
            case 1:
                object.list_cities(N);
                cout << "\n\n Press 1 to Continue...";
                int cont;
                cin >> cont;
                if (cont == 1) {
                    object.initial();
                }
                break;
            case 2:
                obj1.user_input(userchoice);
                object.display_price(userchoice[0], userchoice[1], N, username);
                break;
            case 3:
                return 0;
        }
    }
    return 0;
}

