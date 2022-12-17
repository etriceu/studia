;1
;************************************************
	LJMP	START
	ORG	100H
START:

	MOV A,#90
	ADD A,#7

	LJMP $

;2
;************************************************
	LJMP	START
	ORG	100H
START:

	MOV A,#100
	ADD A,#10001101B

	LJMP $


;3
;************************************************
	LJMP	START
	ORG	100H
START:
	MOV A,#10111110B
	ADD A,#11000100B


	LJMP $

;4
;************************************************
	LJMP	START
	ORG	100H
START:
	MOV A,#10111110B
	ADD A,#11000100B


	LJMP $
