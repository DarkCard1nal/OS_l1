# STP_p6

_Created for the course "Operating systems" V. N. Karazin Kharkiv National University_

Ñ++11 Point Simulation and ArrayList program.

---

# Overview
This project implements a simulation involving points in a 3D space, where each point has coordinates and a mass. The simulation repeatedly removes the point with the smallest mass and transfers its mass to the nearest point. This process continues until only one point remains.

Additionally, the project includes an implementation of a custom ArrayList similar to Java's, supporting basic operations like adding, inserting, and removing elements.

# Task 0: Point Simulation in 3D Space

- **Goal**: Simulate the interaction of `n` material points in a 3D space. The point with the smallest mass disappears, transferring its mass to the nearest point. The process repeats until only one point remains.

## Class Point

The `Point` class represents a point in three-dimensional space with an additional characteristic - mass. This class provides the ability to create random points, calculate the distance between them, and also allows one point to absorb the mass of another.

- - Represents a point in 3D space with `x`, `y`, `z` coordinates and a `mass`.
- Supports methods to create random points, calculate distances, and absorb the mass of other points.

### Class fields:
- `int _x` - the coordinate of the point along the X-axis.
- `int _y` - the coordinate of the point on the Y-axis.
- `int _z` - the coordinate of the point on the Z-axis.
- `int _mass` - the mass of the point.

### Constructor:
```cpp
Point(int x, int y, int z, int mass);
```
- Initializes the object `Point` with the given coordinates `x`, `y`, `z` and mass `mass`.

### Methods:
1. **`void AbsorbMass(Point *oldPoint)`**.
- Increases the mass of the current point by the mass of another point `oldPoint`.
- After absorbing the mass, it frees memory by deleting the `oldPoint` object.
- It is used to simulate the process of merging points.

2. **`int X() const`**
- Returns the value of the X coordinate of the current point.

3. **`int Y() const`**
- Returns the value of the Y coordinate of the current point.

4. **`int Z() const`**
- Returns the value of the Z coordinate of the current point.

5. **`int Mass() const`**
- Returns the mass value of the current point.

6. **`static Point *RandomPoint(int min = 0, int max = 1000)`**
- A static method that creates a new `Point` object with random coordinates `x`, `y`, `z` and mass within `[min, max]`.
- Uses the standard random number library to generate values.

7. **`static double Distance(const Point *a, const Point *b)`**
- Static method for calculating the Euclidean distance between two points `a` and `b`.
- Distance formula:
\[
d = \sqrt{(x_2 - x_1)^2 + (y_2 - y_1)^2 + (z_2 - z_1)^2}
\]

8. **`friend std::ostream &operator<<(std::ostream &os, const Point &point)`**
- Overloading the `<<` operator to output the `Point` object in a user-friendly format.
- The output format: 
```cpp
Point(x: 10, y: 20, z: 30, mass: 100)
```



## Class `PointSimulator`

The `PointSimulator` class is designed to simulate the interaction of three-dimensional points (objects of the `Point` class) in space. The main function of the class is a simulation where points can absorb each other, depending on their distance and mass.

- Manages a collection of `Point` objects and performs the simulation.
- Iteratively removes the point with the smallest mass and transfers its mass to the nearest neighbor until only one point remains.

### Class fields
- **`std::vector<Point *> _points`** - a container that stores pointers to objects of type `Point`. This vector is used to store all the points with which the simulator works.

### Constructors.
1. **Default constructor**.
```cpp
PointSimulator();
```
Initializes an empty simulator without any points.

2. **Constructor with random generation of points**.
```cpp
PointSimulator(int randomCount, int min = 0, int max = 1000);
```
- `randomCount` - the number of points to generate.
- `min` and `max` - the range of coordinate values and mass for randomly generated points.
- Uses the `Point::RandomPoint()` method to create new points.

3. **Constructor with a passed vector of points**.
```cpp
PointSimulator(std::vector<Point *> points);
```
- Initializes the simulator with the existing vector of points.

### Destructor
```cpp.
~PointSimulator();
```
- Clears memory by deleting all dynamically created points.

### Methods
1. **`void Add(Point *point)`**
- Adds a new point to the simulator.

