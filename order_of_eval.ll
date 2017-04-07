; ModuleID = 'order_of_eval.c'
target datalayout = "e-m:e-p:32:32-f64:32:64-f80:32-n8:16:32-S128"
target triple = "i386-pc-linux-gnu"

@.str = private unnamed_addr constant [9 x i8] c"Hello A\0A\00", align 1
@.str1 = private unnamed_addr constant [9 x i8] c"Hello B\0A\00", align 1
@.str2 = private unnamed_addr constant [9 x i8] c"Hello C\0A\00", align 1
@.str3 = private unnamed_addr constant [9 x i8] c"Hello D\0A\00", align 1
@.str4 = private unnamed_addr constant [14 x i8] c"%d %d %d %d \0A\00", align 1

; Function Attrs: nounwind
define i32 @A() #0 {
  %1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @.str, i32 0, i32 0))
  ret i32 1
}

declare i32 @printf(i8*, ...) #1

; Function Attrs: nounwind
define i32 @B() #0 {
  %1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @.str1, i32 0, i32 0))
  ret i32 2
}

; Function Attrs: nounwind
define i32 @C() #0 {
  %1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @.str2, i32 0, i32 0))
  ret i32 3
}

; Function Attrs: nounwind
define i32 @D() #0 {
  %1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([9 x i8]* @.str3, i32 0, i32 0))
  ret i32 4
}

; Function Attrs: nounwind
define i32 @main() #0 {
  %1 = alloca i32, align 4
  store i32 0, i32* %1
  %2 = call i32 @A()
  %3 = call i32 @B()
  %4 = call i32 @C()
  %5 = call i32 @D()
  %6 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([14 x i8]* @.str4, i32 0, i32 0), i32 %2, i32 %3, i32 %4, i32 %5)
  ret i32 0
}

attributes #0 = { nounwind "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }
attributes #1 = { "less-precise-fpmad"="false" "no-frame-pointer-elim"="true" "no-frame-pointer-elim-non-leaf" "no-infs-fp-math"="false" "no-nans-fp-math"="false" "stack-protector-buffer-size"="8" "unsafe-fp-math"="false" "use-soft-float"="false" }

!llvm.ident = !{!0}

!0 = metadata !{metadata !"Ubuntu clang version 3.5.0-4ubuntu2~trusty2 (tags/RELEASE_350/final) (based on LLVM 3.5.0)"}
