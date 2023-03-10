#include <fstream>
#include <iostream>
#include <cstring>
#include <filesystem>

namespace fs = std::filesystem;

class User {
    std::string _name;
    std::string _login;
    std::string _pass;
    public:
    User(std::string name, std::string login, std::string pass)
    : _name(name), _login(login), _pass(pass)
    {
        if (check_login() == true)
        {
            if(check_pass() == true)
            {
                std::cout << "OK!" << std::endl;
            } else
            {
                std::cout << "Fail pass!" << std::endl;
            }
        } else
        {
            record();
        }
        
    }
    void record()
    {
        std::string full_name = _name + ".txt";
        std::ofstream out(full_name);
        if (out.is_open())
        {
            out << "Login: " << _login << ", " << "Pass: " << _pass << ";" << std::endl;
        }

        fs::permissions(full_name,
        fs::perms::group_write | fs::perms::others_all,
        fs::perm_options::remove);
        out.close();     
    }
    bool check_login()
    {
        std::string full_name = _name + ".txt";
        std::ifstream in(full_name); // окрываем файл для чтения
        std::string line;
        char c_login[25];
        if (in.is_open())
        {
            while (getline(in, line))
            {
                const char* type_str = strstr(line.c_str(),"Login: ");
                const char* type_str1 = strstr(type_str, ",");
                if (type_str && type_str1)
                {
                    type_str = type_str + strlen("Login: ");
                    int size = strlen(type_str) - strlen(type_str1);
                    strncpy(c_login, type_str, size);
                    c_login[size] = 0;
                    break;
                }
            }
        }
        if (strcmp(c_login, _login.c_str()) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        in.close();  
    }

    bool check_pass()
    {
        std::string full_name = _name + ".txt";
        std::ifstream in(full_name); // окрываем файл для чтения
        std::string line;
        char c_pass[25];
        if (in.is_open())
        {
            while (getline(in, line))
            {
                const char* type_str = strstr(line.c_str(),"Pass: ");
                const char* type_str1 = strstr(type_str, ";");
                if (type_str && type_str1)
                {
                    type_str = type_str + strlen("Pass: ");
                    int size = strlen(type_str) - strlen(type_str1);
                    strncpy(c_pass, type_str, size);
                    c_pass[size] = 0;
                    break;
                }
            }
        }
        if (strcmp(c_pass, _pass.c_str()) == 0)
        {
            return true;
        }
        else
        {
            return false;
        }
        in.close();  
    }

};