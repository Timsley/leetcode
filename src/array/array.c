#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>



void printArray(int * array, int num)
{
    int i = 0;

    for(i=0; i<num; i++)
    {
        printf("%d  ", array[i]);
    }
    printf("\n");
}

void printDoubleArray(int **array, int row, int col)
{
    int i, j;
    
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            //printf("array[%d][%d]=%d   ", i, j, array[i*col + j]);
            printf("array[%d][%d]=%2d   ", i, j, array[i][j]);
        }
        printf("\n");
    }
    printf("****************\n");
}

/***************************************************************************************
*****                             217. Contains Duplicate
*****       Given an array of integers, find if the array contains any duplicates. Your function should return true 
*****       if any value appears at least twice in the array, and it should return false if every element is distinct.
****************************************************************************************/
bool containsDuplicate(int* nums, int numsSize) 
{
    int i=0, j=0;
    bool flag = false;
    
    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[i] == nums[j])
                flag = true;
        }
    }
    return flag;
}

/***************************************************************************************
*****                             66. Plus One
*****       Given a non-negative number represented as an array of digits, plus one to the number.
*****       
*****       The digits are stored such that the most significant digit is at the head of the list.
****************************************************************************************/
int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int i = 0, j=0;
    int *ret;

    for(i=digitsSize-1; i>=0; i--)
        if(digits[i] != 9)
            break;

    if(i == -1)
    {
        ret = (int *)malloc(sizeof(int)*(digitsSize+1));
        memset(ret, 0, sizeof(int)*(digitsSize+1));
        ret[0] = 1;
        *returnSize = digitsSize+1;
    }
    else
    {
        for(j=digitsSize-1; j>i; j--)
           digits[j] = 0;  
        
        digits[i]++;
        *returnSize = digitsSize;
        ret = digits;
    }

    return ret;
}

/***************************************************************************************
*****                             66. Plus One
*****       Given a non-negative number represented as an array of digits, plus one to the number.
*****       
*****       The digits are stored such that the most significant digit is at the head of the list.
****************************************************************************************/
int* plusOne2(int* digits, int digitsSize, int* returnSize) 
{
    int i = 0;
    
    if(digits[digitsSize-1] != 9)
    {
        digits[digitsSize-1]++;
    }
    else
    {
        for(i=digitsSize-1; i>=0; i--)
        {
            if(digits[i] == 9)
            {
                digits[i] = 0;
            }
            else
            {
                digits[i]++;
                break;
            }
        }
    }

    if(digits[0] == 0)
        *returnSize = digitsSize+1;  
   else
   {
        *returnSize = digitsSize;
        return digits;
   }
    int *array = (int *)malloc(sizeof(int)*(*returnSize));

    for(i=*returnSize-1; i>=1; i--)
        array[i] = digits[i-1];

    array[0] = 1;   

    return array;
}

/***************************************************************************************
*****                             189. Rotate Array
*****       Rotate an array of n elements to the right by k steps.
*****       
*****       For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
*****       
*****       Note:
*****       Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem
****************************************************************************************/
void rotate(int* nums, int numsSize, int k)
{
    int i=0;
    int *array = (int *)malloc(sizeof(int)*numsSize);

    for(i=0; i<numsSize; i++)
    {
        array[(i+k)%numsSize] = nums[i];
    }
    
    for(i=0; i<numsSize; i++)
        nums[i] = array[i];

    free(array);
}

/***************************************************************************************
*****                             27. Remove Element
*****       Given an array and a value, remove all instances of that value in place and return the new length.
*****       
*****       Do not allocate extra space for another array, you must do this in place with constant memory.
*****       
*****       The order of elements can be changed. It doesn't matter what you leave beyond the new length.
*****       
*****       Example:
*****       Given input array nums = [3,2,2,3], val = 3
*****       
*****       Your function should return length = 2, with the first two elements of nums being 2.
****************************************************************************************/
int removeElement(int* nums, int numsSize, int val)
{    
    int i = 0, j = 0;
    
    int *array = (int *)malloc(sizeof(int)*numsSize);

    for(i=0; i<numsSize; i++)
    {
        if(val != nums[i])
        {
            array[j] = nums[i];
            j++;
        }
    }

    for(i=0; i<j; i++)
        nums[i] = array[i];

    free(array);
    
    return j;
}

