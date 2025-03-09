//
// Created by yasen on 2025/3/9.
//

#ifndef ATM_STORAGE_H
#define ATM_STORAGE_H
#include<iostream>
#include<string>
#include<random>
#include<vector>
#include<fstream>
#include<sstream>

using namespace std;
struct user_info {
    string user_name;
    string passwd_hash;
    long balance;
    long user_id;
};

bool log_in(const string& user_name,const string& passwd);
user_info& create_user(const string& user_name,const string& passwd);
long& get_balance_by_id(const long& user_id);
void append_money_by_Id(const long& id,const int& amount);

const string& db_path = "db/db.txt";
#endif //ATM_STORAGE_H
