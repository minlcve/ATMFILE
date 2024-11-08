#include <iostream>
#include <string>
#include <cstdlib>


void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();
void manageAccount();


std::string userId;
std::string userPassword;
double balance = 0.0;
char menuInput;

void printIntroMenu() {
    std::cout << "Please select an option from the menu below:\n";
    std::cout << "l  -> Login\n";
    std::cout << "c -> Create New Account\n";
    std::cout << "q -> Quit\n";
    std::cout << "> ";
}

void printMainMenu() {
    std::cout << "d  -> Deposit Money\n";
    std::cout << "w -> Withdraw Money\n";
    std::cout << "r -> Request Balance\n";
    std::cout << "q -> Quit\n";
    std::cout << "> ";
}

void start() {
    while (true) {
        printIntroMenu();  // Display the intro menu
        std::cin >> menuInput;  // Get user input

        switch (menuInput) {
            case 'l':  // Login option
                login();
                break;
            case 'c':  // Create New Account
                createAccount();
                break;
            case 'q':  // Quit program
                std::cout << "Thanks for stopping by!\n";
                exit(0);
            default:
                std::cout << "Invalid input. Please try again.\n";
        }
    }
}

void createAccount() {
    std::string inputId, inputPassword;

    std::cout << "Please enter your user name: ";
    std::cin >> inputId;
    std::cout << "Please enter your password: ";
    std::cin >> inputPassword;

    userId = inputId;  // Store the user id
    userPassword = inputPassword;  // Store the user password

    std::cout << "Thank You! Your account has been created!\n";
}

void login() {
    std::string inputId, inputPassword;

    std::cout << "Please enter your user id: ";
    std::cin >> inputId;
    std::cout << "Please enter your password: ";
    std::cin >> inputPassword;

    // Validate login
    if (inputId == userId && inputPassword == userPassword) {
        std::cout << "Access Granted!\n";
        manageAccount();  // Call manageAccount after login success
    } else {
        std::cout << "******** LOGIN FAILED! ********\n";
    }
}

void manageAccount() {
    while (true) {
        printMainMenu();  // Display the main menu
        std::cin >> menuInput;  // Get user input

        switch (menuInput) {
            case 'd':  // Deposit Money
                {
                    double depositAmount;
                    std::cout << "Amount of deposit: $";
                    std::cin >> depositAmount;
                    balance += depositAmount;
                    break;
                }
            case 'w':  // Withdraw Money
                {
                    double withdrawAmount;
                    std::cout << "Amount of withdrawal: $";
                    std::cin >> withdrawAmount;
                    if (withdrawAmount > balance) {
                        std::cout << "Insufficient funds!\n";
                    } else {
                        balance -= withdrawAmount;
                    }
                    break;
                }
            case 'r':  // Request Balance
                std::cout << "Your balance is $" << balance << ".\n";
                break;
            case 'q':  // Quit
                std::cout << "Thanks for stopping by!\n";
                exit(0);
            default:
                std::cout << "Invalid input. Please try again.\n";
        }
    }
}
