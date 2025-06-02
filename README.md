# 📝 POSIX File Writer — `write.c`

Author: Aneesh Jain  
Project: Exploring low-level Linux file I/O using POSIX system calls like `open()` and `write()`.

---

## 📌 Overview

This C program takes a single command-line argument (a string), opens/creates a file named `write.txt`, and writes the input string into it using **POSIX APIs**.

It demonstrates:

- Use of system calls: `open()`, `write()`, and `close()`
- Flag-based file access with bitwise OR (`O_WRONLY | O_CREAT`)
- Basic command-line argument handling
- Error checking and logging

---

## 🛠️ How to Build

```bash
gcc write.c -o write
```
## ▶ How to Run
Correct usage:
```bash
./write "HelloWorld"
```
This will create write.txt (if not present) and write "HelloWorld" into it.

## Example of incorrect usage
```bash
linux-o-phile@homeserver:~/File-I-O/FILEIO$ ./write


Author: Aneesh Jain
========== write usage ===========
Usage: ./write <string_to_write>

linux-o-phile@homeserver:~/File-I-O/FILEIO$ ./write arg arge arge


Author: Aneesh Jain
More than required number of arguments were passed
========== write usage ===========
Usage: ./write <string_to_write>

linux-o-phile@homeserver:~/File-I-O/FILEIO$
```
Both cases will print a usage message and exit.

## 📂 File Created
write.txt: Contains the data you pass via command line.

## Main highlights of the program
```bash
fd = open("write.txt", O_WRONLY | O_CREAT, 0600);
write(fd, user_input, sizeof(user_input));
close(fd);
```
O_WRONLY: Open for writing
O_CREAT: Create the file if it doesn't exist
0600: File permission bits — read & write for owner only

Each flag is a binary bitmask:

```bash
#define O_WRONLY 0b00000001  // open for write only
#define O_CREAT  0b01000000  // create file if it doesn't exist
```
When you combine them:
```bash
O_WRONLY = 0b00000001
O_CREAT  = 0b01000000
--------------------------
Result   = 0b01000001  ← This is passed to `open()`
```
You're telling the kernel:
- Open the file for writing
- Create it if it doesn't exist

All flags are combined using bitwise OR, resulting in a binary representation the kernel can parse.
