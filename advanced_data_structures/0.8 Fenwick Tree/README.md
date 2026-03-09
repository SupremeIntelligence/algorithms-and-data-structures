# 0.8 Задача о сумме

## English version

### Problem

You are given a sequence of numbers \(A\) of length \(n\):  
\[
a_0, a_1, a_2, \dots, a_{n-1}
\]  

There are two types of queries:

1. **Modification query**: Given an index \(i\) and a number \(x\), add \(x\) to the element \(a_i\).  
2. **Sum query**: Given a range \([l, r)\), compute the sum of elements in that half-open interval:  
\[
a_l + a_{l+1} + \dots + a_{r-1}
\]

### Input

Standard input:

1. First line: integer \(n\) — the number of elements in the array (\(1 \le n \le 3\cdot 10^5\))  
2. Second line: \(n\) integers \(a_i\) (\(-10^9 \le a_i \le 10^9\))  
3. Third line: integer \(q\) — number of queries (\(1 \le q \le 3\cdot 10^5\))  
4. Next \(q\) lines: each query is either:  
   - `Add i x` — add \(x\) to element \(a_i\) (\(0 \le i < n\))  
   - `FindSum l r` — output the sum of elements in \([l, r)\) (\(0 \le l < r \le n\))  

### Output

Standard output:  

For each `FindSum` query, print a single line containing the sum of elements in the specified range.

### Constraints

- Time limit: **2 seconds**  
- Memory limit: **256 MB**

---

# 0.8 Сумма на отрезке с модификациями

## Русская версия

### Условие

Дан массив чисел \(A\) длины \(n\) с нулевой индексацией:  
\[
a_0, a_1, a_2, \dots, a_{n-1}
\]  

Поступают два типа запросов:

1. **Запрос модификации**: прибавить число \(x\) к элементу с индексом \(i\).  
2. **Запрос суммы**: вычислить сумму элементов на полуинтервале \([l, r)\):  
\[
a_l + a_{l+1} + \dots + a_{r-1}
\]

### Входные данные

Стандартный ввод:

1. Первая строка: число \(n\) — длина массива (\(1 \le n \le 300000\))  
2. Вторая строка: \(n\) чисел \(a_i\) (\(-10^9 \le a_i \le 10^9\))  
3. Третья строка: число \(q\) — количество запросов (\(1 \le q \le 300000\))  
4. Следующие \(q\) строк: каждый запрос либо:  
   - `Add i x` — прибавить \(x\) к \(a_i\) (\(0 \le i < n\))  
   - `FindSum l r` — вывести сумму элементов на полуинтервале \([l, r)\) (\(0 \le l < r \le n\))  

### Выходные данные

Стандартный вывод:  

Для каждого запроса `FindSum` выведите сумму элементов в указанном полуинтервале в отдельной строке.

### Ограничения

- Время: **2 секунды**  
- Память: **256 МБ**

---

**Примечание:**  
Код использует **дерево Фенвика (Fenwick Tree)** для эффективного выполнения операций `Add` и `FindSum` за \(O(\log n)\) на запрос.