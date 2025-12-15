#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain {
    private :
        std::string ideas[100];
    public :
        Brain();
        Brain(const Brain &other);
        std::string getBrainIdeas(int index);
        void setBrainIdeas(int index, std::string str);
        Brain &operator=(const Brain &other);
        ~Brain();
};

#endif