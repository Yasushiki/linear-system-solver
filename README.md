# Linear System Solver
A C++ linear system solver

# Headers
## vectorOperatorOverload
Defines a class called Vector. Vector is exatly the same as std::vector, but with some Operator Overloads.

### << Operator
Allows Vector to be printed in std::cout
```c++
Vector<int> vector {1,2,3};
std::cout << vector << "\n";
```
will print
```c++
{1,2,3}
```

### + Operator
Adds two Vector
```c++
Vector<int> vector1 {1,2,3}, vector2 {4,5,6}, vectorSum;
vectorSum = vector1+vector2;
std::cout << vectorSum << "\n";
```
will print
```c++
{5,7,9}
```

### - Operator
Subtracts two Vector
```c++
Vector<int> vector1 {1,2,3}, vector2 {4,5,6}, vectorSub;
vectorSub = vector1-vector2;
std::cout << vectorSub << "\n";
```
will print
```c++
{-3,-3,-3}
```

### * Operator
Multiplies a Vector and a scalar
```c++
Vector<int> vector1 {1,2,3}, vectorMultiplied;
int scalar = 5;
vectorMultiplied = vector1 * scalar;
std::cout << vectorMultiplied << "\n";
```
will print
```c++
{5,10,15}
```

## linearSystem
Defines a class called LinearSystem. Its only method is solve(), that returns a Vector with the solutions of the system.
```c++
// creating the system
std::vector<Vector<double>> system = {{1,1,1,1}, {0,1,2,1}, {0,0,1,1}};
/*
1x + 1y + 1z = 1
0x + 1y + 2z = 1
0x + 0y + 1z = 1
*/

// solving the linear system
LinearSystem ls(system);
Vector<double> solution = ls.solve();


std::cout << solution << "\n";
```
will print
```c++
{1,-1,1}
```


# Limitations
## Main diagonal
The program will not work if the linear system contains 0 in any position of the "main diagonal".
Maybe you'll need to change the order of the lines.
`{{0,1,2}, {1,3,7}}` wont work, but `{{1,3,7}, {0,1,2}}` will.

Try writing the matrix in a paper without the last column if the solutions keep returning "nan", it will help you see where is the 0 in the main diagonal.
```
Wont work  \  Will work
0 1           1 3
1 3           0 1
```

## Different size Vector operation
If you try to sum or subtract two Vector with different sizes, the final size will be the same as the First vector. Other columns wont be modified.
```c++
Vector<double> vector1 {1,2,3}, vector2 {10,20}, vector12, vector21;

vector12 = vector1 + vector2;
vector21 = vector2 + vector1;

std::cout << vector12 << " " << vector21 << "\n";
```
will print
```c++
{11,22,3} {11,22}
```