/***************************************************************************************
*****                             26. Remove Duplicates from Sorted Array
*****       Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
*****       
*****       Do not allocate extra space for another array, you must do this in place with constant memory.
*****       
*****       For example,
*****       Given input array nums = [1,1,2],
*****       
*****       Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. 
*****       It doesn't matter what you leave beyond the new length.
****************************************************************************************/
int removeDuplicates(int* nums, int numsSize)
{
    int i = 0;
    int count = 0;
    
    for(i=0; i<numsSize-1; i++)
    {
        if(nums[i] != nums[i+1])
        {
            count++;
            nums[count] = nums[i+1];
        }
    }

    if(0 == numsSize)
        return count;
    else
        return count+1;
}

/***************************************************************************************
*****                             228. Summary Ranges
*****       Given a sorted integer array without duplicates, return the summary of its ranges.
*****       
*****       For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
****************************************************************************************/
char** summaryRanges(int* nums, int numsSize, int* returnSize) 
{
    int i = 0;
    static char *array[20];
    int begin = nums[0], end=0;
    int j=0;

    if(numsSize == 0)
    {
        *returnSize = 0;
        return NULL;
     }
     
    for(i=0; i<20; i++)
    {
        array[i] = (char *)malloc(sizeof(char)*10);
        memset(array[i], 0, sizeof(char)*10);
    }
    
    for(i=0; i<numsSize-1; i++)
    {
        if( nums[i] != (nums[i+1] -1) )
        {
            end = nums[i];
            
            if(begin == end)
                sprintf(array[j++], "%d", begin);
            else
                sprintf(array[j++], "%d->%d", begin, end);
            
            begin = nums[i+1];
        }
    }
    
    if(begin == nums[i])
        sprintf(array[j++], "%d", begin);
    else
        sprintf(array[j++], "%d->%d", begin, nums[i]);
    
    *returnSize = j;

    return array;
}

/***************************************************************************************
*****                             169. Majority Element 
*****       Given an array of size n, find the majority element. The majority element is the element that appears more than ? n/2 ? times.
*****       
*****       You may assume that the array is non-empty and the majority element always exist in the array.
****************************************************************************************/
int majorityElement(int* nums, int numsSize) 
{
    int i, num;
    int count = 0;

    for(i=0; i<numsSize; i++)
    {
        if(count == 0)
        {
            num = nums[i];
            count++;
        }
        else 
        {
            if(num == nums[i])
                count++;
            else
                count--;
        }
    }

    return num;
}

/***************************************************************************************
*****                             88. Merge Sorted Array
*****       Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.
*****       
*****       Note:
*****       You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional 
*****       elements from nums2. The number of elements initialized in nums1 and nums2 are m and n respectively.
****************************************************************************************/
void merge(int* nums1, int m, int* nums2, int n) 
{
    while(m>0 && n>0)
    {
        if(nums1[m-1] > nums2[n-1])
        {
            nums1[m+n-1] = nums1[m-1];
            m--;
        }
        else
        {
            nums1[m+n-1] = nums2[n-1];
            n--;
        }
    }

    while(n>0)
    {
        nums1[m+n-1] = nums2[n-1];
        n--;
    }

    while(m>0)
    {
        nums1[m+n-1] = nums1[m-1];
        m--;
    }
}

/***************************************************************************************
*****                             73. Set Matrix Zeroes
*****       Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
****************************************************************************************/
void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int i=0, j=0;

    bool row[matrixRowSize];
    bool col[matrixColSize];    

    for(i=0; i<matrixRowSize; i++) 
        row[i] = false;
    
    for(j=0; j<matrixColSize; j++) 
        col[j] = false;

    for(i=0; i<matrixRowSize; i++)
    {
        for(j=0; j<matrixColSize; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = true;
                col[j]= true;
            }
        }
    }

    for(i=0; i<matrixRowSize; i++)
    {
        if(row[i] == true)
        {
            for(j=0; j <matrixColSize; j++)
                matrix[i][j] = 0;
        }            
    }

    for(j=0; j<matrixColSize; j++)
    {
        if(col[j] == true)
        {
            for(i=0; i <matrixRowSize; i++)
                matrix[i][j] = 0; 
        }            
    }
}

