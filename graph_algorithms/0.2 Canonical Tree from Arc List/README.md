# 0.2. Canonical Form of Rooted Tree

## English version

### Problem

Given a **rooted tree** represented as a directed graph with vertices numbered from 1 to n (edges directed from root to leaves), output the **canonical representation** of the tree.

The canonical representation is an array `P[1..n]` where:  
- `P[i]` is the parent of vertex `i`.  
- If vertex `i` is the root, `P[i] = 0`.

### Input

File `input.txt`:

- First line: integer `n` — number of vertices (1 ≤ n ≤ 100000).  
- Next `n-1` lines: directed edges `u v` (1 ≤ u, v ≤ n) indicating an edge from `u` to `v`.

### Output

File `output.txt`:

- n integers `P[1] P[2] ... P[n]` — canonical parent array.

### Constraints

- 1 ≤ n ≤ 100000  
- The input graph is guaranteed to be a rooted tree.

---

## Русская версия

### Условие

Дан ориентированный граф, представляющий **корневое дерево** с вершинами от 1 до n. Дуги направлены от корня к листьям. Необходимо вывести **каноническое представление** дерева.

Каноническое представление — массив `P[1..n]`, где:  
- `P[i]` — родитель вершины `i`.  
- Если вершина `i` является корнем, `P[i] = 0`.

### Входные данные

Файл `input.txt`:

- Первая строка: число `n` — количество вершин (1 ≤ n ≤ 100000).  
- Следующие `n-1` строк: дуги `u v`, где `u` — родитель, `v` — ребёнок (1 ≤ u, v ≤ n).

### Выходные данные

Файл `output.txt`:

- n чисел — элементы массива `P[1..n]`.

### Ограничения

- 1 ≤ n ≤ 100000  
- Гарантируется, что граф является корректным корневым деревом.