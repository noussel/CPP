#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <climits>
#include <cstdlib>
#include <cctype>
#include <algorithm>

template <typename Container>
void PmergeMe::FordJohnson(Container &c)
{
    if (c.size() <= 1)
        return;

    typedef typename Container::value_type value_type;

    Container maxList;
    Container minList;

    // 1️⃣ Former les paires
    for (size_t i = 0; i + 1 < c.size(); i += 2)
    {
        if (c[i] > c[i + 1])
        {
            maxList.push_back(c[i]);
            minList.push_back(c[i + 1]);
        }
        else
        {
            maxList.push_back(c[i + 1]);
            minList.push_back(c[i]);
        }
    }

    // 2️⃣ Élément impair
    bool hasStraggler = false;
    value_type straggler;
    if (c.size() % 2 != 0)
    {
        hasStraggler = true;
        straggler = c[c.size() - 1];
    }

    // 3️⃣ Trier récursivement les max
    FordJohnson(maxList);

    // 4️⃣ Construire la chaîne principale
    Container mainChain = maxList;

    // 5️⃣ Insertion binaire des min
    for (size_t i = 0; i < minList.size(); i++)
    {
        typename Container::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), minList[i]);

        mainChain.insert(pos, minList[i]);
    }

    // 6️⃣ Insérer l’élément impair
    if (hasStraggler)
    {
        typename Container::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), straggler);

        mainChain.insert(pos, straggler);
    }

    // 7️⃣ Copier le résultat dans c
    c = mainChain;
}
