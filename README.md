# Transaction Database
-------

This is a console application that aims to provide a transactions database.

## Table of Contents
-------
- [Installation](#Installation)
- [Commands](#Commands)
- [Writeup](#Writeup)
- [Example Output](#Example-Output)

## Installation
-------
To use the application, follow these installation steps:

1. Clone the repository to your local machine:
```bash
git clone git@github.com:wilfredogao/transactions.git
```
2. Navigate to the project directory:
```bash
cd transactions
```
3. Run the executable
```bash
./transactions.exe
```

## Commands
-------
![Console Commands](images/consoleCmds.jpg)

## Writeup
-------

Overall this assignment was good practice for implementing a basic transactions database. 

In terms of modifictaions, I would change assignment details to mention:
* Fig 1: shows the header file for the InMemoryDB class
* Fig 2: shows what will be executed in main

Likewise, to detail what should happen in case of an error occurring either in Fig. 2 or showing an example output display for reference in the assignment details.

In terms of grading, I would change the 4 points for working code to be more detailed, similar to below:

4 points for working code:
* 1 point for get and put functionality
* 1 point for begin transactions functionality
* 1 point for commit functionality
* 1 point for rollback functionality

## Example Output
-------
![Using GET/PUT Commands before beginning transaction](images/outputEx1.jpg)
![Using PUT/GET/COMMIT Commands after beginng transaction](images/outputEx2.jpg)
![Using ROLLBACK Commands before beginning transaction](images/outputEx3.jpg)
![Using GET/PUT/ROLLBACK Commands after beginning transaction](images/outputEx4.jpg)
