# 0.4 Matrix Multiplication Order

## English version

### Problem
Given a sequence of **s matrices** $A_1, A_2, \dots, A_s$, determine the order of multiplication that **minimizes the total number of scalar multiplications**.

Matrix multiplication is defined as usual: multiplying a $k \times m$ matrix with an $m \times n$ matrix requires $k \cdot m \cdot n$ atomic multiplications.  

Since matrix multiplication is associative, the final matrix does not depend on the order, but the total number of operations does.

### Input
- The first line contains the integer **s** — the number of matrices $2 \le s \le 100$.  
- Each of the next **s lines** contains two integers $n_i$ and $m_i$ — the number of rows and columns of the **i**-th matrix ($1 \le n_i, m_i \le 100$).  
  It is guaranteed that $m_i = n_{i+1}$ for all valid **i**.

The input is read from `input.txt`.

### Output
Output a single integer — the **minimum number of scalar multiplications** required to compute the product of the matrices.

### Constraints
- Time limit: **1 second**  
- Memory limit: **256 MB**  

---

# 0.4 Порядок перемножения матриц

## Русская версия

### Условие
Дана последовательность из **s матриц** $A_1, A_2, \dots, A_s$.  
Необходимо определить порядок их перемножения, чтобы **суммарное число атомарных операций умножения** было минимальным.

Перемножение двух матриц $k \times m$ и $m \times n$ требует $k \cdot m \cdot n$ элементарных операций.  
Поскольку матричное умножение ассоциативно, итоговая матрица не зависит от порядка, но суммарное число операций меняется.

### Входные данные
- В первой строке указано число **s** — количество матриц ($2 \le s \le 100$).  
- В следующих **s строках** указаны два целых числа $n_i$ и $m_i$ — количество строк и столбцов i-й матрицы ($1 \le n_i, m_i \le 100$).  
  Гарантируется, что $m_i = n_{i+1}$ для всех i.

Входной файл: `input.txt`.

### Выходные данные
Выведите одно число — **минимальное количество атомарных операций умножения**, необходимое для вычисления произведения матриц.

### Ограничения
- Ограничение по времени: **1 секунда**  
- Ограничение по памяти: **256 МБ**  