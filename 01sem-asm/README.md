# 1 Семинар 02.2024 ASM 1



## Компиляция и запуск:

### Компиляция:

`gcc -m32 <file_name> -o <binname>`

`gcc -m32 prog1.S simpleio_i686.S -o prog1`

### Запуск:

`./prog1`

### Сгенерировать asm код из c:

`gcc -S -m32 -O0 file.c`

## simpleio_i686.S

readi32 - считать 32 битное число (сложится в eax)

readi64 - считать 64 битное число (сложится в edx:eax)

writei32 - напечатать 32 битное число (печатается из eax)

writei64 - напечатать 64 битное число (печатается из edx:eax)

## Регистры:

%eax, %ebx, %ecx, %edx, %esi, %edi, %ebp, %esp

## Инструкции:

        add    SRC, DST        /* DST += SRC */
        sub    SRC, DST        /* DST -= SRC */
        inc    DST             /* ++DST */
        dec    DST             /* --DST */
        neg    DST             /* DST = -DST */
        mov    SRC, DST        /* DST = SRC */
        imul   SRC             /* (%eax,%edx) = %eax * SRC - знаковое */
        mul    SRC             /* (%eax,%edx) = %eax * SRC - беззнаковое */
        and    SRC, DST        /* DST &= SRC */
        or     SRC, DST        /* DST |= SRC */
        xor    SRC, DST        /* DST ^= SRC */
        not    DST             /* DST = ~DST */
        cmp    SRC, DST        /* DST - SRC, результат не сохраняется, */
        test   SRC, DST        /* DST & SRC, результат не сохраняется  */
        adc    SRC, DST        /* DST += SRC + CF */
        sbb    SRC, DST        /* DST -= SRC - CF */
        sdq                    /* расширяет старший бит регистра %eax на %edx */

## Флаги:

Большинство арифметических инструкций в результате вычисления результата инструкции устанавливают арифметические флаги слова состояния процесса.

Флаг *ZF* устанавливается, если в результате операции был получен нуль.

Флаг *SF* устанавливается, если в результате операции было получено отрицательное число.

Флаг *CF* устанавливается, если в результате выполнения операции произошел перенос из старшего бита результата. Например, для сложения CF устанавливается если результат сложения двух беззнаковых чисел не может быть представлен 32-битным беззнаковым числом.

Флаг *OF* устанавливается, если в результате выполняния операции произошло переполнение знакового результата. Например, при сложении OF устанавливается, если результат сложения двух знаковых чисел не может быть представлен 32-битным знаковым числом.

Обратите внимание, что и сложение addl, и вычитание subl устанавливают одновременно и флаг CF, и флаг OF. Сложение и вычитание знаковых и беззнаковых чисел выполняется совершенно одинаково, и поэтому используется одна инструкция и для знаковой, и для беззнаковой операции.

## Переходы:

        jz      label   /* переход, если равно (нуль), ZF == 1 */
        jnz     label   /* переход, если не равно (не нуль), ZF == 0 */
        jc      label   /* переход, если CF == 1 */
        jnc     label   /* переход, если CF == 0 */
        jo      label   /* переход, если OF == 1 */
        jno     label   /* переход, если OF == 0 */
        jg      label   /* переход, если больше для знаковых чисел */
        jge     label   /* переход, если >= для знаковых чисел */
        jl      label   /* переход, если < для знаковых чисел */
        jle     label   /* переход, если <= для знаковых чисел */
        ja      label   /* переход, если > для беззнаковых чисел */
        jae     label   /* переход, если >= (беззнаковый) */
        jb      label   /* переход, если < (беззнаковый) */
        jbe     label   /* переход, если <= (беззнаковый) */

