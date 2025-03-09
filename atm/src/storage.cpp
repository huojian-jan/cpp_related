//
// Created by yasen on 2025/3/9.
//
#include "../include/storage.h"

void parse_data(vector<string> parsed_data,string raw_data)
{
    std::vector<std::string> result;
    std::string token;

    std::stringstream ss(raw_data);
    while (std::getline(ss, token, '|')) {
        result.push_back(token);
    }
}

void get_all_users(vector<user_info> users)
{
    //按行读取db_path文件
    std::ifstream file(db_path);
    std::string str;
    while (std::getline(file, str))
    {
        vector<string> parsed_data;
        parse_data(parsed_data,str);

        user_info info;
        info.user_name=parsed_data[0];
        info.passwd_hash=parsed_data[1];
        info.balance= stoi(parsed_data[2]);
        info.user_id=stol(parsed_data[3]);
    }
}

void write_all_users(vector<user_info> users)
{
    std::ofstream outFile;
    outFile.open(db_path, std::ios::trunc); // std::ios::app 表示追加模式

    for (auto &user:users)
    {
        string data;
        data+=user.user_name+"|";
        data+=user.passwd_hash+"|";
        data+=to_string(user.balance)+"|";
        data+=to_string(user.user_id);
        if (outFile.is_open()) {
            outFile <<data << std::endl; // 追加文本并换行
        }
    }
    outFile.close(); // 关闭文件
}

void create_user_id(long* user_id)
{
    //TODO(生成随机的user_id)
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<long> dis(0, 1000000000);
    *user_id = dis(gen);
}



bool log_in(const string &user_name, const string &passwd) {
    vector<user_info> users;
    get_all_users(users);
    for (auto &user:users)
    {
        if(user.user_name==user_name && user.passwd_hash==passwd)
        {
            return true;
        }
    }
    return false;
}


user_info &create_user(const string &user_name, const string &passwd) {
    user_info new_user;
    new_user.user_name = user_name;
    new_user.passwd_hash = passwd;
    create_user_id(&new_user.user_id);
    new_user.balance = 0;

    std::ofstream outFile;
    outFile.open(db_path, std::ios::app); // std::ios::app 表示追加模式

    string data;
    data += new_user.user_name + "|";
    data += new_user.passwd_hash + "|";
    data += to_string(new_user.balance) + "|";
    data += to_string(new_user.user_id);

    if (outFile.is_open()) {
        outFile << data << std::endl; // 追加文本并换行
        outFile.close(); // 关闭文件
        return new_user;
    }
    return new_user;
}


long &get_balance_by_id(const long &user_id) {
    vector<user_info> users;
    get_all_users(users);
    for (auto &user:users)
    {
        if(user.user_id==user_id)
        {
            return user.balance;
        }
    }
    return users[0].balance;
}

void append_money_by_Id(const long &id, const int &amount)
{
    vector<user_info> users;
    get_all_users(users);
    for (auto &user:users)
    {
        if(user.user_id==id)
        {
            user.balance+=amount;
        }
    }
    write_all_users(users);
}
