# 0.6. DFS Vertex Labeling

## English version

### Problem

Given a **directed graph** represented as an adjacency matrix, perform a **depth-first search (DFS)**. When there is a choice of which vertex to visit next, always choose the vertex with the **smallest number**.  

Assign a **label** to each vertex at the moment it is visited (labels start from 1). Output the label assigned to each vertex.

### Input

File `input.txt`:

- First line: integer `n` — number of vertices (1 ≤ n ≤ 100).  
- Next `n` lines: adjacency matrix of size n×n, elements `0` or `1` separated by spaces.  
- The diagonal elements are all zero.

### Output

File `output.txt`:

- n integers: the label assigned to each vertex, in order from vertex 1 to vertex n.

### Constraints

- 1 ≤ n ≤ 100  
- Time limit: 1 second  
- Memory limit: 256 MB

---

## Русская версия

### Условие

Для **ориентированного графа**, заданного **матрицей смежности**, выполнить **поиск в глубину (DFS)**. При неоднозначности выбора следующей вершины всегда выбирается вершина с **наименьшим номером**.  

В момент посещения вершины присваивается **метка** (нумерация меток начинается с 1). Выведите метки всех вершин.

### Входные данные

Файл `input.txt`:

- Первая строка: число `n` — количество вершин (1 ≤ n ≤ 100).  
- Следующие n строк: матрица смежности размером n×n, элементы 0 или 1, разделённые пробелом.  
- Элементы главной диагонали равны нулю.

### Выходные данные

Файл `output.txt`:

- n чисел — метки вершин в порядке от 1 до n.

### Ограничения

- 1 ≤ n ≤ 100  
- Время: 1 секунда  
- Память: 256 МБ

---

**Примечание:**  
Код использует рекурсивный DFS с выбором вершины с наименьшим номером при неоднозначности. Массив `tags` хранит метки посещённых вершин.