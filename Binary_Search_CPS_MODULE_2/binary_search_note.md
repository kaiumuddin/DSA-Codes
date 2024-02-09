# Binary Search Notes

## To design a implementation you need to choose some

### Search Space : L, R

    - What will be the search space ?
    - How many minimum elements will be in search space ?
        - 1, 2 or 3
    - Search space will include all of the posible answer.
        - For array problems
            - L = ? 0, 1
            - R = ? n, n + 1
        - For integer bisection
            - L = ? 0, 1
            - R = ? n, n + 1

### Loop Condition : while( condition )

    -  L <= R    , for at least 1 elements in Search space
    -  L < R    , for at least 2 elements in Search space
    -  L + 1 < R    , for at least 3 elements in Search space

### M check condition

    - ( M  == target value ) check for answer
        - nedded in L <= R 
        - not nedded in L < R 
        - not nedded in L + 1 < R 

### Ans check and L,R update condition : if

    - When L <= R, exclude mid from SS
    - Exclude M from Search space, bcz we are cheking if M is the ans
        - M == target, return M as ans
        - R = M - 1
        - L = M + 1

    - When L < R
    - Include M in Search space, bcz we are not cheking if M is the ans
        - R = M
        - L = M + 1

    - When L + 1 < R
    - Include M in Search space, bcz we are not cheking if M is the ans
        - R = M
        - L = M

### After Search Where will be ANSWER

    - After successful search what is the value of L, R, M ?
        - When L <= R
            - M has the answer,
            - so return it OR
            - maybe returned M as ans before terminating loop

        - When L < R
            - no successfull search,
            - it will terminate when L == R

    - After Unsuccessful search what is the value of L, R, M ?
        - When L <= R
            - loop will Terminate if
                - either L crosses R
                - either R crosses L
            - ans maybe in R
        
        - When L < R
            - if(M >= target){} 
                - for lowerbound, : first element equal/greater to target
                    - if target found L stays on ans
                    - if not found L passes over ans
                - L == R 
                - M == L - 1 or R - 1
                - ans is in L and R

            - if(M > target){}
                - for upperbound, : first element greater to target
                    - if target found L passes over ans
                    - if not found L passes over ans
                - L == R 
                - M == L - 1 or R - 1
                - for some problem like sqrt(x)
                    - ans is in L - 1 and R - 1,
