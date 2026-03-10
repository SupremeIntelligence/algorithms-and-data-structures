# 0.5 Longest Common Subsequence (LCS)

## English version

### Problem
Given **two sequences** **A** and **B** of length **n**, find the **longest common subsequence** (LCS) and the sequences of indices in **A** and **B** that form this LCS.  

If multiple solutions exist, **any valid LCS and corresponding indices** can be output.

### Input
- First line: integer **n** $(1 \le n \le 1000)$ — the length of the sequences.  
- Second line: **n** integers — elements of sequence **A** ($1 \le A_i \le 1000$).  
- Third line: **n** integers — elements of sequence **B** ($1 \le B_i \le 1000$).

### Output
- First line: integer **k** — the length of the LCS.  
- Second line: **k** integers — indices in **A** corresponding to the LCS (1-based or 0-based depending on implementation).  
- Third line: **k** integers — indices in **B** corresponding to the LCS.  

### Constraints
- Time limit: **2 seconds**  
- Memory limit: **64 MB**  

---

# 0.5 Наибольшая общая подпоследовательность (LCS)

## Русская версия

### Условие
Даны **две последовательности** **A** и **B** длины **n**.  
Необходимо найти **наибольшую общую подпоследовательность** (LCS) и последовательности индексов в **A** и **B**, которые формируют эту LCS.  

Если решений несколько, можно вывести **любое корректное решение**.

### Входные данные
- Первая строка: целое число **n** **(1 \le n \le 1000)** — длина последовательностей.  
- Вторая строка: **n** целых чисел — элементы последовательности **A** ($1 \le A_i \le 1000$).  
- Третья строка: **n** целых чисел — элементы последовательности **B** ($1 \le B_i \le 1000$).

### Выходные данные
- Первая строка: число **k** — длина LCS.  
- Вторая строка: **k** чисел — индексы элементов LCS в **A** (0- или 1-индексация).  
- Третья строка: **k** чисел — индексы элементов LCS в **B**.

### Ограничения
- Ограничение по времени: **2 секунды**  
- Ограничение по памяти: **64 МБ**