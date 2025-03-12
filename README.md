# mywc - Custom Word Count Tool in C

`mywc` is a simple word count tool, similar to the Unix `wc` command, written in C.

## 🚀 Features
- Count **lines**, **words**, and **characters** in a file.
- Supports **command-line options**:
  - `-l` → Count lines
  - `-w` → Count words
  - `-c` → Count characters
- Can process **multiple files**.

## 🛠️ Installation
### **Compile the Program**
```sh
gcc mywc.c -o mywc

## Run the Program
```sh

./mywc filename.txt

or use options:

./mywc -l filename.txt   # Count lines
./mywc -w filename.txt   # Count words
./mywc -c filename.txt   # Count characters
./mywc filename1.txt filename2.txt  # Process multiple files

## Example Usage

echo "Hello world!" | ./mywc

output:
Lines: 1  Words: 2  Characters: 13
 
