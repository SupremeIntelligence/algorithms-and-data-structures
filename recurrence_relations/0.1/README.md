# 0.1 Frog Path

## English version

### Problem
A frog jumps along lily pads arranged in a straight line across a very long and narrow pond.  
The frog starts on the **first lily pad** and wants to reach the **last one**.

However, the frog is stubborn and only agrees to jump forward:
- over **one lily pad** (`i → i+2`)
- over **two lily pads** (`i → i+3`)

Some lily pads contain mosquitoes.  
The `i-th` lily pad has `a[i]` mosquitoes.  
Whenever the frog lands on a lily pad, it eats **all mosquitoes on it**.

The frog wants to choose a path that allows it to eat the **maximum possible number of mosquitoes**.

Your task is to determine:
1. The **maximum number of mosquitoes** the frog can eat.
2. The **sequence of lily pads** the frog should visit.

If there are multiple optimal solutions, output **any** of them.

If the frog **cannot reach the last lily pad**, output `-1`.

### Input
- The first line contains an integer `n` — the number of lily pads  
  (`1 ≤ n ≤ 100000`).

- The second line contains `n` integers  
  `a[i]` — the number of mosquitoes on the `i-th` lily pad.

All numbers satisfy:
`0 ≤ a[i] ≤ 1000`

### Output
- The first line should contain the **maximum number of mosquitoes** the frog can eat.
- The second line should contain the **indices of the visited lily pads** in increasing order.

If reaching the last lily pad is impossible, output -1.

### Constraints
- Time limit: **1 second**
- Memory limit: **256 MB**

---

# 0.1 Путь лягушки

## Русская версия

### Условие
В одном очень длинном и узком пруду по кувшинкам прыгает лягушка.  
Кувшинки расположены **в один ряд**.

Лягушка начинает с **первой кувшинки** и хочет добраться до **последней**.

Однако из-за своего характера лягушка может прыгать только вперёд:
- **через одну кувшинку** (`i → i+2`)
- **через две кувшинки** (`i → i+3`)

На некоторых кувшинках сидят комарики.  
На `i`-й кувшинке находится `a[i]` комаров.

Когда лягушка приземляется на кувшинку, она **съедает всех комаров**, которые на ней находятся.

Лягушка хочет выбрать такой маршрут, чтобы съесть **максимальное количество комаров**.

Необходимо определить:
1. **Максимальное количество комаров**, которое может съесть лягушка.
2. **Последовательность кувшинок**, которые она должна посетить.

Если существует несколько решений, можно вывести **любое**.

Если лягушка **не может добраться до последней кувшинки**, необходимо вывести `-1`.

### Входные данные
- Первая строка содержит число `n` — количество кувшинок  
  (`1 ≤ n ≤ 100000`).

- Вторая строка содержит `n` целых чисел  
  `a[i]` — количество комаров на `i`-й кувшинке.

Ограничения:
`0 ≤ a[i] ≤ 1000`

### Выходные данные
- В первой строке вывести **максимальное количество комаров**.
- Во второй строке вывести **номера посещённых кувшинок** в возрастающем порядке.

Если добраться до последней кувшинки невозможно, вывести -1.

### Ограничения
- Ограничение по времени: **1 секунда**
- Ограничение по памяти: **256 МБ**