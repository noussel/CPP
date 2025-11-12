#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <string>

class contact {
    private:
        std::string first_name;
        std::string last_name;
        std::string nick_name;
        std::string phone_number;
        std::string DarkestSecret;
    public:
        void setinfo();
        void displayshort(int index) const;
        void displayfull() const;
};
#endif