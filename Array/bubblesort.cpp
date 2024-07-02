#include<iostream>
using namespace std;
void buffersort(int a[],int size)
{
	int r,i,t;
	for(r=1;r<=size-1;r++)
	{
		for(i=0;i<=size-1-r;i++)
		{
			if(a[i]>a[i+1])
			{
				t=a[i];
				a[i]=a[i+1];
				a[i+1]=a[i];
			}
		}
	}
}
void printArray(int a[], int size)
{
    for(int i = 0; i < size; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {5, 3, 8, 4, 2};
    int size = sizeof(arr) 
    
    cout << "Original array: ";
    printArray(arr, size);
    
    buffersort(arr, size);
    
    cout << "Sorted array: ";
    printArray(arr, size);
    
    return 0;
}
