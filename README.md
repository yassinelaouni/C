# README: How to Set Up and Run a C Project in Visual Studio Code (VSCode)

This guide provides step-by-step instructions to set up, build, run, and debug a C project in Visual Studio Code (VSCode). Follow these steps to get started with your C programming journey.

---

## **Table of Contents**
1. [Prerequisites](#prerequisites)
2. [Setting Up Your Workspace](#setting-up-your-workspace)
3. [Writing Your C Code](#writing-your-c-code)
4. [Building Your Project](#building-your-project)
5. [Running Your Program](#running-your-program)
6. [Debugging Your Code](#debugging-your-code)
7. [Optional: Using Code Runner](#optional-using-code-runner)
8. [Troubleshooting](#troubleshooting)
9. [Conclusion](#conclusion)

---

## **Prerequisites**

Before you start, ensure you have the following installed:

1. **Visual Studio Code**:
   - Download and install VSCode from [here](https://code.visualstudio.com/).

2. **C Compiler**:
   - **Windows**: Install [MinGW](http://www.mingw.org/) or [TDM-GCC](https://jmeubank.github.io/tdm-gcc/).
   - **Linux**: Install `gcc` using your package manager (e.g., `sudo apt install gcc` for Ubuntu).
   - **macOS**: Install `gcc` using [Homebrew](https://brew.sh/) (e.g., `brew install gcc`).

3. **C/C++ Extension for VSCode**:
   - Install the official C/C++ extension from the Extensions Marketplace in VSCode.

---

## **Setting Up Your Workspace**

1. Open VSCode.
2. Create a new folder for your C project.
3. Open the folder in VSCode (`File > Open Folder`).
4. Inside the folder, create a new file with a `.c` extension (e.g., `main.c`).

---

## **Writing Your C Code**

1. Open the `.c` file and write your C code. For example:

```c
#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}