/***************************************************************************************
*****                             48. Rotate Image
*****       You are given an n x n 2D matrix representing an image.
*****       
*****       Rotate the image by 90 degrees (clockwise).
*****       
*****       Follow up:
*****       Could you do this in-place?
****************************************************************************************/
void rotateImage(int** matrix, int matrixRowSize, int matrixColSize)
{
    int i, j;
    int temp = 0;
#if 0
    for (i = 0; i < matrixRowSize; i++)
    {
        for (j = i+1; j < matrixColSize; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
#endif     
    for (i = 0; i < matrixRowSize; i++)
    {
        for (j = 0; j < matrixColSize/2; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[i][matrixColSize-j-1];
            matrix[i][matrixColSize-j-1] = temp;
        }
    }

    for (i = 0; i < matrixRowSize; i++)
    {
        for (j=0; j<matrixColSize-i-1; j++)
        {
            temp = matrix[i][j];
            matrix[i][j] = matrix[matrixColSize-1-j][matrixRowSize-1-i];
            matrix[matrixColSize-1-j][matrixRowSize-1-i] = temp;
        }
    }
}

/***************************************************************************************
*****                             219. Contains Duplicate II 
*****       Given an array of integers and an integer k, find out whether there are two distinct indices i and j 
*****       in the array such that nums[i] = nums[j] and the difference between i and j is at most k.
****************************************************************************************/
bool containsNearbyDuplicate(int* nums, int numsSize, int k) 
{
    int i=0, j=0;
    bool flag = false;
    
    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if((nums[i] == nums[j]) && ((j-i)<=k))
                flag = true;
        }
    }
    return flag;
}

/***************************************************************************************
*****                             35. Search Insert Position
*****       Given a sorted array and a target value, return the index if the target is found. If not, 
*****       return the index where it would be if it were inserted in order.
*****       
*****       You may assume no duplicates in the array.
*****       
*****       Here are few examples.
*****       [1,3,5,6], 5 ¡ú 2
*****       [1,3,5,6], 2  ¡ú 1
*****       [1,3,5,6], 7 ¡ú  4
*****       [1,3,5,6], 0  ¡ú 0
****************************************************************************************/
int searchInsert(int* nums, int numsSize, int target) 
{
    int i = 0;
    
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] >= target)
            return i;
    }

    return i;
}

/***************************************************************************************
*****                             34. Search for a Range 
*****       Given a sorted array of integers, find the starting and ending position of a given target value.
*****       
*****       Your algorithm's runtime complexity must be in the order of O(log n).
*****       
*****       If the target is not found in the array, return [-1, -1].
*****       
*****       For example,
*****       Given [5, 7, 7, 8, 8, 10] and target value 8,
*****       return [3, 4].
****************************************************************************************/
int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int i=0;
    int start=0, end=0;
    bool startFlag = false;
    bool endFlag = false;    
    
    int * array = (int *)malloc(sizeof(int *)*2);

    for(i=0; i<numsSize; i++)
    {
        if(target == nums[i])
        {
            start = i;
            startFlag = true;
            break;
        }
    }

    for(i=numsSize-1; i>=0; i--)
    {
        if(target == nums[i])
        {
            end = i;
            endFlag = true;
            break;
        }
    }

    *returnSize = 2;

    if((true ==startFlag) && (true ==endFlag))
    {
        array[0] = start;
        array[1] = end;    
    }
    else
    {
        array[0] = -1;
        array[1] = -1; 
    }
    
    return array;
}

/***************************************************************************************
*****                             33. Search in Rotated Sorted Array
*****       Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*****       
*****       (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*****       
*****       You are given a target value to search. If found in the array return its index, otherwise return -1.
*****       
*****       You may assume no duplicate exists in the array.
****************************************************************************************/
int search(int* nums, int numsSize, int target) 
{
    int l = 0;
    int r = numsSize-1;

    while(l<=r)
    {
        int mid = l + (r-l)/2;
        if(target == nums[mid])
            return mid;

        if(nums[l]<=nums[mid])//it is sorted in [l,mid], "=" contains an edge case:3, 1
        {
            if(nums[mid] > target && nums[l] <= target)  
                    r = mid-1;  
                else   
                    l = mid+1;
        }
        else//[mid,r] must be sorted, if [l,mid] not sorted  
        {  
            if(nums[mid] < target && nums[r] >= target)  
                l = mid+1;  
            else   
                r = mid-1;  
        }
        
    }
    return -1;
#if 0
    int i;
    for(i=0; i<numsSize; i++)
    {
        if(target == nums[i])
            return i;
    }
    return -1;
#endif
}

