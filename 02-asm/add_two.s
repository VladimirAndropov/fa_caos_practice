// Задача: считать со строки ввода два числа и вывести их сумму

    .global main
main:
    // считать из строки ввода число в %eax
    call    readi32
    // переложим считанное число в %edx, чтобы можно было еще раз вызвать readi32
    // и потерять считанное ранее число
    mov     %eax, %edx

    // считываем второе число
    call    readi32
    // или второе число мы могли бы просто константой положить:
    // mov $50, %eax

    // так как одно число уже лежит в %edx, а второе мы считали только что в %eax
    // то можем сложить %eax и %edx. Складываем так, чтобы вторым операндом был %eax
    // чтобфы избежать лишнего перекладывания в %eax для вывода через writei32
    add     %edx, %eax

    // выводим число из регистра %eax
    call    writei32
    // завершаем выполнение
    call    finish