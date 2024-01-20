 # 23 Семинар 31.06.2022 Threads, atomic, mutex

## Файлики с кодом:

* [Создаем простой банк](bank_add_simple.c)
* [Добавляем потоков](bank_add_threads.c)
* [Добавляем еще и вывод средств](bank_safe.c)
* [еще одна банковская структура, 2 счета зачисления и 1 счет чтобы тратить](bank_transfers.c)
* [+mutex](bank_transfers_mutex.c)
* [еще один вариант mutex-а](bank_transfers_mutex_2.c)

#  создаем потоки
```
for (int i = 0; i != N; ++i) {
        pthread_create(&tids[i], NULL, process, (void *)&account);
    }
```
функция pthread_create создает потоки, 1ым аргементом - куда сложить id-шники потоков, 2 - атрибуты, 3 - функция, 4 - параметры у функции



#  threads
```
int balance;
balance += amount;
```
|основной код лежит в [файле](bank_add_threads.c)|
при множестве операций возникнет data race, в следствии получаем UB, потому что процессы начинают вклиниваться и мешать друг другу

#  threads + atomic
```
_Atomic int balance;
balance += amount;
```
|основной код лежит в [файле](bank_add_threads.c)|
делаем переменную атомарной, тем самым обеспечив гарантию того, что все операции над переменной проходят последовательно и не прерываются

#  threads + atomic функции
```
_Atomic int balance;
atomic_fetch_add(&account->balance, amount);
```
|основной код лежит в [файле](bank_add_threads.c)|
делаем операции атомарными, значит сами операции выполняются последовательно и не прерываются. но важно помнить, что атомарные функции работают с атомарными переменными.