/***************************************************************************************
*****                             81. Search in Rotated Sorted Array II
*****       Follow up for "Search in Rotated Sorted Array":
*****       What if duplicates are allowed?
*****       
*****       Would this affect the run-time complexity? How and why?
*****       
*****       Write a function to determine if a given target is in the array.
****************************************************************************************/
bool search2(int* nums, int numsSize, int target) 
{
    int start=0, end=numsSize-1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(nums[mid] == target)
            return true;
        if(nums[mid]>nums[start])
        {
            if((target>=nums[start]) && (target<nums[mid]))
                end = mid-1;
            else
                start = mid+1;
        }
        else if(nums[mid]<nums[start])
        {
            if((target>nums[mid]) && (target<=nums[end]))
                start = mid+1;
            else
                end = mid-1;
        }
        else
            start++;
    }
    return false;
}

/***************************************************************************************
*****                             283. Move Zeroes
*****       Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
*****       
*****       For example, given nums = [0, 1, 0, 3, 12], after calling your function, nums should be [1, 3, 12, 0, 0].
*****       
*****       Note:
*****       You must do this in-place without making a copy of the array.
*****       Minimize the total number of operations.
****************************************************************************************/
void moveZeroes(int* nums, int numsSize) 
{
    int i=0, j=0;
    
    while(j<numsSize) 
    {  
        if(nums[j]!=0) 
        {  
            if(j!=i) 
            {   
                nums[i++] = nums[j];  
                nums[j] = 0;  
            } 
            else 
            {  
                ++i;  
            }  
        }   
        ++j;  
    } 
}

/***************************************************************************************
*****                             74. Search a 2D Matrix
*****       Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
*****       
*****       Integers in each row are sorted from left to right.
*****       The first integer of each row is greater than the last integer of the previous row.
*****       For example,
*****       
*****       Consider the following matrix:
*****       
*****       [
*****         [1,   3,  5,  7],
*****         [10, 11, 16, 20],
*****         [23, 30, 34, 50]
*****       ]
*****       Given target = 3, return true.
****************************************************************************************/
bool searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int row=0, col=matrixColSize-1;

    while(row<matrixRowSize && col>=0)
    {
        if(target == matrix[row][col])
            return true;
        else if(target > matrix[row][col])
            row++;
        else
            col--;
    }

    return false;
}

/***************************************************************************************
*****                             118. Pascal's Triangle
*****       Given numRows, generate the first numRows of Pascal's triangle.
*****       
*****       For example, given numRows = 5,
*****       Return
*****       
*****       [
*****            [1],
*****           [1,1],
*****          [1,2,1],
*****         [1,3,3,1],
*****        [1,4,6,4,1]
*****       ]
*****
*****       Return an array of arrays.
*****       The sizes of the arrays are returned as *columnSizes array.
*****       Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
****************************************************************************************/
int** generate(int numRows, int** columnSizes) 
{
    int i=0;    
    int j=0;

    if(numRows == 0)
        return 0;

    int ** returnArray = (int **)malloc(sizeof(int *) * numRows);
    *columnSizes = (int *)malloc(sizeof(int)*numRows);

    for(i=0; i<numRows; i++)
    {
        (*columnSizes)[i] = i+1;
        
        returnArray[i] = (int *)malloc(sizeof(int) * (i+1));

        for(j=0; j<i+1; j++)
        {
            if( (0 == j)  || (i == j) )
                returnArray[i][j] = 1;
            else
                returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
        }
        
    }

    return returnArray;
}


/***************************************************************************************
*****                             119. Pascal's Triangle II
*****       Given an index k, return the kth row of the Pascal's triangle.
*****       
*****       For example, given k = 3,
*****       Return [1,3,3,1].
*****       
*****       Return an array of size *returnSize.
*****       Note: The returned array must be malloced, assume caller calls free().
****************************************************************************************/
int* getRow(int rowIndex, int* returnSize) 
{
    int i=0, j=0;    

    int ** returnArray = (int **)malloc(sizeof(int *) * (rowIndex+1));

    for(i=0; i<rowIndex+1; i++)
    {
        returnArray[i] = (int *)malloc(sizeof(int) * (i+1));

        for(j=0; j<i+1; j++)
        {
            if( (0 == j)  || (i == j) )
                returnArray[i][j] = 1;
            else
                returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
        }        
    }

    *returnSize = rowIndex + 1;
    return returnArray[rowIndex];    
}

