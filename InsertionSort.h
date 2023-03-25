#pragma once

template <typename Iterator>
void insertionSort(Iterator first, Iterator last) {
    // Sprawdzenie, czy lista do posortowania jest niepusta
    if (first == last) {
        return;
    }
    // P�tla iteruj�ca po elementach listy, pocz�wszy od drugiego
    for (auto i = (first + 1); i != last; i++) {
        // Ustawienie wska�nika j na poprzedni element
        auto j = i - 1;
        // Dop�ki warto�� nast�pnego elementu jest mniejsza od warto�ci aktualnego elementu
        while (*(j + 1) < *j) {
            // Zamiana miejscami warto�ci nast�pnego elementu z warto�ci� aktualnego elementu
            std::swap(*(j + 1), *j);
            // Przesuni�cie wska�nika j na poprzedni element
            if (j == first)
                break;
            j--;
        }
    }
}