.cpu cortex-m0
.align 1
.text
.global toggle

toggle:
     cmp r0, #'Z'
     ble upper
     cmp r0, #'a'
     bge lower
     mov pc, lr

upper:
     cmp r0, #'A'
     blt done
     add r0, r0, #'z' - 'Z'
     mov pc, lr

lower:
     cmp r0, #'z'
     bgt done
     sub r0, r0, #'z' - 'Z'     
     mov pc, lr

done:
     mov pc, lr
