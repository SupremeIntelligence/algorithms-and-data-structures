# 0.10 Хеш-таблица

## English version

### Problem

You are given a hash table with \(m\) slots (numbered from 0 to \(m-1\)) using **open addressing** with linear probing.  

The hash function is:

\[
h(x, i) = ((x \bmod m) + c \cdot i) \bmod m
\]

where \(x\) is the key, \(i\) is the probe number (starting from 0), and \(c\) is a constant.  

You are given a sequence of \(n\) keys inserted sequentially into the table. If a key is already present, it is not inserted again.  

Determine the final content of each cell of the hash table.

### Input

File `input.txt`:

1. First line: three integers \(m, c, n\) — table size, linear probing constant, and number of keys (\(2 \le m \le 10000, 1 \le c \le m-1, 0 \le n \le 10000\))  
   - \(c\) is coprime with \(m\)  
2. Next \(n\) lines: each line contains a key to insert (\(0 \le \text{key} \le 10^9\))  
   - Keys may repeat  
   - It is guaranteed that there is enough space to insert all **unique** keys

### Output

File `output.txt`:

- Exactly \(m\) integers: the \(i\)-th integer describes the content of the \(i\)-th cell (0-based).  
- If the cell is empty, output `-1`; otherwise output the key stored in it.

### Constraints

- Time limit: **1 second**  
- Memory limit: **256 MB**

---

# 0.10 Hash table with linear probing

## Русская версия

### Условие

Дана хеш-таблица на \(m\) ячеек (от 0 до \(m-1\)) с методом **открытой адресации** и линейным пробированием.  

Функция хеширования:

\[
h(x, i) = ((x \bmod m) + c \cdot i) \bmod m
\]

где \(x\) — ключ, \(i\) — номер попытки (начиная с нуля), \(c\) — константа.  

Последовательно вставляются \(n\) ключей. Если ключ уже есть, повторное добавление не происходит.  

Определите, какие ключи находятся в каждой ячейке таблицы после всех вставок.

### Входные данные

Файл `input.txt`:

1. Первая строка: три числа \(m, c, n\) — размер таблицы, константа для линейного пробирования, количество ключей (\(2 \le m \le 10000, 1 \le c \le m-1, 0 \le n \le 10000\))  
   - \(c\) взаимно просто с \(m\)  
2. Следующие \(n\) строк: ключи для вставки (\(0 \le \text{ключ} \le 10^9\))  
   - Ключи могут повторяться  
   - Гарантируется, что места достаточно для всех уникальных ключей

### Выходные данные

Файл `output.txt`:

- Ровно \(m\) чисел: \(i\)-е число — содержимое ячейки с индексом \(i\)  
- Если ячейка пуста, выводится `-1`, иначе выводится ключ

### Ограничения

- Время: **1 секунда**  
- Память: **256 МБ**

---

**Примечание:**  
Код реализует хеш-таблицу с линейным пробированием и проверкой на дубликаты. Каждое добавление выполняется за \(O(m)\) в худшем случае, но гарантируется достаточный размер таблицы для всех уникальных ключей.