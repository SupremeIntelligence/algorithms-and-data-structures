# 0.7 Strictly Increasing Contiguous Subsequence

## English version

### Problem
Given a numerical sequence \(A\) of length \(n\), remove the **minimum number of elements** so that the remaining elements form a **strictly increasing subsequence**.  
The algorithm should have a time complexity of \(O(n \log n)\).

> Note: "Strictly increasing" means that each next element of the subsequence is **strictly greater** than the previous one.

### Input
- The input file `input.txt` contains:  
  - First line: integer \(n\) (1 ≤ n ≤ 700,000) — the number of elements in the sequence.  
  - Second line: \(n\) integers separated by spaces — the sequence \(A\) (each |A_i| ≤ 10^9).

### Output
- A single integer — the length of the strictly increasing subsequence.

### Constraints
- Time limit: 1–5 seconds  
- Memory limit: not specified  

---

# 0.7 Строго возрастающая без разрывов подпоследовательность

## Русская версия

### Условие
Дана числовая последовательность \(A\) из \(n\) элементов.  
Необходимо вычеркнуть **минимальное число элементов**, чтобы оставшиеся элементы образовали **строго возрастающую подпоследовательность**.  
Алгоритм должен иметь трудоёмкость \(O(n \log n)\).

> Замечание: "Строго возрастающая" означает, что каждый следующий элемент подпоследовательности **строго больше** предыдущего.

### Входные данные
Файл `input.txt` содержит:  
- Первая строка: целое число \(n\) (1 ≤ n ≤ 700 000) — количество элементов последовательности.  
- Вторая строка: \(n\) целых чисел через пробел — элементы последовательности \(A\) (каждое |A_i| ≤ 1 000 000 000).

### Выходные данные
- Одно число — длина строго возрастающей подпоследовательности.

### Ограничения
- Ограничение по времени: от 1 до 5 секунд  
- Ограничение по памяти: не указано