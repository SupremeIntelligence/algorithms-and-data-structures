# 0.5. Breadth-First Search (BFS) Vertex Labeling

## English version

### Problem

Given a directed graph represented by an **adjacency matrix**, perform **breadth-first search (BFS)**. When there is ambiguity in choosing the next vertex, always select the vertex with the smaller number. Each vertex receives a **label** when it is first visited (labels start from 1). Determine the label of each vertex after BFS traversal.

### Input

File `input.txt`:

- The first line contains an integer `n` — the number of vertices (1 ≤ n ≤ 100).  
- The next `n` lines contain `n` numbers each — the adjacency matrix of the graph. Each number is 0 or 1.  
- The diagonal elements are all 0.  

### Output

File `output.txt`:

- `n` integers — the label assigned to each vertex in order from vertex 1 to vertex `n`.

### Constraints

- Time limit: 1 second  
- Memory limit: 256 MB

---

## Русская версия

### Условие

Для ориентированного графа, заданного **матрицей смежности**, выполните **поиск в ширину (BFS)**. При неоднозначности выбора следующей вершины всегда выбирайте вершину с меньшим номером. Каждой вершине присваивается **метка** в момент её первого посещения (нумерация меток начинается с 1). Определите метку каждой вершины после BFS.

### Входные данные

Файл `input.txt`:

- Первая строка содержит число `n` — количество вершин (1 ≤ n ≤ 100).  
- Далее `n` строк по `n` чисел — матрица смежности графа (0 или 1).  
- Главная диагональ содержит только нули.  

### Выходные данные

Файл `output.txt`:

- `n` чисел — метки вершин в порядке от 1 до `n`.

### Ограничения

- Время: 1 секунда  
- Память: 256 МБ