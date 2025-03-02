
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

    lang_res.insert(pair<string,vector<string>>(Greet,vector<string>()));
    lang_res.insert(pair<string,vector<string>>(One_Operation,vector<string>()));
    lang_res.insert(pair<string,vector<string>>(Two_Operation,vector<string>()));
    lang_res.insert(pair<string,vector<string>>(Three_Operation,vector<string>()));
    lang_res.insert(pair<string,vector<string>>(Four_Operation,vector<string>()));
    lang_res.insert(pair<string,vector<string>>(Exit_Operation,vector<string>()));

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
    for (const auto &item: lang_res) {
        cout << get_lang_str(item.first);
    }
}






