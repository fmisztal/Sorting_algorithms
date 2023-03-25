#pragma once
#include <algorithm>
#include<iostream>
#include <vector>

template <typename Iterator>
void merge(Iterator first, Iterator mid, Iterator last) 
{
    // Inicjalizujemy pusty wektor, ktry bdzie przechowywa posortowane elementy
    std::vector <typename Iterator::value_type> v = {};

    // Tworzymy iteratory dla przedziaw lewej i prawej strony
    Iterator left = first;
    Iterator right = mid;

    while (left != mid && right != last) {
        if (*left <= *right) {
            v.push_back(*left);
            left++;
        }
        else {
            v.push_back(*right);
            right++;
        }
    }
    v.insert(v.end(), left, mid);
    v.insert(v.end(), right, last);

    // Przepisujemy wektor tymczasowy do wektora oryginalnego
    std::move(v.begin(), v.end(), first);
}

// Definicja szablonowej funkcji sortujcej metod merge sort
template <typename Iterator>
void mergeSort(Iterator first, Iterator last)
{
    // Obliczamy rodek przedziau
    auto mid = ((distance(first, last) / 2) + first);

    // Jeli przedzia skada si z jednego elementu, to przerywamy sortowanie
    if (distance(first, last) <= 1) {
        return;
    }

    // Sortujemy elementy z lewej i prawej strony przedziau
    mergeSort(first, mid);
    mergeSort(mid, last);

    // Wywo³anie funkcji ³¹cz¹cej elementy
    merge(first, mid, last);
}