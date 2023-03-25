#pragma once
#include <algorithm>

template <typename Iterator>
Iterator partition(Iterator i, Iterator j, Iterator pivot) {
    // P�tla while, kt�ra przechodzi po li�cie, zamieniaj�c elementy wi�ksze od pivota na pocz�tek
    while (j != pivot) {
        if (*j > *pivot) {
            i--;
            std::swap(*j, *i);
        }
        j--;
    }
    // Zamiana warto�ci pivota z ostatnim elementem mniejszym od pivota
    std::swap(*(i - 1), *pivot);
    return i-1;
}

template <typename Iterator>
void quickSort(Iterator first, Iterator last) {
    // Sprawdzenie, czy lista do posortowania jest niepusta
    if (distance(first, last) <= 1 && std::is_sorted(first, last)) {
        return;
    }
    
    // Wywo�anie funkcji partycjonuj�cej
    auto pivot = partition(last, last-1, first);

    // Rekurencyjne wywo�anie quickSort dla lewej i prawej cz�ci listy
    quickSort(first, pivot);
    quickSort(pivot+1, last);
}