/***************************************************************************************
*****                             238. Product of Array Except Self 
*****       Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal 
*****       to the product of all the elements of nums except nums[i].
*****       
*****       Solve it without division and in O(n).
*****       
*****       For example, given [1,2,3,4], return [24,12,8,6].
*****       
*****       Follow up:
*****       Could you solve it with constant space complexity? (Note: The output array does not count as extra space for 
*****       the purpose of space complexity analysis.)
****************************************************************************************/
int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int i=0, temp=1;
    
    *returnSize = numsSize;
    
    int *result = (int *)malloc(sizeof(int)*numsSize);    
    result[0] = 1;
    
    // remember the  product from left to right, such as : result[0]=1, 
    // result[1]=1*result[0]=1, result[2]=2*result[1]=2, result[3]=3*result[2]=6
    for(i=1; i<numsSize; i++)                   
    {
        result[i] = nums[i-1] * result[i-1];
    }

    // The result[i] is equal to sum of the left[i] and right[i], and left[i] mean the sum of product from left to right,
    // and right[i] mean the sum of product from right to left
    for(i=numsSize-1; i>=0; i--) 
    {
        result[i] *= temp;
        temp *= nums[i];
    }

    return result;
}

/***************************************************************************************
*****                             11. Container With Most Water 
*****       Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). 
*****       n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, 
*****       which together with x-axis forms a container, such that the container contains the most water.
*****       
*****       Note: You may not slant the container.
****************************************************************************************/
int maxArea(int* height, int heightSize) 
{
    
}



/***************************************************************************************
*****                             1. Two Sum 
*****       Given an array of integers, return indices of the two numbers such that they add up to a specific target.
*****       
*****       You may assume that each input would have exactly one solution.
*****       
*****       Example:
*****       Given nums = [2, 7, 11, 15], target = 9,
*****       
*****       Because nums[0] + nums[1] = 2 + 7 = 9,
*****       return [0, 1].
****************************************************************************************/
int* twoSum(int* nums, int numsSize, int target)
{
    int i=0, j=0;
    int * ret = (int *)malloc(2 * sizeof(int));
    memset(ret, 0, (2 * sizeof(int)));

    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if( (nums[i]+nums[j]) == target)
            {
                ret[0] = i;
                ret[1] = j;

                return ret;
            }
        }
    }

    return NULL;
}

/***************************************************************************************
*****                             448. Find All Numbers Disappeared in an Array
*****       Given an array of integers where 1 = a[i] = n (n = size of array), some elements appear twice and others appear once.
*****       
*****       Find all the elements of [1, n] inclusive that do not appear in this array.
*****       
*****       Could you do it without extra space and in O(n) runtime? You may assume the returned list does not count as extra space.
*****       
*****       Example:
*****       Input:
*****       [4,3,2,7,8,2,3,1]
*****       
*****       Output:
*****       [5,6]
****************************************************************************************/
int* findDisappearedNumbers(int* nums, int numsSize, int* returnSize) 
{
    int * ret = (int *)malloc(sizeof(int));
    int i=0, j=0, index=0;

    for(i=0; i<numsSize; i++)
    {
        index = abs(nums[i]) - 1;
        if(nums[index] > 0)
            nums[index] = -nums[index];
    }

    for(i=0; i<numsSize; i++)
    {
        if(nums[i] > 0)
        {
            ret[j++] = i + 1;
            ret = (int *)realloc(ret, sizeof(int));
        }
    }
    
    *returnSize = j;

    return ret;
}


/***************************************************************************************
*****                             167. Two Sum II - Input array is sorted
*****       Given an array of integers that is already sorted in ascending order, find two numbers 
*****       such that they add up to a specific target number.
*****       
*****       The function twoSum should return indices of the two numbers such that they add up to the target, 
*****       where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
*****       
*****       You may assume that each input would have exactly one solution.
*****       
*****       Input: numbers={2, 7, 11, 15}, target=9
*****       Output: index1=1, index2=2
****************************************************************************************/
int* two_Sum(int* numbers, int numbersSize, int target, int* returnSize) 
{
    int * ret = (int *)malloc(sizeof(int));
    int i=0;
    int *p, *q;

    p = &numbers[0];
    q = &numbers[numbersSize-1];

    while(p != q)
    {
        if( (*p + *q) == target )
        {
            ret = (int *)realloc(ret, sizeof(int));
            ret[0] = (p-&numbers[0]) + 1;
            ret[1] = (q-&numbers[0]) + 1;
            *returnSize = 2;

            return ret;
        }
        else if( (*p + *q) > target )
            q = q -1;
        else if( (*p + *q) < target )
            p = p + 1;
    }
    
    *returnSize = 0;

    return NULL;
}

