rax -> what gets returned in a function 
eax -> lower 32 bits of 64 rax


maybe i need to know how to do debugging in lldb or gdb and see each mapping between assembly and what gets stored in the registers and etc...

rax -> return 
cmp -> compares two values or registers or combination of both and set EFLAG registers 
jmp -> jumps to the address
jg -> check zf (0) or sf(if result > 0) and jump to the memory address

tour of the lldb
lldb execuable

dis -> disassemble specified instructions in the current target
watch set variable <> ->set a watchpoint at the variable 