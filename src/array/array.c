#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "typedef.h"



void printArray(int * array, int num)
{
    int i = 0;

    for(i=0; i<num; i++)
    {
        printf("%d  ", array[i]);
    }
}

void printDoubleArray(int **array, int row, int col)
{
    int i, j;
    
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            //printf("array[%d][%d]=%d   ", i, j, array[i*col + j]);
            printf("array[%d][%d]=%d   ", i, j, array[i][j]);
        }
        printf("\n");
    }
    printf("****************\n");
}


BOOL containsDuplicate(int* nums, int numsSize) 
{
    int i=0, j=0;
    BOOL flag = FALSE;
    
    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if(nums[i] == nums[j])
                flag = TRUE;
        }
    }
    return flag;
}

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

void setZeroes(int** matrix, int matrixRowSize, int matrixColSize) 
{
    int i=0, j=0;

    BOOL row[matrixRowSize];
    BOOL col[matrixColSize];    

    for(i=0; i<matrixRowSize; i++) 
        row[i] = FALSE;
    
    for(j=0; j<matrixColSize; j++) 
        col[j] = FALSE;

    for(i=0; i<matrixRowSize; i++)
    {
        for(j=0; j<matrixColSize; j++)
        {
            if(matrix[i][j] == 0)
            {
                row[i] = TRUE;
                col[j]= TRUE;
            }
        }
    }

    for(i=0; i<matrixRowSize; i++)
    {
        if(row[i] == TRUE)
        {
            for(j=0; j <matrixColSize; j++)
                matrix[i][j] = 0;
        }            
    }

    for(j=0; j<matrixColSize; j++)
    {
        if(col[j] == TRUE)
        {
            for(i=0; i <matrixRowSize; i++)
                matrix[i][j] = 0; 
        }            
    }
}


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

BOOL containsNearbyDuplicate(int* nums, int numsSize, int k) 
{
    int i=0, j=0;
    BOOL flag = FALSE;
    
    for(i=0; i<numsSize; i++)
    {
        for(j=i+1; j<numsSize; j++)
        {
            if((nums[i] == nums[j]) && ((j-i)<=k))
                flag = TRUE;
        }
    }
    return flag;
}

int searchInsert(int* nums, int numsSize, int target) 
{
    int i = 0;
    
    for(i=0; i<numsSize; i++)
    {
        if(nums[i] >= target)
            return i;
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) 
{
    int i=0;
    int start=0, end=0;
    BOOL startFlag = FALSE;
    BOOL endFlag = FALSE;    
    
    int * array = (int *)malloc(sizeof(int *)*2);

    for(i=0; i<numsSize; i++)
    {
        if(target == nums[i])
        {
            start = i;
            startFlag = TRUE;
            break;
        }
    }

    for(i=numsSize-1; i>=0; i--)
    {
        if(target == nums[i])
        {
            end = i;
            endFlag = TRUE;
            break;
        }
    }

    *returnSize = 2;

    if((TRUE ==startFlag) && (TRUE ==endFlag))
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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int** columnSizes, int* returnSize) 
{
    int i, j;

    int ** returnArray = (int **)malloc(sizeof(int *)*numRows);
    int *columnSizesArray = malloc(sizeof(int)*numRows);
    
    for(i=0; i<numRows; i++)
        returnArray[i] = (int *)malloc(sizeof(int)*numRows);
        
    if(numRows < 1)
        return returnArray;
    
    for(i=0; i<numRows; i++)
    {
        printf("111\n");
        columnSizesArray[i] = i+1;
        printf("columnSizesArray[%d]=%d\n", i,columnSizesArray[i]);
        for(j=0; j<=i; j++)
        {
            if(i == 0)
                returnArray[i][j] = 1;
            else if(j == 0)
                returnArray[i][j] = 0 + returnArray[i-1][j];
            else if(j == (numRows-1))
                returnArray[i][j] = returnArray[i-1][j-1] + 0;
            else
                returnArray[i][j] = returnArray[i-1][j-1] + returnArray[i-1][j];
            printf("a[%d][%d]=%d    ", i,j, returnArray[i][j]);
            *returnSize++;
        }
        printf("\n");
    }
    
    printf("222\n");

    *columnSizes = columnSizesArray;
    printf("returnSize=%d\n", *returnSize);

    return returnArray;
}

/**
 Given an index k, return the kth row of the Pascal's triangle.
 
 For example, given k = 3,
 Return [1,3,3,1].

 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize) 
{
    
}

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
#if 0
void moveZeroes(int* nums, int numsSize) 
{
    int i=0, j=0;

    while(j<numsSize)
    {
        if(nums[j]!=0)
            nums[i++] = nums[j];
        j++;
    }

    while(i<numsSize)
    {
        nums[i++] = 0;
    }    
}
#endif

/*********************************************
********   Num : 74
********   Title  : Search a 2D Matrix
********   Tag  : Array/Binary Search
**********************************************/
BOOL searchMatrix(int** matrix, int matrixRowSize, int matrixColSize, int target)
{
    int row=0, col=matrixColSize-1;

    while(row<matrixRowSize && col>=0)
    {
        if(target == matrix[row][col])
            return TRUE;
        else if(target > matrix[row][col])
            row++;
        else
            col--;
    }

    return FALSE;
}

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡Ý s. 
If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7,
the subarray [4,3] has the minimal length under the problem constraint.

*/
int minSubArrayLen(int s, int* nums, int numsSize)
{
    
}   

#define ROW     3
#define COL      4

void array_main_test(void)
{
    int array[] = { 0,1,0,3,32,0,0,45}; 
    int len = sizeof(array)/sizeof(array[0]);
    //int ret = search(array, len, 2);
    //printf("ret=%d\n", ret);
#if 0
    moveZeroes(array, len);
    //int **matrix;
    printArray(array, len);
    
    //generate(1, matrix, &size);
    //printDoubleArray(matrix, ROW, COL);
#endif

#if 1
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

    printf("ret=%d\n", searchMatrix(matrix, ROW, COL, 4));
#endif

#if 0

    generate(3, matrix, &len);
    printDoubleArray(matrix, ROW, COL);

//    rotateImage(matrix, ROW, COL);

//    printDoubleArray(matrix, COL, ROW);
#endif    
}