/***************************************************************************************
*****                             162. Find Peak Element
*****       A peak element is an element that is greater than its neighbors.
*****       
*****       Given an input array where num[i] ¡Ù num[i+1], find a peak element and return its index.
*****       
*****       The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
*****       
*****       You may imagine that num[-1] = num[n] = -¡Þ.
*****       
*****       For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
****************************************************************************************/
int findPeakElement(int* nums, int numsSize)
{
    int i=0;

    while((i+1)< numsSize)
    {
        if(nums[i] > nums[i+1])
            return i;
        i++;
    }

    return i;
}

/***************************************************************************************
*****                             153. Find Minimum in Rotated Sorted Array
*****       Suppose a sorted array is rotated at some pivot unknown to you beforehand.
*****       
*****       (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
*****       
*****       Find the minimum element.
*****       
*****       You may assume no duplicate exists in the array.
****************************************************************************************/
int findMin(int* nums, int numsSize) 
{
    int i=0;
    
    for(i=0; i<numsSize; i++)
    {
        if(0 == i)
        {
            if( (nums[0]<nums[1]) && (nums[0]<nums[numsSize-1]))    
                return nums[0];
        }
        else if((numsSize-1) == i)
        {
            if( (nums[numsSize-1]<nums[0]) && (nums[numsSize-1]<nums[numsSize-2]))    
                return nums[numsSize-1];    
        }
        else if( (nums[i]<nums[i-1]) && (nums[i]<nums[i+1])) 
            return nums[i];
    }
    
    return 1;
}

#if 0
/***************************************************************************************
*****                             229. Majority Element II
*****       Given an integer array of size n, find all elements that appear more than [n/3] times. 
*****       The algorithm should run in linear time and in O(1) space
****************************************************************************************/
int* majorityElement2(int* nums, int numsSize, int* returnSize) 
{
    int * ret = (int *)malloc(sizeof(int));
    int i=0, j=0, k=0;
    int count = 1;

    for(i=0; i<numsSize; i++)
    {
        for(j=i; j<numsSize; j++)
        {
            printf("nums[i]:%d      nums[j]:%d\n", nums[i], nums[j]);
            if(0 == (nums[i]-nums[j]))
            {
                printf("count=%d        numsSize/3:%d\n", count, numsSize/3);
                if(++count > (numsSize/3))
                {
                    ret[k++] = nums[i];
                    ret = (int *)realloc(ret, sizeof(int));
                    count = 0;
                    break;
                }
            }
        }
    }

    *returnSize = k;

    return ret;
}
#endif


/***************************************************************************************
*****                             442. Find All Duplicates in an Array
*****       Given an array of integers, 1 = a[i] = n (n = size of array), some elements appear twice and others appear once.
*****       
*****       Find all the elements that appear twice in this array.
*****       
*****       Could you do it without extra space and in O(n) runtime?
*****       
*****       Example:
*****       Input:
*****       [4,3,2,7,8,2,3,1]
*****       
*****       Output:
*****       [2,3]
****************************************************************************************/
int* findDuplicates(int* nums, int numsSize, int* returnSize) 
{
    int * ret = (int *)malloc(sizeof(int));
    int i=0, j=0, index=0;

    for(i=0; i<numsSize; i++)
    {
        index = abs(nums[i]) - 1;
        
        printf("nums[%d]:%2d     index:%2d        nums[index-1]:%2d\n", i, nums[i], index, nums[index]);
        if(nums[index] < 0)
        {
            ret[ j++] = abs(nums[i]);           
            ret = (int *)realloc(ret, (j+1)*sizeof(int));

            *returnSize = j;
        }
        else
            nums[index] = -nums[index];
    }
    
    return ret;
}

/***************************************************************************************
*****                             80. Remove Duplicates from Sorted Array II
*****       Follow up for "Remove Duplicates":
*****       What if duplicates are allowed at most twice?
*****       
*****       For example,
*****       Given sorted array nums = [1,1,1,2,2,3],
*****       
*****       Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. 
*****       It doesn't matter what you leave beyond the new length.
****************************************************************************************/
int removeDuplicates2(int* nums, int numsSize) 
{
    int i=0, count=0;

    for(i=0; i<numsSize; i++)
    {
        if(count<2 || nums[i]>nums[count-2])
            nums[count++] = nums[i];
    }

    return count;
}

