QuizMaster CLI

A simple and interactive command-line quiz application built in C++.
The program loads MCQ questions from a text file, takes user input, and displays the final score.

Features

Multiple-choice quiz in the terminal

Reads questions from an external file

Simple and easy to extend

Tracks score automatically

Beginner-friendly project structure

How It Works

Questions follow a fixed format inside questions.txt:

Question text
Option 1
Option 2
Option 3
Option 4
CorrectOptionNumber


Each question block must be separated by an empty line.

How to Run

Install a C++ compiler (e.g., g++).

Open the project folder in a terminal.

Compile the program:

g++ main.cpp -o quiz


Run the quiz:

./quiz

Example Question Format
What is the capital of France?
Paris
London
Berlin
Rome
1

Project Structure
QuizMaster-CLI/
│── main.cpp
│── questions.txt
└── README.md

License

This project is licensed under the MIT License.