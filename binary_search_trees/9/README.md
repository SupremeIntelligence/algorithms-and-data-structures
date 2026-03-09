# 9. BST Half-Path Node Deletion

## English version

### Problem

Given a sequence of keys, build a **binary search tree (BST)**. Find the nodes through which the **longest half-paths** pass. Delete (using "right deletion") the node whose key is **second in value** among these nodes.  

After deletion, perform a **pre-order traversal** of the resulting tree and output the keys.

### Input

File `in.txt`:  

- A sequence of integers — keys of tree nodes in the order of insertion (one per line).  
- The tree contains at least two nodes.

### Output

File `out.txt`:  

- Sequence of keys after deletion obtained by **pre-order traversal** (one key per line).

### Constraints

- Time limit: 1 second  
- Memory limit: none

---

# Задача 9. Удаление второй вершины наибольшего полупути

## Русская версия

### Условие

По последовательности ключей построить **бинарное поисковое дерево (BST)**. Найти вершины, через которые проходят **наибольшие полупути**. Удалить с помощью **правого удаления** вершину, ключ которой является **вторым по значению** среди этих вершин.  

После удаления выполнить **прямой левый обход** дерева и вывести последовательность ключей.

### Входные данные

Файл `in.txt`:

- Последовательность чисел — ключи вершин дерева в порядке вставки (по одному числу на строку).  
- В дереве не менее двух вершин.

### Выходные данные

Файл `out.txt`:

- Последовательность ключей после удаления, полученная **прямым левым обходом** (по одному числу на строку).

### Ограничения

- Время: 1 секунда  
- Память: нет ограничений

---

**Примечание:**  
Код реализует BST с классом `Tree`, поддерживает вставку, вычисление высот поддеревьев, поиск корней наибольших полупутей, выбор второй вершины по значению и удаление с использованием метода **правого удаления**, а также pre-order обход для вывода.