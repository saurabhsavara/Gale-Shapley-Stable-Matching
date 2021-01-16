# Gale Shapley Stable Matching

Find the stable matching pair from a list of Men and Women where each of their preferences for the other has been given.

# New Features!

  - Given a set of "stable" matching, check if there is a "more stable" matching available for any man or woman in the list.

### Compiling and Running

Dillinger requires [Node.js](https://nodejs.org/) v4+ to run.

Install the dependencies and devDependencies and start the server.

```
make
```

```
match man.txt woman.txt output.txt
```

```
find man.txt woman.txt stable.txt output.txt 
```
