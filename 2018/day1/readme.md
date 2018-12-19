# Solution to day1-2.cpp
Implemented a brute force approach.  Used a map (perhaps should've used a set) to log all the frequencies encountered.  Continued to loop over input and checking each frequency against the keys in the map.  If found, then we break the loop and return the frequency.

The disadvantage to this approach is that there's no guarauntee that this will terminate (though for the purposes of the coding challenge it does).  The v2 approach addresses this issue.

# Solution to day1-2v2.cpp
A mathematical approach is used to guarauntee that this algorithm will terminate whether there exists a duplicate or not.

Observe the pattern in the example below:
    Inputs.txt: +1 +1 +10 -9 -> shift = 3
    ITERATION 0: 0, 1, 2, 12
    ITERATION 1: 3, 4, 5, 15
    ITERATION 2: 6, 7, 8, 18
    ITERATION 3: 9, 10, 11, 21
    ITERATION 4: 12

With each iteration, the number in each position is offset by the overall shift of one iteration through Inputs.txt (shit = 3).  Because we know that the value will increase by 3 for each iteration on Inputs.txt, I see that the first value 0 will eventually reach 12.
    - 0 + (shift * n); // n = number of iterations through Inputs.txt
    - 0 + (3 * 4) = 12

Now the problem can be further reduced, given a set of frequencies F, find a frequency x inside F such that x = y + (shift * n) where y is some frequency inside F.  Grouping the integers in F based on their modulo shift is a good way to observe this:
    - _ % 3 = 0: 0, 12
    - _ % 3 = 1: 1
    - _ % 3 = 2: 2

The integers in the group where y % shift = 0 identify the numbers which we know will replicate again.  If there are no numbers, we can terminate, if there is at least one number, we know there will be replication.

    ## Edge Cases to Consider
    - If multiple values replicated, choose value that appears in set F first.
    - Consider how modulo operates in language of choice if shift is negative
    - If repitition occurs inside iteration 0; need to explicitly check for this
    - If shift = 0; then solution will be 0; // asked on reddit why this is 0 versus `arr[0]`
    - If all groups contain only 1 number, there is no solution

Credit to solution: https://www.reddit.com/r/adventofcode/comments/a20646/2018_day_1_solutions/

