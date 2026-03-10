# 32. Equalities and inequalities

## English version

### Problem

Given a set of variables $x_1, x_2, \dots, x_n$ and a list of constraints of two types:

1. **Equality**: $x_i = x_j$  
2. **Inequality**: $x_i \neq x_j$ 

Determine whether it is possible to assign integer values to all variables so that all constraints are satisfied simultaneously.

### Input

File `equal-not-equal.in`:

1. First line: integers **n** and **m** — number of variables and number of constraints ($1 \le n, m \le 100\,000$)  
2. Next **m** lines: constraints in the format `xi == xj` or `xi != xj`, where `xi` and `xj` are variable names (`x` followed by a number from 1 to n).

### Output

File `equal-not-equal.out`:

- `Yes` if there exists an assignment satisfying all constraints  
- `No` otherwise

### Constraints

- Time limit: **1 second**  
- Memory limit: **256 MB**

---

# 32. Равенства и неравенства

## Русская версия

### Условие

Даны **n** переменных $x_1, x_2, \dots, x_n$ и список ограничений:

1. **Равенства**: $x_i = x_j$ 
2. **Неравенства**: $x_i \neq x_j$  

Нужно определить, возможно ли присвоить переменным целочисленные значения так, чтобы все ограничения выполнялись одновременно.

### Входные данные

Файл `equal-not-equal.in`:

1. Первая строка: числа **n** и **m** — количество переменных и ограничений ($1 \le n, m \le 100\,000$)  
2. Следующие **m** строк: ограничения в формате `xi == xj` или `xi != xj`. Переменные задаются буквой `x` и номером от 1 до n.

### Выходные данные

Файл `equal-not-equal.out`:

- `Yes`, если существует присвоение значений, удовлетворяющее всем ограничениям  
- `No`, если такого присвоения не существует

### Ограничения

- Время: **1 секунда**  
- Память: **256 МБ**