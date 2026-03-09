# 0.1 Бинарный поиск

## English version

### Problem

Implement **binary search** on an array of numbers sorted in non-decreasing order. Do **not** use built-in binary search functions from standard libraries.  

For each query, return whether the number exists in the array, the index of the first element **≥ x**, and the index of the first element **> x**.

### Input

Standard input format:

1. First line: integer `n` — number of elements in the array (`0 ≤ n ≤ 3·10^5`)  
2. Second line: `n` integers — the array elements (sorted in non-decreasing order, values in `[-2^31, 2^31-1]`)  
3. Third line: integer `k` — number of queries (`0 ≤ k ≤ 3·10^5`)  
4. Fourth line: `k` integers — queries (values in `[-2^31, 2^31-1]`)  

### Output

Standard output:  

For each query `x`, print a line with three numbers `b l r`:  

- `b = 1` if `x` exists in the array, `0` otherwise  
- `l` — index of the first element **≥ x** (0-based)  
- `r` — index of the first element **> x** (0-based)  

If there is no such element, return `n` as the index.  

---

# 0.1 Binary Search

## Русская версия

### Условие

Реализуйте **бинарный поиск** на массиве чисел, отсортированном по неубыванию. Готовые функции бинарного поиска из стандартной библиотеки использовать нельзя.  

Для каждого запроса нужно вывести, есть ли число в массиве, индекс первого элемента, **большего или равного** числу, и индекс первого элемента, **большего** числа.  

### Входные данные

Стандартный ввод:

1. Первая строка: `n` — количество элементов массива (`0 ≤ n ≤ 3·10^5`)  
2. Вторая строка: `n` чисел — элементы массива (отсортированы по неубыванию, диапазон значений `[-2^31, 2^31-1]`)  
3. Третья строка: `k` — количество запросов (`0 ≤ k ≤ 3·10^5`)  
4. Четвёртая строка: `k` чисел — запросы (значения в диапазоне `[-2^31, 2^31-1]`)  

### Выходные данные

Стандартный вывод:  

Для каждого числа `x` в отдельной строке три числа `b l r`:  

- `b = 1`, если `x` есть в массиве, иначе `0`  
- `l` — индекс первого элемента **≥ x**  
- `r` — индекс первого элемента **> x**  

Если подходящих элементов нет, возвращаем `n`.  

### Ограничения

- Время: **3 секунды**  
- Память: **256 МБ**