#include <stdio.h>
#include <stdlib.h>
#include "code.c" 
void run_tests(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open %s\n", filename);
        return;
    }

    int n, k, expected, testNum = 1;

    
    while (fscanf(file, "%d %d", &n, &k) == 2) {
        int* nums = malloc(sizeof(int) * n);
        for (int i = 0; i < n; i++) {
            fscanf(file, "%d", &nums[i]);
        }
        fscanf(file, "%d", &expected);

       
        int result = subarraySum(nums, n, k);

       
    if (result == expected) {
            printf("Test Case %d: PASSED\n", testNum);
        } else {
            printf("Test Case %d: FAILED (Expected %d, Got %d)\n", testNum, expected, result);
            free(nums);
            fclose(file);
            return 1; // <--- TRÈS IMPORTANT : Force la croix rouge en cas d'erreur
        }

        free(nums);
        testNum++;
    }

    fclose(file);
}

int main() {
    printf("Bissmilleh...\n");
    run_tests("input.txt");
    return 0;
}
