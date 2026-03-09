# 0.7. Dijkstra's Algorithm

## English version

### Problem

Given an **undirected weighted pseudograph** with vertices numbered from 1 to n, find the **shortest path** between vertex 1 and vertex n. It is guaranteed that a path exists.

### Input

File `input.txt`:

- The first line contains two integers n and m — the number of vertices and edges (1 ≤ n ≤ 200,000, 0 ≤ m ≤ 300,000).  
- The next m lines contain three integers ui, vi, wi each — an edge between vertices ui and vi of weight wi (1 ≤ ui, vi ≤ n, 0 ≤ wi ≤ 11,111).  

### Output

File `output.txt`:

- A single integer — the length of the shortest path between vertices 1 and n.

### Constraints

- Time limit: 1 second  
- Memory limit: 64 MB  

---

## Русская версия

### Условие

Дан **неориентированный взвешенный псевдограф** с вершинами, пронумерованными от 1 до n. Требуется найти **кратчайшую цепь** между вершинами 1 и n. Гарантируется, что путь существует.

### Входные данные

Файл `input.txt`:

- Первая строка содержит два числа n и m — количество вершин и рёбер (1 ≤ n ≤ 200 000, 0 ≤ m ≤ 300 000).  
- Следующие m строк содержат три числа ui, vi, wi — ребро между вершинами ui и vi длиной wi (1 ≤ ui, vi ≤ n, 0 ≤ wi ≤ 11 111).  

### Выходные данные

Файл `output.txt`:

- Одно число — длина кратчайшей цепи между вершинами 1 и n.

### Ограничения

- Время: 1 секунда  
- Память: 64 МБ