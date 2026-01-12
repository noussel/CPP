#include "ShrubberyCreationForm.hpp"



const char *FileException::what() const throw(){
    return("fealed to create file .\n");
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target){

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &other) : AForm("ShrubberyCreationForm", 145, 137), target(other.target){
        
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &other){
    if(this != &other)
        this->target = other.target;
    return *this;
}

void ShrubberyCreationForm::executeAction(Bureaucrat const &executor) const{
    (void) executor;
    std::string fileName(target + "_shrubbery");
    try{
        std::ofstream file(fileName.c_str());
        if(!file)
            throw FileException();
        file << "        *\n";
        file << "       ***\n";
        file << "      *****\n";
        file << "     *******\n";
        file << "       ***\n";
        file << "       ***\n";
        file << "       ***\n";
        file << "    =========\n";
        file << "\n";
        file.close();
        std::ifstream in(fileName.c_str());
        std::cout << in.rdbuf();
        in.close();
    }
    catch(std::exception &e){
        std::cerr << e.what();
    }
}

ShrubberyCreationForm::~ShrubberyCreationForm(){

}
