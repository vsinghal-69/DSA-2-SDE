/*

Given an int array in which every element is either 0 or 1. calculate it's corresponding decimal representation starting from  msb(from left-most bit)
 ex : n=4
      arr= {1, 1, 0, 1}
      
output : 13


*/


// function to calculate the decimal representation of a binary string starting from msb

int b2d(int arr[], int n)
{
	int no=0;
	for(int i=0; i<n; ++i)
	{
		no = (no << 1) | arr[i];
	}
	return no;
}