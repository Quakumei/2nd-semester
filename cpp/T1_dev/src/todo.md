[ ] - fix:

````
    Input:
    ```
ELLIPSE 0.0 0.0 1.0 2.0
ELLIPSE 0.5 1.0 2.0 1.0
ELLIPSE 0.0 0.0 -1.0 1.0
ELLIPSE 0.0 0.0 0.0 1.0
ELLIPSE 0.0 0.0 1.0 0.0
ELLIPSE 0.0 0.0 1.0 -1.0
SCALE 0.0 0.0 2.0
    ```
    Output:
    ```
12.6 -2.0 -1.0 2.0 1.0 -0.5 -1.0 1.5 3.0
50.3 -4.0 -2.0 4.0 2.0 -2.5 -5.0 1.5 3.0
    ```
    Error Output:
    ```
BAD SHAPE ARGUMENTS, SKIPPED.
    ```
    Expected:
    ```
	12.6 -2.0 -1.0 2.0 1.0 -0.5 -1.0 1.5 3.0
	50.3 -4.0 -2.0 4.0 2.0 -1.0 -2.0 3.0 6.0
````
