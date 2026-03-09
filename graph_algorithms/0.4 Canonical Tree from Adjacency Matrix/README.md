# 0.4. Canonical Tree Representation (Adjacency Matrix)

## English version

### Problem

Given a **directed graph** that forms a **rooted tree**, represented by an **adjacency matrix**, output its **canonical form**. The canonical form is an array `P` of length `n`, where `pi` is the parent of vertex `i`, and `0` if vertex `i` is the root.

### Input

File `input.txt`:

- The first line contains an integer `n` — the number of vertices (1 ≤ n ≤ 100).  
- The next `n` lines contain `n` integers each — the adjacency matrix of the tree. A `1` in row `i` and column `j` indicates an edge from vertex `i` to vertex `j`, and `0` otherwise.  

### Output

File `output.txt`:

- `n` integers — the array `P` representing the parent of each vertex (0 for the root).

### Constraints

- Time limit: 1 second  
- Memory limit: 256 MB

---

## Русская версия

### Условие

Дан ориентированный граф, который является **корневым деревом**, заданный **матрицей смежности**. Выведите **канонический вид** дерева. Каноническим способом представления дерева является массив `P` длины `n`, где `pi` — отец вершины `i`, а если вершина является корнем, `pi = 0`.

### Входные данные

Файл `input.txt`:

- Первая строка содержит число `n` — количество вершин (1 ≤ n ≤ 100).  
- Далее `n` строк по `n` чисел — матрица смежности дерева. Если есть дуга из вершины `i` в вершину `j`, то соответствующий элемент равен 1, иначе 0.  

### Выходные данные

Файл `output.txt`:

- `n` чисел — массив `P`, где `pi` — отец вершины `i`, 0 для корня.

### Ограничения

- Время: 1 секунда  
- Память: 256 МБ