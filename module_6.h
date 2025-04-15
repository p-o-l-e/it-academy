#pragma once

void reverseString(char*);
void reverseStringA(char*);
void requestAndReverse(const int& max = 12);
void printMatrix(const int& w = 3, const int& h = 3);
void sortVector(const int& size = 10, const int& min = 1, const int& max = 100);
void findMinMax(const int& size = 10);

// Utility
template <typename T>
void xorSwap(T&, T&);
const int countDigits(const int&);
const int randInRange(const int&, const int&) noexcept;