# CA (Архитектура компьютерных систем)

# Страничка семинаров ЗБ-ПИ21-1 ЗБ-ПИ21-2


## Навигация по семинарам
1.  [[конспект](01sem-asm/README.md)][[лекция](01lec-asm/README.md)] - введение в язык ассемблера

2.  [[конспект](02sem-asm/README.md)][[лекция](02lec-asm/README.md)] - продолжение языка ассемблера - сдвиги, loop, simpleio
3. [[конспект](03sem-asm/README.md)][[лекция](03lec-asm/README.md)] - язык ассемблера. Arrays, variables, lea, lea для арифметики
4. [[конспект](04sem-asm/README.md)][[лекция](04lec-asm/README.md)] - стек. Работа с asm из C/C++ и наборот. printf/scanf. Cdecl

-------
5. [создание простой операционной системы x86](https://github.com/VladimirAndropov/fa-os-practice-yabloko)

_______


6. [конспект][c] - буферизация, выравнивание
6. [конспект][c] - системные вызовы
7. [[конспект](07sem-c/README.md)][c] - динамическая память.
8. [[конспект](08sem-c/README.md)][c] - IEEE754. float. inline asm.


22. [[конспект](22sem-fs/README.md)][C++] - std::thread, std::async, std::future, std::promise, std::lock_guard
 


# План по содержанию семинаров, практических занятий 
## Программирование на языке ассемблера
Мнемоническое описание машинных команд в языке ассемблера. Способы записи мнемоник. Типы адресации в языке ассемблера. Реализация циклов и ветвлений на языке ассемблера. Структурное программирование на языке ассемблера.
## Машинный язык 
Кодировка машинных команд. Типы кодировки машинных команд. Автоматическая генерация машинного кода.
## Процесс сборки программ
Ассемблирование кода. Сборка программ. Компиляция и трансляция. Компоновка программ. Загрузка программ в оперативную память.
## Дополнительные аспекты ассемблера 
Остроконечный и тупоконечный порядок байтов. Работа с числами с плавающей запятой. Сжатие машинных команд.
## Архитектура x86
Анализ архитектуры x86. Регистры x86-совместимых процессоров. Состояние процессора в архитектуре x86. Команды архитектуры x86. Программирование для архитектуры x86.





# Примерные вопросы к контрольной работе 

1. Регистры общего назначения архитектуры x86.
2. Понятие микрокоманды. Примеры микрокоманд.
3. Компоновка программ. Оптимизация при компоновке.
4. Маскирование прерываний.
5. Своппинг (swapping) и реализация «спящего режима».
6. Организация циклов на языке ассемблера.
7. Регистры флагов в распространенных процессорных архитектурах.
8. Организация работы с памятью, имеющей неравномерное время доступа (NUMA).
9. Принципы функционирования сопроцессора.
10. Однотактный тракт данных.
# Примерные задания контрольной работы 
1. На языке ассемблера для архитектуры x86 написать подпрограмму, реализующую возведение целого числа в степень целого числа.
2. Перевести в десятичный вид число 0x0A32B415 в предположении, что порядок байтов остроконечный.
3. Определить, какая команда архитектуры x86 представлена значением 0xB805000000.
4. На языке SystemVerilog реализовать основной декодер однотактного процессора.
5. Определить, сколько тактов потребуется, чтобы выполнить следующую программу на многотактном процессоре архитектуры RISC-V:
```asm
addi s0, zero, 5
L1:
bge zero, s0, Done 
addi s0, s0, –1
j L1
Done:
```


Примерные задания для подготовки к экзамену 
1. Преобразуйте следующий ассемблерный код RISC-V в машинный код. Запишите команды в шестнадцатеричном формате.
```
    addi s3, s4, 28
    sll t1, t2, t3
    srli s3, s1, 14
    sw s9, 16(t4)
```

2. Переведите приведенные ниже инструкции условного перехода в машинный код. Адреса инструкций указаны слева от каждой из них:
```
0x0000A000 beq t4, zero, Loop
0x0000A004 ...
0x0000A008 ...
0x0000A00C Loop: ...
```

3. Расширьте набор команд RISC-V, включив в него lwpostinc (load with postincrement) – команду чтения из памяти с последующим приращением адреса. Ассемблерная инструкция lwpostinc rd, imm (rs) эквивалентна следующим двум инструкциям:
```
lw rd, 0(rs)
addi rs, rs, imm
```

4. Вычислить величину CPI (количество команд на такт для следующей программы):
```
addi s0, zero, 5
L1:
bge zero, s0, Done 
addi s0, s0, –1 
j L1
Done:
```
5. Подсистема виртуальной памяти использует реализованную аппаратно одноуровневую таблицу страниц, включающую блоки памяти SRAM и сопутствующую логику. Она поддерживает 25-битные виртуальные адреса, 22-битные физические адреса и страницы размером 64 Кбайт. В каждой записи таблицы страниц имеется бит достоверности V и бит изменения D. Чему равен размер всей таблицы в битах?

# Примерные вопросы для подготовки к экзамену 
1. Язык ассемблера. Мнемоники. Инструкции, операнды, регистры.
2. Память. Адресация памяти. База и смещение, индекс.
3. Логические инструкции. Логические маски. Установка и сброс битов.
4. Инструкции арифметического и логического сдвига.
5. Инструкции умножения. Особенности целочисленного умножения.
6. Инструкции условного перехода. Сравнение целочисленных значений.
7. Безусловные переходы. Типы операндов инструкций безусловного перехода. Ближние и дальние переходы.
8. Реализация операций выбора на языке ассемблера. Таблицы переходов.
9. Реализация циклов и повторений на языке ассемблера. Метки.
10. Представления массивов в языке ассемблера. Адресация массивов.
11. Байты и символы. Операции с байтами и символами.
12. Реализация подпрограмм на языке ассемблера. Стек вызовов. Аргументы, результаты и локальные переменные.
13. Псевдокоманды в языке ассемблера.
14. Кодировка регистровых инструкций в машинном коде.
15. Кодировка непосредственных инструкций в машинном коде.
16. Инструкции типа хранение/условный переход.
17. Инструкции типа старшие разряды константы/безусловный переход.
18. Кодирование констант в машинном коде архитектуры RISC-V.
19. Режимы адресации в машинном коде архитектуры RISC-V.
20. Карта оперативной памяти. Сегменты. Куча. 
21. Компиляция, трансляция, компоновка. Загрузка программ в память.
22. Обработка чисел с плавающей запятой. Векторные расширения.
23. Регистры общего назначения архитектуры x86.
24. Управляющие регистры архитектуры x86.
25. Основные команды архитектуры x86.
26. Кодировка машинных команд архитектуры x86.
27. Микроархитектура однотактных процессоров.
28. Микроархитектура многотактных процессоров.
29. Микроархитектура конвейерных процессоров.
30. Конфликты в конвейерных микроархитектурах и их разрешение.
31. Блоки предсказания переходов.
32. Суперскалярные процессоры. Внеочередное выполнение команд.
33. Многопоточность. Многопроцессорные архитектуры.
34. Кэш-память. Организация кэш-памяти. Многоуровневый кэш. Когерентность кэша.
35. Виртуальная память. Страничная организация памяти. Таблицы страниц.
36. Ввод/вывод общего назначения. Последовательный ввод/вывод.
37. Ввод/вывод с отображением в память. Виртуализация ввода/вывода.
# Пример экзаменационного билета
- Задание 1. Микроархитектура многотактных процессоров. (20 баллов)
- Задание 2. 	Кодировка регистровых инструкций в машинном коде. (20 баллов)
- Задание 3. Подсистема виртуальной памяти использует реализованную аппаратно одноуровневую таблицу страниц, включающую блоки памяти SRAM и сопутствующую логику. Она поддерживает 26-битные виртуальные адреса, 23-битные физические адреса и страницы размером 128 Кбайт. В каждой записи таблицы страниц имеется бит достоверности V и бит изменения D. Чему равен размер всей таблицы в битах? (20 баллов)


# Основная литература:

[Лекции ВШЭ](lectures/index.html)
