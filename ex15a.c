// I still don't completely understand pointers
// These are excercise I did to reinforce my understanding
// Hopefully with more practice I can get a hang of it

#include <stdio.h>

void swap(int *p1, int *p2);

// *nums is the same thing as nums[]
// This is because a C compiler will transform the type of the respective parameter to be a pointer
void array(int *nums);
void print_addr(int num);
int* new_integer();
void print_array(int *array, int length);

int main()
{
	int x = 10;
	int y = 20;

	swap(&x, &y);

	// Should print out x: 20, y: 10
	printf("x: %d, y: %d\n", x, y);

	int nums[] = {1, 2, 3, 4, 5};
	array(nums);


	// According to the C standard, arr[0] is actually syntactic shorthand for *(arr+0). This loop demonstrates this alternate notation.
	int i = 0;
	int count = sizeof(nums) / sizeof(int);
	for (i = 0; i < count; i++) {
		printf("%d\n", *(nums+i));
	}

	int num = 100;
	printf("%p\n", &num);
	print_addr(num);

	// printf("%p\n", new_interger());

	int array[] = {82, 23, 12, 48, 12};
	int length = sizeof(array) / sizeof(array[0]);
	print_array(array, length);

	return 0;
}

void swap(int *p1, int *p2)
{
	int temp = *p1;
	*p1 = *p2;
	*p2 = temp;
}


void array(int *nums)
{
	// This demonstrates the fact that arrays themselves are not passed to functions, but a pointer to the first element of the array is what is passed.
	printf("%d\n", *nums);
}

void print_addr(int num)
{
	printf("%p\n", &num);
}

// This is illegal in C.
// The local variables have a lifetime which extends only inside the block in which it is defined. 
// The moment the control goes outside the block in which the local variable is defined, the storage for the variable is no longer allocated (not guaranteed). 
// Therefore using the memory address of the variable outside the lifetime area of the variable will be undefined behavior.
// int* new_integer()
// {
// 	int x = 15;
// 	return &x;
// }

void print_array(int *array, int length)
{
	int i;
	for (i = 0; i < length; i++) {
		printf("%d\n", array[i]);
	}
}