/***************************************************************************************
*****                             75. Sort Colors
*****       Given an array with n objects colored red, white or blue, sort them so that objects of 
*****       the same color are adjacent, with the colors in the order red, white and blue.
*****       
*****       Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
*****       
*****       Note:
*****       You are not suppose to use the library's sort function for this problem.
****************************************************************************************/
void sortColors(int* nums, int numsSize) 
{
    int i=0, zero=0, second=numsSize-1;
    int temp=-1;

    for(i=0; i<=second; i++)
    {
        while( (2 == nums[i]) && (i < second) )
        {
            temp = nums[i];
            nums[i] = nums[second];
            nums[second] = temp;
            second--;
        }
        
        while( (0 == nums[i]) && (i > zero) )
        {
            temp = nums[i];
            nums[i] = nums[zero];
            nums[zero] = temp;
            zero++;
        }
    }
}

/***************************************************************************************
*****                             54. Spiral Matrix
*****       Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
*****       
*****       For example,
*****       Given the following matrix:
*****       
*****       [
*****        [ 1, 2, 3 ],
*****        [ 4, 5, 6 ],
*****        [ 7, 8, 9 ]
*****       ]
*****       You should return [1,2,3,6,9,8,7,4,5].
****************************************************************************************/
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int * ret = (int *)malloc(matrixRowSize*matrixColSize*sizeof(int));
    int k=0;

    int rowBegin=0, rowEnd=matrixRowSize-1;
    int colBegin=0, colEnd=matrixColSize-1;
    int i=0;    

    while((rowBegin<=rowEnd) && (colBegin<=colEnd))
    {
        for(i=colBegin; i<=colEnd; i++)
            ret[k++] = matrix[rowBegin][i];
        rowBegin++;

        for(i=rowBegin; i<=rowEnd; i++)
            ret[k++] = matrix[i][colEnd];
        colEnd--;

        if(rowBegin<=rowEnd)
        {
            for(i=colEnd; i>=colBegin; i--)
                ret[k++] = matrix[rowEnd][i];
        }
        rowEnd--;

        if(colBegin<=colEnd)
        {
            for(i=rowEnd; i>=rowBegin; i--)        
                ret[k++] = matrix[i][colBegin];
        }
        colBegin++;
    }

    return ret;
}

/***************************************************************************************
*****                             59. Spiral Matrix II
*****       Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
*****       
*****       For example,
*****       Given n = 3,
*****       
*****       You should return the following matrix:
*****       [
*****        [ 1, 2, 3 ],
*****        [ 8, 9, 4 ],
*****        [ 7, 6, 5 ]
*****       ]
****************************************************************************************/
int** generateMatrix(int n) 
{
    int i=0, num=1;
    int rowBegin=0, rowEnd= n-1;
    int colBegin=0, colEnd=n-1;
    
    int **matrix= (int **)malloc(n*sizeof(int *));
    for(i=0;i<n;i++)
    {
        matrix[i]=(int *)malloc(n*sizeof(int));
        memset(matrix[i], 0, sizeof(int)*n);
    }

    while(rowBegin<=rowEnd && colBegin<=colEnd)
    {
        for(i=colBegin; i<=colEnd; i++)
        {
            matrix[rowBegin][i] = num++;
            //printf("111 matrix[%d][%d] : %d\n", rowBegin, i, matrix[rowBegin][i]);
        }
        rowBegin++;

        for(i=rowBegin; i<=rowEnd; i++)
        {
            matrix[i][colEnd] = num++;
            //printf("222 matrix[%d][%d] : %d\n", i, colEnd, matrix[i][colEnd]);
        }
        colEnd--;

        if(rowBegin<=rowEnd)
        {
            for(i=colEnd; i>=colBegin; i--)
            {
                matrix[rowEnd][i] = num++;
                //printf("333 matrix[%d][%d] : %d\n", rowEnd, i, matrix[rowEnd][i]);
            }
        }
        rowEnd--;

        if(colBegin<=colEnd)
        {
            for(i=rowEnd; i>=rowBegin; i--)
            {
                matrix[i][colBegin] = num++;
                //printf("444 matrix[%d][%d] : %d\n", i, colBegin, matrix[i][colBegin]);
            }
        }
        colBegin++;
    }

    return matrix;
}

