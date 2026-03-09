# 0.3. Build Adjacency List

## English version

### Problem

Given an **undirected graph** represented by a **list of edges**, construct the **adjacency list** of the graph. It is guaranteed that there are **no loops or multiple edges**.

### Input

File `input.txt`:

- The first line contains two integers `n` and `m` — the number of vertices (1 ≤ n ≤ 100,000) and the number of edges (0 ≤ m ≤ 200,000).  
- Vertices are numbered from 1 to n.  
- The next `m` lines contain pairs of integers `u` and `v` (1 ≤ u, v ≤ n, u ≠ v) describing edges.

### Output

File `output.txt`:

- `n` lines, one for each vertex from 1 to n.  
- Each line contains: first the number of neighbors of vertex `i`, then the numbers of its neighboring vertices (in any order).

### Constraints

- Time limit: 1 second  
- Memory limit: 128 MB

---

## Русская версия

### Условие

Дан **неориентированный граф**, заданный списком рёбер. Постройте **список смежности** графа. Гарантируется, что **нет петель и кратных рёбер**.

### Входные данные

Файл `input.txt`:

- Первая строка содержит два числа `n` и `m` — количество вершин (1 ≤ n ≤ 100,000) и количество рёбер (0 ≤ m ≤ 200,000).  
- Вершины пронумерованы от 1 до n.  
- Далее `m` строк, каждая с двумя числами `u` и `v` (1 ≤ u, v ≤ n, u ≠ v) — описание рёбер.

### Выходные данные

Файл `output.txt`:

- `n` строк, по одной для каждой вершины от 1 до n.  
- Каждая строка: сначала число соседей вершины `i`, затем номера соседних вершин (в произвольном порядке).

### Ограничения

- Время: 1 секунда  
- Память: 128 МБ