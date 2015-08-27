/*
Write a function:

int solution(int A, int B, int K);

that, given three integers A, B and K, returns the number of integers within the range [A..B] that are divisible by K, i.e.:

{ i : A ≤ i ≤ B, i mod K = 0 }

For example, for A = 6, B = 11 and K = 2, your function should return 3, because there are three numbers divisible by 2 within the range [6..11], namely 6, 8 and 10.

Assume that:

A and B are integers within the range [0..2,000,000,000];
K is an integer within the range [1..2,000,000,000];
A ≤ B.
Complexity:

expected worst-case time complexity is O(1);
expected worst-case space complexity is O(1).
*/

int solution(int A, int B, int K) {
    int rem  = A%K;
    int quot = A/K;
    int s ;
    if (rem == 0) s = A;
    else{
        if (quot == 0) s = K > B ? B:K; 
        else s = (A + rem) > B? B:A + rem;
    }
    return (B-s)/K + (s%K == 0);  
}

/*Test case*/
/*
A = 6, B = 11, K = 2
A = 11, B = 345, K = 17
A = B in {0,1}, K = 11
A = 10, B = 10, K in {5,7,20}
A = 100, B=123M+, K=2
A = 101, B = 123M+, K = 10K
A = 0, B = MAXINT, K in {1,MAXINT}
A, B, K in {1,MAXINT}
*/




