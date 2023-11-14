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
  printf("let 6 insert to the index 2 of nums:");
  printArray(nums, 5);

  system("pause");
}

// 将元素插入数组中的指定位置
void insert(int *nums, int size, int index, int data)
{
  // 把索引 index 以及之后的所有元素向后移动一位
    for (int i = size - 1; i > index; i--) {
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