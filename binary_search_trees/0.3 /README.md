# 0.3 Checking the binary tree for BST

## English version

### Problem

You are given a **binary tree**. Determine if it is a **binary search tree (BST)**.

For this problem, duplicate keys are allowed. A tree is a BST if, for each node `x`:

- All keys in the **left subtree** of `x` are **less than** the key of `x`.
- All keys in the **right subtree** of `x` are **greater than or equal** to the key of `x`.

### Input

`bst.in` format:

1. First line: an integer `n` — number of nodes in the tree (`1 ≤ n ≤ 8*10^5`).
2. Second line: integer `m` — value of the root node.
3. Next `n-1` lines: three values per line:  
   - `value` — value of the node  
   - `parentIndex` — line number of parent node (0-based, always less than current line)  
   - `side` — `'L'` for left child, `'R'` for right child

It is guaranteed that the input represents a valid binary tree.

### Output

`bst.out` must contain one line:  

- `YES` if the tree is a BST  
- `NO` otherwise

---

# 0.3 Проверка бинарного дерева на BST

## Русская версия

### Условие

Задано бинарное дерево. Нужно проверить, является ли оно **бинарным деревом поиска (БПД)**.

Дерево может содержать вершины с одинаковыми ключами. Для каждой вершины `x` должно выполняться:

- все ключи в левом поддереве меньше ключа вершины
- все ключи в правом поддереве больше либо равны ключу вершины

### Входные данные

Файл `bst.in`:

1. Первая строка: число `n` — количество вершин (`1 ≤ n ≤ 8*10^5`)  
2. Вторая строка: число `m` — значение корневой вершины  
3. Последующие `n-1` строк: три значения `value parentIndex side`  
   - `value` — значение вершины  
   - `parentIndex` — индекс родителя (нумерация строк с нуля)  
   - `side` — `'L'` или `'R'`

Гарантируется корректная бинарная структура дерева.

### Выходные данные

Файл `bst.out` содержит `YES`, если дерево является БПД, иначе `NO`.

### Ограничения

- Время: **1 секунда**  
- Память: **64 МБ**