#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

int isNumber(std::string s);
class contact {
    private:
        std::string FirstName;
        std::string LastName;
        std::string NickName;
        std::string PhoneNumber;
        std::string DarkestSecret;
    public:
        void setinfo(std::string FN, std::string LN, std::string NN, std::string PN, std::string DS);
        void displayshort(int index);
        void displayfull();
};


#endif