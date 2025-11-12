; word count		12 nov 25

; ascii
cr	equ	0dh
lf	equ	0ah
ctrlz	equ	1ah
space	equ	' '

; bdos functions
rconf	equ	1
wconf	equ	2
rbuff	equ	10

; vectors
rboot	equ	0
bdos	equ	5
tpa	equ	100h

	org	tpa

start:	lxi	sp,stak
start1:	lxi	h,inbuf
	call	cimsg
	call	ccrlf
	mvi	b,1
start2:	mov	a,m
	inx	h
	ora	a
	jz	start3
	cpi	space
	jnz	start2
	inr	b
	jmp	start2
start3:	mov	a,b
	call	conum
	ret

; console in (a)
ci:	push	b
	push	d
	push	h
	mvi	c,rconf
	call	bdos
	ani	7fh
	pop	h
	pop	d
	pop	b
	ret

; console out (a)
co:	push	a
	push	b
	push	d
	push	h
	mvi	c,wconf
	mov	e,a
	call	bdos
	pop	h
	pop	d
	pop	b
	pop	a
	ret

; console out decimal number (a)
conum:	push	a
	push	b
	push	d
	push	h
	mvi	b,0
conum1:	sui	100
	jc	conum2
	inr	b
	jmp	conum1
conum2:	adi	100
	push	a
	mov	a,b
	mov	c,b
	ora	a
	jz	conum3
	adi	'0'
	call	co
conum3:	pop	a
	mvi	b,0
conum4:	sui	10
	jc	conum5
	inr	b
	jmp	conum4
conum5:	adi	10
	push	a
	mov	a,b
	ora	c
	jz	conum6
	mov	a,b
	adi	'0'
	call	co
conum6:	pop	a
	adi	'0'
	call	co
	pop	h
	pop	d
	pop	b
	pop	a
	ret

; console out carriage-return line-feed
ccrlf:	push	a
	mvi	a,cr
	call	co
	mvi	a,lf
	call	co
	pop	a
	ret

; console out message (hl)
comsg:	push	a
	push	h
	mov	a,m
	ora	a
	jz	comsg1
	call	co
	inx	h
	jmp	comsg
comsg1:	pop	h
	pop	a
	ret

; console in message (hl)
; altered from book, assumed proper buffer setup:
; max_length, length, buffer_ptr: reserved bytes
cimsg:	push	a
	push	b
	push	d
	push	h
	dcx	h
	push	h
	dcx	h
	xchg
	mvi	c,rbuff
	call	bdos
	pop	h
	mov	e,m
	mvi	d,0
	dad	d
	inx	h
	mvi	m,0
	pop	h
	pop	d
	pop	b
	pop	a
	ret

; input buffer
	db	254,0
inbuf:	ds	254
	db	0

; stack
	ds	64
stak:	dw	rboot

	end
