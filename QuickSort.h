#pragma once
#include <algorithm>

template <typename Iterator>
Iterator partition(Iterator i, Iterator j, Iterator pivot) {
    // Pêtla while, która przechodzi po liœcie, zamieniaj¹c elementy wiêksze od pivota na pocz¹tek
    while (j != pivot) {
        if (*j > *pivot) {
            i--;
            std::swap(*j, *i);
        }
        j--;
    }
    // Zamiana wartoœci pivota z ostatnim elementem mniejszym od pivota
    std::swap(*(i - 1), *pivot);
    return i-1;
}

template <typename Iterator>
void quickSort(Iterator first, Iterator last) {
    // Sprawdzenie, czy lista do posortowania jest niepusta
    if (distance(first, last) <= 1 && std::is_sorted(first, last)) {
        return;
    }
    
    // Wywo³anie funkcji partycjonuj¹cej
    auto pivot = partition(last, last-1, first);

    // Rekurencyjne wywo³anie quickSort dla lewej i prawej czêœci listy
    quickSort(first, pivot);
    quickSort(pivot+1, last);
}

