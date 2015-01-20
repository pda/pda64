bits 16
section .text
org 0x7C00

write_message_tty_style:
	mov	bx, 0		; index into message
write_message_tty_style_loop:
	mov	al, [message+bx]	; BIOS: write_char param
	mov	ah, 0x0E		; BIOS: output character, TTY style.
	mov	bh, 0x00		; BIOS: page number
	int	0x10			; BIOS: call
	inc	bx
	cmp	bx, after_message-message
	jb	write_message_tty_style_loop


message:
	db "pda64 booting..."
after_message:
