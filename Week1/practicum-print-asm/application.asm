.cpu cortex-m0
text:
    .asciz "Hello world, the ANSWER is 42! @[]`{}~\n"
.align 1
.text
.global text
.global application



application:
    ldr r0, =text
    bl print_asciz
