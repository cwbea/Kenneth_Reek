    .text                   ; Code section
    .globl _sum_three_values ; Make the function visible externally

; Function: _sum_three_values
; Purpose:  Sum three 32-bit integers passed on the stack
; Arguments: 
;   sp@(4)  - First argument (int)
;   sp@(8)  - Second argument (int)
;   sp@(12) - Third argument (int)
; Return:
;   d0 - Sum of the three arguments

_sum_three_values:
    movl    sp@(4), d0       ; Move first argument into data register d0
    addl    sp@(8), d0       ; Add second argument to d0
    addl    sp@(12), d0      ; Add third argument to d0
    rts                      ; Return from subroutine, result is in d0

