# 0.6 Разрушение дорог (простая версия)

## English version

### Problem

In Berland, there are `n` cities connected by `m` roads. Initially, the graph is **connected** — there is a path between any pair of cities.  

There are `q` earthquakes, each destroying **exactly one road**. After each earthquake, determine if the resulting graph remains connected. Destroyed roads **do not rebuild**.  

### Input

File `input.txt` format:

1. First line: three integers `n`, `m`, `q` (`1 ≤ n, m, q ≤ 100000`, `2 ≤ n`) — number of cities, roads, and earthquakes.  
2. Next `m` lines: two integers `u`, `v` (`1 ≤ u, v ≤ n`, `u ≠ v`) — cities connected by a road. There is at most one road between any pair.  
3. Next `q` lines: integer `x_i` (`1 ≤ x_i ≤ m`) — the road destroyed in the `i`-th earthquake. Each road is destroyed at most once.  

### Output

File `output.txt`:  

A string of length `q` consisting of `0` and `1`. The `i`-th character is:

- `1` if the graph is connected after the `i`-th earthquake  
- `0` otherwise  

---

# 0.6 Road Destruction (simple version)

## Русская версия

### Условие

В Берляндии `n` городов и `m` дорог. Гарантируется, что исходный граф связный.  

Происходит `q` землетрясений, каждое разрушает **ровно одну дорогу**. После каждого землетрясения нужно определить, остался ли граф связным. Разрушенные дороги не восстанавливаются.  

### Входные данные

Файл `input.txt`:

1. Первая строка: `n m q` — количество городов, дорог и землетрясений (`1 ≤ n, m, q ≤ 100000`, `2 ≤ n`)  
2. Следующие `m` строк: `u v` — номера городов, соединённых дорогой (`1 ≤ u, v ≤ n`, `u ≠ v`)  
3. Следующие `q` строк: `x_i` — номера дорог, разрушаемых в i-ом землетрясении (`1 ≤ x_i ≤ m`), каждая дорога разрушается не более одного раза  

### Выходные данные

Файл `output.txt`:  

Строка длины `q` из символов `0` и `1`.  

- `1` — если после i-го землетрясения граф остался связным  
- `0` — если граф перестал быть связным  

### Ограничения

- Время: **1 секунда**  
- Память: **256 МБ**