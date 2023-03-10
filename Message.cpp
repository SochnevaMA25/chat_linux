#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;

class Message {
    std::string _text;
    std::string _sender; //otpr
    std::string _receiver;
    public:
    Message(std::string receiver, std::string sender, std::string text)
    : _receiver(receiver), _sender(sender), _text(text)
    {
        read_mes();
        record_mes();
    }

    void record_mes()
    {
        std::string full_name = "mes" + _receiver + ".txt";
        std::ofstream out(full_name);
        if (out.is_open())
        {
            out << _sender << ": " << _text << std::endl;
        }
        out.close(); 
    }
    bool check_mes()
    {
        std::string full_name = "mes" + _sender + ".txt";
        std::ifstream out(full_name);
        if (out.is_open())
        {
            out.close();
            return true;
        } 
        return false;
    }
    void read_mes()
    {
        std::string line;
        if (check_mes() == true)
        {
            std::string full_name = "mes" + _sender + ".txt";
            std::ifstream out(full_name);
            if (out.is_open())
            {
               while (getline(out, line))
                {    
                    std::cout << line << std::endl;
                }
                
            } 
            out.close();
        } else
        {
            std::cout << "NO MESSAGE" << std::endl;
        }
    }
};