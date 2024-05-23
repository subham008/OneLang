; ModuleID = 'One Lang'
source_filename = "One Lang"

@.str = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1
declare i32 @printf(i8*, ...) ; declare printf linking 

define i32 @main() {
entry:
  
  %result= call i32 @add_num(i32 10 , i32 20, i32 20)

  %print_x = call i32 (i8*, ...) @printf(i8* getelementptr inbounds ([4 x i8], [4 x i8]* @.str, i32 0, i32 0), i32 %result)
  ret i32 42  ;return statement
}


define i32 @add_num(i32 %a , i32 %b , i32 %c ){
   %sum = add i32 %a,%b
   %sum1 = mul i32 %sum,%c 
   ret i32 %sum1
}

