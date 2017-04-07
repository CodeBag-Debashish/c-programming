#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int left1(int i)
{
         return 2*i+1;
}
//these are two helper functions
int right1(int i)
{
        return 2*i+2;
}

void swap(int x[],int i,int j)
{
        int temp = 0;
        temp = x[i];
        x[i] = x[j];
        x[j] = temp;

}



void max_heapify(int x[],int i,int n)
{
	int heap_size = n,largest = 0;
	int l = left1(i);
	int r = right1(i);
	
	if(l < heap_size && x[l] > x[i])
		largest = l;
	else
		largest = i;
	if(r < heap_size && x[r] > x[largest])
		largest = r;

	if(largest != i) {
		swap(x,i,largest);
		max_heapify(x,largest,n);  //this n here specifies the max limit that you can rearrange i.e. upto last tem if needed
	}


}

void build_max_heap(int x[],int n) {
	int heap_size = n;
	for(int i = (heap_size/2) - 1;i >= 0;i--) {
		max_heapify(x,i,n);
	}



}

void heap_sort(int x[],int n)
{
	build_max_heap(x,n);
	for(int i = n - 1;i >=1;i--)
	{
		swap(x,0,i);	       // swap top with last becoz top is the biggest after heapifying
		n = n-1;               //so that last term does not get effected
		max_heapify(x,0,n);    // arrange as max_heap the remaining part stating from top
	}
}

//int left1(int i) 
//{
//	 return 2*i;
//}
//these are two helper functions
//int right1(int i) 
//{ 
//	return 2*i+1;
//}


//void swap(int x[],int i,int j)
//{
//	int temp = 0;
//	temp = x[i];
//	x[i] = x[j];
//	x[j] = temp;
	
//}



int main()
{

	//ifstream fin;
	fstream fin("input.txt", std::ios_base::in);
	//fin.open("input.txt",ios::in);
	int *x = new int[80000];
	int i=0,a;
	while(cin >> a)       //read the file untill endline occurs
	{
		x[i] = a;
		i++;
	}

	cout << "\n Printing the input array\n ";
	
	for(int i = 0;i < 70000;i++)
        {
                cout << x[i] << endl;
        }
	//cout << endl;


	heap_sort(x,70000);
	
	cout << "\n Printing the heapsorted array\n";


	for(int i = 0;i < 70000;i++)
	{
		cout << x[i] << endl;
	}

	cout << endl;
	delete x;	
	return 0;
}

