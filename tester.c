#include <stdio.h>
#include <stdlib.h>
#include "code.c" 

void run_tests(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open %s\n", filename);
        exit(1); // Arrête tout si le fichier est absent
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
            printf("Test Case %d: PASSED (Expected %d, Got %d)\n", testNum, expected, result);
        } else {
            printf("Test Case %d: FAILED (Expected %d, Got %d)\n", testNum, expected, result);
            free(nums);
            fclose(file);
            exit(1);
        }

        free(nums); 
        testNum++;
    } // Fin du while

    fclose(file);
}

int main() {
    printf("Bissmilleh... Starting Tests\n");
    run_tests("input.txt");
    printf("All tests passed successfully!\n");
    return 0;
}
