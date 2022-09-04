#include <iostream>
using namespace std;

/*This function is for printing the array*/

void print_array(int arr[],int size)
{
    cout<<"Sorted array:=>"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<arr[i]<<" ";
    }
}

int partition(int arr[],int lower_index,int higher_index)
{
    int t;
    int pivot_element=arr[lower_index];
    int i=lower_index,j=higher_index;
    while(i<j)
    {
        while(arr[i]<=pivot_element)
        {
            i++;
        }
        while(arr[j]>pivot_element)
        {
            j--;
        }
        
        if(i<j)
        {
            t=arr[i];
            arr[i]=arr[j];    
            arr[j]=t;
        }

    }
    arr[lower_index]=arr[j];
    arr[j]=pivot_element;
    return j;
}

void quicksort(int arr[],int lower_index,int higher_index)
{
    if(lower_index<higher_index)
    {
        int pivot_element=partition(arr,lower_index,higher_index);
        quicksort(arr,lower_index,pivot_element);
        quicksort(arr,pivot_element+1,higher_index);
    }
}

int main()
{
    int size;
    int arr[]={1,4,5,3,2,7,9,8};
    size=sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    cout<<"-----QuickSort algorithm-----"<<endl;
    print_array(arr,size);
    return 0;
}