2. **`const int Count() const`**
- Returns the number of points in the simulator.

3. **`Point *SimulateAll()`**
- Runs the simulation until only one point remains.
- Repeats the iterative process of merging points until the number of points is greater than 1.
- Returns the only point remaining after the simulation is completed.

4. **`void ClearPoints()`**
- Removes all points from the `_points` vector and frees memory.

5. **`const std::vector<Point *> GetPoints() const`**
- Returns a copy of the vector of all points.

6. **`int Simulate()`**
- One iteration of the simulation:
- Finds the point with the minimum mass.
- Creates a copy of this point.
- Removes the original point from the vector.
- Finds the nearest neighbor and absorbs its mass.
- Returns the number of remaining points.

7. **`Point *FindNeighbor(const Point *a)`**
- Finds the point that is closest to the given point `a` using the Euclidean distance.
- Returns the closest point.

8. **Overloading the `<<`** operator
```cpp
friend std::ostream &operator<<(std::ostream &os, const PointSimulator &points);
```
- Allows convenient output of all points from the simulator.
- The output format:
```cpp
Point(x: 10, y: 20, z: 30, mass: 100)
```

## Examples
The main program `main`:
```cpp
Enter the number of points: 10
Create random points:
Point(x: 65, y: 65, z: 54, mass: 89)
Point(x: 30, y: 19, z: 42, mass: 76)
Point(x: 92, y: 5, z: 80, mass: 71)
Point(x: 32, y: 92, z: 40, mass: 56)
Point(x: 70, y: 89, z: 90, mass: 21)
Point(x: 20, y: 87, z: 65, mass: 99)
Point(x: 65, y: 26, z: 39, mass: 37)
Point(x: 72, y: 26, z: 2, mass: 96)
Point(x: 79, y: 84, z: 16, mass: 80)
Point(x: 50, y: 3, z: 19, mass: 61)

Start Point SimulateAll, Total points: 10
Iteration: 1
Point Count: 9
Point(x: 65, y: 65, z: 54, mass: 110)
Point(x: 30, y: 19, z: 42, mass: 76)
Point(x: 92, y: 5, z: 80, mass: 71)
Point(x: 32, y: 92, z: 40, mass: 56)
Point(x: 20, y: 87, z: 65, mass: 99)
Point(x: 65, y: 26, z: 39, mass: 37)
Point(x: 72, y: 26, z: 2, mass: 96)
Point(x: 79, y: 84, z: 16, mass: 80)
Point(x: 50, y: 3, z: 19, mass: 61)

Iteration: 2
Point Count: 8
Point(x: 65, y: 65, z: 54, mass: 110)
Point(x: 30, y: 19, z: 42, mass: 76)
Point(x: 92, y: 5, z: 80, mass: 71)
Point(x: 32, y: 92, z: 40, mass: 56)
Point(x: 20, y: 87, z: 65, mass: 99)
Point(x: 72, y: 26, z: 2, mass: 96)
Point(x: 79, y: 84, z: 16, mass: 80)
Point(x: 50, y: 3, z: 19, mass: 98)

Iteration: 3
Point Count: 7
Point(x: 65, y: 65, z: 54, mass: 110)
Point(x: 30, y: 19, z: 42, mass: 76)
Point(x: 92, y: 5, z: 80, mass: 71)
Point(x: 20, y: 87, z: 65, mass: 155)
Point(x: 72, y: 26, z: 2, mass: 96)
Point(x: 79, y: 84, z: 16, mass: 80)
Point(x: 50, y: 3, z: 19, mass: 98)

Iteration: 4
Point Count: 6
Point(x: 65, y: 65, z: 54, mass: 181)
Point(x: 30, y: 19, z: 42, mass: 76)
Point(x: 20, y: 87, z: 65, mass: 155)
Point(x: 72, y: 26, z: 2, mass: 96)
Point(x: 79, y: 84, z: 16, mass: 80)
Point(x: 50, y: 3, z: 19, mass: 98)

Iteration: 5
Point Count: 5
Point(x: 65, y: 65, z: 54, mass: 181)
Point(x: 20, y: 87, z: 65, mass: 155)
Point(x: 72, y: 26, z: 2, mass: 96)
Point(x: 79, y: 84, z: 16, mass: 80)
Point(x: 50, y: 3, z: 19, mass: 174)

Iteration: 6
Point Count: 4
Point(x: 65, y: 65, z: 54, mass: 261)
Point(x: 20, y: 87, z: 65, mass: 155)
Point(x: 72, y: 26, z: 2, mass: 96)
Point(x: 50, y: 3, z: 19, mass: 174)

Iteration: 7
Point Count: 3
Point(x: 65, y: 65, z: 54, mass: 261)
Point(x: 20, y: 87, z: 65, mass: 155)
Point(x: 50, y: 3, z: 19, mass: 270)

Iteration: 8
Point Count: 2
Point(x: 65, y: 65, z: 54, mass: 416)
Point(x: 50, y: 3, z: 19, mass: 270)

Iteration: 9
Point Count: 1
Point(x: 65, y: 65, z: 54, mass: 686)

Stop Point SimulateAll
Last Point(x: 65, y: 65, z: 54, mass: 686)
```
Tests in `test`

