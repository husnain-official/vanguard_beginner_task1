## 1. Explore the repository
### Task: 01  
- `git status` tells which branch i am on, have i made any commits, the files which are not being tracked, being tracked, staged etc. 
- `git log --oneline` gives the 1st line of the previous commits you have made. 
- `git branch -a` lists all the branches that both the local ones and the remotes ones.
  
### Task: 02  
`game.h`     just a simple header which declares 2 functions.   
`game.cpp`  contains the function definition for `playGame`, a simple number guessing game, it calls the function `randomNumber` which still isnt defined in `game.h/cpp`, so it needs to be defined in another file for it to compile.   
`main.cpp` contains the main function, the entry for the program, calls `playGame`  
`random.cpp` uses `random` library to generate a random number uses in the game.   
`CMAKELISTS` sets the requirements for the softwares being used (CMAKE, g++), gives instructions on how and what to make.  
### Task:03  
Both commands gave errors:   
`cmake -S . -B build` gave error as the name in the `CMAKELISTS.txt` `games.cpp` did not match any existing files, the correct name was `game.cpp`  
`cmake --build build` also gave a error, that was because we did not lists in the `CMAKELISTS.txt` the header files to include  

## 2. Repair the build
### Task: 01
`cmake -S . -B build` lists the location of the `CMAKEFILE.txt`, and build the `build` folder where the build instructions are put.   
`cmake --build build` fetches the build info from the make files in the build folder and makes all the executables, it is smart enough that if  `CMAKELISTS.txt` is updated it, updates the make files.   

### Task: 02
Updating and correcting the errors,  done while doing [Task: 03](#task-03)  
One error during the `cmake -S . -B build` as the source file listed did not exist.  
One error as the header was not defined, so the compiler gave error as soon as it tried to compile that part. 
Final error the files compiled but the files were not linked properly, one file `random.cpp` was left out, so it was not compiled with the others and therefore could not be linked. 

## Task: 03
Created a new branch, moved into it, staged the files, commited them, pushed them, then made a PR, merged the PR.

## Task: 04
### Part 1
`upstream/feature/limited-attempts` adds limit to attempts made.   
`upstream/feature/hints` adds hints about your guesses  

- Make both PR, resolved the conflict, merged, built the executable again, ran it. 






