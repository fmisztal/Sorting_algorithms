#pragma once
#include <algorithm>
#include <iostream>
// Implementacja algorytmu sortowania bąbelkowego (bubble sort) dla szablonowej funkcji.
// Funkcja przyjmuje jako argumenty iteratory wskazujące na pierwszy i ostatni element sortowanej kolekcji.

template <typename Iterator>
void bubbleSort(Iterator first, Iterator last)
{
    bool wasChanged = true; // Flaga s�u��ca do wykrywania momentu, gdy nie ma ju� element�w do zamiany.
    auto lastToSort = last; // Przechowujemy d�ugo�� kolekcji.

    // Pętla iterująca po wszystkich elementach kolekcji.
    for (auto i = first; i != last && wasChanged ; i++) {

        wasChanged = false;

        // Pętla iterująca po sąsiadujących elementach.
        for (auto j = first; j != (lastToSort - 1); j++) {

            // Jeśli sąsiadujące elementy są w złej kolejności, to je zamieniamy.
            if (*j > *(j + 1)) {
                std::swap(*j, *(j + 1));
                wasChanged = true; // Ustawiamy flagę, aby pokazać, że wykonaliśmy zamianę.
            }
        }

        lastToSort--; // Skracamy przedział o ostatni element, który został przesunięty na właściwe miejsce
    }
}