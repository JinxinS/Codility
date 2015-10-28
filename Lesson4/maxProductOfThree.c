/*
* A non-empty zero-indexed array A consisting of N integers is given. The product of triplet (P, Q, R) equates to A[P] * A[Q] * A[R] (0 ≤ P < Q < R < N).
*
* For example, array A such that:
*
* A[0] = -3
* A[1] = 1
* A[2] = 2
* A[3] = -2
* A[4] = 5
* A[5] = 6
* contains the following example triplets:
*
* (0, 1, 2), product is −3 * 1 * 2 = −6
* (1, 2, 4), product is 1 * 2 * 5 = 10
* (2, 4, 5), product is 2 * 5 * 6 = 60
* Your goal is to find the maximal product of any triplet.
*
* Write a function:
*
* int solution(int A[], int N);
*
* that, given a non-empty zero-indexed array A, returns the value of the maximal product of any triplet.
*
* For example, given array A such that:
*
* A[0] = -3
* A[1] = 1
* A[2] = 2
* A[3] = -2
* A[4] = 5
* A[5] = 6
* the function should return 60, as the product of triplet (2, 4, 5) is maximal.
*
* Assume that:
*
* N is an integer within the range [3..100,000];
* each element of array A is an integer within the range [−1,000..1,000].
*Complexity:
*
*expected worst-case time complexity is O(N*log(N));
*expected worst-case space complexity is O(1), beyond input storage (not counting the storage required for input arguments).
*Elements of input arrays can be modified.
**/
int cmp (const void * a, const void * b)
{
	   return ( abs(*(int*)a) - abs(*(int*)b) );
}

int solution(int A[], int N) {
	if(N==3) return A[N-1]*A[N-2]*A[N-3];
	qsort(A, N, sizeof(int), cmp);  
	int r  = A[N-1]*A[N-2];
	for(int i = N-3 ; i >=0; --i ) {   
		if((r > 0 && A[i] > 0) || (r < 0 && A[i] < 0))
			return r*A[i];
	}
	if(r == 0) return 0;
	if(r < 0) {
		if (A[N-1] > 0)	return A[N-4]*A[N-3]*A[N-1];
		else return A[N-4]*A[N-3]*A[N-2];
	}
	if(r > 0)  return A[0]* A[1]* A[2];
}
