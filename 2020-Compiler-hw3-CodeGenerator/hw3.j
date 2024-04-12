.source hw3.j
.class public Main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 100
.limit locals 100 ;
ldc 0
istore 0
ldc 999
istore 1
label0_begin:
iload 1
ldc 1
istore 1

iload 1
ldc 9
isub
ifle L_cmp_0
iconst_0
goto L_cmp_1
L_cmp_0:
iconst_1
L_cmp_1:
here is LEQ
iload 1
ldc 1
iadd
istore 1
ifeq label0_end
label0_begin:
iload 0
ldc 1
istore 0
iload 0
ldc 9
isub
ifle L_cmp_2
iconst_0
goto L_cmp_3
L_cmp_2:
iconst_1
L_cmp_3:
here is LEQ
iload 0
ldc 1
iadd
istore 0
ifeq label0_end
iload 1
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "*"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 0
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "="
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
iload 1
iload 0
imul
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(I)V
ldc "\t"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto label0_begin
label0_end:
ldc "\n"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/print(Ljava/lang/String;)V
goto label1_begin
label1_end:
return
.end method
