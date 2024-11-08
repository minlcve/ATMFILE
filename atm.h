#ifndef ATM_H
#define ATM_H

#include <string>

void printIntroMenu();
void printMainMenu();
void start();
void login();
void createAccount();

extern std::string userId;
extern std::string userPassword;
extern double balance;

#endif
