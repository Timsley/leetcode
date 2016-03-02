#include <stdio.h>
#include <string.h>
#include "two_pointers.h"



/*
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0]

*/
void moveZeroes(int* nums, int numsSize) 
{
    int *p, *q;
    p = nums;
    q = nums;
    
    while(q<nums+numsSize)
    {
        if(0 == *p)   
        {
            if(0 == *q)
                q++;
            else
            {
                *p = *q;
                *q = 0;
                p++;
                q++;
            }
        }
        else
        {
            p++;
            q++;
        }
    }
}


void two_pointers_print(int *array, int len)
{
    int i = 0;
    
    for(i=0; i<len; i++)
    {
        printf("%d     ", array[i]);
    }
    printf("\n");
}

void two_pointers_main_test(void)
{
    int nums[] = {0, 1, 0, 3, 12};
    int len = sizeof(nums)/sizeof(nums[0]);

    moveZeroes(nums, len);

    two_pointers_print(nums, len);
}

