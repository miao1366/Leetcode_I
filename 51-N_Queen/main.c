/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h> 
#include <stdbool.h>

bool check(int* visited, int row, int col) {
  for (int i = 0; i < row; i++)
    if (col == visited[i] || row + col == (visited[i] + i) || row - col == i - visited[i])
      return false;
  return true;
}

void backtrack(int n, int row, int* visited, char*** result, int* returnSize) {
  if (row == n) {
    result[*returnSize] = (char**)malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
      result[*returnSize][i] = (char*)calloc(n + 1, sizeof(char));
      memset(result[*returnSize][i], '.', n);
      result[*returnSize][i][visited[i]] = 'Q';
    }
    (*returnSize)++;
    return;
  }
  for (int i = 0; i < n; i++) {
    if (!check(visited, row, i)) continue;
    visited[row] = i;
    backtrack(n, row + 1, visited, result, returnSize);
    // visited[row] = 0; //此句无关紧要，但是回溯的思想
  }
}
char*** solveNQueens(int n, int* returnSize, int** returnColumnSizes) {
  *returnSize = 0;
  int* visited = (int*)calloc(n, sizeof(int));
  char*** result = (char***)malloc(n * n * n * sizeof(char**));
  backtrack(n, 0, visited, result, returnSize);
  *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
  for (int i = 0; i < *returnSize; i++)
    (*returnColumnSizes)[i] = n;
  return result;
}

// gcc -ggdb main.c 
