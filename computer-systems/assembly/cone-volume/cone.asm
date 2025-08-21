default rel

section .data
pi: dd 3.14
third: dd 0.33


section .text
global volume
;1/3 * pi * r^2 * h
volume:

 	ret
