// Ctrl + Shift + V to preview
# fill2DArray(3, 4)

**Returns:** (kolom x baris)

```
[1, 1, 1]
[4, 5, 2]
[4, 6, 2]
[3, 3, 2]
```

**Index mapping:**

| Index           | Value |
|-----------------|-------|
| [0,0][0,1][0,2] | 1 1 1 |
| [1,0][1,1][1,2] | 4 5 2 |
| [2,0][2,1][2,2] | 4 6 2 |
| [3,0][3,1][3,2] | 3 3 2 |

---

## Variables

```cpp
int top = 0;
int left = 0;
int bottom = m-1 = 3;
int right = n-1 = 2;
int count = 1;
```

**Loop condition:** `top <= bottom && left <= right`

---

## Spiral Steps

### Step 1 - Fill top row (left to right)

```cpp
for (int i = left; i <= right; i++) {
    graph[0][0] = 1;
    graph[0][1] = 1;
    graph[0][2] = 1;

    // second loop
    graph[1][1] = 5;
}
top++; count++;
// top = 1
// second loop top = 2
```

### Step 2 - Fill right column (top to bottom)

```cpp
for (int i = top; i <= bottom; i++) {
    graph[i][right] = count;
    grpah[1][2] = 2;
    graph[2][2] = 2;
    graph[3][2] = 2;
    graph[4][2] = 2;

    // second loop
    graph[2][1] = 6;
}
right--; count++;
// right = 1
```

### Step 3 - Fill bottom row (left to right)

```cpp
for (int i = left; i <= right; i++) {
    graph[bottom][i] = count;
    graph[3][0] = 3;
    graph[3][1] = 3;
}
bottom--; count++;
// bottom = 2
```

### Step 4 - Fill left column (bottom to top)

```cpp
for (int i = bottom; i >= top; i--) {
    graph[i][left] = count;
    graph[2][0] = 4;
    graph[1][0] = 4;
}
left++; count++;
// left = 1
```
