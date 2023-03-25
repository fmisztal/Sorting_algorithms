#pragma once

template <typename Iterator>
void insertionSort(Iterator first, Iterator last) {
    // Sprawdzenie, czy lista do posortowania jest niepusta
    if (first == last) {
        return;
    }
    // Pêtla iteruj¹ca po elementach listy, pocz¹wszy od drugiego
    for (auto i = (first + 1); i != last; i++) {
        // Ustawienie wskaŸnika j na poprzedni element
        auto j = i - 1;
        // Dopóki wartoœæ nastêpnego elementu jest mniejsza od wartoœci aktualnego elementu
        while (*(j + 1) < *j) {
            // Zamiana miejscami wartoœci nastêpnego elementu z wartoœci¹ aktualnego elementu
            std::swap(*(j + 1), *j);
            // Przesuniêcie wskaŸnika j na poprzedni element
            if (j == first)
                break;
            j--;
        }
    }
}