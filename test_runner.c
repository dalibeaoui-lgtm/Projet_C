#include <stdio.h>
#include <stdlib.h>
#include "../hashmap.h" 

extern int subarraySum(int* nums, int numsSize, int k);

int main() {
    FILE *file = fopen("TESTS/input.txt", "r");
    if (!file) {
        perror("Could not open input.txt");
        return 1;
    }

    int k, size, expected, testNum = 1;
    while (fscanf(file, "%d %d %d", &k, &size, &expected) != EOF) {
        int *nums = malloc(size * sizeof(int));
        for (int i = 0; i < size; i++) {
            fscanf(file, "%d", &nums[i]);
        }

        int result = subarraySum(nums, size, k);
        
        if (result == expected) {
            printf("Test %d: PASSED (Found %d subarrays)\n", testNum, result);
        } else {
            printf("Test %d: FAILED! Expected %d, but got %d\n", testNum, expected, result);
        }

        free(nums);
        testNum++;
    }

    fclose(file);
    return 0;
}