
#include "../include/atm.h"

int main() {
    init();
    string input;
    while(true) {
    main_menu();
        cin >> input;
        if(cin.fail()) {
            continue;
        }
        if(input=="q") {
            break;
        }
    }
    return 0;
}


void init_lang_res() {
    lang_res.clear();
    lang_res[Greet].emplace_back("欢迎来到大佐银行\n");
    lang_res[Greet].emplace_back("Welcome to DaZuo Bank\n");

    lang_res[One_Operation].emplace_back("1代表查询余额\n");
    lang_res[One_Operation].emplace_back("1 represents checking the balance\n");


    lang_res[Two_Operation].emplace_back("2代表取款\n");
    lang_res[Two_Operation].emplace_back("2 represents withdrawing money\n");

    lang_res[Three_Operation].emplace_back("3代表存款\n");
    lang_res[Three_Operation].emplace_back("3 represents deposit\n");

    lang_res[Four_Operation].emplace_back("4代表创建新账户\n");
    lang_res[Four_Operation].emplace_back("4 represents create account\n");

    lang_res[Exit_Operation].emplace_back("q 代表退出程序\n");
    lang_res[Exit_Operation].emplace_back("q represents to quit\n");
}

void init() {
    current_lang = "EN";
    init_lang_res();
}

string & get_lang_str(const string &lang_key) {
    if(current_lang=="CN") {
        return lang_res[lang_key][0];
    }else {
        return lang_res[lang_key][1];
    }
}

void main_menu() {
    cout<<lang_res[Greet][0];
    cout<<lang_res[One_Operation][0];
    cout<<lang_res[Two_Operation][0];
    cout<<lang_res[Three_Operation][0];
    cout<<lang_res[Four_Operation][0];
    cout<<lang_res[Exit_Operation][0];
}

void query_balance() {
    if(!require_auth_if_need())
    {
        throw Auth_Failed;
    }
    long balance= get_balance_by_id(_user_info->user_id);
    cout<<"your balance= "<<balance<<endl;
}

void withdraw(const int &amount) {
    if(!require_auth_if_need())
    {
        throw Auth_Failed;
    }

    long balance= get_balance_by_id(_user_info->user_id);
    if(balance<amount)
    {
        throw "余额不足";
    }
    append_money_by_Id(_user_info->user_id,-amount);
    balance= get_balance_by_id(_user_info->user_id);
    cout<<"successfully withdraw"<<amount<<",current balance="<<balance<<endl;
}

void deposit(const int &amount) {
    if(!require_auth_if_need())
    {
        throw Auth_Failed;
    }

    long balance= get_balance_by_id(_user_info->user_id);
    if(balance<amount)
    {
        throw "余额不足";
    }
    append_money_by_Id(_user_info->user_id,amount);
    balance= get_balance_by_id(_user_info->user_id);
    cout<<"successfully deposit"<<amount<<",current balance="<<balance<<endl;
}

void create_accont() {

}

void quit() {
    exit(0);
}