# Task 4: Custom ArrayList Implementation

The `ArrayList` class is an implementation of a dynamic array that provides functionality for working with collections of items in the style of standard C++ containers. It supports basic operations such as adding, inserting, deleting, modifying, and accessing items.

**Goal**: Create an array list with functionalities similar to Java's `ArrayList`.

## Designers

1. **Default constructor**.

`ArrayList(int capacity = 10)`

- Initializes an array with the specified (or standard) capacity.
- Allocates memory for an array of size `capacity`.
2. **Copy constructor**.

`ArrayList(const ArrayList<T> &array)`

- Creates a new array based on another object of type `ArrayList`.
3. **Constructor with an initial array**.

`ArrayList(const T *array, int size)`

- Initializes an array based on the provided array `array` of size `size`.

## Destructor

- `~ArrayList()` - Frees the memory allocated for the `_data` array.

## Main methods

1. **`bool add(const T &item)`**

- Adds a new item to the end of the list.
- Automatically expands the array if it is full.
2. **`bool insert(int index, const T &item)`**

- Inserts the element `item` at the position `index`.
- Shifts all subsequent items to the right.
- Returns `false` if the index is incorrect or if the array size could not be increased.
3. **`bool set(int index, const T &item)`**

- Replaces the item at position `index` with the new value `item`.
- Returns `false` if the index is incorrect.
4. **`const int size() const`**

- Returns the number of items in the list.
5. **`const int capacity() const`**

- Returns the current capacity of the list.
6. **`T get(int index) const`**

- Returns the item at the position `index`.
- If the index is incorrect, returns the default element of type `T`.
7. **`T remove(int index)`**

- Deletes the element at position `index`.
- Shifts all subsequent elements to the left.
- Returns the deleted element or the default element if the index is incorrect.
8. **`const T *getArray() const`**

- Returns a pointer to the internal data array.

## Auxiliary methods

1. **`bool indexIsCorrect(int index) const`**

- Checks if the index is correct (in the range from `0` to `_count - 1`).
2. **`bool resize(int newCapacity)`**

- Changes the capacity of the array to `newCapacity`.
- Returns `true` if the operation was successful.
3. **`bool resizeSmart(int newSize)`**

- Automatically resizes the array depending on the new size `newSize`.
- Uses the ratio `ratio` to determine when to resize.

## Examples test.cpp

The tests `test`:

```cpp
Test Start!
class ArrayList
After adding 5 elements:
10 20 30 40 50
After inserting 25 at index 2:
10 20 25 30 40 50
After setting index 3 to 35:
10 20 25 35 40 50
Removed element: 25
After removing element at index 2:
10 20 35 40 50
Removed element: 35
After removing element at index 2:
10 20 40 50
Removed element: 40
After removing element at index 2:
10 20 50
Current size: 3
Current capacity: 12
Removed element: 0
After removing element at index 3:
10 20 50
Removed element: 50
After removing element at index 2:
10 20
Current size: 2
Current capacity: 4
Test Stop!
```