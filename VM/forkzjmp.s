.name "fdp"
.comment "WOW"

lab:
live %1
fork %-8
sti r104446, %0, %0
and r2, r1, r3
zjmp %:lab
