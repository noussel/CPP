#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(){
    static bool started = false;

    if(!started)
    {
        std::srand(std::time(NULL));
        started = true;
    }

    int r = rand() % 3;
    if(r == 0)
        return new A();
    else if(r == 1)
        return new B();
    else
        return new C();
}

void identify(Base *p){
    A* a;
    B* b;
    C* c;

    a = dynamic_cast<A*>(p);
    if(a)
        std::cout << "pointer type is : A\n";
    b = dynamic_cast<B*>(p);
    if(b)
        std::cout << "pointer type is : B\n";
    c = dynamic_cast<C*>(p);
    if(c)
        std::cout << "pointer type is : C\n";
}

void identify(Base &p){
    
    try{
        A& a = static_cast<A&>(p);
        (void)a;
        std::cout << "pointer type is : A\n";
    }
    catch(std::exception &e){
    }
    try{
        B& b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "pointer type is : B\n";
    }
    catch(std::exception &e){
    }
    try{
        C& c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "pointer type is : C\n";
    }
    catch(std::exception &e){
    }
}

Base::~Base(){}
