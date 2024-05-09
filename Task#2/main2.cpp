#include <iostream>
#include <string>
#include <vector>
#include <map>

class PhoneBook
{
    std::map<std::string, std::string> NumberToSurname;
    std::map<std::string, std::vector<std::string>> SurnameToNumber;
    bool number(std::string tmp)
    {
        if ((tmp.size() == 12 || tmp.size() == 11) && ((tmp[0] == '+' && tmp[1] == '7') || (tmp[0] == '8')))
        {
            for (int i = 1; i < tmp.size(); i++)
            {
                if (tmp[i] <= '0' && tmp[i] >= '9')
                    return false;
            }
            return true;
        }
        else
            return false;
    }

public:
    void add()
    {
        std::string numb, nameContact;
        std::cout << "Enter number and name contact: ";
        std::cin >> numb >> nameContact;
        // for (int i = 0; i < 8; ++i)
        // {
        //     numb += tmp[i];
        // }
        // std::string nameContact = "";
        // for (int i = 9; i < tmp.size(); ++i)
        // {
        //     nameContact += tmp[i];
        // }
        NumberToSurname.insert(std::pair<std::string, std::string>(numb, nameContact));
        SurnameToNumber[nameContact].push_back(numb);
    }
    void call()
    {
        std::string callUp;
        std::cout << "Enter number or name: ";
        std::cin >> callUp;
        if (number(callUp))
        {
            if (NumberToSurname.count(callUp) > 0) // если имя есть, то выводить имя, иначе номер
            {
                std::cout << "You called " << NumberToSurname.find(callUp)->second << "\nCALL..." << std::endl;
            }
            else
                std::cout << "You called number " << callUp;
        }
        else
        {
            if (SurnameToNumber.count(callUp) > 0)
            {
                if (SurnameToNumber.find(callUp)->second.size() > 1)
                {
                    std::cout << "What number to call?" << std::endl;
                    for (int i = 0; i < SurnameToNumber.find(callUp)->second.size(); ++i) // вывод номера контакта по имени
                    {
                        std::cout << i + 1 << ") " << SurnameToNumber.find(callUp)->second[i] << std::endl;
                    }
                    int id;
                    std::cout << "Enter ID: ";
                    std::cin >> id;
                    std::cout << "You called " << SurnameToNumber.find(callUp)->second[id - 1] << "\nCALL..." << std::endl;
                }
                else
                    std::cout << "You called " << SurnameToNumber.find(callUp)->second[0] << "\nCALL..." << std::endl;
            }
            else
                std::cout << "ERROR: this contact not found.";
        }
    }
    void sms()
    {
        std::string sendSMS, SMS;
        std::cout << "Enter number or name: ";
        std::cin >> sendSMS;
        std::cout << "Enter text SMS: ";
        std::cin >> SMS;
        if (number(sendSMS))
        {
            if (NumberToSurname.count(sendSMS) > 0) // если имя есть, то выводить имя, иначе номер
            {
                std::cout << "You send SMS " << NumberToSurname.find(sendSMS)->second << "\nCALL..." << std::endl;
            }
            else
                std::cout << "You send SMS number " << sendSMS;
        }
        else
        {
            if (SurnameToNumber.count(sendSMS) > 0)
            {
                if (SurnameToNumber.find(sendSMS)->second.size() > 1)
                {
                    std::cout << "What number to call?" << std::endl;
                    for (int i = 0; i < SurnameToNumber.find(sendSMS)->second.size(); ++i) // вывод номера контакта по имени
                    {
                        std::cout << i + 1 << ") " << SurnameToNumber.find(sendSMS)->second[i] << std::endl;
                    }
                    int id;
                    std::cout << "Enter ID: ";
                    std::cin >> id;
                    std::cout << "You send SMS " << SurnameToNumber.find(sendSMS)->second[id - 1] << "\nCALL..." << std::endl;
                }
                else
                    std::cout << "You send SMS " << SurnameToNumber.find(sendSMS)->second[0] << "\nCALL..." << std::endl;
            }
            else
                std::cout << "ERROR: this contact not found.";
        }
    }
};
int main()
{
    PhoneBook phoneBook;
    std::string command;
    while (command != "exit")
    {
        std::cout << "Enter command: ";
        std::cin >> command;
        if (command == "add")
            phoneBook.add();
        else if (command == "call")
            phoneBook.call();
        else if (command == "sms")
            phoneBook.sms();
    }
}
