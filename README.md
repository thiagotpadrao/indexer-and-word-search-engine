# Indexer and word search engine

> Status: Finished

This work originated from a college project. It is a C code where it is possible to index a text file (.txt) into a data structure using either a binary tree or a linked list. It is also possible to search for words contained (or not) in the file after indexing, displaying the time in milliseconds for each operation performed in the program.

## How to run the application:

### Windows:

#### Compilation Intructions
1. Obtain gcc on your machine's command prompt
2. Open your machine's command prompt and verify if gcc was installed correctly. (you can verify by running the command: gcc --version)
3. Run the command: gcc "<PathToFile.c>" -o <FileName>
Note: <PathToFile.c> is the path of the C file on your computer. <FileName> is the name you would like the compiled file to have, for example: gcc "C:\Users\your_user\folder\code.c" -o test

#### Execution Instructions
To run, you must use the previously compiled file, passing as a parameter the text file you want and one of the two data structures (tree or list).

Run the command: <FileName> "<PathToFile.txt>" <DesiredIndex>

Note: <FileName> is the name of the compiled file (chosen earlier), <PathToFile.txt> is the path of the txt file on your computer. And <DesiredIndex> corresponds to: "arvore" or "lista". Example: test "C:\Users\your_user\textFiles\text.txt" arvore

### Linux:

#### Compilation Instructions
1. Obtain gcc on your machine's command prompt
2. Open your machine's command prompt and verify if gcc was installed correctly. (you can verify by running the command: gcc --version)
3. You must be in the same directory as the c file. If not, navigate through the directories until you are in the correct one.
Run the command: gcc <file.c> -o <FileName>
Note: <file.c> is the C file, that is, the code. <FileName> is the name you would like the compiled file to have, for example: gcc code.c -o test

#### Execution Instructions
To run, you must use the previously compiled file, passing as a parameter the text file you want and one of the two data structures (tree or list). You must be in the same directory as the text file.

Run the command: ./<FileName> "<file.txt>" <DesiredIndex>
Note: <FileName> is the name of the compiled file (chosen earlier), <file.txt> is the chosen txt file. And <DesiredIndex> corresponds to: "tree" or "list". Example: ./test text.txt tree

## How to use the application:
After executing, the process will store all the words from the txt file passed as a parameter and index them according to the index also passed as a parameter: arvore (which corresponds to a binary tree) or lista (which corresponds to a linked list).

After that, to search for a word in the file, the user must type the word "busca" followed by the desired word.

To end the execution, just type "fim".

If another word is typed, the message "Opcao Invalida!" will appear on the screen, and the user must provide an input again.

Additionally, the process also calculates and prints the time of indexing and searches (in milliseconds).
