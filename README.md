C Multi-Mode Calculator
Overview

This is a multi-functional calculator written in C that supports several modes: computer arithmetic, complex numbers, base-N conversions, and solving equations. It is designed as a command-line interface (CLI) tool to perform a variety of mathematical operations including trigonometry, logarithms, algebra, and linear and quadratic equations.

Features
1. Computer Mode

Primary Operations: Addition, subtraction, multiplication, division, exponentiation (^)

Trigonometry: sin, cos, tan (input in degrees)

Logarithmic Functions: log (base 10), ln (natural log), e^x

Inverse Trigonometry: sin^-1, cos^-1, tan^-1 (outputs in radians and degrees)

2. Complex Mode

Perform arithmetic on complex numbers (addition, subtraction, multiplication, division)

3. Base-N Conversion

Converts numbers from any base 2–16 to decimal, binary, octal, and hexadecimal

4. Equation Solver

Linear Equations:

Two variables (AX + BY = C)

Three variables (AX + BY + CZ = D)

Quadratic Equations: AX^2 + BX + C = 0

Supports complex roots

5. Future Extensions

Placeholder for matrix operations and table generation (not yet implemented)

Installation

Make sure you have a C compiler installed (GCC or Clang recommended).

Clone or download the repository.

Compile the code:

gcc -o calculator calculator.c -lm


The -lm flag links the math library for trigonometric and logarithmic functions.

Run the program:

./calculator

Usage

Run the program.

Select the mode from the main menu:

1. COMPUTER
2. COMPLEX
3. BASE-N
4. EQUATION
5. MATRIX
6. TABLE


Follow prompts specific to each mode.

Example

Computer Mode (Primary Operations):

Input: 5 + 3
Output: 8.0000


Quadratic Equation Solver:

A=1, B=-3, C=2
Output: X1=2.00, X2=1.00


Base-N Converter:

Input: 1011 2
Output: Decimal: 11
        Binary: 1011
        Octal: 13
        Hexadecimal: B

Notes

Trigonometric inputs are in degrees.

Supports constants pi and e in computations.

Proper error handling for division by zero, invalid input, and math domain errors.

License

This project is open-source and free to use for educational purposes.
