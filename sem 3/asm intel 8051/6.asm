    LJMP    START
    ORG    100H
START:

    MOV R0,#CS55D
    MOV A,#90H
    MOVX @R0,A

    MOV R0,#CS55B
    MOV A, #10000000B
    MOVX @R0, A

    CLR A

    MOV R0,#CS55A
    MOVX A, @R0
