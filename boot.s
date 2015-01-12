section .text
org 0x7C00

write_string:
	mov	ah, 0x13	; int10h 13h: display string
	mov	bl, 0x0E	; color, E=yellow on 0=black
	mov	al, 0x00	; write-mode
	mov	cx, 11		; string length
	mov	dh, 24		; screen row
	mov	dl, 0		; screen column
	push	0
	pop	es		; string address segment
	mov	bp, message	; string address
	int	0x10
message:
	db "hello pda64"
