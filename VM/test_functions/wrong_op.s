.name "wrong byte_code"
.comment "will it crash"

label:
ld %2694881440, r1
sti r1, %-6, %0
and r2, %1, r3
zjmp %:label
