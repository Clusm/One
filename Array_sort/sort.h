
#include<iostream>
#include<iomanip>
#include<time.h>

using namespace std;

void Print(int* p, int length);
void Bubble_sort(int* p, int length);
void Section_sort(int* p, int length);
void Insertion_sort(int* p, int length);
void Shell_sort(int* p, int length);
void Quick_sort(int* p, int start,int end);
void Merge(int* s,int start, int end,int mid);
void Merge_sort(int* s,int start, int end);
void Create_heap(int* p, int length);
void Heap_sort(int* p, int length);
void Count_sort(int* p, int length);