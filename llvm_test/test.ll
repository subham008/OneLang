; Declare the string constant
@.str = private unnamed_addr constant [14 x i8] c"Hello, World!\0A\00"

; Declare the external printf function
declare i32 @printf(i8*, ...)

; Define the main function
define i32 @main() {
entry:
  ; Call printf with the string constant
  %printf = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([14 x i8], [14 x i8]* @.str, i32 0, i32 0))
  ret i32 0
}