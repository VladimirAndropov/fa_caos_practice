
    .global main
main:
    mov x, %eax
    call writei32
    call finish

x:  .int 43

