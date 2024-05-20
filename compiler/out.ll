; ModuleID = 'One Lang'
source_filename = "One Lang"

@num_of_devices = constant i32 234, align 4
@my_name = private constant [12 x i8] c"subham shaw\00"
@marks = private global [5 x i32] [i32 23, i32 45, i32 78, i32 12, i32 90], align 4

define i16 @main(i16 %a, i16 %b) {
  %sum = add i16 %a, %b
  ret i16 %sum
}
