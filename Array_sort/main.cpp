#include"sort.h"

int main()
{
	int length = 10;
	int test[10] = { 5,2,1,0,7,4,9,8,6,3 };
	std::cout << "Ã°ÅİÅÅĞò" << endl;
	Print(test, length);
	Bubble_sort(test, length);
	Print(test, length);

	int test1[10] = { 5,2,1,0,7,4,9,8,6,3 };
	std::cout << "Ñ¡ÔñÅÅĞò" << endl;
	Print(test1, length);
	Section_sort(test1, length);
	Print(test1, length);

	int test2[10] = { 5,2,1,0,7,4,9,8,6,3 };
	std::cout << "²åÈëÅÅĞò" << endl;
	Print(test2, length);
    Insertion_sort(test2, length);
	Print(test2, length);

	int test3[10] = { 5,2,1,0,7,4,9,8,6,3 };
	std::cout << "Ï£¶ûÅÅĞò" << endl;
	Print(test3, length);
	Shell_sort(test3, length);
	Print(test3, length);

	int test4[10] = { 5,2,1,0,7,4,9,8,6,3 };
	std::cout << "¿ìËÙÅÅĞò" << endl;
	Print(test4, length);
	Quick_sort(test4,0, length-1);
	Print(test4, length);

	int test5[10] = {5,2,1,0,7,4,9,8,6,3};
	std::cout << "¹é²¢ÅÅĞò" << endl;
	Print(test5, length);
	int re[11];
	Merge_sort(test5,0,length-1);
	Print(test5, length);

	int test6[10] = { 5,2,1,0,7,4,9,8,6,3 };
	std::cout << "¶ÑÅÅĞò" << endl;
	Print(test6, length);
	Heap_sort(test6, length);
	Print(test6, length);

	int test7[10] = { 5,2,1,0,7,4,9,8,6,3 };
	std::cout << "¼ÆÊıÅÅĞò" << endl;
	Print(test7, length);
	Count_sort(test7, length);
	Print(test7, length);
}