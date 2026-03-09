# 0.2. Delete from BST

## English version

### Problem

Given a sequence of keys, build a **binary search tree (BST)**. Remove a given key (using the "right deletion" strategy) if it exists in the tree. After deletion, perform a **pre-order (straight left) traversal** of the tree and output the sequence of keys.

### Input

File `input.txt`:

1. First line: integer — the key to remove.  
2. Second line: empty.  
3. Subsequent lines: a sequence of integers — keys of tree nodes in the order of insertion (one per line). The tree contains at least two nodes.  

**Note:** All keys are unique. Duplicate insertions are ignored.

### Output

File `output.txt`:

- Sequence of keys obtained by **pre-order traversal** after deletion (one key per line).

### Constraints

- Time limit: **1 second**  
- Memory limit: **256 MB**

---

# 0.2. Удалить из дерева

## Русская версия

### Условие

По набору ключей постройте **бинарное поисковое дерево (BST)**. Удалите из него ключ с использованием **правого удаления**, если он есть в дереве. После удаления выполните **прямой левый обход** дерева.

### Входные данные

Файл `input.txt`:

1. Первая строка: ключ, который нужно удалить.  
2. Вторая строка пустая.  
3. Остальные строки: последовательность чисел — ключи вершин в порядке вставки (по одному числу на строку). Дерево содержит хотя бы две вершины.  

**Примечание:** Ключи уникальны, повторное добавление игнорируется.

### Выходные данные

Файл `output.txt`:

- Последовательность ключей после удаления, полученная **прямым левым обходом** (pre-order), по одному числу на строку.

### Ограничения

- Время: **1 секунда**  
- Память: **256 МБ**

---

**Примечание:**  
Код реализует BST с классом `Tree`, поддерживает вставку и удаление, а также pre-order обход. Удаление учитывает все случаи: лист, узел с одним поддеревом или узел с двумя поддеревьями (используется метод поиска минимального элемента правого поддерева для замены).