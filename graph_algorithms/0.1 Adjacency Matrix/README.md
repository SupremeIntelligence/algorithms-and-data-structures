# 0.1. Build Adjacency Matrix

## English version

### Problem

Given an **undirected graph** represented by a **list of edges**, construct the **adjacency matrix** of the graph. It is guaranteed that there are **no loops or multiple edges**.

### Input

File `input.txt`:

- The first line contains two integers `n` and `m` — the number of vertices (1 ≤ n ≤ 100) and the number of edges (0 ≤ m ≤ n(n − 1)/2).  
- Vertices are numbered from 1 to n.  
- The next `m` lines contain pairs of integers `u` and `v` (1 ≤ u, v ≤ n, u ≠ v) describing edges.

### Output

File `output.txt`:

- `n` lines of `n` integers (0 or 1) — the adjacency matrix of the graph. Numbers in a line are separated by spaces.

### Constraints

- Time limit: 1 second  
- Memory limit: 64 MB

---

## Русская версия

### Условие

Дан **неориентированный граф**, заданный списком рёбер. Постройте **матрицу смежности** графа. Гарантируется, что **нет петель и кратных рёбер**.

### Входные данные

Файл `input.txt`:

- Первая строка содержит два числа `n` и `m` — количество вершин (1 ≤ n ≤ 100) и количество рёбер (0 ≤ m ≤ n(n − 1)/2).  
- Вершины пронумерованы от 1 до n.  
- Далее `m` строк, каждая с двумя числами `u` и `v` (1 ≤ u, v ≤ n, u ≠ v) — описание рёбер.

### Выходные данные

Файл `output.txt`:

- `n` строк по `n` чисел (0 или 1) — матрица смежности графа. Числа в строке разделяются пробелами.

### Ограничения

- Время: 1 секунда  
- Память: 64 МБ