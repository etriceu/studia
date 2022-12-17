 
;1. Dodawanie liczb  16-bitowych bez znaku
    LJMP    START
    ORG    100H
START:
    CLR C

    MOV A,#0B6H
    ADD A,#06CH
    MOV R1,A
    MOV A,#28H
    ADDC A,#51H
    MOV R0,A

;2. Dodawanie liczb  8- i 16-bitowej w kodzie U2
    LJMP    START
    ORG    100H
START:
    CLR C

    MOV A,#00011001B
    ADD A,#00010010B
    MOV R1,A
    MOV A,#00000000B
    ADDC A,#10100110B
    MOV R0,A

;3. Dodawanie liczb  16-bitowych w kodzie U2
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
