# Задача 14. Второй по длине маршрут / Second Shortest Path

## English version

### Problem

Given **N cities** numbered 1 to N and **M directed roads**, each with a positive length, find the **second shortest path** between cities A and B.  

The path can pass through the same city multiple times. If multiple second shortest paths exist, output any of them.

### Input

File `input.in`:  

- First line: integers `N` and `M` (1 ≤ N ≤ 10,000, 1 ≤ M ≤ 100,000)  
- Next M lines: triples `i j k` describing a road from city `i` to city `j` of length `k`.  
- Last line: integers `A` and `B` — start and end cities.

### Output

File `output.out`:  

- First line: length of the second shortest path between A and B.  
- Second line: sequence of cities in this path (space-separated).  

### Constraints

- Time limit: 1 second  
- Memory limit: 256 MB  

---

## Русская версия

### Краткое название

**Второй по длине маршрут**

### Условие

Дано N городов с номерами от 1 до N и сеть из M дорог с **односторонним движением**. Каждая дорога задаётся тройкой (i, j, k), где i — город отправления, j — город назначения, k — длина дороги.  

Необходимо найти маршрут, который является **вторым по длине** среди всех ориентированных маршрутов между городами A и B. Если таких маршрутов несколько, можно вывести любой. Маршрут может проходить через города несколько раз.

### Входные данные

Файл `input.in`:

- Первая строка: целые числа `N` и `M` (1 ≤ N ≤ 10 000, 1 ≤ M ≤ 100 000)  
- Следующие M строк: три числа `i j k`, описание дороги.  
- Последняя строка: `A B` — города начала и конца маршрута.

### Выходные данные

Файл `output.out`:

- Первая строка: длина второго по длине маршрута.  
- Вторая строка: последовательность городов в этом маршруте (через пробел).

### Ограничения

- Время: 1 секунда  
- Память: 256 МБ  