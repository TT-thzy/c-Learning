#include <stdio.h>
#include <stdlib.h>

/*
  Describe：数据操作
  Author： maGod
*/

int main()
{
  // 初始化数组
  int nums[5] = {1, 2, 3, 4, 5};

  printf("the random number is: %d \n", randomAccess(nums, 5));

  insert(nums, 5, 2, 6);
  printf("let 6 insert to the index 2 of the nums:");
  printArray(nums, 5);

  printf("\n");

  delete (nums, 5, 2);
  printf("delete the the index 2 of the nums: ");
  printArray(nums, 5);

  printf("/n");

  
  printf("let the nums size expansion from 5 to 8");
  
  system("pause");
}

//数组扩容
int* entend(int* nums, int size, int enlarge)
{
  //分配扩容数组的内存空间
  int* res = (int*)malloc(sizeof(int) * (size + enlarge));

  return res;
}

// 删除数组中的指定位置的元素
// 最后一个元素已经没有意义不需要关心，如有特殊处理，在for循环中加入特定逻辑处理即可
void delete(int *nums, int size, int index)
{
  for (int i = index; i < size - 1; i++)
  {
    // 把索引index之后的所有元素往前移动一位
    nums[i] = nums[i + 1];
  }
}

// 将元素插入数组中的指定位置
void insert(int *nums, int size, int index, int data)
{
  // 把索引 index 以及之后的所有元素向后移动一位
  for (int i = size - 1; i > index; i--)
  {
    nums[i] = nums[i - 1];
  }
  // 将 num 赋给 index 处元素
  nums[index] = data;
}

// 随机访问元素
int randomAccess(int *nums, int size)
{
  int randomIndex = rand() % size;
  return nums[randomIndex];
}

// 打印数组
void printArray(int *nums, int size)
{
  for (int i = 0; i < size; i++)
  {
    printf("%d ", nums[i]);
  }
}