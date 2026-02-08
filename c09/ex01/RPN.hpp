#pragma once
#include <iostream>


// 5 1 2 + 4 * + 3 -
// 5 3 4 * + 3 -
// 5 12 + 3 -
// 17 3 -
// 14
// 5 + ((1 + 2) * 4) - 3
class RPN {
    // parse calculate afficher 
    private :

    public :
    RPN();
    RPN(RPN &other);
    RPN &operator=(RPN &other);
    ~RPN();


}
















// Le programme doit afficher Error si :

// expression invalide
// pas assez d’opérandes
// division par zéro
// caractères non autorisés
// pile finale ≠ 1 élément