/***************************************************************************************
*****                             414. Third Maximum Number
*****       Given a non-empty array of integers, return the third maximum number in this array. 
*****       If it does not exist, return the maximum number. The time complexity must be in O(n).
*****       
*****       Example 1:
*****       Input: [3, 2, 1]
*****       
*****       Output: 1
*****       
*****       Explanation: The third maximum is 1.
*****       Example 2:
*****       Input: [1, 2]
*****       
*****       Output: 2
*****       
*****       Explanation: The third maximum does not exist, so the maximum (2) is returned instead.
*****       Example 3:
*****       Input: [2, 2, 3, 1]
*****       
*****       Output: 1
*****       
*****       Explanation: Note that the third maximum here means the third maximum distinct number.
*****       Both numbers with value 2 are both considered as second maximum.
****************************************************************************************/
int thirdMax(int* nums, int numsSize) 
{
    int i=0, count=0;
    long min, mid, max;
    min=mid=max=LONG_MIN;

    for(i=0; i<numsSize; i++)
    {        
        /* ignore the same value */
        if(nums[i]==max || nums[i]==mid)
            continue;
        
        if(nums[i] > max)
        {
            min = mid;
            mid = max;
            max = nums[i];
            count++;
        }
        else if(nums[i] > mid)
        {
            min = mid;
            mid = nums[i];
            count++;
        }
        else if(nums[i] >= min)
        {
            min = nums[i];
            count++;
        }            
    }

    if(count >= 3)
        return min;
    else 
        return max; 
}


#define ROW     6
#define COL      6

void array_main_test(void)
{
    int array[] = { 1,2,-2147483648LL}; 
    int len = sizeof(array)/sizeof(array[0]);
    int ret = 0;

    ret = thirdMax(array, len);
    printf("ret : %d\n", ret);
#if 0 // test case for 59. Spiral Matrix II    
    //printDoubleArray(generateMatrix(ROW), ROW, COL);
#endif
#if 0       // test case for 54. Spiral Matrix
    int doubleArray[ROW][COL] = {
                                    //{1,2,3,4},
                                    //{5,6,7,8},
                                    //{9,10,11,12},
                                    //{13,14,15,16}
                                        {1,2,3,4,5,6,7,8, 9,10},
                                }; 
    
    int **matrix =  (int **)malloc(sizeof(int *)*ROW);
    
    int i;
    for(i=0; i<ROW; i++)
        matrix[i] = doubleArray[i];

    int * result;

    result = spiralOrder(matrix, ROW, COL);
    //printDoubleArray(matrix, ROW, COL);
    printArray(result, ROW*COL);
#endif    

#if 0    
    int array[] = {0,1,0}; 
    int len = sizeof(array)/sizeof(array[0]);
    int size = 0;   

    sortColors(array, len);

    printArray(array, len);
#endif

#if 0
    size = findPeakElement(array, len);
    printf("ret %d\n", size);
#endif    
#if 0
    two_Sum(array, len, 6, &size);
#endif
#if 0
    int doubleArray[ROW][COL] = {
                                    {1,2,3,4},
                                    {5,6,7,8},
                                    {9,10,11,12},
                                    //{13,14,15,16}
                                    //{0},
                                    //{0},
                                    //{0}
                                    //    {1,2},
                                    //    {3,4}
                                }; 


    
    int **matrix =  (int **)malloc(sizeof(int *)*ROW);
    
    int i;
    for(i=0; i<ROW; i++)
        matrix[i] = doubleArray[i];

    //printf("ret=%d\n", searchMatrix(matrix, ROW, COL, 4));
#endif

#if 0
    int i=0;
    int ** returnArray = (int **)malloc(sizeof(int *) * ROW);
    int ** columnSizes = (int **)malloc(sizeof(int *) * ROW);
    returnArray = generate(6, columnSizes);
    
    for(i=0; i<ROW; i++)
    {
        printArray(returnArray[i], (*columnSizes)[i]);
        printf("\n");
    }
#endif
#if 0
    int arraySize = 0;
    int * returnArray = (int *)malloc(sizeof(int) * 5);
    returnArray = getRow(5, &arraySize);
    printArray(returnArray, arraySize);
#endif

#if 0
    int array[] = { 1,2,3, 4 }; 
    int len = sizeof(array)/sizeof(array[0]);

    int arraySize = 0;    
    int * returnArray = (int *)malloc(sizeof(int) * len);
    
    returnArray = productExceptSelf(array, len, &arraySize);
    printArray(returnArray, arraySize);
#endif    
}
