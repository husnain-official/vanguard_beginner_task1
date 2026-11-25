# Learning Reflection

## 1. What does CMake do, and how is it different from a compiler?
CMake is a build-system generator, not a compiler. When I ran `cmake -S . -B build`, CMake read `CMakeLists.txt` and generated Makefiles inside the `build` directory. The compiler (`g++`) only ran during `cmake --build build`, when it translated `src/main.cpp`, `src/game.cpp`, and the random-number source file into object files and linked them into the `guessquest` executable.

## 2. How do `git add`, `git commit`, and `git push` differ?
`git add` stages specific changes—such as `git add src/game.cpp`—preparing them for the next snapshot without saving them yet. `git commit` records those staged changes into my local repository history. `git push` uploads my local commits and branches (like `fix/cmake` or `feature/difficulty-selector`) to my remote GitHub fork (`origin`).

## 3. Why did the conflict happen, and how did you resolve it?
Both `feature/limited-attempts` and `feature/hints` modified the same wrong-guess block in `src/game.cpp`. Because `limited-attempts` was merged into `main` first, merging `main` into `feature/hints` triggered a conflict. I resolved it by removing the `<<<<<<<`, `=======`, and `>>>>>>>` markers, placing the attempt check before the high/low hints, removing the duplicate `"Try again!"` line, and committing the merge.

## 4. Which error took longest to understand, and what did you learn?
The trickiest errors were `game.h: No such file or directory` and the `undefined reference to randomNumber(int, int)` linker error, which taught me how `target_include_directories` and linking source files work in CMake. I also accidentally put `submission.md` on `main` earlier while learning, which blocked branch switching. That mistake taught me to keep `main` clean by always working on a separate branch, pushing it, opening a PR, resolving any conflicts, and merging.