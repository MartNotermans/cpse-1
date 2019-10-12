.cpu cortex-m0
.text
.align 1
.global application

    .data
string:
    .asciz "Hello world +-TESTAZaz@![]{}`~\n"

    .text
application:
    PUSH {LR}
    LDR R0, =string
    BL print_asciz
    POP {PC}


print_asciz:
    PUSH {R5, LR}
    MOV R5, R0
loop:
    LDRB R0, [R5]
    ADD R0, R0, #0
    BEQ done
    BL toggle_char
    ADD R5, R5, #1
    B loop
done:
    POP {R5, PC}


toggle_char:
    PUSH {LR}
    CMP R0, #'A'
    BLT az
    CMP R0, #90
    BGT az 
    B AZ
AZ:
    ADD R0, R0, #'a' - 'A'
    B done2
az:
    CMP R0, #97
    BLT done2
    CMP R0, #122
    BGT done2
    SUB R0, R0, #32
done2:
    BL uart_put_char
    POP {PC}