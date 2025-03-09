//
// Created by yasen jan on 2025/3/2.
//

#ifndef ATM_H
#define ATM_H

#include <iostream>
#include<iostream>
#include<string>
#include<exception>
#include<map>
#include <vector>

#include "./storage.h"

using namespace std;
const string Greet="Greetings";
const string One_Operation ="One_Operation";
const string Two_Operation ="Two_Operation";
const string Three_Operation="Three_Operation";
const string Four_Operation ="Four_Operation";
const string Exit_Operation ="Exit_Operation";


const string Auth_Failed="Failed to authentication,please check your user_name or password";


map<string,vector<string>> lang_res;
string current_lang;

void init_lang_res();
void init();
string& get_lang_str(const string& lang_key);

user_info* _user_info;

bool& require_auth_if_need();

void query_balance();
void withdraw(const int& amount);
void deposit(const int& amount);
void create_accont();
void quit();

void main_menu();
int main();
#endif //ATM_H
