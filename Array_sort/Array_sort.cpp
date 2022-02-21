
#include"sort.h"

void Print(int* p, int length)
{
	for (int i = 0;i < length;i++)
	{
		cout << setw(3) << p[i];
	}
	cout<<endl;
	cout << endl;
}


void Bubble_sort(int* p, int length)
{
	int temp;
	for (int i = 0;i < length;i++)
	{
		for (int j = 0;j < length-1 - i;j++)
		{
			if (p[j] > p[j + 1])
			{
				temp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = temp;
			}
		}
	}
}

void Section_sort(int* p, int length)
{
	int i,j,Min;
	for ( i = 0;i < length;i++)
	{
		Min= i;
		for (j = i + 1;j < length;j++)
		{
			if (p[Min] > p[j])
			{
				Min = j;
			}
		}
		if (Min != i)
		{
			swap(p[i], p[Min]);
		}
	}
}

void Insertion_sort(int* p, int length)
{
	int temp, j;
	for (int i = 0;i < length;i++)
	{
		temp = p[i];                   //将第一个元素视为一个有序序列
		for (j = i;j > 0;j--)
		{
			if (p[j - 1] > temp)
			{
				p[j] = p[j - 1];
			}
			else
				break;
		}
		p[j] = temp;
	}
}

void Shell_sort(int* p, int length)
{
	for (int gap = length / 2;gap > 0;gap--)
	{
		int temp, k;
		for (int i = 0;i< length;i++)
		{
			for (int  j = gap;j < length;j++)
			{
				temp = p[j];
				k = j;
				while (k - gap >= 0 && p[k - gap] > temp)
				{
					p[k] = p[k - gap];
					k -= gap;
				}
				p[k] = temp;
			}
		}
	}

}

void Quick_sort(int* p, int start, int end)
{
	if (start >= end)
		return;
	int key, temp;
	int i = start, j = end;
	key = p[i];
	while (i != j)
	{
		while (p[j] >= key && i < j)
			j--;
		while (p[j] <= key && i < j)
			i++;
		if (i < j)
		{
			temp = p[i];
			p[i] = p[j];
			p[j] = temp;
		}
		p[start] = p[i];
		p[i] = key;
		Quick_sort(p, start, i - 1);
		Quick_sort(p, i + 1, end);
		return;
	}
}


void Merge(int test[], int start, int mid, int end)        /* 对子序列x[low~mid]和x[mid+1~high]进行归并操作 */
{
	int i, j, k;
	int m, n;
	int t;
	int y[10];                                /* 临时缓冲区 */
	i = start;                                /* 指向前一个子序列的起始位置 */
	j = mid + 1;                             /* 指向后一个子序列的起始位置 */
	for (k = start; i <= mid && j <= end; k++)            /* 逐个比较两个子序列中数据元素的大小 */
	{
		if (test[i] <= test[j])                         /* 将较小的数据元素放入缓冲区 */
			y[k] = test[i++];
		else
			y[k] = test[j++];
	}
	/* 如果前一个子序列中的数据元素已经比较完毕，则直接复制后一个子序列中的数据元素到缓冲区 */
	if (i <= mid)
	{
		for (m = i; m <= mid; m++)
		{
			y[k++] = test[m];
		}
	}
	/* 如果后一个子序列中的数据元素已经比较完毕，则直接复制前一个子序列中的数据元素到缓冲区 */
	if (j <= end)
	{
		for (n = j; n <= end; n++)
		{
			y[k++] = test[n];
		}
	}
	/* 将缓冲区中的数据元素复制回原序列中 */
	for (t = start; t <= end; t++)
	{
		test[t] = y[t];
	}
}
void Merge_sort(int test[], int start, int end)            /* 定义归并排序函数，递归方式 */
{
	int mid;
	if (start< end)
	{
		mid = (start + end) / 2;
		Merge_sort(test, start, mid);                 /* 递归调用，将子序列x[low~mid]归并为有序序列 */
		Merge_sort(test, mid + 1, end);                 /* 递归调用，将子序列x[mid+1~high]归并为有序序列 */
		Merge(test, start, mid, end);                /* 将子序列x[low~mid]和x[mid+1~high]进行归并 */
	}
}


void Create_heap(int* p, int length,int index)
{
	if (index > length)
		return;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int Max = index;
	if (left<length && p[left]>p[Max]) //左孩子大于父节点，记录下标
		Max = left;
	if (right<length && p[right]>p[Max])
		Max = right;
	if (Max != index)
	{
		swap(p[Max], p[index]);
		Create_heap(p, length, Max);
	}
}

void Heap_sort(int* p, int length)
{
	for (int i = length / 2 - 1;i >= 0; i--)//length / 2 - 1表示最后一个非叶子节点
	{
		Create_heap(p, length, i);
	}
	for (int i = length - 1;i >= 0;i--)
	{
		swap(p[0], p[i]);          //交换堆顶与堆尾，i--将元素固定在尾部
		Create_heap(p, i, 0);
	}
}

void Count_sort(int* p, int length)
{
	int Max = p[0];
	int Min = p[0];
	for (int i = 0;i < length-1;i++)
	{
		if (p[i] > Max)
			Max = p[i];
		if (p[i] < Min)
			Min = p[i];
	}
	int d = Max - Min;
	int* count = new int[d + 1];
	memset(count, 0, sizeof(int) * (d + 1));
	for (int i = 0;i < length;i++)
		count[p[i] - Min]++;
	int index = 0;
	for (int i = 0;i < d + 1;i++)
	{
		while (count[i] > 0)
		{
			p[index++] = i + Min;
			count[i]--;
		}
	}
	delete[] count;
}

