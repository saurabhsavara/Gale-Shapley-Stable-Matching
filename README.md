# Gale Shapley Stable Matching

Find the stable matching pair from a list of Men and Women where each of their preferences for the other has been given.

# New Features!

  -Verify a given stable matching is the best possible matching.

# Description
  Data Read in the following Input Format 
N
pref list

Example:
5
5 1 2 4 3
3 2 4 1 5
2 3 4 5 1
1 5 4 3 2
4 2 5 3 1


### Compiling and Running

```
make
```

```
./matchmaking find %mantextfile% %womantextfile% %outputfile%
```

```
./matchmaking stable %mantextfile% %womantextfile% %unstablefile%
```

# Error Handling 
  - No missing pairs
  - No repeated pairings 
  - Equal Number of men and woman in preference list
