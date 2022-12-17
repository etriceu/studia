;1,2
    LJMP START
    ORG 100H

START:
    MOV 'K',#'P'
    MOV 'K'+1,#'x'
    MOV 'K'+2,#'x'
    MOV 'K'+3,#'x'
    MOV 'K'+4,#'x'
    MOV 'K'+5,#'x'
    MOV 'K'+6,#'x'
    MOV 'K'+7,#'x'
    MOV 'K'+8,#'x'
    MOV 'K'+9,#'x'
    MOV 'K'+10,#'.'
    MOV 'K'+11,#'K'
    MOV 'K'+12,#'x'
    MOV 'K'+13,#'x'
    MOV 'K'+14,#'x'
    MOV 'K'+15,#'x'
    MOV 'K'+16,#'x'
    MOV 'K'+17,#'x'
    MOV 'K'+18,#'x'
    MOV 'K'+19,#'x'
    MOV 'K'+20,#'x'
    MOV 'K'+21,#'x'
    MOV 'K'+22,#'x'
    MOV 'K'+23,#'.'

    CLR RS0
    CLR RS1

    MOV R0,#98
    MOV R1,#99
LOOP:
    MOV A,@R0
    MOV @R1,A
    INC R1
    DEC R0
    LJMP LOOP

;3
    LJMP    START
    ORG    100H
START:

    CLR C
    MOV A,#10101000B
    ADD A,#01111100B
    MOV R1,A
    MOV A,#11100010B
    ADDC A,#10011001B
    MOV R0,A
