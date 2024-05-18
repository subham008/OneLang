; ModuleID = 'One Lang'
source_filename = "One Lang"

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
  %str = private unnamed_addr constant [15 x i8] c"Hello, World!\0A\00"
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([15 x i8], [15 x i8]* @str, i32 0, i32 0))
  ret i32 42
}
