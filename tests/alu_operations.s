.text
li x20 30
li x21 6

print "add(30,6):  "
li x10 1
add x11 x20 x21
ecall
call new_line
print "sub(30,6):  "
li x10 1
sub x11 x20 x21
ecall
call new_line
print "mul(30,6):  "
li x10 1
mul x11 x20 x21
ecall
call new_line
print "div(30,6):  "
li x10 1
div x11 x20 x21
ecall
call new_line

li x10 10
ecall

new_line:
li x10 11
li x11 10
ecall
ret