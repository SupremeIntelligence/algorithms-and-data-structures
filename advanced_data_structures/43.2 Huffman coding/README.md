# 43.2 Huffman coding (advanced version)

## English version

### Problem

You are given frequencies of \(n\) symbols. Build the **Huffman code** and compute the total length of the text encoded using this code.  

Huffman coding minimizes the total length by assigning shorter codes to more frequent symbols. The algorithm is as follows:

1. Start with all symbols as leaves of the tree, each labeled with its frequency \(p_i\).  
2. Repeatedly select two nodes with the smallest labels, create a new parent node with label equal to the sum of the two, and make the two nodes its children.  
3. Continue until there is only one active node — the root.  

The code for each symbol is determined by the path from the root to the leaf (0 for one branch, 1 for the other). The total encoded length is the sum of frequency × code length for all symbols.

### Input

File `huffman.in`:

1. First line: integer \(n\) — number of symbols (\(1 \le n \le 2{,}500{,}000\))  
2. Next \(n\) lines: integer \(p_i\) — frequency of the \(i\)-th symbol (\(1 \le p_i \le 10^9\))

### Output

File `huffman.out`:

- One integer — total length of the text encoded with Huffman coding.

### Constraints

- Time limit: **0.5 seconds**  
- Memory limit: **256 MB**

---

# 43.2 Кодирование Хаффмана (сложная версия)

## Русская версия

### Условие

Даны частоты появления \(n\) символов. Постройте **код Хаффмана** и вычислите суммарную длину текста после кодирования.  

Код Хаффмана минимизирует длину текста за счёт того, что часто встречающиеся символы кодируются меньшим числом бит. Алгоритм:

1. Все символы считаются листьями дерева, каждая вершина помечена частотой \(p_i\).  
2. Пока есть больше одной активной вершины: выбираем две с наименьшими частотами, создаём родителя с суммой частот и делаем их детьми.  
3. Последняя вершина — корень дерева.  

Код каждого символа строится как путь от корня к листу (0 для одного потомка, 1 для другого). Суммарная длина — это \(\sum_i p_i \cdot \text{длина кода}_i\).

### Входные данные

Файл `huffman.in`:

1. Первая строка: число \(n\) — количество символов (\(1 \le n \le 2{,}500{,}000\))  
2. Следующие \(n\) строк: число \(p_i\) — частота \(i\)-го символа (\(1 \le p_i \le 10^9\))

### Выходные данные

Файл `huffman.out`:

- Одно число — суммарная длина текста после кодирования методом Хаффмана.

### Ограничения

- Время: **0.5 секунды**  
- Память: **256 МБ**

---

**Примечание:**  
Код использует min-heap для построения дерева Хаффмана и рекурсивный обход дерева для вычисления суммарной длины закодированного текста.