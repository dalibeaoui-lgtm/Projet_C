# Subarray Sum Equals K

## 1. Problem Description

The objective of this project is to determine the total number of **continuous subarrays** within an integer array that sum to a specific target value `k`.

- **LeetCode Reference:** [560. Subarray Sum Equals K](https://leetcode.com/problems/subarray-sum-equals-k/)  
- **Language:** C

Given an integer array `nums` and a target integer `k`, the algorithm counts all contiguous subarrays whose sum equals `k`. This requires an efficient solution to handle large arrays without brute-force iteration.

---

## 2. Real-Life Use Case: Financial Pattern Detection

This algorithm can be applied in **financial transaction monitoring**.

**Example scenario:**  
A bank monitors streams of credit card transactions. Fraudsters sometimes use “structuring” — splitting a large transaction into smaller ones to avoid detection. By applying the Subarray Sum algorithm:

- The bank can scan a customer’s transaction history in real-time.
- Detect any continuous sequence of transactions summing exactly to a flagged high-risk total (`k`), even if spread across multiple days.
- Enable timely alerts for suspicious behavior.

This demonstrates how the algorithm is relevant beyond theoretical problems, providing **real-world impact**.

---

## 3. Approach and Solution

The solution uses a **Prefix Sum** strategy combined with a **Hash Map** to achieve **linear time efficiency**.

### Core Logic

1. **Prefix Sum:**  
   Iterate through the array while maintaining a running total of all elements seen so far.

2. **Equation:**  
   Sum(i, j) = PrefixSum(j) - PrefixSum(i-1) = k
   PrefixSum(i-1) = PrefixSum(j) - k

3. **Hash Map:**  
   - Since C does not have a native hash map, a **custom hash map with chaining** is implemented.  
   - The map stores the frequency of each prefix sum encountered.  
   - For every new prefix sum, the map is queried for `(current_total - k)` occurrences. This count is added to the total result.

4. **Single Pass:**  
   The array is traversed **once**, checking the hash map for matches and updating it with the current prefix sum. This ensures **O(n)** time complexity.

---

## 4. Time and Space Complexity

| Metric | Complexity | Explanation |
|--------|-----------|-------------|
| Time   | O(n)      | Each element is processed once. Hash map insertions and queries are O(1) on average. |
| Space  | O(n)      | In the worst case, every unique prefix sum is stored in the hash map. |

---

## 5. Compilation and Execution

### Prerequisites
- A C compiler (e.g., `gcc` or `clang`)  
- A main test file (e.g., `main.c`) that includes the solution

### Compilation

Open a terminal in the project directory and run:

```bash
gcc -Wall -o subarray_solver solution.c
```

### Running the Program

```bash
./subarray_solver
```


