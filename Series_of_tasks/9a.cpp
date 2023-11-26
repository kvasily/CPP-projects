#include <iostream>

// 19. Write a function named ‘swap’ that accepts two integer pointers as arguments, and then swaps the two integers that the pointers point to. 
// Function to swap two integers pointed to by pointers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to set a negative integer to zero
void noNegatives(int* x) {
    if (*x < 0) {
        *x = 0;
    }
}

int main() {
    // 1. Create two integer variables named x and y
    int x, y;

    // 2. Create an int pointer named p1
    int* p1;

    // 3. Store the address of x in p1
    p1 = &x;

    // 4. Use p1 to set the value of x to 99
    *p1 = 99;

    // 5. Using cout and x, display the value of x
    std::cout << "Value of x: " << x << std::endl;

    // 6. Using cout and the pointer p1, display the value of x
    std::cout << "Value of x using pointer p1: " << *p1 << std::endl;

    // 7. Store the address of y into p1
    p1 = &y;

    // 8. Use p1 to set the value of y to -300
    *p1 = -300;

    // 9. Create two new variables: an int named temp, and an int pointer named p2
    int temp;
    int* p2;

    // 10. Use temp, p1, and p2 to swap the values in x and y
    temp = x;
    x = y;
    y = temp;

    // 11. Write a function with the following signature: void noNegatives(int *x). The function should accept the address of an int variable. If the value of this integer is negative then it should set it to zero.  Note: you should declare the noNegatives function BEFORE main, not inside of main.
    // 12. Call the function twice: once with the address of x as the argument, and once with the address of y
    noNegatives(&x);
    noNegatives(&y);

    // 13. Use p2 to display the values in x and y
    p2 = &x;
    std::cout << "Value of x using pointer p2: " << *p2 << std::endl;

    p2 = &y;
    std::cout << "Value of y using pointer p2: " << *p2 << std::endl;

    // 14. Create an int array with two elements. The array should be named ‘a’
    int a[2];

    // 15. Use p2 to initialize the first element of a with the value of x
    p2 = &x;
    a[0] = *p2;

    // 16. Use p2 to initialize the second element of a with the value of y
    p2 = &y;
    a[1] = *p2;

    // 17. Use p1, p2, and temp to swap the values in the two elements of array ‘a’
    p1 = &a[0];
    p2 = &a[1];
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    // 18. Display the values of the two elements
    std::cout << "Value of a[0]: " << a[0] << std::endl;
    std::cout << "Value of a[1]: " << a[1] << std::endl;

    // 20. Call your swap function with the addresses of x and y, then print their values
    swap(&x, &y);
    std::cout << "Value of x after swap: " << x << std::endl;
    std::cout << "Value of y after swap: " << y << std::endl;

    // 21. Call your swap function with the address of the two elements in array ‘a’, then print their values
    swap(&a[0], &a[1]);
    std::cout << "Value of a[0] after swap: " << a[0] << std::endl;
    std:: cout << "Value of a[1] after swap: " << a[1] << std::endl;

    return 0;
}
