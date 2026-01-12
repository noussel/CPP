#include "ScalarConverter.hpp"

const char *ERROR::what() const throw(){
    return "\033[31mERROR\033[0m\n";
}

static bool is_char(std::string &s){
    if(s.length() == 1 && !std::isdigit(s[0]))
        return true;
    return false;
}

static bool is_int(std::string s){
    unsigned int i = 0;
    if(s[i] == '+' || s[i] == '-')
        i++;
    if(i == s.length())
        return false;
    for(; i < s.length(); i++){
        if(!std::isdigit(s[i]))
            return false;
    }
    return true;
}

static bool is_float(std::string &s){
    unsigned int i = 0;
    bool pointFound = false;

    if(s[i] == '+' || s[i] == '-')
        i++;
    if(i == s.length())
        return false;
    for(; i < s.length()-1; i++){
        if(!std::isdigit(s[i]))
        {
            if(s[i] == '.' && !pointFound && s[i+1] && s[i+2])
                pointFound = true;
            else
                return false;  
        }
    }
    if(s[i] == 'f')
        return true;
    return false;
}

static bool is_double(std::string &s){
    unsigned int i = 0;
    bool pointFound = false;

    if(s[i] == '+' || s[i] == '-')
        i++;
    if(i == s.length())
        return false;
    for(; i < s.length(); i++){
        if(!std::isdigit(s[i])){
            if(s[i] == '.' && !pointFound && s[i + 1])
                pointFound = true;
            else
                return false;
        }
    }
    return true;
}

bool is_special(const std::string& s)
{
    return (s == "nan" || s == "nanf"
        || s == "+inf" || s == "-inf"
        || s == "+inff" || s == "-inff");
}

static TYPE detectType(std::string &s){
    if(is_special(s))
        return IS_sPECIAL;
    if(is_char(s))
        return IS_CHAR;
    if(is_int(s))
        return IS_INT;
    if(is_float(s))
        return IS_FLOAT;
    if(is_double(s))
        return IS_DOUBLE;
    return IS_INVALID;
}

static double toDouble(std::string &arg, TYPE type){
    if(type == IS_CHAR)
        return static_cast<double>(arg[0]);//just trying std::atof(literal)
    if(type == IS_INT)
        return static_cast<double>(strtod(arg.c_str(), NULL));
    if(type == IS_FLOAT || type == IS_DOUBLE)
        return static_cast<double>(strtod(arg.c_str(), NULL));
    if(type == IS_sPECIAL )
        return static_cast<double>(strtod(arg.c_str(), NULL));
    else
        throw ERROR();
}

void coutChar(TYPE type, double value)
{
    char c = static_cast<char>(value);
    if(type == IS_sPECIAL || value > 127 || value < 0)
        std::cout << "char : impossible\n";
    else if (value < 32 || value > 126)
        std::cout << "char: Non displayable\n";
    else
        std::cout << "Char : '" << c << "'\n";
}

void coutInt(double value, TYPE type){
    int i = static_cast<int>(value);
    if(type == IS_sPECIAL || value > INT_MAX || value < INT_MIN)
        std::cout << "int : impossible\n";
    else 
        std::cout << "int : " << i << "\n";
}

bool NonFractinal(std::string &arg){
    unsigned int l = arg.length();
    if(arg[l-1] == 'f' && arg[l-2] == '0' && arg[l-3] == '.')
        return true;
    else if (arg[l-1] == '0' && arg[l-2] == '.')
        return true;
    return false;
}

void coutFloat(double value, TYPE type, std::string &arg){
    float f = static_cast<float>(value);
    if(value > FLT_MAX || value < -FLT_MAX)
        std::cout << "float : " << (value > 0 ? "+inff\n" : "-inff\n");
    else if(type == IS_INT || type == IS_CHAR || NonFractinal(arg))
        std::cout << "float : " << f << ".0f\n";
    else
        std::cout << "float : " << f << "f\n";
}

void coutDouble(double value, TYPE type, std::string &arg){
    double d = static_cast<double>(value);
    if(type == IS_INT || type == IS_CHAR || NonFractinal(arg))
        std::cout << "double : " << d << ".0\n";
    else
        std::cout << "double : " << d << "\n";
    }

void coutInvalid(TYPE type){
    if(type == IS_INVALID)
        throw ERROR();
}

void ScalarConverter::convert(std::string arg){
    TYPE type = detectType(arg);
    double value;////////////////111111111111111111111111111111111111
    value = toDouble(arg, type);

    coutInvalid(type);
    coutChar(type, value);
    coutInt(value, type);
    coutFloat(value, type, arg);
    coutDouble(value , type, arg);
}
